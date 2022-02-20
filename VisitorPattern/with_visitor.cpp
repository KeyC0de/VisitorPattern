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
	std::cout << person->getName()
		<< " sends greetings\n";
}

void VisitorGreets::visit( Bad* person )
{
	std::cout << person->getName()
		<< " sends greetings\n";
}

void VisitorGreets::visit( Ugly* person )
{
	std::cout << person->getName()
		<< " sends greetings\n";
}

void VisitorStateful::visit( Good* person )
{
	std::cout << person->getName()
		<< " sends greetings to " 
		<< m_pOtherPerson->getName() << '\n';
}

void VisitorStateful::visit( Bad* person )
{
	std::cout << person->getName()
		<< " sends greetings to " 
		<< m_pOtherPerson->getName() << '\n';
}

void VisitorStateful::visit( Ugly* person )
{
	std::cout << person->getName()
		<< " sends greetings to " 
		<< m_pOtherPerson->getName() << '\n';
}