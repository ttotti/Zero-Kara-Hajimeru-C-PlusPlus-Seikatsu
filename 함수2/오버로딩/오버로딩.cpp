#include <iostream>

using namespace std;

// 시그니처란 함수의 원형에서 인자 부분을 의미한다 // 예를들어 int max(int a) 의 시그니처는 int a 부분에 해당한다
int max(int a, int b); // 오버로딩 인자의 종류에 상관없이 동일한 함수 이름을 사용할수있다
float max(float a, float b);

int main()
{
	int a1 = 10, b1 = 20, c1;
	float a2 = 12.8f, b2 = 3.5f, c2;

	c1 = max(a1, b1);
	cout << c1 << endl;

	c2 = max(a2, b2);
	cout << c2 << endl;

	return 0;
}

int max(int a, int b) // 컴퓨터는 인자의 타입을 확인해서 그에 가장 잘 어울리는 시그니처를 가진 함수를 호출하게 된다
{
	int c;
	
	if (a < b)
		c = b;
	else
		c = a;

	return c;
}

float max(float a, float b)
{
	float c;

	if (a < b)
		c = b;
	else
		c = a;

	return c;
}

// 반환 값만 틀린 경우는 오버로드 할 수 없다
// 시그니처가 다르더라도 할수없는 경우(int i) (int& r) 의 경우 int형 타입을 인자로 받았을때 어떠한 함수를 호출해야하는지 문제가 생긴다
// 적당한 함수를 찾는 순서 funtion(int n) 일때 funtion('A') 이렇게 인자 타입을 char로 주었지만 합법적인 호출이다 char타입은 int형으로 자동 형변환이 되기때문이다(정수형 승진)
// funtion(int n) 와 funtion(char n) 이렇게 오버로드했을경우 funtion((int)'A') 이런 식으로 의도를 밝힌다면 컴퓨터는 의도한 함수를 호출할수있다