#ifndef PMERGEME_HPP
#define PMERGEME_HPP

class PmergeMe
{
	private :
		PmergeMe();
		PmergeMe(const PmergeMe &other);
		~PmergeMe();
		PmergeMe &operator=(const PmergeMe &other);
		static const int kDefaultThreshold = 10;

		template <class T>
		static void mergeInsertSort(T &c, int start, int end, int threshold)
		{
			if (start < end)
			{
				if (end - start < threshold)
					insertSort(c, start, end);
				else
				{
					int mid = start + (end - start) / 2;
					mergeInsertSort(c, start, mid, threshold);
					mergeInsertSort(c, mid + 1, end, threshold);
					merge(c, start, mid, end);
				}
			}
		}

		template <class T>
		static void merge(T &c, int start, int mid, int end)
		{
			int i, j, k;
			int n1 = mid - start + 1;
			int n2 = end - mid;

			T L(n1), R(n2);

			for (i = 0; i < n1; i++)
				L[i] = c[start + i];
			for (j = 0; j < n2; j++)
				R[j] = c[mid + 1 + j];

			i = 0;
			j = 0;
			k = start;
			while (i < n1 && j < n2)
			{
				if (L[i] <= R[j])
				{
					c[k] = L[i];
					i++;
				}
				else
				{
					c[k] = R[j];
					j++;
				}
				k++;
			}
			while (i < n1)
			{
				c[k] = L[i];
				i++;
				k++;
			}
			while (j < n2)
			{
				c[k] = R[j];
				j++;
				k++;
			}
		}

		template <class T>
		static void insertSort(T &c, int start, int end)
		{
			for (int i = start + 1; i <= end; ++i)
			{
				int key = c[i];
				int j = i - 1;
				for (; j >= start && c[j] > key; --j)
					c[j + 1] = c[j];
				c[j + 1] = key;
			}
		}

	public:
		template <class T>
		static void process(T &c, int threshold = PmergeMe::kDefaultThreshold)
		{
			mergeInsertSort(c, 0, c.size() -1, threshold);
		}
};

#endif
