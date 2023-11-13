#include "PmergeMe.hpp"

template <class T>
void	print_container(std::string const &msg, const T &c)
{
	typedef typename T::const_iterator iterator;
	iterator it = c.begin();
	iterator ite = c.end();
	std::cout << msg << std::endl;

	while (it != ite) {
		std::cout << *it << " ";
		it++;
	}
	std::cout << std::endl;
}

template <class T>
double bench_container(T &c)
{
	std::clock_t start = std::clock();
	PmergeMe::process(c);
	clock_t end = std::clock();
	double elapsed = 1000000.0 * (end - start) / CLOCKS_PER_SEC;
	return (elapsed);
}

int main(int ac, char **av)
{
	if (ac > 2) {
		std::vector<int> v;
		std::deque<int> d;
		for (int i = 1; i < ac; i++) {
			std::stringstream ss(av[i]);
			int n;
			ss >> n;
			if (!ss.fail() || !ss.eof()) {
				if (n >= 0) {
					v.push_back(n);
					d.push_back(n);
				} else {
					std::cout << "Error: " << av[i] << " is negative" << std::endl;
					return (1);
				}
			} else {
				std::cout << "Error: " << av[i] << " is not a number" << std::endl;
				return (1);
			}
		}

		print_container("Before :", v);

		double v_time = bench_container(v);
		double d_time = bench_container(d);

		print_container("After :", v);

		std::cout	<< "Time to process a range of "
					<< v.size()
					<< " elements with std::vector : "
					<< v_time
					<< " us"
					<< std::endl;

		std::cout	<< "Time to process a range of "
					<< d.size()
					<< " elements with std::deque : "
					<< d_time
					<< " us"
					<< std::endl;
	} else {
		std::cout << "Usage: ./PmergeMe  [list of numbers]" << std::endl;
		return (1);
	}
}
