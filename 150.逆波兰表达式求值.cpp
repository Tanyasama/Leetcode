/*
 * @lc app=leetcode.cn id=150 lang=cpp
 *
 * [150] 逆波兰表达式求值
 */

// @lc code=start
// #include<iostream>
// using namespace std;
// #include<stack>
// #include<vector>
// #include <cstdlib>


class Solution {
    public:
        int evalRPN(vector<string>& tokens) {
            
            stack<int>st;
            for(const string& token : tokens)
            {
                if(token == "+" || token == "-" || token == "*" || token == "/" )
                {
                    int right = st.top();st.pop();
                    int left = st.top();st.pop();
                    int result;
                    if(token == "+")result = right + left;
                    else if(token == "-")result = left - right;
                    else if(token == "*")result = left * right;
                    else
                        result = left / right;
                    st.push(result);
                }
                else
                {
                    st.push(stoi(token));
                }
            }
            return st.top();
        }
    };
// @lc code=end

