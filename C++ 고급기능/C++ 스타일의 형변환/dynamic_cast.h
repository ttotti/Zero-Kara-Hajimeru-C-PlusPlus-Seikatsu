#pragma once

class A
{
public:
	// dynamic_cast Ű������ ������ ���� ���� �Լ� ����
	virtual void Func(){}
};

class B :public A
{

};

class C :public B
{

};