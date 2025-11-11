/*
 * @lc app=leetcode.cn id=707 lang=cpp
 *
 * [707] 设计链表
 */

// @lc code=start
class MyLinkedList {
    private:
    struct Node{
        int val;
        Node* next;
        Node(int x):val(x),next(nullptr){};
    };

    Node* dummy;
    int size;

    public:
    MyLinkedList() {
        dummy =new Node(0);
        size = 0;
    }
    
    int get(int index) {
        if(index < 0 || index >= size) return -1;

        Node* cur = dummy->next;
        for(int i = 0; i < index; i++)
        {
            cur = cur->next;
        }
        return cur->val;
    }
    
    void addAtHead(int val) {
         addAtIndex(0,val);   
    }
    
    void addAtTail(int val) {
        addAtIndex(size,val);
    }
    
    void addAtIndex(int index, int val) {
        if(index > size) return;
        if(index < 0) return;

        Node* cur = dummy;
        for(int  i = 0;i < index; i++)
        {
            cur = cur->next;
        }

        Node* nnode = new Node(val);
        nnode->next = cur->next;
        cur->next = nnode;

        size++;
    }
    
    void deleteAtIndex(int index) {
        if(index < 0 || index >= size) return;

        Node* cur = dummy;
        for(int  i = 0;i < index; i++)
        {
            cur = cur->next;
        }

        Node* todelete = cur->next;
        cur->next = todelete->next;

        delete todelete;

        size--;
    }
    ~MyLinkedList(){
        Node* cur = dummy;
        while(cur != nullptr)
        {
            Node* temp = cur;
            cur = cur->next;
            delete temp;
        }
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */
// @lc code=end

