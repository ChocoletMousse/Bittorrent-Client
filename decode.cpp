#include "pch.h"
#include "readFile.h"
#include "decode.h"
#include <iostream>
#include <string>
#include <vector>
#include <iostream>
#include <fstream>

int pos = 0;

void decode::decodeAll(std::vector<byte> dataVec)
{

	for (auto elem = 0; elem != dataVec.size(); ++elem)
	{
		if (dataVec.at(elem) == numberStart)
		{
			++pos;
			decodeNumber(dataVec, elem);
		}

	}
}


void decode::decodeDictionary()
{
	std::vector<byte> dictionaryStore;
}

void decode::decodeList()
{
	std::vector<byte> listStore;
}

long long decode::decodeNumber(std::vector<byte> dataVec, int startElem)
{
	std::vector<byte> numberStore;
	std::string numAsStr;

	for (auto nextElem = startElem + 1; dataVec.at(nextElem) != numberEnd; ++nextElem)
	{
		{
			numberStore.push_back(dataVec.at(nextElem));
		}
		++pos;
	}

	for (const auto &piece : numberStore)
	{
		numAsStr += piece;
	}
	long long numAsInt = std::stoll(numAsStr);
	return numAsInt;
}
