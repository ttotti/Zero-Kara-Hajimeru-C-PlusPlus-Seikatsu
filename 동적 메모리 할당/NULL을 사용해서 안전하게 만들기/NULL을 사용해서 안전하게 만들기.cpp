#include <iostream>

using namespace std;

int main()
{
	short* p = new short[100]; // �޸� �Ҵ� �� 200 ����Ʈ�� �Ҵ��Ѵ�

	cout << "p = " << p << endl;

	delete[] p; // �Ҵ��� �޸𸮸� �����Ѵ�
	p = NULL; // ���������Ƿ� p�� �ƹ��͵� ����Ű�� ���� �ʴ� �׷��� �����ϰ� NULL���� �־��ش�

	cout << "p = " << p << endl;

	delete[] p; // �̹� ������ �޸𸮸� �ι� �����Ҽ����� �� ��� ġ������ ������ �߻��Ѵ� ������ ������ �����ϰ� NULL���� �־��־����Ƿ� �������� �ʴ�
	p = NULL;

	return 0;
}