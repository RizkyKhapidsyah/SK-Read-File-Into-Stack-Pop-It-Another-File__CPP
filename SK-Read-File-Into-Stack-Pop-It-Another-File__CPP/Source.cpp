#include <iostream>
#include <string>
#include <fstream>
#include <conio.h>

using namespace std;

template <class T>

class DynStack {
private:
	struct StackNode {
		T value;
		StackNode* next;
	};

	StackNode* top;

public:
	DynStack() {
		top = NULL;
	}

	void push(T);
	void pop(T&);
	bool isEmpty();
};


//*********************************************************
// Member function push pushes the argument onto the stack. *
//*********************************************************

template <class T>
void DynStack<T>::push(T num) {
	StackNode* newNode = NULL;
	// Allocate a new node & store Num
	newNode = new StackNode;
	newNode->value = num;

	// If there are no nodes in the list make newNode the first node
	if (isEmpty()) {
		top = newNode;
		newNode->next = NULL;
	} else { // Otherwise, insert NewNode before top 
		newNode->next = top;
		top = newNode;
	}

}

//*********************************************************
// Member function pop pops the value at the top of the stack off, *
// and copies it into the variable passed as an argument. *
//*********************************************************
template <class T>
void DynStack<T>::pop(T& ch) {

	StackNode* temp = NULL;

	if (isEmpty()) {
		cout << "The stack is empty.\n";
	} else { // pop value off top of stack
		ch = top->value;
		temp = top->next;
		delete top;
		top = temp;

	}

}

//*********************************************************
// Member funciton isEmpty returns true if the stack *
// is empty, or false otherwise. *
//*********************************************************
template <class T>
bool DynStack<T>::isEmpty() {
	bool status = false;

	if (!top) {
		status = true;
	}

	return status;
}

int main(int argc, char** argv) {

	string inputFile = "file.txt";

	ifstream obj(inputFile.c_str());
	DynStack<char>  stack;

	char ch;

	cout << "\n\n\n=======Content of input file file.txt =========== \n\n";

	if (obj) {
		while (obj.get(ch)) {
			cout << ch;
			stack.push(ch);
		} obj.close();
	} else {
		cout << "\nfile.txt not found. Create file.txt in current folder";
	}

	string outputFile = "output.txt";

	ofstream file(outputFile.c_str());

	char temp;
	while (!stack.isEmpty()) {
		stack.pop(temp);
		file.put(temp);

	}
	file.close();

	cout << "\n\n\n========Content of Output file output.txt==========\n\n";

	ifstream readOutputFile(outputFile.c_str());
	ch = NULL;

	while (readOutputFile.get(ch)) {
		cout << ch;
	}
	readOutputFile.close();

	cout << endl;

	_getch();
	return 0;
}