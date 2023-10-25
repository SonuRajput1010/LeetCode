class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        long long int product = 1;
        int n = nums.size();
        int flag = 0;
        for(int i=0; i<n; i++){
            if(nums[i] == 0) flag++;
            else product *= nums[i];
        }
        
        for(int i=0; i<n; i++){
            if(flag > 1) nums[i] = 0;
            else if(flag == 0) nums[i] = product/nums[i];
            else if(flag == 1 && nums[i] != 0) nums[i] = 0;
            else nums[i] = product;
        }
        return nums;
    }
};