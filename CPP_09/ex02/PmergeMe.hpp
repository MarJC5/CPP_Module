#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <vector>
# include <list>
# include <string>
# include <iomanip>

class PmergeMe
{
	public:
		PmergeMe(int ac, char **av);
		~PmergeMe();
		void process();

	private:
		PmergeMe();
		PmergeMe(PmergeMe const &src);
		PmergeMe &operator=(PmergeMe const &rhs);

		int _size;
		std::vector<int> _sequence;
		std::vector<int> _vec;
		std::list<int> _list;
		std::string _firstContainer;
		std::string _secondContainer;
};

#endif
