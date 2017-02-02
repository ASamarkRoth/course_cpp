#include <iostream>
#include "list.h"

using std::cout;
using std::endl;

//Make an initialisation list! This implies that these variables are created in the compilation. This is just what happens with inheritance. It is required for varriables that need to be available at compilation, cf. const:s.
List::List() : nodes(0), first(nullptr) {
}

//Is this called implicitly? Yes, at the end of a scope for an object allocated on the stack!
List::~List() {
	cout << "Running destructor!" << endl;
	Node* node;
	int counter = 0;
	while(first) {
		//if(counter == nodes-2) break;
		node = first;
		first = first->next;
		delete node;
		++counter;
	}

}

//The const like this indicates that this function cannot change the value of a member variable of the class
bool List::exists(int d) const {
		Node* node = first;
		int counter = 0;
		//while(counter < 10 || node) {
	while(node) {
			if(node->value == d)	return true;
			node = node->next;
			++counter;
		}
	return false;
}

int List::size() const {
	return nodes;
}

bool List::empty() const {
	//conditional assignment: logic ? if(true) do : if(false) do
	//cout << "Is first: " << static_cast<bool>(first==NULL) << endl;
	bool to_return = first ? false : true;
	return to_return;
}

void List::insertFirst(int d) {
	if(nodes == 0) {
		first = new Node(d, NULL);
		++nodes;
	}
	else {
		first = new Node(d, first);
		++nodes;
	}

}

void List::remove(int d, DeleteFlag df) {
	Node* node = first;
	Node* temp;

	while(node) {
		if(check_remove(node, d, df)) {
			cout << "Removing: " << node->value << endl;
			temp = node;
			node = node->next;
			if(temp == first) first = node;
			delete temp;
			--nodes;
		}
		else if(node->next && check_remove(node->next, d, df)) {
			cout << "Removing next: " << node->next->value << endl;
			temp = node->next;
			node->next = node->next->next;
			delete temp;
			--nodes;
		}
		else {
			node = node->next;
		}
	}
}

/*
void List::remove(int d, DeleteFlag df) {
	first = recursive_remove(first, d, df);
}

List::Node* List::recursive_remove(Node* node, int d, DeleteFlag df) {
	if (node == NULL) {
		return NULL;
	} else {
		Node *next = recursive_remove(node->next, d, df);
		if (check_remove(node, d, df)) {
			delete node;
			return next;
		} else {
			node->next = next;
			return node;
		}
	}
}
*/

bool List::check_remove(Node* node, int d, DeleteFlag df) {
	if(df == DeleteFlag::LESS && node->value < d) {
		return true;
	}
	else if(df == DeleteFlag::EQUAL && node->value == d) {
		return true;
	}
	else if(df == DeleteFlag::GREATER && node->value > d) {
		return true;
	}
	return false;
}

void List::print() const {
	if(empty()) cout << "List is empty!" << endl;
	else {
		Node* node = first;
		while(node) {
			cout << node->value << " ";
			node = node->next;
		}
		cout << endl;
	}

}

