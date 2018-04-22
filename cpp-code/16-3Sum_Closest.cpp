class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
    
    	sort(nums.begin(), nums.end());
    	int mid, right;
    	int Min = nums[0] + nums[1] + nums[2];
    
    	for(int left = 0; left < nums.size()-2; left++)
    	{
        	mid = left+1;
        	right = nums.size()-1;
        	int tmp = target - nums[left];
        	while(mid < right)
        	{
            	int sum = nums[left] + nums[mid] + nums[right];
            	if(abs(target - sum) < abs(target - Min))
                	Min = sum;
            	if(nums[mid] + nums[right] == tmp)
                	return target;
            	else if(nums[mid]+nums[right] < tmp) mid++;
            	else right--;
        	}
    	}
    	return Min;
	}
};