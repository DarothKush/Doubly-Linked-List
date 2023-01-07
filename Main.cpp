#include <iostream>
#include "doublylinkedlist2.h"
using namespace std;

struct Node {
	int data;
	struct Node* next;
	struct Node* prev;
};

struct Node* addToEmpty(struct Node* head, int data) {
	struct Node* temp = (Node*)malloc(sizeof(struct Node));
	temp->prev = NULL;
	temp->data = data;
	temp->next = NULL;
	head = temp;
	return head;
};

struct Node* addAtTheBeg(struct Node* head, int data) {
	struct Node* temp = (Node*)malloc(sizeof(struct Node*));
	temp->prev = NULL;
	temp->data = data;
	temp->next = NULL;
	temp->next = head;
	temp->prev = temp;
	head = temp;
	return head;
};

struct Node* addAtTheEnd(struct Node* head, int data) {
	struct Node* temp, * tp;
	temp = (struct Node*)malloc(sizeof(struct Node*));
	temp->prev = NULL;
	temp->data = data;
	temp->next = NULL;
	tp = head;
	while (tp->next != NULL) {
		tp = tp->next;
	}
	tp->next = temp;
	temp->prev = tp;
	return head;
};

struct Node* addBetween(struct Node* head, int data, int position) {
	struct Node* newNode = NULL;
	struct Node* temp = head;
	struct Node* temp2 = NULL;
	newNode = addToEmpty(newNode, data);
	while (position != 1) {
		temp = temp->next;
		position--;
	}
	//check if the position added at the last node
	//and add a new node at the end
	if (temp->next == NULL) {
		temp->next = newNode;
		newNode->prev = temp;
	}
	//else we do add normally
	else {
		temp2 = temp->next;
		temp->next = newNode;
		temp2->prev = newNode;
		newNode->next = temp2;
		newNode->prev = temp;
	}
	return head;
};

struct Node* addBeforeSpecificPos(struct Node* head, int data, int position) {
	struct Node* newNode = NULL;
	struct Node* temp = head;
	struct Node* temp2 = NULL;
	newNode = addToEmpty(newNode, data);
	int pos = position;
	while (pos > 2) {
		temp = temp->next;
		pos--;
	}
	//add at the begining of the node
	if (position == 1) {
		head = addAtTheBeg(head, data);
	}
	else if (temp->next == NULL) {
		temp->next = newNode;
		newNode->prev = temp;
	}
	else {
		temp2 = temp->next;
		temp->next = newNode;
		temp2->prev = newNode;
		newNode->next = temp2;
		newNode->prev = temp;
	}
	return head;
}
struct Node* deleteFirstNode(struct Node* head) {
	struct Node* temp = head;
	head = head->next;
	free(head->prev);
	//temp = NULL;
	head->prev = NULL;
	return head;
}
struct Node* reverse(struct Node* head) {
	struct Node* ptr1 = head;
	struct Node* ptr2 = ptr1->next;
	ptr1->next = NULL;
	ptr1->prev = ptr2;
	while (ptr2 != NULL) {
		ptr2->prev = ptr2->next;
		ptr2->next = ptr1;
		ptr1 = ptr2;
		ptr2 = ptr2->prev;
	}
	head = ptr1;
	return head;
}

void printForward(Node* head) {
	while (head != NULL) {
		cout << head->data<<endl;
		head = head->next;
	}
}
void printBackward(Node* tail) {
	
}
//struct Node* head;//creating global 
int main() {
	struct Node* head = NULL;

	//create a new node
	head = addToEmpty(head, 45);
	cout << head->data<<endl;
	//after adding another node
	cout << "After adding another node at the front"<<endl;
	head = addAtTheBeg(head, 50);
	printForward(head);
	cout << "After adding another node at the end"<<endl;
	head = addAtTheEnd(head, 60);
	printForward(head);
	cout << "After adding another node between" << endl;
	head = addBetween(head, 24, 2);
	printForward(head);
	cout << "After addning another node after a specific position" << endl;
	head = addBeforeSpecificPos(head, 90, 4);
	printForward(head);
	cout << "After deleting the first node"<<endl;
	head = deleteFirstNode(head);
	printForward(head);
	cout<<"After reverse";
	head = reverse(head);
	printForward(head);

	//struct Node* ptr;
	//ptr = head;
	//while (ptr != NULL) {
	//	cout << ptr->data << endl;
	//	ptr = ptr->next;
	//}
	return 0;
}



