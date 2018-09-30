#include <iostream>

using namespace std;

struct StudentInfo
{
	char name[20];
	int stdNumber;
	float grade[2];
};

struct User 
{
	char userID[20];
	char passwd[20];
	int scores_per_stage[5];
	unsigned long magicPt;
	unsigned long healthPt;
};

int main()
{
	StudentInfo si = { "Kim chol-su",200121233,{3.2f,3.5f} };

	cout << si.name << endl;
	cout << si.stdNumber << endl;
	cout << si.grade[0] << ", " << si.grade[1] << endl << endl;

	/////////////////////////////////////////////////////////////

	StudentInfo stdInfos[5] = {
		{"Kim chol-su",200121233,{ 3.2f,5.5f }},
		{ "dim chol-su",200141233,{ 4.2f,3.5f }},
		{ "gim chol-su",200151233,{ 5.2f,3.5f }},
		{ "qim chol-su",200161233,{ 6.2f,3.5f }},
		{ "sim chol-su",200171233,{ 7.2f,3.5f }},
	};

	for (int i = 0; i < 5; i++)
	{
		cout << stdInfos[i].name << endl;
		cout << stdInfos[i].stdNumber << endl;
		cout << stdInfos[i].grade[0] << ", " << stdInfos[i].grade[1] << endl;
		cout << endl;
	}

	//////////////////////////////////////////////////////////////

	User user[3] = {
		{"denzang","sd933k",{80,56,72,86,91},300,10010},
		{"zzazang","!@sd487",{100,98,100,100,91},20000,19000},
		{"gochuzang","df321#4",{34,54,70,48,54},400,5000}
	};

	for (int i = 0; i < 3; i++)
	{
		cout << "userID: "<<user[i].userID << "  userPasswd: " << user[i].passwd << endl;
		cout << "스테이지별 점수" << endl;
		for (int j = 0; j < 5; j++)
		{
			cout << j+1 << "번: " << user[i].scores_per_stage[j] << "  ";
		}
		cout << endl << "체력포인트: " << user[i].healthPt << ", " << "마법포인트: " << user[i].magicPt << endl;
		cout << endl;
	}

	return 0;
}