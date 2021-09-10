#pragma once

#include <string>


class Good;
class Bad;
class Ugly;

class Person
{
private:
	std::string m_name;
public:
	Person( const std::string& name = "person" )
		:
		m_name{name}
	{

	}
	virtual ~Person() = default;

	virtual void greet();
	virtual void greet( Good* otherPerson ) = 0;
	virtual void greet( Bad* otherPerson ) = 0;
	virtual void greet( Ugly* otherPerson ) = 0;

	std::string getName() const noexcept
	{
		return m_name;
	}
};

class Good
	: public Person
{
public:
	Good( const std::string& name = "Good" )
		:
		Person{name}
	{

	}

	virtual void greet() override;
	void greet( Good* otherPerson ) override;
	void greet( Bad* otherPerson ) override;
	void greet( Ugly* otherPerson ) override;
};

class Bad
	: public Person
{
public:
	Bad( const std::string& name = "Bad" )
		:
		Person{name}
	{

	}

	virtual void greet() override;
	void greet( Good* otherPerson ) override;
	void greet( Bad* otherPerson ) override;
	void greet( Ugly* otherPerson ) override;
};

class Ugly
	: public Person
{
public:
	Ugly( const std::string& name = "Ugly" )
		:
		Person{name}
	{

	}

	virtual void greet() override;
	void greet( Good* otherPerson ) override;
	void greet( Bad* otherPerson ) override;
	void greet( Ugly* otherPerson ) override;
};
