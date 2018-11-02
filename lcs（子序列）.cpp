#include<bits/stdc++.h>
#define endl "\n"
typedef long long ll;
using namespace std;
const int maxn=1e3+5;
string a,b,ans;
int res[maxn][maxn],lst[maxn][maxn];
int lcs(int n,int m)
{
	//init
	for(int i=0;i<=n;i++)res[i][0]=0;
	for(int j=0;j<=m;j++)res[0][j]=0;
	
	//get lcs
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			if(a[i]==b[j])
			{
				res[i][j]=res[i-1][j-1]+1;
				lst[i][j]=0;
			}
			else
			{
				if(res[i-1][j]>res[i][j-1])
				{
					res[i][j]=res[i-1][j];
					lst[i][j]=1;
				}
				else
				{
					res[i][j]=res[i][j-1];
					lst[i][j]=2;
				}
			}
		}
	}
	
	//print
	ans.clear();
	int i=n,j=m;
	while(i&&j)
	{
		if(!lst[i][j])ans.push_back(a[i]),i--,j--;
		else if(lst[i][j]==1)i--;
		else j--;
	}
	reverse(ans.begin(),ans.end());
	
	return res[n][m];
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>a>>b;
	int n=a.size(),m=b.size();
	a=" "+a;
	b="#"+b;
	cout<<lcs(n,m)<<endl;
	cout<<ans<<endl;//print lcs 
}

