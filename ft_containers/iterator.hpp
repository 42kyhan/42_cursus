#ifndef ITERATOR_HPP
#define ITERATOR_HPP

#include <cstddef>

namespace ft {

    //iterator base class
    template <class Category, class T, class Distance = ptrdiff_t, 
              class Pointer = T*, class Reference = T&>
        class iterator {
        public::
          typedef T             value_type; // 반복자가 가르키고 있는 값의 요소
          typedef Distance      difference_type; // 반복자의 차이
          typedef Pointer       pointer; // 반복자가 가르키는 값의 포인터
          typedef Reference     reference; // 반복자가 가르키는 값의 레퍼런스
          typedef Category      iterator_category; // 아래의 태그중 하나
      };

    //Category tags
     class input_iterator_tag {}; //읽기만 가능 증가만 함
     class output_iterator_tag {}; //쓰기만 가능 증가만 함
     class forward_iterator_tag : public input_iterator_tag {}; //증가만 함 한번에 여러개 access
     class bidirectional_iterator_tag : public forward_iterator_tag {}; //증가 감소 가능, 한번에 여러개 access
     class random_access_iterator_tag : public bidirectional_iterator_tag {}; // 임의의 위치로 이동가능

    //iterator traits
    template <class Iterator>
        class iterator_traits {
        public:
           typedef typename Iterator::value_type value_type;
           typedef typename Iterator::difference_type difference_type;
           typedef typename Iterator::pointer pointer;
           typedef typename Iterator::reference reference;
           typedef typename Iterator::iterator_category iterator_category;
      };

    template <class T>
        class iterator_traits<T*> {
        public:
           typedef ptrdiff_t difference_type;
           typedef T value_type;
           typedef T* pointer;
           typedef T& reference;
           typedef random_access_iterator_tag iterator_category;
      };
    
    template <class T>
        class iterator_traits<const T*> {
        public:
           typedef ptrdiff_t difference_type;
           typedef T value_type;
           typedef const T* pointer;
           typedef const T& reference;
           typedef random_access_iterator_tag iterator_category;
      };

    //reverse iterator
    template <class Iterator>
        class reverse_iterator {
        protected:
            Iterator current;
        public:
            typedef Iterator iterator_type;
            typedef iterator_traits<Iterator>::difference_type difference_type;
            typedef iterator_traits<Iterator>::pointer pointer;
            typedef iterator_traits<Iterator>::reference reference;

            reverse_iterator() : current(iterator_type()) {}
            explicit reverse_iterator(iterator_type it) : current(it) {}
            template <class Iter>
            reverse_iterator(const reverse_iterator<Iter>& rev_it) : current(rev_it.base()) {}
            template <class Iter>
            reverse_iterator& operator=(cosnt reverse_iterator<Iter>& rev_it) {current = rev_it.base(); return (*this);}

            iterator_type base() const {return (current);}

            reference operator*() const {iterator_type tmp(current); return (*--tmp);}

            reverse_iterator operator+(difference_type n) const {return (reverse_iterator(base() - n));}

            reverse_iterator& operator++() {--current; return(*this);}

            reverse_iterator operator++(int) {reverse_iterator tmp(*this); --current; return(tmp);}

            reveres_iterator& operator+=(difference_type n) {current -= n; return (*this);}

            reverse_iterator operator-(difference_type n) const {return (reverse_iterator(base() + n));}

            reverse_iterator& operator--() {++current; return (*this);}

            reverse_iterator operator--(int) {reverse_iterator tmp(*this); ++current; return(tmp);}

            reverse_iterator& operator-=(difference_type n) {current += n; return (*this);}

            pointer operator->() const {return &(operator*());}

            reference operator[] (difference_type n) const {return (base()[-n-1]);}
        };

        template <class Iterator>
        bool operator==(const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs) {return (lhs.base() == rhs.base());}
        template <class Iterator>
        bool operator!=(const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs) {return (lhs.base() != rhs.base());}
        template <class Iterator>
        bool operator<(const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs) {return (lhs.base() > rhs.base());}
        template <class Iterator>
        bool operator<=(const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs) {return (lhs.base() >= rhs.base());}
        template <class Iterator>
        bool operator>(const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs) {return (lhs.base() < rhs.base());}
        template <class Iterator>
        bool operator>=(const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs) {return (lhs.base() <= rhs.base());}

        template <class Iterator>
        reverse_iterator<Iterator> operator+(typename reverse_iterator<Iterator>::difference_type n, const reverse_iterator<Iterator>& rev_it) {return (rev_it + n);}

        template <class Iterator>
        typename reverse_iterator<Iterator>::difference_type operator-(const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs) {return (rhs.base() - lhs.base());}

    //random access iterator
    //가장 완벽한 반복자
    template <class T>
        class random_access_iterator : public iterator<random_access_iterator_tag, T> {
        public:
            typedef typename iterator<random_access_iterator_tag, T>::difference_type difference_type;
            typedef typename iterator<random_access_iterator_tag, T>::pointer pointer;
            typedef typename iterator<random_access_iterator_tag, T>::reference reference;
        protected:
            pointer _ptr;
        public:
            random_access_iterator() : _ptr(nullptr) {}
            random_access_iterator(pointer ptr) : _ptr(ptr) {}
            random_access_iterator(const random_access_iterator<T>& ref) : _ptr(ref._ptr) {} 
            random_access_iterator& operator=(const random_access_iterator& ref) { if (this != &ref) _ptr = ref._ptr; return (*this);}

            virtual ~random_access_iterator() {}

            pointer base() const {return (_ptr);}

            reference operator*() const {return (*_ptr);}

            pointer operator->() const {return (&(operator*()));}

            random_access_iterator& operator=(T* rhs) {_ptr = rhs; return (*this);}

            random_access_iterator operator+(difference_type n) cosnt {return (_ptr + n);}
        
            random_access_iterator& operator++() {++_ptr; return(*this);}

            random_access_iterator operator++(int) {random_access_iterator tmp(*this); ++_ptr; return(tmp);}

            random_access_iterator operator-(difference_type n) cosnt {return (_ptr - n);}

            random_access_iterator& operator--() {--_ptr; return(*this);}

            random_access_iterator operator--(int) {random_access_iterator tmp(*this); --_ptr; return(tmp);}

            random_access_iterator& operator+=(difference_type n) {_ptr + n; return (*this);}

            random_access_iterator& operator-=(difference_type n) {_ptr - n; return (*this);}

            reference operator[](difference_type n) const {return (_ptr[n]);}
        };
        template <class T>
        bool operator==(const random_access_iterator<T>& lhs, const random_access_iterator<T>& rhs) {return (lhs.base() == rhs.base());}
        template <class T>
        bool operator!=(const random_access_iterator<T>& lhs, const random_access_iterator<T>& rhs) {return (lhs.base() != rhs.base());}
        template <class T>
        bool operator<(const random_access_iterator<T>& lhs, const random_access_iterator<T>& rhs) {return (lhs.base() < rhs.base());}
        template <class T>
        bool operator<=(const random_access_iterator<T>& lhs, const random_access_iterator<T>& rhs) {return (lhs.base() <= rhs.base());}
        template <class T>
        bool operator>(const random_access_iterator<T>& lhs, const random_access_iterator<T>& rhs) {return (lhs.base() > rhs.base());}
        template <class T>
        bool operator>=(const random_access_iterator<T>& lhs, const random_access_iterator<T>& rhs) {return (lhs.base() >= rhs.base());}

        template <class T>
        random_access_iterator<T> operator+(typename random_access_iterator<T>::difference_type n, const random_access_iterator<T>& rand_it) {return (rand_it + n);}

        template <class T>
        typename random_access_iterator<T>::difference_type operator-(const random_access_iterator<T>& lhs, const random_access_iterator<T>& rhs) {return (lhs.base() - rhs.base());}
}

#endif