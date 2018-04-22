class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
    	vector<vector<int> > result;

    	sort(nums.begin(), nums.end());
    	int mid, right;

    	for(int left = 0; left<nums.size() && nums[left]<=0; left++)
    	{
    		mid = left +1; right = nums.size()-1;
    		int tmp = 0 - nums[left];

    		if(left > 0 && nums[left] == nums[left-1]) continue;
    		while(mid < right)
    		{
    			if(nums[mid] + nums[right] == tmp)
    			{
    				int tmp_mid = nums[mid], tmp_right = nums[right];
    				result.push_back(vector<int>({nums[left], nums[mid], nums[right]}));
    				while(mid < right && nums[mid] == tmp_mid) ++mid;
    				while(mid < right && nums[right] == tmp_right) --right;
    			}
    			else if(nums[mid] + nums[right] < tmp) ++mid;
    			else --right;
    		}
    	}
        return result;	
    }
};