#include "Rectangle.h"
#include <iostream>
using namespace std;

int Rectangle::id = 0; // Rectangle�� �����ִ� id


Rectangle::~Rectangle() { //�ı��� ����
	cout << "��ǥ (" << xLow << ',' << yLow << ')' // �ı��ڰ� ����Ǹ� ���
		<< " Rectangle ��ü �Ҹ�\n\n";
}

std::ostream& operator <<(std::ostream& os, Rectangle& r) { // ��� �������� �����ε� ����	
	os << "height : " << r.height << endl
		<< "width : " << r.width << endl
		<< "x : " << r.xLow << endl
		<< "y : " << r.yLow << endl << endl;

	return os;
}

std::istream& operator >>(std::istream& in, Rectangle& r) { // �Է� �������� �����ε� ����
	in >> r.xLow >> r.yLow >> r.width >> r.height; //������� x,y,width,height�� �Է¹���

	return in;
}

Rectangle Rectangle::operator +(Rectangle& r) { // �÷��� ������ �����ε� ����
	int sum_x, sum_y, sum_w, sum_h;

	sum_x = xLow + r.xLow; // ������ x���� ���� ���� sum_x�� ����
	sum_y = yLow + r.yLow; // ������ x���� ���� ���� sum_y�� ����
	sum_w = this->width + r.width; // ������ ��ü�� ��� ���� ����
	sum_h = this->height + r.height;

	return Rectangle(sum_x, sum_y, sum_w, sum_h);
}

int Rectangle::calArea() {  // �簢���� ���� ���ϴ� �Լ�
	return width * height;
}

Rectangle Rectangle::sameArea(Rectangle r1, Rectangle r2) { // ��ġ�� �簢���� ���ο� ��ü�� ���� ��ȯ�ϴ� �Լ� sameArea
	// ������ �簢�� 2���� �Ȱ�ġ�� ����� �� Ȯ��
	if (r1.xLow > r2.xLow + r2.width) { // r1�� �º��� r2�� �캯���� �����ʿ� ������ 
		return 0; // �Ȱ�ģ�ٴ� ��
	}
	if (r1.xLow + r1.width < r2.xLow) { // r2�� �º��� r1�� �캯���� �����ʿ� ������
		return 0;
	}
	if (r1.yLow > r2.yLow + r2.height) { // r1�� �Ʒ����� r2�� �������� ���� ������
		return 0;
	}
	if (r1.yLow + r1.height < r2.yLow) { // r2�� �Ʒ����� r1�� �������� ���� ������
		return 0;
	}
	//��ġ�� �κ��� �簢���� ���ο� ��ü intersection�� ����
	Rectangle intersection = {}; //x,y,height,width ���� ���� �غ�
	intersection.xLow = max(r1.xLow, r2.xLow); //�ִ밪�� ���ϴ� �Լ��� ����Ͽ� r1,r2�� ��ġ ���о��� ���Ҽ��ְ���
	intersection.yLow = max(r1.yLow, r2.yLow);
	intersection.width = min(r1.xLow + r1.width, r2.xLow + r2.width) - intersection.xLow; // �ּҰ��� ���ϴ� �Լ��� ����Ͽ� r1,r2�� ��ġ ���о��� ���Ҽ��ְ���
	intersection.height = min(r1.yLow + r1.height, r2.yLow + r2.height) - intersection.yLow;

	return intersection; // ��ġ�� �簢���� x,y,height,width ���� ������ �ִ� Rectangle ��ü ����
}