#include"function.h"

void init() {

	//�öδ��빦�������ع�꣬������win32��̽ӿڣ�����Ҫ����
	HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);//��ȡ���ھ��
	CONSOLE_CURSOR_INFO cci;//ʵ�л�һ������̨�����Ϣ��
	GetConsoleCursorInfo(hOut, &cci);//��ȡ�����Ϣ
	cci.bVisible = FALSE;//���ع��
	SetConsoleCursorInfo(hOut, &cci);//���ù����Ϣ

	system("title ������1.0");//�趨��������
	system("mode con cols=120 lines=30");//�趨���ڴ�С
}

void mainloop() {
	int level, level_option,scenes;
	char option;
	int isEnd;

	//��ʼ������
	level = 0;
	level_option = 1;
	scenes = 0;
	isEnd = 0;

	//���ƽ���
	//������
	char main_interface[50][50] = {
		"\n\n\n\n\n\n\n",
		"\t\t\t\t\t\t\t ������",
		"\t\t\t\t\t\t   |===============|",
		"\t\t\t\t\t\t   |               |",
		"\t\t\t\t\t\t   |               |",
		"\t\t\t\t\t\t   |    ��ʼ(S)    |",
		"\t\t\t\t\t\t   |               |",
		"\t\t\t\t\t\t   |   �˳�(ESC)   |",
		"\t\t\t\t\t\t   |               |",
		"\t\t\t\t\t\t   |               |",
		"\t\t\t\t\t\t   |===============|",
	};

	//���˵�2
	char menu2[50][50] = {
		"\n\n\n\n\n\n\n\n",
		"\t\t\t\t\t\t\t ������\n",
		"\t\t\t\t\t\t   |===============|",
		"\t\t\t\t\t\t   |               |",
		"\t\t\t\t\t\t   |   ��ͷ��ʼ(A) |",
		"\t\t\t\t\t\t   |               |",
		"\t\t\t\t\t\t   |    ѡ��(X)    |",
		"\t\t\t\t\t\t   |               |",
		"\t\t\t\t\t\t   |    ����(R)    |",
		"\t\t\t\t\t\t   |               |",
		"\t\t\t\t\t\t   |===============|"
	};


	//��ʼ��Ϣѭ��
	while (1){//������ԶΪ�棬����ѭ��

		//�����ӡ
		system("cls");//�����Ļ
		switch (scenes){
		case 0:
			//��ӡ������
			for (int i = 0; i < 11; i++)
				puts(main_interface[i]);
			break;
		case 1:
			//��ӡ���˵�2
			for (int i = 0; i < 11; i++)
				puts(menu2[i]);
			break;
		case 2:
			//��ӡ�ؿ�ѡ�����
			printf("\n\n\n\n\n\n\n\n\n\n\n");
			printf("\t\t\t\t\t\t");
			printf("��ѡ��ؿ�(1-%d):%d", maps_num, level_option);
			break;
		default:
			break;
		}

		//��ȡ��������
		if (scenes < 3) {
			option = getch();
			option = tolower(option);//�����������ĸ���ΪСд
		}

		//�¼��ж�
		switch (scenes){
		case 0://�������¼��ж�
			if (option == 's')
				scenes = 1;
			else if (option == 27) {
				isEnd = 1;
			}
			break;
		case 1://���˵�2�¼��ж�
			if (option == 'r'|| option == 27)//�����ϼ��˵�
				scenes = 0;
			else if (option == 'a') {
				scenes = 3;
			}
			else if (option == 'x') {
				scenes = 2;
			}
			break;
		case 2://�ؿ�ѡ������¼��ж�
			if ((option == 'a') && level_option > 1)
				level_option--;
			else if ((option == 'd') && level_option < maps_num)
				level_option++;
			else if ((option == 30 || option == 32)) {
				level = level_option - 1;
				scenes = 4;
			}
			else if (option == 27)
				scenes = 1;
			break;
		case 3://��ͷ��ʼ
			level = 0;
			scenes = gameloop(level);//������Ϸ
			break;
		case 4://��ʼ��ǰ�ؿ�
			scenes = gameloop(level);
			break;
		case 5://������һ��
			level++;
			scenes = 4;
			break;
		case 6://ͨ����������
			scenes = 0;
			level = 0;
			break;
		default:
			break;
		}

		if (isEnd)
			break;
	}
}

int gameloop(int level)
{
	//��������
	//i,t ѭ��������, x ������, y ������
	//restep_num ��¼ÿ�ֳ�������,step_num ��¼�����ܲ���,wide ��ͼ���
	int x, y,restep_num, step_num, wide;
	//(ch ��Ϸ�����ж�ȡ������Ϣ,last_step ��¼��һ������)
	char option, last_step;
	//���������飬��¼�յ�����
	int X_num[50] = { 0 }, Y_num[50] = { 0 }, xnum, ynum;
	//lstep ��¼�Ƿ�����,x_box ��¼��һ��������ǰ�����������,y_box ��¼��һ��������ǰ��ĺ�������, rerestep_num ��¼��һ��������ǰ���ߵĲ���
	int lstep, x_box, y_box, rerestep_num;
	int map_high;
	int scenes;
	int reValue;
	int isEnd;

	//��Ϸ��ʼ��
	//���弰��ʼ����ͼ
	char map[50][50] = { 0 };
	LoadMap(level, &map_high, map);

	//��ʼ������
	wide = step_num = restep_num = 0;
	option=last_step = NULL;
	xnum = ynum = 0;
	lstep = 0;
	scenes = 0;
	reValue = 0;
	isEnd = 0;

	//��ʼ����ʼλ��
	for (int i = 0; i < 20; i++){
		for (int t = 0; map[i][t] != '\0'; t++)
			if (map[i][t] == '@'){
				x = i;
				y = t;
				i = 99;
				break;
			}
	}

	//Ѱ���յ�����
	for (int i = 2; i < 20; i++){
		for (int t = 2; map[i][t] != '\0'; t++){
			if (map[i][t] == 'X' || map[i][t] == 'Q'){
				X_num[xnum] = i;
				Y_num[ynum] = t;
				xnum++;
				ynum++;
			}
			if (i == map_high){
				i = 99;
				break;
			}
		}
	}

	//�����ͼ���
	wide = strlen(map[0]);

	//��Ϸ��ѭ��
	while (1) {

		//�����ӡ
		system("cls");//�����Ļ
		switch (scenes){
		case 0:
			//��Ϸ����
			printf("\n\n\n\n\t\t\t\t\t\t         ��%d��", level + 1);
			printf("\n\n");
			for (int i = 0; i <= 17; i++)
			{
				for (int t = 0; t < (120 - wide) / 2; t++)
					printf(" ");
				puts(map[i]);
			}
			printf("\t\t\t\t\t\t������%d  ʣ�೷��������%d", step_num, 3 - restep_num);
			printf("\n\n\t\t\t\t\t      ���汾��(Q) ����(B) �˵�(ESC)");
			break;
		case 1:
			//��ͣ����
			printf("\n\n\n\n\n\t\t\t\t\t\t        ����(R)\n");
			printf("\n\n\t\t\t\t         ѡ��(X)  ����(Q)  ��һ��(N)  ���˵�(M)  \n");
			printf("\n\n\n\t\t\t\t\t\t      ����˵��");
			printf("\n\n\t\t\t\t\t        W:��  S:��  A:��  D:��");
			printf("\n\n\t\t\t\t\t         @:��  O:����  X:�յ� ");
			break;
		case 2:
			//���ؽ���
			if (level == maps_num - 1)
				printf("\n\n\n\n\n\n\n\t\t\t\t\t\t���Ѿ������һ���ˣ�");
			else
				printf("\n\n\n\n\n\n\n\t\t\t\t\t\t\t  ����!");
			printf("\n\n\t\t\t\t\t\t    �����ܼƲ�����%d", step_num);
			if (level == maps_num - 1)
				printf("\n\n\t\t\t\t\t  ѡ��(X)  ����(Q)  ���˵�(M)  \n");
			else
				printf("\n\n\t\t\t\t\t  ѡ��(X)  ����(Q)  ��һ��(N)  ���˵�(M)  \n");
			break;
		default:
			break;
		}

		//��ȡ��������
		option = getch();
		option = tolower(option);//�����������ĸ���ΪСд

		//�¼��ж�
		switch (scenes){
		case 0:
			if (option =='s'){//�����ƶ�
				if (map[x + 1][y] == ' ' || map[x + 1][y] == 'X')
				{
					map[x][y] = ' ';
					x++;
					map[x][y] = '@';
					step_num++;
				}
				else if ((map[x + 1][y] == 'O' || map[x + 1][y] == 'Q') && map[x + 2][y] != 'O' && map[x + 2][y] != 'Q' && map[x + 2][y] != '#')
				{
					map[x][y] = ' ';
					x++;
					map[x][y] = '@';
					map[x + 1][y] = 'O';
					lstep = 1;
					x_box = x;
					y_box = y;
					rerestep_num = step_num;
					step_num++;
					last_step = option;//�洢��һ����Ϣ
				}
			}
			else if (option == 'w') {//�����ƶ�
				if (map[x - 1][y] == ' ' || map[x - 1][y] == 'X')
				{
					map[x][y] = ' ';
					x--;
					map[x][y] = '@';
					step_num++;
				}
				else if ((map[x - 1][y] == 'O' || map[x - 1][y] == 'Q') && map[x - 2][y] != 'O' && map[x - 2][y] != 'Q' && map[x - 2][y] != '#')
				{
					map[x][y] = ' ';
					x--;
					map[x][y] = '@';
					map[x - 1][y] = 'O';
					lstep = 1;
					x_box = x;
					y_box = y;
					rerestep_num = step_num;
					step_num++;
					last_step = option;//�洢��һ����Ϣ
				}
			}
			else if (option == 'a') {//�����ƶ�
				if (map[x][y - 1] == ' ' || map[x][y - 1] == 'X')
				{
					map[x][y] = ' ';
					y--;
					map[x][y] = '@';
					step_num++;
				}
				else if ((map[x][y - 1] == 'O' || map[x][y - 1] == 'Q') && map[x][y - 2] != 'O' && map[x][y - 2] != 'Q' && map[x][y - 2] != '#')
				{
					map[x][y] = ' ';
					y--;
					map[x][y] = '@';
					map[x][y - 1] = 'O';
					lstep = 1;
					x_box = x;
					y_box = y;
					rerestep_num = step_num;
					step_num++;
					last_step = option;//�洢��һ����Ϣ
				}
				break;
			}
			else if (option == 'd') {//�����ƶ�
				if (map[x][y + 1] == ' ' || map[x][y + 1] == 'X')
				{
					map[x][y] = ' ';
					y++;
					map[x][y] = '@';
					step_num++;
				}
				else if ((map[x][y + 1] == 'O' || map[x][y + 1] == 'Q') && map[x][y + 2] != 'O' && map[x][y + 2] != 'Q'&&map[x][y + 2] != '#')
				{
					map[x][y] = ' ';
					y++;
					map[x][y] = '@';
					map[x][y + 1] = 'O';
					lstep = 1;
					x_box = x;
					y_box = y;
					rerestep_num = step_num;
					step_num++;
					last_step = option;//�洢��һ����Ϣ
				}
			}
			else if (option == 'b') {
				//����һ��
				if (lstep == 1 && restep_num < 3){
					switch (last_step){
					case 's'://���������ƶ�
						map[x][y] = ' ';
						map[x_box + 1][y_box] = ' ';
						map[x_box][y_box] = 'O';
						x_box--;
						x = x_box;
						y = y_box;
						map[x][y] = '@';
						step_num = rerestep_num;
						restep_num++;
						lstep = 0;
						break;
					case 'w'://���������ƶ�
						map[x][y] = ' ';
						map[x_box - 1][y_box] = ' ';
						map[x_box][y_box] = 'O';
						x_box++;
						x = x_box;
						y = y_box;
						map[x][y] = '@';
						step_num = rerestep_num;
						restep_num++;
						lstep = 0;
						break;
					case 'a'://���������ƶ�
						map[x][y] = ' ';
						map[x_box][y_box - 1] = ' ';
						map[x_box][y_box] = 'O';
						y_box++;
						x = x_box;
						y = y_box;
						map[x][y] = '@';
						step_num = rerestep_num;
						restep_num++;
						lstep = 0;
						break;
					case 'd'://���������ƶ�
						map[x][y] = ' ';
						map[x_box][y_box + 1] = ' ';
						map[x_box][y_box] = 'O';
						y_box--;
						x = x_box;
						y = y_box;
						map[x][y] = '@';
						step_num = rerestep_num;
						restep_num++;
						lstep = 0;
						break;
					}
				}
			}
			else if (option == 'q') {
				reValue = 4;
				isEnd = 1;
			}
			else if (option == 27) {
				scenes = 1;
			}
			break;
		case 1:
			if (option == 'r'||option==27) {
				scenes = 0;
			}
			else if (option == 'x') {
				reValue = 2;
				isEnd = 1;
			}
			else if (option == 'q') {
				reValue = 4;
				isEnd = 1;
			}
			else if (option == 'n') {
				reValue = 5;
				isEnd = 1;
			}
			else if (option == 'm') {
				reValue = 1;
				isEnd = 1;
			}
			break;
		case 2:
			if (option == 'x') {
				reValue = 2;
				isEnd = 1;
			}
			else if (option == 'q') {
				reValue = 4;
				isEnd = 1;
			}
			else if (option == 'n'&&level != maps_num - 1) {
				reValue = 5;
				isEnd = 1;
			}
			else if (option == 'm') {
				reValue = 1;
				isEnd = 1;
			}
			break;
		default:
			break;
		}

		//�߼�����

		//��ԭ�յ���
		for (int i = 0; X_num[i] != 0; i++)
		{
			if (map[X_num[i]][Y_num[i]] == ' ')
				map[X_num[i]][Y_num[i]] = 'X';
			if (map[X_num[i]][Y_num[i]] == 'O')
				map[X_num[i]][Y_num[i]] = 'Q';
		}

		//ͨ�������ж�
		int count=0;
		for (int i = 0; X_num[i] != 0; i++){
			if (map[X_num[i]][Y_num[i]] == 'Q')
				count++;
		}
		if (count == xnum){
			scenes = 2;
		}

		if (isEnd)
			break;
	}

	return reValue;
}

void LoadMap(int level, int *map_high, char(*map)[50])
{
	char buffer[256];
	FILE *fp;
	sprintf(buffer, "data\\Map\\%d.txt", level + 1);
	fp = fopen(buffer, "r");
	for (int i = 0;; i++)
	{
		fgets(map[i], 256, fp);
		map[i][strlen(map[i]) - 1] = '\0';
		if (map[i][1] == '|')
		{
			map[i][1] = '=';
			map_high = i;
			break;
		}
	}
	fclose(fp);
}
