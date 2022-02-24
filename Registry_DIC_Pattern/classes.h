#pragma once

#include <string>
#include <memory>
#include "condnoex.h"


class IClass
{
protected:
	int m_i;
public:
	explicit IClass( int i )
		:
		m_i(i)
	{

	}
	virtual ~IClass() noexcept = default;

	virtual void run() cond_noex = 0;
	virtual std::string getUid() const noexcept;
};

class A
	: public IClass
{
	using Super = A;

	int m_a;
public:
	A( int i, int a );

	virtual void run() cond_noex override;
	static std::shared_ptr<A> fetch( int i, int a );
	static std::string generateUid( int i, int a );
	std::string getUid() const noexcept override;
};

class B
	: public IClass
{
	using Super = B;

	std::string m_b;
public:
	B( int i, const std::string& b );

	virtual void run() cond_noex override;
	static std::shared_ptr<B> fetch( int i, const std::string& b );
	template<typename... TArgsIgnored>
	static std::string generateUid( int i,
		const std::string& b,
		TArgsIgnored&&... )
	{
		using namespace std::string_literals;
		return typeid( B ).name() + ":"s + std::to_string( i ) + "#"s + b;
	}
	std::string getUid() const noexcept override;
};