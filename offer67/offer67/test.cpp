#include<iostream>

long long StrToIntCore(const char* str, bool minus);

enum Status{KValid=0, KInVaild};
int g_Status = KValid;


int StrToInt(const char* str)
{
	g_Status = KInVaild;
	long long num = 0;
	if (str != nullptr && *str != '\0')
	{
		bool minus = false;
		if (*str == '+')
		{
			++str;
		}
		else if (*str == '-')
		{
			++str, minus = true;
		}
		if (*str != '\0')
		{
			num = StrToIntCore(str, minus);
		}
	}

	return (int)num;
}

long long StrToIntCore(const char* str, bool minus)
{
	long long num = 0;

	while (*str != '\0')
	{
		if (*str >= '0' && *str <= '9')
		{
			int flag = minus ? -1 : 1;
			num = num * 10 + flag*(*str - '0');

			// �������
			if (!minus && num > 0x7FFFFFFF || minus && num < (signed int)0x80000000)
			{
				num = 0;
				break;
			}
			++str;
		}
		else
		{
			num = 0;
			break;
		}
	}

	// ����ַ�ת����ϣ����Ƿ��ַ��ı�־λ����
	if (*str == '\0')
	{
		g_Status = KValid;
	}
	return num;
}

// ====================���Դ���====================
void Test(const char* string)
{
	int result = StrToInt(string);
	if (result == 0 && g_Status == KInVaild)
		printf("the input %s is invalid.\n", string);
	else
		printf("number for %s is: %d.\n", string, result);
}

int main(int argc, char* argv[])
{
	Test(nullptr);

	Test("");

	Test("123");

	Test("+123");

	Test("-123");

	Test("1a33");

	Test("+0");

	Test("-0");

	//��Ч�����������, 0x7FFFFFFF
	Test("+2147483647");

	Test("-2147483647");

	Test("+2147483648");

	//��Ч����С������, 0x80000000
	Test("-2147483648");

	Test("+2147483649");

	Test("-2147483649");

	Test("+");

	Test("-");

	return 0;
}