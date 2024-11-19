#include <iostream>
#define SIZE 10

using namespace std;

template<typename T>
class Stack
{
private:
	T container[SIZE];
	int top;

public:
	Stack()
	{
		top = -1;

		for (int i = 0; i < SIZE; i++)
		{
			container[i] = 0;
		}
	}
};

int main()
{
	Stack<int> stack;

	return 0;
}