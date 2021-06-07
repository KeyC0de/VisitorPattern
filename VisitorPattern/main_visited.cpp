#include "with_visitor.h"


int main()
{
	Person* pg = new Good{};
	Person* pb = new Bad{};
	Person* pu = new Ugly{};

	auto pg2 = std::make_unique<Good>( "Good2" );
	Person* pb2 = new Bad{ "Bad2" };
	auto pu2 = std::make_unique<Ugly>( "Ugly2" );

	VisitorGreets visitorGreets;

	pg->accept( visitorGreets );
	pb->accept( visitorGreets );
	pu->accept( visitorGreets );

	VisitorStateful visitorStateful{std::move( pg2 )};

	pg->accept( visitorStateful );
	pb2->accept( visitorStateful );
	pu2->accept( visitorStateful );

	delete pg;
	delete pb;
	delete pu;
	delete pb2;

	std::system( "pause" );
	return 0;
}
