#ifndef LIST_H
#define LIST_H

// 하나의 데이터를 보관할 클래스
class Node
{
	// List 클래스에서 모든 멤버에 접근할 수 있게 만든다
	friend class List;

	// Node 클래스의 멤버 변수 private로 설정했다
	// 즉 이 클래스 이외의 외부에서 이 멤버의 값을 바꿀수없다
	// 다만 List 클래스는 Node 클래스의 친구기 때문에 미 멤버들의 값을 바꿀 수 있다
private:
	Node* prev;
	Node* next;
	void* data;

public:
	Node* GetNext() const;
	Node* GetPrev() const;
	void* GetData() const;
};

// 전체 리스트를 관리하는 클래스
class List
{
public:
	// 데이터 제거를 위한 함수의 포인터
	// List 클래스와 관련된 것이므로 클래스의 정의에 포함하는 것이 좋다
	typedef void(*FN_DELETE)(void*);

public:
	List(FN_DELETE fnDelete = 0, bool deleteData = true);
	~List();

	void InsertNodeAfter(Node* node, void* data);
	void RemoveNode(Node* node);
	Node* GetHead() const;
	Node* GetTail() const;

	void RemoveAll();

private:
	Node* head; // 헤드(더미)노드
	bool deleteData; // 리스트 , 노드 제거 시 데이터 제거 여부
	FN_DELETE fnDel; // 더이터 제거 시 호출할 함수
};

#endif // !LIST_H