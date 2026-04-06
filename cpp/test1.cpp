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
