#include <iostream>

using namespace std;

class AccessControl
{
public: // 외부에서 접근이 가능하다 // 생성자와 소멸자는 public으로 하는것이 원칙이다
	char publicData;
	void publicFunc();

protected: // 외부에서 접근이 불가하다 // private 과는 차이점이 있다
	int protectedData;
	void protectedFunc();

private: // 외부에서 접근이 불가하다
	float privateData;
	void privateFunc();

public:
	void AccessAllMembers(); // 클래스의 내부인 멤버함수에서는 접근 권한에 상관없이 모든 멤버에 접근이 가능하다
};

void AccessControl::AccessAllMembers() // 멤버함수 AccessControl() 에서 모든 멤버에 접근할수있다
{
	publicData = 100;
	publicFunc();

	protectedData = 200;
	protectedFunc();

	privateData = 300;
	privateFunc();
}


int main()
{
	AccessControl ac;

	ac.publicData = 100; // 접근제어가 public 으로 되있으므로 접근이 가능하다
	ac.publicFunc();

	ac.AccessAllMembers();

	return 0;
}