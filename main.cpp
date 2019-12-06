#include "pch.h"
#include "readFile.h"
#include "decode.h"
#include <iostream>
#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <iomanip>


int main()
{
	const char* filename = "numberdecode.torrent";
	std::vector<byte> dataVec = readFile::readAllBytes(filename);

	/*if (!readFile::validateFormat(dataVec))
	{
		std::cerr << "Invalid format" << std::endl;
		return -1;
	}*/

	decode::decodeAll(dataVec);

	//Convert byte array to hexadecimal string
	std::ostringstream ss;
	ss << std::hex << std::uppercase << std::setfill('0');
	for (int c : dataVec) {
		ss << std::setw(2) << c;
	}
	std::string result = ss.str();
	std::cout << result << std::endl << std::endl;

	//convert to string using string constructor with initial and final vector positions
	std::string dataString(dataVec.begin(), dataVec.end());

	//find string "fail" in torrent data string to throw error
	std::string fail("fail");
	if (dataString.find(fail) == std::string::npos)
	{
		std::cout << dataString << std::endl;;
		return 0;
	}
	else
	{
		std::cerr << "File failed to open: " << filename << std::endl;
		return -1;
	}
}