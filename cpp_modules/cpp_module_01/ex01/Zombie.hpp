#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <string>

class Zombie
{
	private:
		std::string	name;
	public:
		Zombie();
		Zombie( const std::string newName );
		~Zombie();

		void		setName( const std::string newName );
		void		announce( void );
};

#endif