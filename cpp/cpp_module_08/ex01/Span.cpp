#include "Span.hpp"

int op(int n) {return std::abs(n);}

unsigned int Span::shortestSpan()
{
    if (_data.size() < 2)
        throw std::length_error("stored data is too low");
    std::vector<int> sortData(_data);
    std::sort(sortData.begin(), sortData.end());
    std::adjacent_difference(sortData.begin(), sortData.end(), sortData.begin());
    std::transform(sortData.begin(), sortData.end(), sortData.begin(), op);
    return (*std::min_element(sortData.begin(), sortData.end()));
}

unsigned int Span::longestSpan()
{
    if (_data.size() < 2)
        throw std::length_error("stored data is too low");
    std::pair<std::vector<int>::iterator, std::vector<int>::iterator> itPair = std::minmax_element(_data.begin(), _data.end());
    return (*(itPair.second) - *(itPair.first));
}

Span::Span(Span const &obj)
{
    *this = obj;
}

Span& Span::operator=(Span obj)
{
    _data.swap(obj._data);
    return (*this);
}

void Span::addNumber(int n)
{
    try
    {
        if (_data.size() == _data.capacity())
            throw std::out_of_range("Not enough Capacity");
        _data.push_back(n);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
}

Span::Span(unsigned int n) : _data(0, 0)
{
    _data.reserve(n);
}

Span::~Span()
{
}
