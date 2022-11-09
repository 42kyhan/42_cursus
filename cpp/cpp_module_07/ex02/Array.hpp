#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <iostream>
# include <string>
# include <exception>

template <typename T>
class Array
{
private:
	std::size_t len_;
	T *arr_;
public:
	Array()
	{
		this->len_ = 0;
		this->arr_ = NULL;
	}

	Array(unsigned int n)
	{
		this->len_ = n;
		this->arr_ = new T[this->len_];
	}

	Array(Array const &obj)
	{
		this->len_ = obj.len_;
		this->arr_ = new T[this->len_];
		for (std::size_t i = 0; i < this->len_; i++)
			this->arr_[i] = obj.arr_[i];
	}

	Array& operator=(Array const &obj)
	{
		if (this != &obj)
		{
			delete[] this->arr_;
			this->len_ = obj.len_;
			this->arr_ = new T[this->len_];
			for (std::size_t i = 0; i < this->len_; i++)
				this->arr_[i] = obj.arr_[i];
		}
		return (*this);
	}

	T& operator[](std::size_t i)
	{
		if (i >= this->len_)
			throw std::out_of_range("배열의 index가 초과되었습니다");
		return (this->arr_[i]);
	}

	const T& operator[](std::size_t i) const
	{
		if (i >= this->len_)
			throw std::out_of_range("배열의 index가 초과되었습니다");
		return (this->arr_[i]);
	}
	
	std::size_t size() const
	{
		return (this->len_);
	}

	~Array()
	{
		delete[] this->arr_;
	}
};

#endif
