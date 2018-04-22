// map
class Solution{
	public:
		vector<int> twoSum(vector<int>& nums, int target){
			vector<int> result;
			unordered_map<int, int> mymap;
			int res;
			for(int i=0; i< nums.size(); ++i){
				res = target - nums[i];
				unordered_map<int, int>::iterator it = mymap.find(res);
				if(it != mymap.end()){
					return vector<int>({it->second, i});
				}
				mymap[nums[i]] = i;
			}
		}
};

// sort
class Solution{
public:
	vector<int> twoSum(vector<int>& nums, int target){
		vector<int> result;

		vector<int> nums_sort(nums);
		sort(nums_sort.begin(), nums_sort.end());
		int start = 0;
		int end = nums.size()-1;

		while(start < end){
			while(nums[start] + nums[end] > target) end--;
            if(nums[start] + nums[end] == target) break;
			while(nums[start] + nums[end] < target) start++;
			if(nums[start] + nums[end] == target) break;
		}
        
		int a = nums_sort[start];
		int b = nums_sort[end];
		for(int i = 0;i<nums.size(); ++i)
		{
			if(nums[i] == a) result.push_back(i);
            if(nums[i] == b) result.push_back(i);
		}
        
		return result;
	}
};