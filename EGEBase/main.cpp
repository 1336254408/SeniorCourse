#include "tests.h"

#include <iostream>

using namespace std;

int main() {

	int key = 0;

	while (true) {
		system("cls");
		cout << "\t\t\t\t\t\t\tʾ���б�" << endl;
		cout << "------------------------------------------------------------------------------------------------------------------------" << endl;
		cout << "���\t����\t\t\t\t\t\t\t\t˵��" << endl;
		cout << "------------------------------------------------------------------------------------------------------------------------" << endl;
		cout << "��ͼ����" << endl;
		cout << "------------------------------------------------------------------------------------------------------------------------" << endl;
		cout << "1\t��һ��ͼ�δ��ڳ���\t\t\t\t\t��һ��ͼ�δ��ڳ���ѧ�Ὠ�����ڽ���" << endl;
		cout << "2\t��һ����ͼ����\t\t\t\t\t\tѧ��滭�򵥵�ͼ�Σ��Լ������������˵��" << endl;
		cout << "3\tɫ�ʵļ���\t\t\t\t\t\tѧ��ʹ��ָ����ͼ��ɫ���Լ�����Ļ�ͼ����" << endl;
		cout << "4\t��ɫ���\t\t\t\t\t\tʹ�������ɫ����ʵ��ͼ��" << endl;
		cout << "5\tͼ�α߽�����\t\t\t\t\t\t�ֱ�����ͼ�α߽���ɫ�������ɫ����ͼ" << endl;
		cout << "6\t��Ļ����ɫ\t\t\t\t\t\t������Ļ�ı���ɫ" << endl;
		cout << "7\t���ֻ����������������" << endl;
		cout << "8\tͼ���ӿڲü�" << endl;
		cout << "9\tʹ��PIMAGE����ץͼ���滭��PIMAGE��PIMAGE����Ļ\t\tPIMAGE�Ļ���ʹ�÷���" << endl;
		cout << "10\tʹ��PIMAGE����ͼƬ����" << endl;
		cout << "11\tʹ��PIMAGE����͸������͸��" << endl;
		cout << "12\t�û�������������1" << endl;
		cout << "13\t�û�������������2" << endl;
		cout << "14\t�û������������1" << endl;
		cout << "15\t�û������������2" << endl;
		cout << "16\t�û����������ַ�����������" << endl;
		cout << "17\t��������ֶ��뷽ʽ����" << endl;
		cout << "18\t�������ɫ��ʾ�취(HSV/HSL)" << endl;
		cout << "19\t�߼����滭����ɫ/�ʺ�" << endl;
		cout << "------------------------------------------------------------------------------------------------------------------------" << endl;
		cout << "ͼ�ζ�������" << endl;
		cout << "------------------------------------------------------------------------------------------------------------------------" << endl;
		cout << "20\t��������һ���淶���\t\t\t\t\t��һ��ͼ�ζ����淶���ʾ��" << endl;
		cout << "21\t��������������ƽ�ƶ���\t\t\t\t��ƽ��ʾ��" << endl;
		cout << "22\t���������������ḻ�ı仯��֡��\t\t\t\tƽ����ײ��֡����ʾʾ��" << endl;
		cout << "23\t���������ģ���͸�����뵭��\t\t\t\t͸����͸��������ʾʾ��" << endl;
		cout << "24\t���������壬�����װ��ʹ�����������\t\t\t�����װʾ��" << endl;
		cout << "25\t���������������ö����װ����ʾ�������\t\t\t�����װӦ��ʾ��" << endl;
		cout << "26\t���������ߣ�ʹ�÷��������������ɫ�ʣ�ʹ��Ķ�������Ȼ\t�����װ����Ӧ��ʾ��" << endl;
		cout << "27\t���������ˣ�ʹ��C++��װ��Ķ���\t\t\t\tC++�����װʾ��" << endl;
		cout << "28\t���������ţ�ʹ�ó����������ؿ��ƶ���\t\t\t��������ʾ��" << endl;
		cout << "29\t��������ʮ�����������µ������������\t\t\t��ʵ���Ѿ��Ǽ򵥵���Ϸʾ��" << endl;
		cout << "------------------------------------------------------------------------------------------------------------------------" << endl;
		cout << "99\t�˳�" << endl;
		cout << "------------------------------------------------------------------------------------------------------------------------" << endl;
		cout << "������Ҫִ��ʾ���ı��:" ;

		cin >> key;
		switch (key)
		{
		case 1:
			test1::test();
			break;
		case 2:
			test2::test();
			break;
		case 3:
			test3::test();
			break;
		case 4:
			test4::test();
			break;
		case 5:
			test5::test();
			break;
		case 6:
			test6::test();
			break;
		case 7:
			test7::test();
			break;
		case 8:
			test8::test();
			break;
		case 9:
			test9::test();
			break;
		case 10:
			test10::test();
			break;
		case 11:
			test11::test();
			break;
		case 12:
			test12::test();
			break;
		case 13:
			test13::test();
			break;
		case 14:
			test14::test();
			break;
		case 15:
			test15::test();
			break;
		case 16:
			test16::test();
			break;
		case 17:
			test17::test();
			break;
		case 18:
			test18::test();
			break;
		case 19:
			test19::test();
			break;
		case 20:
			test20::test();
			break;
		case 21:
			test21::test();
			break;
		case 22:
			test22::test();
			break;
		case 23:
			test23::test();
			break;
		case 24:
			test24::test();
			break;
		case 25:
			test25::test();
			break;
		case 26:
			test26::test();
			break;
		case 27:
			test27::test();
			break;
		case 28:
			test28::test();
			break;
		case 29:
			test29::test();
			break;
		case 99:
			return 0;
			break;
		default:
			break;
		}

	}

	return 0;
}