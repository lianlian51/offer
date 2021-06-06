#include <stdio.h>
#include <cstring>
#include <iostream>

char FirstNotRepeatingChar(const char* pString)
{
	if (pString == nullptr)
		return '\0';

	const int hashSize = 256;
	unsigned int hashTable[hashSize];

	for (int i = 0; i < 256; ++i)
		hashTable[i] = 0;

	const char* scan = pString;
	while (*scan != '\0')
	{
		hashTable[*scan]++;
		++scan;
	}

	scan = pString;
	while (*scan != '\0')
	{
		if (hashTable[*scan] == 1)
			return *scan;
		scan++;
	}

	return '\0';
}


// ====================���Դ���====================
void Test(const char* pString, char expected)
{
	if (FirstNotRepeatingChar(pString) == expected)
		printf("Test passed.\n");
	else
		printf("Test failed.\n");
}

int main(int argc, char* argv[])
{
	// ����������ԣ�����ֻ����һ�ε��ַ�
	Test("google", 'l');

	// ����������ԣ�������ֻ����һ�ε��ַ�
	Test("aabccdbd", '\0');

	// ����������ԣ������ַ���ֻ����һ��
	Test("abcdefg", 'a');

	// ³���Բ��ԣ�����nullptr
	Test(nullptr, '\0');

	return 0;
}
