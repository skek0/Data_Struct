#include <iostream>

using namespace std;
#define SIZE 10

template<typename T>
class AdjacentMatrix
{
private:
	int vertexAmount;
	T vertexes[SIZE];
	int matrix[SIZE][SIZE];
public:
	AdjacentMatrix()
	{
		vertexAmount = 0;
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
};

int main()
{
	/*
		A	B	C	D
	A	0	1	0	1
	B	0	0	1	1
	C	0	0	0	1
	D	0	0	0	0
	*/

	return 0;
}