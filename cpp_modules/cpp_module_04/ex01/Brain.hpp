/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydylan-k <ydylan-k@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/13 00:29:23 by ydylan-k          #+#    #+#             */
/*   Updated: 2026/10/13 00:29:23 by ydylan-k         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
# define BRAIN_HPP

# include <string>

class Brain
{
	private:
		std::string			ideas[100];
	public:
		Brain();
		Brain( const Brain& other );
		Brain&				operator=( const Brain& other );
		~Brain();

		const std::string&	getIdea(int index) const;
		void				setIdea(int index, const std::string& idea);
};

#endif
