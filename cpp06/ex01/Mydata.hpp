#ifndef MYDATA_HPP
#define MYDATA_HPP

class Data
{
	public :
		int	value;
		Data(int value);
		Data(const Data &another);
		~Data();
		Data &operator=(const Data &another);
};

#endif
