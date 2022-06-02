#include <stdexcept>
#ifndef QUEUE_H
#define QUEUE_H
class Queue
{
    int elements;
    int capacity;
    int *mem;
    int first;

public:
    Queue() : elements(0), capacity(10), mem(new int[capacity]), first(0) {}
    ~Queue()
    {
        delete[] mem;
    }

    Queue(const Queue &original) : capacity(original.capacity), elements(original.elements), first(original.first), mem(new int[original.capacity])
    {
        for (int i = 0; i < elements; ++i)
        {
            mem[i] = original.mem[i];
        }
    }

    Queue &operator=(const Queue &original)
    {
        if (this != &original)
        {
            if (this != nullptr)
            {
                delete[] mem;
            }
            capacity = original.capacity;
            elements = original.elements;
            first = original.first;
            mem = new int[original.capacity];
            for (int i = 0; i < elements; ++i)
            {
                mem[i] = original.mem[i];
            }
        }
        return *this;
    }

    void push(int x)
    {
        if (elements == capacity)
        {
            int *new_mem = new int[capacity * 2];
            for (int i = 0; i < elements; ++i)
            {
                new_mem[i] = mem[(first + i) % capacity];
            }
            delete[] mem;
            mem = new_mem;
            capacity *= 2;
            first = 0;
        }
        int insert_location = (first + elements) % capacity;
        mem[insert_location] = x;
        elements++;
    }

    void pop()
    {
        if (elements == 0)
        {
            throw std::runtime_error("Queue is empty");
        }
        first = (first + 1) % capacity;
        elements--;
    }
    bool empty()
    {
        return elements == 0;
    }

    int front()
    {
        if (elements == 0)
        {
            throw std::runtime_error("Queue is empty");
        }
        return mem[first];
    }
};

#endif
