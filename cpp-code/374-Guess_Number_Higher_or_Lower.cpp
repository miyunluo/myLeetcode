// Forward declaration of guess API.
// @param num, your guess
// @return -1 if my number is lower, 1 if my number is higher, otherwise return 0
int guess(int num);

class Solution {
public:
    int guessNumber(int n) {
        int maxx = n, minn = 1;
        for(;;)
        {
        	int mid = minn + (maxx - minn) / 2;
        	int res = guess(mid);
        	if(res == 0) return mid;
        	else if (res == 1) minn = mid +1;
        	else maxx = mid-1;
        }
    }
};