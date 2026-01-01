
/*
141. Linked List Cycle
Easy
Topics
premium lock icon
Companies
Given head, the head of a linked list, determine if the linked list has a cycle in it.

There is a cycle in a linked list if there is some node in the list that can be reached again by continuously following the next pointer. Internally, pos is used to denote the index of the node that tail's next pointer is connected to. Note that pos is not passed as a parameter.

Return true if there is a cycle in the linked list. Otherwise, return false.



Example 1:


Input: head = [3,2,0,-4], pos = 1
Output: true
Explanation: There is a cycle in the linked list, where the tail connects to the 1st node (0-indexed).
Example 2:


Input: head = [1,2], pos = 0
Output: true
Explanation: There is a cycle in the linked list, where the tail connects to the 0th node.
Example 3:


Input: head = [1], pos = -1
Output: false
Explanation: There is no cycle in the linked list.


Constraints:

The number of the nodes in the list is in the range [0, 104].
-105 <= Node.val <= 105
pos is -1 or a valid index in the linked-list.
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

// LOVE BABBAR SOLUTION WITH BONUS QUESTION ON THIS QUESTION.
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

bool detectloop(Node *head)
{
    if (head == NULL)
    {
        cout << "List is Empty " << endl;
        return false;
    }
    map<Node *, bool> visited;

    Node *temp = head;

    while (temp != NULL)
    {
        // cycle is present
        if (visited[temp] == true)
        {
            cout << "Present on element " << temp->data << endl;
            return 1;
        }
        visited[temp] = true;
        temp = temp->next;
    }
    return false;
}
// tc = 0(N) sc=0(N)

// to reduce space we use floyd cycle detection algorithm

// slow == fast khiladi = loop is present

Node *FloydCycleDetect(Node *head)
{
    if (head == NULL)
    {
        cout << "List is Empty " << endl;
        return NULL;
    }

    Node *slow = head;
    Node *fast = head;

    while (slow != NULL && fast != NULL)
    {
        fast = fast->next;
        if (fast != NULL)
        {
            fast = fast->next;
        }
        slow = slow->next;
    }
    // looop present
    if (slow == fast)
    {
        cout << "Present on element " << slow->data << endl;
        return slow;
    }

    return NULL;
}
// TC=0(N) SC=0(1)

// node where loop starts?
Node *getstartingnode(Node *head)
{
    if (head == NULL)
    {
        cout << "List is Empty " << endl;
        return NULL;
    }

    Node *intersection = FloydCycleDetect(head);
    if (intersection == NULL)
    {
        return NULL;
    }

    Node *slow = head;

    while (slow != intersection)
    {
        slow = slow->next;
        intersection = intersection->next;
    }

    return slow;
}

// remove loop
Node *removeloop(Node *head)
{
    if (head == NULL)
    {
        cout << "List is Empty " << endl;
        return NULL;
    }

    Node *startofloop = getstartingnode(head);
    if (startofloop == NULL)
    {
        return head;
    }

    Node *temp = startofloop;

    while (temp->next != startofloop)
    {
        temp = temp->next;
    }
    temp->next = NULL;

    return;
}
// TC= 0(N),sc=0(1)

/*
tc=0(n) sc=0(1) but less complexity
ListNode *detectCycle(ListNode *head) {
        if (head == NULL || head->next == NULL)
            return NULL;
        ListNode* slow = head, *fast = head;
        while (fast->next != NULL && fast->next->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast) {
                slow = head;
                while (slow != fast) {
                    slow = slow->next;
                    fast = fast->next;
                }
                return slow;
            }
        }
        return NULL;
    }*/