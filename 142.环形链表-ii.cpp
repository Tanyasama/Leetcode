/*
 * @lc app=leetcode.cn id=142 lang=cpp
 *
 * [142] 环形链表 II
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
    if(!head || !head->next) return nullptr;
    
    ListNode* fast = head;
    ListNode* slow = head;

    while(fast && fast->next)
    {
        fast = fast->next->next;
        slow = slow->next;

        if(fast == slow)
        {
            ListNode* p1 = head;
            ListNode* p2 = slow;

            while(p1 != p2)
            {
                p1 = p1->next;
                p2 = p2->next;
            }
            return p1;
        }
    }
    return nullptr;
    }
};
// @lc code=end

