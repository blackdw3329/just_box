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
