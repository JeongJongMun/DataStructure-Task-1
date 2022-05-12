#pragma once
#include <iostream>
#include <algorithm> //min, max�Լ� ���
using namespace std;

class Rectangle
{
private:
	static int id; // Rectangle.cpp���� �����ϱ� ���� static ��� / ��ü ������ ���� id
	int width; //��ü ������
	int height;
	int xLow, yLow;

public:
	Rectangle(int x = 0, int y = 0, int w = 0, int h = 0) : xLow(x), yLow(y), width(w), height(h) { // �������� ����� ����
		cout << ++id << "��° Rectangle ��ü ����\n\n";
	}

	~Rectangle(); //�ı��� ����

	int calArea(); // ���� ���ϴ� �Լ�

	Rectangle sameArea(Rectangle r1, Rectangle r2);  // r1, r2�� ��ġ�� �κ��� x,y,height,width���� ���� ���ִ� �Լ�

	friend std::ostream& operator <<(std::ostream&, Rectangle&); // ��� ������ �����ε� ����

	friend std::istream& operator >>(std::istream& in, Rectangle& r); // �Է� ������ �����ε� ����

	Rectangle operator +(Rectangle&); // �÷��� ������ �����ε� ����
};