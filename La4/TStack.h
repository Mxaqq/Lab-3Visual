#ifndef TSTACK_H
#define TSTACK_H

class TStack {
private:
    class TNode {
    public:
        int data;
        TNode* pNext;

        TNode(int value)
            : data(value), pNext(nullptr) {
        }
    };

    TNode* pHead;

public:
    TStack();
    ~TStack();

    bool IsEmpty() const;
    void Push(int value);
    int Top() const;
    void Pop();
};

#endif 