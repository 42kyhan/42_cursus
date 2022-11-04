#ifndef CONVERT_HPP
# define CONVERT_HPP

# include <iostream>
# include <string>
# include <cstdlib>
# include <iomanip>

class Convert
{
private:
	float num_;
	int check_;
	Convert();
public:
	Convert(char const *input);
	~Convert();
	Convert(Convert const &obj);
	Convert& operator=(Convert const &obj);

	void printChar() const;
	void printInt() const;
	void printFloat() const;
	void printDouble() const;

	class OnlyOne : public std::exception
	{
	public:
		const char *what(void) const throw();
	};

	class isNotNumuric : public std::exception
	{
	public:
		const char *what(void) const throw();
	};
};

#endif
