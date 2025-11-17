/*
 * @lc app=leetcode.cn id=232 lang=cpp
 *
 * [232] 用栈实现队列
 */

// @lc code=start
class MyQueue {
private:
    stack<int> stack1;
    stack<int> stack2;

public:
    MyQueue() {
        
    }
    
    void push(int x) {
        stack1.push(x); //将元素 x 推入到 stack1 中
    }
    
    int pop() {
        if(stack2.empty())
        {
            // 如果 stack2 为空，将 stack1 中的元素转移到 stack2
            while(!stack1.empty())
            {
                stack2.push(stack1.top());
                stack1.pop();
            }
        }   

        int front = stack2.top(); //获取队列的头部元素
        stack2.pop(); // 移除队列头部元素
        return front;
    }
    
    int peek() {
        if(stack2.empty())
        {
            // 如果 stack2 为空，将 stack1 中的元素转移到 stack2
            while(!stack1.empty())
            {
                stack2.push(stack1.top());
                stack1.pop();
            }
        }

        return stack2.top();  //返回队列的头部元素
    }
    
    bool empty() {
        return stack1.empty() && stack2.empty(); // 当两个栈都为空时，队列为空
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */
// @lc code=end

