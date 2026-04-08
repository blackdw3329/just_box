// 실습2
#include <iostream>
using namespace std;
class Circle {
	int radius;
public:
	Circle();
	Circle(int r);
	~Circle();
	void setRadius(int r) { radius = r; }
	double getArea() { return 3.14 * radius * radius; }
};
Circle::Circle() {
	radius = 1; cout << "생성자 실행 radius = " << radius << endl;
}
Circle::Circle(int r) {
	radius = r; cout << "생성자 실행 radius = " << radius << endl;
}
Circle::~Circle() {
	cout << "소멸자 실행 radius = " << radius << endl;
}
int main() {
	int radius;
	while (true) {
		cout << "반지름 입력(음수이면 종료)>> ";
		cin >> radius;
		if (radius < 0) break;
		Circle* p = new Circle(radius);
		cout << "원의 면적:" << p->getArea() << endl;
		 //delete p;  // 메모리 해제를 안해주면 메모리 누수 발생
	}
	return 0;
}
//실습3
#include <iostream>
using namespace std;
class Circle {
	int radius;
public:
	Circle();
	Circle(int r);
	~Circle();
	void setRadius(int r) { radius = r; }
	double getArea() { return 3.14 * radius * radius; }
};
Circle::Circle() {
	radius = 1; cout << "생성자 실행 radius = " << radius << endl;
}
Circle::Circle(int r) {
	radius = r; cout << "생성자 실행 radius = " << radius << endl;
}
Circle::~Circle() {
	cout << "소멸자 실행 radius = " << radius << endl;
}

int main() {
	Circle* pArray = new Circle[3];
	for (int i = 0; i < 3; i++) {
		cout << pArray->getArea() << '\n';
		pArray++; // 해제할때 pArray의 주소가  달라져있어 문제가된다
	}
	delete[] pArray;
	return 0;
}

// 해결한 main 함수
/*
int main() {
	Circle* pArray = new Circle[3];
	Circle* p = pArray;
	for (int i = 0; i < 3; i++) {
		cout << p->getArea() << '\n';
		p++; // 다른 포인터를 만들어 주소를 따로 접근한다
	}
	delete[] pArray;
	return 0;
}
*/
//실습4
#include <iostream>
using namespace std;
class Triangle {
	int width,height;
public:
	Triangle();
	Triangle(int w, int h);
	~Triangle();
	double getArea() { return (0.5 * width * height); }
};
Triangle::Triangle():Triangle(1,1) { }
Triangle::Triangle(int w, int h) {
	width = w; height = h;
	cout << "밑변" << width << " 높이" << height << "인 삼각형 생성" << endl;
}
Triangle::~Triangle() {
	cout << "밑변" << width << " 높이" << height << "인 삼각형 소멸" << endl;
}
int main() {
	Triangle* pArray = new Triangle[3]{ Triangle(),Triangle(2,2),Triangle(4,4) };
	
	Triangle* p = pArray;
	for (int i = 0; i < 3; i++) {
		cout << "삼각형의 면적은 " << p[i].getArea() << '\n';
		p++;
	}
	delete[] pArray;
	return 0;
}

//실습5
#include <iostream>
using namespace std;
class Sphere {
	int radius;
public:
	Sphere();
	~Sphere() {}
	void setRadius(int r) { cout << r << "반지름 변경" << endl; radius = r; }
	double getArea() { cout << "부피 출력" << endl; return 3.14 * radius * radius * radius * 4 / 3; }
};
Sphere::Sphere() {
	radius = 1;
}
int main() {
	cout << "생성하고자 하는 구의 개수: ";
	int n, radius;
	cin >> n;
	Sphere* pArray = new Sphere[n];
	for (int i = 0; i < n; i++) {
		cout << "구" << i + 1 << "의 반지름: ";
		cin >> radius;
		(pArray + i)->setRadius(radius);
	}
	for (int j = 0; j < n; j++) {
		cout << "구" << j + 1 << "의 부피: " << (pArray + j)->getArea() << endl;
	}
	delete[] pArray;
	return 0;
}

