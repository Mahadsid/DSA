/*
Given the head of a linked list, remove the nth node from the end of the list and return its head.



Example 1:


Input: head = [1,2,3,4,5], n = 2
Output: [1,2,3,5]
Example 2:

Input: head = [1], n = 1
Output: []
Example 3:

Input: head = [1,2], n = 1
Output: [1]


Constraints:

The number of nodes in the list is sz.
1 <= sz <= 30
0 <= Node.val <= 100
1 <= n <= sz


Follow up: Could you do this in one pass?

Solution/Code : https://takeuforward.org/data-structure/remove-n-th-node-from-the-end-of-a-linked-list/

Video: https://youtu.be/3kMKYQ2wNIU?si=I9FdkgnHSozIs978

*/

//+++++++++++++++++++++++ Brute Force Approach+++++++++++++++++
// Complexity Analysis
// Time Complexity : O(L) + O(L - N), We are calculating the length of the linked list and then iterating up to the(L - N) th node of the linked list, where L is the total length of the list.Space Complexity : O(1), constant additional space is used.

#include <bits/stdc++.h>
using namespace std;

// Class representing a node in the linked list
class Node
{
public:
    int data;
    Node *next;

    // Constructor for Node with data and next node
    Node(int data1, Node *next1)
    {
        data = data1;
        next = next1;
    }

    // Constructor for Node with only data
    // (next set to nullptr)
    Node(int data1)
    {
        data = data1;
        next = nullptr;
    }
};

// Class to hold the solution logic
class Solution
{
public:
    // Function to print the linked list
    void printLL(Node *head)
    {
        while (head != NULL)
        {
            cout << head->data << " ";
            head = head->next;
        }
    }

    // Function to delete the Nth node from the end
    Node *deleteNthNodeFromEnd(Node *head, int N)
    {
        // If list is empty, return NULL
        if (head == NULL)
        {
            return NULL;
        }

        int cnt = 0;
        Node *temp = head;

        // Count the number of nodes in the linked list
        while (temp != NULL)
        {
            cnt++;
            temp = temp->next;
        }

        // If N equals the total number of nodes, delete the head
        if (cnt == N)
        {
            Node *newHead = head->next;
            // free memory
            delete head;
            return newHead;
        }

        // Calculate the position from start to delete
        int res = cnt - N;
        temp = head;

        // Traverse to the node just before the one to delete
        while (temp != NULL)
        {
            res--;
            if (res == 0)
            {
                break;
            }
            temp = temp->next;
        }

        // Delete the target node
        Node *delNode = temp->next;
        temp->next = temp->next->next;
        delete delNode; // free memory

        return head;
    }
};

int main()
{
    vector<int> arr = {1, 2, 3, 4, 5};
    int N = 3;

    // Creating linked list manually
    Node *head = new Node(arr[0]);
    head->next = new Node(arr[1]);
    head->next->next = new Node(arr[2]);
    head->next->next->next = new Node(arr[3]);
    head->next->next->next->next = new Node(arr[4]);

    Solution sol;
    head = sol.deleteNthNodeFromEnd(head, N);
    sol.printLL(head);
}

// ++++++++++++++++++++++++++++++++ Optimal Solution : ++++++++++++++++++++++++++++++++++++++++++++
/*
Complexity Analysis
Time Complexity: O(N), since the fast pointer will traverse the entire linked list, where N is the length of the linked list.
Space Complexity: O(1), constant additional space is used to check unique elements.
*/

#include <bits/stdc++.h>
using namespace std;

// Class representing a node in the linked list
class Node
{
public:
    int data;
    Node *next;

    // Constructor for Node with data and next node
    Node(int data1, Node *next1)
    {
        data = data1;
        next = next1;
    }

    // Constructor for Node with only data (next = nullptr)
    Node(int data1)
    {
        data = data1;
        next = nullptr;
    }
};

// Class to hold the solution logic
class Solution
{
public:
    // Function to print the linked list
    void printLL(Node *head)
    {
        while (head != NULL)
        {
            cout << head->data << " ";
            head = head->next;
        }
    }

    // Function to delete the Nth node from the end
    // using the optimized two-pointer method
    Node *deleteNthNodeFromEnd(Node *head, int N)
    {
        // Create a dummy node before head to handle edge cases
        Node *dummy = new Node(0, head);

        // Initialize slow and fast pointers at dummy
        Node *slow = dummy;
        Node *fast = dummy;

        // Move fast pointer N+1 steps ahead to create a gap
        for (int i = 0; i <= N; i++)
        {
            fast = fast->next;
        }

        // Move both pointers until fast reaches the end
        while (fast != NULL)
        {
            slow = slow->next;
            fast = fast->next;
        }

        // Slow is now at node before target → delete target node
        slow->next = slow->next->next;

        // Return updated head
        return dummy->next;
    }
};

// Main driver code
int main()
{
    vector<int> arr = {1, 2, 3, 4, 5};
    int N = 3;

    // Create linked list manually
    Node *head = new Node(arr[0]);
    head->next = new Node(arr[1]);
    head->next->next = new Node(arr[2]);
    head->next->next->next = new Node(arr[3]);
    head->next->next->next->next = new Node(arr[4]);

    // Create Solution object
    Solution sol;

    // Delete the Nth node from the end
    head = sol.deleteNthNodeFromEnd(head, N);

    // Print the modified linked list
    sol.printLL(head);
}