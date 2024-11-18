#include <iostream>

using namespace std;

template<typename T>
class CircleLinkedList
{
private:
	int size;
	struct Node
	{
		T data;
		Node* next;
	};
	Node* head;

public:
	CircleLinkedList()
	{
		head = nullptr;
		size = 0;
	}
	void PushBack(T data)
	{
		Node* newNode = new Node;
		newNode->data = data;

		if (head != nullptr)
		{
			newNode->next = head->next;		//newNode를 head로 만들기 위해서 next부터 이어받음
			head->next = newNode;
			head = head->next;
		}
		else
		{
			head = newNode;
			head->next = head;
		}
		size++;
	}
	void PushFront(T data)
	{
		Node* newNode = new Node;
		newNode->data = data;
		if (head != nullptr)
		{
			newNode->next = head->next;
			head->next = newNode;
		}
		else
		{
			head = newNode;
			head->next = head;
		}
		size++;
	}

	void Show()
	{
		if (head != nullptr)
		{
			Node* temp = head->next;
			do
			{
				cout << temp->data << " ";
				temp = temp->next;
			} while (temp != head->next);

			cout << endl;
		}
		else
		{
			cout << "NO DATA" << endl;
		}
	}
};

int main()
{
	CircleLinkedList<int> circlelist;
	
	circlelist.PushBack(10);
	circlelist.PushBack(20);
	circlelist.PushBack(30);
	circlelist.PushBack(40);
	circlelist.PushFront(50);
	circlelist.PushFront(60);

	circlelist.Show();

	return 0;
}