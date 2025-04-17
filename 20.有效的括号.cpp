/*
 * @lc app=leetcode.cn id=20 lang=cpp
 *
 * [20] 有效的括号
 */

// @lc code=start
// #include<iostream>
// using namespace std;
// #include<stack>
class Solution {
public:
    bool isValid(string s) {
        stack<char> cs;

        for(char ch : s)
        {
            if(ch == '(' || ch == '[' || ch == '{')
            {
                cs.push(ch);
            }
            else{
                if(cs.empty())
                    return false;
                //遇到右括号
                char cmp = cs.top();
                cs.pop();
                
                if(ch == ')' && cmp != '('
                || ch == ']' && cmp != '[' 
                || ch == '}' && cmp != '{')
                {
                    return false;
                }
            }  
        }
    //栈里面括号没处理完
    return cs.empty();
    }
};
// @lc code=end

