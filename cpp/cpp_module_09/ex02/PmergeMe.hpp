#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <deque>
#include <list>
#include <iostream>
#include <ctime>

class PmergeMe
{
private:
    std::deque<int> mergeInsertionDeque;
    std::list<int> mergeInsertionList;
public:
    PmergeMe() { return; }
    ~PmergeMe() {}
    PmergeMe(PmergeMe const &obj) {
        *this = obj;
    }
    PmergeMe& operator=(PmergeMe const &obj) {
        if (this != &obj) {
            this->mergeInsertionDeque = obj.mergeInsertionDeque;
            this->mergeInsertionList = obj.mergeInsertionList;
        }
        return (*this);
    }

    PmergeMe(int ac, char **av) {
        for (int i = 1; i < ac; ++i) {
            int value = atoi(av[i]);
            if (value < 0) {
                std::cerr << "Error" << std::endl;
                return ;
            }
            this->mergeInsertionDeque.push_back(value);
            this->mergeInsertionList.push_back(value);
        }
        std::cout << "Before: ";
        display(this->mergeInsertionDeque);

        clock_t start1 = clock();
        mergeInsertionSortDeque(this->mergeInsertionDeque);
        clock_t end1 = clock();
        clock_t start2 = clock();
        mergeInsertionSortList(this->mergeInsertionList);
        clock_t end2 = clock();

        std::cout << "After:  ";
        display(this->mergeInsertionList);
        std::cout << "Time to process a range of " << this->mergeInsertionDeque.size() << " elements with std::deque : " << double(end1 - start1) / 10000 << " us" << std::endl;
        std::cout << "Time to process a range of " << this->mergeInsertionList.size() << " elements with std::list : " << double(end2 - start2) / 10000  << " us" << std::endl;
    }
    
    template <class T>
    void display(T const &obj) {
        typename T::const_iterator cit;
        for (cit = obj.cbegin(); cit != obj.cend(); ++cit) {
            std::cout << *cit << ' ';
        }
        std::cout << std::endl;
    }

    void mergeInsertionSortDeque(std::deque<int>& arr) {
        if (arr.size() <= 1)
            return ;
        else if (arr.size() <= 20) {
            insertSortDeque(arr);
            return ;
        }
        int mid = arr.size() / 2;
        std::deque<int> left(arr.begin(), arr.begin() + mid);
        std::deque<int> right(arr.begin() + mid, arr.end());

        mergeInsertionSortDeque(left);
        mergeInsertionSortDeque(right);

        arr.clear();
        while (!left.empty() && !right.empty()) {
            if (left.front() <= right.front()) {
                arr.push_back(left.front());
                left.pop_front();
            }
            else {
                arr.push_back(right.front());
                right.pop_front();
            }
        }

        while (!left.empty()) {
            arr.push_back(left.front());
            left.pop_front();
        }
        while (!right.empty()) {
            arr.push_back(right.front());
            right.pop_front();
        }
    }

    void insertSortDeque(std::deque<int>& arr) {
        std::deque<int>::iterator it1, it2;
        for (it1 = ++arr.begin(); it1 != arr.end(); ++it1) {
            int tmp = *it1;
            it2 = it1;
            while (it2 != arr.begin() && *(std::prev(it2)) > tmp) {
                *it2 = *(std::prev(it2));
                std::advance(it2, -1);
            }
            *it2 = tmp;
        }
    }

    void mergeInsertionSortList(std::list<int>& arr) {
        if (arr.size() <= 1)
            return ;
        else if (arr.size() <= 20) {
            insertSortList(arr);
            return ;
        }
        int mid = arr.size() / 2;
        std::list<int> left;
        std::list<int>::iterator it = arr.begin();
        for (int i = 0; i < mid; ++i) {
            left.push_back(*it);
            ++it;
        }
        std::list<int> right(it, arr.end());

        mergeInsertionSortList(left);
        mergeInsertionSortList(right);

        arr.clear();
        while (!left.empty() && !right.empty()) {
            if (left.front() <= right.front()) {
                arr.push_back(left.front());
                left.pop_front();
            }
            else {
                arr.push_back(right.front());
                right.pop_front();
            }
        }

        while (!left.empty()) {
            arr.push_back(left.front());
            left.pop_front();
        }
        while (!right.empty()) {
            arr.push_back(right.front());
            right.pop_front();
        }
    }

    void insertSortList(std::list<int>& arr) {
        std::list<int>::iterator it1, it2;
        for (it1 = ++arr.begin(); it1 != arr.end(); ++it1) {
            int tmp = *it1;
            it2 = it1;
            while (it2 != arr.begin() && *(std::prev(it2)) > tmp) {
                *it2 = *(std::prev(it2));
                std::advance(it2, -1);
            }
            *it2 = tmp;
        }
    }
};

#endif