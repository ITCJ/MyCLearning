/*
ʵ���˶൲���Լ���ͼ��ת��

�����˵�ͼ��Ŀ

����Ż������ƶ�.����ı�ȫ���Ƶ�withoutinput ,withinput���ı��ٶ����ж�

�����˶�ȫ�����,����Ҳ���ڸ���ͼ����,ֻҪ�������ݼ������־Ϳ�����

A�����ƶ�,D�����ƶ�,J����,K��Ծ,Wת����ͼ(���ڹ�Ȧ��),WҲ��Ϊ������(��������),

EΪ������,������Ϊû���ӳ�,���Ե�����������(������Ҳ����)
*/
#include <graphics.h>
#include <conio.h>
#include <stdlib.h>
#include <math.h>
#include <stdio.h>
#include <mmsystem.h>

// ���� Windows Multimedia API
#pragma comment(lib,"Winmm.lib")

#define High 600  // ��Ϸ����ߴ�
#define Width 800
struct barkgound		//���ڵ�ͼ�Ķ���
{

	int x;	//��ͼλ��
	int y;
	int length;		//��ͼ����
	int high;
	//����
	int num_of_land;
	int x_left_land[30];	//������˵�
	int x_right_land[30];//�����Ҷ˵�
	int y_land[30];		//����������
						//��Ȧ
	int num_of_aperture;	//ʵ�ʹ�Ȧ��Ŀ
	int x_aperture[2];	//��Ȧλ�ã�һ��ͼ�����Ϳ�����)
	int y_aperture[2];
	int deliver_to_bk[2];		//����ȥ�ĵ�ͼ
	int deliver_to_aperture[2];//����ȥ��ͼ�����Ȧ
	int local_deliver_to_aperture[2];//���͹�ȥ�����ﴦ���һ������
									 //����
	int num_of_rope;//��������
	int x_rope[6];
	int y_down_rope[6];//�������·�
	int y_up_rope[6];//�������Ϸ�
					 //����
	int num_of_enemy;//���˵�����
	int enemy_x[5];//���˵ĺ�����
	int enemy_y[5];//���˵�������
	int hp_of_enemy[5];//���˵�����
	int enemy_direction[5];//���˵ķ���
	int enemy_delay[5];//�����ӳ�
	int enemy_attack;//Ұ�ֹ�������ֵ
					 //��������������Ұ�ֵ�λ��
	int enemy_high;//Ұ�ֵĸ߶�
	int enemy_width;//Ұ�ֵĿ��
	int enemy_birth[5];
};
int i_land;		//�����жϵ���
int i_aperture;			//�����жϹ�Ȧ
int i_rope;		//�����ж�����

barkgound bk[5];		//���ŵ�ͼ�͹��˰�
int now_of_bk;		//��ǰ�ĵ�ͼ
int re_of_bk;	//����ȥ�ĵ�ͼ
int re_of_aperture;//���͹�ȥ�Ĵ��͵�

IMAGE img_bk_bk;	//�����ı���
IMAGE img_bk[2][5];
IMAGE img_end;//��������
IMAGE img_walk[2];//��������
IMAGE img_stand[2];//����ս��
IMAGE img_jump[2][2];//������Ծ 0�ڸǣ�1ԭͼ  0����1����
IMAGE img_attack[2][4];//���﹥��

IMAGE img_bullet[2][2];//�ӵ�������
int bullet_x, bullet_y;//�ӵ��ĺᣬ������
IMAGE img_enemy1;
IMAGE img_enemy2;
int enemy_x[5], enemy_y[5];//���˵ĺ�������
int enemy_walk = 10;//��������ͼƬ���л���
int i_enemy = 0;//�������ߵı���
int enemy_vx = 10;//�������ߵı���
int enemy[5];


int direction = 0;		//���﷽��
int role_x, role_y; // ����λ��
int role_vx = 0, role_vy = 0;//����ĺ��ݷ�����ٶ�
int hp_of_role = 3;//���������
IMAGE img_hp[2];

int i_stand = 0;//վ���ı���
int v_stand;		//վ��֡��

int i_walk = 0; //��Ϊ����
int delay_walk;		//��·ֹͣ�ӳ�

int v_walk;			//�߶�֡��

int i_jump;		//ÿ����Ծ�ľ���
int delay_jump = 1;
int v_jump = 0;		//��Ծ֡��

int delay_deliver = 0;	//���δ����ӳ�
int delay_climb = 0;	//�����ӳ�
int delay_attack = 0;
int i_attack = 0, j_attack = 0;		//i����֡����j���ƹ�������
int v_attack[4] = { 30,30,30,40 };	//��ͬ�������Ƶ��ӳ�

int x_attack[4] = { 86,90,113,116 };//���ڹ���ͼ��x����ĵ���
int y_attack[4] = { 86,76,72,94 }; //���ڹ���ͼ������ĵ���
								   //������������ʾ���˵�������
int i = 0;
int j = 0;
void startup()
{
	mciSendString(_T("open D:\\ССð�յ�\\BGM\\���ִ�ѵ����.mp3 alias startmusic"), NULL, 0, NULL);
	mciSendString(_T("play startmusic repeat"), NULL, 0, NULL);

	//bk[] = {/*bk_x*/,/*bk_y*/,/*bk_len*/,/*bkhigh*/,
	// /*������*/,{/*������*/}, { /*������*/ }, {/*�����*/ },
	// /*��Ȧ��*/, { /*��Ȧx*/ }, {/*��Ȧy*/ }, {/*��Ȧ��Ӧ��ͼ*/ }, { /*��Ȧ��Ӧ��Ȧ*/ }, {/*��Ȧ������*/ }, 
	// /*������*/ ,{����x*/},{/*�����¶�*/},{/*�����϶�*/} 
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
		21/*������*/,
		{ 0,815,2005,920,1890,1035,815,1945,480,2170,365,815,2170,1040,2055,815,1945,590,25,2280,1040/*������*/ },
		{ 2814,920,2110,1035,2005,1890,985,2110,755,2335,875,980,2710,1880,2225,980,2115,755,535,2785,1880/*������*/ },
		{ 1350,1315,1315,1240,1240,1160,1090,1090,1015,1015,785,710,710,635,635,560,560,485,410,410,260/*�����*/ },
		2/*��Ȧ��*/,{ 2670,2635 /*��Ȧx*/ },{ 1350,410/*��Ȧy*/ },{ 2,4/*��Ȧ��Ӧ��ͼ*/ },{ 1,0/*��Ȧ��Ӧ��Ȧ*/ },{ 1,0/*��Ȧ������*/ },
		6/*������*/ ,{ 685,795,356,1480,2220,2535/*����x*/ },{ 1285,1015,715,605,945,675/*�����¶�*/ },{ 1015,785,410,260,710,410/*�����϶�*/ },
		5,{ 1460,1460,1460,620,1300 },{ 1350,1165,635,785,260 },{ 5,5,5,5,5 },{ 1,1,1,1,1 },{ 2,2,2,2,2 },{ 3 },{ 55 },{ 60 }
	,{ 0,0,0,0,0 } };

	bk[4] = { 0/*bk_x*/,0/*bk_y*/,1283/*bk_len*/,1053/*bkhigh*/,
		9/*������*/,
		{ 0,285,355,420,490,555,760,490,85/*������*/ },
		{ 1283,355,420,490,555,1200,1200,725,455/*������*/ },
		{ 845,820,775,735,685,640,330,370,415/*�����*/ },
		1/*��Ȧ��*/,{ 165 /*��Ȧx*/ },{ 845/*��Ȧy*/ },{ 3/*��Ȧ��Ӧ��ͼ*/ },{ 1/*��Ȧ��Ӧ��Ȧ*/ },{ 1/*��Ȧ������*/ },
		1/*������*/ ,{ 805/*����x*/ },{ 575/*�����¶�*/ },{ 330/*�����϶�*/ } ,
		5,{ 510,1060,825 ,1085,200 },{ 845,845,640,325,415 },{ 5,5,5,5,5 },{ 1,1,1,1,1 },{ 2,2,2,2,2 },{ 3 },{ 55 },{ 60 }
	,{ 0,0,0,0,0 } };

	now_of_bk = 1;//��ʼ��λ��

	v_stand = 50;//�ٶ�
	v_walk = 20;//�ٶ�

	delay_walk = 10;//���ߵ�֡��
	initgraph(Width, High);
	//����
	loadimage(&img_bk_bk, _T(".\\ССð�յ�\\����\\bk.jpg"));
	loadimage(&img_end, _T(".\\ССð�յ�\\����\\end.jpg"));
	loadimage(&img_bk[0][1], _T(".\\ССð�յ�\\����\\backgound01 1367 648.jpg"));
	loadimage(&img_bk[1][1], _T(".\\ССð�յ�\\����\\backgound11 1367 648.jpg"));
	loadimage(&img_bk[0][2], _T(".\\ССð�յ�\\����\\backgound02 2093 807.jpg"));
	loadimage(&img_bk[1][2], _T(".\\ССð�յ�\\����\\backgound12 2093 807.jpg"));
	loadimage(&img_bk[0][3], _T(".\\ССð�յ�\\����\\backgound03 2814 1695.jpg"));
	loadimage(&img_bk[1][3], _T(".\\ССð�յ�\\����\\backgound13 2814 1695.jpg"));
	loadimage(&img_bk[0][4], _T(".\\ССð�յ�\\����\\backgound04 1283 1053.jpg"));
	loadimage(&img_bk[1][4], _T(".\\ССð�յ�\\����\\backgound14 1283 1053.jpg"));
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

																				  //ѩ��
	loadimage(&img_bullet[1][0], _T(".\\ССð�յ�\\����\\Сѩ��\\Сѩ��10.jpg"));
	loadimage(&img_bullet[1][1], _T(".\\ССð�յ�\\����\\Сѩ��\\Сѩ��11.jpg"));
	loadimage(&img_bullet[0][0], _T(".\\ССð�յ�\\����\\Сѩ��\\Сѩ��00.jpg"));
	loadimage(&img_bullet[0][1], _T(".\\ССð�յ�\\����\\Сѩ��\\Сѩ��01.jpg"));
	//����
	loadimage(&img_enemy1, _T(".\\ССð�յ�\\����\\����\\���� walk12 61 55 .bmp"));
	loadimage(&img_enemy2, _T(".\\ССð�յ�\\����\\����\\���� walk02 61 55 .bmp"));
	//��������Ϊ��
	loadimage(&img_hp[0], _T(".\\ССð�յ�\\����\\hp0 20 23.jpg"));
	loadimage(&img_hp[1], _T(".\\ССð�յ�\\����\\hp1 20 23.jpg"));
	role_x = 500;
	role_y = 500;
	//��ʼӡˢ
	BeginBatchDraw();
}
void stand()
{
	v_stand = 25;
	putimage(role_x - 32, role_y - 76, 65, 76, &img_stand[0], i_stand / v_stand * 65, direction * 76, NOTSRCERASE); //��ʾ����
	putimage(role_x - 32, role_y - 76, 65, 76, &img_stand[1], i_stand / v_stand * 65, direction * 76, SRCINVERT);
	i_stand++;
	if (i_stand == 4 * v_stand)
		i_stand = 0;
}

void role_walk()
{
	v_walk = 10;
	putimage(role_x - 33, role_y - 76, 67, 76, &img_walk[0], i_walk / v_walk * 67, direction * 76, NOTSRCERASE); //��ʾ����
	putimage(role_x - 33, role_y - 76, 67, 76, &img_walk[1], i_walk / v_walk * 67, direction * 76, SRCINVERT);
	i_walk++;
	if (i_walk == 4 * v_walk)//�ظ����ͼƬ����̬
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
	putimage(bk[now_of_bk].x, bk[now_of_bk].y, &img_bk[1][now_of_bk], SRCINVERT);	// ��ʾ����	
	for (i = 0; i < hp_of_role; i++)
	{
		putimage(23 * i, 0, &img_hp[0], NOTSRCERASE);
		putimage(23 * i, 0, &img_hp[1], SRCINVERT);//���Ѫ��
	}

	if (now_of_bk == 3 || now_of_bk == 4)
	{
		for (i = 0; i < bk[now_of_bk].num_of_enemy; i++)
		{				//���˻�����
			if (bk[now_of_bk].hp_of_enemy[i] > 0)
			{
				enemy_x[i] = bk[now_of_bk].x + bk[now_of_bk].enemy_x[i] - bk[now_of_bk].enemy_width / 2;
				enemy_y[i] = bk[now_of_bk].y + bk[now_of_bk].enemy_y[i] - bk[now_of_bk].enemy_high;
				if (role_x > enemy_x[i])				//��������˵������жϳ����˵��ƶ�����
					bk[now_of_bk].enemy_direction[i] = 1;
				if (role_x <= enemy_x[i])
					bk[now_of_bk].enemy_direction[i] = 0;
				if (bk[now_of_bk].hp_of_enemy[i] > 0 && bk[now_of_bk].hp_of_enemy[i] < 5)
				{
					if (abs(enemy_x[i] - role_x)>200)//�������ܵ�������������ƶ��������ʱ����
					{
						enemy_walk = 25;
						putimage(enemy_x[i], enemy_y[i], 61, 55, &img_enemy2, i_enemy / enemy_vx * 61, bk[now_of_bk].enemy_direction[i] * 55, SRCAND);
						putimage(enemy_x[i], enemy_y[i], 61, 55, &img_enemy1, i_enemy / enemy_vx * 61, bk[now_of_bk].enemy_direction[i] * 55, SRCPAINT);
						i_enemy++;
						if (i_enemy == 3 * enemy_vx)
							i_enemy = 0;
					}
					if (abs(enemy_x[i] - role_x) <= 200)//�������ʱ��ʼ����
					{
						putimage(enemy_x[i], enemy_y[i], 61, 55, &img_enemy2, bk[now_of_bk].enemy_direction[i] * 122, bk[now_of_bk].enemy_direction[i] * 55, SRCAND);
						putimage(enemy_x[i], enemy_y[i], 61, 55, &img_enemy1, bk[now_of_bk].enemy_direction[i] * 122, bk[now_of_bk].enemy_direction[i] * 55, SRCPAINT);
					}


				}
				if (bk[now_of_bk].hp_of_enemy[i] == 5)//��ʼλ��
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
		putimage(role_x - 33, role_y - 76, &img_jump[0][direction], NOTSRCERASE); //��ʾ����
		putimage(role_x - 33, role_y - 76, &img_jump[1][direction], SRCINVERT);
	}
	else if (delay_attack == 1)
	{
		putimage(role_x - x_attack[j_attack] / 2, role_y - y_attack[j_attack], x_attack[j_attack], y_attack[j_attack], &img_attack[0][j_attack], i_attack / 10 * x_attack[j_attack], direction * y_attack[j_attack], SRCAND); //��ʾ����
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

	for (i = 0; i < bk[now_of_bk].num_of_enemy; i++)//��Ұ�ֵ�����
	{
		if (abs(role_y - enemy_y[i]) < 50)//�б�������Ĳ��
		{
			if (role_x < enemy_x[i])
			{
				if (abs(role_x - enemy_x[i]) < 20)//��������ᱻ����
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
		if (abs(bullet_x - enemy_x[j]) < 21 && abs(bullet_y - enemy_y[j]) < 35)//�б��ӵ�����Ұ��
		{
			bullet_x = -10000;
			bk[now_of_bk].hp_of_enemy[j]--;
			bk[now_of_bk].enemy_delay[j] = 2;
		}
	}
	for (j = 0; j < bk[now_of_bk].num_of_enemy; j++)
	{

		if (bk[now_of_bk].hp_of_enemy[j] <= 0)//Ұ��������
			enemy_x[j] = -100000;
	}



	if (abs(bullet_x - role_x) < 1000)//�ӵ�����
	{
		bullet_x = bullet_x + 10 * (2 * direction - 1);
	}
	for (j = 0; j < bk[now_of_bk].num_of_enemy; j++)
	{
		if (bk[now_of_bk].hp_of_enemy[j] < 5 && 0 < bk[now_of_bk].hp_of_enemy[j])//Ұ�ֱ�����г��ֵ���῿���㲢����
		{
			if (enemy_x[j] > role_x + 200)
				bk[now_of_bk].enemy_x[j]--;
			if (enemy_x[j] < role_x - 200)
				bk[now_of_bk].enemy_x[j]++;

			if (enemy_x[j] <= role_x + 200 && enemy_x[j] > role_x)
			{
				if (bk[now_of_bk].enemy_delay[j] == -200)//����ʱ��û��Ѫ
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
			if (abs(role_x - enemy_x[j]) > 200)//�뿪Ұ��һ�������������ʧ
			{
				bk[now_of_bk].enemy_delay[j] = 2;
			}

		}
	}


	if (delay_attack != 1 || delay_jump == 1)//�ƶ��ӽǣ���������λ��ѡ���ƶ����ﻹ�ǵ�ͼ
	{
		if (((role_x <= 200 && bk[now_of_bk].x < -1) && (role_vx < 0)) || ((role_x >= 600 && bk[now_of_bk].x + bk[now_of_bk].length >= 802) && (role_vx > 0)))
		{
			bk[now_of_bk].x -= role_vx;
		}
		else if (((role_x - 33 >= 2) || (role_vx > 0)) && ((role_x + 33 <= 798) || (role_vx < 0)))
			role_x += role_vx;
	}

	if (v_jump == 2)//��Ծ
	{
		if (delay_climb != 1)
			delay_jump = 1;
		if (role_vy > 0)
		{
			for (i_jump = role_vy; i_jump >= 0; i_jump -= 1)//����ѡ���ƶ���ͼ
			{
				if (role_y <= 200)
					bk[now_of_bk].y++;
				else
					role_y -= 1;		//����
			}
		}
		else if (role_vy <= 0)
		{

			for (i_jump = -1 * role_vy; i_jump > 0; i_jump -= 1)
			{
				if (role_y >= 550 && bk[now_of_bk].y + bk[now_of_bk].high >= 600)
					bk[now_of_bk].y--;
				else
					role_y += 1;		//����

				i_land = bk[now_of_bk].num_of_land - 1;		//�洢bk[0].num_of_land��ֵ
				while (i_land >= 0)
				{
					if (role_x <= bk[now_of_bk].x + bk[now_of_bk].x_right_land[i_land] && role_x >= bk[now_of_bk].x + bk[now_of_bk].x_left_land[i_land]
						&& (role_y >= bk[now_of_bk].y + bk[now_of_bk].y_land[i_land] && role_y <= bk[now_of_bk].y + 10 + bk[now_of_bk].y_land[i_land]))
					{
						//���ڵ�����ж�
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

	if ((GetAsyncKeyState(0x41) & 0x8000))		//������
	{
		if (role_vx == 0)
			role_vx = -2;
		delay_walk = 1;
		if (delay_attack != 1 || delay_jump == 1)
		{
			direction = 0;
		}
	}
	else if ((GetAsyncKeyState(0x44) & 0x8000))		//������
	{
		if (role_vx == 0)
			role_vx = 2;
		delay_walk = 1;
		if (delay_attack != 1 || delay_jump == 1)
		{
			direction = 1;
		}
	}
	if ((GetAsyncKeyState(0x45) & 0x8000))		//��E������
	{
		role_vy += 1;
		if (direction == 1)
			role_vx = 5;
		else if (direction == 0)
			role_vx = -5;
	}

	if ((GetAsyncKeyState(0x4B) & 0x8000) && delay_jump == 0 && delay_attack == 0 && delay_climb != 1)
	{
		delay_jump = 1;		//Ϊ1ʱ������Ծ��̬
		role_vy = 16;		//��Ծ�ٶ�
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
		//��¥��
		i_rope = bk[now_of_bk].num_of_rope - 1;
		while (i_rope >= 0)
		{
			if ((role_x <= bk[now_of_bk].x + bk[now_of_bk].x_rope[i_rope] + 5 && role_x >= bk[now_of_bk].x + bk[now_of_bk].x_rope[i_rope] - 5)
				&& (role_y <= bk[now_of_bk].y + bk[now_of_bk].y_down_rope[i_rope] && role_y >= bk[now_of_bk].y + bk[now_of_bk].y_up_rope[i_rope] + 1))//���������ڹ�Ȧ��
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

		//����
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
					&& (role_y <= bk[now_of_bk].y + bk[now_of_bk].y_aperture[i_aperture] + 10 && role_y >= bk[now_of_bk].y + bk[now_of_bk].y_aperture[i_aperture] - 10))//���������ڹ�Ȧ��
				{
					for (i = 0; i < 5; i++)
					{
						bk[now_of_bk].enemy_delay[i] = 500;
					}
					re_of_bk = bk[now_of_bk].deliver_to_bk[i_aperture];		//��¼ת��ȥ�ĵ�ͼ
					re_of_aperture = bk[now_of_bk].deliver_to_aperture[i_aperture];		//��¼ת��ȥ�Ĺ�Ȧ
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
		//������¥��
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
