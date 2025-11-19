/*
 * @lc app=leetcode.cn id=541 lang=cpp
 *
 * [541] 反转字符串 II
 */

// @lc code=start
class Solution {
public:
    string reverseStr(string s, int k) {
        int n = s.size();
        
        for(int i = 0;i < n; i += 2*k)
        {
            int right = min(i+k-1,n-1);
            int left = i;

            while(left<right)
            {
                swap(s[left],s[right]);
                left++;
                right--;
            }
        }

        return s;
    }
};
// @lc code=end

