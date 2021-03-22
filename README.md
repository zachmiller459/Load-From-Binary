# Load-From-Binary
Single header file that allows for easy (and fast) loading of binary files as an array of chars or ints of varying size. 

Using the template in LoadFromBinary.h is more or less straightforward. 
I wrote this to load 16 bit unsigned integers, so my usage looks like this:

#include \<cstdint> // using this library to ensure that the integer is 16 bits

const char* file = "path/to/file.txt";\
uint16_t* data = LoadFromBinary<uint16_t>(file);

// perform some operations on the loaded data

delete[] data; // need to explicitly delete the data variable because it is allocated on the heap

You can use the standard integer types (i.e. unsigned short int), but they can vary in size depending on the platform.