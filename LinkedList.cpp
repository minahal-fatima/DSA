#include <iostream>

using namespace std;

/** Data element of linked list */
class Node
{
private:
	int data;	/** holds data in a node */
	Node* next;	/** keeps a reference of the next node */

public:
	Node(int data, Node* next)
	{
		this->data = data;
		this->next = next;
	}
		
	friend class List;
};

/** Manages collection of nodes in a linked list */
class List
{
private:
	Node* head;		/** holds the first node of the linked list */

public:
	/** creates an empty list */
	List() : head{ NULL } 
	{}
	
	//destructor, complete its implementation
	/** deallocates linked list from memory */ 
	~List()
	{
		Node* cur = head;

		while (head)
		{
			head = head->next;
			
			delete cur;

			cur = head;			
		}
	}

	/** list is empty or not */
	bool isEmpty() const 
	{
		return (!head);
	}

	/** insertes an item at the end of linked list */
	void insertAtEnd(int item)
	{
		Node* newNode = new Node(item, NULL);

		if (!head)					//if list is empty
		{
			head = newNode;
		}
		else						//if list contains nodes
		{
			Node* curNode = head;

			while (curNode->next != NULL)
				curNode = curNode->next;

			curNode->next = newNode;
		}

		cout << "Node inserted successfully at the end." << endl;
	}

	//complete its implementation
	/** insertes an item at the beginning of the linked list */
	void insertAtStart(int item)
	{

	}

	//complete its implementation. if oldItem does not exist, give appropriate error message and do nothing
	/** inserts a newItem before the oldItem */
	void insertBefore(int oldItem, int newItem)
	{

	}

	//complete its implementation. if oldItem does not exist, give appropriate error message and do nothing
	/** inserts a newItem after the oldItem. */
	void insertAfter(int oldItem, int newItem)
	{

	}

	/** removes the last item from the linked list */
	void removeLast()
	{
		if (!head)
		{
			cout << "List is empty." << endl;
		}
		else
		{
			if (head->next == NULL)
			{
				delete head;
				head = NULL;
			}
			else
			{
				Node* preNode = head;		//holds first node
				Node* curNode = head->next;	//holds second node, if any
				
				while (curNode->next != NULL)
				{
					preNode = curNode;
					curNode = curNode->next;
				}

				delete curNode;
				preNode->next = NULL;
			}

			cout << "Last node removed successfully." << endl;
		}
	}

	//complete its implementation
	/** removes the first node of the linked list */
	void removeFirst()
	{
		
	}

	//complete its implementation. Give appropriate error message item does not exist.
	/** removes an item of the linked list. */
	void removeItem(int item)
	{
		
	}

	/** display the contents of entire list */
	void display() const
	{
		if (!head)
			cout << "List is empty." << endl;
		else
		{
			Node* curNode = head;

			while (curNode != NULL)
			{
				cout << curNode->data << endl;
				curNode = curNode->next;
			}
		}
	}

	//complete its implementation.
	/** finds an item in the linked list and returns its address, returns NULL, otherwise */
	Node* find(int item) const
	{

	}
};

int main()
{
	List obj;

	obj.insertAtEnd(1);

	obj.insertAtEnd(1);

	obj.insertAtEnd(1);
			

	return 0;
}