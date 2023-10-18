//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

/* A binary tree node has data, pointer to left
child and a pointer to right child */
class Node
{
public:
    int data;
    Node *left, *right;
    Node(int data)
    {
        this->data = data;
        this->left = this->right = NULL;
    }
};

/* This function is to print the inorder of the tree  */
void inorder(Node *root)
{
    if (root == NULL)
        return;
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}



// } Driver Code Ends
//User function Template for C++

/*
class Node
{
public:
    int data;
    Node *left, *right;
    Node(int data)
    {
        this->data = data;
        this->left = this->right = NULL;
    }
};
*/


class Solution{
public:
    // function to construct tree from string
    int i=0;
    void solve(Node* root,string str){
        
        if(i<str.size() && isdigit(str[i])){
            int sum = 0;
            while(i<str.size() && isdigit(str[i])){
                sum *= 10;
                sum += str[i] -'0';
                i++;
            }
            root->data = sum;
        }
        if(i<str.size() && str[i] == '('){
            root->left = new Node(0);
            i++;
            solve(root->left,str);
            
            if(root->left->data == 0){
                root->left = NULL;
            }
        }
        if(i<str.size() && str[i] == '('){
            root->right = new Node(0);
            i++;
            solve(root->right,str);
            
            if(root->right->data == 0){
                root->right = NULL;
            }
        }
        if(i>=0 && str[i] ==')'){
            i++;
            return ;
        }
    }
    
    
    Node *treeFromString(string str){
        // code here
        int n = str.size();
        Node* root = new Node(0);
        
        solve(root,str);
        return root;
    }
};

//{ Driver Code Starts.

// Driver Code
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string str;
        cin >> str;
        Solution obj;
        Node *root = obj.treeFromString(str);
        inorder(root);
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends