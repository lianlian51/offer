#include <iostream>
#include <deque>
#include <vector>
using namespace std;

std::vector<int> maxInWindows(const std::vector<int>& num, unsigned int size)
{
	std::vector<int> res;
	if (size >= 1 && num.size() >= size)
	{
		std::deque<int> temp;
		for (unsigned int i = 0; i < size; ++i)
		{
			while (!temp.empty() && num[i] >= num[temp.back()])
				temp.pop_back();
			temp.push_back(i);
		}

		for (unsigned int i = size; i < (int)num.size(); ++i)
		{
			res.push_back(num[temp.front()]);
			while (!temp.empty() && num[i] >= num[temp.back()])
				temp.pop_back();
			if (!temp.empty() && temp.front() <= (int)(i - size))
				temp.pop_front();
			temp.push_back(i);
		}
		res.push_back(num[temp.front()]);
	}
	return res;
}


// ====================���Դ���====================
void Test(const char* testName, const vector<int>& num, unsigned int size, const vector<int>& expected)
{
	if (testName != nullptr)
		printf("%s begins: ", testName);

	vector<int> result = maxInWindows(num, size);

	vector<int>::const_iterator iterResult = result.begin();
	vector<int>::const_iterator iterExpected = expected.begin();
	while (iterResult < result.end() && iterExpected < expected.end())
	{
		if (*iterResult != *iterExpected)
			break;

		++iterResult;
		++iterExpected;
	}

	if (iterResult == result.end() && iterExpected == expected.end())
		printf("Passed.\n");
	else
		printf("FAILED.\n");
}

void Test1()
{
	int num[] = { 2, 3, 4, 2, 6, 2, 5, 1 };
	vector<int> vecNumbers(num, num + sizeof(num) / sizeof(int));

	int expected[] = { 4, 4, 6, 6, 6, 5 };
	vector<int> vecExpected(expected, expected + sizeof(expected) / sizeof(int));

	unsigned int size = 3;

	Test("Test1", vecNumbers, size, vecExpected);
}

void Test2()
{
	int num[] = { 1, 3, -1, -3, 5, 3, 6, 7 };
	vector<int> vecNumbers(num, num + sizeof(num) / sizeof(int));

	int expected[] = { 3, 3, 5, 5, 6, 7 };
	vector<int> vecExpected(expected, expected + sizeof(expected) / sizeof(int));

	unsigned int size = 3;

	Test("Test2", vecNumbers, size, vecExpected);
}

// �������鵥������
void Test3()
{
	int num[] = { 1, 3, 5, 7, 9, 11, 13, 15 };
	vector<int> vecNumbers(num, num + sizeof(num) / sizeof(int));

	int expected[] = { 7, 9, 11, 13, 15 };
	vector<int> vecExpected(expected, expected + sizeof(expected) / sizeof(int));

	unsigned int size = 4;

	Test("Test3", vecNumbers, size, vecExpected);
}

// �������鵥���ݼ�
void Test4()
{
	int num[] = { 16, 14, 12, 10, 8, 6, 4 };
	vector<int> vecNumbers(num, num + sizeof(num) / sizeof(int));

	int expected[] = { 16, 14, 12 };
	vector<int> vecExpected(expected, expected + sizeof(expected) / sizeof(int));

	unsigned int size = 5;

	Test("Test4", vecNumbers, size, vecExpected);
}

// �������ڵĴ�СΪ1
void Test5()
{
	int num[] = { 10, 14, 12, 11 };
	vector<int> vecNumbers(num, num + sizeof(num) / sizeof(int));

	int expected[] = { 10, 14, 12, 11 };
	vector<int> vecExpected(expected, expected + sizeof(expected) / sizeof(int));

	unsigned int size = 1;

	Test("Test5", vecNumbers, size, vecExpected);
}

// �������ڵĴ�С��������ĳ���
void Test6()
{
	int num[] = { 10, 14, 12, 11 };
	vector<int> vecNumbers(num, num + sizeof(num) / sizeof(int));

	int expected[] = { 14 };
	vector<int> vecExpected(expected, expected + sizeof(expected) / sizeof(int));

	unsigned int size = 4;

	Test("Test6", vecNumbers, size, vecExpected);
}

// �������ڵĴ�СΪ0
void Test7()
{
	int num[] = { 10, 14, 12, 11 };
	vector<int> vecNumbers(num, num + sizeof(num) / sizeof(int));

	vector<int> vecExpected;

	unsigned int size = 0;

	Test("Test7", vecNumbers, size, vecExpected);
}

// �������ڵĴ�С������������ĳ���
void Test8()
{
	int num[] = { 10, 14, 12, 11 };
	vector<int> vecNumbers(num, num + sizeof(num) / sizeof(int));

	vector<int> vecExpected;

	unsigned int size = 5;

	Test("Test8", vecNumbers, size, vecExpected);
}

// ��������Ϊ��
void Test9()
{
	vector<int> vecNumbers;
	vector<int> vecExpected;

	unsigned int size = 5;

	Test("Test9", vecNumbers, size, vecExpected);
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
	Test8();
	Test9();

	return 0;
}