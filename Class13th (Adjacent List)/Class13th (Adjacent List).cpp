#include <iostream>

using namespace std;
#define SIZE 10

template<typename T>
class AdjacentList
{
private:
	struct Node
	{
		T data;
		Node* next;

		Node(T data, Node* link = nullptr)
		{
			this->data = data;
			next = link;
		}
	};
	int count;
	T vertexes[SIZE];
	Node* list[SIZE];
public:
	AdjacentList()
	{
		count = 0;

		for (int i = 0; i < SIZE; i++)
		{
			list[i] = NULL;
			vertexes[i] = NULL;
		}
	}

	void Insert(T data)
	{
		if (count < SIZE)
		{
			vertexes[count++] = data;
		}
		else
		{
			cout << "Adjacent List FULL!" << endl;
		}
	}
	void Connect(int u, int v)
	{
		if (count <= 0)
		{
			cout << "Adjacent List is Empty" << endl;
		}
		if (u < SIZE && v < SIZE)
		{
			list[u] = new Node(vertexes[v], list[u]);
			list[v] = new Node(vertexes[u], list[v]);
		}
		else
		{
			cout << "Index out of range!" << endl;
		}
	}
	void Print()
	{
		for (int i = 0; i < count; i++)
		{
			cout << vertexes[i] << " : ";
			Node* currentNode = list[i];
			while (currentNode != nullptr)
			{
				cout << currentNode->data << " ";
				currentNode = currentNode->next;
			}
			cout << endl;
		}
	}

	~AdjacentList()
	{
		for (int i = 0; i < SIZE; i++)
		{
			if (list[i] != nullptr)
			{
				delete[] list[i];
			}
		}
	}
};

int main()
{
	AdjacentList<char> ajList;

	ajList.Insert('A');
	ajList.Insert('B');
	ajList.Insert('C');
	ajList.Insert('D');

	ajList.Connect(0, 1);
	ajList.Connect(1, 2);
	ajList.Connect(2, 3);
	ajList.Connect(1, 3);

	ajList.Print();

	return 0;
}