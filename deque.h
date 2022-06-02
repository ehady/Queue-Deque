#include <stdexcept>
#ifndef DEQUE_H
#define DEQUE_H
class Deque
{
    int capacity;
    int elements;
    int *mem;
    int first;

public:
    Deque() : capacity(10), elements(0), mem(new int[capacity]), first(0) {}
    ~Deque() { delete[] mem; }

    Deque(const Deque &original) : capacity(original.capacity), elements(original.elements), first(original.first), mem(new int[original.capacity])
    {
        for (int i = 0; i < elements; ++i)
        {
            mem[i] = original.mem[i];
        }
    }
    Deque &operator=(const Deque &original)
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
            return *this;
        }
    }

    void push_back(int x)
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

    void push_front(int x)
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
        first = (first - 1 + capacity) % capacity;
        mem[first] = x;
        ++elements;
    }
    bool empty()
    {
        return elements == 0;
    }
    void pop_front()
    {
        if (elements == 0)
        {
            throw std::runtime_error("Deque is empty");
        }
        elements--;
    }
    int back()
    {
        if (elements == 0)
        {
            throw std::runtime_error("Deque is empty");
        }
        return mem[(first + elements - 1) % capacity];
    }
    int front()
    {
        if (elements == 0)
        {
            throw std::runtime_error("Deque is empty");
        }
        return mem[first];
    }
};
#endif