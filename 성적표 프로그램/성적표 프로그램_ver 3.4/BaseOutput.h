#ifndef BASE_OUTPUT_H
#define BASE_OUTPUT_H

#include <string>

using namespace std;

// 소스 코드를 간결하게 하기 위해서 타입을 새로 정의한다
typedef const string& STR;

// 콘솔 출력을 도와주는 클래스
// 이 클래스에는 나머지 세 클래스가 오버라이드해서 구현할 순수 가상 함수들이 존재한다
// 이 함수들은 세 개의 자식 클래스들의 사정을 모두 고려해서 만들어졌다
// 예를 들어 함수중에 콘솔화면을 지우는 함수가 있다고 하면 콘솔화면에는 쓸모가 있겠지만 텍스트 파일이나 HTML에는 필요가 없다
// 즉 추상 클래스에 순수 가상 함수를 만들 때는 자식 클래스들 모두가 사용할 수 있게 만드는 것이 중요하다
class BaseOutput
{
public:
	// 성적표 출력을 시작한다는 의미 각 자식 클래스들은 이 함수에서 필요한 준비 작업을 하게 된다
	virtual void BeginTable(STR title) = 0;
	// 헤더를 출력하는 용도의 함수다 인자로는 문자열의 배열과 배열의 크기를 전달한다
	// (예 {번호, 이름, 국어, 수학, 영어, 평균}과 같은 배열
	virtual void PutHeader(string headers[], int number) = 0;
	// 학생의 정보를 출력하는 용도의 함수 인자로는 각 항목의 값을 문자열의 배열로 전달한다
	// (예 {"1", "이현창","90","80"...}과 같은 배열
	virtual void PutRecord(string record[]) = 0;
	// 성적표 출력을 끝낸다는 의미의 함수 각 자식 클래스들은 이 함수에서 필요한 마무리 작업을 하게 된다
	virtual void EndTable() = 0;
	// 한 줄의 문자열을 출력하는 함수 각 자식 클래스들은 자신의 특징에 맞게 이 문자열을 출력할 것이다
	// (예 "전체평균 = 90.33" 과 같은 출력
	virtual void Write(STR text) = 0;

	// 자식 클래스들의 소멸자가 호출되는 것을 보장하기 위해 소멸자를 가상 함수로 만들었다
	virtual ~BaseOutput() {};
};

#endif // !BASE_OUTPUT_H

