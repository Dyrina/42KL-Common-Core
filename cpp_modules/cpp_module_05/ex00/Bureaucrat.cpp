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

Bureaucrat::Bureaucrat() :
	m_name("Bureaucrat"),
	m_grade(validate_grade("Bureaucrat", 150))
{}

Bureaucrat::Bureaucrat( const std::string& newName, const short& newGrade ) :
	m_name(newName),
	m_grade(validate_grade(newName, newGrade))
{}

Bureaucrat::Bureaucrat( const Bureaucrat& other ) :
	m_name(other.getName()),
	m_grade(other.getGrade())
{}

Bureaucrat&		Bureaucrat::operator=( const Bureaucrat &other )
{
	if (this != &other)
	{
		this->m_grade = other.m_grade;
	}
	return (*this);
}

Bureaucrat::~Bureaucrat() {};

const std::string&	Bureaucrat::getName() const
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

Bureaucrat::GradeTooHighException::GradeTooHighException( const std::string& newName, const short& newGrade ) :
	m_errorName(newName),
	m_errorGrade(newGrade),
	m_errorMessage("Bureaucrat::GradeTooHighException: Grade is too high! (Maximum is 1)")	
{}

Bureaucrat::GradeTooHighException::~GradeTooHighException() throw() {}

const char*	Bureaucrat::GradeTooHighException::what() const throw()
{
	return m_errorMessage.c_str();
}

Bureaucrat::GradeTooLowException::GradeTooLowException( const std::string& newName, const short& newGrade ) :
	m_errorName(newName),
	m_errorGrade(newGrade),
	m_errorMessage("Bureaucrat::GradeTooLowException: Grade is too low! (Minimum is 150)")	
{}

Bureaucrat::GradeTooLowException::~GradeTooLowException() throw() {}

const char*	Bureaucrat::GradeTooLowException::what() const throw()
{
	return m_errorMessage.c_str();
}

std::ostream&	operator<<( std::ostream& oStream, const Bureaucrat& b )
{
	oStream << b.getName() << ", bureaucrat grade " << b.getGrade();
	return (oStream);
}

short	Bureaucrat::validate_grade( const std::string& newName, const short& newGrade )
{
	if (newGrade < 1)
		throw Bureaucrat::GradeTooHighException(newName, newGrade);
	else if (newGrade > 150)
		throw Bureaucrat::GradeTooLowException(newName, newGrade);
	return (newGrade);
}