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
		if (index <= 0)
		{
			cout << "Heap is Empty" << endl;
			exit(1);
		}
		T result = container[1];

		container[1] = container[index];
		container[index--] = NULL;

		int parent = 1;
		while (parent < index)
		{
			if (container[parent] > container[parent * 2] || container[parent] > container[parent * 2 + 1]) break;
			if (container[parent * 2] > container[parent * 2 + 1])
			{
				std::swap(container[parent], container[parent * 2]);
				parent = parent * 2;
			}
			else
			{
				std::swap(container[parent], container[parent * 2 + 1]);
				parent = parent * 2 + 1;
			}
		}
		/*
		while(parent*2 <= index)
		{
			int child = parent * 2;

			if(container[chlid] < container[child + 1])
			{
				child++;
			}
			else
			{
				std::swap(container[parent], container[child]);
				parent = child;
			}
		}
		*/

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
	heap.Insert(11);
	heap.Insert(1);
	heap.Insert(13);

	cout << heap.Remove() << endl;
	cout << heap.Remove() << endl;
	cout << heap.Remove() << endl;
	cout << heap.Remove() << endl;
	cout << heap.Remove() << endl;
	cout << heap.Remove() << endl;
	cout << heap.Remove() << endl;
	/*
	15
	11 13
	5 9 1 7

	13
	11 7
	5 9 1

	11
	9 7
	5 1
	*/

	heap.Print();
	return 0;
}