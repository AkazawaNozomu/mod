#include<bits/stdc++.h>
#define endl "\n"
typedef long long ll;
using namespace std;
const int maxn=1e5+5;
int a[maxn],back[maxn],ans=0;
//�ϸ����
int find(int x,int len)//x��back[1,len]���±�
{
	return lower_bound(back+1,back+len+1,x)-back;//��Ҫ���ϸ�����˴��ĳ�upper
}
int solve(int len)//����Ϊlen
{
	int res=0;
	memset(back,0,sizeof(back));//Ҫ������Ԫ�ؾ�Ϊ�� 
	for(int i=1;i<=len;i++)
	{
		if(a[i]>back[res])//��Ҫ���ϸ����ʱ�˴��ĳ�>= 
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
