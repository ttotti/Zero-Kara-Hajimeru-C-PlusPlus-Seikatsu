#ifndef CAT_H
#define CAT_H

// �߿��̿� ���õ� �͵�
namespace Cat
{
	// �߿��� �� ���� ����
	class Info
	{
	public:
		void Meow();
	protected:
		char name[20];
	};

	// ���⿡ extern Ű���带 �ٿ��� ������
	// �ϴ� extern Ű���带 ���̴� ���� �ٸ� ���Ͽ��� ������ ������ ����ϰڴٰ� �����ϴ� �ǹ̸� ������ �ִ�
	// �ٸ� ��� ��� ������ �׷����� cat.h ������ �뵵�� example.cpp �� ���� ���Ͽ� ���ؼ� ���ԵǱ� ���� ���̴�
	// �� example.cpp(�ٸ�.cpp ����) ���� cat.cpp�� ���ǵ� cats�� count ������ ������ �� �ְ� ����� ��Ȱ�� �Ѵ�
	extern Info cats[20];
	extern int count;

	void CreateAll();
}

#endif // !CAT_H

