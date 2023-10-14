#include "Span.hpp"

Span::Span(unsigned int n) : size(n){}

Span::~Span() {}

Span::Span(const Span &another) {*this = another;}

Span	&Span::operator=(const Span &another)
{
    if (this != &another) {
        this->size = another.size;
        this->myList = another.myList;
    }
    return (*this);
}

void    Span::addNumber(int n)
{
    if (myList.size() < size)
        myList.push_back(n);
    else
        throw std::exception();
}

void    Span::addNumber(std::string numbers)
{
    int num;
    std::stringstream ss(numbers);

    while (ss >> num)
    {
        addNumber(num);
    }
}

int     Span::shortestSpan() const
{
    std::vector<int>    tmp;
    int                 rtn;

    if (myList.size() == 0 || myList.size() == 1)
        throw std::exception();
    tmp = this->myList;
    sort(tmp.begin(), tmp.end());
    rtn = tmp[1] - tmp[0];
    for (unsigned int i = 1; i < tmp.size() - 1; i++)
        rtn = tmp[i + 1] - tmp[i] < rtn ? tmp[i + 1] - tmp[i] : rtn;
    tmp.clear();
    return (rtn);
}

int     Span::longestSpan() const
{
    std::vector<int>    tmp;
    int                 rtn;

    if (myList.size() == 0 || myList.size() == 1)
        throw std::exception();
    tmp = this->myList;
    sort(tmp.begin(), tmp.end());
    rtn = *(tmp.end() - 1) - *(tmp.begin());
    tmp.clear();
    return (rtn);
}