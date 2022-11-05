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
	class OutOfRange : public std::exception
	{
	public:
		const char *what(void) const throw()
		{
			return ("Out Of Range");
		}
	};

	Array()
	{
		this->len_ = 0;
		this->arr_ = NULL;
	}

	Array(unsigned int n)
	{
		this->len_ = n;
		if (this->len_)
			this->arr_ = new T[this->len_];
	}

	Array(Array const &obj)
	{
		this->len_ = obj.len_;
		if (this->len_)
			this->arr_ = new T[this->len_];
		for (std::size_t i = 0; i < this->len_; i++)
			this->arr_[i] = obj.arr_[i];
	}

	Array& operator=(Array const &obj)
	{
		if (this != &obj)
		{
			if (this->len_)
			{
				delete[] this->arr_;
				this->arr_ = NULL;
				this->len_ = 0;
			}
			this->len_ = obj.len_;
			if (this->len_)
				this->arr_ = new T[this->len_];
			for (std::size_t i = 0; i < this->len_; i++)
				this->arr_[i] = obj.arr_[i];
		}
		return (*this);
	}

	T& operator[](std::size_t i)
	{
		if (i >= this->len_)
			throw OutOfRange();
		return (this->arr_[i]);
	}

	const T& operator[](std::size_t i) const
	{
		if (i >= this->len_)
			throw OutOfRange();
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
