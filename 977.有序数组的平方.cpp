/*
 * @lc app=leetcode.cn id=977 lang=cpp
 *
 * [977] 有序数组的平方
 */

// @lc code=start
class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int> sortnums;
        for(vector<int>::iterator it = nums.begin(); it != nums.end(); it++)
        {
            sortnums.push_back((*it)*(*it));
        }
        sort(sortnums.begin(),sortnums.end());
        return sortnums;
    }
};
// @lc code=end

