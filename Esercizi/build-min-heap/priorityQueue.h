#ifndef PRIORITYQUEUE_H
#define PRIORITYQUEUE_H

template <typename T>
class PriorityQueue
{
public:
    virtual T *extract() = 0;
    virtual PriorityQueue<T> *enqueue(T x) = 0;
    virtual double compare(T *a, T *b) = 0;
    virtual void printKey(int i) const = 0;
};
#endif