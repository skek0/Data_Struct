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
		if (front < rear)
		{
			container[front++] = NULL;
			size--;
		}
		else
		{
			cout << "NO DATA" << endl;
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

	linearQueue.Pop();

	return 0;
}