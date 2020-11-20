#include "with_visitor.h"
#include <iostream>

void Good::accept( Visitor& visitor )
{
	visitor.visit( this );
}

void Bad::accept( Visitor& visitor )
{
	visitor.visit( this );
}

void Ugly::accept( Visitor& visitor )
{
	visitor.visit( this );
}

void VisitorGreets::visit( Good* person )
{
	std::wcout << person->getName() << L" sends greetings" << L'\n';
}

void VisitorGreets::visit( Bad* person )
{
	std::wcout << person->getName() << L" sends greetings" << L'\n';
}

void VisitorGreets::visit( Ugly* person )
{
	std::wcout << person->getName() << L" sends greetings" << L'\n';
}

void VisitorStateful::visit( Good* person )
{
	std::wcout << person->getName()
		<< L" sends greetings to " 
		<< m_otherPerson->getName() << L'\n';
}

void VisitorStateful::visit( Bad* person )
{
	std::wcout << person->getName()
		<< L" sends greetings to " 
		<< m_otherPerson->getName() << L'\n';
}

void VisitorStateful::visit( Ugly* person )
{
	std::wcout << person->getName()
		<< L" sends greetings to " 
		<< m_otherPerson->getName() << L'\n';
}
