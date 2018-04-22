class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int> > result;
        if(nums.size() < 4) return result; // 出这种小于4个数的测试点莫不是失了智
        
        sort(nums.begin(), nums.end());
        int mid, right;
        for(int i= 0; i < nums.size()-3; i++)
        {
        	int target_i = target - nums[i];
        	if(i>0 && nums[i] == nums[i-1]) continue;

        	for(int left = i+1; left < nums.size()-2; left++)
        	{
        		if(left>i+1 && nums[left] == nums[left-1]) continue;
        		mid = left+1;
        		right = nums.size()-1;
        		int tmp = target_i - nums[left];
        		while(mid < right)
        		{
        			if(nums[mid] + nums[right] == tmp)
        			{
        				int tmp_mid = nums[mid], tmp_right = nums[right];
        				result.push_back(vector<int>({nums[i], nums[left], nums[mid], nums[right]}));
        				while(mid < right && nums[mid] == tmp_right) mid++;
        				while(mid < right && nums[right] == tmp_right) right--;
        			}
        			else if(nums[mid] + nums[right] < tmp) mid++;
        			else right--;
        		}
        	}
        }
        return result;
    }
};