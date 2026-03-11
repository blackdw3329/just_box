#include <iostream>
#include <cstring>

using namespace std;
//int main() {
//	int n;
//
//	cout << "정수를 입력 하시오.: ";
//	cin >> n;
//	
//	cout << "x=" << n << "일때 y의 값은 " << n*n+2*n-5 << "입니다.";
//
//	return 0;
//}

int main()
{
	char number[10];
	char name[10];
	string address[20];

	cout << "학번을 입력하시오: ";
	cin >> number;

	cout << "이름을 입력하시오: ";
	cin >> name;
	
	cout << "주소을 입력하시오: ";
	cin.getline(address, sizeof(address),'\n');


	cout << "1.학번:" << number << endl << "2.이름:" << name << endl << "3.주소:" << address << endl;


	return 0;
}
