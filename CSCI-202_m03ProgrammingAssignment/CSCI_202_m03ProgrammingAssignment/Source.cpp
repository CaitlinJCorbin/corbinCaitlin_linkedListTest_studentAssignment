/*	Caitlin J. Corbin	*/
/*	M03 Programming Assignment	*/
/*	"Menu-Driven Linked-List Program	*/
/*	"Optimizations and error-handling are still needed. This program is simulated to add/delete/view a customer */

#include<iostream>
#include <cstdlib>

using namespace std;

// Customer class
class Customer {
public:
	// Data members
	string name;
	string customerID;
	string address;
	string phoneNumber;
	// Constructor
	Customer(string name, string customerID, string address, string phoneNumber) {
		this->name = name;
		this->customerID = customerID;
		this->address = address;
		this->phoneNumber = phoneNumber;
	};
	// Deconstructor
	~Customer() { cout << "Deconstructing Customer. . ." << endl; };
};

// Linked-List Class
class List {
private:
	typedef struct Node {
		string data;
		Node* next;
	}*nodePtr; // This structure lets me change node* to nodePtr
	// Pointers
	nodePtr h;
	nodePtr c;
	nodePtr t;

public:
	// Declaring functions 
	List();
	void addNode(string data);
	void deleteNode(string data);
	void printList();
};

// Declares the pointers for Linked-List to NULL
List::List() {
	h = nullptr; // Head - Start of list
	c = nullptr; // Current
	t = nullptr; // Temporary
};

// Adds nodes to the Linked-List
void List::addNode(string addData) {
	// Sets up the function by declaring pointers
	nodePtr n = new Node;
	n->next = nullptr;
	n->data = addData;

	// Traverses the list and adds a new node
	if (h != NULL) {
		c = h;
		while (c->next != NULL) {
			c = c->next;
		};
		c->next = n;
	}
	// If there is no list, this will start it
	else {
		h = n;
	};
};

// Deletes nodes from the Linked-List
void List::deleteNode(string delNode) {
	// Declares pointers for this function
	nodePtr delPtr = nullptr;
	c = h;
	t = h;
	// Traverses the list
	while (c != NULL && c->data != delNode) {
		t = c;
		c = c->next;
	};
	// Data not found
	if (c == NULL) {
		cout << delNode << " not found\n";
		delete delPtr;
	}
	// Deletes the data
	else {
		delPtr = c;
		c = c->next;
		t->next = c;
		if (delPtr == NULL) {
			h = h->next;
			t = nullptr;
		};
		delete delPtr;
		cout << delNode << " deleted\n";
	};
};

// Prints the elements of a Linked-List
void List::printList() {
	c = h;
	while (c != NULL) {
		cout << c->data << endl;
		c = c->next;
	};
};

// Prints menu of options
int printMenu() {
	int selection = NULL;
	cout << "Menu" << endl;
	cout << "1 - Add  a new entry to the customer list" << endl;
	cout << "2 - Delete an entry from the customer list" << endl;
	cout << "3 - Display the list" << endl;
	cout << "4 - Exit program" << endl;
	cin >> selection;
	return selection;
};

// Main function
int main() {
	
	int selection = NULL;
	Customer c1("Johnny Pepper", "111-222-333", "7231 S Walnut St Terre Haute, IN 47803", "812-111-222");
	List customer;

	// Loops until user terminates program
	do {	
		selection = printMenu();
		// Option selector
		switch (selection) {
		// Adds a customer
		case 1:
			customer.addNode(c1.name);
			customer.addNode(c1.customerID);
			customer.addNode(c1.address);
			customer.addNode(c1.phoneNumber);
			break;
		// Deletes a customer
		case 2:
			customer.deleteNode(c1.name);
			customer.deleteNode(c1.customerID);
			customer.deleteNode(c1.address);
			customer.deleteNode(c1.phoneNumber);
			break;
		// Prints Linked-List
		case 3:
			customer.printList();
			break;
		};
	} while (selection != 4);
	cout << "Program Terminated" << endl;

	system("pause>0");
};