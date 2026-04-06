// 실습2
#include <iostream>

using namespace std;

int main()
{
	int  n;
	int total = 0;
	double avg;
	cout << "입력할 정수의 개수를 입력하시오:";
	cin >> n;
	int* p = new int[n];
	cout << n << "개의 정수를 입력 하시오." << endl;

	for (int i = 0; i < n; i++)
	{
		cin >> p[i];
	}
	for (int j = 0; j < n; j++)
	{
		total += p[j];
	}
	avg = total / n;
	cout << "평균값은 " << avg << "입니다" << endl;
	delete[]p;
}

//실습2
#include <iostream>

using namespace std;

int main()
{
	int  n;
	int max;
	cout << "입력할 정수의 개수를 입력하시오:";
	cin >> n;
	int* p = new int[n];
	cout << n << "개의 정수를 입력 하시오." << endl;

	for (int i = 0; i < n; i++)
	{
		cin >> p[i];
	}
	max = p[0];
	for (int j = 0; j < n; j++)
	{
		if (max <= p[j]) max = p[j];
	}
	cout << "최대값은 " << max << "입니다" << endl;
	delete[]p;
}

//실습3
#include <iostream>

using namespace std;

int main()
{
	int  n;
	int max;
	cout << "저장할 문자열의 크기를 입력하세요:";
	cin >> n;
	char* p = new char[n+1];
	cout << "문자열을 입력하시오: ";
	cin.ignore();
	cin.getline(p, n + 1);
	cout << "입력한 문자열은: " << p << "입니다." << endl;

	delete[]p;
}
