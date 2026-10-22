/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydylan-k <ydylan-k@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/13 00:49:04 by ydylan-k          #+#    #+#             */
/*   Updated: 2026/10/13 00:49:04 by ydylan-k         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

# include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource
{
	private:
		AMateria*	m_learned[4];
	public:
		MateriaSource();
		MateriaSource( const MateriaSource& other );
		MateriaSource&	operator=( const MateriaSource& other );
		virtual	~MateriaSource();

		virtual void		learnMateria( AMateria* m );
		virtual AMateria*	createMateria( std::string const & type );
};

#endif
