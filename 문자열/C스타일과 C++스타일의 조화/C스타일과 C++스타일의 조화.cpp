#include <iostream>
#include <string>

using namespace std;

int main()
{
	char cstyle[] = "Are you a string, too?";

	string cppstyle; // string ��ü ����

	cppstyle = cstyle; // ��ȯ

	cout << cppstyle << endl;
	cout << cstyle << endl;

	cppstyle[0] = 'B'; // C��Ÿ���� ���ڿ��� string Ŭ������ ������������ ���ڿ��� ���簡 �Ͼ�� // �� ������ �ص� �ٸ��ʿ� ������ ���� �ʴ´�

	cout << cppstyle << endl;

	////////////////////////////

	string cppstyle2 = "Yes, I am";

	const char* cstyle2 = NULL; // C��Ÿ�Ͽ� C++��Ÿ���� ���ڿ��� ������� C��Ÿ�� ������ const�Ӽ��� �������Ѵ�

	cstyle2 = cppstyle2.c_str(); // c_str �Լ��� C��Ÿ�� ���ڿ��� �ּҸ� ��ȯ�Ѵ� // �� ���ڿ��� ������ cppstyle2�� �����̸� ���� �д� �뵵�θ� ����Ҽ��ִ�

	cout << cstyle2 << endl;
	cout << cppstyle2 << endl;

	///////////////////////////

	string cppstyle3 = "Lim-ttotti";

	char* cstyle3 = new char[cppstyle3.size() + 1]; // ���� �Ҵ� // ���ڿ��� ũ��+1��ŭ �޸𸮸� �Ҵ��Ѵ�

	strcpy(cstyle3, cppstyle3.c_str()); // C��Ÿ�Ϸ� ��ȯ �� ������ �ϰ�������� strcpy �� �����ϸ� �ȴ�

	cstyle3[0] = 'K';

	cout << cstyle3 << endl;
	cout << cppstyle3 << endl;

	///////////////////////////

	char cs[20];
	string cpps;

	// cin �Լ��� ������ ������ ���ڿ��� �Է¹����� ������ getline �Լ��� ������ �������ִ� // C��Ÿ���� ������ �ٸ���
	cin.getline(cs,20); // �Է� �Լ� // C��Ÿ�� // ���⼭ 19�ڰ� ������ cin ��ü�� �ڽ��� ���¸� ���з� ���´� �׷��Ƿ� �������� �ùٸ��� �۵����� �ʴ´�
	cin.clear(); // �׷��� cin.clear() �Լ��� �Ἥ ���л��¸� �����ش�
	getline(cin, cpps); // C++ ��Ÿ��

	cout << cs << endl; // cin.getline �Լ��� ��Ȯ�� �޸�ũ�⸸ŭ �Էµȴ� �� ������Ʈ���� NULL���� ���� �����̴�
	cout << cpps << endl;

	delete[] cstyle3;
	cstyle3 = NULL;

	return 0;
}