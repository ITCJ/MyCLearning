/*�����Ѿ�����ʵ���߶���վ��
VK_LEFT VK_RIGHT ʵ�����������ƶ�
������һ����Ծ��� ��VK_LCONTROL ����
��Ծ��VK_SPACE����
*/

#include <graphics.h>
#include <conio.h>
#include <stdlib.h>
#include <math.h>
#include <stdio.h>

// ���� Windows Multimedia API
#pragma comment(lib,"Winmm.lib")

#define High 464  // ��Ϸ����ߴ�
#define Width 580

IMAGE img_bk; // ����ͼƬ
int img_bk_x, img_bk_y;  //��������λ��
int img_bk_b_x1, img_bk_b_x2, img_bk_b_y;
IMAGE img_walk[2];//��������
IMAGE img_stand[2];//����ս��
IMAGE img_jump[2][2];//������Ծ 0�ڸǣ�1ԭͼ  0����1����
IMAGE img_attack[2][4];//���﹥��

int direction = 0;		//���﷽��
float role_x, role_y; // ����λ��
int role_vx = 0, role_vy = 0;	//�����ƶ��ٶ�

int i_stand = 0;
int v_stand;		//վ��֡��

int i_walk = 0; //��Ϊ����
int delay_walk;		//��·ֹͣ�ӳ�

int v_walk;			//�߶�֡��

int i_jump;			//������Ծ�ı���
int delay_jump = 1;
int v_jump = 0;		//��Ծ֡��

int delay_attack = 0;
int i_attack = 0, j_attack = 0;		//i����֡����j���ƹ�������
int v_attack[4] = { 30,30,30,40 };	//��ͬ�������Ƶ��ӳ�
int x_attack[4] = { 86,90,113,116 };
int y_attack[4] = { 86,76,72,94 }; //���ڹ���ͼ��x��y����ĵ���

void startup()
{

	v_stand = 50;
	v_walk = 20;

	delay_walk = 10;
	initgraph(Width, High);
	img_bk_x = 0;
	img_bk_y = High - 648;	//�������λ��



	loadimage(&img_bk, _T(".\\ССð�յ�\\����\\backgound11 1367 648.jpg"));

	//�������ߣ�0Ϊ��1Ϊ��)
	loadimage(&img_walk[0], _T(".\\ССð�յ�\\����\\walk\\walk0 67 76.jpg"));
	loadimage(&img_walk[1], _T(".\\ССð�յ�\\����\\walk\\walk1 67 76.jpg"));
	//����վ��
	loadimage(&img_stand[0], _T(".\\ССð�յ�\\����\\stand\\stand0 65 76.jpg"));
	loadimage(&img_stand[1], _T(".\\ССð�յ�\\����\\stand\\stand1 65 76.jpg"));
	//������Ծ
	loadimage(&img_jump[0][0], _T(".\\ССð�յ�\\����\\jump\\jump00 67 76.jpg"));
	loadimage(&img_jump[1][0], _T(".\\ССð�յ�\\����\\jump\\jump10 67 76.jpg"));
	loadimage(&img_jump[0][1], _T(".\\ССð�յ�\\����\\jump\\jump01 67 76.jpg"));
	loadimage(&img_jump[1][1], _T(".\\ССð�յ�\\����\\jump\\jump11 67 76.jpg"));
	//���﹥��
	loadimage(&img_attack[0][0], _T(".\\ССð�յ�\\����\\attack\\attack01 86 86.bmp"));
	loadimage(&img_attack[1][0], _T(".\\ССð�յ�\\����\\attack\\attack11 86 86.bmp"));
	loadimage(&img_attack[0][1], _T(".\\ССð�յ�\\����\\attack\\attack02 90 76.bmp"));
	loadimage(&img_attack[1][1], _T(".\\ССð�յ�\\����\\attack\\attack12 90 76.bmp"));
	loadimage(&img_attack[0][2], _T(".\\ССð�յ�\\����\\attack\\attack03 113 72.bmp"));
	loadimage(&img_attack[1][2], _T(".\\ССð�յ�\\����\\attack\\attack13 113 72.bmp"));
	loadimage(&img_attack[0][3], _T(".\\ССð�յ�\\����\\attack\\attack04 116 94.bmp"));
	loadimage(&img_attack[1][3], _T(".\\ССð�յ�\\����\\attack\\attack14 116 94.bmp"));//���ֹ�����ʽ



	role_x = 0;
	role_y = 250;
	img_bk_b_y = role_y + 110 + 67;

	//��ʼӡˢ
	BeginBatchDraw();
}
void stand()
{
	v_stand = 25;


	putimage(role_x, role_y - 76, 65, 76, &img_stand[0], i_stand / v_stand * 65, direction * 76, NOTSRCERASE); //��ʾ����
	putimage(role_x, role_y - 76, 65, 76, &img_stand[1], i_stand / v_stand * 65, direction * 76, SRCINVERT);
	FlushBatchDraw();
	i_stand++;
	if (i_stand == 4 * v_stand)
		i_stand = 0;
}

void role_walk()
{
	v_walk = 10;

	putimage(role_x, role_y - 76, 67, 76, &img_walk[0], i_walk / v_walk * 67, direction * 76, NOTSRCERASE); //��ʾ����
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
	putimage(img_bk_x, img_bk_y, &img_bk);	// ��ʾ����	

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
		putimage(role_x, role_y - 76, &img_jump[0][direction], NOTSRCERASE); //��ʾ����
		putimage(role_x, role_y - 76, &img_jump[1][direction], SRCINVERT);
		FlushBatchDraw();
	}
	else if (delay_attack == 1)
	{
		putimage(role_x, role_y - y_attack[j_attack], x_attack[j_attack], y_attack[j_attack], &img_attack[0][j_attack], i_attack / 10 * x_attack[j_attack], direction * y_attack[j_attack], SRCAND); //��ʾ���﹥��ͼ��
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
		/*����ʱ���жϵ���*/
		else if (role_vy <= 0)
		{
			for (i_jump = -1 * role_vy; i_jump >= 0; i_jump -= 1)
			{
				role_y += 1;
			}
		}
		v_jump = 0;

		if (role_y < img_bk_b_y)		//���ڵ�����ж�
		{
			role_vy--;
		}
		else
		{
			role_y = img_bk_b_y;
			role_vy = 0;//�ȵ�����ʱ���������ٶ�Ϊ0,��Ծ�ӳ�Ϊ0,����������Ϊ����������
			delay_jump = 0;
		}
	}
	else
		v_jump++;



}

void updateWithInput()
{

	if ((GetAsyncKeyState(VK_LEFT) & 0x8000))	//����
	{
		role_vx = -2;
		if (delay_attack != 1 || delay_jump == 1)		//�ڹ���ʱ�����ƶ����ı䷽��,���ڿ��п���
		{
			direction = 0;
			role_x += role_vx;
		}
		delay_walk = 1;
	}
	else if ((GetAsyncKeyState(VK_RIGHT) & 0x8000))	//����
	{

		role_vx = 2;
		if (delay_attack != 1 || delay_jump == 1)		//�ڹ���ʱ�����ƶ����ı䷽��,���ڿ��п���
		{
			direction = 1;
			role_x += role_vx;
		}
		delay_walk = 1;
	}
	if ((GetAsyncKeyState(VK_SPACE) & 0x8000) && delay_jump == 0 && delay_attack == 0)
	{
		delay_jump = 1;		//Ϊ1ʱ������Ծ��̬
		role_vy = 12;		//��Ծ�ٶ�
		v_jump = 2;
	}
	if ((GetAsyncKeyState(VK_LCONTROL) & 0x8000))
	{
		delay_attack = 1;	//�����ӳ�
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
	startup();  // ���ݳ�ʼ��	
	while (1)  //  ��Ϸѭ��ִ��
	{
		show();  // ��ʾ����
		updateWithoutInput();  // ���û������޹صĸ���
		updateWithInput();     // ���û������йصĸ���
	}
	gameover();     // ��Ϸ��������������
	return 0;
}

