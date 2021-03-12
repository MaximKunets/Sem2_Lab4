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

void replace_all(Node* head, int old_value, int new_value)
{
    Node* curr = head;
    while (curr)
    {
        if (curr->value == old_value)
            curr->value = new_value;
        curr = curr->next;
    }


}

int main()
{
    int old_value, new_value;
    Node* head = nullptr;

    fill_list(&head);
    cout << "old_value ";
    cin >> old_value;
    cout << "new_value ";
    cin >> new_value;
    replace_all(head, old_value, new_value);
    print_list(head);
    return 0;
}
