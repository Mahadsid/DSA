/*
206. Reverse Linked List
Easy
Topics
premium lock icon
Companies
Given the head of a singly linked list, reverse the list, and return the reversed list.



Example 1:


Input: head = [1,2,3,4,5]
Output: [5,4,3,2,1]
Example 2:


Input: head = [1,2]
Output: [2,1]
Example 3:

Input: head = []
Output: []


Constraints:

The number of nodes in the list is the range [0, 5000].
-5000 <= Node.val <= 5000


Follow up: A linked list can be reversed either iteratively or recursively. Could you implement both?

//STRIVER VID: https://youtu.be/D2vI2DNJGd8?si=v1IgstNaustft5_Z

*/

// +++++++++++++++++++++++++++++++++++++++++++++++ BRUTE FORCE +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
/*
Complexity Analysis

Time Complexity: O(N) ,We traverse the linked list twice once to push all node values into the stack, and once to reassign values. Each traversal takes O(N) time, where N is the number of nodes.

Space Complexity: O(N) , We use an extra stack to store all the node values, which requires O(N) additional space.
*/
#include <bits/stdc++.h>
using namespace std;

// Definition for singly-linked list node
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution
{
public:
    // Function to reverse a linked list using stack
    ListNode *reverseList(ListNode *head)
    {
        // Stack to store values of nodes
        stack<int> st;

        // Temporary pointer to traverse the list
        ListNode *temp = head;

        // Traverse and push all node values to stack
        while (temp != NULL)
        {
            st.push(temp->val);
            temp = temp->next;
        }

        // Reset temp back to head
        temp = head;

        // Reassign values from stack in reverse order
        while (temp != NULL)
        {
            temp->val = st.top();
            st.pop();
            temp = temp->next;
        }

        // Return the modified head
        return head;
    }
};

// Driver code
int main()
{
    // Creating linked list 1 -> 2 -> 3 -> NULL
    ListNode *head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);

    Solution sol;
    head = sol.reverseList(head);

    // Printing reversed list
    while (head != NULL)
    {
        cout << head->val << " ";
        head = head->next;
    }

    return 0;
}

// +++++++++++++++++++++++++++++++++++++++++++++++++ OPTIMAL ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
/*
Complexity Analysis

Time Complexity: O(N) Because we are traversing each node of the linked list exactly once. Each pointer reversal is done in constant time.

Space Complexity: O(1) We are not using any additional data structure or recursion. All modifications are done in-place using pointers.
*/
#include <bits/stdc++.h>
using namespace std;

class ListNode
{
public:
    int val;
    ListNode *next;

    // Constructor to initialize node value
    ListNode(int val)
    {
        this->val = val;
        this->next = NULL;
    }
};

class Solution
{
public:
    // Function to reverse a linked list iteratively
    ListNode *reverseList(ListNode *head)
    {
        // Initialize previous pointer to NULL
        ListNode *prev = NULL;

        // Start from the head of the list
        ListNode *temp = head;

        // Traverse the list
        while (temp != NULL)
        {
            // Save the next node
            ListNode *front = temp->next;

            // Reverse the current node's pointer
            temp->next = prev;

            // Move prev to current node
            prev = temp;

            // Move to the next node
            temp = front;
        }

        // Return new head (last node becomes first)
        return prev;
    }
};

// Driver code
int main()
{
    // Creating a linked list: 1 -> 2 -> 3 -> 4 -> 5
    ListNode *head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    Solution sol;
    // Reversing the list
    ListNode *newHead = sol.reverseList(head);

    // Printing the reversed list
    while (newHead != NULL)
    {
        cout << newHead->val << " ";
        newHead = newHead->next;
    }
    cout << endl;

    return 0;
}

//+++++++++++++++++++++++++++++++++++++++++++++++ RECURSIVE++++++++++++++++++++++++++++++++++++++++++++++++++++++++
/*
Complexity Analysis

Time Complexity: O(n),Each node is visited exactly once during the recursive call, and we do constant-time work for each node (like flipping pointers).

Space Complexity: O(n),The recursion stack goes up to n levels deep (one for each node), which uses extra space on the call stack.
*/
#include <bits/stdc++.h>
using namespace std;

// Definition for singly-linked list
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution
{
public:
    // Recursive function to reverse the linked list
    ListNode *reverseList(ListNode *head)
    {
        // Base case: if list is empty or has one node
        if (head == NULL || head->next == NULL)
            return head;

        // Recursively reverse the rest of the list
        ListNode *newHead = reverseList(head->next);

        // Store the next node
        ListNode *front = head->next;

        // Make the next node point back to current
        front->next = head;

        // Break the current node's forward link
        head->next = NULL;

        // Return the new head of the reversed list
        return newHead;
    }
};

// Driver code
int main()
{
    // Creating linked list 1 -> 2 -> 3 -> 4 -> 5
    ListNode *head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    Solution sol;
    ListNode *reversed = sol.reverseList(head);

    // Printing reversed list
    while (reversed != NULL)
    {
        cout << reversed->val << " ";
        reversed = reversed->next;
    }
    cout << endl;
    return 0;
}