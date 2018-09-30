#include "List.h"
#include "students.h"
#include <iostream>

using namespace std;

// 링크드 리스트의 생성 및 초기화
// 반환값: 새로운 링크드 리스트의 포인터
List * CreateList()
{
	Node* head = new Node; // 헤드 노드를 만들고 초기화 한다
	head->prev = head;
	head->next = head;
	head->data = 0;

	List* list = new List; // List 구조체를 만들고 초기화 한다
	list->head = head;

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
			// 이 코드가 메모리 릭을 발생하는 원인
			// delete 연산자의 하는 일은 하나 객체에 알맞는 소멸자를 호출하는것이고 , 다른 하나는 객체가 차지하는 메모리 공간을 해제하는 것이다
			// 그런데 current->data 는 void* 타입이기 때문에 가리키는 곳이 Student 변수가 있다는 사실을 모른다 그래서 그냥 단순한 메모리 공간이라 생각하고 메모리 공간만 해제하는 것이다
			// 그걸 해결하기 위해 (Student*)current->data 라고 알려주면 소멸자가 호출된다
			// 하지만 이렇게 하면 링크드 리스트의 범용성을 잃어버린다 (Student 타입 이외의 다른 타입을 저장하지 못한다)
			delete current->data;
		delete current;

		// 현재 노드를 갱신한다
		current = next;
	} while (current != list->head); // 일단 헤드 노드를 제거한 다음에 조건을 비교해야 하므로 do while을 사용했다
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

