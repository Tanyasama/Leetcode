/*
 * @lc app=leetcode.cn id=20 lang=cpp
 *
 * [20] 有效的括号
 */

// @lc code=start
class Solution {
public:
    bool isValid(string s) {
        stack<char> stk;

        for(char c : s)
        {
            if(c == '(' || c == '{' || c == '[')
            {
                stk.push(c);
            }

            else if(c == ')' || c == '}' || c == ']')
            {
                if(stk.empty())
                {
                    return false;
                }

                char top = stk.top();
                stk.pop();

                if((top=='(' && c!=')') ||
                   (top=='{' && c!='}') ||
                   (top=='[' && c!=']'))
                {
                    return false;
                }
            }
        }

        return stk.empty();
    }
};
// @lc code=end

