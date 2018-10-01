#include <string>

using namespace std;

// 학부생 클래스
class UnderGradStudent
{
public:
	string name;		// 이름
	string department;  // 학부

	// 학사 경고
	void Warn()
	{
		// 구현 생략
	}
};

// 기숙사생 클래스
class DormStudent
{
public:
	string building; // 기숙사 명
	int roomNumber;	 // 방 번호

	// 벌점 부여
	void Warn()
	{
		// 구현 생략
	}
};

// 기숙사생이면서 학부생인 경우
// 다중 상속
class UnderGrad_DormStudent :public UnderGradStudent, public DormStudent
{
public:

};

int main()
{
	// 이 클래스는 두 부모의 모든 멤버를 가지고 있다
	UnderGrad_DormStudent std;

	std.name = "Lim-ttotti";
	std.roomNumber = 501;
	std.building = "ttotti";
	std.department = "Game";

	// 두 부모 클래스에서 정의 된 멤버함수가 이름이 같아서 어떤 클래스의 함수를 호출해야하는지 모른다(이름 충돌)
	// std.Warn();

	// 이렇게 선언하면 확실하게 정해져서 오류가 나지 않는다
	std.UnderGradStudent::Warn();


	// 포함과 상속을 구분해서 사용하는 방법
	// 포함은 Has-a 관계 - A가 B를 가지고 있다면(Has) 포함을 사용하라 (예 : 자동차와 타이어 - 자동차는 타이어를 가지고 있다 하지만 자동차는 타이어가 아니다)
	// 상속은 Is-a 관계 - A가 B라면(Is) 상속을 사용하라 (예 : 사과와 과일 - 사과는 과일의 한 종류이다 하지만 사과가 과일을 가지고 있지않다)
	// Rect 클래스와 Point 클래스 사각형은 점을 가지고 있다(Has) 사각형은 점이 아니다 그렇기때문에 Rect는 Point를 포함하게 한다
	// HTML 저장 클래스는 문서 저장 클래스의 한 종류이다(Is) 그러나 HTML 저장 클래스가 문서 저장 클래스를 가지고 있는 것은 아니다 그러므로 HTML 클래스를 문서저장 클래스에 상속받게 한다
	return 0;
}