class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int V=graph.size();
        // vector<int> vis(n,0);
        vector<int> inDegree(V,0);
        vector<int> Revadj[V];
        for(int i=0; i<V; i++){
            for(int it : graph[i]){
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