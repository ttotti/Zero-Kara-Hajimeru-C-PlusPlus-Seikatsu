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

	/*cout << "������ �����θ� �Է����ּ���!: ";
	getline(cin, apn);*/

	string directory;

	directory = DirectoryExtract(apn.c_str()); // �̷����Ÿ� ���� �Ʒ� ����� ����ϴ�..

	/*char path[256];
	cin.getline(path, 256);

	int len = strlen(path);

	for (int i = len-1; i >= 0; --i) // ���ڿ��� �ں��� �о \\ ������ �κ��� �տ� NULL���� �ִ´�
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