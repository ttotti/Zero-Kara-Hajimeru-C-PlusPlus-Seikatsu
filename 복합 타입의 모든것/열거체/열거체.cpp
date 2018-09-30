#include <iostream>

using namespace std;

enum { JOB_DWARF, JOB_WARRIOR, JOB_SORCERER }; // �� ���忡 ���ؼ� ���ʴ�� 0 1 2 �� �ǹ��ϴ� �ɺ��� �ȴ� �׸��� �ٸ� ������ �ʱ�ȭ�� �����ϴ�
// �ʱ�ȭ�� �� �ɺ��� �������� �����ɺ��� ���� 1 �ö󰣴� ex)JOB_WARRIOR = 3 ���� �ʱ�ȭ�� ���� �ɺ��� JOB_SORCERER�� ���� �ڵ����� 4 �� �ȴ�

enum NUMBER { ONE, TWO, THREE }; // ����ü �̸�����

enum SKILL { FIRE_BALL = 1, ICE_BALL };

struct Character
{
	int jobType;
	NUMBER number; // ����ü�� Ÿ������ ����Ҽ��ִ� Ÿ������ ���� Ÿ������ ������ �����ڸ� ������ ���ִ� ���ο� ������ Ÿ���� �ȴ�
	SKILL skill;
};

int main()
{
	Character c;

	c.jobType = JOB_SORCERER;

	if (JOB_SORCERER == c.jobType)
	{
		cout << "�������Դϴ�!" << endl;
	}

	c.number = ONE; // ����ü�� Ÿ���� ���� �׸��� �ϴ� ���� Ÿ�������� ������ ���� Ÿ�԰��� ���� �κ��� �ٸ���
	// c.number = JOB_DWARF; ���� �ش� ����ü�� �ִ� �����ڸ� �����Ҽ��ִ�
	// c.number = ONE + TWO; ���� ����ü�� �̿��Ͽ� ������ ���� ������ ������ �� ����
	// c.number = 3;		 ���� ������ ����ü ������ �����ϴ� �͵� �Ұ����ϴ�
	int a = THREE; //		 ���� �ݴ��� ���� �����ϴ� �Ͻ������� ���� Ÿ������ ����ȯ�ȴ�
	int b = ONE + 1; //		 ����
	c.number = (NUMBER)2; // ���� ������� ����ȯ�� ���� ���� Ÿ���� ���� �����Ҽ��ִ� ���: THREE �� �ȴ�
	c.number = (NUMBER)50000; // �׷��� ����ü�� ������ �Ѿ�� ���� ������ ������ִ� ���: �˼�����

	int n = 2;
	c.number = (NUMBER)n;
	cout << c.number << endl;

	cout << "���ϴ� ��ų�� ������ (1. ���̾ 2. ���̽���): ";
	// cin >> c.skill; ����
	cin >> n;
	c.skill = (SKILL)n;

	switch (c.skill)
	{
	//case JOB_WARRIOR: // ���� �̹� ���� �ֽ��ϴ�
	//	cout << "1" << endl;
	//	break;
	case FIRE_BALL:
	{
		cout << "���̾!!" << endl;
		break;
	}
	case ICE_BALL:
	{
		cout << "���̽���!!" << endl;
		break;
	}
	default:
		break;
	}

	return 0;
}