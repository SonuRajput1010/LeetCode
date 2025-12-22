class Solution {
    public int[] twoSum(int[] numbers, int target) {
        int[] nums = numbers.clone(); 
        Arrays.sort(numbers); 

        int left = 0;
        int right = numbers.length - 1;

        while (left < right) {
            int sum = numbers[left] + numbers[right];
            if (sum == target) {
                int first = -1, second = -1;

                for (int i = 0; i < nums.length; i++) {
                    if (nums[i] == numbers[left] && first == -1) first = i;
                    else if (nums[i] == numbers[right] && i != first) second = i;
                }
                return new int[]{first, second};
            } else if (sum < target) {
                left++;
            } else {
                right--;
            }
        }
        return new int[]{-1, -1};
    }
}