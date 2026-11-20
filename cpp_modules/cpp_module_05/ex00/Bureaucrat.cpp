/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydylan-k <ydylan-k@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/10 23:02:57 by ydylan-k          #+#    #+#             */
/*   Updated: 2026/11/10 23:02:57 by ydylan-k         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include <cstdlib>
#include <ostream>

Bureaucrat::Bureaucrat() :
	m_name("Bob"),
	m_grade(150)
{
	if (m_grade < 1)
		throw Bureaucrat::GradeTooHighException(m_name, m_grade);
	else if (m_grade > 150)
		throw Bureaucrat::GradeTooLowException(m_name, m_grade);
}

Bureaucrat::Bureaucrat( const std::string& newName, const short& newGrade ) :
	m_name(newName),
	m_grade(newGrade)
{
	if (m_grade < 1)
		throw Bureaucrat::GradeTooHighException(m_name, m_grade);
	else if (m_grade > 150)
		throw Bureaucrat::GradeTooLowException(m_name, m_grade);
}

Bureaucrat::Bureaucrat( const Bureaucrat& other )
{
	*this = other;
}

Bureaucrat&		Bureaucrat::operator=( const Bureaucrat &other )
{
	if (this != &other)
	{
		this->m_grade = other.m_grade;
		this->m_name = other.m_name;
	}
	return (*this);
}

Bureaucrat::~Bureaucrat() {};

std::string		Bureaucrat::getName() const
{
	return (m_name);
}

short	Bureaucrat::getGrade() const
{
	return (m_grade);
}

void	Bureaucrat::incrementGrade()
{
	if (m_grade - 1 < 1)
		throw Bureaucrat::GradeTooHighException(m_name, m_grade);
	m_grade--;
}

void	Bureaucrat::decrementGrade()
{
	if (m_grade + 1 > 150)
		throw Bureaucrat::GradeTooLowException(m_name, m_grade);
	m_grade++;
}

/****************************************************************************/

Bureaucrat::GradeTooHighException::GradeTooHighException( std::string newName, short newGrade ) :
	m_errorName(newName),
	m_errorGrade(newGrade),
	m_errorMessage("Bureaucrat::GradeTooHighException")	
{}

Bureaucrat::GradeTooHighException::~GradeTooHighException() throw() {}

const char*	Bureaucrat::GradeTooHighException::what() const throw()
{
	return m_errorMessage.c_str();
}

Bureaucrat::GradeTooLowException::GradeTooLowException( std::string newName, short newGrade ) :
	m_errorName(newName),
	m_errorGrade(newGrade),
	m_errorMessage("Bureaucrat::GradeTooLowException")	
{}

Bureaucrat::GradeTooLowException::~GradeTooLowException() throw() {}

const char*	Bureaucrat::GradeTooLowException::what() const throw()
{
	return m_errorMessage.c_str();
}

std::ostream&	operator<<( std::ostream& oStream, const Bureaucrat& b )
{
	oStream << b.getName() << ", bureaucrat grade " << b.getGrade() << ".\n";
	return (oStream);
}
