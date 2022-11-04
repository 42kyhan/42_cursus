#include <iostream>
#include <string>

struct Data
{
	std::string data;
};

uintptr_t serialize(Data *ptr)
{
	return (reinterpret_cast<uintptr_t>(ptr));
}

Data *deserialize(uintptr_t raw)
{
	return (reinterpret_cast<Data *>(raw));
}

int main()
{
	Data data1;
	Data *data2;

	data1.data = "이게 나라냐 ;;";
	uintptr_t serial = serialize(&data1);
	std::cout << data1.data << std::endl;
	data2 = deserialize(serial);
	std::cout << data2->data << std::endl;
}
