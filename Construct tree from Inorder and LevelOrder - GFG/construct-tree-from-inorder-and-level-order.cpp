//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;
struct Node
{
	int key;
	struct Node *left;
	struct Node *right;
	
	Node(int x){
	    key = x;
	    left = NULL;
	    right = NULL;
	}
};

Node* buildTree(int inorder[], int levelOrder[], int iStart, int iEnd,int n);
void printPreorder(Node* node)
{
    if (node == NULL)
       return;
    cout << node->key << " ";
    printPreorder(node->left);
    printPreorder(node->right);
    
}
int main()
{
    int t;
    cin>>t;
    while(t--){
    int n;
    cin>>n;
    int in[n],level[n];
    for(int i=0;i<n;i++){
        cin>>in[i];
    }
    for(int i=0;i<n;i++){
        cin>>level[i];
    }
    Node *root=NULL;
    root = buildTree(in, level, 0, n - 1,n);
    printPreorder(root);
    cout<<endl;
    }
    return 0;
}
// } Driver Code Ends


/*Complete the function below
Node is as follows:
struct Node
{
    int key;
    struct Node* left, *right;
};
*/
Node* buildTree(int inorder[], int levelOrder[], int iStart, int iEnd,int n)
{
//add code here.
    queue<Node*> q;
    queue<int> arr;
    
    for(int i=0;i<n;i++){
        arr.push(levelOrder[i]);
    }
    
    Node* root=new Node(levelOrder[0]);
    arr.pop();
    q.push(root);
    
    while(!q.empty()){
        Node* node=q.front();
        q.pop();
        
        if(arr.size()){
            Node* l=new Node(arr.front());
            arr.pop();
            node->left=l;
            q.push(l);
        }
        
        if(arr.size()){
            Node* r=new Node(arr.front());
            arr.pop();
            
            node->right=r;
            
            q.push(r);
        }
    }
    return root;
}