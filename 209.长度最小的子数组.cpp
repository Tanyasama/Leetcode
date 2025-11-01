/*
 * @lc app=leetcode.cn id=209 lang=cpp
 *
 * [209] 长度最小的子数组
 */

// @lc code=start
class Solution {
public:
//滑动窗口
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        int left = 0,minlen=n+1,sum=0;

        for(int right = 0; right < n; right++)
        {
            sum += nums[right];
            
            while(sum>=target)
            {
                minlen=min(minlen,right-left+1);
                sum -= nums[left];
                left++;
            }
        }

        if(minlen==n+1)
            return 0;
        else
            return minlen;
    }
};
// @lc code=end

