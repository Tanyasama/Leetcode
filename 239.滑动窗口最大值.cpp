/*
 * @lc app=leetcode.cn id=239 lang=cpp
 *
 * [239] 滑动窗口最大值
 */

// @lc code=start
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        /** 
        vector<int> max_vector;

        for(int i = 0; i <= nums.size()-k; i++)
        {
            int maxval = nums[i];

            for(int j=1;j < k;j ++)
            {
                if(nums[i+j]>=maxval)
                {
                    maxval=nums[i+j];
                }
            }
            max_vector.push_back(maxval);
        }

        return max_vector;**/

    vector<int> res;
    deque<int> dq;
    
    for(int i = 0; i < nums.size(); i ++)
    {
        while(!dq.empty() && dq.front() <= i - k)
        {
            dq.pop_front();
        }

        while(!dq.empty() && nums[dq.back()] < nums[i])
        {
            dq.pop_back();
        }

        dq.push_back(i);

        if(i >= k - 1)
        {
            res.push_back(nums[dq.front()]);
        }
    }

    return res;
    }
};
// @lc code=end

