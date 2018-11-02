#include<bits/stdc++.h>
#define endl "\n"
typedef long long ll;
using namespace std;
const int maxn=1e5+5;
const ll mod=1e9+7;
ll qpow(ll a,ll b)//a^b
{
	if(b==0)return 1;
	else if(b%2)return (((qpow(a,b/2)*qpow(a,b/2))%mod)*(a%mod))%mod;
	else return ((qpow(a,b/2)*qpow(a,b/2))%mod)%mod;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
}

