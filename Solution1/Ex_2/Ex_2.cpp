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
    (*head)->next = NULL;
    (*head)->value = 0;

    // filling rest of list
    Node* curr = *head;
    for (int i = 1; i < 5; ++i) {
        Node* temp = (Node*)malloc(sizeof(Node));
        curr->next = temp;
        temp->next = NULL;
        temp->value = i * i;
        curr = temp;
    }
}

void print_list(Node* head) 
{
    for (Node* curr = head; curr != NULL; curr = curr->next) {
        cout << curr->value << ' ';
    }
    cout << endl;
}

void clear_list(Node** head)
{
    
    
    Node* curr = (*head)->next;
    while (curr != NULL)
    {
        Node* curr_extra = curr->next;
        free(curr);
        curr = curr_extra;
        
    }
    free(curr);
    *head = NULL;
}

int main()
{
    Node* head = nullptr;

    fill_list(&head);

    print_list(head);
    cout << endl;

    clear_list(&head);

    print_list(head);

    return 0;
}