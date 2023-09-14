//{ Driver Code Starts
// driver code

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node* next;
    
    Node(int val)
    {
        data = val;
        next = NULL;
    }
};

void loopHere(Node* head, Node* tail, int position)
{
    if(position==0) return;
    
    Node* walk = head;
    for(int i=1; i<position; i++)
        walk = walk->next;
    tail->next = walk;
}

bool isLoop(Node* head)
{
    if(!head) return false;
    
    Node* fast = head->next;
    Node* slow = head;
    
    while( fast != slow)
    {
        if( !fast || !fast->next ) return false;
        fast=fast->next->next;
        slow=slow->next;
    }
    
    return true;
}

int length(Node* head)
{
    int ret = 0;
    while(head)
    {
        ret++;
        head = head->next;
    }
    return ret;
}

bool notOriginal(Node *head, unordered_map<Node *, int>&myMap){
    
    while(head){
        if(myMap.find(head)==myMap.end()) return true;
        if(myMap[head] != (head->data)) return true;
        
        head=head->next;
    }
}




// } Driver Code Ends
/*
structure of linked list node:

struct Node
{
    int data;
    Node* next;
    
    Node(int val)
    {
        data = val;
        next = NULL;
    }
};

*/

class Solution
{
    public:
    //Function to remove a loop in the linked list.
    bool detect_loop(Node* head)
    {
        Node* slow=head,*fast=head->next ;
        while(slow && fast)
        {
            if(slow==fast)
                return true ;
            slow = slow->next ;
            if(fast->next)
                fast = fast->next->next ;
            else
                fast = NULL ;
        }
        return false ;
    }
    Node* findfirst(Node* head)
    {
        Node* slow=head,*fast=head->next ;
        while(slow && fast && slow !=fast)
        {
            slow = slow->next ;
            if(fast->next)
                fast = fast->next->next ;
            else
                fast = NULL ;
        }
        fast = fast->next ;
        slow = head ;
        while(slow!=fast)
        {
            slow = slow->next ;
            fast = fast->next ;
        }
        return slow ;
    }
    void removeLoop(Node* head)
    {
        bool have_loop = detect_loop(head) ;
        if(!have_loop)
            return ;
            
        Node* firstNode = findfirst(head) ;
        bool flag = false ;
        Node* ptr = head,*prev ;
        while(1)
        {
            if(ptr==firstNode)
            {
                if(flag==false)
                    flag = true ;
                else
                    break ;
            }
            prev = ptr ;
            ptr = ptr->next ;
        }
        prev->next = NULL ;
        return ;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        unordered_map<Node *, int>myMap;
        
        int n, num;
        cin>>n;
        
        Node *head, *tail;
        cin>> num;
        head = tail = new Node(num);
        
        myMap[head]=num;
        
        for(int i=0 ; i<n-1 ; i++)
        {
            cin>> num;
            tail->next = new Node(num);
            tail = tail->next;
            myMap[tail]=num;
        }
        
        int pos;
        cin>> pos;
        loopHere(head,tail,pos);
        
        Solution ob;
        ob.removeLoop(head);
        
        if( isLoop(head) || length(head)!=n || notOriginal(head, myMap))
            cout<<"0\n";
        else
            cout<<"1\n";
    }
	return 0;
}

// } Driver Code Ends