#include <iostream>
using namespace std;
template<typename T>
class Node
{
friend class LinkedList;
friend class Queue;
private:
	T data;
	T* next;
	T* prev;
public:
	Node(T* _data)
	{
		data = _data;
		next = nullptr;
		previous = nullptr;
	}
};

template <typename T>
class LinkedList
{
friend class Queue;
friend class Node;
private:
	Node* head;
	Node* tail;
public:
	LinkedList()
	{
		head = nullptr, tail = nullptr;
	}
	bool isEmpty()
	{
		return head == false;
	}
	const T front() const
	{
		if (this->isEmpty())
		{
			cout << "Error: Empty!!!" << endl;
			return -1;
		}
		return head->data;
	}
	const T back() const
	{
		if (this->isEmpty())
		{
			cout << "Error: Empty!!!" << endl;
			return -1;
		}
		return tail->data;
	}
	void push_back(const &T added)
	{
		Node* addedNode = new Node(added);
		tail->next = addedNode;
		addedNode->previous = tail;
		tail = added;

	}
	void push_front(const& T added)
	{
		Node* addedNode = new Node(added);
		if (!head)
		{
			head = addedNode;
			return;
		}
		head->previous = addedNode;
		addedNode->next = head;
		head = addedNode;
	}
	void pop_front()
	{
		Node* temp = head;
		head = head->next;
		delete temp;
		temp = nullptr;
	}
	void pop_back()
	{
		Node* temp = tail;
		tail = tail->previous;
		delete temp;
		temp = nullptr;
	}

};
template <typename T>
class Queue
{
	friend class LinkedList;
private:
	LinkedList ll;
	int capacity;
	int size;
public:
	Queue(int capacity)
	{
		this->capacity = capacity;
		LinkedList* linkedList = new LinkedList();
		size = 0;
	}
	int giveSize()
	{
		return this->size;
	}
	int giveCapacity()
	{
		return this->capacity;
	}
	void doubleCapacity()
	{
		capacity *= 2;
	}
	void shrinkCapacity()
	{
		capacity /= 2;
	}
	bool isEmpty()
	{
		return ll->isEmpty();
	}
	const T& front() const
	{
		return ll->front();
	}
	const T& back() const
	{
		return ll->back();
	}
	void enqueue()
	{
		if (size + 1 > capacity / 2)
		{
			this->expandCapacity();
		}
		ll->push_front();
	}
	void dequeue()
	{
		if (this->size - 1 < capacity / 2)
		{
			this->shrinkCapacity();
		}
		ll->pop_front();
	}

};
int main()
{

}