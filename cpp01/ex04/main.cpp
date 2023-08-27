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

int	main(int ac, char **av)
{
	if (ac == 4)
	{
		std::string filename = av[1];
		std::string	s1 = av[2];
		std::string	s2 = av[3];
		int rowCount = row_count(filename);
		if (rowCount > 0)
		{
			std::string	fileContent[rowCount + 1];
			std::string str;
			copy_content(fileContent, filename);
			int i = 0;
			while (i < rowCount)
			{
				std::cout << fileContent[i] << std::endl;
				i++;
			}
		}
	}
	//system("leaks a.out");
	return (0);
}
