#include "Serializer.hpp"
#include <iostream>
#include <stdint.h>


int main()
{
	Data		data;
	Data		*data_ptr;
	uintptr_t	serialized_ptr;

	data.value = 42;
	std::cout <<"Original: " << &data << ", value: " << data.value << std::endl;

	serialized_ptr = Serializer::serialize(&data);
	std::cout << "Serialized: " << serialized_ptr << std::endl;

	data_ptr = Serializer::deserialize(serialized_ptr);
	std::cout << "Deserialized: " << data_ptr << ", value: " << data_ptr->value << std::endl;
}
