#include <string>

using namespace std;

// �кλ� Ŭ����
class UnderGradStudent
{
public:
	string name;		// �̸�
	string department;  // �к�

	// �л� ���
	void Warn()
	{
		// ���� ����
	}
};

// ������ Ŭ����
class DormStudent
{
public:
	string building; // ����� ��
	int roomNumber;	 // �� ��ȣ

	// ���� �ο�
	void Warn()
	{
		// ���� ����
	}
};

// �������̸鼭 �кλ��� ���
// ���� ���
class UnderGrad_DormStudent :public UnderGradStudent, public DormStudent
{
public:

};

int main()
{
	// �� Ŭ������ �� �θ��� ��� ����� ������ �ִ�
	UnderGrad_DormStudent std;

	std.name = "Lim-ttotti";
	std.roomNumber = 501;
	std.building = "ttotti";
	std.department = "Game";

	// �� �θ� Ŭ�������� ���� �� ����Լ��� �̸��� ���Ƽ� � Ŭ������ �Լ��� ȣ���ؾ��ϴ��� �𸥴�(�̸� �浹)
	// std.Warn();

	// �̷��� �����ϸ� Ȯ���ϰ� �������� ������ ���� �ʴ´�
	std.UnderGradStudent::Warn();


	// ���԰� ����� �����ؼ� ����ϴ� ���
	// ������ Has-a ���� - A�� B�� ������ �ִٸ�(Has) ������ ����϶� (�� : �ڵ����� Ÿ�̾� - �ڵ����� Ÿ�̾ ������ �ִ� ������ �ڵ����� Ÿ�̾ �ƴϴ�)
	// ����� Is-a ���� - A�� B���(Is) ����� ����϶� (�� : ����� ���� - ����� ������ �� �����̴� ������ ����� ������ ������ �����ʴ�)
	// Rect Ŭ������ Point Ŭ���� �簢���� ���� ������ �ִ�(Has) �簢���� ���� �ƴϴ� �׷��⶧���� Rect�� Point�� �����ϰ� �Ѵ�
	// HTML ���� Ŭ������ ���� ���� Ŭ������ �� �����̴�(Is) �׷��� HTML ���� Ŭ������ ���� ���� Ŭ������ ������ �ִ� ���� �ƴϴ� �׷��Ƿ� HTML Ŭ������ �������� Ŭ������ ��ӹް� �Ѵ�
	return 0;
}