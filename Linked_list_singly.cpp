#include <iostream>
#include <cstdlib>
using namespace std;

template <class T1>
class List_s;				//Forward declaration because of friend class in Node.

template <class T>
class Node {				//Every node contains its data and a pointer which points to the next node (class).
	friend class List_s <T>;	//List_s can access the private member in Node.
private:
	T data;
	Node* next;				//A pointer which points to the next node (class).
};

template <class T1>
class List_s {				//It implements the entire data structure.
private:
	Node <T1> * first;		//The first pointer points to the first Node.
	int size;				//How many Nodes are there in the List?
public:
	List_s() :first(NULL), size(0) {}		//constructor
	void pushFront(T1 _data) {				//Insert a Node at the beginning.
		Node <T1>* p = new Node <T1>;
		p->data = _data;
		p->next = first;
		first = p;
		++size;
	}
	void pushAt(const int index, T1 _data) {		//Insert a Node at the particular location.
		if (index == 0) pushFront(_data);
		else if (index > size) cout << "Out of range!!!" << endl;
		else {
			Node <T1>* before = first;		//In order to find the location.
			for (int i = 1; i < index; ++i) before = before->next;	//Search from the first Node.
			
			Node <T1>* p = new Node <T1>;
			p->data = _data;
			p->next = before->next;
			before->next = p;
			++size;
		}
	}
	void printOut() const {
		Node <T1>* p = first;
		while (p != NULL) {
			cout << p->data << " -> ";
			p = p->next;
		}
		cout << "NULL" << endl;
	}
	void deleteFirst() {
		Node <T1>* p = first;
		first = p->next;
		delete p;
		p = NULL;
		--size;
	}
	void deleteIndex(const int index) {
		if (index == 0) deleteFirst();
		else if (index > size - 1) cout << "Out of range!!!" << endl;
		else {
			Node <T1>* before = first;								//In order to find the location.
			for (int i = 1; i < index; ++i) before = before->next;	//Search from the first Node.
			Node <T1>* _delete = before->next;
			Node <T1>* next = _delete->next;

			before->next = next;
			delete _delete;
			_delete = NULL;
			--size;
		}
	}
};

int main() { 
	List_s <int> myList;
	myList.pushAt(0, 0);
	myList.pushAt(1, 1);
	myList.pushAt(2, 2);
	myList.pushAt(3, 3);
	myList.pushAt(4, 4);
	myList.pushFront(-100);
	myList.printOut();

	myList.deleteIndex(0);
	myList.deleteIndex(3);
	myList.printOut();

	myList.deleteIndex(0);
	myList.deleteIndex(0);
	myList.deleteIndex(0);
	myList.deleteIndex(0);
	myList.printOut();

	myList.pushFront(100);
	myList.printOut();

	system("pause");
	return 0;
}