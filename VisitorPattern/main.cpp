#include "no_visitor.h"
#if defined _DEBUG && !defined NDEBUG
#	include <vld.h>
#endif


int main()
{
	Person* pg = new Good{};
	Person* pg2 = new Good{"Good2"};
	Person* pb = new Bad{};
	Person* pb2 = new Bad{"Bad2"};
	Person* pu = new Ugly{};
	Person* pu2 = new Ugly{"Ugly2"};

	/// Single dispatch
	pg->greet();
	pb->greet();
	pu->greet();

	// What happens when objects interact with other objects?
	/// Double dispatch - aka polymorphism
	// Impossible in C++/Java etc. (but not on functional languages)
	//		... without the visitor pattern!

	// uncomment the following code lines and you'll see compile errors.
	// You can't do double dispatch without Visitor in C++!
	//pg->greet( pg2 );	// no instance of overloaded function "Person::greet"
						// matches the argument list. Argument types are: (Person *), object type is: Person
		// See? C++ does not consider the dynamic type of the arguments when doing function overload resolution
		// remember the algorithm for dispatching objects!
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

	delete pu2;
	delete pu;
	delete pb2;
	delete pb;
	delete pg2;
	delete pg;
	
	std::system( "pause" );
	return 0;
}
