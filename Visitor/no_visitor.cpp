#include <iostream>
#include "no_visitor.h"


void Person::greet()
{
	std::wcout << m_name << L" says hi" << L'\n';
}

void Good::greet()
{
	std::wcout << getName() << L"says hi" << L'\n';
}

void Bad::greet()
{
	std::wcout << getName() << L"says hi" << L'\n';
}

void Ugly::greet()
{
	std::wcout << getName() << L"says hi" << L'\n';
}

void Good::greet( Good* otherPerson )
{
	std::wcout << "Good greets " << otherPerson->getName() << L'\n';
}
void Good::greet( Bad* otherPerson )
{
	std::wcout << "Good greets " << otherPerson->getName() << L'\n';
}
void Good::greet( Ugly* otherPerson )
{
	std::wcout << "Good greets " << otherPerson->getName() << L'\n';
}

void Bad::greet( Good* otherPerson )
{
	std::wcout << "Bad greets " << otherPerson->getName() << L'\n';
}
void Bad::greet( Bad* otherPerson )
{
	std::wcout << "Bad greets " << otherPerson->getName() << L'\n';
}
void Bad::greet( Ugly* otherPerson )
{
	std::wcout << "Bad greets " << otherPerson->getName() << L'\n';
}

void Ugly::greet( Good* otherPerson )
{
	std::wcout << "Ugly greets " << otherPerson->getName() << L'\n';
}
void Ugly::greet( Bad* otherPerson )
{
	std::wcout << "Ugly greets " << otherPerson->getName() << L'\n';
}
void Ugly::greet( Ugly* otherPerson )
{
	std::wcout << "Ugly greets " << otherPerson->getName() << L'\n';
}
