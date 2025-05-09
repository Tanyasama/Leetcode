/*
 * @lc app=leetcode.cn id=141 lang=cpp
 *
 * [141] 环形链表
 */

// @lc code=start

 
//  struct ListNode {
//      int val;
//      ListNode *next;
//     ListNode(int x) : val(x), next(nullptr) {}
//  };

class Solution {
public:
    bool hasCycle(ListNode *head) {
        if(!head || !head->next)
        {
            return false;
        }

        ListNode * slow = head;
        ListNode * fast = head;

        while(fast && fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;
            if(slow == fast) return true;
        }
        return false;
    }
};


// @lc code=end

