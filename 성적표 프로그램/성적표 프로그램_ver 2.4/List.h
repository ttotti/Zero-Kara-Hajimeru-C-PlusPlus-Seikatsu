#pragma once

// 데이터 제거를 위한 함수의 포인터
// 노드의 데이터 해제용 함수를 보관하기 위한 함수의 포인터 타입을 정의한다
typedef void(*FN_DELETE)(void*);

// 하나의 데이터를 보관할 구조체
struct Node
{
	// 이중 링크드 리스트 앞과 뒤 둘다 가리키고 있다 // 단일 링크드 리스트 앞쪽만 가리키고 있다 // 환형 링크드 리스트 head 가 마지막 노드를 가리키고 있다(시작과 끝의 개념이 사라진다)
	Node* prev; // 뒤쪽을 가리키고 있다
	Node* next; // 앞쪽을 가리키고 있다

	// Student std; // Student 변수 이렇게 해도 되지만 나중에 리스트소스를 재사용이 불가하다
	void* data; // 타입에 상관없이 데이터를 받을수 있다 // 나중에 리스트소스를 재사용할때 용이하다
};

// 전체 리스트를 관리하는 구조체
struct List
{
	Node* head;
	FN_DELETE fnDel; // 데이터 제거 시 호출할 함수
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