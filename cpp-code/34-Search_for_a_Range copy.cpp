class Solution {
public:
    int lower_bound(vector<int>& nums, int  target) {
        int minn = 0, maxx = nums.size()-1, mid;
        while(minn <= maxx)
        {
            mid = minn + (maxx - minn) / 2;
            if(nums[mid] < target) minn = mid + 1;
            else maxx = mid - 1;
        }
        return minn;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        if(nums.size() == 0) vector<int>({-1, -1});;
        int x1 = lower_bound(nums, target);
        int x2 = lower_bound(nums, target+1)-1;
        if(x1 < nums.size() && nums[x1] == target)
            return vector<int>({x1, x2});
        else return vector<int> ({-1, -1});
    }
};