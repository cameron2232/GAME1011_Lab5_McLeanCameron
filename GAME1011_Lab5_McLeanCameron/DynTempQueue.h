#pragma once
#ifndef DYNINTQUEUE_H
#define DYNINTQUEUE_H
#include "iostream"
#include <cstdlib>
#include <vector>
template<typename T>
class DynTempQueue
{
private:
	class QueueNode
	{
		friend class DynTempQueue;
		T value;
		QueueNode* next;
		QueueNode(T value1, QueueNode* next1 = NULL)
		{
			value = value1;
			next = next1;
		}
	};
	// These track the front and rear of the queue
	std::vector<T> QueueNodeVector;
	QueueNode* front;
	QueueNode* rear;
public:
	// Constructor and Destructor
	DynTempQueue()
	{
		front = NULL;
		rear = NULL;
	}
	~DynTempQueue()
	{
	}

	void enqueue(T type)
	{
		if (isEmpty())
		{
			front = new QueueNode(type);
			rear = front;
			QueueNodeVector.push_back(type);
		}
		else
		{
			rear->next = new QueueNode(type);
			rear = rear->next;
			QueueNodeVector.insert(QueueNodeVector.begin(), type);
		}
		printQueue();
		
	}

	void dequeue(T& type)
	{
		QueueNode* temp;
		if (isEmpty())
		{
			std::cout << "The queue is empty.\n";
			exit(1);
		}
		else
		{
			QueueNodeVector.pop_back();
			type = front->value;
			temp = front;
			front = front->next;
			delete temp;
		}
		printQueue();
	}

	bool isEmpty() const
	{
		if (front == NULL)
			return true;
		else
			return false;
	}

	void clear()
	{
		std::cout << "Cleaning...\n\n\n";
		T value;   // Dummy variable for dequeue

		while (!isEmpty())
			dequeue(value);
	}

	void printQueue()
	{
		std::cout << "[";
		for (int i = 0; i < QueueNodeVector.size(); i++)
		{
			if (i < QueueNodeVector.size() - 1)
				std::cout << QueueNodeVector[i] << ", ";
			else  std::cout << QueueNodeVector[i];

		}
		std::cout << "]" << std::endl;
	}
};
#endif