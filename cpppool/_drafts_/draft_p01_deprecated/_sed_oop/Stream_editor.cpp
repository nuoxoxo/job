/* ************************************************************************** */
/*                                                                            */
/*                                                       .!.      .:+!^!+:.   */
/*   _                                                  .":      .:!    .:!   */
/*                                                    :!. .!:         !:.     */
/*   By: nuo <marvin@42.fr>                         +.+  :+:       :.:        */
/*                                                .:+!+:._.:.    +.+          */
/*   Created: ____/__/__ __:__:__ by nuo               :..    ...             */
/*   Updated: ____/__/__ __:__:__ by nuo              :._    .:.:_:.:.:.      */
/*                                                                            */
/* ************************************************************************** */

#include "Stream_editor.hpp"

Stream_editor::Stream_editor(void) {}
Stream_editor::~Stream_editor(void) {}

bool	Stream_editor::replace(std::string s1, std::string s2)
{
	//std::string::iterator		it;
	std::string::size_type		it; // ??
	std::string			text;
	std::string			line;
	int				len;

	if (s1 == "" || s2 == "")
	{
		std::cerr << "either s1 or s2 is empty. " << std::endl;
		return false;
	}
	len = s1.length();
	while (getline(input_file_stream, line))
	{
		it = line.find(s1);
		while (it != std::string::npos)
		{
			line.erase(it, len);
			line.insert(it, s2);
			it = line.find(s1);
		}
		line += "\n";
		text.append(line);
	}

	//	Up and down output the same buggy result

	/*
	while (getline(input_file_stream, line))
		text.append(line);
	it = text.find(s1);
	len = s1.length();
	while (it != std::string::npos)
	{
		text.erase(it, len);
		text.insert(it, s2);
		it = text.find(s1);
	}
	*/
	write_infile(text);
	return true;
}

/*

	----------8<-------[ Goal . sed ]------------------

	public:

		Stream_editor(void);
		~Stream_editor(void);
		bool			replace(std::string, std::string);
		bool			setup_infile(std::string);
		bool			write_infile(std::string);

*/

bool	Stream_editor::setup_infile(std::string filename)
{
	if (filename == "")
	{
		std::cerr << "filename cannot be empty. " << std::endl;
		return false;
	}
	if (this->input_file_stream.is_open())
	{
		this->input_file_stream.close();
	}
	this->input_file_stream.open(filename);
	this->filename = filename;
	return true;
}

bool	Stream_editor::write_infile(std::string to_write)
{
	std::string		filename;
	std::ofstream		ofs;

	filename = this->filename;

	/* upcase each char in a string - 2 ways to do it : */

	/* 1st one need incl. algorithm */
	//std::for_each(filename.begin(), filename.end(), [](char &c) { c = ::toupper(c); });
	std::transform(filename.begin(), filename.end(), filename.begin(), ::toupper);

	filename += ".replace";
	ofs.open(filename); // return none, thus always true
	ofs << to_write; // cruicial step
	return true;
}
