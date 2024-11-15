﻿#include <iostream>

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

		size++;
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
	void PushBack(T data)
	{
		Node* newNode = new Node;
		newNode->data = data;
		newNode->prev = nullptr;
		newNode->next = nullptr;

		if (tail != nullptr)
		{
			tail->next = newNode;
			newNode->prev = tail;
			tail = newNode; // == tail = tail->next;
		}
		else
		{
			head = newNode;
			tail = newNode;
		}
		size++;
	}
	void PopBack()
	{
		if (tail != nullptr)
		{
			Node* deleteNode = tail;

			if (tail->prev != nullptr)
			{
				tail = tail->prev;
				tail->next = nullptr;
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

	void Show()
	{
		Node* temp = head;
		while (temp != nullptr)
		{
			cout << temp->data << endl;
			temp = temp->next;
		}
	}
	int& Size()
	{
		return size;
	}

	~DoubleLinkedList()
	{
		while (head != nullptr)PopBack();
	}
};

int main()
{
	DoubleLinkedList<int> doubleLinkedlist;

	doubleLinkedlist.PushFront(10);
	doubleLinkedlist.PushFront(20);
	doubleLinkedlist.PushFront(30);
	doubleLinkedlist.PushBack(40);
	doubleLinkedlist.PushBack(50);
	doubleLinkedlist.PushBack(60);

	doubleLinkedlist.PopFront();
	doubleLinkedlist.PopBack();

	doubleLinkedlist.Show();
	cout << doubleLinkedlist.Size() << endl;

	return 0;
}