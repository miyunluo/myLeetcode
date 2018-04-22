class Solution {
public:
    int search(vector<int>& nums, int target) {
    	if(nums.size() == 0) return -1;

        int st = 0, ed = nums.size()-1, mid;
        while(st <= ed)
        {
        	mid = st + (ed - st) / 2;
        	if(nums[mid] == target) return mid;

        	// 中位数在左边
        	if(nums[mid] > nums[ed])
        	{
        		if(nums[mid] > target && target >= nums[st]) ed = mid -1;
        		else st = mid + 1;
        	}
        	// 中位数在右边
        	else if(nums[mid] < nums[st])
        	{
        		if(nums[mid] < target && target <= nums[ed]) st = mid + 1;
        		else ed = mid - 1;
        	}
        	// 没有旋转，正常情况
        	else{
        		if(nums[mid] > target) ed = mid - 1;
        		else st = mid + 1;
        	}
        }
        return -1;
    }
};