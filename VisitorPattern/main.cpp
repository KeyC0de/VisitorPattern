#include "no_visitor.h"


int main()
{
	Person* pg = new Good{};
	Person* pg2 = new Good{ "Good2" };
	Person* pb = new Bad{};
	Person* pb2 = new Bad{ "Bad2" };
	Person* pu = new Ugly{};
	Person* pu2 = new Ugly{ "Ugly2" };

	// single dispatch
	pg->greet();
	pb->greet();
	pu->greet();

	// What happens when objects interact with other objects?
	// double dispatch - aka polymorphism
	// Impossible (in C++/Java etc but not on functional languages)
	//		without the visitor pattern!
	// remember the algorithm for dispatching objects!

	// uncomment these and you'll see compile errors.
	// You can't do double dispatch without Visitor in C++!
	//pg->greet( pg2 );
	//pg->greet( pb );
	//pg->greet( pu );
	//
	//pb->greet( pg );
	//pb->greet( pb2 );
	//pb->greet( pu );
	//
	//pu->greet( pg );
	//pu->greet( pb );
	//pu->greet( pu2 );
	
	std::system( "pause" );
	return 0;
}
