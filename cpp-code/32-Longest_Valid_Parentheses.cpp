class Solution {
public:
    int longestValidParentheses(string s) {
        stack<pair<int, int> > stk; // first:index, second: 0: ( 1:)
        int maxLen = 0, curLen = 0;
        for(int i = 0; i<s.size();i++) {
            if(s[i] == '(') stk.push(make_pair(i,0));
            else 
            {
                if(stk.empty() || stk.top().second == 1) stk.push(make_pair(i, 1));
                else 
                {
                    stk.pop();
                    if(stk.empty()) curLen = i+1;
                    else curLen = i - stk.top().first;
                    maxLen = max(maxLen, curLen);
                }
            }
        }
        return maxLen;
    }
};