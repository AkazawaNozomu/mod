#include<bits/stdc++.h>
#define endl "\n"
typedef long long ll;
using namespace std;
const int maxn=1e5+5;
int dp[2][maxn],ans=-1,pos;//滚动数组
string s1,s2;
void lcs()
{
	int l1=s1.size(),l2=s2.size();
	for(int i=0;i<l1;i++)
	{
		memset(dp[i%2],0,sizeof(dp[i%2]));
		for(int j=0;j<l2;j++)
		{
			if(s1[i]==s2[j])
			{
				if(j)dp[i%2][j]=dp[1-i%2][j-1]+1;
				else dp[i%2][j]=1;
				if(dp[i%2][j]>ans)ans=dp[i%2][j],pos=j;
			}
		}
	}
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>s1>>s2;
	lcs();
	cout<<ans<<endl;
	//cout<<s2.substr(pos-ans+1,pos);//打印最长子串 
}

