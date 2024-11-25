#include <iostream>

using namespace std;

class String
{
private:
	int size;
	char* container;

public:
	String()
	{
		size = 0;
		container = nullptr;
	}

	char* operator = (const char* word)
	{
		/*if (container == nullptr)
		{
			int arraysize = sizeof(word)+1;
			size = arraysize - 1;
			container = new char[arraysize];

			return container;
		}*/
		int arraySize = strlen(word) +1;

		size = strlen(word);

		if(container == nullptr)
		{
			container = new char[arraySize];
			for(int i = 0; i < arraySize; i++)
			{
				container[i] = word[i];
			}
		}
		else
		{
			char* newContainer = new char[arraySize];
			for (int i = 0; i < arraySize; i++)
			{
				newContainer[i] = word[i];
			}
			delete[] container;
			container = newContainer;
		}

		return container;
		
	}
	int& Size()
	{
		return size;
	}
	char operator [ ](const int& index)
	{
		return container[index];
	}

	~String()
	{
		if (container != nullptr) 
		{
			size = 0;
			delete[] container;
		}
	}
};

int main()
{
	String string;
	string = "janna";
	for (int i = 0; i < string.Size(); i++)
	{
		cout << string[i];
	}
	cout << endl;
	string = "Bard";
	for (int i = 0; i < string.Size(); i++)
	{
		cout << string[i];
	}
	cout << endl;

	return 0;
}
