#include<bits/stdc++.h>
#define endl "\n"
typedef long long ll;
using namespace std;
const int maxn=1e5+5;
string a,b;
int adig[maxn],bdig[maxn],ans[maxn*2+5],anslen;
bool asign,bsign,anssign=1;//1 p 0 n

bool cmp(string &x, string &y)
{
	if(x.size() > y.size())return true;
	if(x.size() < y.size())return false;
	return x > y;
}

void add()//positive + positive
{
	memset(ans, 0, sizeof(ans));
	int l1 = a.size(), l2 = b.size();
	for(int i = 0; i < l1; i++)
	{
		adig[i] = a[l1 - 1 - i] - '0';
	}
	for(int i = 0; i < l2; i++)
	{
		bdig[i] = b[l2 - 1 - i] - '0';
	}
	int maxl = max(l1, l2);
	for(int i = 0; i < maxl; i++)
	{
		ans[i] += adig[i] + bdig[i];
		ans[i + 1]+=(adig[i] + bdig[i]) % 10;
	}
	if(ans[maxl + 1])anslen = maxl + 1;
	else anslen = maxl;
}

void subtract()//positive - positive
{
	//a - b
	memset(ans, 0, sizeof(ans));
	if(a == b)return;
	int l1 = a.size(),l2 = b.size();
	if(cmp(a, b))
	{
		//anssign;
		for(int i = 0; i < l1; i++)
		{
			adig[i] = a[l1 - 1 - i] - '0';
		}
		for(int i = 0; i < l2; i++)
		{
			bdig[i] = b[l2 - 1 - i] - '0';
		}
	}
	else
	{
		anssign = !anssign;
		for(int i = 0; i < l1; i++)
		{
			bdig[i] = a[l1 - 1 - i] - '0';
		}
		for(int i = 0; i < l2; i++)
		{
			adig[i] = b[l2 - 1 - i] - '0';
		}
	}
	int maxl = max(l1, l2);
	for(int i = 0; i < maxl; i++)
	{
		ans[i] += adig[i] - bdig[i];
		if(ans[i] < 0)
		{
			ans[i] += 10;
			ans[i + 1]--;
		}
		if(ans[i] > 0)anslen = i;
	}
}

void addint()//integer + integer
{
	if(!(asign ^ bsign))
	{
		anssign = asign;
		add();
	}
	else
	{
		anssign = asign;
		subtract();
	}
}

void subint()//integer - integer
{
	if(!(asign ^ bsign))
	{
		anssign = asign;
		subtract();
	}
	else
	{
		anssign = asign;
		add();
	}
}

void fft()
{
	
}

ll getrem(ll mod)
{
	//a / mod = ans ... rem
	//-9 / 4 = -2 ... -1
	ll rem = 0;int anslen = 0;
	anssign = !(asign ^ (mod > 0))
	if(mod < 0)mod = -mod;
	memset(ans, 0, sizeof(ans));
	int l = a.size();
	for(int i = 0; i < l; i++)
	{
		adig[i] = a[i] - '0';
	}
	for(int i = 0; i < l; i++)
	{
		rem *= 10;
		rem += adig[i];
		ans[i] = rem / mod;
		rem %= mod;
		if(ans[i] && !anslen)anslen = l - i;
	}
	return rem;
}



int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
}

