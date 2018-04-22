class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
    	if(s3.size() != s1.size() + s2.size()) return false;

        cache[s2.size()+1][s1.size()+1];
        fill_n(&cache[0][0], (s2.size()+1)*(s1.size()+1), false);
        cache[0][0] = true;
        int i,j;
        for(i=1; i<s1.size()+1; i++)
        if(cache[0][i-1] && s1[i - 1] == s3[i - 1]) cache[0][i] = true;

        for(j=1; j<s2.size()+1; j++)
        if(cache[j-1][0] && s2[j - 1] == s3[j - 1]) cache[j][0] = true;

        for(j = 1; j<s2.size()+1; j++)
        for(i = 1; i<s1.size()+1; i++)
        if((cache[j-1][i] && s2[j-1] == s3[j+i-1]) || (cache[j][i-1] && s1[i-1] == s3[j+i-1]))
        cache[j][i] = true;

        return cache[s2.size()][s1.size()];
    }
};


