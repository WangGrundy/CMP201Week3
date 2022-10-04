// William Kavanagh, CMP201 lab 3, partial implementation

#include "LinkedList.h"
#include <iostream>

// default Constructor
template <class T>
LinkedList<T>::LinkedList()
{
	LinkedList::head = nullptr;
}

// Single element constructor set head to new Node(n)
template<class T>
LinkedList<T>::LinkedList(T n)
{
	head = new Node<T>(n);
	head->next = head;
	head->prev = head;
}

template<class T>
LinkedList<T>::~LinkedList()
{
}

// Insertion, append to LL, update references.
template<class T>
void LinkedList<T>::Insert(T n)
{
	// TODO: Assessed, 1 mark
	//		0.5 marks for forward referencing (i.e. ->next is correct)
	//		0.5 marks for backward referencing (i.e. ->prev is correct)

	// case: nothing in ll
	if (head == nullptr) {

		head = new Node<T>(n);
		head->data = n;
		head->next = head;
		head->prev = head;

		return;
	}

	// case: something inside ll
	Node<T>* current = head; //checkpoint

	while (current->next != head) { //traverse through ll to find tail
		
		current = current->next;
	}

	//The BIG 4
	Node<T>* newTail = new Node<T>(n); //simple brain lol
	//node
	newTail->next = head;
	newTail->prev = current;
	//current
	current->next = newTail;
	//head
	head->prev = newTail;

}

// Removal, delete first element found matching param, update references
template<class T>
void LinkedList<T>::Remove(T n)
{
	//	TODO: Assessed, 2 marks
	//		1 mark for removal of the head
	//			0.5 marks for correct head assignment
	//			0.5 marks for correct reference updating
	//		1 mark for removal from after head
	//			0.5 marks for correct forward referencing (i.e. ->next is correct)
	//			0.5 marks for correct backward referencing (i.e. ->prev is correct)

	//if its a lone node
	if (head->next == head) {
		head->next = nullptr; 
		head->prev = nullptr; 
		head = nullptr; 
		return;
	}

	//removal of the head with a body
	if (head->data == n) {
		std::cout << "removing " << head->data << std::endl;
		Node<T>* tail = head->prev;
		Node<T>* newHead = head->next; //set new head
		newHead->prev = tail; //decapitate old head
		tail->next = newHead; //put the nail in the coffin
		head = newHead; //leave no evidence
		return;
	}

	//removal of the body
	if (head != nullptr) { //sanity check
		Node<T>* current = head;
		while (current->next->data != n) {
			current = current->next;
		}
		//next node is our target
		Node<T>* replacementNode = current->next->next;
		current->next = replacementNode;
		replacementNode->prev = current;
	}
	
	
}

// Return element at position indexed by param <index>
template<class T>
Node<T>* LinkedList<T>::Get(int index)
{
	if (index == 0) return head;
	Node<T>* temp = head;
	for (int i = 0; i < index; i++)
	{
		temp = temp->next;
	}
	return temp;
}


// Flip the order of all elements in the LL such that head becomes the tail.
template<class T>
void LinkedList<T>::Reverse()
{
	// TODO: Assessed, 2 marks
	//		1 mark for test with ints
	//		1 mark for test with std:strings

	if (head->next == head) { //sanity check
		return;
	}

	Node<T>* nextNode = nullptr;
	Node<T>* current = head;
	Node<T>* tail = head->prev;

	do{ //loop through entire list to find head again
		nextNode = current->next; //set next node to head
		current->next = current->prev;
		current->prev = nextNode;
		current = nextNode;

	} while (current != head);
	head = tail;
}

// return count of elements in LL
template<class T>
int LinkedList<T>::Size()
{
	if (!head) return 0;
	Node<T>* temp = head;
	int count = 1;
	while (temp->next != head)
	{
		temp = temp->next;
		count++;
	}
	return count;
}

// Convert all elements into a vector 
template<class T>
std::vector<T> LinkedList<T>::ToVector()
{
	std::vector<T> returnVector;
	if (!head) return returnVector;
	Node<T>* temp = head;
	for (int i = 0; i < Size(); i++)
	{
		returnVector[i] = temp->data;
		temp = temp->next;
	}
	return returnVector;
}

// Return pointer to the tail 
template<class T>
Node<T>* LinkedList<T>::GetTail()
{
	if (!head) return nullptr;
	return head->prev;
}


// A generic toString (numeric types typically)
template<class T>
std::string LinkedList<T>::ToString()
{
	std::string returnString = "[";
	Node<T>* t = head;
	while (t)
	{
		returnString += std::to_string(t->data);
		// comma if there is more to come.
		if (t->next != head)
		{
			returnString += ", ";
		}
		else
		{
			break;	// we're done, leave.
		}
		t = t->next;
	}
	return returnString + "]\n";	// end and newline.
}

// specific toString for ll<std::string> 
template <>
std::string LinkedList<std::string>::ToString()
{
	std::string returnString = "[";
	Node<std::string>* t = head;
	while (t)
	{
		returnString += t->data;

		// comma if there is more to come.
		if (t->next != head)
		{
			returnString += ", ";
		}
		else
		{
			break;	// we're done, leave.
		}
		t = t->next;
	}
	return returnString + "]\n";	// end and newline.
}

// specific toString for ll<char> 
template <>
std::string LinkedList<char>::ToString()
{
	std::string returnString = "[";
	Node<char>* t = head;
	while (t)
	{
		returnString += t->data;

		// comma if there is more to come.
		if (t->next != head)
		{
			returnString += ", ";
		}
		else
		{
			break;	// we're done, leave.
		}
		t = t->next;
	}
	return returnString + "]\n";	// end and newline.
}

// Sample main() method for testing.
// Comment out or delete entire method INCLUDING SIGNATURE before submission.
int main()
{
	//// Test 1: Ints and insertion.
	//LinkedList<int>* ll = new LinkedList<int>();	// Make an empty linked list for ints
	//ll->Insert(5);				// insert when empty.
	////std::cout << "expecting [5], got: " << ll->ToString();

	//ll->Insert(10);
	//ll->Insert(20);
	//ll->Insert(10);
	////std::cout << "expecting [5, 10, 20, 10], got: " << ll->ToString();

	//// Test 2: Removal
	//ll->Remove(10);
	//std::cout << "expecting [5, 20, 10], got: " << ll->ToString();

	LinkedList<char>* llChar = new LinkedList<char>('x');	// Make a ll<char>: {x}
	//std::cout << "expecting [x], got: " << llChar->ToString();
	/*llChar->Insert('a');
	llChar->Insert('b');
	llChar->Insert('c');*/

	llChar->Remove('x');	// test removal from head
	//std::cout << "expecting [a, b, c], got: " << llChar->ToString();


	// Test 3: Reversal
	llChar->Insert('a');	// should be empty, add 'a', 'b', 'c'
	llChar->Insert('b');
	llChar->Insert('c');
	std::cout << "expecting [a, b, c], got: " << llChar->ToString();
	llChar->Reverse();		// reverse in place.
	std::cout << "expecting [c, b, a], got: " << llChar->ToString();
}
