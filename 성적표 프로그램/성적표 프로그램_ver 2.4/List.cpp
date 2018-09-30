#include "List.h"
#include "students.h"
#include <iostream>

using namespace std;

// 링크드 리스트의 생성 및 초기화
// 반환값: 새로운 링크드 리스트의 포인터
List * CreateList(FN_DELETE fnDelete)
{
	Node* head = new Node; // 헤드 노드를 만들고 초기화 한다
	head->prev = head;
	head->next = head;
	head->data = 0;

	List* list = new List; // List 구조체를 만들고 초기화 한다
	list->head = head;

	// 데이터 제거 함수의 주소를 보관한다
	list->fnDel = fnDelete;

	return list;
}

// 새로운 노드를 추가한다
void InsertNodeAfter(Node* node, void* data) // 새 노드가 끝에 삽입되건 앞에 삽입되건 중간에 삽입되건 상관없이 쓸수 있다 (환형구조)
{
	// 삽입되려는 곳의 앞, 뒤 노드를 구해놓으면 읽기 쉬운 소스를 만들 수 있다
	Node* before = node; // 뒤 노드
	Node* after = node->next; // 앞 노드

	// 새 노드를 만들고 초기화 한다
	Node* newNode = new Node; // 노드를 동적으로 생성하고 인자로 넘어온 data값을 보관한다
	newNode->data = data;
	newNode->next = after; // 앞 노드
	newNode->prev = before; // 뒤 노드

	// node의 앞, 뒤에 있던 노드가 새 노드를 가리키게 만든다
	after->prev = newNode;
	before->next = newNode;
}

// 노드를 제거한다
void RemoveNode(Node* node, bool deleteData)
{
	// node의 앞, 뒤 노드를 구해놓으면 읽기 쉬운 소스가 된다
	Node* before = node->prev;
	Node* after = node->next;

	// node의 이전노드와 다음 노드를 연결해준다
	before->next = after; // 이전 노드와 다음 노드를 연결하면 자연스럽게 중간노드가 떨어져 나온다
	after->prev = before;

	// node의 데이터와 node 자신을 제거한다
	if (deleteData) // deleteData 인자값이 true라면 노드가 보관하는 정보도 제거한다
		delete node->data;

	delete node;
}

// 노드를 탐색한다
//void ShowNames(List* students)
//{
//	// 헤드 노드의 다음 노드부터 시작한다
//	Node* current = students->head->next;
//
//	while (current != students->head) // current가 헤드노드를 가리키지 않을 동안 즉 한바퀴를 돈다
//	{
//		// 현재 노드의 데이터를 꺼내온다
//		const Student* std = (Student*)current->data; // void* 타입으로 보관되어 있으므로 student* 타입으로 형변환해야 한다
//
//		// 해당 학생의 이름을 출력한다
//		cout << std->name << endl;
//
//		// 다음 노드를 가리킨다
//		current = current->next;
//	}
//}

// 모든 리스트를 제거한다
void RemoveList(List* list, bool deleteData)
{
	// current가 head노드를 가리키게 한다 head노드 부터 제거할 것이다
	Node* current = list->head;

	do
	{
		Node* next = current->next; // 현재 노드를 제거하면 current->next 처럼 사용할 수 없으므로 미리 다음을 가리킨다

		if (deleteData) // 제거한다
		{
			// 보관된 함수의 주소가 있는지 확인한다
			// list->fnDel에 NULL이 보관되어 있는 상황에서 95줄 처럼 함수를 호출하면 프로그램이 비정상 종료된다
			if (list->fnDel)
				// 데이터 해제 함수가 있는 경우에는 함수를 호출한다
				// Node 구조체의 data 멤버를 인자로 넘긴다
				(*list->fnDel)(current->data);
			else
				delete current->data;
		}
		delete current;

		// 현재 노드를 갱신한다
		current = next;
	} 
	while (current != list->head); // 일단 헤드 노드를 제거한 다음에 조건을 비교해야 하므로 do while을 사용했다
	// list->head가 가리키는 곳의 메모리는 해제된 상대이지만 list->head 처럼 그곳의 주소 값만 사용하는 것은 상관 없다

	// 리스트를 제거한다
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

