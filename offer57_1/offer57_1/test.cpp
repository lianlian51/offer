#include <iostream>

bool FindNumbersWithSum(int data[], int length, int sum, int* num1, int* num2)
{
	if (num1 == nullptr || num2 == nullptr || length <= 0)
		return false;
	bool flag = false;

	int start = 0;
	int end = length - 1;

	while (end > start)
	{
		long long curSum = data[start] + data[end];
		if (curSum == sum)
		{
			*num1 = data[start];
			*num2 = data[end];
			flag = true;
			break;
		}
		else if (curSum > sum)
			end--;
		else
			start++;
	}

	return flag;

}

// ====================测试代码====================
void Test(const char* testName, int data[], int length, int sum, bool expectedReturn)
{
	if (testName != nullptr)
		printf("%s begins: ", testName);

	int num1, num2;
	int result = FindNumbersWithSum(data, length, sum, &num1, &num2);
	if (result == expectedReturn)
	{
		if (result)
		{
			if (num1 + num2 == sum)
				printf("Passed. \n");
			else
				printf("FAILED. \n");
		}
		else
			printf("Passed. \n");
	}
	else
		printf("FAILED. \n");
}

// 存在和为s的两个数字，这两个数字位于数组的中间
void Test1()
{
	int data[] = { 1, 2, 4, 7, 11, 15 };
	Test("Test1", data, sizeof(data) / sizeof(int), 15, true);
}

// 存在和为s的两个数字，这两个数字位于数组的两段
void Test2()
{
	int data[] = { 1, 2, 4, 7, 11, 16 };
	Test("Test2", data, sizeof(data) / sizeof(int), 17, true);
}

// 不存在和为s的两个数字
void Test3()
{
	int data[] = { 1, 2, 4, 7, 11, 16 };
	Test("Test3", data, sizeof(data) / sizeof(int), 10, false);
}

// 鲁棒性测试
void Test4()
{
	Test("Test4", nullptr, 0, 0, false);
}

int main(int argc, char* argv[])
{
	Test1();
	Test2();
	Test3();
	Test4();

	return 0;
}