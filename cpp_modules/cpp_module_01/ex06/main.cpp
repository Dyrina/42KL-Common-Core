/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydylan-k <ydylan-k@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/22 20:16:06 by ydylan-k          #+#    #+#             */
/*   Updated: 2026/09/23 16:18:13 by ydylan-k         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int	main(int argc, char *argv[])
{
	if (argc != 2)
		return 1;

	Harl	newHarl;
	newHarl.complain(argv[1]);
}