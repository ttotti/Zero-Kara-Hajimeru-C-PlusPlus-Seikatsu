#include <iostream>

using namespace std;

class AccessControl
{
public: // �ܺο��� ������ �����ϴ� // �����ڿ� �Ҹ��ڴ� public���� �ϴ°��� ��Ģ�̴�
	char publicData;
	void publicFunc();

protected: // �ܺο��� ������ �Ұ��ϴ� // private ���� �������� �ִ�
	int protectedData;
	void protectedFunc();

private: // �ܺο��� ������ �Ұ��ϴ�
	float privateData;
	void privateFunc();

public:
	void AccessAllMembers(); // Ŭ������ ������ ����Լ������� ���� ���ѿ� ������� ��� ����� ������ �����ϴ�
};

void AccessControl::AccessAllMembers() // ����Լ� AccessControl() ���� ��� ����� �����Ҽ��ִ�
{
	publicData = 100;
	publicFunc();

	protectedData = 200;
	protectedFunc();

	privateData = 300;
	privateFunc();
}


int main()
{
	AccessControl ac;

	ac.publicData = 100; // ������� public ���� �������Ƿ� ������ �����ϴ�
	ac.publicFunc();

	ac.AccessAllMembers();

	return 0;
}