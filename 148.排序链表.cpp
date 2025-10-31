/*
 * @lc app=leetcode.cn id=148 lang=cpp
 *
 * [148] 排序链表
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
    ListNode* sortList(ListNode* head) {
        if (!head || !head->next) return head; 

        vector<int> vals;
        ListNode* p = head;
        while (p) {
            vals.push_back(p->val);
            p = p->next;
        }

        sort(vals.begin(), vals.end());
        p = head;
        for (int v : vals) {
            p->val = v;
            p = p->next;
        }

        return head;
    }
};

// @lc code=end

