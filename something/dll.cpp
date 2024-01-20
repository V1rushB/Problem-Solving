#include <bits/stdc++.h>

using namespace std;

struct node {
    int data;
    node *next,*previous;
};

class DLL {
    private:
        node *head,*tail;
    public: 
    
    DLL() {
        head = tail = NULL;
    }

    void insert(int data) {
	node *cur = new node;
	cur->data = data;
	cur->next = NULL;
	cur->previous = NULL;
	if(head == NULL)
		head = tail = cur;
	else {
		tail->next = cur;
		cur->previous = tail;
		tail = cur;
	}
    }

    void insertBeginning(int data) {
	    node *cur = new node;
	    cur->data = data;
	    cur->next = NULL;
	    cur->previous = NULL;
	    if(head == NULL)
	    {
		    head = tail = cur;
	    } else {
	    	head->previous = cur;
		cur->next = head;
		head = cur;
	    }
	}

    void deleteBeginning() {
	    if(head==NULL)
		    return void(cout << "Nothing to delete." << endl);
	    node *temp = head;
	    head = head->next;
	    head->previous = NULL;
	    delete(temp);
    }

    void deleteEnd() {
	    if(head == NULL)
		    return void(cout << "Nothing to delete." << endl);
	    node *temp = tail;
	    tail = tail->previous;
		tail->next = NULL;
	    delete(temp);
    }

    void print() {
	    node *temp = new node;
	    temp = head;
	    while(temp !=NULL) {
		    cout << temp->data << ' ';
		    temp = temp->next;
	    }
	    cout << endl;
    }

    void findItem(int key) {
	    node *temp = new node;
	    temp = head;
	    while(temp) {
		if(temp->data == key)
			return void(cout << "Item has been found." << endl);
	    	temp = temp->next;
	    }
	    cout << "Item hasn't been found." << endl;
    }
	//helping me
	node* getHead() {
		return head;
	}

	node* findElement(int element) {
		node *temp = head;
		while(temp) {
			if(temp->data == element)
				return temp;
			temp = temp->next;
		}
		return NULL;
	}
	void deleteItem(int key) {
		if(!findElement(key))
			return void(cout << "Item doesn't exist" << endl);
		if(head->data == key)
			deleteBeginning();
		else if(tail->data == key)
			deleteEnd();
		else {
			node *temp = findElement(key);
			temp->previous->next = temp->next;
			temp->next->previous = temp->previous;
			delete(temp);
		}
	}
};

int main() {
	int a; cin >> a;
	DLL ll;
	ll.insert(1);
	ll.insert(2);
	ll.insert(3);
	ll.insertBeginning(0);
	ll.print();
	ll.findItem(2);
	ll.deleteBeginning();
	ll.print();
	ll.deleteEnd();
	ll.print();
	ll.insert(5);
	ll.deleteItem(8);
	ll.deleteItem(2);
	ll.print();
	return 0;
}
