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

void print_list(Node* head) {
    for (Node* curr = head; curr != nullptr; curr = curr->next)
    {
        cout << curr->value << ' ';
    }
    cout << endl;
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

bool check_of_difference(Node* head, int value)
{
    Node* curr = head;
    while (curr)
    {
        if (curr->value == value)
            return false;
        curr = curr->next;
    }
    return true;
}

int unique(Node* head)
{
    int i = 0;
    Node* curr = head->next;
    Node* different_value = (Node*)malloc(sizeof(Node));
    different_value->next = nullptr;
    different_value->value = head->value;

    while (curr)
    {        if (check_of_difference(different_value, curr->value))
        {
            push_left(&different_value, curr->value);
        }
        curr = curr->next;
    }
    while (different_value)
    {
        i += 1;
        different_value = different_value->next;
    }
    return i;
}

int main()
{
    int old_value, new_value;
    Node* head = nullptr;
    fill_list(&head);
    cout << unique(head);
    return 0;
}
