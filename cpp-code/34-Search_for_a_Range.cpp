class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> result({-1, -1});
        if(nums.size() == 0) return result;

        int st = 0, ed = nums.size()-1, mid;

        while(st < ed)
        {
        	mid = st + (ed - st) / 2;
        	if(nums[mid] < target) st = mid + 1;
        	else ed = mid;
        }
        if(nums[st] != target) return result;

        result[0] = st;

        ed = nums.size()-1;
        while(st < ed)
        {
        	mid = st + (ed - st) / 2;
        	if(nums[mid] > target) ed = mid - 1;
        	else st = mid;
        }
        result[1] = ed;
        return result;
    }
};