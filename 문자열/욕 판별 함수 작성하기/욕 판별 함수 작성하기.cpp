#include <iostream>
#include <string>
#include <cstring>
#include <time.h>

using namespace std;

bool IsTermOfAbuse(const char* pChatMessage) // ���ڿ� �Ǻ� �Լ� // strcmp �Լ��� ����ؼ� ���ڿ��� ���Ѵ�
{
	if (strcmp(pChatMessage, "�ٺ�") == 0)
		return true;
	else if (strcmp(pChatMessage, "����") == 0)
		return true;
	else if (strcmp(pChatMessage, "���� ��") == 0)
		return true;
	else if (strcmp(pChatMessage, "��ģ ��") == 0)
		return true;

	return false;
}

char* CopyMessage() // ����ڰ� �Է��� ��ŭ ũ�⸦ �Ҵ��� �� ���ڿ��� ��ȯ�Ѵ�
{
	char m[100]; // �Է¹��� ������ ������ ũ�⸸ŭ �������ش�

	cout << "ä���� ���ּ���(���� q): ";
	//cin >> m;	// �Է��� �޴� �Լ�����.. ������ �Է� ���� ���Ѵ�
	//getline(cin, m); // �ִ� ���鵵 ������ ���ڿ��� ������ �ƽ��� ������ ������ ������ Ÿ���� char�̴� �ִ� string ���� �޴´�(C++ ��Ÿ�� ���ڿ�)
	scanf("%[^\n]%*c", m); // ���� // [^\n] ��� ���� input������ ����(\n)�� �ޱ� �������� ��� �Է¹޴´ٴ� ���� ���Ѵ� *c �� �Ƹ� char���� �޴´ٴ� ���� �ƴұ�..? ���� �����ϱ� ������ ����..

	int len = strlen(m); // �Է¹��� ���ڿ��� NULL�������� ���̸� ����ϰ�
	char* message = new char[len + 1]; // �� ������ +1 ��ŭ�� �޸𸮸� �Ҵ��Ѵ�!!

	strcpy(message, m); // ���� ��
	//for (int i = 0; i < len + 1; i++)
	//{
	//	message[i] = m[i];
	//}

	return message; // ���ڿ� ��ȯ!
}

int main()
{
	char* message = NULL;
	//cout << "ä���� ���ּ���: ";
	//cin >> message;

	while (true)
	{
		message = CopyMessage(); // �հ� ���� ���ڿ��� �Է��� ��ŭ ũ�⸦ �Ҵ�ް� �;���

		if (strcmp(message, "q") == 0) // ���� ���ǹ�
			break;
	
		int number = 0;
		srand((unsigned)time(NULL)); // �����Լ�

		if (IsTermOfAbuse(message)) // ���ڿ��� �� �� ���� �Ǻ��Ѵ�
		{
			number = rand() % 4; // �հ� ������Ÿ���� �������� ���ϸ� �������� �ƹ����� �վ�� �;���

			switch (number)
			{
			case 0:
				cout << "�޳���" << endl;
				break;
			case 1:
				cout << "����ؿ�!" << endl;
				break;
			case 2:
				cout << "�����ؿ�!!" << endl;
				break;
			case 3:
				cout << "������!!!" << endl;
				break;
			}
		}
		else
		{
			cout << message << endl;
		}
		cout << endl;
	}

	delete[] message; // �Լ� �ȿ��� �޸𸮸� �Ҵ�޾����� ��ȯ ���� �����ָ� ���������� �����Ѵ�
	message = NULL;

	return 0;
}