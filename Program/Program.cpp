#include <iostream>

using namespace std;

template<typename T>
class SingleLinkedList
{
	struct Node
	{
		T data;
		Node* next;
	~Node()
	{
		cout << "deleted" << endl;		//오류
	}
	};
	int size;
	Node* head;

public:
	SingleLinkedList()
	{
		size = 0;
		head = nullptr;
	}
	void PushFront(T data)
	{
		if (head != nullptr) 
		{
			Node* newNode = new Node;
			newNode->data = data;
			newNode->next = head;
			head = newNode;
			size++;
		}
		else
		{
			head = new Node;
			head->data = data;
			head->next = nullptr;
			size++;
		}
	}

	~SingleLinkedList()
	{
		Node* curr = head;
		Node* prev = new Node;
		while (curr->next != nullptr)
		{
			prev = curr;
			curr = curr->next;
			delete prev;
		}
		delete head;
	}
};

int main()
{
	SingleLinkedList<int> singleLinkedList;
	singleLinkedList.PushFront(10);
	singleLinkedList.PushFront(20);
	

	return 0;
}