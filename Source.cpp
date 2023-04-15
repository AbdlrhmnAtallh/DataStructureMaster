#include<iostream>
#include<string>
#include<algorithm>
#include<stack>
#include <windows.h>
using namespace std;

const int Size = 5;
class Stack {
int element [Size];
public:
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
	int top_element() {
		return  element[top];
	}
};
class Balanced_parentheses {
public:
	bool pair(char open ,char close) {
		if (open == '(' && close == ')') return true;
		if (open == '{' && close == '}') return true;
		if (open == '[' && close == ']') return true;
		return false;
	}
	bool is_balance(string exp) {
		Stack left_brackets;
		for (int i = 0; i < exp.length(); i++) {
			if (exp[i] == '[' || exp[i] == '{' || exp[i] == '(') {
				left_brackets.push(exp[i]);
			}
			else if (exp[i] == ']' || exp[i] == '}' || exp[i] == ')') {
				if (left_brackets.Empty()) return false;
				else if (!pair(left_brackets.top_element(), exp[i])) return false;
				else
					left_brackets.pop();
			}

		}
		
		if (!left_brackets.Empty()) return false;
		else return true;
	}
	void print( string x) {
		if (!is_balance (x)) {
			cout << " Not balanced \n";
		}
		else
			cout << " Balanced \n";
	}
};
class To_Postfix {
 private:
	int priority(char c) {
		if (c == '+' || c == '-') return 1;
		if (c == '/' || c == '*') return 2;
		else return 0;
	}
 public:
	 void infixExpression(string exp) {
		 Stack stk;
		 string ouput;
		 for (int i = 0; i < exp.length(); i++) {
			 if (exp[i] == ' ') continue;
			 if (isdigit(exp[i]) || isalpha(exp[i])) {
				 
				 ouput += exp[i];

			 } 
			 else if (exp[i] == '(') stk.push('(');
			 else if (exp[i] == ')') {
				 while (stk.top_element() != '(') {
					 ouput += stk.top_element();
					 stk.pop();

				 }
				 stk.pop();
			 }
			 else {
				 while ( !stk.Empty() && priority(exp[i]) <= priority(stk.top_element())) {
					 ouput += stk.top_element();
					 stk.pop();
				 }
				 stk.push(exp[i]);
			 }

		 }
		 while (!stk.Empty()) {
			 ouput += stk.top_element();
			 stk.pop();
		 }

			 
		cout << ouput << endl;
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
			cout << " Can't delete No elements \n";
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
	HANDLE console_color;
	console_color = GetStdHandle(
		STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(
		console_color,1);
	for (int P = 1; P < 50; P++) {

		// P is color code of the
		// corresponding color
		SetConsoleTextAttribute(
			console_color, P);

		// Print Statement
		cout << P << " Hello, "
			<< "good night!!!";
	}
	cout << " \n pres .. 0 To automatically display \n " <<
		" press .. 1 To choose  \n";

	int options; cin >> options;
	if (options == 0) {



		// --------------------Stack-----------------------------//
		cout << "\n---------------------------\n" << " Stack class : \n";

		Stack c;
		c.display(); c.push(10); c.push(20); c.push(30); c.display();
		c.pop(); c.display();

		//..------------------Qeue-------------------------------..//
		cout << "\n\n---------------------------\n" << " Qeue class : \n";

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
		cout << "\n\n-------------------------------\n" << "double Linked list : \n";
		Double_linkedList DLs;
		DLs.addNode(1); DLs.addNode(2); DLs.addNode(3); DLs.addNode(4);
		DLs.addNode(5);
		DLs.Display();
		DLs.Display_forwardBackward(1);
		DLs.Display_forwardBackward(3);
		DLs.Display_forwardBackward(5);
		//---------------------blanced parentheses------------//
		cout << "\n\n------------------------------------\n" << "Balaned or not : \n";

		Balanced_parentheses balance;
		balance.print("[]");
		balance.print(")(()()())(((");

		//---------------------ToPostfix----------------------//
		cout << "\n\n------------------------------------------\n" << "To Postfix : \n";
		To_Postfix tps;
		tps.infixExpression("8+2*5-(5+3)");
		tps.infixExpression("a+(c*d)/x-c");
		tps.infixExpression("1+23*y%4(a+12*34)");
		//---------------------------------------------------//
	}
	else if (options == 1) {


		bool Exit = false;
		while (!Exit) {
			bool Back = false;
			cout << " \n \n Choose one of the following options by its number .";
			cout << " \n 1. Stack \n 2. Qeue \n 3. Circular qeue \n 4. Linkedlist \n 5. Double Linked list " <<
				"\n 6. Balanced parentheses \n 7. Topostfix \n 0. Exit program \n";
			int option;
			cin >> option;
			if (option == 0) Exit = true;
			enum process {
				stack, qeue, CircularQqeue, Linked_list, DoubleLinkedList,
				BalancedParentheses, Topostfix
			};
			process p;
			switch (option) {

			case 1: p = stack; break;
			case 2: p = qeue; break;
			case 3: p = CircularQqeue; break;
			case 4: p = Linked_list; break;
			case 5: p = DoubleLinkedList; break;
			case 6: p = BalancedParentheses; break;
			case 7: p = Topostfix; break;
			}

			if (p == stack) {

				Stack c;
				bool Close = false;
				while (!Close) {
					cout << "\n Choose one of the following . \n" <<
						" 1. Push \n 2. Pop \n 3. Display \n 4. Top element \n 0. Back \n 00. Exit program : ";
					int choose;
					cin >> choose;
					if (choose == 0) {
						Back = true;
						Close = true;
					}
					else if (choose == 00) {
						Exit = true;
					}
					// push ..
					else if (choose == 1) {
						bool loop = true;
						while (loop) {
							cout << " Enter the number you want to push \n";
							int pushNo;
							cin >> pushNo;
							c.push(pushNo);
							cout << " Number [ " << pushNo << " ] has been added \n" <<
								" Do you want to add another number ? \n 1. YES \n 2. NO \n 0. back \n 00. Home : ";
							string Yes;
							cin >> Yes;
							if (Yes == "0") {
								Close = true;
								Back = true;
								loop = false;
							}
							else if (Yes == "2") loop = false;
							else if (Yes == "00")Exit = true;
							else {
								cout << "please try again... \n";
								Close = true;
								//Back = true;
								//Exit = false;
								loop = false;
							}
							// i need to finish the push opration 

						}
					}
					// POP ..
					else if (choose == 2 && !Back) {
						bool loop = true;
						while (loop) {
							if (c.Empty()) {
								cout << "\n Stack is Empty \n";
								loop = false;
							}
							else {
								cout << "\n Number [ " <<
									c.top_element();
								cout << " ] has ben deleted \n";
								cout << " This is the new top element [ " << c.pop() << " ] \n";
								cout << " \n do you want to pop agin ? \n 1. YES \n 2. NO \n 0. back \n 00. Exit : ";
								int Yes;
								cin >> Yes;
								if (Yes == 0) {
									Close = true;
									Back = true;
								}
								else if (Yes == 2) loop = false;
								else if (Yes == 00) {
									Exit = true;
									loop = true;
								}
							}
						}
					}
					// Display ..
					else if (choose == 3 && !Back) {
						cout << endl;
						c.display();
						cout << "\n \n 0. back \n 00. Exit :";
						int Yes;
						cin >> Yes;
						if (Yes == 0) {
							Close = true;
							Back = true;
						}
						else if (Yes == 00)Exit = true;
					}
					// Top element ..
					else if (choose == 4 && !Back) {
						cout << endl << " [ " << c.top_element() << " ] " << endl;
						cout << "\n \n 0. back \n 00. Exit :";
						int Yes;
						cin >> Yes;
						if (Yes == 0) {
							Close = true;
							Back = true;
						}
						else if (Yes == 00)Exit = true;
					}

				}

			}

			else if (p == qeue) {
				bool Close = false;
				Qeue qe;
				bool loop = true;
				while (loop) {
					cout << "\n Choose one of the following . \n" <<
						" 1. EnQeue \n 2. DeQeue \n 3. Display Qeue \n 0. back \n 00. Home : ";
					int choose;
					cin >> choose;
					if (choose == 0 ) {
						Back = true;
						loop = false;
					}
					else if (choose == 00) {
						Exit = true;
						loop = false;

					}
					else if (choose == 1) {
						bool add = true;
						while (add) {
							cout << "\n Enter the number you want to add \n";
							int enqeueNo;
							cin >> enqeueNo;
							qe.enqeue(enqeueNo);
							cout << " Number [ " << enqeueNo << " ] has been added \n" <<
								" Do you want to add another number ? \n 1. YES \n 2. NO \n 0. back \n 00. Home : ";

							int Yes;
							cin >> Yes;
							if (Yes == 1)continue;
							else if (Yes == 0) {
								Close = true;
								Back = true;
								add = false;
							}
							else if (Yes == 2) {
								
								add = false;
							}
							else if (Yes == 00) {
								Exit = true;
								loop = false;
								add = false;
							}
						}
					}
					else if (choose == 2) {
						bool remove = true;
						while (remove) {
							cout << " \n  ..";
							qe.deqeue();

							cout << " \n" <<
								" Do you want to delete another number ? \n 1. YES \n 2. NO \n 0. back \n 00. Home : ";
							int Yes;
							cin >> Yes;
							if (Yes == 0) {
								Close = true;
								Back = true;
								remove = false;
							}
							else if (Yes == 1)continue;
							else if (Yes == 2) remove = false;
							else if (Yes == 00) {
								loop = false;
								Exit = true;
								remove = false;
							}
						}
						
					}
						// display qeue .. 
					else if (choose == 3) {
						cout << "\n ... \t \t ...\n ";
						qe.display();
						cout << "\n ... \t \t ...\n ";

					}


					
				}

			}
			// i will remake this method ..
			else if (p == CircularQqeue) {
				circular_Queue C;
				bool Close = false;
				bool loop = true;
				while (loop) {
					cout << "\n Choose one of the following . \n" <<
						" 1. EnQeue \n 2. DeQeue \n 3. Display Qeue \n 0. back \n 00. Home : ";
					int choose;
					cin >> choose;
					if (choose == 1) {
						bool add = true;
						while (add) {
							if (C.isFull()) {
								cout << " \n Error .. No space \n";
							}
							else
								cout << "\n Enter the number you want to add : \n";
							int enQeue;
							cin >> enQeue;
							C.enQueue(enQeue);
							cout << "\n Do you want to add another number  \n 1. YES \n 2. NO \n 0. back \n 00. Home :  \n";
							int Yes;
							cin >> Yes;
							if (Yes == 1)continue;
							else if (Yes == 0) {
								Close = true;
								Back = true;
								add = false;
							}
							else if (Yes == 2) {

								add = false;
							}
							else if (Yes == 00) {
								Exit = true;
								loop = false;
								add = false;
							}
						}
					}
					else if (choose == 2) {
						if (!C.isFull()) {
							cout << "\n Error .. There are no elements  \n";
						}
						else {
							int deQeueNo;
							cin >> deQeueNo;
							cout << " Number [ " << C.deQueue() << " ] has been deleted \n" <<
								" Do you want to delete another number ? \n 1. YES \n 2. NO \n 0. back \n 00. Home : ";
							int Yes;
							cin >> Yes;
							if (Yes == 0) {
								Close = true;
								Back = true;
								loop = false;
							}
							else if (Yes == 2) loop = false;
							else if (Yes == 00) {
								loop = false;
								Exit = true;
							}
						}
					}
					else if (choose == 3) {
						if (C.isEmpty()) {
							cout << " \n Eroor .. there are no elements \n";
						}
						else {
							C.display();

						}
					}
				}
			}
			else if (p == Linked_list) {
				Linkedlist Lin;
				bool loop = true;
				while (loop) {
					cout << "\n Choose one of the following . \n" <<
						" 1. Isert node \n 2. Inser at beginnig \n 3. Delet node " <<
						"\n 4. Delete at beginning \n 5. Display \n 6. Delete at end  \n  0. back \n 00. Home : ";
					int choose;
					cin >> choose;
					if (choose == 00 || choose == 0)loop = false;
					if (choose == 1) {
						bool add = true;
						while (add) {
							cout << "\n Enter the number you want to add \n ";
							int Number;
							cin >> Number;
							Lin.isertnode(Number);
							cout << "\n Do you want to add another number  \n 1. YES \n 2. NO \n 0. back \n 00. Home :  \n";
							int Yes;
							cin >> Yes;
							if (Yes == 1)continue;
							else if (Yes == 0) {

								Back = true;
								add = false;
							}
							else if (Yes == 2) {

								add = false;
							}
							else if (Yes == 00) {
								Exit = true;
								loop = false;
								add = false;
							}
						}
					}
					else if (choose == 2) {
						bool add = true;
						while (add) {
							cout << "\n Enter the number you want to add at beginning \n ";
							int Number;
							cin >> Number;
							Lin.inser_at_beginnig(Number);
							cout << "\n Do you want to add another number at beginning  \n 1. YES \n 2. NO \n 0. back \n 00. Home :  \n";
							int Yes;
							cin >> Yes;
							if (Yes == 1)continue;
							else if (Yes == 0) {

								Back = true;
								add = false;
							}
							else if (Yes == 2) {

								add = false;
							}
							else if (Yes == 00) {
								Exit = true;
								loop = false;
								add = false;
							}
						}
						
					}
					else if (choose == 3) {
						bool remove = true;
						while (remove) {
							cout << "\n Enter the number you want to remove \n";
							int Number;
							cin >> Number;
							Lin.delet_node(Number);
							cout << "\n Do you want to delete another number  \n 1. YES \n 2. NO \n 0. back \n 00. Home :  \n";
							int Yes;
							cin >> Yes;
							if (Yes == 1)continue;
							else if (Yes == 0) {

								Back = true;
								remove  = false;
							}
							else if (Yes == 2) {

								remove = false;
							}
							else if (Yes == 00) {
								Exit = true;
								loop = false;
								remove = false;
							}

						}
					}
					else if (choose == 4) {
						bool remove = true;
						while (remove) {
							cout << " \n [ " << Lin.head->data << " ] Deleted \n ";
							Lin.delete_at_beginning();
							cout << " \n do you want to delete again ? \n 1. YES \n 2. NO \n 0. back \n 00. Home :  \n ";
							int Yes;
							cin >> Yes;
							if (Yes == 1)continue;
							else if (Yes == 0) {

								Back = true;
								remove = false;
							}
							else if (Yes == 2) {

								remove = false;
							}
							else if (Yes == 00) {
								Exit = true;
								loop = false;
								remove = false;
							}

						}
					}
					else if (choose == 5) {
						Lin.displayNode();
						
					}
					else if (choose == 6) {
						bool remove = true;
						while (remove) {
							Lin.delete_at_end();
							cout << " \n do you want to delete at end again ? \n 1. YES \n 2. NO \n 0. back \n 00. Home :  \n ";
							int Yes;
							cin >> Yes;
							if (Yes == 1)continue;
							else if (Yes == 0) {

								Back = true;
								remove = false;
							}
							else if (Yes == 2) {

								remove = false;
							}
							else if (Yes == 00) {
								Exit = true;
								loop = false;
								remove = false;
							}
						}
					}
				
				}
			}

		}
	}

	return 0;
}




 