#include "student.h"
#include <sstream>
#include <iostream>
#include <iomanip>
#include <limits> // numeric_limits<streamsize>::max() �� ����ϱ� ���� �������

using namespace std;

// ������
// sNo : �й�
Student::Student(int sNo)
{
	// �й� ����
	this->sNo = sNo;

	// ������ ��� �ʱ�ȭ
	kor = eng = math = 0;
	ave = 0.0f;
}

// ���� ������ �Է� �޴´�
// ���α׷��� �����ϰ� �޴����� �۾��� ��ȣ�� ������ �Է¹��� �� cin ��ü�� ������ �ƴ� 'a' �� ���� ���ڰ� �ԷµǸ�
// �� ���Ŀ� cin ��ü�� �츮�� �䱸�� ������ü ������ �޴��� ����ϰų� �ٸ� ������ �Ͼ�� �ȴ�
// �װ��� ���Ը��� cin�� �ľ��� ���̴�
// cin ��ü�� ����ؼ� ���� ���� �Է� ���� ���� �׻� �̷� ������ ���־���Ѵ�
// �ڼ��Ѱ� ���ͳݰ� <��Ʈ���� ����> 881p �� �����Ѵ�
void Student::Input()
{
	// ���� �Է��� ���� �ݺ�
	// �ùٸ� �Է��� ���� ������ �ݺ��Ѵ�
	while (1)
	{
		cout << "�̸�(�������) ����, ����, ���� ������ �Է��ϼ��� : " << endl;
		cin >> name >> kor >> eng >> math;

		// ������ ���ٸ� �ݺ��� ������
		// ��� �Լ� good() �� cin ��ü�� ���¸� �����ϴ� �Լ���
		// cin ��ü�� �ľ� ���¶�� false �� ��ȯ�Ѵ�
		if (cin.good())
			break;

		// ������ �ִٸ� cin ��ü�� �ʱ�ȭ �Ѵ�
		// cin ��ü�� �ľ� ���¶�� �ٽ� �������� �ǵ��� �ʿ䰡 �ִ�
		// ��� �Լ� clear()�� �ľ� ���¸� ����� ���� ���·� �����
		cin.clear();
		// ����Լ� ignore()�� cin ��ü�� �Է��� ������ ���������� �Լ���
		// �Լ��ȿ� ���ڷ� �־��� ���� ��� �Է� ���� ����� ���ؼ� ���� ���ε� �ϴ� �ܿ����� // ������� <limits> ����
		cin.ignore(numeric_limits<streamsize>::max()), '\n');

		// �ȳ� �޽����� ����Ѵ�
		cout << "[�Է��� �߸��Ǿ����ϴ�] \n";
	}

	// ���� ����� ����Ѵ�
	ave = float(kor + eng + math) / 3.0f;
}

// ���� ������ ȭ�鿡 ����Ѵ�
void Student::Show(BaseOutput& out) const
{
	// ���� ��� �ϳ��� ���ڿ��� �����
	stringstream ss;
	ss.precision(2);
	ss << fixed;
	ss << sNo << " " << name << " " << kor << " " << eng << " " << math << " - " << ave;

	// 7���� ���ڿ��� ���� �迭�� ����� �ʱ�ȭ �Ѵ�
	string record[7];
	for (int i = 0; i < 7; i++)
		ss >> record[i];

	// ��� ��ü�� ������
	out.PutRecord(record);
}

int Student::GetStdNumber() const
{
	return sNo;
}

string Student::GetName() const
{
	return name;
}

int Student::GetKor() const
{
	return kor;
}

int Student::GetEng() const
{
	return eng;
}

int Student::GetMath() const
{
	return math;
}

float Student::GetAverage() const
{
	return ave;
}

//------------------------------------------
// EngStudent
//------------------------------------------

// ������
EngStudent::EngStudent(int sNo)
	:Student(sNo)
{
	hi_eng = 0;
}

void EngStudent::Input()
{
	while (1)
	{
		cout << "�̸�(�������) ����, ����, ����, ��޿��� ������ �Է��ϼ��� : " << endl;
		cin >> name >> kor >> eng >> math >> hi_eng;

		if (cin.good())
			break;

		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');

		cout << "[�Է��� �߸��Ǿ����ϴ�] \n";
	}
	// ���� ����� ����Ѵ�
	ave = float(kor + eng + math+hi_eng) / 4.0f;
}

void EngStudent::Show(BaseOutput& out) const
{
	// ���� ��� �ϳ��� ���ڿ��� �����.
	stringstream ss;
	ss.precision(2);
	ss << fixed;
	ss << sNo << " " << name << " " << kor << " ";
	ss << eng << " " << math << " " << hi_eng << " " << ave;

	// 7���� ���ڿ��� ���� �迭�� ����� �ʱ�ȭ�Ѵ�.
	string record[7];
	for (int i = 0; i < 7; ++i)
		ss >> record[i];

	// ��� ��ü�� ������.
	out.PutRecord(record);
}
