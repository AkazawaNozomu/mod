#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e5+5;
int f[maxn];
void init(int n)//size
{
	for(int i=1;i<=n;i++)
	{
		f[i]=i;
	}
}
int find(int x)
{
	if(f[x]==x)return x;
	else return f[x]=find(f[x]);
}
void unite(int x,int y)
{
	x=find(x);
	y=find(y);
	if(x>y)f[x]=y;
	else f[y]=x;
}
bool quest(int x,int y)
{
	return find(x)==find(y);
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	return 0;
}

