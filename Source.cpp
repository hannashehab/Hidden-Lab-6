//Hanna Mostafa
//900222857

#include <iostream>
using namespace std;

template <class T>
class Node {
private:
	T info;
	Node<T>* next, * back;

public:
	Node() {
		next = NULL;
		back = NULL;
	}
	//getters
	T get_info() {
		return info;
	}
	Node<T>* get_next() {
		return next;
	}
	Node<T>* get_back() {
		return back;
	}

	//setters
	void set_info(T info_p) {
		info = info_p;
	}
	void set_next(Node<T>* n) {
		next = n;
	}
	void set_back(Node<T>* b) {
		back = b;
	}

	~Node() {

	}
};

template <class T>
class My_list {
private:
	Node<T>* head, * tail;

public:
	My_list() {
		head = NULL;
		tail = NULL;
	}

	Node<T>* get_head() {
		return head;
	}

	Node<T>* get_tail() {
		return tail;
	}

	Node<T>* append(T info_p) {
		Node<T>* temp = new Node<T>();
		temp->set_info(info_p);
		if (head == NULL) {
			//first element in the list
			head = temp;
			tail = head;

		}
		else {
			//not the first element
			/*
			1.temp becomes tail
			2.temp->next = NULL
			3.temp->back = old tail
			4.old tail->next = temp
			*/
			temp->set_back(tail);
			tail->set_next(temp);
			temp->set_next(NULL);
			tail = tail->get_next();
		}
	}
	//write a method insertMid(node* curr, info)
	//it should insert a new node after curr in the linked list containing info
	Node<T>* insertMid(Node<T>* curr, T info) {
		Node<T>* new_node = new Node<T>();
		new_node->set_info(info);
		new_node->set_next(curr->get_next());
		new_node->set_back(curr);
		if (curr->get_next() != NULL) {
			curr->get_next()->set_back(new_node);
		}
		curr->set_next(new_node);
		return new_node;
	}



	~My_list() {}

};