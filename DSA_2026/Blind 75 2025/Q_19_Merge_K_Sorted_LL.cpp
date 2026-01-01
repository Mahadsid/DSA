// BABBAR = https://youtu.be/eccAKrmffh8?si=VsoXc2KHnqBGY0so
#include <bits/stdc++.h>
#include <iostream>
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

class compare
{
public:
    bool operator()(Node *a, Node *b)
    {
        return a->data > b->data;
    }
};

Node *MergeKsortedLL(vector<Node *> &listArray)
{

    priority_queue<Node *, vector<Node *>, compare> minHeap;

    int k = listArray.size();

    if (k == 0)
    {
        return NULL;
    }
    // step1
    for (int i = 0; i < k; i++)
    {
        if (listArray[i] != NULL)
        {
            minHeap.push(listArray[i]);
        }
    }

    Node *head = NULL;
    Node *tail = NULL;
    while (minHeap.size() > 0)
    {
        Node *top = minHeap.top();
        minHeap.pop();

        if (top->next != NULL)
        {
            minHeap.push(top->next);
        }

        if (head == NULL)
        { // LL is empty
            head = top;
            tail = top;
        }
        else
        { // insert at end
            tail->next = top;
            tail = top;
        }
    }
    return head;
}
// tc=0(N log k) where N=Total No of nodes * no of link-list 'k' sc=0(k)

// ++++++++++++++++++++++++++++++++ STRIVER+++++++++++++++++++++++++++++++++
// https://youtu.be/1zktEppsdig?si=p93lAL-YF14YtrSr
/*
Time Complexity: O(K log K) + O(N*K*(3*log K))where K is the number of linked lists and N is the number of nodes in each list.

O(K log K) as inserting an element into the priority queue takes log K time and is repeated K times for each list head.

Considering there are N nodes in each of the K linked lists, the overall number of nodes to be processed is N * K. For each of these N * K nodes:

Pop: Removing the smallest element (top of the priority queue) takes log K time.
Add: Adding the next element from the same list (when available) also takes log K time.
Access top: Accessing the top of the priority queue for extraction or comparison also takes log K time.
Hence, the total time complexity for the merging process across all nodes is ~ O(N * K * log K).

Space Complexity : O(K) where K is the number of linked lists. The main contributor to space usage is the priority queue which holds a node from each of these lists. Regardless of the number of nodes within each list, priority queue only holds a reference to one of its nodes at a time hence the space complexity is proportional to the number of input linked lists

*/

#include <iostream>
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

// Function to merge K sorted linked lists
Node *mergeKLists(vector<Node *> &listArray)
{
    // Priority queue to maintain
    // sorted order based on node values
    // Pairs store node value and pointer to the node
    priority_queue<pair<int, Node *>,
                   vector<pair<int, Node *>>, greater<pair<int, Node *>>>
        pq;

    // Push the heads of all the
    // linked lists into the priority queue
    for (int i = 0; i < listArray.size(); i++)
    {
        // Check if the current linked list exists
        if (listArray[i])
        {
            // Push the pair of node data and
            // node pointer into the priority queue
            pq.push({listArray[i]->data, listArray[i]});
        }
    }

    // Create a dummy node to build the merged list
    Node *dummyNode = new Node(-1);
    Node *temp = dummyNode;

    // Merge the lists present
    // in the priority queue
    while (!pq.empty())
    {
        // Get the top element (minimum node value)
        // from the priority queue
        auto it = pq.top();
        pq.pop();

        // Check if the current
        // node has a next node
        if (it.second->next)
        {
            // Push the next node
            // into the priority queue
            pq.push({it.second->next->data, it.second->next});
        }

        // Set the next pointer of the
        // current node in the merged list
        temp->next = it.second; // update pointer
        temp = temp->next;      // move temp
    }

    // Return the merged linked list
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
    // Create linked lists
    Node *head1 = new Node(2, new Node(4, new Node(6)));
    Node *head2 = new Node(1, new Node(5));
    Node *head3 = new Node(1, new Node(1, new Node(3, new Node(7))));
    Node *head4 = new Node(8);

    // Populate the lists vector
    vector<Node *> lists = {head1, head2, head3, head4};

    cout << "Original Linked Lists:" << endl;
    for (int i = 0; i < lists.size(); ++i)
    {
        cout << "List " << i + 1 << ": ";
        printLinkedList(lists[i]);
    }

    // Merge the linked lists
    Node *mergedList = mergeKLists(lists);

    // Print the merged linked list
    cout << "Merged Linked List: ";
    printLinkedList(mergedList);

    return 0;
}