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

void sort_by_value(Node** head)//первый способ сортировки, изменяя значения
{
    Node* curr = (*head)->next;
    Node* sort = (Node*)malloc(sizeof(Node));
    sort->next = nullptr;
    Node* sort_head = sort;

    int min = (*head)->value;
    Node* min_value = *head;
    while (curr)
    {
        if (curr->value < min)
        {
            min = curr->value;
            min_value = curr;
        }
        curr = curr->next;
    }
    sort->value = min;

    curr = (*head);
    while (curr)
    {
        if (curr != min_value)
        {
            while (sort->next)
                if (curr->value >= (sort->next)->value)
                    sort = sort->next;
                else
                    break;
            Node* sort_new = (Node*)malloc(sizeof(Node));
            Node* memory = sort->next;
            sort->next = sort_new;
            sort_new->value = curr->value;
            sort_new->next = memory;
            sort = sort_head;
        }
        curr = curr->next;
    }
    curr = *head;
    while (curr)
    {
        curr->value = sort->value;
        curr = curr->next;
        sort = sort->next;
    }
}

Node* max(Node *head)
{
    Node* curr = head->next;
    Node* max_point = head;
    int max = head->value;
    while (curr)
    {
        if (max < curr->value)
        {
            max = curr->value;
            max_point = curr;
            
        }
        curr = curr->next;
    }
    return max_point;
}

void sort_by_points(Node** head)//второй способ сортировки, изменяя указатели
{
    Node* curr = *head;
    Node* old_head;
    int count = 0;
    Node* max_curr = max(*head);
    Node* m = max_curr;
    while (curr)
    {
        count += 1;
        curr = curr->next;
    }
    for(int i = 0;i<count;++i)
    {
        Node* extra_curr = *head;
        if (m != *head)
        {
            while (extra_curr)
            {
                if (extra_curr->next != m)
                {
                    extra_curr = extra_curr->next;
                }
                else
                    break;
            }
            extra_curr->next = m->next;

            old_head = *head;
            *head = m;
            (*head)->next = old_head;
        }
        if (max_curr->next!=nullptr)
            m = max(max_curr->next);
    }
}

int main()
{
    int old_value, new_value;
    Node* head = nullptr;
    fill_list(&head);
    sort_by_points(&head);
    print_list(head);
    return 0;
}
