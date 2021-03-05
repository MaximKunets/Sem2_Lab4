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
    cout << "value of elements"<< endl;
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

void remove(Node** head, int value)
{
    Node* curr = *head;
    Node* curr_extra = nullptr;
    while (curr->value != value && curr->next != nullptr)
    {
        curr_extra = curr; // pointer to the element preceding the one you are looking for
        curr = curr->next; // pointer to the desired element
    }
    if (curr->next != nullptr)
    {
        if (curr_extra != nullptr)
        {
            // if the first element we are looking for is not the head
            curr_extra->next = curr->next;
            free(curr);
        }
        else

        {
            // delete head if value coincides with head->value
            curr_extra = (*head)->next;
            value = (*head)->value;
            free(*head);
            *head = curr_extra;
        }
    }

}

int main()
{
    int value;
    Node* head = nullptr;

    fill_list(&head);
    cout << "deleted value ";
    cin >> value;
    remove(&head, value);

    print_list(head);
    return 0;
}
