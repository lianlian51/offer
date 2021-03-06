#include <iostream>

int GetNumberSameAsIndex(const int* numbers, int length)
{
	if (numbers == nullptr || length <= 0)
		return -1;
	int left = 0;
	int right = length - 1;
	while (left <= right)
	{
		int mid = (left + right) / 2;
		if (numbers[mid] == mid)
			return mid;
		else if (numbers[mid] < mid)
			left = mid + 1;
		else if (numbers[mid] > mid)
			right = mid - 1;
	}
	return -1;
}

// ====================???Դ???====================
void Test(const char* testName, int numbers[], int length, int expected)
{
	if (GetNumberSameAsIndex(numbers, length) == expected)
		printf("%s passed.\n", testName);
	else
		printf("%s FAILED.\n", testName);
}

void Test1()
{
	int numbers[] = { -3, -1, 1, 3, 5 };
	int expected = 3;
	Test("Test1", numbers, sizeof(numbers) / sizeof(int), expected);
}

void Test2()
{
	int numbers[] = { 0, 1, 3, 5, 6 };
	int expected = 0;
	Test("Test2", numbers, sizeof(numbers) / sizeof(int), expected);
}

void Test3()
{
	int numbers[] = { -1, 0, 1, 2, 4 };
	int expected = 4;
	Test("Test3", numbers, sizeof(numbers) / sizeof(int), expected);
}

void Test4()
{
	int numbers[] = { -1, 0, 1, 2, 5 };
	int expected = -1;
	Test("Test4", numbers, sizeof(numbers) / sizeof(int), expected);
}

void Test5()
{
	int numbers[] = { 0 };
	int expected = 0;
	Test("Test5", numbers, sizeof(numbers) / sizeof(int), expected);
}

void Test6()
{
	int numbers[] = { 10 };
	int expected = -1;
	Test("Test6", numbers, sizeof(numbers) / sizeof(int), expected);
}

void Test7()
{
	Test("Test7", nullptr, 0, -1);
}

int main(int argc, char* argv[])
{
	Test1();
	Test2();
	Test3();
	Test4();
	Test5();
	Test6();
	Test7();

	return 0;
}