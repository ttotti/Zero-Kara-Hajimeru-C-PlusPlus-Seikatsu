#ifndef DOG_H
#define DOG_H

// �۸��̿� ���õ� �͵�
namespace Dog
{
	// �۸��� �� ���� ����
	struct Info
	{
		char name[20];
		int age;
	};

	extern Info dogs[20]; // �۸��� ����Ʈ
	extern int count;	   // ��ü �۸��̵��� ��

	void CreateAll(); // ��� �۸��� ���� �Լ�
}
#endif // !DOG_H

