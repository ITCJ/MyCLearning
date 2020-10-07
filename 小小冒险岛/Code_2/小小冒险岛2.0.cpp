/*人物已经可以实现走动与站立
VK_LEFT VK_RIGHT 实现向左向右移动
攻击先一步跳跃编好 由VK_LCONTROL 控制
跳跃由VK_SPACE控制
*/

#include <graphics.h>
#include <conio.h>
#include <stdlib.h>
#include <math.h>
#include <stdio.h>

// 引用 Windows Multimedia API
#pragma comment(lib,"Winmm.lib")

#define High 464  // 游戏画面尺寸
#define Width 580

IMAGE img_bk; // 背景图片
int img_bk_x, img_bk_y;  //背景放置位置
int img_bk_b_x1, img_bk_b_x2, img_bk_b_y;
IMAGE img_walk[2];//人物行走
IMAGE img_stand[2];//人物战立
IMAGE img_jump[2][2];//人物跳跃 0遮盖，1原图  0向左，1向右
IMAGE img_attack[2][4];//人物攻击

int direction = 0;		//人物方向
float role_x, role_y; // 人物位置
int role_vx = 0, role_vy = 0;	//人物移动速度

int i_stand = 0;
int v_stand;		//站立帧数

int i_walk = 0; //作为变量
int delay_walk;		//走路停止延迟

int v_walk;			//走动帧数

int i_jump;			//用于跳跃的变量
int delay_jump = 1;
int v_jump = 0;		//跳跃帧数

int delay_attack = 0;
int i_attack = 0, j_attack = 0;		//i控制帧数，j控制攻击类型
int v_attack[4] = { 30,30,30,40 };	//不同攻击姿势的延迟
int x_attack[4] = { 86,90,113,116 };
int y_attack[4] = { 86,76,72,94 }; //关于攻击图像x，y坐标的调整

void startup()
{

	v_stand = 50;
	v_walk = 20;

	delay_walk = 10;
	initgraph(Width, High);
	img_bk_x = 0;
	img_bk_y = High - 648;	//背景最初位置



	loadimage(&img_bk, _T(".\\小小冒险岛\\背景\\backgound11 1367 648.jpg"));

	//人物行走（0为左，1为右)
	loadimage(&img_walk[0], _T(".\\小小冒险岛\\人物\\walk\\walk0 67 76.jpg"));
	loadimage(&img_walk[1], _T(".\\小小冒险岛\\人物\\walk\\walk1 67 76.jpg"));
	//人物站立
	loadimage(&img_stand[0], _T(".\\小小冒险岛\\人物\\stand\\stand0 65 76.jpg"));
	loadimage(&img_stand[1], _T(".\\小小冒险岛\\人物\\stand\\stand1 65 76.jpg"));
	//人物跳跃
	loadimage(&img_jump[0][0], _T(".\\小小冒险岛\\人物\\jump\\jump00 67 76.jpg"));
	loadimage(&img_jump[1][0], _T(".\\小小冒险岛\\人物\\jump\\jump10 67 76.jpg"));
	loadimage(&img_jump[0][1], _T(".\\小小冒险岛\\人物\\jump\\jump01 67 76.jpg"));
	loadimage(&img_jump[1][1], _T(".\\小小冒险岛\\人物\\jump\\jump11 67 76.jpg"));
	//人物攻击
	loadimage(&img_attack[0][0], _T(".\\小小冒险岛\\人物\\attack\\attack01 86 86.bmp"));
	loadimage(&img_attack[1][0], _T(".\\小小冒险岛\\人物\\attack\\attack11 86 86.bmp"));
	loadimage(&img_attack[0][1], _T(".\\小小冒险岛\\人物\\attack\\attack02 90 76.bmp"));
	loadimage(&img_attack[1][1], _T(".\\小小冒险岛\\人物\\attack\\attack12 90 76.bmp"));
	loadimage(&img_attack[0][2], _T(".\\小小冒险岛\\人物\\attack\\attack03 113 72.bmp"));
	loadimage(&img_attack[1][2], _T(".\\小小冒险岛\\人物\\attack\\attack13 113 72.bmp"));
	loadimage(&img_attack[0][3], _T(".\\小小冒险岛\\人物\\attack\\attack04 116 94.bmp"));
	loadimage(&img_attack[1][3], _T(".\\小小冒险岛\\人物\\attack\\attack14 116 94.bmp"));//四种攻击方式



	role_x = 0;
	role_y = 250;
	img_bk_b_y = role_y + 110 + 67;

	//开始印刷
	BeginBatchDraw();
}
void stand()
{
	v_stand = 25;


	putimage(role_x, role_y - 76, 65, 76, &img_stand[0], i_stand / v_stand * 65, direction * 76, NOTSRCERASE); //显示人物
	putimage(role_x, role_y - 76, 65, 76, &img_stand[1], i_stand / v_stand * 65, direction * 76, SRCINVERT);
	FlushBatchDraw();
	i_stand++;
	if (i_stand == 4 * v_stand)
		i_stand = 0;
}

void role_walk()
{
	v_walk = 10;

	putimage(role_x, role_y - 76, 67, 76, &img_walk[0], i_walk / v_walk * 67, direction * 76, NOTSRCERASE); //显示人物
	putimage(role_x, role_y - 76, 67, 76, &img_walk[1], i_walk / v_walk * 67, direction * 76, SRCINVERT);
	FlushBatchDraw();
	i_walk++;
	if (i_walk == 4 * v_walk)
		i_walk = 0;

}
void jump()
{

}

void show()
{
	putimage(img_bk_x, img_bk_y, &img_bk);	// 显示背景	

	if (role_vx == 0 && (delay_jump != 1) && (delay_attack != 1))
	{
		stand();
	}
	else if ((role_vx != 0) && delay_walk != 0 && (delay_jump != 1) && (delay_attack != 1))
	{
		role_walk();
	}
	else if (delay_jump == 1 && (delay_attack != 1))
	{
		putimage(role_x, role_y - 76, &img_jump[0][direction], NOTSRCERASE); //显示人物
		putimage(role_x, role_y - 76, &img_jump[1][direction], SRCINVERT);
		FlushBatchDraw();
	}
	else if (delay_attack == 1)
	{
		putimage(role_x, role_y - y_attack[j_attack], x_attack[j_attack], y_attack[j_attack], &img_attack[0][j_attack], i_attack / 10 * x_attack[j_attack], direction * y_attack[j_attack], SRCAND); //显示人物攻击图像
		putimage(role_x, role_y - y_attack[j_attack], x_attack[j_attack], y_attack[j_attack], &img_attack[1][j_attack], i_attack / 10 * x_attack[j_attack], direction *  y_attack[j_attack], SRCPAINT);
		i_attack++;
		if (i_attack == v_attack[j_attack])
		{
			i_attack = 0;
			j_attack = rand() % 4;
			delay_attack = 0;
		}
		FlushBatchDraw();
	}
	if (delay_walk != 0)
		delay_walk--;
	else
		role_vx = 0;
	Sleep(10);
}

void updateWithoutInput()
{
	if (v_jump == 2)
	{
		if (role_vy > 0)
		{
			for (i_jump = role_vy; i_jump >= 0; i_jump -= 1)
			{
				if (i_jump == 25)
				{
					i_jump = 16;
				}
				role_y -= 1;
			}
		}
		/*上升时不判断挡板*/
		else if (role_vy <= 0)
		{
			for (i_jump = -1 * role_vy; i_jump >= 0; i_jump -= 1)
			{
				role_y += 1;
			}
		}
		v_jump = 0;

		if (role_y < img_bk_b_y)		//对于挡板的判断
		{
			role_vy--;
		}
		else
		{
			role_y = img_bk_b_y;
			role_vy = 0;//踩到挡板时人物下落速度为0,跳跃延迟为0,人物纵坐标为挡板纵坐标
			delay_jump = 0;
		}
	}
	else
		v_jump++;



}

void updateWithInput()
{

	if ((GetAsyncKeyState(VK_LEFT) & 0x8000))	//向左
	{
		role_vx = -2;
		if (delay_attack != 1 || delay_jump == 1)		//在攻击时不可移动及改变方向,但在空中可以
		{
			direction = 0;
			role_x += role_vx;
		}
		delay_walk = 1;
	}
	else if ((GetAsyncKeyState(VK_RIGHT) & 0x8000))	//向右
	{

		role_vx = 2;
		if (delay_attack != 1 || delay_jump == 1)		//在攻击时不可移动及改变方向,但在空中可以
		{
			direction = 1;
			role_x += role_vx;
		}
		delay_walk = 1;
	}
	if ((GetAsyncKeyState(VK_SPACE) & 0x8000) && delay_jump == 0 && delay_attack == 0)
	{
		delay_jump = 1;		//为1时保持跳跃姿态
		role_vy = 12;		//跳跃速度
		v_jump = 2;
	}
	if ((GetAsyncKeyState(VK_LCONTROL) & 0x8000))
	{
		delay_attack = 1;	//攻击延迟
	}
}

void gameover()
{
	EndBatchDraw();
	_getch();
	closegraph();
}

int main()
{
	startup();  // 数据初始化	
	while (1)  //  游戏循环执行
	{
		show();  // 显示画面
		updateWithoutInput();  // 与用户输入无关的更新
		updateWithInput();     // 与用户输入有关的更新
	}
	gameover();     // 游戏结束、后续处理
	return 0;
}

