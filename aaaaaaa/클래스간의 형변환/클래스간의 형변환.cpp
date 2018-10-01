#include "DocWriter.h"
#include "HTMLWriter.h"

int main()
{
	// 자식 객체를 부모 객체로 대입할수있다 (부모객체 = 자식객체 가능)
	HTMLWriter hw("test.txt", "Welcome ttotti");
	DocWriter dw;

	dw = hw;

	dw.Write();

	// 하지만 그 반대는 불가능하다 (자식객체 = 부모객체 불가능)
	/*DocWriter dw2("test.txt", "Welcome ttotti");
	HTMLWriter hw2;

	hw2 = dw2;*/

	/////////////////////////////////////////

	// 자식클래스의 포인터를 이용하서 부모객체를 가리키는 경우 (불가능)
	// 이것은 DocWriter* 타입에서 HTMLWriter* 타입으로 형변환을 시도하는 코드이다 (불가능)
	// 만약 자식클래스가 포인터로 부모객체를 가리킬수있다고 하면 오류가 발생한다
	// 왜냐하면 부모객체는 자식클래스가 가지고 있는 멤버가 없기 때문이다 (phw->fontColor dw는 fontColor이 없음(오류)) (레퍼런스도 마찬가지 불가능하다)
	/*DocWriter dw;
	HTMLWriter* phw = &dw;*/

	// 하지만 그 반대 부모클래스가 자식 객체를 가리킬수있다
	// 부모클래스의 포인터로 자식객체를 가리키는 경우는 아무런 문제가 없다
	// 부모클래스에 있는 모든 멤버는 자식객체에도 있기 때문이다
	// 그런데 저장한 문서의 타입이 HTML포멧이 아닌 텍스트 포멧이다
	// 여기서 DocWriter::wrire() 가 호출된다는 주장과 HTMLWriter::write() 가 호출된다는 주장 둘다 맞다 (가상함수를 배우면 후자로 호출이 가능하다)
	// 실제 객체가 무엇이던 간에 상관없이 포인터의 타입을 기준으로 호출될 함수가 결정된다 (레퍼런스도 마찬가지 가능하다)
	HTMLWriter hw3("Text.html", "Hello ttotti");
	DocWriter* pdc = &hw3;

	// DocWriter 타입으로 HTMLWriter의 객체를 가리키고 있지만
	// DocWriter::write() 가 호출된다
	pdc->Write();

	// 위와 같이 자식 클래스의 포인터가 부모 클래스의 포인터로 형변환 하는것을 업캐스트 라 하고 ( (자식클래스 타입)자식객체 -> (부모클래스 타입)자식객체 )

	// 반대로 명시적으로 부모 클래스의 포인터가 부모 클래스의 포인터로 형변환을 할수있는데 이를 다운캐스트라 한다 ( (부모클래스 타입)자식객체 -> (자식클래스 타입)자식객체 )
	// 자식객체를 부모클래스 타입으로 업캐스트를 하고 다시 다운캐스트를 하는것은 아무런 문제가 없다
	// 하지만 컴퓨터는 pdw3이 HTMLWriter 객체를 가리키는것을 모르기 때문에 명시적으로 형변환을 시켜줘야한다
	HTMLWriter hw4;
	DocWriter* pdw3 = &hw4; // 업캐스트
	HTMLWriter* phw = (HTMLWriter*)pdw3; // 다운캐스트

	return 0;
}