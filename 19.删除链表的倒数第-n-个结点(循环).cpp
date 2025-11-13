/*
 * @lc app=leetcode.cn id=19 lang=cpp
 *
 * [19] 删除链表的倒数第 N 个结点
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* dummy = new ListNode(0);
        dummy->next = head;

        ListNode* left = dummy;
        ListNode* right = head;
        int size = 0;

        while(right != nullptr)
        {
            right = right->next;
            size ++;
        }

        for(int i=0;i<size-n;i++)
        {
            left = left->next;
        }

        ListNode* temp = left->next;
        left->next = temp->next;
        delete temp;

        ListNode* newHead = dummy->next;
        delete dummy;

        return newHead;
    }
};
// @lc code=end

