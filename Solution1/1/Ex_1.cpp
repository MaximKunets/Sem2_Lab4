#include <iostream>
using namespace std;

typedef struct Node
{
	int value;
	struct Node* next;
} Node;

void push_left(Node** head, int value)
{
	Node* old_head = (Node*)malloc(sizeof(Node));
	old_head->value = (**head).value;
	old_head->next = (**head).next;

	Node* new_head = (Node*)malloc(sizeof(Node));
	new_head->value = value;
	new_head->next = old_head;
	*head = new_head;
}

void printNode(Node* head)
{
	Node* current = head;
	while (current != NULL)
	{
		cout << current->value << " ";
		current = current->next;
	}
}

int main()
{
	int value_cin;
	Node* head = (Node*)malloc(sizeof(Node));
	cin >> value_cin;
	head->value = value_cin;

	Node* point_2 = (Node*)malloc(sizeof(Node));
	cin >> value_cin;
	point_2->value = value_cin;
	head->next = point_2;

	Node* point_3 = (Node*)malloc(sizeof(Node));
	cin >> value_cin;
	point_3->value = value_cin;
	point_2->next = point_3;


	Node* point_4 = (Node*)malloc(sizeof(Node));
	point_4 = NULL;
	point_3->next = point_4;

	int value;
	cin >> value;
	push_left(&head, value);
	cout << "became" << endl;
	printNode(head);
}