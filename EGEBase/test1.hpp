#pragma once

//��һ��ͼ�δ��ڳ���
#include "graphics.h"

namespace test1 {

	int test()
	{
		//��ʼ��Ϊ640*480��С
		initgraph(640, 480);

		//�ȴ��û�����
		getch();

		//�ر�ͼ�ν���
		closegraph();
		return 0;
	}
}