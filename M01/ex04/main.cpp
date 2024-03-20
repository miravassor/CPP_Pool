/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avassor <avassor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 13:03:54 by avassor           #+#    #+#             */
/*   Updated: 2023/09/20 12:02:39 by avassor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>

void	replace_write(std::ifstream *in, std::ofstream *out, std::string str1, std::string str2)
{
	std::string	buff;

	while (std::getline(*in, buff))
	{
		for (int i = buff.find(str1.c_str(), 0, str1.size()); i >= 0; i = buff.find(str1.c_str(), i, str1.size()))
		{
			for (size_t j = 0; j < str2.size(); j++)
				buff[i + j] = str2[j];
		}
		*out << buff + "\n";
	}
}

int	main(int argc, char **argv) {

	if (argc != 4) {
		std::cout << "Program arguments: FILENAME STRING_TO_FIND REPLACE_STRING" << std::endl;
		return (1);
	}

	std::string		file = argv[1];
	std::string		ofile = argv[1];
	std::string		str1 = argv[2];
	std::string		str2 = argv[3];
	std::ifstream	in;
	std::ofstream	out;

	in.open(file.c_str());
	if (!in)
	{
		std::cout << "File opening error" << std::endl;
		return (1);
	}
	if (in.peek() == std::ifstream::traits_type::eof())
	{
		std::cout << "Empty file" << std::endl;
		return (in.close(), 1);
	}
	ofile += ".replace";
	out.open(ofile.c_str());
	if (!out)
	{
		std::cout << "Output file creation error" << std::endl;
		return (in.close(), 1);
	}
	replace_write(&in, &out, str1, str2);
	in.close();
	out.close();
	return (0);
}
