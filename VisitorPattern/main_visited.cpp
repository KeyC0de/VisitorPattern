#include <memory>
#include "with_visitor.h"
#if defined _DEBUG && !defined NDEBUG
#	pragma comment( lib, "C:/Program Files (x86)/Visual Leak Detector/lib/Win64/vld.lib" )
#	include <C:/Program Files (x86)/Visual Leak Detector/include/vld.h>
#endif


int main()
{
	Person* pg = new Good{};
	std::unique_ptr<Person> pb = std::make_unique<Bad>();
	std::unique_ptr<Person> pu = std::make_unique<Ugly>();

	auto pg2 = std::make_unique<Good>( "Good2" );
	std::unique_ptr<Person> pb2 = std::make_unique<Bad>( "Bad2" );
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

#if defined _DEBUG && !defined NDEBUG
	while ( !getchar() );
#endif
	return EXIT_SUCCESS;
}