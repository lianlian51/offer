#include <iostream>

int GetMissingNumber(const int* numbers, int length)
{
	if (numbers == nullptr || length <= 0)
		return -1;

	int left = 0;
	int right = length - 1;
	while (left <= right)
	{
		int mid = (left + right) / 2;
		if (numbers[mid] != mid)
		{
			if (mid == 0 || numbers[mid - 1] == mid - 1)
				return mid;
			else
				right = mid - 1;
		}
		else
			left = mid + 1;
	}

	if (left == length)
		return length;
	return -1;
}

// ====================���Դ���====================
void Test(const char* testName, int numbers[], int length, int expected)
{
	if (testName != nullptr)
		printf("%s begins: ", testName);

	int result = GetMissingNumber(numbers, length);
	if (result == expected)
		printf("Passed.\n");
	else
		printf("Failed.\n");
}

// ȱʧ���ǵ�һ������0
void Test1()
{
	int numbers[] = { 1, 2, 3, 4, 5 };
	int expected = 0;
	Test("Test1", numbers, sizeof(numbers) / sizeof(int), expected);
}

// ȱʧ�������һ������
void Test2()
{
	int numbers[] = { 0, 1, 2, 3, 4 };
	int expected = 5;
	Test("Test2", numbers, sizeof(numbers) / sizeof(int), expected);
}

// ȱʧ�����м�ĳ������0
void Test3()
{
	int numbers[] = { 0, 1, 2, 4, 5 };
	int expected = 3;
	Test("Test3", numbers, sizeof(numbers) / sizeof(int), expected);
}

// ������ֻ��һ�����֣�ȱʧ���ǵ�һ������0
void Test4()
{
	int numbers[] = { 1 };
	int expected = 0;
	Test("Test4", numbers, sizeof(numbers) / sizeof(int), expected);
}

// ������ֻ��һ�����֣�ȱʧ�������һ������1
void Test5()
{
	int numbers[] = { 0 };
	int expected = 1;
	Test("Test5", numbers, sizeof(numbers) / sizeof(int), expected);
}

// ������
void Test6()
{
	int expected = -1;
	Test("Test6", nullptr, 0, expected);
}

int main(int argc, char* argv[])
{
	Test1();
	Test2();
	Test3();
	Test4();
	Test5();
	Test6();

	return 0;
}