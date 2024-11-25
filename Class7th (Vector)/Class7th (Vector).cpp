#include <iostream>

using namespace std;

template<typename T>
class Vector
{
private:
	T* container;
	int size;
	int capacity;
public:
	Vector()
	{
		container = nullptr;
		size = 0;
		capacity = 0;
	}
	void ReSize(int newSize)
	{
		// 1. capacity에 새로운 size값 저장
		capacity = newSize;

		// 2. 새로운 포인터 변수를 선언
		T* newContainer = new T[capacity];

		// 3. 새로운 메모리 공간 값들 초기화
		for (int i = 0; i < capacity; i++)
		{
			newContainer[i] = NULL;
		}

		// 4. 기존 배열의 값을 복사해오기
		if (container != nullptr)
		{
			for (int i = 0; i < size; i++)
			{
				newContainer[i] = container[i];
			}
			// 5. 기존 배열 메모리 해제
			delete[] container;
		}
		// 6. 기존 배열을 가리키던 포인터 변수를 새 배열로 옮김
		container = newContainer;
	}
	void PushBack(T data)
	{
		if (container != nullptr)
		{
			if (size >= capacity)
			{
				ReSize(capacity * 2);
			}
		}
		else
		{
			ReSize(1);
		}
		container[size++] = data;
	}
	void PopBack()
	{
		if (container != nullptr && size > 0)
		{
			container[--size] = NULL;
		}
		else
		{
			cout << "Vector is Empty!" << endl;
		}
	}
	void Reserve(int newSize)
	{
		if (capacity < newSize)
		{
			ReSize(newSize);
		}
	}
	int& Size()
	{
		return size;
	}
	T& operator [](const int& index)// 바뀌지 않도록, 레퍼런스로
	{
		return container[index];
	}

	~Vector()
	{
		if (container != nullptr)
		{
			delete[] container;
		}
	}
};

int main()
{
	Vector<int> vector;

	vector.Reserve(4);

	vector.PushBack(10);
	vector.PushBack(20);
	vector.PushBack(30);
	vector.PushBack(40);
	vector.PushBack(50);
	vector.PopBack();
	vector.PopBack();

	for (int i = 0; i < vector.Size(); i++)
	{
		cout << vector[i] << endl;
	}

	return 0;
}