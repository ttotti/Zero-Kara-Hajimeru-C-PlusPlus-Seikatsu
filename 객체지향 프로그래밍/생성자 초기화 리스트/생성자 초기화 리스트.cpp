#include <iostream>

using namespace std;

class NeedConstructor
{
public:
	const int maxCount;
	int& ref;
	int sample;

	NeedConstructor();
	NeedConstructor(int count, int& number);

};

NeedConstructor::NeedConstructor()
	:maxCount(100),ref(sample) // �������� �ʱ�ȭ ����Ʈ // const �Ӽ� Ÿ���̳� ���۷��� Ÿ���� ������ �ʱ�ȭ �� ���ִ�
{
	sample = 200;
}

NeedConstructor::NeedConstructor(int count, int& number) // ���ڰ� �ִ� ������ // ���ڸ� ����ؼ� �ʱ�ȭ�� �Ҽ��ִ�
	: maxCount(count), ref(number)
{
	sample = 200;
}

int main()
{
	NeedConstructor cr;

	cout << cr.maxCount << endl;
	cout << cr.ref << endl;
	cout << cr.sample << endl;
	cout << endl;

	/////////////////////////////////

	int number = 400;

	NeedConstructor cr2(300, number);

	cout << "cr.maxCount = " << cr.maxCount << endl;
	cout << "cr.ref = " << cr.ref << endl;

	return 0;
}