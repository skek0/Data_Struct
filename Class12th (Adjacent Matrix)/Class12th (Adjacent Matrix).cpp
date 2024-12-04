#include <iostream>

using namespace std;
#define SIZE 10

template<typename T>
class AdjacentMatrix
{
private:
	int count;
	T vertexes[SIZE];
	int matrix[SIZE][SIZE];
public:
	AdjacentMatrix()
	{
		count = 0;
		for (int i = 0; i < SIZE; i++)
		{
			vertexes[i] = NULL;
		}
		for (int i = 0; i < SIZE; i++)
		{
			for (int j = 0; j < SIZE; j++)
			{
				matrix[i][j] = 0;
			}
		}
	}

	void Insert(T data)
	{
		if (count < SIZE)
		{
			vertexes[count++] = data;
		}
		else cout << "AdjacentMatrix FULL!" << endl;
	}
	void Connect(int i, int j)
	{
		if (count <= 0)
		{
			cout << "AdjacentMatrix is Empty" << endl;
			return;
		}

		if (i < count && j < count)
		{
			matrix[i][j] = 1;
			matrix[j][i] = 1;
		}
		else
		{
			cout << "Index out of range" << endl;
		}
	}
	void Print()
	{
		cout << "  ";
		for (int i = 0; i < count; i++)
		{
			cout << vertexes[i] << " ";
		}
		cout << endl;
		for (int i = 0; i < count; i++)
		{
			cout << vertexes[i] << " ";
			for (int j = 0; j < count; j++)
			{
				cout << matrix[i][j] << " ";
			}
			cout << endl;
		}
	}
};

int main()
{
	AdjacentMatrix<char> ajMatrix;

	ajMatrix.Insert('A');
	ajMatrix.Insert('B');
	ajMatrix.Insert('C');
	ajMatrix.Insert('D');

	ajMatrix.Connect(0, 1);
	ajMatrix.Connect(0, 2);
	ajMatrix.Connect(1, 2);
	ajMatrix.Connect(2, 3);

	ajMatrix.Print();

	return 0;
}