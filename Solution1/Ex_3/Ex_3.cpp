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
    *head = (Node*)malloc(sizeof(Node));
    (*head)->next = nullptr;
    (*head)->value = 0;

    // filling rest of list
    Node* curr = *head;
    for (int i = 1; i < 5; ++i) 
    {
        Node* temp = (Node*)malloc(sizeof(Node));
        curr->next = temp;
        temp->next = nullptr;
        temp->value = i * i;
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

int pop(Node** head, int index)
{
    int value;
    if (index != 1)
    {
        Node* curr = *head;
        Node* curr_index_pre = nullptr;
        for (int i = 1; i < index; i++)
        // here I believe that the head index is a one    
        {
            if (i == index - 2)
                // getting a pointer to the index-1 element
                curr_index_pre = curr->next; 
            curr = curr->next;
        }
        Node* curr_extra = curr->next; // getting a pointer to the index+1 element
        value = curr->value;
        free(curr);
        curr_index_pre->next = curr_extra;
    }
    else
    {
        Node* curr_extra = (*head)->next;
        value = (*head)->value;
        free(*head);
        *head = curr_extra;
    }
    return value;
}

int main() 
{
    int index;
    Node* head = nullptr;

    fill_list(&head);

    print_list(head);

    cin >> index;
    cout << endl << pop(&head, index) <<endl;

    print_list(head);
    return 0;
}
