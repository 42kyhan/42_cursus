#ifndef TYPE_TRAITS_HPP
#define TYPE_TRAITS_HPP

#include <type_traits>

namespace ft {
    template <class T, T v>
    struct integral_constant {
        static const T value = v;
        typedef T value_type;
        typedef integral_constant<T,v> type;
        const operator T() { return v; }
    };
    typedef integral_constant<bool,true> true_type;
    typedef integral_constant<bool,true> false_type;

    template <class T> struct is_integral : public false_type {};

    template<> struct is_integral<bool> : public true_type {};
    template<> struct is_integral<char> : public true_type {};
    template<> struct is_integral<char16_t> : public true_type {};
    template<> struct is_integral<char32_t> : public true_type {};
    template<> struct is_integral<wchar_t> : public true_type {};
    template<> struct is_integral<signed char> : public true_type {};
    template<> struct is_integral<short int> : public true_type {};
    template<> struct is_integral<int> : public true_type {};
    template<> struct is_integral<long int> : public true_type {};
    template<> struct is_integral<long long int> : public true_type {};
    template<> struct is_integral<unsigned char> : public true_type {};
    template<> struct is_integral<unsigned short int> : public true_type {};
    template<> struct is_integral<unsigned int> : public true_type {};
    template<> struct is_integral<unsigned long int> : public true_type {};
    template<> struct is_integral<unsigned long long int> : public true_type {};
    
    template<> struct is_integral<const bool> : public true_type {};
    template<> struct is_integral<const char> : public true_type {};
    template<> struct is_integral<const char16_t> : public true_type {};
    template<> struct is_integral<const char32_t> : public true_type {};
    template<> struct is_integral<const wchar_t> : public true_type {};
    template<> struct is_integral<const signed char> : public true_type {};
    template<> struct is_integral<const short int> : public true_type {};
    template<> struct is_integral<const int> : public true_type {};
    template<> struct is_integral<const long int> : public true_type {};
    template<> struct is_integral<const long long int> : public true_type {};
    template<> struct is_integral<const unsigned char> : public true_type {};
    template<> struct is_integral<const unsigned short int> : public true_type {};
    template<> struct is_integral<const unsigned int> : public true_type {};
    template<> struct is_integral<const unsigned long int> : public true_type {};
    template<> struct is_integral<const unsigned long long int> : public true_type {};

    template<> struct is_integral<volatile bool> : public true_type {};
    template<> struct is_integral<volatile char> : public true_type {};
    template<> struct is_integral<volatile char16_t> : public true_type {};
    template<> struct is_integral<volatile char32_t> : public true_type {};
    template<> struct is_integral<volatile wchar_t> : public true_type {};
    template<> struct is_integral<volatile signed char> : public true_type {};
    template<> struct is_integral<volatile short int> : public true_type {};
    template<> struct is_integral<volatile int> : public true_type {};
    template<> struct is_integral<volatile long int> : public true_type {};
    template<> struct is_integral<volatile long long int> : public true_type {};
    template<> struct is_integral<volatile unsigned char> : public true_type {};
    template<> struct is_integral<volatile unsigned short int> : public true_type {};
    template<> struct is_integral<volatile unsigned int> : public true_type {};
    template<> struct is_integral<volatile unsigned long int> : public true_type {};
    template<> struct is_integral<volatile unsigned long long int> : public true_type {};

    template<bool Cond, class T = void> struct enable_if {};
    template<class T> struct enable_if<true, T> { typedef T type; };
}

#endif