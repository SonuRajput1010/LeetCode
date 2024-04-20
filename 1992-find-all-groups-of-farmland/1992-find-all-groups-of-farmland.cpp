class Solution {
public:
    vector<vector<int>> findFarmland(vector<vector<int>>& land) {
        vector<vector<int>> ans;
        int m = land.size();
        int n = land[0].size();
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(land[i][j] == 1) {                   // r1 = i and c1 = j
                    int start_i = i, start_j = j;
                    
                    while(start_j < n && land[start_i][start_j] == 1)
                        start_j++;
                    start_j = start_j - 1;              // c2 = start_j
                    
                    while(start_i < m && land[start_i][start_j] == 1)
                        start_i++;
                    start_i = start_i - 1;              // r2 = start_i
                    
                    ans.push_back({i, j, start_i, start_j});
                    
                    // Setting the value 2 for this farmland so that we don't revisit the same
                    for(int p = i; p <= start_i; p++) { 
                        for(int q = j; q <= start_j; q++)
                            land[p][q] = 2;
                    }
                }
            }
        }
        return ans;
    }
};