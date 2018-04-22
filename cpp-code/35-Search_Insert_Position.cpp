class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int minn = 0, maxx = nums.size()-1;
        while(minn <= maxx)
        {
        	int mid = minn + (maxx - minn) / 2;
        	if(nums[mid] < target) minn = mid + 1;
        	else maxx = mid - 1;
        }
        return minn;
    }
};