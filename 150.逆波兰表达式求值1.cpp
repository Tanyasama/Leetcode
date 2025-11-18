/*
 * @lc app=leetcode.cn id=150 lang=cpp
 *
 * [150] 逆波兰表达式求值
 */

// @lc code=start
class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> stk;
        for(auto &c : tokens)
        {

            if(c == "+" || c == "-" || c == "*" || c == "/") //注意是双引号
            {
                int b = stk.top(); stk.pop();
                int a = stk.top(); stk.pop();
                int res = 0;

                if(c == "+") res = a + b;
                else if(c == "-") res = a - b;
                else if(c == "*") res = a * b;
                else if(c == "/") res = a / b;

                stk.push(res);
            }
            else
            {
                stk.push(stoi(c));
            }
        }

        return stk.top();
    }
};
// @lc code=end

