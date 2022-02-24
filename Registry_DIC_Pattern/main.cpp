#include <iostream>
#include <string>
#include "registry.h"
#include "classes.h"


int main()
{
	auto a1 = A::fetch( 5,
		7 );

	auto a2 = A::fetch( 6,
		7 );

	auto a3 = A::fetch( 6,
		7 );

	std::cout << "a1\n";
	std::cout << "id="
		<< a1->getUid()
		<< "\n";
	std::cout << typeid( *a1 ).name() << '\n';

	std::cout << '\n';
	std::cout << "a2\n";
	std::cout << "id="
		<< a2->getUid()
		<< "\n";
	std::cout << typeid( *a2 ).name() << '\n';
	
	std::cout << '\n';
	std::cout << "a3\n";
	std::cout << "id="
		<< a3->getUid()
		<< "\n";
	std::cout << typeid( *a3 ).name() << '\n';

	std::cout << '\n';
	auto b1 = B::fetch( 6,
		"hello" );
	std::cout << "b1\n";
	std::cout << "id="
		<< b1->getUid()
		<< "\n";
	std::cout << typeid( *b1 ).name() << '\n';

	std::cout << std::boolalpha << '\n';
	std::cout << "is a1 different from a2?" << '\n';
	std::cout << (&*a1 != &*a2) << '\n';
	std::cout << "is a2 different from a3?" << '\n';
	std::cout << (&*a2 != &*a3) << '\n';		// a2 and a3 are the same object! no need for useless duplications - the POWER of DIC!


#if defined _DEBUG && !defined NDEBUG
	while ( !getchar() );
#endif
	return EXIT_SUCCESS;
}