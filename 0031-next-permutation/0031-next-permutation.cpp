class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int N = nums.size();
         int idx = -1;
        
        for(int i=N-1; i>0; i--)
        {
            if(nums[i]>nums[i-1])
            {
                idx = i;
                break;
            }
        }
            if(idx == -1)
            {
                reverse(nums.begin(),nums.end());
            }
            else
            {
                
                    int prev = idx;
                for(int i=idx+1;i<N;i++)
                {
                    if(nums[i]>nums[idx-1] and nums[i]<=nums[prev])
                    {
                        prev=i;
                    }
                }
                swap(nums[idx-1],nums[prev]);
                reverse(nums.begin()+idx,nums.end());
                
            }
            for(int i=0; i<N; i++){
                cout<<nums[i]<< " ";
            }
    }
};