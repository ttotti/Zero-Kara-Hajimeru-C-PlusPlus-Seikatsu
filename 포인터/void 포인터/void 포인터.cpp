#include <iostream>

using namespace std;

// void 포인터는 흔히 주소를 저장하는 용도로만 사용한다
int main()
{
	double i = 400.0;
	void* pv = &i; // void 포인터는 아무타입이나 가리킬 수 있기 때문에 형변환없이도 값을 보관할수있다 하지만 타입을 모르기에 사용할수없다

	int* pi = (int*)pv; // 그렇기에 형변환을 통해서 다른 포인터 변수에 값을 저장한다

	cout << "pv의 사이즈: " << sizeof(pv) << endl;
	cout << "pi의 사이즈: " << sizeof(pi) << endl;

	return 0;
}