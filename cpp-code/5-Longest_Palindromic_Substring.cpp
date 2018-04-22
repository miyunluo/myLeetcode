// 动态规划版本
//				true,								j = i
// dp[j][i] = 	str[i] == str[j],					i - j = 1
//				str[i] == str[j] && dp[j+1][i-1]	i - j > 1
class Solution {
public:
    string longestPalindrome(string s) {
        const int len = s.length();
        bool dp[len][len];
        fill_n(&dp[0][0], len*len, false);
        int maxlen = 1, start = 0;

        for(int i = 0; i<len; i++)
        {
        	for(int j = 0; j<=i; j++)
        	{
        		if(i - j < 2) dp[j][i] = (s[i] == s[j]);
        		else dp[j][i] = ( (s[i] == s[j]) && dp[j+1][i-1] );
        		if(dp[j][i] && maxlen < (i - j + 1))
        		{
        			maxlen = i - j + 1;
        			start = j;
        		}
        	}
        }
        return s.substr(start, maxlen);
    }
};