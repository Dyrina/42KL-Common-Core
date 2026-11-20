/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydylan-k <ydylan-k@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/10 23:02:51 by ydylan-k          #+#    #+#             */
/*   Updated: 2026/11/10 23:02:51 by ydylan-k         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <exception>
# include <ostream>
# include <iostream>
# include <string>

class	Bureaucrat
{
	private:
		std::string			m_name;
		short				m_grade;
	public:
		Bureaucrat();
		Bureaucrat( const std::string& newName, const short& newGrade );
		Bureaucrat( const Bureaucrat& other );
		Bureaucrat&			operator=( const Bureaucrat& other );
		~Bureaucrat();

		class GradeTooHighException : public std::exception
		{
			private:
				std::string	m_errorName;
				short		m_errorGrade;
			public:
				GradeTooHighException( std::string name, short grade);
				virtual		~GradeTooHighException() throw();
				std::string	m_errorMessage;
				
		  		virtual const char*	what() const throw();
		};
		class GradeTooLowException : public std::exception
		{
			private:
				std::string	m_errorName;
				short		m_errorGrade;
			public:
				GradeTooLowException( std::string name, short grade);
				virtual		~GradeTooLowException() throw();
				std::string	m_errorMessage;
				
		  		virtual const char*	what() const throw();
		};
		
		std::string		getName() const;
		short			getGrade() const;
		void			incrementGrade();
		void			decrementGrade();
};

std::ostream&	operator<<( std::ostream& oStream, const Bureaucrat& b );

#endif