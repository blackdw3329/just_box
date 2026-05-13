//실습1


//실습2
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
using namespace std;

class Person {
    string name;
    int id;

public:
    Person(int id, const string name);
    Person(const Person& person);
    ~Person();

    void changeName(const string name);

    void show() {
        cout << id << ", " << name << endl;
    }
};

Person::Person(int id, const string name) {
    this->id = id;
    this->name = name;
}

Person::Person(const Person& person) {
    this->id = person.id;
    this->name = person.name;

    cout << "복사 생성자 실행. 원본 객체의 이름 " << this->name << endl;
}

Person::~Person() {
}

void Person::changeName(const string name) {
    this->name = name;
}

int main() {
    Person father(1, "Kitae");
    Person daughter(father);

    cout << "daughter 객체 생성 직후 ----" << endl;
    father.show();
    daughter.show();

    daughter.changeName("Grace");

    cout << "daughter 이름을 Grace로 변경한 후 ----" << endl;
    father.show();
    daughter.show();

    return 0;
}

//실습3
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
using namespace std;

class Mystack {
	int* p;			//배열 주소
	int size;	//배열의 크기
	int tos;	//다음에 저장할 배열의 인덱스
public:
	Mystack();
	Mystack(int size);
	Mystack(const Mystack& src);
	~Mystack();
	bool push(int n);	//꽉 차있으면 false 비어있으면 true
	bool pop(int& n);	//비어있으면 false 비어있으면 true

};
Mystack::Mystack() :Mystack(10) {}
Mystack::Mystack(int size) {
	this->size = size;
	this->tos = 0;
	p = new int[size];
}
Mystack::Mystack(const Mystack& src) {
	this->size = src.size;
	this->tos = src.tos;

	p = new int[size];

	for (int i = 0; i < tos; i++) {
		p[i] = src.p[i];
	}
}
Mystack::~Mystack() {
	delete []p;
}
bool Mystack::push(int n) {
	if (size <= tos) return false; 
	else {
		p[tos++] = n;
		return true;
	}
}
bool Mystack::pop(int& n) {
	if (tos == 0) return false;
	else {
		n = p[--tos];
		return true;
	}
}

int main() {
	Mystack a(10);
	a.push(10);
	a.push(20);

	Mystack b = a;
	b.push(30);
	int n;
	a.pop(n);
	cout << "스택 a에서 팝한 값 " << n << endl;	//20
	b.pop(n);
	cout << "스택 b에서 팝한 값 " << n << endl;	//30
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


//실습5
