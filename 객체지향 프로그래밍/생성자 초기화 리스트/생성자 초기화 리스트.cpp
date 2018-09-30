#include <iostream>

using namespace std;

class NeedConstructor
{
public:
	const int maxCount;
	int& ref;
	int sample;

	NeedConstructor();
	NeedConstructor(int count, int& number);

};

NeedConstructor::NeedConstructor()
	:maxCount(100),ref(sample) // 생성자의 초기화 리스트 // const 속성 타입이나 레퍼런스 타입의 변수를 초기화 할 수있다
{
	sample = 200;
}

NeedConstructor::NeedConstructor(int count, int& number) // 인자가 있는 생성자 // 인자를 사용해서 초기화를 할수있다
	: maxCount(count), ref(number)
{
	sample = 200;
}

int main()
{
	NeedConstructor cr;

	cout << cr.maxCount << endl;
	cout << cr.ref << endl;
	cout << cr.sample << endl;
	cout << endl;

	/////////////////////////////////

	int number = 400;

	NeedConstructor cr2(300, number);

	cout << "cr.maxCount = " << cr.maxCount << endl;
	cout << "cr.ref = " << cr.ref << endl;

	return 0;
}