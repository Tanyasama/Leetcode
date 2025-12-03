/*
 * @lc app=leetcode.cn id=151 lang=cpp
 *
 * [151] 反转字符串中的单词
 */

// @lc code=start
class Solution {
public:
    string reverseWords(string s) {
        //去除前导和尾随的空格
        int start = 0, end = s.size() - 1;

        //去除前导空格
        while(start <= end && s[start] == ' ')
        {
            start++;
        }

        //去除尾随空格
        while(start <= end && s[end] == ' ')
        {
            end--;
        }

        vector<string> words;
        string word;
        
        for(int i = start; i <= end; i++)
        {
            if(s[i] != ' ')
            {
                word += s[i];
            }
            else if(!word.empty())
            {
                words.push_back(word);
                word.clear();
            }
        }

        if(!word.empty())
        {
            words.push_back(word);
        }


        reverse(words.begin(),words.end());

        string result = "";
        for(int i = 0; i < words.size(); i ++)
        {
            result += words[i];
            if(i != words.size() - 1)
            {
                result += " ";
            }
        }

        return result;
    }
};
// @lc code=end

