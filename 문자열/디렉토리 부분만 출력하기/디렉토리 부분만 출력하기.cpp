#include <iostream>
#include <string>

using namespace std;

string DirectoryExtract(const char* str)
{
	/*int len = str.length();*/
	int len = strlen(str);
	char* stc = new char[len + 1];

	for (int i = 0; i < len+1; i++)
	{
		stc[i] = str[len - i-1];
	}
	stc[len] = NULL;
	
	string extract = stc;

	int Find = extract.find("\\");

	string m = extract.substr(Find, len-Find);

	len = len - Find;

	char* n = new char[len + 1];
	const char* q = m.c_str();

	for (int i = 0; i < len + 1; i++)
	{
		n[i] = q[len - i - 1];
	}
	n[len] = NULL;

	m = n;

	delete[] stc;
	delete[] n;
	stc = NULL;
	n = NULL;

	return m;
}

int main()
{
	string apn = "d:\\My Library\\Temp\\dest.jpg";

	/*cout << "파일의 절대경로를 입력해주세요!: ";
	getline(cin, apn);*/

	string directory;

	directory = DirectoryExtract(apn.c_str()); // 이런짓거리 말고 아래 방법이 깔끔하다..

	/*char path[256];
	cin.getline(path, 256);

	int len = strlen(path);

	for (int i = len-1; i >= 0; --i) // 문자열을 뒤부터 읽어서 \\ 나오는 부분의 앞에 NULL값을 넣는다
	{
		if ('\\' == path[i])
		{
			path[i + 1] = NULL;
			break;
		}
	}*/

	cout << directory << endl;
	return 0;
}