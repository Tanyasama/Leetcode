/*
 * @lc app=leetcode.cn id=15 lang=cpp
 *
 * [15] 三数之和
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> v;
        sort(nums.begin(),nums.end());

        for(int i = 0;i< nums.size();i ++)
        {
            if (i > 0 && nums[i] == nums[i - 1]) continue;

            int left = i+1;
            int right = nums.size()-1;

            while(left<right)
            {
                if(nums[i]+nums[left]+nums[right]==0)
                {
                    v.push_back({nums[i],nums[left],nums[right]});
                
                    while (left < right && nums[left] == nums[left + 1]) left++;
                    while (left < right && nums[right] == nums[right - 1]) right--;

                    left++;
                    right--;
                }
                else if(nums[i]+nums[left]+nums[right]<0)
                {
                    left++;
                }
                else
                {
                    right--;
                }
            }
        }
        return v;
    };
};
// @lc code=end

