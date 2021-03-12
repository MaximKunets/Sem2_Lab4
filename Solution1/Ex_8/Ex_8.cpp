#include<iostream>
using namespace std;

struct Node
{
    int value;
    Node* next;
};

void fill_list(Node** head)
{
    // creating head of list
    int value, n;
    cout << "number of elements ";
    cin >> n;
    *head = (Node*)malloc(sizeof(Node));
    (*head)->next = nullptr;
    cout << "value of elements" << endl;
    cin >> value;
    (*head)->value = value;

    // filling rest of list
    Node* curr = *head;

    for (int i = 1; i < n; ++i)
    {
        Node* temp = (Node*)malloc(sizeof(Node));
        curr->next = temp;
        temp->next = nullptr;
        cin >> value;
        temp->value = value;
        curr = temp;
    }
}

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

void print_list(Node* head) {
    for (Node* curr = head; curr != nullptr; curr = curr->next)
    {
        cout << curr->value << ' ';
    }
    cout << endl;
}

void reverse(Node** head)
{
    Node* curr = (*head)->next;
    Node* invers = (Node*)malloc(sizeof(Node));
    invers->value = (*head)->value;
    invers->next = nullptr;

    while (curr)
    {
        push_left(&invers, curr->value);
        curr = curr->next;
    }
    curr = *head;
    while (curr)
    {
        curr->value = invers->value;
        curr = curr->next;
        invers = invers->next;
    }
}

int main()
{
    int old_value, new_value;
    Node* head = nullptr;
    fill_list(&head);
    reverse(&head);
    print_list(head);
    return 0;
}
