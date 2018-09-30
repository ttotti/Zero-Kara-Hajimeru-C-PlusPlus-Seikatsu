#pragma once

class A
{
public:
	// dynamic_cast 키워드의 구현을 위해 가상 함수 정의
	virtual void Func(){}
};

class B :public A
{

};

class C :public B
{

};