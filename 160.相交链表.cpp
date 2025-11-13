/*
 * @lc app=leetcode.cn id=160 lang=cpp
 *
 * [160] 相交链表
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
/**class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if (!headA || !headB) return nullptr;

        ListNode* pA = headA;
        ListNode* pB = headB;

        while (pA != pB) {
            pA = pA ? pA->next : headB;
            pB = pB ? pB->next : headA;
        }

        return pA; // 如果相交返回节点，否则 nullptr
    }
};**/

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {

        ListNode* dummya = new ListNode(0);
        ListNode* dummyb = new ListNode(0);

        dummya->next = headA;
        dummyb->next = headB;

        while(headA != nullptr)
        {
            while(headB != nullptr)
            {
                if(headA == headB)
                    return headA;
                else
                    headB = headB->next;
            }
            headA = headA->next;
            headB = dummyb->next;
        }
        return NULL;
    }
};
// @lc code=end

