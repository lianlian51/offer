#include <iostream>

bool g_InvalidInput = false;

int FindGreatestSumOfSubArray(int *pData, int nLength)
{
	if (pData == nullptr || nLength <= 0)
	{
		g_InvalidInput = true;
		return 0;
	}

	int ret = 0;
	int retSum = INT_MIN;
	for (int i = 0; i < nLength; ++i)
	{
		if (ret <= 0)
			ret = pData[i];
		else
			ret += pData[i];

		if (ret > retSum)
			retSum = ret;
	}
	return retSum;
}

// ====================测试代码====================
void Test(char* testName, int* pData, int nLength, int expected, bool expectedFlag)
{
	if (testName != nullptr)
		printf("%s begins: \n", testName);

	int result = FindGreatestSumOfSubArray(pData, nLength);
	if (result == expected && expectedFlag == g_InvalidInput)
		printf("Passed.\n");
	else
		printf("Failed.\n");
}

// 1, -2, 3, 10, -4, 7, 2, -5
void Test1()
{
	int data[] = { 1, -2, 3, 10, -4, 7, 2, -5 };
	Test("Test1", data, sizeof(data) / sizeof(int), 18, false);
}

// 所有数字都是负数
// -2, -8, -1, -5, -9
void Test2()
{
	int data[] = { -2, -8, -1, -5, -9 };
	Test("Test2", data, sizeof(data) / sizeof(int), -1, false);
}

// 所有数字都是正数
// 2, 8, 1, 5, 9
void Test3()
{
	int data[] = { 2, 8, 1, 5, 9 };
	Test("Test3", data, sizeof(data) / sizeof(int), 25, false);
}

// 无效输入
void Test4()
{
	Test("Test4", nullptr, 0, 0, true);
}

int main(int argc, char* argv[])
{
	Test1();
	Test2();
	Test3();
	Test4();

	return 0;
}
