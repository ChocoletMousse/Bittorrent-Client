#pragma once
class decode
{
public:
	static void decodeAll(std::vector<byte> dataVec);
	static void decodeDictionary();
	static void decodeList();
	static long long decodeNumber(std::vector<byte> dataVec, int startElem);
private:
	static const byte dictionaryStart = 'd';
	static const byte dictionaryEnd = 'e';
	static const byte listStart = 'l';
	static const byte listEnd = 'e';
	static const byte numberStart = 'i';
	static const byte numberEnd = 'e';
	static const byte arrayDivider = ':';
};

