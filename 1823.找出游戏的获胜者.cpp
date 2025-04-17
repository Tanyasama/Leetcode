/*
 * @lc app=leetcode.cn id=1823 lang=cpp
 *
 * [1823] 找出游戏的获胜者
 */

// @lc code=start
class Solution {
    public:
        int findTheWinner(int n, int k) {
            struct Node {
                Node(int val = 0): val_(val), next_(nullptr) {}
                int val_;
                Node* next_;
            };
    
            // 1. 构建环形链表
            Node* head = new Node(1);
            Node* p = head;
            for (int i = 2; i <= n; i++) {
                p->next_ = new Node(i);
                p = p->next_;
            }
            p->next_ = head;  // 形成环
    
            // 2. 模拟游戏过程
            Node* Current = p; // 从尾巴开始，这样 Current->next_ = head
            while (Current->next_ != Current) {
                for (int i = 1; i < k; ++i) {
                    Current = Current->next_;
                }
                Node* deleteNode = Current->next_;
                Current->next_ = deleteNode->next_;
                delete deleteNode;
            }
    
            int winner = Current->val_;
            delete Current;
            return winner;
        }
    };
    
    
  


    

// @lc code=end

