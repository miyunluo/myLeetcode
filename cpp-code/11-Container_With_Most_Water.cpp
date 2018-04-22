class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0, right = height.size()-1;
        int vol, maxVol = min(height[left], height[right]) * (right - left);

        while(left < right)
        {
        	if(height[left] < height[right]) left++;
        	else right--;
        	vol = min(height[left], height[right]) * (right - left);
        	if(vol > maxVol) maxVol = vol;
        }
        return maxVol;
    }
};

// 每次移动高度较低的边