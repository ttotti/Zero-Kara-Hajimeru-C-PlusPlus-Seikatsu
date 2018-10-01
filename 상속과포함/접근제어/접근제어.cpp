#include <iostream>

using namespace std;

class Parent
{
	// 자신의 멤버 함수 외에는 접근이 불가하다
	// 반드시 자식클래스에 숨기고 싶다면 private 로 지정
private:
	int priv;
	void F_priv();

	// 자식 클래스의 멤버 함수로부터의 접근만 허용한다
	// 외부로부터 숨겨야 하는 멤버는 protected 로 지정
protected:
	int prot;
	void F_prot();

	// 모든 곳에서 접근을 허용한다
	// 그 밖의 경우는 public 로 지정
public:
	int pub;
	void F_pub();
};

class child :public Parent
{
public:

	int n;

	void AccessParents()
	{
		int n;

		// n = priv; (불가능)
		n = prot; // 가능
		n = pub; // 가능

		// 멤버 함수도 똑같다
		//F_priv();
		F_prot();
		F_pub()
	}
};

int main()
{
	Parent pa;

	int n;
	//n = pa.priv; (불가능)
	//n = pa.prot; (불가능)
	n = pa.pub; // (가능)

	// 멤버 함수도 똑같다
	//pa.F_priv(); (불가능)
	//pa.F_prot(); (불가능)
	pa.F_pub(); // (가능)

	child cd;
	child* pcd;

	cd.n;
	cd.pub;
	pcd->pub;
	cd.F_pub();
	
	// 포함관계를 가지고 있는 클래스들은 접근 권한에 있어서 서로 아무런 관계가 없다
	// 그러므로 포함관계를 가지고 있는 두 클래스는 상대방 클래스의 public 멤버에만 접근할수있다

	return 0;
}