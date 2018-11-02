#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e5+5;
//求出方程ax+by=gcd(a,b)的一组特解x0,y0
//并返回a,b的最大公约数
//x,y以引用形式传递(修改保存值)
ll exgcd(ll a,ll b,ll &x,ll &y)
{
    if(b==0)
    {
        x=1;y=0;
        return a;
    }
    ll d=exgcd(b,a%b,x,y);
    int z=x;x=y;y=z-(y*(a/b));
    return d;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	return 0;
}
