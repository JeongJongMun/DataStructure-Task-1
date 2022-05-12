#include "Rectangle.h"
#include <iostream>
using namespace std;

int Rectangle::id = 0; // Rectangle에 속해있는 id


Rectangle::~Rectangle() { //파괴자 정의
	cout << "좌표 (" << xLow << ',' << yLow << ')' // 파괴자가 실행되면 출력
		<< " Rectangle 객체 소멸\n\n";
}

std::ostream& operator <<(std::ostream& os, Rectangle& r) { // 출력 연산자의 오버로딩 정의	
	os << "height : " << r.height << endl
		<< "width : " << r.width << endl
		<< "x : " << r.xLow << endl
		<< "y : " << r.yLow << endl << endl;

	return os;
}

std::istream& operator >>(std::istream& in, Rectangle& r) { // 입력 연산자의 오버로딩 정의
	in >> r.xLow >> r.yLow >> r.width >> r.height; //순서대로 x,y,width,height를 입력받음

	return in;
}

Rectangle Rectangle::operator +(Rectangle& r) { // 플러스 연산자 오버로딩 정의
	int sum_x, sum_y, sum_w, sum_h;

	sum_x = xLow + r.xLow; // 각각의 x값을 더한 값을 sum_x에 저장
	sum_y = yLow + r.yLow; // 각각의 x값을 더한 값을 sum_y에 저장
	sum_w = this->width + r.width; // 포인터 객체의 멤버 변수 참조
	sum_h = this->height + r.height;

	return Rectangle(sum_x, sum_y, sum_w, sum_h);
}

int Rectangle::calArea() {  // 사각형의 넓이 구하는 함수
	return width * height;
}

Rectangle Rectangle::sameArea(Rectangle r1, Rectangle r2) { // 겹치는 사각형을 새로운 객체로 만들어서 반환하는 함수 sameArea
	// 생성된 사각형 2개가 안겹치는 경우의 수 확인
	if (r1.xLow > r2.xLow + r2.width) { // r1의 좌변이 r2의 우변보다 오른쪽에 있을때 
		return 0; // 안겹친다는 뜻
	}
	if (r1.xLow + r1.width < r2.xLow) { // r2의 좌변이 r1의 우변보다 오른쪽에 있을때
		return 0;
	}
	if (r1.yLow > r2.yLow + r2.height) { // r1의 아래변이 r2의 위변보다 위에 있을때
		return 0;
	}
	if (r1.yLow + r1.height < r2.yLow) { // r2의 아래변이 r1의 위변보다 위에 있을때
		return 0;
	}
	//겹치는 부분의 사각형을 새로운 객체 intersection로 생성
	Rectangle intersection = {}; //x,y,height,width 값을 받을 준비
	intersection.xLow = max(r1.xLow, r2.xLow); //최대값을 구하는 함수를 사용하여 r1,r2의 위치 구분없이 구할수있게함
	intersection.yLow = max(r1.yLow, r2.yLow);
	intersection.width = min(r1.xLow + r1.width, r2.xLow + r2.width) - intersection.xLow; // 최소값을 구하는 함수를 사용하여 r1,r2의 위치 구분없이 구할수있게함
	intersection.height = min(r1.yLow + r1.height, r2.yLow + r2.height) - intersection.yLow;

	return intersection; // 겹치는 사각형의 x,y,height,width 값을 가지고 있는 Rectangle 객체 리턴
}