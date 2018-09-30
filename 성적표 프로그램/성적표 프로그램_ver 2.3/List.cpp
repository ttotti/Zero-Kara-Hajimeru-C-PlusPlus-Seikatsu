#include "List.h"
#include "students.h"
#include <iostream>

using namespace std;

// ��ũ�� ����Ʈ�� ���� �� �ʱ�ȭ
// ��ȯ��: ���ο� ��ũ�� ����Ʈ�� ������
List * CreateList()
{
	Node* head = new Node; // ��� ��带 ����� �ʱ�ȭ �Ѵ�
	head->prev = head;
	head->next = head;
	head->data = 0;

	List* list = new List; // List ����ü�� ����� �ʱ�ȭ �Ѵ�
	list->head = head;

	return list;
}

// ���ο� ��带 �߰��Ѵ�
void InsertNodeAfter(Node* node, void* data) // �� ��尡 ���� ���Եǰ� �տ� ���Եǰ� �߰��� ���Եǰ� ������� ���� �ִ� (ȯ������)
{
	// ���ԵǷ��� ���� ��, �� ��带 ���س����� �б� ���� �ҽ��� ���� �� �ִ�
	Node* before = node; // �� ���
	Node* after = node->next; // �� ���

	// �� ��带 ����� �ʱ�ȭ �Ѵ�
	Node* newNode = new Node; // ��带 �������� �����ϰ� ���ڷ� �Ѿ�� data���� �����Ѵ�
	newNode->data = data;
	newNode->next = after; // �� ���
	newNode->prev = before; // �� ���

	// node�� ��, �ڿ� �ִ� ��尡 �� ��带 ����Ű�� �����
	after->prev = newNode;
	before->next = newNode;
}

// ��带 �����Ѵ�
void RemoveNode(Node* node, bool deleteData)
{
	// node�� ��, �� ��带 ���س����� �б� ���� �ҽ��� �ȴ�
	Node* before = node->prev;
	Node* after = node->next;

	// node�� �������� ���� ��带 �������ش�
	before->next = after; // ���� ���� ���� ��带 �����ϸ� �ڿ������� �߰���尡 ������ ���´�
	after->prev = before;

	// node�� �����Ϳ� node �ڽ��� �����Ѵ�
	if (deleteData) // deleteData ���ڰ��� true��� ��尡 �����ϴ� ������ �����Ѵ�
		delete node->data;

	delete node;
}

// ��带 Ž���Ѵ�
//void ShowNames(List* students)
//{
//	// ��� ����� ���� ������ �����Ѵ�
//	Node* current = students->head->next;
//
//	while (current != students->head) // current�� ����带 ����Ű�� ���� ���� �� �ѹ����� ����
//	{
//		// ���� ����� �����͸� �����´�
//		const Student* std = (Student*)current->data; // void* Ÿ������ �����Ǿ� �����Ƿ� student* Ÿ������ ����ȯ�ؾ� �Ѵ�
//
//		// �ش� �л��� �̸��� ����Ѵ�
//		cout << std->name << endl;
//
//		// ���� ��带 ����Ų��
//		current = current->next;
//	}
//}

// ��� ����Ʈ�� �����Ѵ�
void RemoveList(List* list, bool deleteData)
{
	// current�� head��带 ����Ű�� �Ѵ� head��� ���� ������ ���̴�
	Node* current = list->head;

	do
	{
		Node* next = current->next; // ���� ��带 �����ϸ� current->next ó�� ����� �� �����Ƿ� �̸� ������ ����Ų��

		if (deleteData) // �����Ѵ�
			// �� �ڵ尡 �޸� ���� �߻��ϴ� ����
			// delete �������� �ϴ� ���� �ϳ� ��ü�� �˸´� �Ҹ��ڸ� ȣ���ϴ°��̰� , �ٸ� �ϳ��� ��ü�� �����ϴ� �޸� ������ �����ϴ� ���̴�
			// �׷��� current->data �� void* Ÿ���̱� ������ ����Ű�� ���� Student ������ �ִٴ� ����� �𸥴� �׷��� �׳� �ܼ��� �޸� �����̶� �����ϰ� �޸� ������ �����ϴ� ���̴�
			// �װ� �ذ��ϱ� ���� (Student*)current->data ��� �˷��ָ� �Ҹ��ڰ� ȣ��ȴ�
			// ������ �̷��� �ϸ� ��ũ�� ����Ʈ�� ���뼺�� �Ҿ������ (Student Ÿ�� �̿��� �ٸ� Ÿ���� �������� ���Ѵ�)
			delete current->data;
		delete current;

		// ���� ��带 �����Ѵ�
		current = next;
	} while (current != list->head); // �ϴ� ��� ��带 ������ ������ ������ ���ؾ� �ϹǷ� do while�� ����ߴ�
	// list->head�� ����Ű�� ���� �޸𸮴� ������ ��������� list->head ó�� �װ��� �ּ� ���� ����ϴ� ���� ��� ����

	// ����Ʈ�� �����Ѵ�
	delete list;
}

Node* GetTail(List* list)
{
	return list->head->prev;
}

Node* GetNext(Node* node)
{
	return node->next;
}

Node* GetPrev(Node* node)
{
	return node->prev;
}

void* GetData(Node* node)
{
	return node->data;
}

