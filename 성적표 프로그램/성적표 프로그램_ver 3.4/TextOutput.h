#ifndef TEXTOUTPUT_H
#define TEXTOUTPUT_H

#include "ConsoleOutput.h"
#include <fstream>

using namespace std;

// 텍스트로 출력하는 것은 Console 클래스나 HTML 클래스 처럼 클래스를 만들어도 되지만 더 간단한 방법이 있다
// 바로 ConsoleOutput 클래스를 상속받는것이다
// 콘솔 창에 값을 출력할때 사용하는 cout 객체는 ostream 클래스 타입이다
// 그리고 파일에 값을 출력할때는 ofstream 클래스를 사용한다
// 중요한것은 이 두 클래스가 부모 자식 관계에 있다 ostream 클래스가 ofstream의 부모 클래스가 되고 다형성을 사용해서 두 클래스를 다룰수가 있다
// 즉 ostream 클래스 객체 cout에 값을 출력하는 코드 그대로 사용해서 ofstream 객체에 값을 출력하게 만들 수 있다
class TextOutput :public ConsoleOutput
{
protected:
	ofstream fout;

protected:
	virtual ostream& StdOut();

public:
	TextOutput(STR filename);
	virtual ~TextOutput();
};

#endif // !TEXTOUTPUT_H

