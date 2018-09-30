#pragma once

class MyException
{
public:
	const void* sender; // 예외를 던진 객체의 주소
	const char* description; // 예외에 대한 설명 // 오류메시지가 넘어온다
	int info; // 부가 정보 // index의 값이 넘어온다

	MyException(const void* sender, const char* description, int info)
	{
		this->sender = sender;
		this->description = description;
		this->info = info;
	}
};

// MyException의 자식 클래스
// 다른 종류의 예외들을 만들수있다
// 인덱스와 관련된 예외
class OutOfRangeException :public MyException
{
public:
	OutOfRangeException(const void* sender, int index)
		:MyException(sender, "Out of Range!!", index)
	{
	}
};

// 메모리와 관련된 예외
class MemoryException :public MyException
{
public:
	MemoryException(const void* sender, int bytes)
		:MyException(sender, "Out of Memory!!", bytes)
	{
	}
};