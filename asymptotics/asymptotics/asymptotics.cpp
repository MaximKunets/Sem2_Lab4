#include <iostream>
#include <chrono>
#include <numeric>
#include <iomanip>
#include <list>
using namespace std;

struct vector
{
	int* arr;
	int size, capacity;
};

void init(vector* qv)
{
	qv->arr = (int*)malloc(2 * sizeof(int));
	qv->size = 0;
	qv->capacity = 2;
}

void push(vector* qv)
{
	for (int i = 0; i < qv->size;++i)
		cout << qv->arr[i] << " ";
}


void push_back(vector* qv, int d)
{
	if (qv->capacity - qv->size == 0)
	{
		qv->arr = (int*)realloc(qv->arr, (qv->size *2) * sizeof(int));
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

void push_front(vector* qv, int d)
{
	if (qv->capacity - qv->size == 0)
	{
		qv->arr = (int*)realloc(qv->arr, (qv->size * 2) * sizeof(int));
		for (int i = qv->size; i > 0;--i)
			qv->arr[i] = qv->arr[i - 1];
		qv->arr[0] = d;
		qv->size += 1;
		qv->capacity *= 2;
	}
	else
	{
		for (int i = qv->size; i > 0;--i)
			qv->arr[i] = qv->arr[i - 1];
		qv->arr[0] = d;
		qv->size += 1;
	}
}

void time_push_back(int N, vector * qv)
{
	FILE* fout;
	char   c = '\n';
	char m[] = "N - Time";
	fopen_s(&fout, "output_push_back.txt", "w");
	fprintf(fout, "%s", m);
	fprintf(fout, "%c", c);

	for (int i = 1; i < N + 1; ++i)
	{
		auto start = chrono::high_resolution_clock::now();
		push_back(qv, 1);
		auto end = chrono::high_resolution_clock::now();
		chrono::duration<float> diff = end - start;
		char   s[] = "-";

		fprintf(fout, "%i", i);
		fprintf(fout, "%s", s);
		fprintf(fout, "%i", int(diff.count() * 1000000000));
		fprintf(fout, "%c", c);
	}
	fclose(fout);
}

void time_pop_back(int N, vector * qv)
{
	FILE* fout;
	char   c = '\n';
	char m[] = "N - Time";
	fopen_s(&fout, "output_pop_back.txt", "w");
	fprintf(fout, "%s", m);
	fprintf(fout, "%c", c);

	for (int i = 1; i < N + 1; ++i)
		push_back(qv, 1);

	for (int i = N; i > 0; --i)
	{
		auto start = chrono::high_resolution_clock::now();
		int a = pop_back(qv);
		auto end = chrono::high_resolution_clock::now();
		chrono::duration<float> diff = end - start;
		char   s[] = "-";

		fprintf(fout, "%i", i);
		fprintf(fout, "%s", s);
		fprintf(fout, "%i", int(diff.count() * 1000000000));
		fprintf(fout, "%c", c);
	}
	fclose(fout);
}

void time_push_front(int N, vector * qv)
{
	FILE* fout;
	char   c = '\n';
	char m[] = "N - Time";
	fopen_s(&fout, "output_push_front.txt", "w");
	fprintf(fout, "%s", m);
	fprintf(fout, "%c", c);

	for (int i = 1; i < N + 1; ++i)
	{
		auto start = chrono::high_resolution_clock::now();
		push_front(qv, 1);
		auto end = chrono::high_resolution_clock::now();
		chrono::duration<float> diff = end - start;
		char   s[] = "-";

		fprintf(fout, "%i", i);
		fprintf(fout, "%s", s);
		fprintf(fout, "%i", int(diff.count() * 1000000000));
		fprintf(fout, "%c", c);
	}
	fclose(fout);
}

void time_push_back_list(list<int> * list1, int N)
{
	FILE* fout;
	char   c = '\n';
	char m[] = "N - Time";
	fopen_s(&fout, "output_push_back_list.txt", "w");
	fprintf(fout, "%s", m);
	fprintf(fout, "%c", c);
	for (int i = 1; i < N + 1; ++i)
	{
		auto start = chrono::high_resolution_clock::now();
		list1->push_back(1);
		auto end = chrono::high_resolution_clock::now();
		chrono::duration<float> diff = end - start;
		char   s[] = "-";

		fprintf(fout, "%i", i);
		fprintf(fout, "%s", s);
		fprintf(fout, "%i", int(diff.count() * 1000000000));
		fprintf(fout, "%c", c);
	}
}

void time_push_front_list(list<int>* list1, int N)
{
	FILE* fout;
	char   c = '\n';
	char m[] = "N - Time";
	fopen_s(&fout, "output_push_front_list.txt", "w");
	fprintf(fout, "%s", m);
	fprintf(fout, "%c", c);
	for (int i = 1; i < N + 1; ++i)
	{
		auto start = chrono::high_resolution_clock::now();
		list1->push_front(1);
		auto end = chrono::high_resolution_clock::now();
		chrono::duration<float> diff = end - start;
		char   s[] = "-";

		fprintf(fout, "%i", i);
		fprintf(fout, "%s", s);
		fprintf(fout, "%i", int(diff.count() * 1000000000));
		fprintf(fout, "%c", c);
	}
}


int main()
{
	vector qv;
	int  N , choice;
	char   c = '\n';
	list<int> list1;
	
	init(&qv);
	cout << "enter the max N"<<endl;
	cin >> N;
	cout << "Data on which of the functions you need?" << endl <<
		"0 - push_back (vector)" << endl << "1 - pop_back" << endl << "2 - push_front (vector)" <<
		endl <<"3 - push_back (list)" << endl << "4 - push_front (list)" << endl;
	cin >> choice;

	if (choice == 0)
		time_push_back(N, &qv);
	if (choice == 1)
		time_pop_back(N, &qv);
	if (choice == 2)
		time_push_front(N, &qv);
	if (choice == 3)
		time_push_back_list(&list1, N);
	if (choice == 4)
		time_push_front_list(&list1, N);

	return 0;
}
