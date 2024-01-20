#include <bits/stdc++.h>

using namespace std;

const int max = 10;

class Stack {
	private:
	  int top;
	  int data[10];

	public:
	  Stack() {
		top = -1;
	  }

	  void clear() {
		  top = -1;
	  }

	  bool isEmpty() {
	  return (top == -1);
	  }
	  bool isFull() {
		 return (top == max-1);
	  }
	  void push(int data) {
	  	if(!isFull())
			data[++top]=data;
	  }

	  void pop() {
		 if(!isEmpty()) 
		 {
			 top--;
		 }
	  }
	  int peek() {
		if(!isEmpty()) {
		return return data[top] 
		}
	  }

}

//some array implemention for the stack
