#include <iostream>
using namespace std;

struct vector
{
	int* arr;
	int size, capacity;
};

void init(vector* qv)
{
	qv = (vector*)malloc(sizeof(vector));
	qv->arr = (int*)malloc(sizeof(int));
	qv->size = 0;
	qv->capacity=1;
}

void push_back(vector* qv, int d)
{
	
	if (qv->capacity - qv->size == 0)
	{
		int*mass = (int*)malloc((qv->capacity+1) * sizeof(int));
		for (int i = 0; i < qv->size + 1;++i)
		{

		}
	}
	else
	{
		qv->arr[qv->size] = d;
		qv->size += 1;
	}
}

int main()
{
	vector qv;
	int d;
	init(&qv);
	cin >> d;
	push_back(&qv, d);
	return 0;
}