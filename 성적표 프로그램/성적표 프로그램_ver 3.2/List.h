#ifndef LIST_H
#define LIST_H

// �ϳ��� �����͸� ������ Ŭ����
class Node
{
	// List Ŭ�������� ��� ����� ������ �� �ְ� �����
	friend class List;

	// Node Ŭ������ ��� ���� private�� �����ߴ�
	// �� �� Ŭ���� �̿��� �ܺο��� �� ����� ���� �ٲܼ�����
	// �ٸ� List Ŭ������ Node Ŭ������ ģ���� ������ �� ������� ���� �ٲ� �� �ִ�
private:
	Node* prev;
	Node* next;
	void* data;

public:
	Node* GetNext() const;
	Node* GetPrev() const;
	void* GetData() const;
};

// ��ü ����Ʈ�� �����ϴ� Ŭ����
class List
{
public:
	// ������ ���Ÿ� ���� �Լ��� ������
	// List Ŭ������ ���õ� ���̹Ƿ� Ŭ������ ���ǿ� �����ϴ� ���� ����
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
	Node* head; // ���(����)���
	bool deleteData; // ����Ʈ , ��� ���� �� ������ ���� ����
	FN_DELETE fnDel; // ������ ���� �� ȣ���� �Լ�
};

#endif // !LIST_H