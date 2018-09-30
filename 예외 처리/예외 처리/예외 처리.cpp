#include "DynamicArray.h"
#include <iostream>

using namespace std;

int main()
{
	DynamicArray arr(10);

	for (int i = 0; i < 10; ++i)
	{
		arr.SetAt(i, (i + 1) * 10);
	}

	cout << "Size of arr = " << arr.GetSize() << endl;

	for (int i = 9; i >= 0; --i)
	{
		cout << "arr[ " << i << " ] = " << arr.GetAt(i) << endl;
	}

	// 배열 값보다 큰 수를 넣었을때 문제가 발생하지않도록 예외메시지를 날려준다
	// 하지만 이런 방법은 함수를 호출할때마다 매번 이렇게 검사해야한다는 점이 번거롭다
	// 그리고 이 함수의 경우 반환값을 void 에서 bool 로 바꿨는데 다른 반환타입이였다면 본래의 용도로 사용 할 수 없다는 점이 있다
	// 이런 문제를 해결하기 위해 C++이 지원하는 구조적 예외 처리가 있다
	if (!arr.SetAt(20, 0))
		cout << "index의 값이 정의 된 배열 값보다 큼니다!" << endl;

	return 0;
}