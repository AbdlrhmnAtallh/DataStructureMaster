#include<iostream>
using namespace std;
const int Size = 5;
class Stack {
int element [Size];
	int top;
	bool Empty() {
		if (top == -1)
			return true;
		else
			return false;
	}
	bool Full() {
		if (element[top] == Size - 1) {
			return true;
		}
		else
			return false;
	}
public:
	Stack() :top(-1) {};
	void push(int value) {
		if (Full()) {
			cout << "Stack overflow" << endl;
		}
		else
		element[++top] = value;
	}
	int pop() {
		if (Empty()) {
			cout << "element is empty" << endl;
		}
		else
			top--;
		return element[top];
	}
	void peek() {
		if (Empty()) {
			cout << "element is empty" << endl;
		}
		else
			cout << element[top];
	}
	void display() {
		if (Empty()) {
			cout << "element is empty " << endl;
		}
		else {
			cout << "[ ";
			for (int i = top; i >= 0; i--) {
				cout << element[i];
				if ( i != 0) {
					cout << " , ";
				}
			}
			cout << " ]";
		}
	}
};
class Qeue {
	int element[Size];
	int front, rear;
public:
	Qeue() {
		front = -1;
		rear = -1;
	}
	bool isEmpty() {
		if (front ==  - 1) {
			return true;
		}
		return false;
	}
	bool isFull() {
		if (rear == Size - 1) {
			return true;
		}
		return false;
	}
	void enqeue(int value) {
		if (isFull()) {
			cout << "Qeue is full" << endl;
		}
		else {
			if (front == -1) front = 0;
			rear++;
			element[rear] = value;
		}
	}
	void deqeue() {
		if (isEmpty()) {
			cout << "Qeue is empty" << endl;
		}
		else {
			cout <<"[ "<< element[front]<<" ] " << "deleted\n";
			if (rear == 0) {
				rear = -1;
				front = -1;
			}
			else
				front++;
		}
	}
	void display() {
		if (isEmpty()) {
			cout << "Qeue is empty" << endl;
		}
		else {
			if (front == rear) {
				cout << "One elemnt in the qeue ->" << element[front] << endl;
			}
			else
				cout << "[ ";
			for (int i = front; i <= rear; i++) {
				cout << element[i];
				if ( i != rear) {
					cout <<" , ";
				}
			}
			cout << " ]";
		}
	}

};
class circular_Queue {
private:
	int items[Size], front, rear;

public:
	circular_Queue() : front(-1), rear(-1) {};
	bool isFull() {
		if (front == 0 && rear == Size - 1) {
			return true;
		}
		if (front == rear + 1) {
			return true;
		}
		return false;
	}
	bool isEmpty() {
		if (front == -1)
			return true;
		else
			return false;
	}
	void enQueue(int element) {
		if (isFull()) {
			cout << "Queue is full \n";
		}
		else {
			if (front == -1) front = 0;
			rear = (rear + 1) % Size;
			items[rear] = element;
		}
	}
	int deQueue() {
		int element;
		if (isEmpty()) {
			cout << "Queue is empty" << endl;
			return (-1);
		}
		else {
			element = items[front];
			if (front == rear) {
				front = -1;
				rear = -1;
			}
			else {
				front = (front + 1) % Size;
			}
			return (element);
		}
	}

	void display() {
		int i;
		if (isEmpty()) {
			cout << endl
				<< "Empty Queue \n" << endl;
		}
		else {
			cout << " [ ";
			for (i = front; i != rear; i = (i + 1) % Size) {
				cout << items[i];
				if (i != rear - 1) {
					cout << " , ";
				}
			}
			cout << " ] ";
		}
	}
};
class Linkedlist {
public:
	struct node {
		int data;
		node *next;
	};
	node* head = NULL;
	void isertnode(int data) {
		node *new_node = new node;
		node* temp;
		new_node->data = data;
		if (head == NULL) {
			head = new_node;
			new_node->next = NULL;
		}
		else {
			temp = head;
			while (temp->next != NULL) {
				temp = temp->next;
			}
			temp->next = new_node;
			new_node->next = NULL;
		}

	}
	 
	void displayNode() {
		if (head == NULL) {
			cout << "NO ELEMENTS \n";
		}
		else {
			node* Temp1;
			Temp1 = head;
			cout << " [ ";
			while (Temp1 != NULL) {
				cout << Temp1->data;
				Temp1 = Temp1->next;
				if (Temp1 != NULL) {
					cout << " , ";
				}
			}
			cout << " ] \n";
		}

	}
	void inser_at_beginnig (int data) {
		node* First_node = new node;
		First_node->data = data;
		First_node->next = head;
		head = First_node;
	}
	void delet_node(int value) {
		if (head == NULL) {
			cout << " Can't delete \n";
			return;
		}
			node* deleter_temp = head;
			if (deleter_temp->data == value) {
				head = deleter_temp->next;
				free(deleter_temp);
				return;
		}
			node* Fake_temp = head ;
			while (deleter_temp -> data != value) {
					Fake_temp = deleter_temp;
					deleter_temp = deleter_temp->next;
			}
			Fake_temp->next = deleter_temp->next;
		    cout << " [ " << deleter_temp->data << " ] Deleted \n";
			free (deleter_temp);
		
	}
	void delete_at_beginning() {
		if (head == NULL) {
			cout << " Can't delete \n";
			return;
		}
		node* first_node = head;
		head = first_node->next;
		cout << " [" << first_node->data << "] deleted \n";
		free(first_node);
	}
	void delete_at_end() {
		if (head == NULL) {
			cout << " Can't delete \n";
			return;
		}
		node* deleter = head;
		node* temp = head;
		while (deleter->next != NULL) {
			temp = deleter;
			deleter = deleter->next;		
		}
		cout << " [ "<<deleter->data<<" ] Deleted \n";
		free(deleter);
		temp->next = NULL;
		
	}


};
class Double_linkedList {
public:
	struct Node {
		int data;
		Node* next;
		Node* prev;
	};
	Node* head = NULL;
	void addNode(int data) {
		Node* newnode = new Node;
		Node* temp;
		newnode->data = data;
		if (head == NULL) {
			newnode->prev = head;
			head = newnode;
			newnode->next = NULL;
		}
		else {
			temp = head;
			Node* prevTemp;
			while (temp->next != NULL) {
				prevTemp = temp;
				temp = temp->next;
			}
			temp->next = newnode;
			newnode->next = NULL;
			newnode->prev = temp;
		}

	}
	void Display() {
		if (head == NULL) {
			cout << " Can't find elements \n";
			return;
		}
		Node* temp = head;
		cout << " [ ";
		while (temp != NULL) {
			cout << temp->data;
			if (temp->next != NULL) {
				cout << ", ";
			}
			temp = temp->next;
		}
		cout << " ] " << endl;
	
	}
	
	void Display_forwardBackward(int value) {
		if (head == NULL) {
			cout << " Can't find elements \n";
			return;
		}
		Node* temp = head;
		while (temp->data != value ) {
			temp = temp->next;
		}
		if (temp->prev == NULL) {
			cout << " [ " << temp->data << " ] is the first element\n";
			cout << " [ " << temp->data << ", " << temp->next->data << " ]\n";
			return;
		}
		if (temp->next == NULL) {
			cout << " [ " << temp->data << " ] is the last element\n";
			cout << " [ " << temp->prev->data << ", " << temp->data << " ]\n";
			return;
		}
		cout << " [ " << temp->prev->data << ", " << temp->data << ", " << temp->next->data << " ] \n";
	}

};
int main() { 
	// --------------------Stack-----------------------------//
	cout << "\n---------------------------\n" << " Stack class : \n";
	Stack c;
	c.display(); c.push(10); c.push(20); c.push(30); c.display();
	c.pop(); c.display();
	//..------------------Qeue-------------------------------..//
	cout << "\n\n---------------------------\n"<< " Qeue class : \n";

	Qeue q;
	q.display(); q.enqeue(1); q.enqeue(2); q.enqeue(3); q.enqeue(4); q.deqeue();
	q.display();
	//..------------------circular_Qeue---------------------..//
	cout << "\n\n-----------------------------\n" << " Cirqular Qeue class : \n";
	circular_Queue cq;
	cq.display(); cq.enQueue(1); cq.enQueue(2); cq.enQueue(3);
	cq.enQueue(4); cq.enQueue(5); cq.display();
	cq.enQueue(6);
	//..----------------Linked_List------------------------..//
	cout << "\n\n------------------------------\n" << " Linked List class : \n";
	Linkedlist Llist;
	Llist.displayNode();
	Llist.isertnode(1); Llist.isertnode(2); Llist.delet_node(2);
	Llist.isertnode(3); Llist.displayNode(); Llist.inser_at_beginnig(0);
	Llist.inser_at_beginnig(-1);
	Llist.displayNode(); Llist.delete_at_beginning();
	Llist.delete_at_end(); Llist.displayNode();
	//------------------double Linked list------------------//
	cout << "\n\n-------------------------------\n"<< "double Linked list : \n";
	Double_linkedList DLs;
	DLs.addNode(1); DLs.addNode(2); DLs.addNode(3); DLs.addNode(4);
	DLs.addNode(5);
	DLs.Display();
	DLs.Display_forwardBackward(1);
	DLs.Display_forwardBackward(3);
	DLs.Display_forwardBackward(5);
	return 0;
}




 