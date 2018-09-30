#pragma once

// ������ ���Ÿ� ���� �Լ��� ������
// ����� ������ ������ �Լ��� �����ϱ� ���� �Լ��� ������ Ÿ���� �����Ѵ�
typedef void(*FN_DELETE)(void*);

// �ϳ��� �����͸� ������ ����ü
struct Node
{
	// ���� ��ũ�� ����Ʈ �հ� �� �Ѵ� ����Ű�� �ִ� // ���� ��ũ�� ����Ʈ ���ʸ� ����Ű�� �ִ� // ȯ�� ��ũ�� ����Ʈ head �� ������ ��带 ����Ű�� �ִ�(���۰� ���� ������ �������)
	Node* prev; // ������ ����Ű�� �ִ�
	Node* next; // ������ ����Ű�� �ִ�

	// Student std; // Student ���� �̷��� �ص� ������ ���߿� ����Ʈ�ҽ��� ������ �Ұ��ϴ�
	void* data; // Ÿ�Կ� ������� �����͸� ������ �ִ� // ���߿� ����Ʈ�ҽ��� �����Ҷ� �����ϴ�
};

// ��ü ����Ʈ�� �����ϴ� ����ü
struct List
{
	Node* head;
	FN_DELETE fnDel; // ������ ���� �� ȣ���� �Լ�
};

Node* GetTail(List* list);
Node* GetNext(Node* node);
Node* GetPrev(Node* node);
void* GetData(Node* node);

List* CreateList(FN_DELETE);
void InsertNodeAfter(Node* node, void* data);
void RemoveNode(Node* node, bool deleteData);
//void ShowNames(List* students);
void RemoveList(List* list, bool deleteData);