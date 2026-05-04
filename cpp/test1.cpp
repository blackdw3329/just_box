//실습1
//함수 호출시 자동으로 처리되는 2가지 => 매개변수 메모리 할당, 매개변수를 인자값으로 초기화

//실습2
#include <iostream>
#include <string>

using namespace std;

string GetLatterString(string s1, string s2);

int main() {
	string s1("hello");
	string s2("world");
	string res;

	res = GetLatterString(s1, s2);

	cout << "사전에서 뒤에 나오는 문자열은 " << res << "입니다" << endl;
	return 0;
}

string GetLatterString(string s1, string s2) {
	if (s1 > s2) return s1;
	else return s2;
}

//실습3
#include <iostream>
#include <string>

using namespace std;

string GetLatterString(string *s1, string *s2);

int main() {
	string s1("hello");
	string s2("world");
	string res;

	res = GetLatterString(&s1, &s2);

	cout << "사전에서 뒤에 나오는 문자열은 " << res << "입니다." << endl;
	return 0;
}

string GetLatterString(string *s1, string *s2) {
	if (*s1 > *s2) return *s1;
	else return *s2;
}

//실습4
#include <iostream>
#include <string>

using namespace std;

void SwapString(string *s1, string *s2);

int main() {
	string s1("hello");
	string s2("world");

	cout << "호출전 s1:" << s1 << "s2:" << s2 << endl;
	SwapString(&s1, &s2);
	cout << "호출후 s1:" << s1 << "s2:" << s2 << endl;
	return 0;
}

void SwapString(string *s1, string* s2) {
	string tmp;
	tmp = *s1;
	*s1 = *s2;
	*s2 = tmp;
}
