#include <iostream>
#include <string>

using namespace std;

bool IsTermOfAbuse(const string sChatMessahe);

int main()
{
	string message;

	while (true)
	{
		cout << "ü���� ���ּ���!!(����: q): ";
		getline(cin, message);

		if (message == "q")
			break;

		if (IsTermOfAbuse(message))
			cout << "�޳���!!" << endl;
		else
			cout << message << endl;
	}

	return 0;
}

bool IsTermOfAbuse(const string sChatMessahe)
{
	if (string::npos != sChatMessahe.find("�ٺ�") ||  // npos string Ŭ������ �����ϴ� �˻� ���� // �˻��Լ��� ���ϴ� ���� ã�����ϸ� string::npos(-1)�� ��ȯ��
		string::npos != sChatMessahe.find("����") || 
		string::npos != sChatMessahe.find("����") || 
		string::npos != sChatMessahe.find("��ģ"))
		return true;

	return false;
}
