#include <iostream>
#define SIZE 10

using namespace std;

template<typename T>
class Stack
{
private:
	int size;
	T container[SIZE];
	int top;

public:
	Stack()
	{
		top = -1;

		for (int i = 0; i < SIZE; i++)
		{
			container[i] = NULL;
		}
	}
	void Push(T data)
	{
		if (top < SIZE - 1)
		{
			//top++;
			container[++top] = data;
		}
		else
		{
			cout << "Stack Overflow" << endl;
		}
	}
	bool IsEmpty()
	{
		if (top > -1)
		{
			return false;
		}
		return true;
	}
	void Pop()
	{
		if (!IsEmpty())
		{
			//container[top] = NULL;
			top--;
		}
		else
		{
			cout << "Stack is Empty" << endl;
		}
	}
	T& Top()
	{
		return container[top];
	}
	int Size()
	{
		size = top + 1;
		return size;
	}
};

int main()
{
	Stack<int> stack;

	stack.Push(10);
	stack.Push(20);
	stack.Push(30);
	stack.Push(40);
	stack.Push(50);

	for (int i = stack.Size(); i > 0; i--)
	{
		cout << stack.Top() << endl;

		stack.Pop();
	}

	cout << "Size : " << stack.Size() << endl;
	return 0;
}