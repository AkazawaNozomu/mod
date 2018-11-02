#include<bits/stdc++.h>
#define endl "\n"
typedef long long ll;
using namespace std;
const int maxn=1e5+5,inf=2e8;
int a[maxn],st[maxn];
ll sum[maxn];
//sum[i]保存以i为结尾的最大子串和
//st[i]保存以i结尾的最大子串和的开头
//ans为和最大的结尾
//a中最大子串为a[st[ans],ans],和为sum[ans] 
ll max_sub_sum(int len)//长度为len
{
	for(int i=1;i<=n;i++)sum[i]=-inf;
	memset(st,0,sizeof(st));
	st[0]=1;
	for(int i=1;i<=n;i++)
	{
		if(sum[i-1]<0)
		{
			sum[i]=a[i];
			st[i]=i;
		}
		else
		{
			sum[i]=sum[i-1]+a[i];
			st[i]=st[i-1];
		}
	}
	int ans=1;
	for(int i=2;i<=n;i++)
	{
		if(sum[i]>sum[ans])ans=i;
	}
	return sum[ans];
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
}

