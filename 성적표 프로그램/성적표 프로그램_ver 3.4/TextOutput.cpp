#include "TextOutput.h"

// ostream 객체를 반환한다
// 반환값 : ostream 객체인 fout을 반환한다
// 예) out 포인터가 TextOutput 객체를 가리키고 있다고 가정하고 ShowAll()함수의 out->BeginTable()을 호출하면
// TextOutput::BeginTable() 함수가 호출되는것이 이론상 옳다
// 하지만 TextOutput에는 저런 함수가 존재하지 않으므로 ConsoleOutput 클래스로부터 상속받은 ConsoleOutput::BeginTable() 함수가 호출된다
// BeginTable() 함수는 StdOut()로 부터 반환한 객체에 문자열을 출력하는 기능을 가지고 있는데
// 여기서 StdOut()는 가상함수이기 때문에 ConsoleOutput::BeginTable()이 아닌 TextOutput::BeginTable() 가 호출된다
// StdOut()에 의해서 반환되는 객체는 ofstream 클래스 타입의 객체가 되고 문자열은 텍스트 파일에 출력된다
// 나머지 다른 함수도 동일한 메커니즘으로 동작한다
// 이걸 읽어도 이해가 잘되지않는다면 인터넷(키워드: ostream 과 ofstream의 상속)이나 c++책 771~775p를 참고하자
ostream & TextOutput::StdOut()
{
	// TODO: 여기에 반환 구문을 삽입합니다.
	return fout;
} 

TextOutput::TextOutput(STR filename)
{
	// 파일을 생성한다
	fout.open(filename.c_str());
}

TextOutput::~TextOutput()
{
	// 파일을 닫는다
	fout.close();
}
