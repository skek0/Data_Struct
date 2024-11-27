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
		int arraySize = strlen(word) + 1;

		size = strlen(word);

		if (container == nullptr)
		{
			container = new char[arraySize];
			for (int i = 0; i < arraySize; i++)
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
	void Append(const char* word)
	{
		int newSize = strlen(word) + strlen(container);
		char* newcontainer = new char[newSize];
		for (int i = 0; i < newSize; i++)
		{
			i < size ?
				newcontainer[i] = container[i] :
				newcontainer[i] = word[i - size];
		}
		size = newSize;
		delete[] container;
		container = newcontainer;
	}
	int Compare(const char* word)
	{
		//for (int i = 0; i < size; i++)
		//{
		//	if (container[i] != word[i])
		//	{
		//		int classString = container[i];
		//		int otherString = word[i];
		//		if (classString > otherString)
		//		{
		//			return 1;
		//		}
		//		else return -1; // classString < otherString
		//	}
		//}
		//if (strlen(word) > size) return -1;
		//return 0;

		int count = 0;
		for (int i = 0; i < strlen(word); i++)
		{
			if (container[i] != word[i])
			{
				break;
			}
			else count++;
		}

		if (strlen(word) == count)
		{
			return 0;
		}

		int classString = 0;
		int otherString = 0;

		for (int i = 0; i < strlen(container); i++)
		{
			classString += container[i];
		}
		for (int i = 0; i < strlen(word); i++)
		{
			otherString += word[i];
		}
		if (classString > otherString)
		{
			return 1;
		}
		else return -1;
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
	string.Append(" Chosen");
	for (int i = 0; i < string.Size(); i++)
	{
		cout << string[i];
	}
	cout << endl;
	cout << "Compare to \"Bard Chose\" : " << string.Compare("Bard Chose") << endl;
	cout << "Compare to \"Bard Chosen\" : " << string.Compare("Bard Chosen") << endl;
	cout << "Compare to \"Bard Chosez\" : " << string.Compare("Bard Chosez") << endl;
	cout << "Compare to \"Bard Chosen To\" : " << string.Compare("Bard Chosen To") << endl;

	return 0;
}
