#include "DocWriter.h"
#include "HTMLWriter.h"

int main()
{
	// 자식 객체 생성
	HTMLWriter hw("test.html", "Lim-ttotti");

	// 부모클래스의 포인터로 자식 객체 가리킨다
	DocWriter* pdw = &hw;

	// 포인터를 사용해서 저장 함수 호출
	// 자식객체를 가리킨 포인터가 출력을 하는데 부모클래스에 있는 출력함수가 호출되었다
	// 이런경우 가상함수를 적용하면 해결된다
	pdw->Write();

	return 0;
}