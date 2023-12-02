//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    vector<int> eventualSafeNodes(int V, vector<int> adj[]) {
        // code here
        vector<int> Revadj[V];
        int inDegree[V] = {0};
        for(int i=0; i<V; i++){
            for(int it : adj[i]){
                Revadj[it].push_back(i);
                inDegree[i]++;
            }
        }
        
        queue<int>q;
        vector<int>safeNodes;
        for(int i=0; i<V; i++){
            if(inDegree[i] == 0){
                q.push(i);
            }
        }
        
        while(!q.empty()){
            int node = q.front();
            safeNodes.push_back(node);
            q.pop();
            
            for(auto it : Revadj[node]){
                inDegree[it]--;
                if(inDegree[it] == 0){
                q.push(it);
                }
            }
        }
        
        sort(safeNodes.begin(),safeNodes.end());
        
        return safeNodes;
    }
};
// private:
//     bool dfs(int node, int vis[], int pathVis[], vector<int> adj[],int check[]){
//         vis[node] = 1;
//         pathVis[node] = 1;
//         check[node] = 0;
//         for(auto it : adj[node]){
//             if(!vis[it]){
//                 if(dfs(it,vis,pathVis,adj,check)){
//                     check[node] = 0;
//                     return true;
//                 }
//             }    
//             else if(pathVis[it]){
//                 check[node] = 0;
//                 return true;
//             }
//         }
//         check[node] = 1;
//         pathVis[node] = 0;
//         return false;
//     }
//   public:
//     vector<int> eventualSafeNodes(int V, vector<int> adj[]) {
//         // code here
        
//         int vis[V]={0};
//         int pathVis[V] = {0};
//         int check[V] = {0};
//         vector<int> safeNodes;
        
//         for(int i=0; i<V; i++ ){
//             if(!vis[i]){
//                 dfs(i,vis,pathVis,adj,check);
//             }
//         }
//         for(int i=0; i<V; i++){
//             if(check[i] == 1){
//                 safeNodes.push_back(i);
//             }
//         }
//         return safeNodes;
//     }

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {

        int V, E;
        cin >> V >> E;
        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        vector<int> safeNodes = obj.eventualSafeNodes(V, adj);
        for (auto i : safeNodes) {
            cout << i << " ";
        }
        cout << endl;
    }
}

// } Driver Code Ends