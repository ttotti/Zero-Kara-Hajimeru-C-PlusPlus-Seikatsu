#include <iostream>

using namespace std;

void PrintMessage(); // 함수 원형
void PrintMyname();
int Three();
char* PrintMyname2();

int main()
{
	PrintMessage(); // 함수 호출

	/////////////

	for (int i = 0; i < 10; i++)
	{
		PrintMyname();
	}

	/////////////

	int ref;

	ref = Three(); // 함수를 호출하고 반환값을 보관한다

	cout << "ref = " << ref << endl;

	////////////

	for (int i = 0; i < 10; i++)
	{
		char* name = PrintMyname2();
		cout << name << endl;
	}

	return 0; // return의 의미는 이 함수를 끝나라 와 뒤에 나오는 값을 반환하라 두개가 있다
}

void PrintMessage() // 함수 정의
{
	cout << "Hi, I'm your first function!!!\n";
}


//////////////////////////////////////////////////////

void PrintMyname()
{
	cout << "My name is Limttotti!!" << endl;
}

//////////////////////////////////////////////////////

int Three() // 3을 반환하는 함수
{
	return 3;
}

char* PrintMyname2()
{
	return "My name is Lim ttotti2";
}
