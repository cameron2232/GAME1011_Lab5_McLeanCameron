#pragma once
#ifndef DYNINTSTACK_H
#define DYNINTSTACK_H
#include "iostream"
#include <cstdlib>
#include <vector>

template<typename T>
class DynTempStack
{
private:
    class StackNode
    {
        friend class DynTempStack;
        T value;
        StackNode* next;
        // Constructor
        StackNode(T value1, StackNode* next1 = NULL)
        {
            value = value1;
            next = next1;
        }
    };
    StackNode* top;
    std::vector <T> StackNodeVector;
public:
    DynTempStack() { top = NULL; }
	
    void push(T type)
    {
        top = new StackNode(type, top);
        StackNodeVector.push_back(type);
        printStack();
    }

    void pop(T& type)
    {
        StackNode* temp;

        if (isEmpty())
        {
            std::cout << "The stack is empty.\n";
            exit(1);
        }
        else   // Pop value off top of stack
        {
            type = top->value;
            temp = top;
            top = top->next;
            delete temp;
            StackNodeVector.pop_back();
            printStack();
        }
    }

    bool isEmpty() const
    {
        if (!top)
            return true;
        else
            return false;
    }
    void printStack()
    {
        std::cout << "[";
        for (int i = 0; i < StackNodeVector.size(); i++)
        {
            if (i < StackNodeVector.size() - 1)
                std::cout << StackNodeVector[i] << ", ";
            else  std::cout << StackNodeVector[i];

        }
        std::cout << "]" << std::endl;
    }
};
#endif