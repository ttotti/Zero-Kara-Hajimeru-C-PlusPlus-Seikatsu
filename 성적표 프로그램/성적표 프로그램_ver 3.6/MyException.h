#ifndef MYEXCEPTION_H
#define MYEXCEPTION_H

#include <exception> // exception Ŭ������ ��ӹޱ� ���� �������

using namespace std;

// �� ������Ʈ ����� ����
// exception Ŭ������ ��� �޾Ҵ�
// C++���� �������� ����Ŭ������ �ִµ� �� ��� ����Ŭ������ exception Ŭ������ �θ�� ������ �ִ�
// �ڼ��Ѱ� ���ͳݰ� å 777p �� �����Ѵ�
class MyException :public exception
{
protected:
	string _Str;

public:
	// ������
	// msg:���ܸ� �����ϴ� ���ڿ�
	// �����ڿ����� ���ܸ� ������ ���ڿ��� ���ڷ� �޾Ƽ� ��� ���� _Str�� �����Ѵ�
	MyException(const string& msg)
		:_Str(msg)
	{
	}

	// �Ҹ���
	virtual ~MyException()
	{
	}

	// ���� ���� ���ڿ��� ��ȯ�Ѵ�
	// ��ȯ ��: ���ڿ�
	// what() �Լ��� �������̵� �Ѵ�
	// �� �Լ��� bad_alloc Ŭ������ ��� �� ������ ���� �ִµ�
	// ���ܿ� ���� ���� ���ڿ��� ��ȯ�ϴ� �Լ��� �����ڿ��� �Է� ���� ���ڿ��� ��ȯ�Ѵ�
	virtual const char *what() const
	{
		return _Str.c_str();
	}
};

#endif // !MYEXCEPTION_H

