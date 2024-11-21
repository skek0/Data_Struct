#include <iostream>
#define SIZE 5

using namespace std;

template<typename T>
class LinearQueue
{
private:
	int front;
	int rear;
	int size;
	T container[SIZE];
public:
	LinearQueue()
	{
		front = 0;
		rear = 0;
		size = 0;
		for (int i = 0; i < SIZE; i++)
		{
			container[i] = NULL;
		}
	}
	void Push(T data)
	{
		if (rear < SIZE)
		{
			container[rear++] = data;
			size++;
		}
		else
		{
			cout << "Queue overflow" << endl;
		}
	}
	void Pop()
	{
		if (!Empty())
		{
			container[front++] = NULL;
			size--;
		}
		else
		{
			cout << "NO DATA" << endl;
		}
	}
	bool Empty()
	{
		if (front == rear)
		{
			return true;
		}
		else return false;
	}
	int& Size()
	{
		return size;
	}
	T& Front()
	{
		if (!Empty())
		{
			return container[front];
		}
		else
		{
			cout << "NO DATA TO SHOW" << endl;
			exit(1);
		}
	}
	T& Rear()
	{
		if (!Empty())
		{
			return container[rear-1];
		}
		else
		{
			cout << "NO DATA TO SHOW" << endl;
			exit(1);
		}
	}
};

int main()
{
	LinearQueue<int> linearQueue;

	linearQueue.Push(10);
	linearQueue.Push(20);
	linearQueue.Push(30);
	linearQueue.Push(40);
	linearQueue.Push(50);

	while (linearQueue.Empty() == false)
	{
		cout << linearQueue.Front() << endl;
		linearQueue.Pop();
	}



	return 0;
}