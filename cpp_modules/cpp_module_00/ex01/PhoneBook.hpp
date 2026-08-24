/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydylan-k <ydylan-k@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/22 09:35:01 by ydylan-k          #+#    #+#             */
/*   Updated: 2026/08/22 09:35:01 by ydylan-k         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "Contact.hpp"

class PhoneBook
{
	private:
		static const int	MAX_CONTACTS = 8;
		Contact				m_contacts[MAX_CONTACTS];
		int					m_currentIndex;
		int					m_totalContacts;
		void				displayTable() const;
	public:
		PhoneBook();
		void	addContact();
		void	searchContacts();
};

#endif