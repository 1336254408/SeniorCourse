#pragma once
//�û����������ַ�����������* �����ص㣩
#include <graphics.h>

#include <stdio.h>
namespace test16 {
	int test()
	{
		initgraph(640, 480);

		//������������
		char str[100];
		//���öԻ�����
		inputbox_getline("������", "�㰮����ʲô������ʲô���س�ȷ�ϣ�", str, 100);

		//��ʾ���������
		outtextxy(0, 0, str);

		getch();

		closegraph();
		return 0;
	}
}