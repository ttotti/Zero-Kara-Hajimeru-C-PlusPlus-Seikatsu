#include <iostream>
#include <string>
#include <cstring>
#include <time.h>

using namespace std;

bool IsTermOfAbuse(const char* pChatMessage) // 문자열 판별 함수 // strcmp 함수를 사용해서 문자열을 비교한다
{
	if (strcmp(pChatMessage, "바보") == 0)
		return true;
	else if (strcmp(pChatMessage, "병신") == 0)
		return true;
	else if (strcmp(pChatMessage, "나쁜 애") == 0)
		return true;
	else if (strcmp(pChatMessage, "미친 애") == 0)
		return true;

	return false;
}

char* CopyMessage() // 사용자가 입력한 만큼 크기를 할당한 후 문자열을 반환한다
{
	char m[100]; // 입력받을 변수를 적당한 크기만큼 정의해준다

	cout << "채팅을 쳐주세요(종료 q): ";
	//cin >> m;	// 입력을 받는 함수지만.. 공백을 입력 받지 못한다
	//getline(cin, m); // 애는 공백도 포함한 문자열을 받지만 아쉽게 위에서 정의한 변수의 타입이 char이다 애는 string 형을 받는다(C++ 스타일 문자열)
	scanf("%[^\n]%*c", m); // 성공 // [^\n] 라는 뜻은 input값으로 개행(\n)을 받기 전까지는 계속 입력받는다는 것을 뜻한다 *c 는 아마 char형을 받는다는 뜻이 아닐까..? 저거 없으니까 난리가 난다..

	int len = strlen(m); // 입력받은 문자열의 NULL전까지의 길이를 계산하고
	char* message = new char[len + 1]; // 그 길이의 +1 만큼의 메모리를 할당한다!!

	strcpy(message, m); // 복사 후
	//for (int i = 0; i < len + 1; i++)
	//{
	//	message[i] = m[i];
	//}

	return message; // 문자열 반환!
}

int main()
{
	char* message = NULL;
	//cout << "채팅을 쳐주세요: ";
	//cin >> message;

	while (true)
	{
		message = CopyMessage(); // 먼가 내가 문자열을 입력한 만큼 크기를 할당받고 싶었다

		if (strcmp(message, "q") == 0) // 종료 조건문
			break;
	
		int number = 0;
		srand((unsigned)time(NULL)); // 랜덤함수

		if (IsTermOfAbuse(message)) // 문자열을 비교 후 욕을 판별한다
		{
			number = rand() % 4; // 먼가 프리스타일이 생각나서 욕하면 랜덤으로 아무말을 뿜어보고 싶었다

			switch (number)
			{
			case 0:
				cout << "꿈나무" << endl;
				break;
			case 1:
				cout << "사랑해요!" << endl;
				break;
			case 2:
				cout << "좋아해요!!" << endl;
				break;
			case 3:
				cout << "멋져요!!!" << endl;
				break;
			}
		}
		else
		{
			cout << message << endl;
		}
		cout << endl;
	}

	delete[] message; // 함수 안에서 메모리를 할당받았지만 반환 값을 가진애를 죄종적으로 해제한다
	message = NULL;

	return 0;
}