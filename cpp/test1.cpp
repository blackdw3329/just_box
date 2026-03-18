// 실습과제 2

#include <iostream>
using namespace std;

class Triangle {
public:
	int width;
	int height;
	Triangle();
	Triangle(int w, int h);
	double getArea();

};

Triangle::Triangle(int w, int h) {
	width = w;
	height = h;
}

Triangle::Triangle() :Triangle(1, 1) { }

double Triangle::getArea() {
	return width * height * 1.0 / 2.0;
}

int main() {
	Triangle tri1; // 밑변,높이 1로 초기화
	cout << "삼각형의 면적은 " << tri1.getArea() << endl;

	Triangle tri2(2, 4); // 밑변=2,높이=4로 초기화
	cout << "삼각형의 면적은 " << tri2.getArea() << endl;
	return 0;
}
