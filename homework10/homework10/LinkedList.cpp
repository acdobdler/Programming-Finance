#include <iostream>
#include "LinkedList.h"

using namespace std;

LinkedList::LinkedList() {
	Size = 0;
}

LinkedList::~LinkedList() {

}

int LinkedList::size() {
	return Size;
}
/*OK*/
void LinkedList::addToStart(Node *newNode) {
	if (size() == 0) {
		head = newNode;
		tail = newNode;
		Size++;
	} else {
		newNode->next = head;
		head = newNode;
		Size++;
	}
}
/*OK*/
void LinkedList::addToEnd(Node *newNode) {
	if (size() == 0) {
		tail = newNode;
		head = newNode;
		Size++;
	}else {
		tail->next = newNode;
		tail = newNode;
		Size++;
	}
}
/*OK*/
void LinkedList::printList() {
	Node *ptr = head;
	cout << "------list------" << endl;
	if (size() == 0) {
		cout << "There is no item in the shopping list!" << endl;
	}
	else {
		for (int i = 0; i < size(); i++) {
				cout << ptr->itemNo << " " << ptr->itemName << endl;
				ptr = ptr->next;
			}
	}
	cout << "----------------" << endl;
}
/*OK*/
bool LinkedList::removeFromStart() {
	if (size() == 0) return false;
	else if (size() != 1) {
		Node *ptr = head;
		head = head->next;
		delete ptr;
		Size--;
		return true;
	} else {
		Node *ptr = head;
		head = NULL;
		tail = head;
		delete ptr;
		Size--;
		return true;
	}
}

bool LinkedList::removeFromEnd() {
	if (size() == 0) return false;
	else if (size() != 1) {
		Node *ptr = head;
		while (ptr->next != tail) {
			ptr = ptr->next;
		}
		delete tail;
		tail = ptr;
		Size--;
		return true;
	}
	else {
		Node *ptr = tail;
		head = NULL;
		tail = head;
		delete ptr;
		Size--;
		return true;
	}
}

void LinkedList::removeNodeFromList(int no) {
	Node *ptr = head;
	if (ptr->itemNo == no) { removeFromStart(); }
	else {
		while (ptr->next->itemNo != no) {
			if (ptr->next == NULL) {
				cout << "There is no such item in the shopping list!" << endl;
				return;
			}
			ptr = ptr->next;
		}
		if (ptr->next->next == NULL) {
			removeFromEnd();
		} else {
			Node *deleteItem = ptr->next;
			ptr->next = ptr->next->next;
			delete deleteItem;
		}
	}
	Size--;
}

void LinkedList::removeNodeFromList(string name) {
	Node *ptr = head;
	if (ptr->itemName == name) { removeFromStart(); }
	else {
		while (ptr->next->itemName != name) {
			if (ptr->next == NULL) {
				cout << "There is no such item in the shopping list!" << endl;
				return;
			}
			ptr = ptr->next;
		}
		if (ptr->next->next == NULL) {
			removeFromEnd();
		}
		else {
			Node *deleteItem = ptr->next;
			ptr->next = ptr->next->next;
			delete deleteItem;
		}
	}
	Size--;
}