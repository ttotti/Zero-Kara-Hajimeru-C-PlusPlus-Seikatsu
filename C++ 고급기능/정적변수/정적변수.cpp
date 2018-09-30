#include <iostream>

using namespace std;

class Test
{
public:
	void Func()
	{
		static int a = 0;
		cout << "a = " << ++a << endl;
	}
};

void Sub()
{
	// static 키워드를 붙여서 지역변수를 정의하면 변수의 존속 기간이 변하게 된다
	// 변수를 정의하는 순간에 생성되는 것은 동일하지만 이 변수는 프로그램이 종료될 때까지 살아있게 된다
	// 그래서 함수가 종료되더라도 값을 유지하기를 원한다면 static 키워드가 좋은 해결책이 될 것이다
	// static 키워드를 사용해서 지역 변수를 정의했을 때 존속 기간은 방금 말한 것처럼 변화하지만 접근 범위는 변하지 않는다
	static int n = 0;

	++n;

	cout << "n = " << n << endl;
}

int main()
{
	Sub();
	Sub();
	Sub();
	Sub();
	Sub();
	// Sub 함수에 정의된 변수에 접근
	// n = 100; 오류

	cout << endl;

	// 멤버 함수 안에 정의한 static 변수는 모든 객체에 의해서 사용된다
	Test t1;
	Test t2;
	Test t3;

	t1.Func();
	t2.Func();
	t3.Func();

	// 전역 변수를 static 으로 정의하면 다른 파일에서 이 변수에 접근할 수 없게 된다
	// 다른 파일에서 extern 키워드를 사용해서 접근하더라도 오류가 발생한다
	// 전역 변수를 static 으로 만드는 것은 클래스에서 접근 권한을 설정하는 것과 비슷한 의미를 가지며
	// 다른 파일에서 전역 변수에 접근할 수 없게 만들고 싶을 때는 static 키워드를 사용하면 된다
	// 전역 변수를 static 으로 만든 경우에도 존속 기간에는 차이가 없다
	// 함수 또한 마찬가지다

	return 0;
}