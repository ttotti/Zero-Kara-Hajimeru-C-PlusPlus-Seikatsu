#include "List.h"
#include <cstdlib>
#include <stdexcept> // invalid_argument Ŭ������ ����ϱ� ���� ������� ���ӽ����̽� std

using namespace std;

// ����� ���� ��带 ��ȯ�Ѵ�
// ��ȯ�� : ���� ���
Node* Node::GetNext() const
{
	return next;
}

// ����� ���� ��带 ��ȯ�Ѵ�
// ��ȯ�� : ���� ���
Node* Node::GetPrev() const
{
	return prev;
}

// ��忡 ������ �����͸� ��ȯ�Ѵ�
// ��ȯ�� : ������ ������
void* Node::GetData() const
{
	return data;
}

// ��ũ�� ����Ʈ�� ������
// fnDelete : ����� ������ ���Ž� ȣ���� �Լ��� �ּ�
// deleteData : true�� ��带 ������ �� �����͵� �����Ѵ�
List::List(FN_DELETE fnDelete, bool deleteData)
{
	// ���ڸ� �����Ѵ�
	this->fnDel = fnDelete;
	this->deleteData = deleteData;

	// ��� ��带 ����� �ʱ�ȭ�Ѵ�
	head = new Node;
	head->prev = head;
	head->next = head;
	head->data = 0;
}

// ��ũ�� ����Ʈ�� �Ҹ���
List::~List()
{
	// ��� ��带 �����Ѵ�
	RemoveAll();

	// ��� ��带 �����Ѵ�
	delete head;
	head = 0;
}

// ����Ʈ�� ��� ��带 �����Ѵ�
// ����Ʈ�� ��� ���� �����͵� �����Ѵ�
void List::RemoveAll()
{
	// ��� ����� ���� ������ �����
	// �̷��� �ϸ� RemoveAll() �Լ��� ȣ���� �Ŀ��� List ��ü�� �ٽ� ����� �� �ִ�
	Node* current = head->next;

	while (current != head)
	{
		// ���� ��带 ���� ���̹Ƿ�
		// ���� ��带 ���صд�
		Node* next = current->next;

		// ���� ����� �����͸� �����Ѵ�
		if (deleteData)
		{
			if (fnDel)
				(*fnDel)(current->data);
			else
				delete current->data;
		}

		// ���� ��带 �����Ѵ�
		delete current;

		// current�� ���� ��带 ����Ű�� �Ѵ�
		current = next;
	}

	// ��� ��带 �ʱ�ȭ �Ѵ�
	head->next = head;
	head->prev = head;
}

// ù��° ��带 ���Ѵ�
// ��ȯ�� : ����Ʈ�� ù��° ���
Node * List::GetHead() const
{
	// ��� ��带 ��ȯ�Ѵ�
	return head;
}

// ������ ��带 ���Ѵ�
// ��ȯ�� : ����Ʈ�� ������ ���
Node * List::GetTail() const
{
	// ��� ����� ���� ��带 ��ȯ�Ѵ�
	// ��� ��� �ڱ� �ڽ��� ���� �ִ�
	return head->prev;
}

// ���ο� ��带 �߰��Ѵ�
// node : �� ��� �ڿ� �� ��尡 �߰��ȴ�
// data : �� ����� ������
void List::InsertNodeAfter(Node * node, void * data)
{
	// �䱸���� ���: <stdexcept>, ���� �����̽�: std
	// node�� NULL�� ��� invalid_argument ���ܸ� ������ �� ���� ���� C++���� �����ϴ� ���� Ŭ���� �� �ϳ���
	// �߸��� ���ڸ� ��¡�ϴ� ���� Ŭ�����̴� �� ���� Ŭ���� ���� exception Ŭ������ �ڽ��̱� ������ main() �Լ��� catch ���� �޾� ó���Ѵ�
	// List Ŭ������ ��� �Լ��� �Ѿ�� ���ڰ� �ùٸ� ������ �˻��ϴ� �ڵ�
	// List Ŭ������ ���� �����͸� ���� ����ϴ� �ڵ忡�� ������ �߻��ϱ� ����Ƿ� ���ڸ� �����ϰ� �˻��ϴ� ���� ���� ������ �ȴ�

	// �� NULL�� �ƴϴ��� �߸��� �������ϼ� �ִ� ���� ��� �̹� ������ ���� ����Ű�� �������� ���� �ִ�
	// �̷� ����� �� ���� ó�� �ڵ�� �ƹ��� ������ ���� �ʴ´� ������ �׷���찡 ���� ���� �ƴϴ�
	// �׸��� C++���� �����ϴ� ��ɸ� ����ؼ� NULL�� �ƴϸ鼭 �߸��� �����͸� �����س��Ⱑ �����
	// �̷����� �ü���� �����ϴ� ����� ����ϸ� ��� �߸��� ��Ȳ�� �Ǻ��س��� ���� �����ϴ�
	// �ڼ��Ѱ� �������� ���α׷��� Win32 SEH�� ���� �����ϸ� �ȴ� Ȥ�� IsBadWritePtr()�� ���� API�� ���캸�� �͵� ������ �ȴ�
	if (NULL == node)
	{
		// ���ڿ� ���� 377�� �����޽����� ���� ��� � ������ �߻��ߴ����� �׳� ���ڷ� ǥ���Ѱ��̴� ������ ����?
		// �� ��쿡�� 377�� List::InsertNodeAfter() ���� �߻��� ���� ��� ���� ������Ʈ�� ����� ������� ����� �ϴ°��̴�
		// �׷��� ������ ���� �����ڵ常 ���� ������� ��� �߻��ߴ��� ���� �� �� �ִ�
		throw invalid_argument("�� �� ���� ������ �ֽ��ϴ�. (377)");
	}

	// ���ԵǷ��� ���� ��, �� ��带 ���س�����
	// �б� ���� �ҽ� �ڵ带 ���� �� �ִ�
	Node* before = node;
	Node* after = node->next;

	// �� ��带 ����� �ʱ�ȭ �Ѵ�
	Node* newNode = new Node;
	newNode->data = data;
	newNode->next = after;
	newNode->prev = before;

	// node�� �ڿ� �ִ� ��尡 �� ��带 ����Ű���� �����
	after->prev = newNode;

	// �Ű����� node�� �� ��带 ����Ű���� �����
	before->next = newNode;
}

// ��带 �����Ѵ�
// node : ������ ���
void List::RemoveNode(Node * node)
{
	if (NULL == node)
	{
		throw invalid_argument("�� �� ���� ������ �ֽ��ϴ�. (377)");
	}

	// node�� ��, �� ��带 ���س�����
	// �̱� ���� �ҽ� �ڵ带 ���� �� �ִ�
	Node* before = node->prev;
	Node* after = node->next;

	// node�� ���� ���� ���� ��带 �������ش�
	before->next = after;
	after->prev = before;

	// ���� ����� �����͸� �����Ѵ�
	if (deleteData)
	{
		if (fnDel)
			(*fnDel)(node->data);
		else
			delete node->data;
	}

	// ���� ��带 �����Ѵ�
	delete node;
}


