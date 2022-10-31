#include<bits/stdc++.h>
using namespace std;
long long read()
{
	char ch;
	long long t = 0,op = 1;
	ch = getchar();
	while(ch!='-'&&(ch>'9'||ch<'0'))
		ch = getchar();
	if(ch=='-')
		op = -1,ch = getchar();
	while(ch<='9'&&ch>='0')
		t = (t<<1)+(t<<3)+ch-48,ch = getchar();
	return t*op;
}
const long long N = 1e5+5;
int n,m,q;
long long a[N],b[N];
int main()
{
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	n = read(),m = read(),q = read();
	for(int i = 1;i<=n;++i)
		a[i] = read();
	for(int i = 1;i<=m;++i)
		b[i] = read();
	for(int i = 1;i<=q;++i)
	{
		int l1 = read(),r1 = read(),l2 = read(),r2 = read(),x = 0,y = 0;
		for(int k = l1;k<=r1;++k)
		{
			int mn = l2;
			for(int j = l2+1;j<=r2;++j)
				if((b[j]<b[mn]&&a[k]>=0)||(b[j]>b[mn]&&a[k]<=0))
					mn = j;
			if(a[k]*b[mn]>a[x]*b[y]||(x==0&&y==0))
				x = k,y = mn;
		}
		printf("%lld\n",a[x]*b[y]);
	}
	return 0;
}

