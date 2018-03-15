/*
参加完Google Girl Hackathon之后,打车回到了。
需要支付给出租车司机车费s元。妞妞身上一共有n个硬币，第i个硬币价值为p[i]元。
想选择尽量多的硬币，使其总价值足以支付s元车费(即大于等于s)。
但是如果从妞妞支付的这些硬币中移除一个或者多个硬币，剩下的硬币总价值还是足以支付车费的话，出租车司机是不会接受的。例如: 使用价值为2，5，7的硬币去支付s=11的车费,出租车司机是不会接受的，因为价值为2这个硬币是可以移除的。
希望能选取最大数量的硬币，使其总价值足以支付车费并且出租车司机能接受。
希望你能帮她计算最多可以支付多少个硬币。

输入描述:
输入包括两行, 第一行包括两个正整数n和s(1 <= n <= 10, 1 <= s <= 1000), 表示妞妞的硬币个数和需要支付的车费。
第二行包括n个正整数p[i] (1 <= p[i] <= 100)，表示第i个硬币的价值。
保证妞妞的n个硬币价值总和是大于等于s。

输出描述:
输出一个整数, 表示妞妞最多可以支付的硬币个数。
/*


#include "stdafx.h"
#include <iostream>
using namespace std;

int main()
{
	int n, s, temp,index=0;
	int P[11];
	int sum = 0;
	int total=0;
	int count_num = 0;
	bool flag = false;
	cin >> n >> s;
	for (int i = 0; i < n; i++)
	{
		cin >> P[i];
	}
	//全排序,从大到小依次排列
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = 0; j < n - i - 1; j++){
			if (P[j] >= P[j + 1])
			{
				temp = P[j + 1];
				P[j + 1] = P[j];
				P[j] = temp;
			}
		}
	}
//从左到右依次累加，直到大于s退出循环
	for (int i = 0; i < n; i++)
	{
		count_num++;
		for (int j = i; j < n; j++)
		{
			total = sum + P[j];
			if (total>= s)
			{
				flag = true;
				index = j;
				total = total - s;
				break;
			}
		}
		if (flag)
			break;
		sum = sum + P[i];
	}
//判断是否存在减去某一个值total依然大于S
	for (int k = index; index >= 0; index--){
		if ( total >= P[index])
		{
			count_num--;
			total = total - P[index];
		}
	}
	cout << count_num << endl;
	return 0;
}
