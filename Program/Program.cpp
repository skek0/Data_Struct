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


	return 0;
}