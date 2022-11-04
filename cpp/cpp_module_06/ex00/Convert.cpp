#include "Convert.hpp"

const char *Convert::isNotNumuric::what(void) const throw()
{
	return ("슦지마세요 ㅡㅡ");
}

const char *Convert::OnlyOne::what(void) const throw()
{
	return ("한글자만 입력하셈");
}

Convert& Convert::operator=(Convert const &obj)
{
	if (this != &obj)
	{
		this->num_ = obj.num_;
	}
	return (*this);
}

Convert::Convert(Convert const &obj)
{
	*this = obj;
}

Convert::~Convert()
{
}

bool isNumeric(std::string &input)
{
	std::string::iterator it = input.begin();
	while (it != input.end() && std::isdigit(*it))
		it++;
	return (it == input.end());
}

Convert::Convert(char const *input)
{
	
	std::string ccc(input);
	try
	{
		if (isdigit(ccc[0]) && isNumeric(ccc) == false)
			throw isNotNumuric();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
		return ;
	}
	this->num_ = atof(input);
	if (!this->num_)
	{
		this->check_ = static_cast<int>(*input);
		if (ccc[0] != '0' && !(this->check_ == 0 && this->num_ == 0))
		{
			try
			{
				if (ccc.length() != 1)
					throw OnlyOne();
			}
			catch(const std::exception& e)
			{
				std::cerr << e.what() << '\n';
				return ;
			}
			this->num_ = this->check_;
		}
	}
	printChar();
	printInt();
	printFloat();
	printDouble();
}

void Convert::printChar() const
{
	if (!(this->num_ >= CHAR_MIN && this->num_ <= CHAR_MAX))
		std::cout << "char: impossible" << std::endl;
	else if (!(this->num_ >= 33 && this->num_ <= 126))
		std::cout << "char: Non displayable" << std::endl;
	else
		std::cout << "char: '" << static_cast<char>(this->num_) << "'" << std::endl;
}

void Convert::printInt() const
{
	if (this->num_ <= INT_MAX && this->num_ >= INT_MIN)
		std::cout << "int: " << static_cast<int>(this->num_) << std::endl;
	else
		std::cout << "int: impossible" << std::endl;
}

void Convert::printFloat() const
{
	std::cout << "float: " << std::fixed << std::setprecision(1) << static_cast<float>(this->num_) << "f" << std::endl;
}

void Convert::printDouble() const
{
	std::cout << "double: " << std::fixed << std::setprecision(1) << this->num_ << std::endl;
}
