// 실습과제 2
#include <iostream>

using namespace std;

class Circle {
private:
	int radius;
public:
	Circle();
	int getRadius();
	void setRadius(int n);
};
Circle::Circle() { radius = 1; }
int Circle::getRadius() { return radius; }
void Circle::setRadius(int n) { radius = n; }
int main() {
	Circle waffle;
	waffle.setRadius(5);
	cout << "원의 반지름은" << waffle.getRadius() << endl;
	return 0;
}

// 실습과제 3
#include <iostream>

using namespace std;

class Triangle {
private:
	int width;
	int height;
public:
	Triangle();
	Triangle(int w, int h);
	double getArea();
	int getWidth();
	void setWidth(int w);
	int getHeight();
	void setHeight(int h);
};
Triangle::Triangle():Triangle(1,1) {}
Triangle::Triangle(int w, int h) { width = w; height = h; }

int Triangle::getHeight() { return height; }
int Triangle::getWidth() { return width; }
void Triangle::setHeight(int h) { height = h; }
void Triangle::setWidth(int w) { width = w; }

double Triangle::getArea() { return 0.5 * height * width; }

int main() {
	Triangle tri;
	tri.setWidth(3);
	tri.setHeight(5);
	cout << "삼각형의 폭은 " << tri.getWidth() << endl;
	cout << "삼각형의 높이는 " << tri.getHeight() << endl;
	cout << "삼각형의 높이는 " << tri.getArea() << endl;
	return 0;
}

// 실습과제4
#include <iostream>

using namespace std;

class Triangle {
private:
	int width;
	int height;
public:
	Triangle();
	Triangle(int w, int h);
	~Triangle();
	double getArea();	
	int getWidth();
	void setWidth(int w);
	int getHeight();
	void setHeight(int h);
};
Triangle::Triangle():Triangle(1,1) {}
Triangle::Triangle(int w, int h) { 
	if (w < 0 || h < 0) {
		cout << "길이는 양수여야함, 대신에 폭1,높이1 삼각형생성" << endl;
		width = 1; height = 1;
	}
	else width = w; height = h;
}
Triangle::~Triangle() { cout << "폭" << width << ", 높이" << height << " 삼각형 소멸" << endl; }

int Triangle::getHeight() { return height; }
int Triangle::getWidth() { return width; }
void Triangle::setHeight(int h) { if (h < 0) cout << "폭은 양수이어야 함" << endl; 
else height = h; }
void Triangle::setWidth(int w) { if (w < 0) cout << "높이는 양수이어야 함" << endl;
else width = w; }

double Triangle::getArea() { return 0.5 * height * width; }

int main() {
	Triangle tri(-10, -5);
	tri.setWidth(-3);
	tri.setHeight(-5);
	tri.setWidth(3);
	tri.setHeight(5);
	cout << "삼각형의 폭은 " << tri.getWidth() << endl;
	cout << "삼각형의 높이는 " << tri.getHeight() << endl;
	return 0;
}
