#include <iostream>
using namespace std;

struct NODE {
    int data;
    NODE *next;
};

void dupl(NODE *head)
{
    NODE *current = head;

    while (current != NULL) {
        NODE *copy = new NODE;

        copy->data = current->data;
        copy->next = current->next;

        current->next = copy;

        current = copy->next;   // move to next original node
    }
}

void printList(NODE *head)
{
    NODE *current = head;
    while (current != NULL) {
        cout << current->data;
        if (current->next != NULL) {
            cout << " -> ";
        }
        current = current->next;
    }
    cout << endl;
}

void freeList(NODE *head)
{
    while (head != NULL) {
        NODE *temp = head;
        head = head->next;
        delete temp;
    }
}

int main()
{
    NODE *head = new NODE{1, NULL};
    head->next = new NODE{2, NULL};
    head->next->next = new NODE{3, NULL};

    cout << "Original list: ";
    printList(head);

    dupl(head);

    cout << "After dupl:    ";
    printList(head);

    freeList(head);
    return 0;
}