//#include <iostream>
//
//void Reverse(char* pBegin, char* pEnd)
//{
//	if (pBegin == nullptr || pEnd == nullptr)
//		return;
//
//	while (pBegin < pEnd)
//	{
//		char temp = *pBegin;
//		*pBegin = *pEnd;
//		*pEnd = temp;
//
//		++pBegin, --pEnd;
//	}
//}
//
//char* LeftRotateString(char* pStr, int n)
//{
//	if (pStr != nullptr)
//	{
//		int nLength = static_cast<int>(strlen(pStr));
//		if (nLength > 0 && n > 0 && n < nLength)
//		{
//			char* first = pStr;
//			char* firstEnd = pStr + n - 1;
//			char* second = pStr + n;
//			char* secondEnd = pStr + nLength - 1;
//
//			Reverse(first, firstEnd);
//			Reverse(second, secondEnd);
//			Reverse(first, secondEnd);
//		}
//	}
//	return pStr;
//}
//
//// ====================���Դ���====================
//void Test(const char* testName, char* input, int num, const char* expectedResult)
//{
//	if (testName != nullptr)
//		printf("%s begins: ", testName);
//
//	char* result = LeftRotateString(input, num);
//
//	if ((input == nullptr && expectedResult == nullptr)
//		|| (input != nullptr && strcmp(result, expectedResult) == 0))
//		printf("Passed.\n\n");
//	else
//		printf("Failed.\n\n");
//}
//
//// ���ܲ���
//void Test1()
//{
//	char input[] = "abcdefg";
//	char expected[] = "cdefgab";
//
//	Test("Test1", input, 2, expected);
//}
//
//// �߽�ֵ����
//void Test2()
//{
//	char input[] = "abcdefg";
//	char expected[] = "bcdefga";
//
//	Test("Test2", input, 1, expected);
//}
//
//// �߽�ֵ����
//void Test3()
//{
//	char input[] = "abcdefg";
//	char expected[] = "gabcdef";
//
//	Test("Test3", input, 6, expected);
//}
//
//// ³���Բ���
//void Test4()
//{
//	Test("Test4", nullptr, 6, nullptr);
//}
//
//// ³���Բ���
//void Test5()
//{
//	char input[] = "abcdefg";
//	char expected[] = "abcdefg";
//
//	Test("Test5", input, 0, expected);
//}
//
//// ³���Բ���
//void Test6()
//{
//	char input[] = "abcdefg";
//	char expected[] = "abcdefg";
//
//	Test("Test6", input, 7, expected);
//}
//
//int main(int argc, char* argv[])
//{
//	Test1();
//	Test2();
//	Test3();
//	Test4();
//	Test5();
//	Test6();
//
//	return 0;
//}