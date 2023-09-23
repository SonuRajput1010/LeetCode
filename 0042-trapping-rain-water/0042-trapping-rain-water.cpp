class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int left = 0;
        int right = n-1;
        int leftmax = 0;
        int rightmax = 0;
        int water = 0;
        
        while(left <= right){
            
            if(height[left] <= height[right]){
                if(height[left] >= leftmax){
                    leftmax = height[left];
                }
                else
                    water += leftmax - height[left];

                left++;
            }
            else{
                if(height[right] >= rightmax){
                    rightmax = height[right];
                }
                else
                    water += rightmax - height[right];
                right--;
            }
        }
        return water;
        
    }
};
//         int left=0,right=n-1,left_max=0,right_max=0,water=0;
//         while(left<=right){
//             if(height[left]<=height[right]){
                
//                 if(height[left]>left_max) 
//                     left_max=height[left];
//                 else 
//                     water += left_max-height[left];
//                 left++;
//             }
//             else{
//                 if(height[right]>right_max) right_max=height[right];
//                 else water += right_max-height[right];
//                 right--;
//             }
//         }
//         return water;