class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> mymap(255, -1);
        int len = 0, i = -1, tmp;
        for(int j = 0; j < s.length(); j++)
        {
        	tmp = mymap[s.at(j)];
        	i = max(tmp, i);
        	mymap[s.at(j)] = j;
        	len = max(len, (j-i));
        }
        return len;
    }
};

// 返回起始结束位置
// 需要双重循环
void LNRS_hash(char *str, int size)
{
	for(int i = 0;i < size; i++)
	{
		memset(visit, 0, sizeof(visit));
		visit[str[i]] = 1;
		for(int j= i+1; j < size; j++)
		{
			if(visit[str[j]] == 0) visit[str[j]] == 1;
			else {
				if(j - i > longest)
				{
					longest = j-i;
					start = i;
				}
				break;
			}
		}
		if( j == size && (j-i) > longest)
		{
			longest = j - i;
			start = i;
		}
	}
}