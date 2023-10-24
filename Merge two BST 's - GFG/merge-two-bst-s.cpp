//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
#define MAX_HEIGHT 100000

// Tree Node
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};





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
   Node* root = new Node(stoi(ip[0]));

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
           currNode->left = new Node(stoi(currVal));

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
           currNode->right = new Node(stoi(currVal));

           // Push it to the queue
           queue.push(currNode->right);
       }
       i++;
   }

   return root;
}



// } Driver Code Ends
/*
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/
class Solution
{
    public:
    //Function to return a list of integers denoting the node 
    //values of both the BST in a sorted order.
    Node* treeToDLL(Node* root,Node* &prev,Node* &head){
        if(!root) return NULL;
         treeToDLL(root->left,prev,head);
        if(prev==NULL) head=root;
        else{
            root->left=prev;
            prev->right=root;
        }
        prev=root;
        treeToDLL(root->right,prev,head);
        return head;
        
    }
    Node* mergeLL(Node* head1,Node* head2){
        Node* dummy=new Node(-1);
        Node*ans=dummy;
        while(head1 && head2){
            if(head1->data<head2->data){
                ans->right=head1;
                head1->left=ans;
                ans=ans->right;
                head1=head1->right;
            }
            else {
                ans->right=head2;
                head2->left=ans;
                ans=ans->right;
                head2=head2->right;
            }
        }
      if(!head1 && head2){
          ans->right=head2;
          head2->left=ans;
      }
      if(head1 && !head2){
          ans->right=head1;
          head1->left=ans;
      }
        dummy=dummy->right;
        dummy->left=NULL;
        return dummy;
    }
    vector<int> merge(Node *root1, Node *root2)
    {
        vector<int>ans;
        Node* prev1=NULL;
        Node* prev2=NULL;
        Node* Head=NULL;
        Node* Head2=NULL;
        Node* head1= treeToDLL(root1,prev1,Head);
        Node* head2= treeToDLL(root2,prev2,Head2);
        Node* mergedHead=mergeLL(head1,head2);
        while(mergedHead){
            ans.push_back(mergedHead->data);
            mergedHead=mergedHead->right;
        }
        return ans;
    }
};
// class Solution
// {
//     public:
//     //Function to return a list of integers denoting the node 
//     //values of both the BST in a sorted order.
    
//     void convertIntoDLL(Node* root,Node* &head){
//         if(root == NULL){
//             return NULL:
//         }
//         convertIntoLL(root->right,head);
        
//         root->right = head;
        
//         if(head != NULL){
//             head->left = root;
//         }
//         head = root;
//         convertIntoLL(root->left,head);
//     }
    
//     Node* sortedMergeTwoLL(Node* head1, Node* head2)  
//     {   // code here
//         Node* head = NULL;
//         Node* tail = NULL;
        
//         while(head1 != NULL && head2 != NULL){
            
//             if(head1->data < head2->data){
//                 if(head == NULL) {
//                     head = head1;
//                     tail = head1;
//                     head1 = head1->right;
//                 }
//                 else{
//                     tail->right = head1;
//                     head1->left = tail;
//                     tail = head1;
//                     head1 = head1->right;
//                 }
//             }
//             else{
//                 if(head == NULL) {
//                     head = head2;
//                     tail = head2;
//                     head2 = head2->right;
//                 }
//                 else{
//                     tail->right = head2;
//                     head2->left = tail;
//                     tail = head2;
//                     head2 = head2->right;
//                 }
//             }
//         }
//         while(head1 != NULL){
//             tail->right = head1;
//             head1->left = tail;
//             tail = head1;
//             head1 = head1->right;
//         }
//         while(head2 != NULL){
//             tail->right = head2;
//             head2->left = tail;
//             tail = head2;
//             head2 = head2->right;
//         }
//         return head;
//     }  
    
//     int countNode(Node* &head){
//         int count = 0;
//         Node* root= head;
//         while(root != NULL){
//             count++;
//             root = root->right;
//         }
//         return count;
//     }
    
//     Node* SortedLLtoBST(Node* &head, int n){
//         if(n<=0 || head == NULL){
//             return NULL;
//         }
        
//         Node* left = SortedLLtoBST(head, n/2);
        
//         Node* root = head;
//         root->left = left;
        
//         head = head->right;
//         Node* right = SortedLLtoBST(head, n-n/2-1);
//         return root;
//     }
    
//     vector<int> merge(Node *root1, Node *root2)
//     {
//       //Your code here
       
       
//     //   step1 : convert bst into LL
//       Node* head1 = NULL;
//       convertIntoLL(root1,head1);
//       head1->left = NULL;
       
//       Node* head2 = NULL;
//       convertIntoLL(root2,head2);
//       head2->left = NULL;
       
       
//     //   step2 : merge sorted list
//         Node* head  =  sortedMergeTwoLL(head1,head2);
        
//     //  step3: sorted ll into bst
//     SortedLLtoBST(head,countNode(head));
    
//     }
// };


// void inorder(Node *root, vector<int>&in){
//     if(root == NULL){
//         return;
//     }
//     inorder(root->left, in);
//     in.push_back(root->data);
//     inorder(root->right, in);
// }
// vector<int> mergetwoSortedArray(vector<int>&A, vector<int>&B){

//     vector<int>ans(A.size()+B.size());
//     int i=0; 
//     int j = 0;
//     int k =0;
//     while(i<A.size() && j<B.size()){
//         if(A[i] < B[j]){
//             ans[k++] = A[i];
//             i++;
//         }
//         else{
//             ans[k++] = B[j];
//             j++;
//         }
//     }
//     while(i<A.size()){
//         ans[k++] = A[i];
//             i++;
//     }
//     while(j<B.size()){
//         ans[k++] = B[j];
//             j++;
//     }
//     return ans;
// }
// Node* inOrderToBST(int s, int e, vector<int>&in){
        
//         if(s>e){
//             return NULL;
//         }
//             int mid = (s+e)/2;
            
//             Node* temp = new Node(in[mid]);
            
//             temp->left = inOrderToBST(s,mid-1,in);
//             temp->right = inOrderToBST(mid+1,e,in);
        
//         return temp;
            
// }
// vector<int> mergeBST(Node *root1, Node *root2)
// {
//     // Write your code here.

//     //step 1 inorder store
//     vector<int>bst1,bst2;
//     inorder(root1, bst1);
//     inorder(root2, bst2);

//     // merge sorted array
//     vector<int> mergedArray =  mergetwoSortedArray(bst1,bst2);

//     int s=0;
//     int e=mergedArray.size()-1;
//     inOrderToBST(s, e, mergedArray);
//     return mergedArray;

// }

//{ Driver Code Starts.
int main() {

   int t;
   string tc;
   getline(cin, tc);
   t=stoi(tc);
   while(t--)
   {
        string s; 
       getline(cin, s);
       Node* root1 = buildTree(s);

       getline(cin, s);
       Node* root2 = buildTree(s);
    
       // getline(cin, s);
       Solution obj;
       vector<int> vec = obj.merge(root1, root2);
       for(int i=0;i<vec.size();i++)
            cout << vec[i] << " ";
        cout << endl;
       ///cout<<"~"<<endl;
   }
   return 0;
}
// } Driver Code Ends