// 실습과제 2
#include <iostream>
using namespace std;
int main() {
	cout << "이름 : 홍길동" << endl;
	cout << "주소 : 군산시 대학로 558" << endl;
	cout << "학번 : 201012" << endl;
	cout << "차종 : 벤츠" << endl;
	return 0;

}

// 실습과제 3
#include <iostream>
using namespace std;
int main() {
	cout << "군산대학교 \"홍길동\"" << endl;
	cout << "\"축하합니다.\"" << endl;
	cout << "100% \\취업율\\"<< endl;
	return 0;

}


//실습과제 4
#include <iostream>
using namespace std;
int main() {
	int n = 7;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (i==j or i+j == n+1)
			{
				cout << "*";
			}
			else
			{
				cout << "  ";
			}
		}
		cout << "\n";
	}
	return 0;
}


// 실습과제 5 교재 87페이지 실습문제 20번을 푸시오 
#include <iostream>
using namespace std;
int main() {
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j <= i; j++)
		{
			cout << "*";
		}
		cout << "\n";
	}
	return 0;
}
