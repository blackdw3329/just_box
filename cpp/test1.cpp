// 실습2

#include <iostream>
using namespace std;

class Triangle
{
public:
	Triangle() { height = 1; width = 1; }
	~Triangle() {}
	void setWidth(int w) { if (w <= 0)return; width = w; }
	void setHeight(int h) { if (h <= 0)return; height = h; }
	double getArea() { return width * height * 0.5; }

private:
	int width, height;
};


int main() {
	unique_ptr<Triangle> ptr1(new Triangle());
	// Triangle tri; 객체포인터변수 선언 및 초기화 코드 추가
	Triangle tri;
	Triangle* p;
	p = &tri;
	// tri.setWidth(3); 객체포인터 표현으로 변경

	p->setWidth(3);
	// tri.setHeight(5); 객체포인터 표현으로 변경

	p->setHeight(5);
	// cout << "삼각형의 면적은"<< tri.getArea()<< endl; 포인터표현으로 변경
	cout << "삼각형의 면적은" << p->getArea() << endl;
	return 0;
}

//실습3
#include <iostream>
using namespace std;


class Triangle
{
public:
	Triangle() { this->height = 1; this->width = 1; }
	~Triangle() {}
	void setWidth(int w) { if (w <= 0)return; this->width = w; }
	void setHeight(int h) { if (h <= 0)return; this->height = h; }
	double getArea() { return width * height * 0.5; }

private:
	int width, height;
};

int main() {
	Triangle tri1; // 밑변=높이=1로 초기화
	cout << "삼각형의 면적은 " << tri1.getArea() << endl;
	Triangle tri2(10); // 밑변=10,높이=1로 초기화
	cout << "삼각형의 면적은 " << tri2.getArea() << endl;
	Triangle tri3(10, 2); // 밑변=10,높이=2로 초기화
	cout << "삼각형의 면적은 " << tri3.getArea() << endl;
	return 0;
}
