/*
 * @lc app=leetcode.cn id=1823 lang=cpp
 *
 * [1823] 找出游戏的获胜者
 */

// @lc code=start
class Solution {
    public:
        int findTheWinner(int n, int k) {
            struct Node
            {
                Node(int val):val_(val),next_(nullptr){}
                int val_;
                Node * next_;
            };
    
            //环形链表
            Node* head = new Node(1);
            Node* p = head;
            for(int i = 2;i <= n;i ++)
            {
                p->next_ = new Node(i);
                p = p->next_;
            }
            p->next_ = head;
    
            //删除元素
            Node* current = p;
            while(current->next_ != current)
            {
                for(int i = 1; i < k;i ++)
                {
                    current = current->next_;
                }
                Node* todelete = current->next_;
                current->next_ = current->next_->next_;
                delete todelete;
            }
    
    
            int winner = current->val_;
            return winner;
        }
    };
// @lc code=end

