/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   File.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydylan-k <ydylan-k@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/18 12:34:47 by ydylan-k          #+#    #+#             */
/*   Updated: 2026/09/23 15:33:46 by ydylan-k         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILE_HPP
# define FILE_HPP

# include <string>

class	File
{
	private:
		std::string	mInFile;
		std::string	mOutFile;
		std::string	mToReplace;
		std::string	mReplaceWith;
	public:
		File( std::string newFilename, std::string str1, std::string str2 );
		~File();
		bool		replaceFile();
};

#endif