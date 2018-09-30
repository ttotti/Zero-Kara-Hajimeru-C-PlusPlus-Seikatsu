#include <iostream>
#include <string>

using namespace std;

// 애완 동물 클래스
class Pet
{
public:
	void Eat();
	void Eat(const string& it);

	string name;
};

void Pet::Eat()
{
	cout << name << " says, 'Where is the food?'\n";
}

void Pet::Eat(const string& it)
{
	cout << name << " says, 'I like " << it << ".'\n";
}

// 강아지 클래스 (부모클래스 = 애완 동물클래스)
class Dog :public Pet
{
	// 오류!
	// 부모 클래스에서 오버로드된 함수 중에 어느 것 하나라도 오버라이드 하면 나머지 다른 함수들도 모두 사용할 수 없다
	//void Eat();
};

//void Dog::Eat()
//{
//	cout << name << " says, 'Grow1~\n";
//}

int main()
{
	Dog dog1;

	dog1.name = "ttotti";
	
	dog1.Eat();
	dog1.Eat("milk");

	return 0;
}

// 오버로드란 메소드(함수)의 이름은 같으나 인자의 갯수 또는 타입이 다른 함수를 말한다
// 예) void Overload(int i) {}
//     void Overload(int i, int j) {}
//     void Overload(double i, int j) {}
// 하지만 함수가 반환하는 타입이 다른 경우 컴파일이 되지 않는다
// 예) void Overload(int i) {}
//     double Overload(int i) {} 컴파일 되자 않음!!

// 오버라이드란 상속 받은 상위(부모) 클래스의 메소드(함수)를 다시 한번 자식 클래스에서 재정의 하는 것이다
// 메소드의 이름은 동일 해야 하며 또한 인자의 갯수, 타입도 동일 해야 한다

// 예) 부모 클래스에 void Overload() 함수가 있고 이 함수는 모든 멤버변수의 숫자를 1씩 올려주는 기능을 가지고 있다면
//     자식 클래스에 void Overload() 함수는 모든 멤버변수의 숫자를 123씩 올려주는 기능으로 재정의 할 수 있다

// 주위 !: 부모 클래스에서 오버로드된 함수 중에 어느 것 하나라도 오버라이드 하면 나머지 다른 함수들도 모두 사용할 수 없다
// 예) 부모 클래스
//     void Overload() { i += 1 } 1씩 올려준다
//     void Overload(int i) // 오버로드 했다
//     int Drow() 부모 클래스의 다른 함수

//     자식 클래스
//     void Overload() {i += 123} 오버라이딩 했다

//	   부모 클래스에서 오버로드 한 함수를 자식 클래스에서 오버라이딩을 하면 다른 모든 함수를 사용할 수 없다