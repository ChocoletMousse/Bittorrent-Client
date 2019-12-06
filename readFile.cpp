#include "pch.h"
#include "readFile.h"
#include <iostream>
#include <string>
#include <vector>
#include <iostream>
#include <fstream>

std::vector<byte> readFile::readAllBytes(const char* filename)
{
	//open file in binary mode and set pos to end of file
	std::ifstream torrentfile(filename, std::ios::binary | std::ios::ate);

	if (torrentfile)
	{
		//Return the position of the current character in the input stream
		std::ifstream::pos_type pos = torrentfile.tellg();

		//store pos in vector
		std::vector<char> result(pos);

		//set pos of next character to be extracted to offset 0 relative to beginning 
		//of stream
		torrentfile.seekg(0, std::ios::beg);

		//Extracts pos number of characters from the stream and stores 
		//them in result[0].
		torrentfile.read(&result[0], pos);

		//copy signed char vector to unsigned char vector for accurate hex 
		//conversion without sign extension
		std::vector<byte> uChar;
		copy(result.begin(), result.end(), back_inserter(uChar));

		return uChar;
	}

	else
	{
		std::vector<byte> fail{ 'f', 'a', 'i', 'l' };
		return fail;
	}
	
}

bool readFile::validateFormat(std::vector<byte> dataVec)
{
	if ((static_cast<char>(dataVec.front()) == 'd') &&
		(static_cast<char>(dataVec.back()) == 'e'))
	{
		return true;
	}
	else
	{
		return false;
	}
	//for (std::vector<byte>::iterator it = dataVec.begin(); it != dataVec.end(); ++it)
	//{
	//	return static_cast<char>(*it);
	//}
}