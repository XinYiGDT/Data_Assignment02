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
 *  \date      <1/2/2017> 
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
	while (head_ != NULL)
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

	while (curr && position != pos)
	{
		prev = curr;
		curr = curr->next;
		position++;
	}
	newNode->next = curr;
	prev->next = newNode;
	return;
}

int LinkedList::pop_at(int pos)
{
	if (head_ == NULL)
	{
		return 0;
	}

	Node* prev = NULL;
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
	if (head_ == NULL)
	{
		return 0;
	}

	Node* curr = head_;
	int len = 0;

	while (curr)
	{
		len++;
		curr = curr->next;
	}
	return len;
}

//*******************************************************************//
// Queue stuff
//*******************************************************************//
Queue::Queue() :front_(0), back_(0)
{
}

Queue::~Queue()
{   
	while (front_)
		dequeue();
}

void Queue::enqueue(int data)
{   
	Node* curr = new Node(data);

	curr->next = NULL;

	if (front_ == NULL)
	{
		front_ = curr;
		back_ = front_;
		return;
	}
	else
	{

		(back_)->next = curr;
		back_ = curr;
	}
	
}

int Queue::dequeue()
{
	int value = (front_)->data;

	if (front_ == NULL)
	{
		return 0;
	}
	if (front_ == back_)
	{
		back_ = NULL;
	}

	Node* curr = front_;

	front_ = curr->next;
	delete curr;
	return value;
}

size_t Queue::size()
{
	if (front_ == NULL)
	{
		return 0;
	}

	int len = 0;
	Node* curr = front_;

	while (curr)
	{
		len++;
		curr = curr->next;
	}
	return len;
}

//*******************************************************************//
// Stack stuff
//*******************************************************************//
Stack::Stack() :top_(0)
{

}

Stack::~Stack()
{
	while (top_ != NULL)
	{
		pop();
	}
}

void Stack::push(int data)
{
	Node* newNode = new Node(data);
	Node* prev = NULL;
	if (top_ == NULL)
	{
		top_ = newNode;
		return;
	}
	else
	{
		prev = top_;
		top_ = newNode;
		(top_)->next = prev;
	}
	
}

int Stack::pop()
{
	if (top_ == NULL)
	{
		return 0;
	}
	
	int value = 0;

	Node* temp = top_;
	top_ = temp->next;

	value = temp->data;

	delete temp;
	return value;
	
}

size_t Stack::size()
{
	if (top_ == NULL)
	{
		return 0;
	}

	Node* curr = top_;
	int len = 0;

	while (curr)
	{
		len++;
		curr = curr->next;
	}
	return len;
}



// Balanced parenthesis
bool Brackets(const string& input)
{
	stack<char> a;
	
	for (int i = 0; i < input.length(); i++)
	{
		if (input[i] == '(' || input[i] == '{' || input[i] == '[' || input[i] == '<')
		{
			a.push(input[i]);
		}
		else
		{
			if (a.size() == 0)
			{
				return false;
			}
			char top = a.top();
			if (input[i] == ')')
			{
				if (top != '(')
					return false;
			}
			else if (input[i] == ']')
			{
				if (top != '[')
					return false;
			}
			else if (input[i] == '}')
			{
				if (top != '{')
					return false;
			}
			else
			{
				if (top != '<')
					return false;
			}
			a.pop();
		}
	}

		return a.size() == 0;
}

// Query machine, hits
void QueryMachine(vector<int>& data, vector<int>& queries, vector<unsigned int>& results)
{
	map<int, int> a;

	for (int i = 0; i < queries.size(); i++)
	{
		a[queries[i]] = NULL;
	}

	for (int i = 0; i < data.size(); i++)
	{
		if (a.find(data[i]) != a.end())
		{
			a[data[i]]++;
		}
	}

	for (int i = 0; i < queries.size(); i++)
	{
		results.push_back(a[queries[i]]);
	}

}