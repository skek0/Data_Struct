#include <iostream>

using namespace std;
#define SIZE 6

template<typename KEY, typename VALUE>
class HashTable
{
	struct Node
	{
		KEY key;
		VALUE value;
		Node* next;
	};
	struct Bucket
	{
		int count;
		Node* head;
	};
	Bucket bucket[SIZE];
public:
	HashTable()
	{
		for (int i = 0; i < SIZE; i++)
		{
			bucket[i].count = 0;
			bucket[i].head = nullptr;
		}
	}

	template<typename T>
	int HashFunction(T key)
	{
		return (int)key % SIZE;
	}
	template<>
	int HashFunction(std::string key)
	{
		int sum = 0;
		for (int i = 0; i < key.length(); i++)
		{
			sum += key[i];
		}
		return sum % SIZE;
	}
	Node* CreateNode(KEY key, VALUE value)
	{
		Node* newNode = new Node;
		newNode->key = key;
		newNode->value = value;
		newNode->next = nullptr;

		return newNode;
	}
	void Insert(KEY key, VALUE value)
	{
		int _key = HashFunction(key);
		Node* newNode = CreateNode(key, value);

		if (bucket[_key].head != nullptr)
		{
			newNode->next = bucket[_key].head;
		}
		bucket[_key].head = newNode;
		bucket[_key].count++;
	}
	void Print()
	{
		Node* currentNode;
		for (int i = 0; i < SIZE; i++)
		{
			currentNode = bucket[i].head;

			cout <<	"[" << i << "]" ;

			while (currentNode != nullptr)
			{
				cout << currentNode->key << " " << currentNode->value;
				currentNode = currentNode->next;
				if (currentNode != nullptr) cout << "->";
			}
			cout << endl;
		}
	}
	void Remove(KEY key)
	{
		int _key = HashFunction(key);
		if (bucket[_key].head != nullptr)
		{
			Node* currentNode = bucket[_key].head;
			Node* previousNode = nullptr;

			while (currentNode->key != key)
			{
				previousNode = currentNode;
				currentNode = currentNode->next;
				if (currentNode == nullptr)
				{
					cout << "KEY NOT FOUND" << endl;
					return;
				}
			}
			previousNode->next = currentNode->next;
			currentNode->next = nullptr;
			delete currentNode;
			bucket[_key].count--;
		}
		else //bucket[HashedKey] == nullptr)
		{
			cout << "KEY NOT FOUND" << endl;
			return;
		}
	}

	~HashTable()
	{
		Node* deleteNode;
		Node* nextNode;
		for (int i = 0; i < SIZE; i++)
		{
			if (bucket[i].head != nullptr)
			{
				deleteNode = bucket[i].head;
				nextNode = bucket[i].head;

				while(nextNode != nullptr)
				{
					nextNode = nextNode->next;
					delete deleteNode;
					deleteNode = nextNode;
				}
			}
		}
	}
};

int main()
{
	HashTable<int, std::string> table;

	table.Insert(10, "ten");
	table.Insert(20, "twenty");
	table.Insert(30, "thirty");
	table.Insert(40, "forty");

	table.Print();

	table.Remove(2);
	table.Remove(20);
	table.Remove(20);

	table.Print();

	return 0;
}