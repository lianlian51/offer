//�жϻ�����������һ������ `x` ����� `x` ��һ���������������� `true` ��
//���򣬷��� `false` ����������ָ���򣨴������ң��͵��򣨴������󣩶�����һ�������������磬`121` �ǻ��ģ��� `123` ���ǡ�
//
//���룺x = 12321  �����true
//
//���룺x = 10   �����false
//
//���룺x = -101  �����false
//
//�벻Ҫ������תΪ�ַ��������������⡣


#include <iostream>
#include <vector>

bool func(int number)
{
	if (number < 0)
		return false;

	std::vector<int> vec;
	int temp = number;
	while (temp)
	{
		vec.push_back(temp % 10);
		temp /= 10;
	}

	int len = vec.size();
	int left = 0;
	int right = len - 1;
	while (left < right)
	{
		if (vec[left] != vec[right])
			return false;
		++left, --right;
	}
	return true;
}

int main()
{
	std::cout << func(121) << std::endl;
	std::cout << func(-121) << std::endl;
	std::cout << func(321) << std::endl;
	return 0;
}