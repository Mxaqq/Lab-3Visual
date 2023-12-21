#ifndef TQUEUE_H
#define TQUEUE_H

class TQueue {
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
    TNode* pTail;

public:
    TQueue();
    ~TQueue();

    bool IsEmpty() const;
    void Enqueue(int value);
    int Front() const;
    void Dequeue();
};

#endif 