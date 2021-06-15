
class Solution {
public:
	int findDuplicate(vector<int>& nums) {
		// fisrt :���ַ�
		/*
		int n = nums.size();
		int l = 1, r = n - 1, ans = -1;
		while(l <= r)
		{
		int mid = (l + r) >> 1;
		int cnt = 0;
		for(int i = 0; i < n; ++i)
		{
		if(nums[i] <= mid)
		cnt++;
		}
		if(cnt <= mid)
		l = mid + 1;
		else {
		r = mid - 1;
		ans = mid;
		}
		}
		return ans;
		*/

		// second : �����Ʒ�
		// 1.��ȡ���ı���λ,�����ȡ�ı���λ�����±�
		/*
		int n = nums.size(), ans = 0;
		int bit_max = 31;
		while(!((n - 1) >> bit_max))
		--bit_max;

		for(int bit = 0; bit <= bit_max; ++bit)
		{
		// 1.�ֱ�����ÿһλ1�ĸ���
		// x��¼����nums��1�ĸ�����y��¼[1,n - 1]��1�ĸ���
		int x = 0, y = 0;
		for(int i = 0; i < n; ++i)
		{
		if(nums[i] & (1 << bit))
		++x;
		if(i >= 1 && (i & (1 << bit)))
		++y;
		}
		// x > y˵���Ǹ�λ�õı���λ���ظ����ֵ�
		if(x > y)
		ans |= (1 << bit);
		}
		return ans;
		*/

		// third : ����ָ�롢floyd��Ȧ�㷨
		// ���Ƕ�nums ���齨ͼ��ÿ��λ�� i ��һ�� i��nums[i] �ıߡ����ڴ��ڵ��ظ������� target����� target ���λ��һ������������ָ�����ıߣ��������ͼһ�����ڻ���������Ҫ�ҵ���target �������������ڡ�
		int slow = 0, fast = 0;
		do
		{
			slow = nums[slow];
			fast = nums[nums[fast]];
		} while (fast != slow);

		slow = 0;
		while (slow != fast)
		{
			slow = nums[slow];
			fast = nums[fast];
		}

		return fast;
	}
};