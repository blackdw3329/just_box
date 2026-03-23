// 실습과제 2

#include <iostream>

using namespace std;

class Triangle {
public:
	int width;
	int height;
	Triangle();
	Triangle(int w, int h);
	~Triangle();
	double getArea();

};
Triangle::Triangle() {
	width = 1; height = 1;
	cout << "밑변 " << width << "높이" << height << "인 삼각형 생성" << endl;
}

Triangle::Triangle(int w, int h) {
	width = w; height = h;
	cout << "밑변 " << width << "높이" << height << "인 삼각형 생성" << endl;
}

Triangle::~Triangle() {
	cout << "밑변 " << width << "높이" << height << "인 삼각형 소멸" << endl;
}

double Triangle::getArea() {
	return 0.5 * width * height;
}


// 클래스 정의
int main() {
	Triangle tri1; //밑변,높이 1로 초기화
	cout << "삼각형의 면적은" << tri1.getArea() << endl;
	Triangle tri2(2, 4); //밑변=2,높이=4로 초기화
	cout << "삼각형의 면적은" << tri2.getArea() << endl;
	return 0;
}



// 실습문제 3

#include <iostream>

using namespace std;

class Triangle {
public:
	int width;
	int height;
	Triangle();
	Triangle(int w, int h);
	~Triangle();
	double getArea();

};
Triangle::Triangle() {
	width = 1; height = 1;
	cout << "밑변 " << width << "높이" << height << "인 삼각형 생성" << endl;
}

Triangle::Triangle(int w, int h) {
	width = w; height = h;
	cout << "밑변 " << width << "높이" << height << "인 삼각형 생성" << endl;
}

Triangle::~Triangle() {
	cout << "밑변 " << width << "높이" << height << "인 삼각형 소멸" << endl;
}

double Triangle::getArea() {
	return 0.5 * width * height;
}

Triangle tri1(4, 8);
Triangle tri2(2, 2);

// 클래스 정의
int main() {
	cout << "삼각형의 면적은" << tri2.getArea() << endl;
	cout << "삼각형의 면적은" << tri1.getArea() << endl;
	return 0;
}

//실습문제 4
#include <iostream>

using namespace std;

class Sphere {
public:
	int radius;
	Sphere();
	Sphere(int r);
	~Sphere();
	double getVolume();

};
Sphere::Sphere() {
	radius = 1;
	cout << "반지름 " << radius << "인 원 생성" << endl;
}

Sphere::Sphere(int r) {
	radius = r;
	cout << "반지름 " << radius << "인 원 생성" << endl;
}

Sphere::~Sphere() {
	cout << "반지름 " << radius << "인 원 소멸" << endl;
}

double Sphere::getVolume() {
	return radius * radius * radius * 3.14 * 4 / 3;
}

Sphere sph1;
Sphere sph2(3);

// 클래스 정의
int main() {
	cout << "삼각형의 면적은" << sph2.getVolume() << endl;
	cout << "삼각형의 면적은" << sph1.getVolume() << endl;
	return 0;
}
