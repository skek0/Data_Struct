#include <iostream>

using namespace std;

template<typename T>
class DoubleLinkedList
{
private:
	struct Node
	{
		T data;
		Node* prev;
		Node* next;
		~Node()
		{
			cout << "deleted" << endl;
		}
	};
	int size;
	Node* head;
	Node* tail;

public:
	DoubleLinkedList()
	{
		size = 0;
		head = nullptr;
		tail = nullptr;
	}
	void PushFront(T data)
	{
		Node* newNode = new Node;
		newNode->data = data;
		newNode->prev = nullptr;
		newNode->next = nullptr;

		if (head != nullptr)
		{
			newNode->next = head;
			head->prev = newNode;

			head = head->prev;
		}
		else
		{
			head = newNode;
			tail = newNode;
		}
	}
	void PopFront()
	{
		if (head != nullptr)
		{
			Node* deleteNode = head;
			if (head != tail)
			{
				head = head->next;
				head->prev = nullptr;
			}
			else
			{
				head = nullptr;
				tail = nullptr;
			}
			delete deleteNode;

			size--;
		}
		else
		{
			cout << "NO DATA" << endl;
		}
	}

	void ShowByFront()
	{
		Node* temp = head;
		while (temp != nullptr)
		{
			cout << temp->data << endl;
			temp = temp->next;
		}
	}
	void ShowByBack()
	{
		Node* temp = tail;
		while (temp != nullptr)
		{
			cout << temp->data << endl;
			temp = temp->prev;
		}
	}
};

int main()
{
	DoubleLinkedList<int> doubleLinkedlist;

	doubleLinkedlist.PushFront(10);
	doubleLinkedlist.PushFront(20);

	doubleLinkedlist.PopFront();
	doubleLinkedlist.PopFront();
	
	return 0;
}