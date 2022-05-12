#include <iostream>
#include "Rectangle.h"
using namespace std;

int main()
{
	/*
	-- 과제 파일에 기본으로 써있는 코드들
	Rectangle r1(1, 1, 3, 4); // x = 1, y = 1, width = 3, height = 4 인 r1 생성
	std::cout << r1; // r1의 x,y,height,width 출력

	Rectangle* r2 = new Rectangle(2, 3, 5, 5); // x = 2, y = 3, width = 5, height = 5 인 r2 생성
	std::cout << *r2; // r2의 x,y,height,width 출력

	r1 = r1 + *r2; // r1과 r2의 x,y,height,width 값을 각각 더해준것을 r1에 대입

	std::cout << r1; // r1과 r2의 합친 값인 r1의 x,y,height,width 출력

	delete r2; // new로 선언한것만 delete를 할 수 있다.

	-- 실행결과물

	1번째 Rectangle 객체 생성 // ID가 1인 객체 생성 , main.cpp의 7번째 줄에서 Rectangle r1(1, 1, 3, 4);을 입력하고 헤더파일의 생성자를 참고

		height : 4 //헤더파일의 생성자의 정의와 선언 부분에서의 출력결과물
		width : 3
		x : 1
		y : 1

		2번째 Rectangle 객체 생성 // ID가 2인 객체 생성 , main.cpp의 11번째 줄에서 Rectangle* r2 = new Rectangle(2, 3, 5, 5);을 입력하고 헤더파일의 생성자를 참고

		height : 5 //헤더파일의 생성자의 정의와 선언 부분에서의 출력결과물
		width : 5
		x : 2
		y : 3

		3번째 Rectangle 객체 생성 // r1을 ID가 3인 r1+r2의 값으로 새롭게 정의,  main.cpp의 14번째 줄에서 r1 = r1 + *r2;을 입력하고 헤더파일의 생성자를 참고

		좌표(3, 4) Rectangle 객체 소멸 // 클래스의 객체가 삭제될때 파괴자를 자동적으로 기동

		height : 9 //헤더파일의 생성자의 정의와 선언 부분에서의 출력결과물
		width : 8
		x : 3
		y : 4

		좌표(2, 3) Rectangle 객체 소멸 // main.cpp의 18번째 줄에서 delete r2;로 r2 객체를 소멸함

		좌표(3, 4) Rectangle 객체 소멸 // 클래스의 객체가 삭제될때 파괴자를 자동적으로 기동

	*/

	Rectangle r1[2]; //r1이라는 이름의 두개의 사각형 객체 생성

	for (int i = 0; i < 2; i++) {
		cout << i + 1 << "번째의 Rectangle 객체의 x, y, width, height를 입력하시오" << endl;
		cin >> r1[i]; // r1[0],r1[1]을 입력받음
		cout << r1[i] << endl; // r1[0],r1[1]의 x,y,height,width 값을 출력
		cout << i + 1 << "번째 Rectangle 객체의 넓이: " << r1[i].calArea() << endl << endl; // 넓이를 구하는 함수인 calArea를 사용하여 r1[0],r1[1]의 넓이를 각각 출력
	}

	Rectangle r2 = r2.sameArea(r1[0], r1[1]); // 겹치는 부분의 x,y,height,width의 값을 리턴해주는 함수인 sameArea를 호출하여 겹치는 부분을 r2라는 새로운 객체로 만듬

	cout << r2; // r2의 x,y,height,width 값을 출력

	if (r2.calArea() == 0) { // 겹치는 부분의 넓이가 0이면!
		cout << "사각형이 겹치지않습니다!" << endl; // 겹치지 않는다는 문구 출력
	}
	else { // 겹치면
		cout << "겹치는 사각형의 넓이: " << r2.calArea() << endl; // r2의 넓이 출력
	}
}