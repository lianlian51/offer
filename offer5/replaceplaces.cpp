#include <cstdio>
#include <cstring>

// length表示字符数组的总容量
void ReplaceBlank(char str[], int length)
{
  if(str == NULL || length <= 0)
  {
    return;
  }

  // 1.计算新字符数组的长度
  int strLength = 0;
  int black = 0;
  int i = 0;
  while(str[i] != '\0'){
    if(str[i] == ' ')
      black++;
    strLength++;
    ++i;
  }

  int newLength = strLength + black * 2;
  // 处理越界行为
  if(newLength > length)
    return;

  while(strLength >= 0 && strLength < newLength)
  {
    if(str[strLength] == ' '){
      str[newLength--] = '0';
      str[newLength--] = '2';
      str[newLength--] = '%';
      strLength--;
    }
    else 
      str[newLength--] = str[strLength--];
  }
}

// ====================测试代码====================
void Test(const char* testName, char str[], int length, const char expected[])
{
  if(testName != NULL)
    printf("%s begins: ", testName);

  ReplaceBlank(str, length);

  if(expected == NULL && str == NULL)
    printf("passed.\n");
  else if(expected == NULL && str != NULL)
    printf("failed.\n");
  else if(strcmp(str, expected) == 0)
    printf("passed.\n");
  else
    printf("failed.\n");
}

// 空格在句子中间
void Test1()
{
  const int length = 100;

  char str[length] = "hello world";
  Test("Test1", str, length, "hello%20world");
}

// 空格在句子开头
void Test2()
{
  const int length = 100;

  char str[length] = " helloworld";
  Test("Test2", str, length, "%20helloworld");
}

// 空格在句子末尾
void Test3()
{
  const int length = 100;

  char str[length] = "helloworld ";
  Test("Test3", str, length, "helloworld%20");
}

// 连续有两个空格
void Test4()
{
  const int length = 100;

  char str[length] = "hello  world";
  Test("Test4", str, length, "hello%20%20world");
}

// 传入nullptr
void Test5()
{
  Test("Test5", NULL, 0, NULL);
}

// 传入内容为空的字符串
void Test6()
{
  const int length = 100;

  char str[length] = "";
  Test("Test6", str, length, "");
}

//传入内容为一个空格的字符串
void Test7()
{
  const int length = 100;

  char str[length] = " ";
  Test("Test7", str, length, "%20");
}

// 传入的字符串没有空格
void Test8()
{
  const int length = 100;

  char str[length] = "helloworld";
  Test("Test8", str, length, "helloworld");
}

// 传入的字符串全是空格
void Test9()
{
  const int length = 100;

  char str[length] = "   ";
  Test("Test9", str, length, "%20%20%20");
}

int main()
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

