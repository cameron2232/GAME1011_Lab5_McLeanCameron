#include "DynTempQueue.h"
#include "DynTempStack.h"

class Book
{
public:
	Book() {}

	Book(std::string name)
	{
		BookName = name;
	}

	std::string BookName;
};

std::ostream& operator<<(std::ostream& out, Book& printBook)
{
	out << printBook.BookName;

	return out;
}

class Grade
{
public:
	Grade(){}

	Grade(std::string name, int grade)
	{
		this->name = name;
		this->grade = grade;
	}

	std::string name;
	int grade;
};

std::ostream& operator<<(std::ostream& out, Grade& student)
{
	out << student.name << ": " << student.grade;

	return out;
}


int main()
{
	std::vector<Book> Books{ Book("Harry Potter"), Book("Lord of the Rings"), Book("How to Train your Dragon"), Book("Game of Thrones"),
	Book("The Hunger Games"), Book("IT"), Book("A Clockwork Orange")};

	std::vector<Grade> Grades{ Grade("Jonny", 80), Grade("Richard", 98), Grade("Leeroy", 101), Grade("Ava", 95), Grade("Garfunkle", 64) };
	
	int poppedStack;
	std::string poppedQueue;
	Book poppedBook;
	Grade poppedGrade;
	
	
	DynTempStack<int> intStack;
	DynTempStack<Book> bookStack;
	
	DynTempQueue<std::string> stringQueue;
	DynTempQueue<Grade> gradeQueue;

	std::cout << "STACK OF INTEGERS\n";
	intStack.push(1);
	intStack.push(2);
	intStack.push(3);
	intStack.push(4);
	intStack.push(5);
	intStack.push(6);
	intStack.pop(poppedStack);
	intStack.pop(poppedStack);
	intStack.pop(poppedStack);
	intStack.pop(poppedStack);
	
	std::cout << "\nSTACK OF BOOKS\n";
	for (Book BookToInsert : Books)
	{
		bookStack.push(BookToInsert);
	}
	bookStack.pop(poppedBook);
	bookStack.pop(poppedBook);
	bookStack.pop(poppedBook);
	bookStack.pop(poppedBook);

	std::cout << "\nQUEUE OF STRINGS\n";
	stringQueue.enqueue("Do?");
	stringQueue.enqueue("You");
	stringQueue.enqueue("Do");
	stringQueue.enqueue("How");
	stringQueue.enqueue("World");
	stringQueue.enqueue("Hello");
	stringQueue.dequeue(poppedQueue);
	stringQueue.dequeue(poppedQueue);
	stringQueue.enqueue("Before!");
	stringQueue.enqueue("I am");

	std::cout << "\nQUEUE OF STUDENTS WITH GRADES\n";
	for (Grade student : Grades)
	{
		gradeQueue.enqueue(student);
	}
	gradeQueue.dequeue(poppedGrade);
	gradeQueue.dequeue(poppedGrade);
	gradeQueue.dequeue(poppedGrade);
	gradeQueue.dequeue(poppedGrade);
	gradeQueue.dequeue(poppedGrade);
	gradeQueue.enqueue(Grades[2]);
	
}

