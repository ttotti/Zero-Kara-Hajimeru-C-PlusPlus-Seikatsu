#include <iostream>

using namespace std;

// 타입에 대한 별명을 만드는 데 사용된다
// 이름이 긴 구조체를 typedef를 통해 이름을 짧게 만들수있고
// 이름을 지정해준 타입의 용도를 확실하게 전해줄때 사용할수있고
// 나중에 타입이 바뀔 수 있는 경우에 대비해서 사용할수있다
typedef short ID_TYPE; // typedef를 통해 기존의 타입 이름을 바꿀수있다

int main()
{
	ID_TYPE a = (ID_TYPE)0; // 이렇게 했을 경우 만약에 타입이 int 로 바꿔야할경우 위에 정의 해준 타입을 typedef int 로 바꾸면 된다
	ID_TYPE b = (ID_TYPE)0;
}