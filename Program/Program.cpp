#include <iostream>
#define SIZE 5

using namespace std;

template<typename T>
class CircularQueue
{
private:
	int size;
	int front;
	int rear;
	T container[SIZE];

public:
	CircularQueue()
	{
		size = 0;
		front = SIZE - 1;
		rear = SIZE - 1;

		for (int i = 0; i < SIZE; i++)
		{
			container[i] = NULL;
		}
	}
	bool IsEmpty()
	{
		if (front == rear)
		{
			return true;
		}
		return false;
	}
	void Push(T data)
	{
		if (front != (rear + 1) % SIZE)
		{
			rear = (rear + 1) % SIZE;
			container[rear] = data;
			size++;
		}
		else //front-rear == 1
		{
			cout << "CIRCLEQUEUE FULL!" << endl;
		}
	}
	void Pop()
	{
		if (!IsEmpty())
		{
			front = ++front % SIZE;
		}
		else
		{
			cout << "CIRCLEQUEUE EMPTY!" << endl;
		}
	}
	int& Size()
	{
		return size;
	}
	T& Front()
	{
		return container[(front + 1) % SIZE];
	}
};

int main()
{
	CircularQueue<char> circleQueue;

	circleQueue.Push('A');
	circleQueue.Push('B');
	circleQueue.Push('C');
	circleQueue.Push('D');
	circleQueue.Pop();
	circleQueue.Pop();
	circleQueue.Pop();
	circleQueue.Pop();
	circleQueue.Push('E');
	circleQueue.Push('F');
	circleQueue.Push('G');
	circleQueue.Push('H');

	while (!circleQueue.IsEmpty())
	{
		cout << circleQueue.Front() << endl;
		circleQueue.Pop();
	}

	return 0;
}