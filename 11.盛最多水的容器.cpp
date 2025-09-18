/*
 * @lc app=leetcode.cn id=11 lang=cpp
 *
 * [11] 盛最多水的容器
 */

// @lc code=start
class Solution {
public:
    int maxArea(vector<int>& height) {
    //     int n = height.size();
    //     int maxwater = 0;
    //     for(int i = 0;i < n;i ++)
    //     {
    //         for(int j = i+1;j < n;j ++)
    //         {
    //             int h = min(height[i],height[j]);
    //             int area = (j-i)*h;
    //             maxwater = max(maxwater,area);
    //         }
    //     }
    //     return maxwater;
    // }

    int left = 0;
    int right = height.size()-1;
    int maxwater = 0;


    while (left < right)
    {
        int h = min(height[left],height[right]);
        int area = h*(right-left);
        maxwater = max(maxwater,area);
        
        if(height[left]<height[right])
        {
            left++;
        }
        else
        {
            right--;
        }
    }
    return maxwater;
    }
};
// @lc code=end
