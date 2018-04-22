class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int end = nums.size()-1;
        while(end > 0)
        {
            if(nums[end-1] < nums[end]) break;
            end--;
        }
        if(end > 0)
        {
            end--;
            int right = nums.size()-1;
            while(right >0 && nums[right] <= nums[end]) right--;
            int swap = nums[end];
            nums[end] = nums[right];
            nums[right] = swap;
            end++;
        }
        int right=nums.size() -1;
        while(right > end)
        {
            int swap = nums[end]
            nums[end] = nums[right];
            nums[right] = swap;
            right--;
            end++;
        }
    }
};