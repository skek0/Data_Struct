#include <iostream>

using namespace std;
#define SIZE 8

template<typename T>
class Heap
{
private:
	int index;
	T container[SIZE];
public:
	Heap()
	{
		index = 0;
		for (int i = 0; i < SIZE; i++)
		{
			container[i] = 0;
		}
	}
	void Insert(T data)
	{
		if (index >= SIZE - 1)
		{
			cout << "Heap Full!" << endl;
			return;
		}
		container[++index] = data;
		
		int child = index;
		int parent = index / 2;
		while (parent >= 1)
		{
			if (container[child] > container[parent])
			{
				std::swap(container[child], container[parent]);
				child = parent;
				parent = child / 2;
			}
			else break;
		}
	}
	T Remove()
	{
		T result = container[1];

		container[1] = container[index];
		container[index--] = NULL;

		

		return result;
	}

	void Print()
	{
		for (int i = 1; i <= index; i++)
		{
			cout << container[i] << " ";
		}
	}
};

int main()
{
	Heap<int> heap;

	heap.Insert(5);
	heap.Insert(7);
	heap.Insert(9);
	heap.Insert(15);

	heap.Print();
	return 0;
}