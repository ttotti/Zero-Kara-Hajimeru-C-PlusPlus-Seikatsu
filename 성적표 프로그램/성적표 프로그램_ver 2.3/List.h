#pragma once

struct Node
{
	// 이중 링크드 리스트 앞과 뒤 둘다 가리키고 있다 // 단일 링크드 리스트 앞쪽만 가리키고 있다 // 환형 링크드 리스트 head 가 마지막 노드를 가리키고 있다(시작과 끝의 개념이 사라진다)
	Node* prev; // 뒤쪽을 가리키고 있다
	Node* next; // 앞쪽을 가리키고 있다

	// Student std; // Student 변수 이렇게 해도 되지만 나중에 리스트소스를 재사용이 불가하다
	void* data; // 타입에 상관없이 데이터를 받을수 있다 // 나중에 리스트소스를 재사용할때 용이하다
};

struct List
{
	Node* head;
};

Node* GetTail(List* list);
Node* GetNext(Node* node);
Node* GetPrev(Node* node);
void* GetData(Node* node);

List* CreateList();
void InsertNodeAfter(Node* node, void* data);
void RemoveNode(Node* node, bool deleteData);
void ShowNames(List* students);
void RemoveList(List* list, bool deleteData);