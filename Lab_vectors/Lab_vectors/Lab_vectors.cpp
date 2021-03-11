#include <iostream>
#include <stdio.h>
#include <math.h>
using namespace std;

struct vector
{
	int* arr;
	int size, capacity;
};

void init(vector* qv)
{
	qv->arr = (int*)malloc(2*sizeof(int));
	qv->size = 0;
	qv->capacity = 2;
}

void push_back(vector* qv, int d)
{
	if (qv->capacity - qv->size == 0)
	{
		qv->arr = (int*)realloc(qv->arr,(qv->size *2)*sizeof(int));
		qv->arr[qv->size] = d;
		qv->size += 1;
		qv->capacity *= 2;
	}
	else
	{
		qv->arr[qv->size] = d;
		qv->size += 1;
	}
}

int pop_back(vector* qv)
{
	int a = qv->arr[qv->size - 1];
	qv->size -= 1;
	return a;
}

void resize(vector* qv, unsigned int new_capacity)
{
	qv->arr = (int*)realloc(qv->arr, new_capacity * sizeof(int));
	qv->capacity = new_capacity;
	if (new_capacity < qv->size)
		qv->size = new_capacity;
}

void push(vector* qv)
{
	for (int i = 0; i < qv->size;++i)
		cout << qv->arr[i]<<" " ;
}

void shrink_to_fit(vector* qv)
{
	if (qv->capacity > qv->size)
	{
		qv->arr = (int*)realloc(qv->arr, qv->size * sizeof(int));
		qv->capacity = qv->size;
	}
}

void clear(vector* qv)
{
	qv->size = 0;
}

void destructor(vector* qv)
{
	free(qv->arr);
	qv->size = 0;
	qv->capacity = 0;
}

void init_from_file(vector* qv, const char* filename)
{
	FILE* fin;
	int i = 0;
	int a;
	fopen_s(&fin, filename, "r");
	while (fscanf_s(fin, "%i", &a) != EOF)
	{
		push_back(qv, a);
	}
	fclose(fin);
}

int main()
{
	vector qv;
	int d,N;
	unsigned int new_capacity;
	const char* filename;
	filename = "input.txt";
	init(&qv);
	/*cin >> N;
	for (int i = 0; i < N; ++i)
	{
		cin >> d;
		push_back(&qv, d);
	}
	//cout << endl << pop_back(&qv) << endl;
	//push(&qv);
	//cin >> new_capacity;
	//resize(&qv, new_capacity);
	//cout << " Before: "<< (&qv)->capacity;
	//shrink_to_fit(&qv);
	//cout << " After: " << (&qv)->capacity;
	//destructor(&qv);*/
	
	init_from_file(&qv, filename);
	push(&qv);
	return 0;
}