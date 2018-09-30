#include <iostream>
#include <string>

using namespace std;

int main()
{
	char cstyle[] = "Are you a string, too?";

	string cppstyle; // string 객체 생성

	cppstyle = cstyle; // 변환

	cout << cppstyle << endl;
	cout << cstyle << endl;

	cppstyle[0] = 'B'; // C스타일의 문자열을 string 클래스에 대입했을때는 문자열의 복사가 일어난다 // 즉 수정을 해도 다른쪽에 영향이 가지 않는다

	cout << cppstyle << endl;

	////////////////////////////

	string cppstyle2 = "Yes, I am";

	const char* cstyle2 = NULL; // C스타일에 C++스타일의 문자열을 넣을경우 C스타일 변수는 const속성을 가져야한다

	cstyle2 = cppstyle2.c_str(); // c_str 함수는 C스타일 문자열의 주소를 반환한다 // 이 문자열은 여전히 cppstyle2의 소유이며 오직 읽는 용도로만 사용할수있다

	cout << cstyle2 << endl;
	cout << cppstyle2 << endl;

	///////////////////////////

	string cppstyle3 = "Lim-ttotti";

	char* cstyle3 = new char[cppstyle3.size() + 1]; // 동적 할당 // 문자열의 크기+1만큼 메모리를 할당한다

	strcpy(cstyle3, cppstyle3.c_str()); // C스타일로 변환 후 수정을 하고싶을때는 strcpy 로 복사하면 된다

	cstyle3[0] = 'K';

	cout << cstyle3 << endl;
	cout << cppstyle3 << endl;

	///////////////////////////

	char cs[20];
	string cpps;

	// cin 함수는 공백을 포함한 문자열을 입력받을수 없지만 getline 함수는 공백을 받을수있다 // C스타일은 사용법이 다르다
	cin.getline(cs,20); // 입력 함수 // C스타일 // 여기서 19자가 넘으면 cin 객체는 자신의 상태를 실패로 놓는다 그러므로 다음줄이 올바르게 작동하지 않는다
	cin.clear(); // 그래서 cin.clear() 함수를 써서 실패상태를 지워준다
	getline(cin, cpps); // C++ 스타일

	cout << cs << endl; // cin.getline 함수는 정확히 메모리크기만큼 입력된다 맨 끝바이트에는 NULL값이 들어가기 때문이다
	cout << cpps << endl;

	delete[] cstyle3;
	cstyle3 = NULL;

	return 0;
}