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
			bucket[_key].head = newNode;
		}
		else // bucket[_key].head == nullptr
		{
			bucket[_key].head = newNode;
		}
		bucket[_key].count++;
	}
};

int main()
{
	HashTable<int, int> table;

	table.Insert(3, 10);
	table.Insert(3, 20);
	table.Insert(3, 30);

	return 0;
}