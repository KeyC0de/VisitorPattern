#include <string>

class Good;
class Bad;
class Ugly;
class Visitor;

class Person
{
private:
	std::wstring m_name;
public:
	Person( const std::wstring& name )
		:
		m_name{ name }
	{}
	virtual void accept( Visitor& visitor ) = 0;
	std::wstring getName() const noexcept
	{
		return m_name;
	}
};

class Good : public Person
{
public:
	Good( const std::wstring& name = L"Good" )
		:
		Person( name )
	{}

	void accept( Visitor& visitor ) override;
};

class Bad : public Person
{
public:
	Bad( const std::wstring& name = L"Bad" )
		:
		Person( name )
	{}

	void accept( Visitor& visitor ) override;
};

class Ugly : public Person
{
public:
	Ugly( const std::wstring& name = L"Ugly" )
		:
		Person( name )
	{}

	void accept( Visitor& visitor ) override;
};

class Visitor
{
public:
	virtual void visit( Good* person ) = 0;
	virtual void visit( Bad* person ) = 0;
	virtual void visit( Ugly* person ) = 0;
};

// operation 1 on `Person`s
class VisitorGreets final : public Visitor
{
public:
	void visit( Good* person ) override;
	void visit( Bad* person ) override;
	void visit( Ugly* person ) override;
};

#include <memory>

// operation 2 on `Person`s
class VisitorStateful final : public Visitor
{
	std::unique_ptr<Person> m_otherPerson;
public:
	VisitorStateful( std::unique_ptr<Person> person )
		:
		m_otherPerson{ std::move( person ) }
	{
	}
	void visit( Good* person ) override;
	void visit( Bad* person ) override;
	void visit( Ugly* person ) override;
};
