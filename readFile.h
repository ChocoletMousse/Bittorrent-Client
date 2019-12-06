#include "pch.h"
#include <iostream>
#include <string>
#include <vector>
#include <iostream>
#include <fstream>
using byte = unsigned char;

class readFile
{
public:
	static std::vector<byte> readAllBytes(const char*);
	static bool validateFormat(std::vector<byte> dataVec);
};

