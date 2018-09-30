#include <iostream>

using namespace std;

int main()
{
	unsigned int scores[10] = { 10,100,94,36,72,88,60,60,80,24 };

	float TotalAve = 0.0f;

	cout << "도전 퀴즈왕!!!!" << endl;
	for (int i = 0; i < 10; i++)
	{
		cout << i+1 << "번 선수 점수: " << scores[i] << endl<<endl;
		TotalAve += scores[i];
	}
	TotalAve = TotalAve / 10.0f;

	cout << "전체 평균: " << TotalAve << endl;

	cout << "탈락명단 : ";
	for (int i = 0; i < 10; i++)
	{
		if (scores[i] < TotalAve)
		{
			cout << i+1 << "번 선수  ";
			scores[i] = 0;
		}
	}

	cout << endl;

	int select;
	cout << "재출력을 원하시면 1번  " << "종료하시고 싶으면 2번을 눌러주세요" << endl;
	cin >> select;

	switch (select)
	{
	case 1:
	{
		for (int i = 0; i < 10; i++)
		{
			if (scores[i] == 0)
				continue;

			cout << i+1 << "번 선수 점수: " << scores[i] << endl << endl;
		}
		break;
	}
	case 2:
		return 0;
	default:
		cout << "다시 입력해주세요" << endl;
		break;
	}

	return 0;
}