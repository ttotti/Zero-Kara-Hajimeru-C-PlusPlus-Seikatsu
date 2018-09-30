#include <iostream>
#include <string>

using namespace std;

int main()
{
	string s = "C++ style~"; // s라는 문자열 객체를 만든다 // string 은 basic_string 이라는 클래스를 typedef를 사용해서 재정의한 타입이다

	cout << s << endl;

	///////////////////// 복사

	string src = "Hanbit-Media"; // 문자열 객체를 생성

	string desc; // 복사를 담을 문자열 객체 생성
	
	desc = src; // 복사 // 그냥 대입연산자를 사용해서 대입하면 복사가 이루워진다 // 그렇다고 속도가 빠르거나 하는 장점은 없다 strcpy()를 사용하는거랑 같기 때문에 더 빨리 수행될 이유가 없다

	cout << desc << endl << endl;

	////////////////////// 길이
	
	// 문자열 객체 생성
	string s1;
	string s2 = "123";
	string s3 = "abcdefg";

	cout << s1.size() << endl; // 길이를 출력한다 // string 클래스의 멤버인 size() 함수를 호출하면 문자열의 길이를 반환한다
	cout << s2.size() << endl;
	cout << s3.size() << endl << endl;

	////////////////////// 결합 및 비교

	// 문자열 객체 생성
	string str1 = "abcde";
	string str2 = "fghij";

	str1 = str1 + str2; // 결합 // 두개의 문자열을 결합해서 str1에 대입한다

	if (str1 == "abcdefghij") // 문자열 비교 비교연산자를 사용해서 간단하게 비교할수있다
		cout << "같다" << endl;

	if (str1 != "12345") // 일부로 틀려본다
		cout << "같지않다" << endl;

	cout << str1 << endl << endl;

	////////////////////// 검색

	string text = "asfjlvljka lafjkkla sfkjalsiej sflkdsklLimttottifsldkfjoai alkfjalkj"; // 문장이 긴 문자열 객체 생성

	if (string::npos != text.find("Limttotti")) // string::npos 검색 보조
		cout << "찾음!" << endl;

	cout << "Offset of 'Limttotti = "<< text.find("Limttotti") << "\n"; // string 클래스의 함수 find() 는 자신 안에서 특저 문자열을 찾아본후 성공 시 그 위치를 반환한다
																		// 문자열 함수 중 strstr()이 이와 비슷한 일을 한다 차이점은 찾은 위치의 주소를 반환한다는 것이다
	cout << endl;

	/////////////////////// 문자열의 일부분 얻기

	string path = "c:\\My Document\\Pictures\\33.jpg"; // \을 한번 넣으면 이스케이프 문자열로 인식되기 때문에 두번 넣어줘야 역슬래쉬가 하나 있는 효과가 생긴다

	int len = path.length(); // 문자열의 길이를 얻는다

	string ext = path.substr(len - 3, 3); // 끝의 3바이트만 읽어온다 // substr(a,b) 는 a옵셋에 있는 문자부터 b개를 읽어오라 라는 뜻이다
	cout << ext << endl;

	return 0;
}