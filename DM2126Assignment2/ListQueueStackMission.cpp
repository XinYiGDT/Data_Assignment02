#include "DetectMemoryLeak.h"
#include "Node.h"
#include "LinkedList.h"
#include "Stack.h"
#include "Queue.h"

#include <string>
#include <vector>
#include <list>
#include <map>
#include <stack>
#include <queue>

using std::string;
using std::vector;
using std::list;
using std::map;
using std::stack;
using std::queue;

// DO NOT MODIFY ANY LINE ABOVE OR ADD EXTRA INCLUDES

/*! 
 *  \brief     DM2126 Assignment 2
 *  \details   Submit the whole solution, but only this file will be used to grade
 *  \author    <Lim Xin Yi>
 *  \date      2016 
 *  \note      <163935T>
 */

//*******************************************************************//
// Linked list stuff
//*******************************************************************//
LinkedList::LinkedList() : head_(0)
{
}

LinkedList::~LinkedList()
{ 
	while (head_ == NULL)
		pop_back();
}

void LinkedList::push_front(int data)
{
	Node* newNode = new Node(data);

	if (head_ == NULL)
	{
		head_ = newNode;
		return;
	}

	newNode->next = head_;
	head_ = newNode;
}

void LinkedList::push_back(int data)
{
	Node* newNode = new Node(data);

	if (head_ == NULL)
	{
		head_ = newNode;
		return;
	}
	else
	{
		Node* end = head_;
		while (end->next != NULL)
		{
			end = end->next;
		}
		end->next = newNode;
	}

}

int LinkedList::pop_front()
{
	if (head_ == NULL)
	{
		return 0;
	}

	Node* curr = head_;
	
	head_ = curr -> next;

	int value = curr->data;

	delete curr;

	return value;

    
}

int LinkedList::pop_back()
{    
	if (head_ == NULL)
	{
		return 0;
	}

	Node* curr = head_;
	Node* prev = 0;
	while (curr->next != NULL)
	{
		prev = curr;
		curr = curr->next;
	}
	int value = curr->data;

	delete curr;

	if (prev == NULL)
		head_ = 0;
	else
		prev->next = NULL;

	return value;
}

void LinkedList::insert_at(int pos, int data)
{
	Node* newNode = new Node(data);

	if (head_ == NULL || pos <= 0)
	{
		newNode->next = head_;
		head_ = newNode;
		return;
	}

	Node* curr = head_;
	Node* prev = NULL; 
	int position = 0;

	while (curr)
	{
		if (position == pos)
		{
			prev->next = newNode;
			newNode->next = curr;
			return;
		}

		prev = curr;
		curr = curr->next;
		position++;
	}
}

int LinkedList::pop_at(int pos)
{
	if (head_ == NULL)
	{
		return 0;
	}

	Node* prev = 0;
	Node* curr = head_;
	int index = 0;

	if (pos <= 0)
	{
		head_ = curr->next;
		int value = curr->data;
		delete curr;
		return value;
	}

	while (curr && index != pos)
	{
		prev = curr;
		curr = curr->next;
		index++;
	}
    
	int value = curr->data;
	prev->next = curr->next;


	delete curr;
	return value;
}

size_t LinkedList::size()
{
    return 0;
}

//*******************************************************************//
// Queue stuff
//*******************************************************************//
Queue::Queue() 
{
}

Queue::~Queue()
{   
}

void Queue::enqueue(int data)
{   
}

int Queue::dequeue()
{
    return 0;
}

size_t Queue::size()
{
    return 0;
}

//*******************************************************************//
// Stack stuff
//*******************************************************************//
Stack::Stack()
{

}

Stack::~Stack()
{
}

void Stack::push(int data)
{
}

int Stack::pop()
{
    return 0;
}

size_t Stack::size()
{
    return 0;
}



// Balanced parenthesis
bool Brackets(const string& input)
{
    return true;
}

// Query machine, hits
void QueryMachine(vector<int>& data, vector<int>& queries, vector<unsigned int>& results)
{
}