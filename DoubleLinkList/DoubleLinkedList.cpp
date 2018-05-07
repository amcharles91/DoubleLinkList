#include <cstdlib>
#include<iostream>
using namespace std;



//Class creation of dynamic list
class DoubList {
	//Initializing private values
private:
	/*Node Struct Creation*/
	struct node {
		bool pointer = false;
		int data;      //Integer value
		void* voidPointy;  //Pointer Value
		node* next;		//Next pointer
		node* previous;	//Previous
	};

	int size=NULL;
	//Test
	node *begin; // Front
	node *end; // Rear

	  //intializing public valuse
public:

	DoubList::DoubList() {
		this->begin = nullptr;  //Makes front and Rear points Null
		this->end = nullptr;
	};

	/* Inserts the node into the front
	First checks if there is any nodes in the list
	which if there is, align the links correctly
	and if not creates a new node that connects the front
	and back to that node*/

	void DoubList::insert_front(int data) {
		//Creates tempoary node
		node *q = new node; //If empty creates the first node
		if (begin == nullptr) {
			q->next = nullptr;		//constraint		
			q->previous = nullptr;	//Links front and rear point to the new node
			begin = q;
			end = q;
		}
		else {
			//If not empty creates a node and inserts it to the front
			q->next = begin;		//makes q point to front which points to the first node
			begin->previous = q;	//makes the now 2nd node point previous to q
			begin = q;				//makes begin point to q which is now in front spot
		}
		q->data = data;				//inserts data to the new node
		q->pointer = false;			//identifies an int node

	};

	void DoubList::insert_front(void* data) {
		//Creates tempoary node
		node *q = new node; //If empty creates the first node
		if (begin == nullptr) {
			q->next = nullptr;		//constraint		
			q->previous = nullptr;	//Links front and rear point to the new node
			begin = q;
			end = q;
		}
		else {
			//If not empty creates a node and inserts it to the front
			q->next = begin;		//makes q point to front which points to the first node
			begin->previous = q;	//makes the now 2nd node point previous to q
			begin = q;				//makes begin point to q which is now in front spot
		}
		q->voidPointy = data;		//inserts data to the new node
		q->pointer = true;			//Identifies a pointer node

	};
	/*Inserts a node at the rear of the list*/

	void DoubList::insert_rear(int data) {

		node *p = new node;  //Create the node
		p->previous = nullptr; //makes front and back null and recieve the data
		p->data = data;
		p->next = nullptr;

		if (begin == nullptr) { //if there is no node create one
			begin = p;
			end = p;
			p->next = nullptr;
		}
		else {  //If ther eis more then one, insert at rear
			end->next = p;  //makes the next become the new node
			p->previous = end; //make sure the new node points back to the old
			end = p;		//now the end/ rear pointer is pointing at our node
			end->next = nullptr;  //constraint to reach the end
		}
		end->data = data; //add's the data to the newly created node
		end->pointer = false; //Identifies as an int

	};

	void DoubList::insert_rear(void* data) {

		node *p = new node;  //Create the node
		p->previous = nullptr; //makes front and back null and recieve the data
		p->voidPointy = data;
		p->next = nullptr;

		if (begin == nullptr) { //if there is no node create one
			begin = p;
			end = p;
			p->next = nullptr;
		}
		else {  //If there is more then one, insert at rear
			end->next = p;  //makes the next become the new node
			p->previous = end; //make sure the new node points back to the old
			end = p;		//now the end/ rear pointer is pointing at our node
			p->next = nullptr;  //constraint to reach the end
		}
		end->voidPointy = data; //add's the data to the newly created node
		end->pointer = true; //Marks a pointer node

	};


	/*Removes a node that is in the front*/

	int DoubList::remove_front_i() {
		int returnValue = NULL;
		node *p = nullptr;  //creates node pointer
		if (begin == nullptr) {
			//do nothing because there is no nodes
		}
		else if (begin == end) { //Only 1 node
			p = begin;			//p is pointing to the only node
			begin = nullptr;	//make the front and rear pointers null
			end = nullptr;
			p->next = nullptr;  //make sure p next is null
			returnValue = p->data; //put the value into returnValue
		}
		else {						//general case when there is more then 1 node;
			p = begin;				//node p is pointing to the first node
			begin = p->next;		//make the new front node the next node in line
			returnValue = p->data;	//make the data in the front node assigned to returnValue
			p->next = nullptr;		//make sure to null the front of the node
		}

		delete p;					//delete the node
		return returnValue;			//returns the data
	};

	void* DoubList::remove_front_p() {
		void* returnValue = NULL;
		node *p = nullptr;  //creates node pointer
		if (begin == nullptr) {
			//do nothing because there is no nodes
		}
		else if (begin == end) { //Only 1 node
			p = begin;			//p is pointing to the only node
			begin = nullptr;	//make the front and rear pointers null
			end = nullptr;
			p->next = nullptr;  //make sure p next is null
			returnValue = p->voidPointy; //put the value into returnValue
		}
		else {						//general case when there is more then 1 node;
			p = begin;				//node p is pointing to the first node
			begin = p->next;		//make the new front node the next node in line
			returnValue = p->voidPointy;	//make the data in the front node assigned to returnValue
			p->next = nullptr;		//make sure to null the front of the node
		}

		delete p;					//delete the node
		return returnValue;			//returns the data
	};

	/*Removes a node from the rear*/

	int DoubList::remove_rear_i() {
		node *h = nullptr;			//temporary pointer node to be used
		int returnValue = NULL;		//returnValue placeholder
		if (begin == nullptr) {
			//do nothing
		}
		else if (begin == end) {	//only 1 node available
			h = begin;
			begin = end = nullptr;	//nulls front and end
			returnValue = h->data;	//store the data
			h->next = h->previous = nullptr;//nulls next and previous on node p
			delete h;
		}
		else {						//more then 1 node
			h = end;				//makes p point to last node
			end = end->previous;	//assign the new end to the previous node
			end->next = nullptr;	//end next becomes null
			returnValue = h->data;	//store the value
			h->next = h->previous = nullptr;	//Make p next and previous both null
			delete h;
		}							//returns p to memory;
		return returnValue;			//returns the data
	};

	void* DoubList::remove_rear_p() {
		node *p = nullptr;					//temporary pointer to be used
		void*returnValue = nullptr;			//returnValue placeholder
		if (begin == nullptr) {
			//do nothing
		}

		else if (begin == end) {	//only 1 node available
			p = begin;
			begin = end = nullptr;	//nulls front and end
			returnValue = p->voidPointy;	//store the data
			p->next = p->previous = nullptr;//nulls next and previous on node p
		}
		else {						//more then 1 node
			p = end;				//makes p point to last node
			end = p->previous;	//assign the new end to the previous node
			end->next = nullptr;	//end next becomes null
			returnValue = p->voidPointy;	//store the value
			p->next = p->previous = nullptr;	//Make p next and previous both null
		}
		delete p;					//returns p to memory;
		return returnValue;			//returns the data
	};

	void DoubList::remove_front() {
		node *f = nullptr;
		f = begin;

		if (begin == nullptr) {
			return;
		};
		if (f->pointer) {			//If identified as a pointer
			remove_front_p();		//removes front pointer node
		}
		else {						//Then it is a int node
			remove_front_i();		//removes front int node
		}
		f->next = f->previous = nullptr;
		f->data = NULL;				//null's data
		f->voidPointy = NULL;		//null's voidPointy
		f = nullptr;				//null's r completey
		delete f;					//releases r
	};

	void DoubList::remove_rear() {
		node *r = nullptr;
		r = end;
		if (begin == nullptr) {
			return;
		};
		if (r->pointer) {			//If identified as a pointer
			remove_rear_p();		//removes front pointer node
		}
		else {						//Then it is a int node
			remove_rear_i();		//removes front int node
		}
		r->next = r->previous = nullptr;
		r->data = NULL;				//null's data
		r->voidPointy = NULL;		//null's voidPointy
		r = nullptr;				//null's r completey
		delete r;					//releases r
	};

	void DoubList::printList() {
		node* print;
		print = begin;	//points to front node
		cout << "Node List :  ";
		while (print != nullptr) {	//while the pointer is not null
			int *a = (int*)print->voidPointy;
			if (!print->pointer) {
				cout << " " << print->data;	//print out the node data
			}
			else {
				cout << " " << *a;
			}
			print = print->next;	//assign the next value to pointer to iterate
			a = NULL;				//Null's a
			delete a;				//releases a
		}

		cout << "" << endl;
		print = NULL;				//null print
		delete print;				//release print
	}

	void DoubList::makeEmpty() {
		while (begin != nullptr) {		//Just iterates through all the nodes removing them
			remove_front();
		}
	};

	bool DoubList::isEmpty() {
		if (begin == nullptr) {				//checks if there's no node
			cout << "It is empty" << endl;
			return true;
		}
		else {
			cout << "It is not empty" << endl;
			return false;
		}
	};

};






int main() {
	DoubList Test;
	/*Linked list test Statements
	Currently only accepts Integer Types 
	and pointers that point to integers*/
	//Numbers we are going to be using to test each function
	int a = 5;
	int b = 56;
	int c = 10;
	int d = 58;
	int e = 70;

	//Lets Test Basic operations of each 

	//Check if list is empty
	cout << "Checking if Empty"<<endl;
	Test.isEmpty();
	//insert front Operations
	cout << "Testing out inserting from the front" << endl;
	Test.insert_front(a);
	Test.printList();
	Test.insert_front(c);
	Test.printList();
	Test.insert_front(e);
	Test.printList();
	cout << "Removing from front" << endl;
	Test.remove_front();
	Test.printList();
	Test.remove_front();
	Test.printList();
	Test.remove_front();
	Test.printList();
	cout << "Testing void pointer front inserts" << endl;
	Test.insert_front(&d);
	Test.printList();
	Test.insert_front(&c);
	Test.printList();
	Test.insert_front(&b);
	Test.printList();
	cout << "Removing front pointers" << endl;
	Test.remove_front();
	Test.printList();
	Test.remove_front();
	Test.printList();
	Test.remove_front();
	
	//Testing insert from rear operations
	cout << "Testing out inserting integer from the rear" << endl;
	Test.insert_rear(a);
	Test.printList();
	Test.insert_rear(c);
	Test.printList();
	Test.insert_rear(e);
	Test.printList();
	cout << "Removing integers from rear" << endl;
	Test.remove_rear();
	Test.printList();
	Test.remove_rear();
	Test.printList();
	Test.remove_rear();
	Test.printList();
	cout << "Testing void pointer rear inserts" << endl;
	Test.insert_rear(&d);
	Test.printList();
	Test.insert_rear(&e);
	Test.printList();
	Test.insert_rear(&a);
	Test.printList();
	cout << "Removing rear pointers" << endl;
	Test.remove_rear();
	Test.printList();
	Test.remove_rear();
	Test.printList();
	Test.remove_rear();
	Test.printList();

	//Lets test alternativing removing and isnerting
	cout << "Alternating rear front rear inserts" << endl;
	Test.insert_rear(&d);
	Test.printList();
	Test.insert_front(&e);
	Test.printList();
	Test.insert_rear(&a);
	Test.printList();
	
	//Alternating removing
	cout << "Alternating removing front rear front" << endl;
	Test.remove_front();
	Test.printList();
	Test.remove_rear();
	Test.printList();
	Test.remove_front();
	Test.printList();


	//Lets test our remove function
	cout << "Inserting from front and rear alternating mix of int and pointers towards ints" << endl;;
	Test.insert_front(a);
	Test.insert_rear(d);
	Test.insert_front(b);
	Test.insert_rear(c);
	Test.insert_front(a);
	Test.insert_rear(e); 
	Test.insert_front(b);
	Test.insert_rear(d);
	Test.insert_front(e);
	Test.insert_rear(b);
	Test.insert_front(a);
	Test.printList();

	//Let's remove 1 from front 1 from rear
	Test.remove_front();
	Test.printList();
	Test.remove_rear();
	Test.printList();
	

	//Lets make it empty again!
	cout << "Clears out the nodes" << endl;
	Test.makeEmpty();
	Test.isEmpty();
	



	return 0;
};
