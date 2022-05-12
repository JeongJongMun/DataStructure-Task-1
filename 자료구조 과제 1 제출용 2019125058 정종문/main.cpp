#include <iostream>
#include "Rectangle.h"
using namespace std;

int main()
{
	/*
	-- ���� ���Ͽ� �⺻���� ���ִ� �ڵ��
	Rectangle r1(1, 1, 3, 4); // x = 1, y = 1, width = 3, height = 4 �� r1 ����
	std::cout << r1; // r1�� x,y,height,width ���

	Rectangle* r2 = new Rectangle(2, 3, 5, 5); // x = 2, y = 3, width = 5, height = 5 �� r2 ����
	std::cout << *r2; // r2�� x,y,height,width ���

	r1 = r1 + *r2; // r1�� r2�� x,y,height,width ���� ���� �����ذ��� r1�� ����

	std::cout << r1; // r1�� r2�� ��ģ ���� r1�� x,y,height,width ���

	delete r2; // new�� �����Ѱ͸� delete�� �� �� �ִ�.

	-- ��������

	1��° Rectangle ��ü ���� // ID�� 1�� ��ü ���� , main.cpp�� 7��° �ٿ��� Rectangle r1(1, 1, 3, 4);�� �Է��ϰ� ��������� �����ڸ� ����

		height : 4 //��������� �������� ���ǿ� ���� �κп����� ��°����
		width : 3
		x : 1
		y : 1

		2��° Rectangle ��ü ���� // ID�� 2�� ��ü ���� , main.cpp�� 11��° �ٿ��� Rectangle* r2 = new Rectangle(2, 3, 5, 5);�� �Է��ϰ� ��������� �����ڸ� ����

		height : 5 //��������� �������� ���ǿ� ���� �κп����� ��°����
		width : 5
		x : 2
		y : 3

		3��° Rectangle ��ü ���� // r1�� ID�� 3�� r1+r2�� ������ ���Ӱ� ����,  main.cpp�� 14��° �ٿ��� r1 = r1 + *r2;�� �Է��ϰ� ��������� �����ڸ� ����

		��ǥ(3, 4) Rectangle ��ü �Ҹ� // Ŭ������ ��ü�� �����ɶ� �ı��ڸ� �ڵ������� �⵿

		height : 9 //��������� �������� ���ǿ� ���� �κп����� ��°����
		width : 8
		x : 3
		y : 4

		��ǥ(2, 3) Rectangle ��ü �Ҹ� // main.cpp�� 18��° �ٿ��� delete r2;�� r2 ��ü�� �Ҹ���

		��ǥ(3, 4) Rectangle ��ü �Ҹ� // Ŭ������ ��ü�� �����ɶ� �ı��ڸ� �ڵ������� �⵿

	*/

	Rectangle r1[2]; //r1�̶�� �̸��� �ΰ��� �簢�� ��ü ����

	for (int i = 0; i < 2; i++) {
		cout << i + 1 << "��°�� Rectangle ��ü�� x, y, width, height�� �Է��Ͻÿ�" << endl;
		cin >> r1[i]; // r1[0],r1[1]�� �Է¹���
		cout << r1[i] << endl; // r1[0],r1[1]�� x,y,height,width ���� ���
		cout << i + 1 << "��° Rectangle ��ü�� ����: " << r1[i].calArea() << endl << endl; // ���̸� ���ϴ� �Լ��� calArea�� ����Ͽ� r1[0],r1[1]�� ���̸� ���� ���
	}

	Rectangle r2 = r2.sameArea(r1[0], r1[1]); // ��ġ�� �κ��� x,y,height,width�� ���� �������ִ� �Լ��� sameArea�� ȣ���Ͽ� ��ġ�� �κ��� r2��� ���ο� ��ü�� ����

	cout << r2; // r2�� x,y,height,width ���� ���

	if (r2.calArea() == 0) { // ��ġ�� �κ��� ���̰� 0�̸�!
		cout << "�簢���� ��ġ���ʽ��ϴ�!" << endl; // ��ġ�� �ʴ´ٴ� ���� ���
	}
	else { // ��ġ��
		cout << "��ġ�� �簢���� ����: " << r2.calArea() << endl; // r2�� ���� ���
	}
}