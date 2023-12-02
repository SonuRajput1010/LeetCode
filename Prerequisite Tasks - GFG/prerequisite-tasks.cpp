//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
	bool isPossible(int V,int P, vector<pair<int, int> >& prerequisites) {
	    // Code here
	    vector<int>adj[V];
	    for(auto it:prerequisites ){
	        adj[it.first].push_back(it.second);
	    }
	    
	    int inDegree[V] ={0};
	    for(int i=0; i<V; i++){
	        for(auto it : adj[i]){
	            inDegree[it]++;
	        }
	    }
	    queue<int>q;
	    vector<int>topo;
	    for(int i=0; i<V; i++){
	        if(inDegree[i] == 0){
	            q.push(i);
	        }
	    }
	    
	    while(!q.empty()){
	        int node = q.front();
	        q.pop();
	        topo.push_back(node);
	       // node is in your topo sort;
	       //so remove it from inDegree
	        for(auto it : adj[node]){
	            inDegree[it]--;
	            if(inDegree[it] == 0) q.push(it);
	        }
	    }
	    
	    if(topo.size() == V){
	        return true;
	    }
	    return false;
	    
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
    	int N, P;
        vector<pair<int, int> > prerequisites;
        cin >> N;
        cin >> P;
        for (int i = 0; i < P; ++i) {
            int x, y;
            cin >> x >> y;
            prerequisites.push_back(make_pair(x, y));
        }
        // string s;
        // cin>>s;
        Solution ob;
        if (ob.isPossible(N,P, prerequisites))
            cout << "Yes";
        else
            cout << "No";
        cout << endl;
	}
	return 0;
}
// } Driver Code Ends