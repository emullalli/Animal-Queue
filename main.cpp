#include <iostream>
using namespace std;

// Task 2
class Animal
{
protected:
	string name; // only derived classes can access

public:
	Animal() // default constructor
	{
		name = "unknown";
	}

	void setName(string x) // lets us change name
	{
		name = x;
	}
	
	string getName() // returns the name
	{
		return name;
	}

	virtual void Sound() // will call the correct animal sound
	{
		cout << "Animal can't talk." << endl;
	}
};

class Turtle : public Animal //inherits from animal(public)
{
public: 
	Turtle() //default constructor
	{
		name = "unknown";
	}
	void sound() //overides the sound
	{
		cout << "hiss." << endl;
	}
};

class Cat : public Animal  //inherits from animal(public)
{
public:
	Cat() //default constructor
	{
		name = "unknown";
	}
	void sound() //overides the sound
	{
		cout << "meow." << endl;
	}
};

class Dog : public Animal //inherits from animal(public)
{
public:
	Dog() //default constructor
	{
		name = "unknown";
	}
	void sound() //overides the sound
	{
		cout << "vov-vov." << endl;
	}
};

class Cow : public Animal //inherits from animal(public)
{
public:
	Cow() //default constructor
	{
		name = "unknown";
	}
	void sound() //overides the sound
	{
		cout << "moo." << endl;
	}
};

// Task 3
class Node // class node represents one animal in line
{
public: 
	Animal* data; //pointer to an Animal object
	Node* next; //pointer to the next node in the list

	Node(Animal* a) //constructor for node class
	{
		data = a; //stores the Animal pointer
		next = NULL; //at first the node doesnt point anywhere
	}
};

class AnimalQueue
{
private:
	Node* head; //first node in the list

public:
	AnimalQueue() //constructor
	{
		head = NULL; //waiting line is empty at the start
	}
	void insertEnd(Animal* a) //function receives a pointer to an animal
	{
		Node* newNode = new Node(a); //creates new node containing that animal
		if (head == NULL) //checking if the queue is empty
		{
			head = newNode; //if empty the new node becomes the first node
			return;
		}

		Node* temp = head; //temp pointer that starts at the first node
		while (temp->next != NULL) // move through the list till last node
		{
			temp = temp->next; // move forward one node
		}

		temp->next = newNode; // attach the new node at the end
	}
	void insertAfter(string target, Animal* a) //inserts animal after a specific name
	{
		Node* temp = head; // starts searching from the beginning.
		while (temp != NULL && temp->data->getName() != target) //move through list until we find target
		{
			temp = temp->next; // move forward with the list
		}
		if (temp != NULL) //if we found the target node
		{
			Node* newNode = new Node(a);  //create new node
			newNode->next = temp->next; // make new node point to what comes after sam
			temp->next = newNode; //link sam to nick
		}
	}
	void removeFront() //removes the first node
	{
		if (head == NULL) //checking if queue is empty
		{
			return;
		}
		Node* temp = head; // save the first node
		head = head->next; // move head to the next node
		delete temp; // free the memory of the old node
	}

	// task 4
	void print() // displays the queue
	{
		cout << "Animal Clinic <= ";
		Node* temp = head; // starts from first node
		while (temp != NULL) //loops through entire list
		{
			cout << temp->data->getName(); // prints the animals name

			if (temp->next != NULL)
			{
				cout << ", "; // adds commas between names
			}
			temp = temp->next; // move to next node
		}
		cout << endl;
	}
};

int main()
{
	AnimalQueue line; //creates an object line of type AnimalQueue

	cout << "Time Point 1: " << endl;
	line.print(); //print function runs
	cout << endl;

	Turtle* turtle = new Turtle(); // creates Turtle object in memory
	turtle->setName("Sam"); //calls setName() function from Animal class
	line.insertEnd(turtle); //pass pointer to the turtle into the queue

	cout << "Time Point 2: " << endl;
	line.print(); //print function runs
	cout << endl;

	Cat* cat = new Cat(); // creates Cat object
	cat->setName("Jeff"); // Sets the name
	line.insertEnd(cat); // passes pointer to the end

	cout << "Time Point 3: " << endl;
	line.print(); //print function runs
	cout << endl;

	Dog* dog = new Dog(); // creates Dog object
	dog->setName("Nick"); // sets the name
	line.insertAfter("Sam", dog); // inserts the dog after sam(the turtle)

	cout << "Time Point 4: " << endl;
	line.print(); //print function runs
	cout << endl;

	Cow* cow = new Cow(); // creates Cow object
	cow->setName("Anna"); // sets the name
	line.insertEnd(cow); // inserts to the end of list

	cout << "Time Point 5: " << endl;
	line.print(); //print function runs
	cout << endl; 

	line.removeFront(); // removes the first node

	cout << "Time Point 6: " << endl;
	line.print(); //print function runs
	cout << endl;


	system("pause");
	return 0;
}
