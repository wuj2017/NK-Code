
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
	//ȫ����,�Ӵ�С��������
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
//�����������ۼӣ�ֱ������s�˳�ѭ��
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
//�ж��Ƿ���ڼ�ȥĳһ��ֵtotal��Ȼ����S
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