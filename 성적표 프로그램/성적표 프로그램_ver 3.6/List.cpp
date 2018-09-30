#include "List.h"
#include <cstdlib>
#include <stdexcept> // invalid_argument 클래스를 사용하기 위한 헤더파일 네임스페이스 std

using namespace std;

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
	// 요구사항 헤더: <stdexcept>, 네임 스페이스: std
	// node가 NULL인 경우 invalid_argument 예외를 던진다 이 예외 또한 C++에서 제공하는 예외 클래스 중 하나로
	// 잘못된 인자를 상징하는 예외 클래스이다 이 예외 클래스 또한 exception 클래스의 자식이기 때문에 main() 함수의 catch 에서 받아 처리한다
	// List 클래스의 멤버 함수로 넘어온 인자가 올바른 것인지 검사하는 코드
	// List 클래스와 같이 포인터를 많이 사용하는 코드에는 문제가 발생하기 쉬우므로 인자를 엄격하게 검사하는 것이 많은 도움이 된다

	// 꼭 NULL이 아니더라도 잘못된 포인터일수 있다 예를 들어 이미 해제된 곳을 가리키는 포인터일 수도 있다
	// 이런 경우라면 이 예외 처리 코드는 아무런 도움이 되지 않는다 하지만 그런경우가 많은 것은 아니다
	// 그리고 C++에서 제공하는 기능만 사용해서 NULL이 아니면서 잘못된 포인터를 구분해내기가 힘들다
	// 이럴때는 운영체제가 제공하는 방법을 사용하면 모든 잘못된 상황을 판별해내는 것이 가능하다
	// 자세한건 윈도우즈 프로그래밍 Win32 SEH에 대해 공부하면 된다 혹은 IsBadWritePtr()과 같은 API를 살펴보는 것도 도움이 된다
	if (NULL == node)
	{
		// 문자열 끝의 377은 오류메시지만 보고 어디서 어떤 문제가 발생했는지를 그냥 숫자로 표현한것이다 별명같은 느낌?
		// 이 경우에는 377은 List::InsertNodeAfter() 에서 발생한 예외 라고 같이 프로젝트를 만드는 사람끼리 약속을 하는것이다
		// 그러면 오류가 나는 숫자코드만 보고 어떤문제가 어디서 발생했는지 쉽게 알 수 있다
		throw invalid_argument("알 수 없는 오류가 있습니다. (377)");
	}

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
	if (NULL == node)
	{
		throw invalid_argument("알 수 없는 오류가 있습니다. (377)");
	}

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


