/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydylan-k <ydylan-k@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/09 17:57:09 by ydylan-k          #+#    #+#             */
/*   Updated: 2026/08/09 19:30:35 by ydylan-k         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

int	main(int argc, char **argv)
{
	if (argc == 1)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *\n";
		return (0);
	}
	for (int i = 1; i < argc; ++i)
	{
		std::string current_arg(argv[i]);
		for (size_t i = 0; i < current_arg.length(); ++i)
		{
			current_arg[i] = std::toupper(static_cast<unsigned char>(current_arg[i]));
		}
		std::cout << current_arg;
	}
	std::cout << '\n';
	return (0);
}