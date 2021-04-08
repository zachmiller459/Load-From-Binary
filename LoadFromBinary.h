#ifndef LOADFROMBINARY
#define LOADFROMBINARY

#include <fstream>
#include <cstdint>
#include <iostream>
#include <utility>

template <typename T>
std::pair <unsigned long int, T*> LoadFromBinary(const char* filename)
{
    std::ifstream file(filename, std::ios::in|std::ios::binary|std::ios::ate);
    T* Data;
    if (file.is_open())
    {
        std::streampos Size = file.tellg();
        unsigned int ItemCount = (unsigned int)Size/sizeof(T);
        Data = new T[ItemCount];
        file.seekg(0, std::ios::beg);
        file.read((char*)Data, Size);
        file.close();
        return std::make_pair(ItemCount, Data);
    }
    else
    {
        std::cout << "Error opening file" << std::endl;
        return std::make_pair(0, nullptr);
    }
}
#endif
