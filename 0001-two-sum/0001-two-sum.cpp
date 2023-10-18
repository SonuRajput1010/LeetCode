class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> mp;
        int n = nums.size();
        for(int i=0; i<n; i++){
            int ans = nums[i];
            int needed = target - ans;
            if(mp.find(needed) != mp.end()){
                return {mp[needed],i};
            }
            mp[ans] = i ;
         }
        return {-1,-1};
    }
};