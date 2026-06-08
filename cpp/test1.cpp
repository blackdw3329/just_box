#include <iostream>

using namespace std;

class Complex {
	int real, img;
public:
	Complex(int r = 0, int i = 0) { this->real = r; this->img = i; cout << "복소수 " << real << '+' << img << "j 생성" << endl;
	}
	Complex& operator++();
	Complex operator--(int x);
	void show() {
		if(img<0) cout << real << img << 'j' << endl;
		else cout << real << '+' << img << 'j' << endl;
	}
};

Complex& Complex::operator++(){
	real++;
	img++;
	return *this;
}

Complex Complex::operator--(int x){
	Complex tmp = *this;
	real--;
	img--;
	return tmp;
}




int main() {
	Complex x(2, -3);
	++x;
	cout << "증가결과 ";
	x.show();
	x--;
	cout << "감소결과 ";
	x.show();
	return 0;
}




# 실습과제 2
#include <iostream>

using namespace std;

class Complex {
	int real, img;
public:
	Complex(int r = 0, int i = 0) {
		this->real = r; this->img = i; cout << "복소수 " << real << '+' << img << "j 생성" << endl;
	}
	friend Complex& operator++(Complex& op);
	friend Complex operator--(Complex op, int x);
	void show() {
		if (img < 0) cout << real << img << 'j' << endl;
		else cout << real << '+' << img << 'j' << endl;
	}
};

Complex& operator++(Complex& op) {
	op.real++;
	op.img++;
	return op;
}

Complex operator--(Complex& op, int x) {
	Complex tmp = op;
	op.real--;
	op.img--;
	return tmp;
}




int main() {
	Complex x(2, -3);
	++x;
	cout << "증가결과 ";
	x.show();
	x--;
	cout << "감소결과 ";
	x.show();
	return 0;
}

	
