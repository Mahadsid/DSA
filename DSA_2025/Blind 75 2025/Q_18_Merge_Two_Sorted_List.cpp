// Babbar -> https://youtu.be/ogmBt6f9hw8?si=dpbkZyPbpz8sUV8B TC=0(n) SC=0(1)
#include <iostream>
#include <map>
using namespace std;
class Node
{

public:
    int data;
    Node *next;

    // constructor
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }

    // destructor
    ~Node()
    {
        int value = this->data;
        // memory free
        if (this->next != NULL)
        {
            delete next;
            this->next = NULL;
        }
        cout << " memory is free for node with data " << value << endl;
    }
};
// approach 1 kya second ka data first k do element k bich m askta h?

Node *solve(Node *first, Node *second)
{

    // if only one element present in first LL
    if (first->next == NULL)
    {
        first->next = second;
        return first;
    }

    Node *curr1 = first;
    Node *next1 = curr1->next;
    Node *curr2 = second;
    Node *next2 = curr2->next;

    while (next1 != NULL && curr2 != NULL)
    {
        if ((curr2->data >= curr1->data) && (curr2->data <= next1->data))
        {
            // adding node to right position by updating pointers
            curr1->next = curr2;
            next2 = curr2->next;
            curr2->next = next1;

            // updating pointers for next check
            curr1 = curr2;
            curr2 = next2;
        }
        else
        {
            // data range m lie ni krta to pointers ko aaghe badao curr1 nad next1 ko bdhao

            curr1 = next1;
            next1 = next1->next;

            if (next1 == NULL)
            { // first link empty hogyi h ab bachi hui second chipka do
                curr1->next = curr2;
                return first;
            }
        }
    }
    return first;
}

Node *twosortedmerge(Node *first, Node *second)
{
    if (first == NULL)
    {
        return second;
    }
    if (second == NULL)
    {
        return first;
    }

    if (first->data <= second->data)
    {
        return solve(first, second);
    }
    else
    {
        return solve(second, first);
    }
    return first;
}

// TC=0(n) SC=0(1)

// +++++++++++++++++++++++ STRIVER ++++++++++++++++++++++++++++
// Complexity Analysis
// Time Complexity: O(N1+N2), where N1 is the number of nodes in the first linked list and N2 is nodes in the second linked list. We traverse both linked lists in a single pass for merging without any additional loops or nested iterations.
// Space Complexity: O(1), no additonal space is used to store the elements.
// https://youtu.be/jXu-H7XuClE?si=xrxKVf5NnbqfzTi0

#include <bits/stdc++.h>
using namespace std;

// Node class represents a
// node in a linked list
class Node
{
public:
    // Data stored in the node
    int data;

    // Pointer to the next node in the list
    Node *next;

    // Constructor with both data and
    // next node as parameters
    Node(int data1, Node *next1)
    {
        data = data1;
        next = next1;
    }

    // Constructor with only data as a
    // parameter, sets next to nullptr
    Node(int data1)
    {
        data = data1;
        next = nullptr;
    }
};

// Function to merge two sorted linked lists
Node *sortTwoLinkedLists(Node *list1, Node *list2)
{
    // Create a dummy node to serve
    // as the head of the merged list
    Node *dummyNode = new Node(-1);
    Node *temp = dummyNode;

    // Traverse both lists simultaneously
    while (list1 != nullptr && list2 != nullptr)
    {
        // Compare elements of both lists and
        // link the smaller node to the merged list
        if (list1->data <= list2->data)
        {
            temp->next = list1;
            list1 = list1->next;
        }
        else
        {
            temp->next = list2;
            list2 = list2->next;
        }
        // Move the temporary pointer
        // to the next node
        temp = temp->next;
    }

    // If any list still has remaining
    // elements, append them to the merged list
    if (list1 != nullptr)
    {
        temp->next = list1;
    }
    else
    {
        temp->next = list2;
    }
    // Return the merged list starting
    // from the next of the dummy node
    return dummyNode->next;
}

// Function to print the linked list
void printLinkedList(Node *head)
{
    Node *temp = head;
    while (temp != nullptr)
    {
        // Print the data of the current node
        cout << temp->data << " ";
        // Move to the next node
        temp = temp->next;
    }
    cout << endl;
}

int main()
{
    // Example Linked Lists
    Node *list1 = new Node(1);
    list1->next = new Node(3);
    list1->next->next = new Node(5);

    Node *list2 = new Node(2);
    list2->next = new Node(4);
    list2->next->next = new Node(6);

    cout << "First sorted linked list: ";
    printLinkedList(list1);

    cout << "Second sorted linked list: ";
    printLinkedList(list2);

    Node *mergedList = sortTwoLinkedLists(list1, list2);

    cout << "Merged sorted linked list: ";
    printLinkedList(mergedList);

    return 0;
}