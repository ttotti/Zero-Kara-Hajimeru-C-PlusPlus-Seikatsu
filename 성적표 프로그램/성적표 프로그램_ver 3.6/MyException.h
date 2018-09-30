#ifndef MYEXCEPTION_H
#define MYEXCEPTION_H

#include <exception> // exception 클래스를 상속받기 위한 헤더파일

using namespace std;

// 이 프로젝트 사용할 예외
// exception 클래스를 상속 받았다
// C++에는 여러가지 예외클래스가 있는데 그 모든 예외클래스는 exception 클래스를 부모로 가지고 있다
// 자세한건 인터넷과 책 777p 를 참고한다
class MyException :public exception
{
protected:
	string _Str;

public:
	// 생성자
	// msg:에외를 설명하는 문자열
	// 생성자에서는 예외를 설명할 문자열을 인자로 받아서 멤버 변수 _Str에 보관한다
	MyException(const string& msg)
		:_Str(msg)
	{
	}

	// 소멸자
	virtual ~MyException()
	{
	}

	// 예외 설명 문자열을 반환한다
	// 반환 값: 문자열
	// what() 함수를 오버라이드 한다
	// 이 함수는 bad_alloc 클래스를 배울 때 설명한 적이 있는데
	// 예외에 대한 설명 문자열을 반환하는 함수다 생성자에서 입력 받은 문자열을 반환한다
	virtual const char *what() const
	{
		return _Str.c_str();
	}
};

#endif // !MYEXCEPTION_H

