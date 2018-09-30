#include <iostream>

using namespace std;

enum { JOB_DWARF, JOB_WARRIOR, JOB_SORCERER }; // 이 문장에 의해서 차례대로 0 1 2 를 의미하는 심볼이 된다 그리고 다른 값으로 초기화가 가능하다
// 초기화시 그 심볼을 기준으로 다음심볼의 값은 1 올라간다 ex)JOB_WARRIOR = 3 으로 초기화시 다음 심볼인 JOB_SORCERER의 값은 자동으로 4 가 된다

enum NUMBER { ONE, TWO, THREE }; // 열거체 이름지정

enum SKILL { FIRE_BALL = 1, ICE_BALL };

struct Character
{
	int jobType;
	NUMBER number; // 열거체를 타입으로 사용할수있다 타입으로 사용시 타입으로 지정한 열거자만 보관할 수있는 새로운 정수형 타입이 된다
	SKILL skill;
};

int main()
{
	Character c;

	c.jobType = JOB_SORCERER;

	if (JOB_SORCERER == c.jobType)
	{
		cout << "마법사입니다!" << endl;
	}

	c.number = ONE; // 열거체가 타입인 변수 그리고 일단 정수 타입이지만 기존의 정수 타입과는 많은 부분이 다르다
	// c.number = JOB_DWARF; 오류 해당 열거체에 있는 열거자만 보관할수있다
	// c.number = ONE + TWO; 오류 열거체를 이용하여 덧셈과 같은 연산은 수행할 수 없다
	// c.number = 3;		 오류 정수를 열거체 변수에 대입하는 것도 불가능하다
	int a = THREE; //		 성공 반대의 경우는 가능하다 암시적으로 정수 타입으로 형변환된다
	int b = ONE + 1; //		 성공
	c.number = (NUMBER)2; // 성공 명시적인 형변환을 통해 정수 타입의 값을 대입할수있다 결과: THREE 가 된다
	c.number = (NUMBER)50000; // 그러나 열거체의 범위를 넘어서는 경우는 문제가 생길수있다 결과: 알수없음

	int n = 2;
	c.number = (NUMBER)n;
	cout << c.number << endl;

	cout << "원하는 스킬을 고르세요 (1. 파이어볼 2. 아이스볼): ";
	// cin >> c.skill; 오류
	cin >> n;
	c.skill = (SKILL)n;

	switch (c.skill)
	{
	//case JOB_WARRIOR: // 오류 이미 값이 있습니다
	//	cout << "1" << endl;
	//	break;
	case FIRE_BALL:
	{
		cout << "파이어볼!!" << endl;
		break;
	}
	case ICE_BALL:
	{
		cout << "아이스볼!!" << endl;
		break;
	}
	default:
		break;
	}

	return 0;
}