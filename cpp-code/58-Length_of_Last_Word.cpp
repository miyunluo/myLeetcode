class Solution {
public:
    int lengthOfLastWord(string s) {
        int len = 0, right = s.length()-1;
        while(right >= 0 && s[right] == ' ') right--;
        while(right >= 0 && s[right] != ' ')
        {
        	len++;
        	right--;
        }
        return len;
    }
};