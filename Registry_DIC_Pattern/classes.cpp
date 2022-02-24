#include <iostream>
#include "classes.h"
#include "assertions.h"
#include "registry.h"


std::string IClass::getUid() const noexcept
{
	ASSERT( false, "Base class has no UID." );
	return "";
}


A::A( int i,
	int a )
	:
	IClass(i),
	m_a(a)
{

}

void A::run() cond_noex
{
	std::cout << "A is running\n";
}

std::shared_ptr<A> A::fetch( int i,
	int a )
{
	return Dic::fetch<A>( i,
		a );
}

std::string A::generateUid( int i,
	int a )
{
	using namespace std::string_literals;
	return typeid( A ).name() + ":"s + std::to_string( i ) + "#"s + std::to_string( a );
}

std::string A::getUid() const noexcept
{
	return generateUid( m_i,
		m_a );
}


B::B( int i,
	const std::string& b )
	:
	IClass(i),
	m_b(b)
{

}

void B::run() cond_noex
{
	std::cout << "B is running\n";
}

std::shared_ptr<B> B::fetch( int i,
	const std::string& b )
{
	return Dic::fetch<B>( i,
		b );
}

std::string B::getUid() const noexcept
{
	return generateUid( m_i,
		m_b );
}