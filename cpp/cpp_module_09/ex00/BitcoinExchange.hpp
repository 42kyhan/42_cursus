#ifndef BITCOTNEXCHANGE_HPP
#define BITCOTNEXCHANGE_HPP

#include <map>
#include <fstream>
#include <iostream>
#include <sstream>

class Btc
{
private:
    int readFlag;
    std::map<std::string, float> data;
public:

    int getReadFlag() {
        return this->readFlag;
    }

    Btc() {
        std::ifstream ifs;
        this->readFlag = 1;
        ifs.open("./data.csv");
        if (ifs.fail()) {
            std::cerr << "Error: Cannot Open File" << std::endl;
            this->readFlag = 0;
            return ;
        }
        
        std::string line;
        bool firstLine = false;
        size_t pos;
        while (std::getline(ifs, line)) {
            if (!firstLine) {
                firstLine = true;
                continue;
            }
            pos = line.find(',');
            if (pos == std::string::npos) {
                std::cerr << "Invalid Format" << std::endl;
                continue;
            }
            std::string date = line.substr(0, pos);
            double value;
            try
            {
                value = std::stod(line.substr(pos + 1));
            }
            catch(const std::exception& e)
            {
                std::cerr << "Error: Exchane rate is invalid" << '\n';
                continue;
            }
            setData(date, value);
        }
        ifs.close();
    }


    ~Btc() {} 


    Btc& operator=(const Btc& obj) {
        if (this != &obj) {
            this->data = obj.data;
            this->readFlag = obj.readFlag;
        }
        return (*this);
    }


    Btc(const Btc& obj) {
        *this = obj;
    }


    void setData(std::string const& date, float const& value) {
        this->data.insert(std::make_pair(date, value));
    }


    void readData(char *file) {
        std::ifstream ifs;
        ifs.open(file);
        if (ifs.fail()) {
            std::cerr << "Error: Fail to open" << std::endl;
            this->readFlag = 0;
            return ;
        }
        bool firstLine = false;
        std::string line;
        while (std::getline(ifs, line)) {
            if (!firstLine) {
                if (line == "date | value") {
                    firstLine = true;
                }
                else {
                    std::cerr << "Error: Invalid format" << std::endl;
                    return ;
                }
                continue;
            }

            size_t pos = line.find('|');
            if (pos == std::string::npos) {
                std::cerr << "Error: Invalid format" << std::endl;
                continue;
            }


            std::string date;
            date = line.substr(0, pos);
            if (date[4] != '-' || date[7] != '-') {
                std::cerr << "Error: Invalid date format" << std::endl;
                continue;
            }
            int year, month, dates;
            try
            {
                year = std::stoi(date.substr(0, 4));
                month = std::stoi(date.substr(5, 2));
                dates = std::stoi(date.substr(8,2));
            }
            catch(const std::exception& e)
            {
                std::cerr << "Error: Invalid date" << '\n';
                continue;
            }
            if (!((month >= 1 && month <= 12) && (dates >= 1 && dates <= 31))) {
                std::cerr << "Error: bad input => " << date << std::endl;
                continue;
            }


            double value;
            try
            {
                value = std::stod(line.substr(pos + 1));
            }
            catch(const std::exception& e)
            {
                std::cerr << "Error: Invalid value" << '\n';
                continue;
            }
            if (value < 0) {
                std::cerr << "Error: not a positive number." << std::endl;
                continue;
            }
            if (value > 1000) {
                std::cerr << "Error: too large a number" << std::endl;
                continue;
            }

            std::map<std::string, float>::iterator it;
            it = this->data.upper_bound(date);
            std::pair<std::string, float> obj;
            obj = *(--it);
            std::cout << date << "=> " << value << " = " << value * obj.second << std::endl;
        }
        ifs.close();
    }
};

#endif