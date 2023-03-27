#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <deque>
#include <list>
#include <iostream>
#include <ctime>

class PmergeMe
{
private:
    std::deque<int> mergeDeque;
    std::list<int> mergeList;
public:
    PmergeMe() { return; }
    ~PmergeMe() {}
    PmergeMe(PmergeMe const &obj) {
        *this = obj;
    }
    PmergeMe& operator=(PmergeMe const &obj) {
        if (this != &obj) {
            this->mergeDeque = obj.mergeDeque;
            this->mergeList = obj.mergeList;
        }
        return (*this);
    }

    PmergeMe(int ac, char **av) {
        srand(time(NULL));
        for (int i = 1; i < ac; ++i) {
            int value = atoi(av[i]);
            if (value < 0) {
                std::cerr << "Error" << std::endl;
                return ;
            }
            this->mergeDeque.push_back(value);
            this->mergeList.push_back(value);
        }
        std::cout << "Before: ";
        display(this->mergeDeque);

        clock_t start1 = clock();
        sortMergeDeque();
        clock_t end1 = clock();
        clock_t start2 = clock();
        sortMergeList();
        clock_t end2 = clock();

        std::cout << "After:  ";
        display(this->mergeList);
        std::cout << "Time to process a range of " << this->mergeDeque.size() << " elements with std::deque : " << double(end1 - start1) / 10000 << " us" << std::endl;
        std::cout << "Time to process a range of " << this->mergeList.size() << " elements with std::list : " << double(end2 - start2) / 10000  << " us" << std::endl;
    }
    
    template <class T>
    void display(T const &obj) {
        typename T::const_iterator cit;
        for (cit = obj.cbegin(); cit != obj.cend(); ++cit) {
            std::cout << *cit << ' ';
        }
        std::cout << std::endl;
    }

    void sortMergeDeque() {
        std::deque<int>::iterator it1, it2;
        for (it1 = ++this->mergeDeque.begin(); it1 != this->mergeDeque.end(); ++it1) {
            int tmp = *it1;
            it2 = it1;
            while (it2 != mergeDeque.begin() && *(std::prev(it2)) > tmp) {
                *it2 = *(std::prev(it2));
                std::advance(it2, -1);
            }
            *it2 = tmp;
        }
    }

    void sortMergeList() {
        std::list<int>::iterator it1, it2;
        for (it1 = ++this->mergeList.begin(); it1 != this->mergeList.end(); ++it1) {
            int tmp = *it1;
            it2 = it1;
            while (it2 != mergeList.begin() && *(std::prev(it2)) > tmp) {
                *it2 = *(std::prev(it2));
                std::advance(it2, -1);
            }
            *it2 = tmp;
        }
    }
};

#endif