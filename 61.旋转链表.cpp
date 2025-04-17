/*
 * @lc app=leetcode.cn id=61 lang=cpp
 *
 * [61] 旋转链表
 */

// @lc code=start


// struct ListNode {
//     int val;
//     ListNode *next;
//     ListNode() : val(0), next(nullptr) {}
//     ListNode(int x) : val(x), next(nullptr) {}
//     ListNode(int x, ListNode *next) : val(x), next(next) {}
// };

class Solution {
    public:
        ListNode* rotateRight(ListNode* head, int k) {
            ListNode* p = head;
            int length = 1;
            
            if (!head || !head->next || k == 0) return head;
            
            while(p->next != nullptr)
            {
                p = p->next;
                length++ ;
            }


            if(k % length == 0)
            {
                return head;
            }

            
            ListNode * fast = head;
            ListNode * slow = head;
    
            ListNode * pre  = nullptr;
    
            for(int i = 0;i < k % length;i ++)
            {
                fast = fast->next;
            }
    
            while(fast != nullptr)
            {
                fast = fast->next;
                pre = slow;
                slow = slow->next;
            }
    
            pre->next = nullptr;
            p->next = head;
            return slow;
        }
    };
// @lc code=end

