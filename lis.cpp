#include<bits/stdc++.h>
#define endl "\n"
typedef long long ll;
using namespace std;
const int maxn=1e5+5;
int a[maxn],back[maxn],ans=0;
//严格递增
int find(int x,int len)//x在back[1,len]中下标
{
	return lower_bound(back+1,back+len+1,x)-back;//不要求严格递增此处改成upper
}
int solve(int len)//长度为len
{
	int res=0;
	memset(back,0,sizeof(back));//要求数组元素均为正 
	for(int i=1;i<=len;i++)
	{
		if(a[i]>back[res])//不要求严格递增时此处改成>= 
			back[++res]=a[i];
		else
			back[find(a[i],res)]=a[i];
	}
	return res;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	cout<<solve(n)<<endl;
}
