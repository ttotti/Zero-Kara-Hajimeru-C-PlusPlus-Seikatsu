#include <iostream>

using namespace std;

class Parent
{
	// �ڽ��� ��� �Լ� �ܿ��� ������ �Ұ��ϴ�
	// �ݵ�� �ڽ�Ŭ������ ����� �ʹٸ� private �� ����
private:
	int priv;
	void F_priv();

	// �ڽ� Ŭ������ ��� �Լ��κ����� ���ٸ� ����Ѵ�
	// �ܺηκ��� ���ܾ� �ϴ� ����� protected �� ����
protected:
	int prot;
	void F_prot();

	// ��� ������ ������ ����Ѵ�
	// �� ���� ���� public �� ����
public:
	int pub;
	void F_pub();
};

class child :public Parent
{
public:

	int n;

	void AccessParents()
	{
		int n;

		// n = priv; (�Ұ���)
		n = prot; // ����
		n = pub; // ����

		// ��� �Լ��� �Ȱ���
		//F_priv();
		F_prot();
		F_pub()
	}
};

int main()
{
	Parent pa;

	int n;
	//n = pa.priv; (�Ұ���)
	//n = pa.prot; (�Ұ���)
	n = pa.pub; // (����)

	// ��� �Լ��� �Ȱ���
	//pa.F_priv(); (�Ұ���)
	//pa.F_prot(); (�Ұ���)
	pa.F_pub(); // (����)

	child cd;
	child* pcd;

	cd.n;
	cd.pub;
	pcd->pub;
	cd.F_pub();
	
	// ���԰��踦 ������ �ִ� Ŭ�������� ���� ���ѿ� �־ ���� �ƹ��� ���谡 ����
	// �׷��Ƿ� ���԰��踦 ������ �ִ� �� Ŭ������ ���� Ŭ������ public ������� �����Ҽ��ִ�

	return 0;
}