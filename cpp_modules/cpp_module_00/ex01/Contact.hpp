/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydylan-k <ydylan-k@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/22 09:35:07 by ydylan-k          #+#    #+#             */
/*   Updated: 2026/08/22 09:35:07 by ydylan-k         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <string>

class Contact
{
	private:
		std::string	m_firstname;
		std::string	m_lastname;
		std::string	m_nickname;
		std::string	m_phonenumber;
		std::string	m_darkestsecret;
		std::string truncateString(const std::string& str) const;
	public:
		Contact();
		bool	addDetails();
		void	displayRow(int index) const;
		void	displayFullDetails() const;
};

#endif