#include <iostream>
#include <fstream>

int	row_count(std::string filename)
{
	int i = 0;
	std::string str;
	std::ifstream myFile(filename);
	while (getline(myFile, str))
	{
		if (str[0] != '\0')
			i++;
	}
	myFile.close();
	return (i);
}

void	copy_content(std::string *fileContent, std::string filename)
{
	int 			i;
	std::ifstream	myFile(filename);
	std::string		str;

	i = 0;
	while (getline(myFile, str))
	{
		fileContent[i] = str;
		i++;
	}
	fileContent[i] = "\0";
	myFile.close();
}

void	create_copy_file(std::string *fileContent, std::string filename)
{
	std::string		fileName = filename.substr(0, filename.find("."));
	std::ofstream	outfile(fileName + "_copy.txt");
	int				i;

	i = 0;
	while (fileContent[i][0] != '\0')
	{
		outfile << fileContent[i] << std::endl;
		i++;
	}
	outfile.close();
}

void	replace(std::string *fileContent, std::string filename, std::string s1, std::string s2)
{
	std::ofstream	myFile(filename);
	int				i;

	i = 0;
	while (fileContent[i][0] != '\0')
	{
		std::cout << fileContent[i] << std::endl;
		if (fileContent[i] == s1)
			myFile << s2 << std::endl;
		else
			myFile << fileContent[i] << std::endl;
		i++;
	}
	myFile.close();
}

bool	is_file_exist(std::string filaname)
{
	std::ifstream infile(filaname);
	return (infile.good());
}

int	main(int ac, char **av)
{
	if (ac == 4)
	{
		std::string fileName = av[1];
		if (!is_file_exist(fileName))
		{
			std::cout << "Error !\nThere is no file named " << fileName << std::endl;
			return (0);
		}
		std::string	s1 = av[2];
		std::string	s2 = av[3];
		int rowCount = row_count(fileName);
		if (rowCount > 0)
		{
			std::string	fileContent[rowCount + 1];
			copy_content(fileContent, fileName);
			create_copy_file(fileContent, fileName);
			replace(fileContent, fileName, s1, s2);
		}
	}
	else
		std::cout << "Error !\nWrong number of arguments ! <filaname> <s1> <s2>" << std::endl;
	return (0);
}
