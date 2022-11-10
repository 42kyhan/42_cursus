#ifndef SPAN_HPP
# define SPAN_HPP

# include <vector>
# include <stdexcept>
# include <iostream>
# include <algorithm>
# include <numeric>
# include <cstdlib>

class Span
{
private:
    std::vector<int> _data;
    Span();
public:
    void    addNumber(int);
    unsigned int shortestSpan();
    unsigned int longestSpan();
    Span(unsigned int);
    Span& operator=(Span);
    Span(Span const &);
    ~Span();
};

#endif
