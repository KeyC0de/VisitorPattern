#include <iostream>
#include "no_visitor.h"


void Person::greet()
{
	std::cout << m_name
		<< " says hi\n";
}

void Good::greet()
{
	std::cout << getName()
		<< "says hi\n";
}

void Bad::greet()
{
	std::cout << getName()
		<< "says hi\n";
}

void Ugly::greet()
{
	std::cout << getName()
		<< "says hi\n";
}

void Good::greet( Good* otherPerson )
{
	std::cout << "Good greets "
		<< otherPerson->getName()
		<< '\n';
}
void Good::greet( Bad* otherPerson )
{
	std::cout << "Good greets "
		<< otherPerson->getName()
		<< '\n';
}
void Good::greet( Ugly* otherPerson )
{
	std::cout << "Good greets "
		<< otherPerson->getName()
		<< '\n';
}

void Bad::greet( Good* otherPerson )
{
	std::cout << "Bad greets "
		<< otherPerson->getName()
		<< '\n';
}
void Bad::greet( Bad* otherPerson )
{
	std::cout << "Bad greets "
		<< otherPerson->getName()
		<< '\n';
}
void Bad::greet( Ugly* otherPerson )
{
	std::cout << "Bad greets "
		<< otherPerson->getName()
		<< '\n';
}

void Ugly::greet( Good* otherPerson )
{
	std::cout << "Ugly greets "
		<< otherPerson->getName()
		<< '\n';
}
void Ugly::greet( Bad* otherPerson )
{
	std::cout << "Ugly greets "
		<< otherPerson->getName()
		<< '\n';
}
void Ugly::greet( Ugly* otherPerson )
{
	std::cout << "Ugly greets "
		<< otherPerson->getName()
		<< '\n';
}
