#include <iostream>
#include <string>

using namespace std;

bool IsTermOfAbuse(const string sChatMessahe);

int main()
{
	string message;

	while (true)
	{
		cout << "체팅을 쳐주세요!!(종료: q): ";
		getline(cin, message);

		if (message == "q")
			break;

		if (IsTermOfAbuse(message))
			cout << "꿈나무!!" << endl;
		else
			cout << message << endl;
	}

	return 0;
}

bool IsTermOfAbuse(const string sChatMessahe)
{
	if (string::npos != sChatMessahe.find("바보") ||  // npos string 클래스가 제공하는 검색 보조 // 검색함수가 원하는 값을 찾지못하면 string::npos(-1)을 반환함
		string::npos != sChatMessahe.find("병신") || 
		string::npos != sChatMessahe.find("나쁜") || 
		string::npos != sChatMessahe.find("미친"))
		return true;

	return false;
}
