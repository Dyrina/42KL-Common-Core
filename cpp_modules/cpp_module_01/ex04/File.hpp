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
		bool	replaceFile();
};

#endif