/*
 * @lc app=leetcode.cn id=459 lang=cpp
 *
 * [459] 重复的子字符串
 */

// @lc code=start
class Solution {
public:
    bool repeatedSubstringPattern(string s) {
      /*方法1：
      string doubled = s + s;
      return doubled.substr(1,(doubled.size() - 2)).find(s) != string::npos;
      */
      
      //方法二：KMP   不是很懂
        int n = s.size();
        vector<int> prefix(n,0);

        //计算前缀
        for(int i = 1; i < n; i++)
        {
            int j = prefix[i-1];

            while(j > 0 && s[i] != s[j])
            {
                j = prefix[j-1];
            }

            if(s[i] == s[j])
            {
                j++;
            }

            prefix[i] = j;
        }

        int len = prefix[n-1];
        return len > 0 && n % (n - len) == 0;
    }
};
// @lc code=end

