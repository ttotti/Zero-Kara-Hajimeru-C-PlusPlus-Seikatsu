#include <iostream>
#include <string>

using namespace std;

// �ֿ� ���� Ŭ����
class Pet
{
public:
	void Eat();
	void Eat(const string& it);

	string name;
};

void Pet::Eat()
{
	cout << name << " says, 'Where is the food?'\n";
}

void Pet::Eat(const string& it)
{
	cout << name << " says, 'I like " << it << ".'\n";
}

// ������ Ŭ���� (�θ�Ŭ���� = �ֿ� ����Ŭ����)
class Dog :public Pet
{
	// ����!
	// �θ� Ŭ�������� �����ε�� �Լ� �߿� ��� �� �ϳ��� �������̵� �ϸ� ������ �ٸ� �Լ��鵵 ��� ����� �� ����
	//void Eat();
};

//void Dog::Eat()
//{
//	cout << name << " says, 'Grow1~\n";
//}

int main()
{
	Dog dog1;

	dog1.name = "ttotti";
	
	dog1.Eat();
	dog1.Eat("milk");

	return 0;
}

// �����ε�� �޼ҵ�(�Լ�)�� �̸��� ������ ������ ���� �Ǵ� Ÿ���� �ٸ� �Լ��� ���Ѵ�
// ��) void Overload(int i) {}
//     void Overload(int i, int j) {}
//     void Overload(double i, int j) {}
// ������ �Լ��� ��ȯ�ϴ� Ÿ���� �ٸ� ��� �������� ���� �ʴ´�
// ��) void Overload(int i) {}
//     double Overload(int i) {} ������ ���� ����!!

// �������̵�� ��� ���� ����(�θ�) Ŭ������ �޼ҵ�(�Լ�)�� �ٽ� �ѹ� �ڽ� Ŭ�������� ������ �ϴ� ���̴�
// �޼ҵ��� �̸��� ���� �ؾ� �ϸ� ���� ������ ����, Ÿ�Ե� ���� �ؾ� �Ѵ�

// ��) �θ� Ŭ������ void Overload() �Լ��� �ְ� �� �Լ��� ��� ��������� ���ڸ� 1�� �÷��ִ� ����� ������ �ִٸ�
//     �ڽ� Ŭ������ void Overload() �Լ��� ��� ��������� ���ڸ� 123�� �÷��ִ� ������� ������ �� �� �ִ�

// ���� !: �θ� Ŭ�������� �����ε�� �Լ� �߿� ��� �� �ϳ��� �������̵� �ϸ� ������ �ٸ� �Լ��鵵 ��� ����� �� ����
// ��) �θ� Ŭ����
//     void Overload() { i += 1 } 1�� �÷��ش�
//     void Overload(int i) // �����ε� �ߴ�
//     int Drow() �θ� Ŭ������ �ٸ� �Լ�

//     �ڽ� Ŭ����
//     void Overload() {i += 123} �������̵� �ߴ�

//	   �θ� Ŭ�������� �����ε� �� �Լ��� �ڽ� Ŭ�������� �������̵��� �ϸ� �ٸ� ��� �Լ��� ����� �� ����