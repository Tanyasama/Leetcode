/*
 * @lc app=leetcode.cn id=19 lang=cpp
 *
 * [19] 删除链表的倒数第 N 个结点
 */

// @lc code=start
// /**
//  * Definition for singly-linked list.
//  * struct ListNode {
//  *     int val;
//  *     ListNode *next;
//  *     ListNode() : val(0), next(nullptr) {}
//  *     ListNode(int x) : val(x), next(nullptr) {}
//  *     ListNode(int x, ListNode *next) : val(x), next(next) {}
//  * };
//  */

// struct ListNode {
//     int val;
//     ListNode *next;
//     ListNode() : val(0), next(nullptr) {}
//     ListNode(int x) : val(x), next(nullptr) {}
//     ListNode(int x, ListNode *next) : val(x), next(next) {}
// };

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* p = head;
        ListNode* q = head;
        ListNode* pre = nullptr;

        for(int i = 0;i < n;i ++)
        {
            p = p->next;
        }

        if(p == nullptr)
        {
            ListNode* temp = head;
            head = head->next;
            delete temp;
            return head;
        }

        while(p != nullptr)
        {
            p = p->next;
            pre = q;
            q = q->next;
        }

        pre->next = q->next;
        return head;
    }
};
// @lc code=end

