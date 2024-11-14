#include <iostream>

using namespace std;

template<typename T>
class SingleLinkedList
{
private:
	struct Node
	{
		T data;
		Node* next;
		~Node()
		{
			cout << "deleted" << endl;
		}
	};

	int size;
	Node* head;
	//ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ
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
	void PushBack(T data)
	{
		if (head != nullptr)
		{
			Node* newNode = new Node;
			newNode->data = data;
			newNode->next = nullptr;

			Node* temp = head;
			while (temp->next != nullptr)
			{
				temp = temp->next;
			}

			temp->next = newNode;

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
	void PopFront()
	{
		if (head != nullptr)
		{
			Node* deleteNode = head;
			head = head->next;
			delete deleteNode;
			size--;
		}
		else
		{
			cout << "NO DATA" << endl;
		}
	}
	void PopBack()
	{
		if (head != nullptr)
		{
			Node* deleteNode = head;
			Node* prev = nullptr;

			if (head->next != nullptr)
			{
				while (deleteNode->next != nullptr)
				{
					prev = deleteNode;
					deleteNode = deleteNode->next;
				}
				prev->next = nullptr;
				delete deleteNode;
			}
			else
			{
				/* Node* deleteNode = head;
				head = head->next;
				delete deleteNode;*/
				head = deleteNode->next;
				delete deleteNode;
			}
			size--;
		}
		else
		{
			cout << "NO DATA" << endl;
		}
	}
	void Show()
	{
		Node* temp = head;
		while (temp != nullptr)
		{
			cout << temp->data << " ";
			temp = temp->next;
		}
		cout << endl;
	}
	~SingleLinkedList()
	{
		while (head != nullptr)
		{
			Popback();
		}

		/*
		Node* deleteNode = head;

		while (head != nullptr)
		{
			head = head->next;
			delete deleteNode;
			deleteNode = head;
		}
		*/
	}
};

int main()
{
	SingleLinkedList<int> singleLinkedList;

	singleLinkedList.PushFront(10);
	singleLinkedList.PushFront(20);

	singleLinkedList.PushBack(5);
	singleLinkedList.PushBack(0);

	singleLinkedList.PopBack();

	singleLinkedList.Show();

	return 0;
}