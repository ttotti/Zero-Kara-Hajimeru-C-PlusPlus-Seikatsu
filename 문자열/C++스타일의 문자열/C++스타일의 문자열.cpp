#include <iostream>
#include <string>

using namespace std;

int main()
{
	string s = "C++ style~"; // s��� ���ڿ� ��ü�� ����� // string �� basic_string �̶�� Ŭ������ typedef�� ����ؼ� �������� Ÿ���̴�

	cout << s << endl;

	///////////////////// ����

	string src = "Hanbit-Media"; // ���ڿ� ��ü�� ����

	string desc; // ���縦 ���� ���ڿ� ��ü ����
	
	desc = src; // ���� // �׳� ���Կ����ڸ� ����ؼ� �����ϸ� ���簡 �̷������ // �׷��ٰ� �ӵ��� �����ų� �ϴ� ������ ���� strcpy()�� ����ϴ°Ŷ� ���� ������ �� ���� ����� ������ ����

	cout << desc << endl << endl;

	////////////////////// ����
	
	// ���ڿ� ��ü ����
	string s1;
	string s2 = "123";
	string s3 = "abcdefg";

	cout << s1.size() << endl; // ���̸� ����Ѵ� // string Ŭ������ ����� size() �Լ��� ȣ���ϸ� ���ڿ��� ���̸� ��ȯ�Ѵ�
	cout << s2.size() << endl;
	cout << s3.size() << endl << endl;

	////////////////////// ���� �� ��

	// ���ڿ� ��ü ����
	string str1 = "abcde";
	string str2 = "fghij";

	str1 = str1 + str2; // ���� // �ΰ��� ���ڿ��� �����ؼ� str1�� �����Ѵ�

	if (str1 == "abcdefghij") // ���ڿ� �� �񱳿����ڸ� ����ؼ� �����ϰ� ���Ҽ��ִ�
		cout << "����" << endl;

	if (str1 != "12345") // �Ϻη� Ʋ������
		cout << "�����ʴ�" << endl;

	cout << str1 << endl << endl;

	////////////////////// �˻�

	string text = "asfjlvljka lafjkkla sfkjalsiej sflkdsklLimttottifsldkfjoai alkfjalkj"; // ������ �� ���ڿ� ��ü ����

	if (string::npos != text.find("Limttotti")) // string::npos �˻� ����
		cout << "ã��!" << endl;

	cout << "Offset of 'Limttotti = "<< text.find("Limttotti") << "\n"; // string Ŭ������ �Լ� find() �� �ڽ� �ȿ��� Ư�� ���ڿ��� ã�ƺ��� ���� �� �� ��ġ�� ��ȯ�Ѵ�
																		// ���ڿ� �Լ� �� strstr()�� �̿� ����� ���� �Ѵ� �������� ã�� ��ġ�� �ּҸ� ��ȯ�Ѵٴ� ���̴�
	cout << endl;

	/////////////////////// ���ڿ��� �Ϻκ� ���

	string path = "c:\\My Document\\Pictures\\33.jpg"; // \�� �ѹ� ������ �̽������� ���ڿ��� �νĵǱ� ������ �ι� �־���� ���������� �ϳ� �ִ� ȿ���� �����

	int len = path.length(); // ���ڿ��� ���̸� ��´�

	string ext = path.substr(len - 3, 3); // ���� 3����Ʈ�� �о�´� // substr(a,b) �� a�ɼ¿� �ִ� ���ں��� b���� �о���� ��� ���̴�
	cout << ext << endl;

	return 0;
}