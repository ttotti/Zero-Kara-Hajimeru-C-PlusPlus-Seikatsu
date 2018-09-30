#include "List.h"

// 노드의 다음 노드를 반환한다
// 반환값 : 다음 노드
Node* Node::GetNext() const
{
	return next;
}

// 노드의 이전 노드를 반환한다
// 반환값 : 이전 노드
Node* Node::GetPrev() const
{
	return prev;
}

// 노드에 보관된 데이터를 반환한다
// 반환값 : 보관된 데이터
void* Node::GetData() const
{
	return data;
}

// 링크드 리스트의 생성자
// fnDelete : 노드의 데이터 제거시 호출할 함수의 주소
// deleteData : true면 노드를 제거할 때 데이터도 제거한다
List::List(FN_DELETE fnDelete, bool deleteData)
{
	// 인자를 보관한다
	this->fnDel = fnDelete;
	this->deleteData = deleteData;

	// 헤드 노드를 만들고 초기화한다
	head = new Node;
	head->prev = head;
	head->next = head;
	head->data = 0;
}

// 링크드 리스트의 소멸자
List::~List()
{
	// 모든 노드를 제거한다
	RemoveAll();

	// 헤드 노드를 제거한다
	delete head;
	head = 0;
}

// 리스트의 모든 노드를 제거한다
// 리스트의 모든 노드와 데이터도 제거한다
void List::RemoveAll()
{
	// 헤드 노드의 다음 노드부터 지운다
	// 이렇게 하면 RemoveAll() 함수를 호출한 후에도 List 객체를 다시 사용할 수 있다
	Node* current = head->next;

	while (current != head)
	{
		// 현재 노드를 지울 것이므로
		// 다음 노드를 구해둔다
		Node* next = current->next;

		// 현재 노드의 데이터를 제거한다
		if (deleteData)
		{
			if (fnDel)
				(*fnDel)(current->data);
			else
				delete current->data;
		}

		// 현재 노드를 제거한다
		delete current;

		// current가 다음 노드를 가리키게 한다
		current = next;
	}

	// 헤드 노드를 초기화 한다
	head->next = head;
	head->prev = head;
}

// 첫번째 노드를 구한다
// 반환값 : 리스트의 첫번째 노드
Node * List::GetHead() const
{
	// 헤드 노드를 반환한다
	return head;
}

// 마지막 노드를 구한다
// 반환값 : 리스트의 마지막 노드
Node * List::GetTail() const
{
	// 헤드 노드의 이전 노드를 반환한다
	// 헤드 노드 자기 자신일 수도 있다
	return head->prev;
}

// 새로운 노드를 추가한다
// node : 이 노드 뒤에 새 노드가 추가된다
// data : 새 노드의 데이터
void List::InsertNodeAfter(Node * node, void * data)
{
	// 삽입되려는 곳의 앞, 뒤 노드를 구해놓으면
	// 읽기 쉬운 소스 코드를 만들 수 있다
	Node* before = node;
	Node* after = node->next;

	// 새 노드를 만들고 초기화 한다
	Node* newNode = new Node;
	newNode->data = data;
	newNode->next = after;
	newNode->prev = before;

	// node의 뒤에 있던 노드가 새 노드를 가리키도록 만든다
	after->prev = newNode;

	// 매개변수 node가 새 노드를 가리키도록 만든다
	before->next = newNode;
}

// 노드를 제거한다
// node : 제거할 노드
void List::RemoveNode(Node * node)
{
	// node의 앞, 뒤 노드를 구해놓으면
	// 앍기 쉬운 소스 코드를 만들 수 있다
	Node* before = node->prev;
	Node* after = node->next;

	// node의 이전 노드와 다음 노드를 연결해준다
	before->next = after;
	after->prev = before;

	// 현재 노드의 데이터를 제거한다
	if (deleteData)
	{
		if (fnDel)
			(*fnDel)(node->data);
		else
			delete node->data;
	}

	// 현재 노드를 제거한다
	delete node;
}


