#pragma once
#include <iostream>
#include <algorithm> //min, max함수 사용
using namespace std;

class Rectangle
{
private:
	static int id; // Rectangle.cpp에서 수정하기 위해 static 사용 / 객체 구분을 위한 id
	int width; //객체 변수들
	int height;
	int xLow, yLow;

public:
	Rectangle(int x = 0, int y = 0, int w = 0, int h = 0) : xLow(x), yLow(y), width(w), height(h) { // 생성자의 선언과 정의
		cout << ++id << "번째 Rectangle 객체 생성\n\n";
	}

	~Rectangle(); //파괴자 선언

	int calArea(); // 넓이 구하는 함수

	Rectangle sameArea(Rectangle r1, Rectangle r2);  // r1, r2가 겹치는 부분의 x,y,height,width값을 리턴 해주는 함수

	friend std::ostream& operator <<(std::ostream&, Rectangle&); // 출력 연산자 오버로딩 선언

	friend std::istream& operator >>(std::istream& in, Rectangle& r); // 입력 연산자 오버로딩 선언

	Rectangle operator +(Rectangle&); // 플러스 연산자 오버로딩 선언
};