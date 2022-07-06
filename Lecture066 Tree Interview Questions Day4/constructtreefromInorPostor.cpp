// { Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h> 
using namespace std; 

// Tree Node
struct Node
{
    int data;
    Node* left;
    Node* right;
};

// Utility function to create a new Tree Node
Node* newNode(int val)
{
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;
    
    return temp;
}

// Function to Build Tree
Node* buildTree(string str)
{   
    // Corner Case
    if(str.length() == 0 || str[0] == 'N')
            return NULL;
    
    // Creating vector of strings from input 
    // string after spliting by space
    vector<string> ip;
    
    istringstream iss(str);
    for(string str; iss >> str; )
        ip.push_back(str);
        
    // Create the root of the tree
    Node* root = newNode(stoi(ip[0]));
        
    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);
        
    // Starting from the second element
    int i = 1;
    while(!queue.empty() && i < ip.size()) {
            
        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();
            
        // Get the current node's value from the string
        string currVal = ip[i];
            
        // If the left child is not null
        if(currVal != "N") {
                
            // Create the left child for the current node
            currNode->left = newNode(stoi(currVal));
                
            // Push it to the queue
            queue.push(currNode->left);
        }
            
        // For the right child
        i++;
        if(i >= ip.size())
            break;
        currVal = ip[i];
            
        // If the right child is not null
        if(currVal != "N") {
                
            // Create the right child for the current node
            currNode->right = newNode(stoi(currVal));
                
            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }
    
    return root;
}


 // } Driver Code Ends
//User function Template for C++

//Node Structure
/*
struct Node
{
    int data;
    Node* left;
    Node* right;
};
*/

class Solution{
  public:
    void createmap(int in[], map<int,int> &nodeToIndex, int n){
        for (int i = 0; i < n; i++)
        {
            nodeToIndex[in[i] = i];
        }
        
    }
    int findPosition(int in[], int element, int n){
        for (int i = 0; i < n; i++)
        {
            if (in[i] == element)
            {
                return i;
            }
            
        }
        return -1;
    }
    Node* solve(int in[], int post[], int &index, int inorderStart, int inorderEnd, int n,
            map<int,int> &nodeToIndex){
        //base cASE
        if( index < 0 || inorderStart > inorderEnd){
            return NULL;
        }

        int element = post[index--];
        Node* root = newNode (element);


        int position = nodeToIndex[element];


        //recur call (in case of post order we create the right sub tree first)
        root->right = solve(in, post, index, position+1, inorderEnd, n, nodeToIndex);
        root->left = solve(in, post, index, inorderStart, position-1, n, nodeToIndex);
        
        return root;
    }
   Node * buildTreeInPre(int in[], int post[], int n){
       int postOrderIndex = n-1;
       map<int,int> nodeToIndex;
       createmap(in, nodeToIndex ,n);
       Node * ans = solve(in, post, postOrderIndex, 0, n-1, n, nodeToIndex);
       return ans;
   }
  
};
//tc=0(nlogn), sc=0()

// { Driver Code Starts.

// Driver code 
int main()
{
  
  
  return 0;
}  // } Driver Code Ends