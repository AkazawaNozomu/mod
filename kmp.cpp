#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e5+5;
string s,t;//从s中查找t
int f[maxn]; 
void getf(string &t/*,int f[]*/)
{
	memset(f,0,sizeof(f));
	for(int i=1;i<t.size();i++)//整个t中下标，求f[i]
	{
		int j=f[i];
		while(j &&(t[i]!=t[j]))j=f[j];
		f[i+1]=(t[i]==t[j])?j+1:0;
	} 
}
int solve(string &s,string &t/*,int f[]*/)
{
	getf(t/*,f*/);
	int j=0,ans=0;//t中当前位置
	for(int i=0;i<s.size();i++)
	{
		while(j&&(s[i]!=t[j]))j=f[j];//不能匹配时向后移动t
		if(s[i]==t[j])j++;//可以匹配
		if(j==t.size())ans++;
	} 
	return ans;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	string s="aaabbabcaaabcccc",t="abc";
	cout<<solve(s,t);
	return 0;
}

