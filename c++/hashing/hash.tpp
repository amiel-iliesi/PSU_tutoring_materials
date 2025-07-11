uint32_t hash_cstring(const char arr[])
{
	uint32_t hash_value = 0u;
	uint32_t pos_scaling = 1u;
	
	for (int i = 0; arr[i] != '\0'; ++i) {
		hash_value += (uint32_t)arr[i] * (++pos_scaling);
	}

	return hash_value;
}

#include <iostream>
template <typename T>
uint32_t hash(const T & key)
{
	//FIXME doesn't work for dynamic memory; try and re-integrate w/ STL interface
	std::size_t size = sizeof(key);
	std::cout << "NOTE: sizeof(" << key << ") = " << size << std::endl;
	uint8_t * curr_byte;

	uint32_t hash_value = 0;

	for (std::size_t byte_index = 0; byte_index < size; ++byte_index) {
		curr_byte = (uint8_t*)&key + byte_index;
	}

	return hash_value;
}
