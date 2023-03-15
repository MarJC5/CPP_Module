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
		std::string _firstContainer;
		std::string _secondContainer;

		void _sortVector(std::vector<int> &v);
		void _mergeSort(std::vector<int> &v, std::vector<int> &tmp, int start, int end);
		void _merge(std::vector<int> &v, std::vector<int> &tmp, int start, int mid, int end);
};

#endif
