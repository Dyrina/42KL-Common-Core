/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   File.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydylan-k <ydylan-k@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/18 12:34:50 by ydylan-k          #+#    #+#             */
/*   Updated: 2026/09/23 15:39:48 by ydylan-k         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "File.hpp"
#include <fstream>
#include <iostream>

File::File( std::string newFilename, std::string str1, std::string str2 ) :
	mInFile(newFilename),
	mOutFile(newFilename + ".replace"),
	mToReplace(str1),
	mReplaceWith(str2)
{}

File::~File() {};

bool	File::replaceFile()
{
	if (mToReplace == "")
	{
		std::cerr << "Error: empty string to find\n";
		return false;
	}
	std::ifstream	inFile(mInFile.c_str());
	if (!inFile.is_open())
	{
		std::cerr << "Error: can't open " << mInFile << "\n";
		return false;
	}
	std::ofstream	outFile(mOutFile.c_str());
	if (!outFile.is_open())
	{
		std::cerr << "Error: can't open " << mOutFile << "\n";
		return false;
	}
	while (!inFile.eof())
	{
		std::string	newLine;
		std::getline(inFile, newLine);
		std::string::size_type	i = 0;
		while (1)
		{
			std::string::size_type	n = newLine.find(mToReplace, i);
			if (n != std::string::npos)
			{
				newLine.erase(n, mToReplace.length());
				newLine.insert(n, mReplaceWith);
				i = n + mReplaceWith.length();
			}
			else
				break ;
		}
		if (inFile.eof())
			outFile << newLine;
		else
			outFile << newLine << "\n";
	}
	outFile.close();
	inFile.close();
	return true;
}