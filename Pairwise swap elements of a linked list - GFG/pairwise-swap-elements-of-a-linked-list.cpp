//{ Driver Code Starts
#include <bits/stdc++.h> 
using namespace std; 

struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};


// } Driver Code Ends
/*
  Pairwise swap a linked list
  The input list will have at least one element
  node is defined as

struct Node
{
    int data;
    struct Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }

}*head;
*/
class Solution
{
    public:
    int getLen(struct Node* head){
        int len = 0;
        while(head != NULL){
            head = head->next;
            len++;
        }
        return len;
    }
    Node* pairWiseSwap(struct Node* head) 
    {
        // The task is to complete this method
        if(head==NULL||head->next==NULL){
        return head;
        }
        int len = getLen( head);
        
        Node* prev = NULL;
        Node* curr = head;
        Node* forward = curr->next;
        
        int  k = 2;
        int c = 0;
        while(c<k){
            forward=curr->next;
            curr->next=prev;
            prev=curr;
            curr=forward;
            c++;
        }
        
        if(forward != NULL){
            head->next = pairWiseSwap(forward);
        }
        return prev;
    }
};

//{ Driver Code Starts.

void printList(Node* node) 
{ 
	while (node != NULL) { 
		cout << node->data <<" "; 
		node = node->next; 
	}  
	cout<<"\n";
}

int main() 
{ 
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;

		int data;
		cin>>data;
		struct Node *head = new Node(data);
		struct Node *tail = head;
		map<Node*, int> mp;
		mp[head] = head->data;
		for (int i = 0; i<n-1; ++i)
		{
			cin>>data;
			tail->next = new Node(data);
			tail = tail->next;
			mp[tail] = tail->data;
		}
		struct Node *failure = new Node(-1);
		Solution ob;
		head = ob.pairWiseSwap(head);
		int flag = 0;
		struct Node *temp = head;
		while(temp){
		    if(mp[temp] != temp->data){
		        flag = 1;
		        break;
		    }
		    temp = temp->next;
		}
		if(flag)
		    printList(failure);
		else
		    printList(head);
	}
	return 0; 
}

// } Driver Code Ends