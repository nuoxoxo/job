/* ************************************************************************** */
/*                                                                            */
/*                                                        ...      :::::::    */
/*   _                                                  ...      :::    :::   */
/*                                                    ... ...         :::     */
/*   By: nxu <marvin@42.fr>                         ...  ...       :::        */
/*                                                ...........   :::           */
/*   Created: ____/__/__ __:__:__ by nxu               ...    :::             */
/*   Updated: ____/__/__ __:__:__ by nxu              ...   ::::::::.fi       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STREAM_EDITOR_HPP
# define STREAM_EDITOR_HPP

# include "iostream"
# include "fstream" // ifs ofs
# include "string"

class	Stream_editor
{
	private:

		std::string		filename;
		//std::string		to_find; // s1
		//std::string		to_replace_with; // s2
		std::ifstream		input_file_stream;

	public:

		Stream_editor(void);
		//~Stream_editor(void);
		virtual			~Stream_editor(void);
		bool			replace(std::string, std::string);
		//bool			replace(std::string to_find, std::string to_replace_with);
		bool			setup_infile(std::string filename);
		bool			write_infile(std::string);
};

#endif

/*

	----------8<-------[ Goal . sed ]------------------

	1. Make a program called ./replace 

	- replace takes a filename and two strings, s1 and s2
		- *Important* s1 and s2 are NOT empty
	- replace will open the file, 
	- replaces every occurrence of s1 with s2
	- writes its contents to FILENAME.replace

*/
