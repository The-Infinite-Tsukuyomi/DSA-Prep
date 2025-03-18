class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
        int n = nums.size(); if(n == 1) return 1;
        int i = 1, j = 1, ans = 1, currLen = 1, uptoSet = nums[1];

        if((nums[0] & nums[1]) == 0)
        {
            i = 0;
            currLen = 2;
            ans = 2;
            uptoSet |= nums[0];
        }

        while(j < n - 1)
        {
            j++;
            if(!(nums[j] & uptoSet))
            {
                uptoSet |= nums[j];
                currLen++;
                ans = max(ans, currLen);
            }
            else
            {
                uptoSet = nums[j];
                currLen = 1;
                i = j - 1;
                if((nums[j] & nums[i]))
                {
                    i = j - 1;
                    j = j;
                    continue;
                }
                while(!(nums[i] & nums[j]))
                {
                    uptoSet |= nums[i];
                    i--;
                    currLen++;
                    ans = max(ans, currLen);
                }
            }
        }

        ans = max(ans, currLen);

        return ans;
    }
};