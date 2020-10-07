/*
实现了多挡板以及地图的转化

增加了地图数目

大幅优化人物移动.坐标改变全体移到withoutinput ,withinput仅改变速度与判定

人物运动全体完成,怪物也会在各地图出现,只要完善数据加上音乐就可以了

A向左移动,D向右移动,J攻击,K跳跃,W转换地图(得在光圈内),W也可为爬绳子(在绳子旁),

E为二段跳,不过因为没加延迟,可以当做飞行来用(好像这也不错)
*/
#include <graphics.h>
#include <conio.h>
#include <stdlib.h>
#include <math.h>
#include <stdio.h>
#include <mmsystem.h>

// 引用 Windows Multimedia API
#pragma comment(lib,"Winmm.lib")

#define High 600  // 游戏画面尺寸
#define Width 800
struct barkgound		//对于地图的定义
{

	int x;	//地图位置
	int y;
	int length;		//地图长宽
	int high;
	//挡板
	int num_of_land;
	int x_left_land[30];	//挡板左端点
	int x_right_land[30];//挡板右端点
	int y_land[30];		//挡板纵坐标
						//光圈
	int num_of_aperture;	//实际光圈数目
	int x_aperture[2];	//光圈位置（一地图两个就可以了)
	int y_aperture[2];
	int deliver_to_bk[2];		//传送去的地图
	int deliver_to_aperture[2];//传送去地图具体光圈
	int local_deliver_to_aperture[2];//传送过去是人物处于右或者左侧
									 //绳索
	int num_of_rope;//绳索数量
	int x_rope[6];
	int y_down_rope[6];//绳索的下方
	int y_up_rope[6];//绳索的上方
					 //敌人
	int num_of_enemy;//敌人的数量
	int enemy_x[5];//敌人的横坐标
	int enemy_y[5];//敌人的纵坐标
	int hp_of_enemy[5];//敌人的生命
	int enemy_direction[5];//敌人的方向
	int enemy_delay[5];//攻击延迟
	int enemy_attack;//野怪攻击的数值
					 //下面两个用来找野怪的位置
	int enemy_high;//野怪的高度
	int enemy_width;//野怪的宽度
	int enemy_birth[5];
};
int i_land;		//用于判断挡板
int i_aperture;			//用于判断光圈
int i_rope;		//用于判断绳子

barkgound bk[5];		//四张地图就够了吧
int now_of_bk;		//当前的地图
int re_of_bk;	//传送去的地图
int re_of_aperture;//传送过去的传送点

IMAGE img_bk_bk;	//背景的背景
IMAGE img_bk[2][5];
IMAGE img_end;//人物死亡
IMAGE img_walk[2];//人物行走
IMAGE img_stand[2];//人物战立
IMAGE img_jump[2][2];//人物跳跃 0遮盖，1原图  0向左，1向右
IMAGE img_attack[2][4];//人物攻击

IMAGE img_bullet[2][2];//子弹的坐标
int bullet_x, bullet_y;//子弹的横，纵坐标
IMAGE img_enemy1;
IMAGE img_enemy2;
int enemy_x[5], enemy_y[5];//敌人的横纵坐标
int enemy_walk = 10;//敌人行走图片的切换用
int i_enemy = 0;//敌人行走的变量
int enemy_vx = 10;//敌人行走的变量
int enemy[5];


int direction = 0;		//人物方向
int role_x, role_y; // 人物位置
int role_vx = 0, role_vy = 0;//人物的横纵方向的速度
int hp_of_role = 3;//人物的生命
IMAGE img_hp[2];

int i_stand = 0;//站立的变量
int v_stand;		//站立帧数

int i_walk = 0; //作为变量
int delay_walk;		//走路停止延迟

int v_walk;			//走动帧数

int i_jump;		//每次跳跃的距离
int delay_jump = 1;
int v_jump = 0;		//跳跃帧数

int delay_deliver = 0;	//两次传送延迟
int delay_climb = 0;	//攀爬延迟
int delay_attack = 0;
int i_attack = 0, j_attack = 0;		//i控制帧数，j控制攻击类型
int v_attack[4] = { 30,30,30,40 };	//不同攻击姿势的延迟

int x_attack[4] = { 86,90,113,116 };//关于攻击图像x坐标的调整
int y_attack[4] = { 86,76,72,94 }; //关于攻击图像坐标的调整
								   //两个变量，表示敌人的数组用
int i = 0;
int j = 0;
void startup()
{
	mciSendString(_T("open D:\\小小冒险岛\\BGM\\射手村训练场.mp3 alias startmusic"), NULL, 0, NULL);
	mciSendString(_T("play startmusic repeat"), NULL, 0, NULL);

	//bk[] = {/*bk_x*/,/*bk_y*/,/*bk_len*/,/*bkhigh*/,
	// /*挡板数*/,{/*挡板左*/}, { /*挡板右*/ }, {/*挡板高*/ },
	// /*光圈数*/, { /*光圈x*/ }, {/*光圈y*/ }, {/*光圈对应地图*/ }, { /*光圈对应光圈*/ }, {/*光圈的左右*/ }, 
	// /*绳索数*/ ,{绳子x*/},{/*绳子下端*/},{/*绳子上端*/} 
	//};
	bk[1] = { 0,-48,1367,648,
		1,{ 0 },{ 1367 } ,{ 570 } ,
		2,{ 210,1210 },{ 570,570 },{ 0,2 },{ 0,0 },{ 0,0 },
		0 ,{},{},{},
		0
	};
	for (i = 0; i < 5; i++)
	{
		enemy[i] = bk[now_of_bk].enemy_x[i];
	}




	bk[2] = { 0,0,2093,807,
		9,{ 0,740,860,355,1500,1570,1530,1600,1600 },{ 740,860,1500,930,1575,2094,1640,1710,1710 },{ 650,605,560,400,605,650,515,335,380 },
		2,{ 260,1850 },{ 650,650 },{ 1,3 },{ 1,0 },{ 1,1 } ,
		2,{ 890,1619 },{ 560,515 },{ 400,380 } ,
		0
	};

	bk[3] = { 0/*bk_x*/,0/*bk_y*/,2814/*bk_len*/,1695/*bkhigh*/,
		21/*挡板数*/,
		{ 0,815,2005,920,1890,1035,815,1945,480,2170,365,815,2170,1040,2055,815,1945,590,25,2280,1040/*挡板左*/ },
		{ 2814,920,2110,1035,2005,1890,985,2110,755,2335,875,980,2710,1880,2225,980,2115,755,535,2785,1880/*挡板右*/ },
		{ 1350,1315,1315,1240,1240,1160,1090,1090,1015,1015,785,710,710,635,635,560,560,485,410,410,260/*挡板高*/ },
		2/*光圈数*/,{ 2670,2635 /*光圈x*/ },{ 1350,410/*光圈y*/ },{ 2,4/*光圈对应地图*/ },{ 1,0/*光圈对应光圈*/ },{ 1,0/*光圈的左右*/ },
		6/*绳索数*/ ,{ 685,795,356,1480,2220,2535/*绳子x*/ },{ 1285,1015,715,605,945,675/*绳子下端*/ },{ 1015,785,410,260,710,410/*绳子上端*/ },
		5,{ 1460,1460,1460,620,1300 },{ 1350,1165,635,785,260 },{ 5,5,5,5,5 },{ 1,1,1,1,1 },{ 2,2,2,2,2 },{ 3 },{ 55 },{ 60 }
	,{ 0,0,0,0,0 } };

	bk[4] = { 0/*bk_x*/,0/*bk_y*/,1283/*bk_len*/,1053/*bkhigh*/,
		9/*挡板数*/,
		{ 0,285,355,420,490,555,760,490,85/*挡板左*/ },
		{ 1283,355,420,490,555,1200,1200,725,455/*挡板右*/ },
		{ 845,820,775,735,685,640,330,370,415/*挡板高*/ },
		1/*光圈数*/,{ 165 /*光圈x*/ },{ 845/*光圈y*/ },{ 3/*光圈对应地图*/ },{ 1/*光圈对应光圈*/ },{ 1/*光圈的左右*/ },
		1/*绳索数*/ ,{ 805/*绳子x*/ },{ 575/*绳子下端*/ },{ 330/*绳子上端*/ } ,
		5,{ 510,1060,825 ,1085,200 },{ 845,845,640,325,415 },{ 5,5,5,5,5 },{ 1,1,1,1,1 },{ 2,2,2,2,2 },{ 3 },{ 55 },{ 60 }
	,{ 0,0,0,0,0 } };

	now_of_bk = 1;//初始的位置

	v_stand = 50;//速度
	v_walk = 20;//速度

	delay_walk = 10;//行走的帧数
	initgraph(Width, High);
	//背景
	loadimage(&img_bk_bk, _T(".\\小小冒险岛\\背景\\bk.jpg"));
	loadimage(&img_end, _T(".\\小小冒险岛\\背景\\end.jpg"));
	loadimage(&img_bk[0][1], _T(".\\小小冒险岛\\背景\\backgound01 1367 648.jpg"));
	loadimage(&img_bk[1][1], _T(".\\小小冒险岛\\背景\\backgound11 1367 648.jpg"));
	loadimage(&img_bk[0][2], _T(".\\小小冒险岛\\背景\\backgound02 2093 807.jpg"));
	loadimage(&img_bk[1][2], _T(".\\小小冒险岛\\背景\\backgound12 2093 807.jpg"));
	loadimage(&img_bk[0][3], _T(".\\小小冒险岛\\背景\\backgound03 2814 1695.jpg"));
	loadimage(&img_bk[1][3], _T(".\\小小冒险岛\\背景\\backgound13 2814 1695.jpg"));
	loadimage(&img_bk[0][4], _T(".\\小小冒险岛\\背景\\backgound04 1283 1053.jpg"));
	loadimage(&img_bk[1][4], _T(".\\小小冒险岛\\背景\\backgound14 1283 1053.jpg"));
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

																				  //雪球
	loadimage(&img_bullet[1][0], _T(".\\小小冒险岛\\飞镖\\小雪球\\小雪球10.jpg"));
	loadimage(&img_bullet[1][1], _T(".\\小小冒险岛\\飞镖\\小雪球\\小雪球11.jpg"));
	loadimage(&img_bullet[0][0], _T(".\\小小冒险岛\\飞镖\\小雪球\\小雪球00.jpg"));
	loadimage(&img_bullet[0][1], _T(".\\小小冒险岛\\飞镖\\小雪球\\小雪球01.jpg"));
	//怪物
	loadimage(&img_enemy1, _T(".\\小小冒险岛\\怪物\\猴子\\猴子 walk12 61 55 .bmp"));
	loadimage(&img_enemy2, _T(".\\小小冒险岛\\怪物\\猴子\\猴子 walk02 61 55 .bmp"));
	//人物生命为零
	loadimage(&img_hp[0], _T(".\\小小冒险岛\\人物\\hp0 20 23.jpg"));
	loadimage(&img_hp[1], _T(".\\小小冒险岛\\人物\\hp1 20 23.jpg"));
	role_x = 500;
	role_y = 500;
	//开始印刷
	BeginBatchDraw();
}
void stand()
{
	v_stand = 25;
	putimage(role_x - 32, role_y - 76, 65, 76, &img_stand[0], i_stand / v_stand * 65, direction * 76, NOTSRCERASE); //显示人物
	putimage(role_x - 32, role_y - 76, 65, 76, &img_stand[1], i_stand / v_stand * 65, direction * 76, SRCINVERT);
	i_stand++;
	if (i_stand == 4 * v_stand)
		i_stand = 0;
}

void role_walk()
{
	v_walk = 10;
	putimage(role_x - 33, role_y - 76, 67, 76, &img_walk[0], i_walk / v_walk * 67, direction * 76, NOTSRCERASE); //显示人物
	putimage(role_x - 33, role_y - 76, 67, 76, &img_walk[1], i_walk / v_walk * 67, direction * 76, SRCINVERT);
	i_walk++;
	if (i_walk == 4 * v_walk)//重复输出图片，动态
		i_walk = 0;

}
void gameover()
{
	putimage(0, 0, &img_end);
	FlushBatchDraw();
	Sleep(2000);
	now_of_bk = 2;
	role_x = 500;
	role_y = 500;
	hp_of_role = 3;

}

void show()
{

	putimage(-10, -10, &img_bk_bk);
	putimage(bk[now_of_bk].x, bk[now_of_bk].y, &img_bk[0][now_of_bk], NOTSRCERASE);
	putimage(bk[now_of_bk].x, bk[now_of_bk].y, &img_bk[1][now_of_bk], SRCINVERT);	// 显示背景	
	for (i = 0; i < hp_of_role; i++)
	{
		putimage(23 * i, 0, &img_hp[0], NOTSRCERASE);
		putimage(23 * i, 0, &img_hp[1], SRCINVERT);//你的血量
	}

	if (now_of_bk == 3 || now_of_bk == 4)
	{
		for (i = 0; i < bk[now_of_bk].num_of_enemy; i++)
		{				//敌人还活着
			if (bk[now_of_bk].hp_of_enemy[i] > 0)
			{
				enemy_x[i] = bk[now_of_bk].x + bk[now_of_bk].enemy_x[i] - bk[now_of_bk].enemy_width / 2;
				enemy_y[i] = bk[now_of_bk].y + bk[now_of_bk].enemy_y[i] - bk[now_of_bk].enemy_high;
				if (role_x > enemy_x[i])				//由人与敌人的坐标判断出敌人的移动方向
					bk[now_of_bk].enemy_direction[i] = 1;
				if (role_x <= enemy_x[i])
					bk[now_of_bk].enemy_direction[i] = 0;
				if (bk[now_of_bk].hp_of_enemy[i] > 0 && bk[now_of_bk].hp_of_enemy[i] < 5)
				{
					if (abs(enemy_x[i] - role_x)>200)//当敌人受到攻击后会向你移动，距离大时奔跑
					{
						enemy_walk = 25;
						putimage(enemy_x[i], enemy_y[i], 61, 55, &img_enemy2, i_enemy / enemy_vx * 61, bk[now_of_bk].enemy_direction[i] * 55, SRCAND);
						putimage(enemy_x[i], enemy_y[i], 61, 55, &img_enemy1, i_enemy / enemy_vx * 61, bk[now_of_bk].enemy_direction[i] * 55, SRCPAINT);
						i_enemy++;
						if (i_enemy == 3 * enemy_vx)
							i_enemy = 0;
					}
					if (abs(enemy_x[i] - role_x) <= 200)//距离近的时候开始蓄力
					{
						putimage(enemy_x[i], enemy_y[i], 61, 55, &img_enemy2, bk[now_of_bk].enemy_direction[i] * 122, bk[now_of_bk].enemy_direction[i] * 55, SRCAND);
						putimage(enemy_x[i], enemy_y[i], 61, 55, &img_enemy1, bk[now_of_bk].enemy_direction[i] * 122, bk[now_of_bk].enemy_direction[i] * 55, SRCPAINT);
					}


				}
				if (bk[now_of_bk].hp_of_enemy[i] == 5)//初始位置
				{
					putimage(enemy_x[i], enemy_y[i], 61, 55, &img_enemy2, 122, 55, SRCAND);
					putimage(enemy_x[i], enemy_y[i], 61, 55, &img_enemy1, 122, 55, SRCPAINT);
				}
			}
		}
	}
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
		putimage(role_x - 33, role_y - 76, &img_jump[0][direction], NOTSRCERASE); //显示人物
		putimage(role_x - 33, role_y - 76, &img_jump[1][direction], SRCINVERT);
	}
	else if (delay_attack == 1)
	{
		putimage(role_x - x_attack[j_attack] / 2, role_y - y_attack[j_attack], x_attack[j_attack], y_attack[j_attack], &img_attack[0][j_attack], i_attack / 10 * x_attack[j_attack], direction * y_attack[j_attack], SRCAND); //显示人物
		putimage(role_x - x_attack[j_attack] / 2, role_y - y_attack[j_attack], x_attack[j_attack], y_attack[j_attack], &img_attack[1][j_attack], i_attack / 10 * x_attack[j_attack], direction *  y_attack[j_attack], SRCPAINT);
		putimage(bullet_x, bullet_y, &img_bullet[direction][0], NOTSRCERASE);
		putimage(bullet_x, bullet_y, &img_bullet[direction][1], SRCINVERT);
		i_attack++;
		if (i_attack == v_attack[j_attack])
		{
			i_attack = 0;
			j_attack = rand() % 4;
			delay_attack = 0;
		}
	}

	if (hp_of_role <= 0)
	{
		gameover();
	}
	FlushBatchDraw();
	Sleep(10);
}

void updateWithoutInput()
{
	for (i = 0; i < bk[now_of_bk].num_of_enemy; i++)
	{
		if (bk[now_of_bk].hp_of_enemy[i] <= 0)
		{
			bk[now_of_bk].enemy_birth[i]++;
		}
		if (bk[now_of_bk].enemy_birth[i] == 100)
		{
			bk[now_of_bk].hp_of_enemy[i] = 5;
			enemy_x[i] = enemy[i] + bk[now_of_bk].x;
			bk[now_of_bk].enemy_birth[i] = 0;
		}
	}

	for (i = 0; i < bk[now_of_bk].num_of_enemy; i++)//即野怪的数量
	{
		if (abs(role_y - enemy_y[i]) < 50)//判别纵坐标的差距
		{
			if (role_x < enemy_x[i])
			{
				if (abs(role_x - enemy_x[i]) < 20)//距离过近会被弹开
				{
					role_x = role_x - 100 * (2 * direction - 1);
					role_vx = 0;
					hp_of_role = hp_of_role - 1;

				}
			}
			if (role_x > enemy_x[i])
			{
				if (abs(role_x - enemy_x[i]) < 60)
				{
					role_x = role_x - 100 * (2 * direction - 1);
					role_vx = 0;
					hp_of_role = hp_of_role - 1;
				}
			}
		}
	}
	for (j = 0; j < bk[now_of_bk].num_of_enemy; j++)
	{
		if (abs(bullet_x - enemy_x[j]) < 21 && abs(bullet_y - enemy_y[j]) < 35)//判别子弹击中野怪
		{
			bullet_x = -10000;
			bk[now_of_bk].hp_of_enemy[j]--;
			bk[now_of_bk].enemy_delay[j] = 2;
		}
	}
	for (j = 0; j < bk[now_of_bk].num_of_enemy; j++)
	{

		if (bk[now_of_bk].hp_of_enemy[j] <= 0)//野怪死亡后
			enemy_x[j] = -100000;
	}



	if (abs(bullet_x - role_x) < 1000)//子弹飞行
	{
		bullet_x = bullet_x + 10 * (2 * direction - 1);
	}
	for (j = 0; j < bk[now_of_bk].num_of_enemy; j++)
	{
		if (bk[now_of_bk].hp_of_enemy[j] < 5 && 0 < bk[now_of_bk].hp_of_enemy[j])//野怪被打后有仇恨值，会靠近你并灼烧
		{
			if (enemy_x[j] > role_x + 200)
				bk[now_of_bk].enemy_x[j]--;
			if (enemy_x[j] < role_x - 200)
				bk[now_of_bk].enemy_x[j]++;

			if (enemy_x[j] <= role_x + 200 && enemy_x[j] > role_x)
			{
				if (bk[now_of_bk].enemy_delay[j] == -200)//灼烧时间久会减血
				{
					if (role_x >= 50)
					{
						role_x = role_x - 50;
						hp_of_role--;
						bk[now_of_bk].enemy_delay[j] = 2;
					}
					else

					{
						hp_of_role--;
						bk[now_of_bk].enemy_delay[j] = 2;
					}
				}
				bk[now_of_bk].enemy_delay[j]--;
			}
			if (role_x - enemy_x[j] <= 200 && role_x > enemy_x[j])
			{
				if (bk[now_of_bk].enemy_delay[j] == -200)
				{
					if (role_x <= bk[now_of_bk].length + bk[now_of_bk].x)
					{
						role_x = role_x + 50;
						hp_of_role--;
						bk[now_of_bk].enemy_delay[j] = 2;
					}
					else
					{
						hp_of_role--;
						bk[now_of_bk].enemy_delay[j] = 2;
					}
				}
				bk[now_of_bk].enemy_delay[j]--;
			}
			if (abs(role_x - enemy_x[j]) > 200)//离开野怪一定距离后灼烧消失
			{
				bk[now_of_bk].enemy_delay[j] = 2;
			}

		}
	}


	if (delay_attack != 1 || delay_jump == 1)//移动视角，根据人物位置选择移动人物还是地图
	{
		if (((role_x <= 200 && bk[now_of_bk].x < -1) && (role_vx < 0)) || ((role_x >= 600 && bk[now_of_bk].x + bk[now_of_bk].length >= 802) && (role_vx > 0)))
		{
			bk[now_of_bk].x -= role_vx;
		}
		else if (((role_x - 33 >= 2) || (role_vx > 0)) && ((role_x + 33 <= 798) || (role_vx < 0)))
			role_x += role_vx;
	}

	if (v_jump == 2)//跳跃
	{
		if (delay_climb != 1)
			delay_jump = 1;
		if (role_vy > 0)
		{
			for (i_jump = role_vy; i_jump >= 0; i_jump -= 1)//进行选择移动地图
			{
				if (role_y <= 200)
					bk[now_of_bk].y++;
				else
					role_y -= 1;		//上升
			}
		}
		else if (role_vy <= 0)
		{

			for (i_jump = -1 * role_vy; i_jump > 0; i_jump -= 1)
			{
				if (role_y >= 550 && bk[now_of_bk].y + bk[now_of_bk].high >= 600)
					bk[now_of_bk].y--;
				else
					role_y += 1;		//下落

				i_land = bk[now_of_bk].num_of_land - 1;		//存储bk[0].num_of_land的值
				while (i_land >= 0)
				{
					if (role_x <= bk[now_of_bk].x + bk[now_of_bk].x_right_land[i_land] && role_x >= bk[now_of_bk].x + bk[now_of_bk].x_left_land[i_land]
						&& (role_y >= bk[now_of_bk].y + bk[now_of_bk].y_land[i_land] && role_y <= bk[now_of_bk].y + 10 + bk[now_of_bk].y_land[i_land]))
					{
						//对于挡板的判断
						role_y = bk[now_of_bk].y_land[i_land] + bk[now_of_bk].y;
						role_vy = 0;
						role_vx = 0;
						delay_jump = 0;
						break;

					}
					i_land--;
				}
				if (role_y >= 600)
					role_y = 50;
			}
		}

		role_vy -= 2;
		if (delay_climb != 0 && role_vy < 0)
		{
			role_vy = 0;
		}
		v_jump = 0;
	}
	else
		v_jump++;

	if (delay_climb == 1)
	{
		i_rope = bk[now_of_bk].num_of_rope - 1;
		while (i_rope >= 0)
		{
			if ((role_x <= bk[now_of_bk].x + bk[now_of_bk].x_rope[i_rope] + 5 && role_x >= bk[now_of_bk].x + bk[now_of_bk].x_rope[i_rope] - 5)
				&& (role_y < bk[now_of_bk].y + bk[now_of_bk].y_down_rope[i_rope] && role_y > bk[now_of_bk].y + bk[now_of_bk].y_up_rope[i_rope]))
			{
				delay_climb = 1;
				role_vx = 0;
				delay_jump = 0;
				break;
			}
			else
				delay_climb = 0;
			i_rope--;

		}
	}
	if (delay_deliver > 0)
		delay_deliver--;


}

void updateWithInput()
{

	if ((GetAsyncKeyState(0x41) & 0x8000))		//向左走
	{
		if (role_vx == 0)
			role_vx = -2;
		delay_walk = 1;
		if (delay_attack != 1 || delay_jump == 1)
		{
			direction = 0;
		}
	}
	else if ((GetAsyncKeyState(0x44) & 0x8000))		//向右走
	{
		if (role_vx == 0)
			role_vx = 2;
		delay_walk = 1;
		if (delay_attack != 1 || delay_jump == 1)
		{
			direction = 1;
		}
	}
	if ((GetAsyncKeyState(0x45) & 0x8000))		//按E二段跳
	{
		role_vy += 1;
		if (direction == 1)
			role_vx = 5;
		else if (direction == 0)
			role_vx = -5;
	}

	if ((GetAsyncKeyState(0x4B) & 0x8000) && delay_jump == 0 && delay_attack == 0 && delay_climb != 1)
	{
		delay_jump = 1;		//为1时保持跳跃姿态
		role_vy = 16;		//跳跃速度
		v_jump = 2;
	}

	if ((GetAsyncKeyState(0x4A) & 0x8000))
	{
		delay_attack = 1;
		bullet_x = role_x + 50 * (2 * direction - 1);
		bullet_y = role_y - 35;
	}

	if ((GetAsyncKeyState(0x57) & 0x8000) && delay_deliver == 0)
	{
		//爬楼梯
		i_rope = bk[now_of_bk].num_of_rope - 1;
		while (i_rope >= 0)
		{
			if ((role_x <= bk[now_of_bk].x + bk[now_of_bk].x_rope[i_rope] + 5 && role_x >= bk[now_of_bk].x + bk[now_of_bk].x_rope[i_rope] - 5)
				&& (role_y <= bk[now_of_bk].y + bk[now_of_bk].y_down_rope[i_rope] && role_y >= bk[now_of_bk].y + bk[now_of_bk].y_up_rope[i_rope] + 1))//人物坐标在光圈内
			{
				role_vx = 0;
				delay_climb = 1;
				break;
			}
			else
			{
				delay_climb = 0;
			}
			i_rope--;
		}

		//传送
		if (delay_climb == 1)
		{
			if ((GetAsyncKeyState(0x4B) & 0x8000))
				role_vy = 25;

			if (role_y <= 200)
				bk[now_of_bk].y++;
			else
				role_y -= 1;
		}
		else
		{
			i_aperture = bk[now_of_bk].num_of_aperture - 1;
			while (i_aperture >= 0 && delay_deliver == 0)
			{
				if ((role_x <= bk[now_of_bk].x + bk[now_of_bk].x_aperture[i_aperture] + 25 && role_x >= bk[now_of_bk].x + bk[now_of_bk].x_aperture[i_aperture] - 25)
					&& (role_y <= bk[now_of_bk].y + bk[now_of_bk].y_aperture[i_aperture] + 10 && role_y >= bk[now_of_bk].y + bk[now_of_bk].y_aperture[i_aperture] - 10))//人物坐标在光圈内
				{
					for (i = 0; i < 5; i++)
					{
						bk[now_of_bk].enemy_delay[i] = 500;
					}
					re_of_bk = bk[now_of_bk].deliver_to_bk[i_aperture];		//记录转移去的地图
					re_of_aperture = bk[now_of_bk].deliver_to_aperture[i_aperture];		//记录转移去的光圈
					if (bk[now_of_bk].local_deliver_to_aperture[i_aperture] == 0)
					{
						role_x = 50;
						role_y = 522;
					}
					else
					{
						role_x = 750;
						role_y = 522;
					}
					bk[re_of_bk].x = role_x - bk[re_of_bk].x_aperture[re_of_aperture];
					bk[re_of_bk].y = role_y - bk[re_of_bk].y_aperture[re_of_aperture];
					now_of_bk = re_of_bk;
					delay_deliver = 100;
					break;
				}
				i_aperture--;

			}
		}
	}
	else if ((GetAsyncKeyState(0x53) & 0x8000) && delay_deliver == 0)
	{
		//向下爬楼梯
		i_rope = bk[now_of_bk].num_of_rope - 1;
		while (i_rope >= 0)
		{
			if ((role_x <= bk[now_of_bk].x + bk[now_of_bk].x_rope[i_rope] + 5 && role_x >= bk[now_of_bk].x + bk[now_of_bk].x_rope[i_rope] - 5)
				&& (role_y < bk[now_of_bk].y + bk[now_of_bk].y_down_rope[i_rope] && role_y >= bk[now_of_bk].y + bk[now_of_bk].y_up_rope[i_rope]))
			{
				delay_climb = 1;
				break;
			}
			else
			{
				delay_climb = 0;
			}
			i_rope--;
		}
		if (delay_climb == 1)
		{
			if (role_y >= 550 && bk[now_of_bk].y + bk[now_of_bk].high >= 600)
				bk[now_of_bk].y--;
			else
				role_y += 1;
			role_x = bk[now_of_bk].x + bk[now_of_bk].x_rope[i_rope];
		}
	}

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
