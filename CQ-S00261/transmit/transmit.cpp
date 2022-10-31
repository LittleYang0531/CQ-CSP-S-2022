#include<bits/stdc++.h>
using namespace std;
int read()
{
	char ch;
	int t = 0,op = 1;
	ch = getchar();
	while(ch!='-'&&(ch>'9'||ch<'0'))
		ch = getchar();
	if(ch=='-')
		op = -1,ch = getchar();
	while(ch<='9'&&ch>='0')
		t = (t<<1)+(t<<3)+ch-48,ch = getchar();
	return t*op;
}
const int N = 2*1e5+5;
int n,q,k,v[N];
vector<int> a[N];
int main()
{
	freopen("transmit.in","r",stdin);
	freopen("transmit.out","w",stdout);
	n = read(),q = read(),k = read();
	for(int i = 1;i<=n;i++)
		v[i] = read();
	for(int i = 1;i<n-1;i++)
	{
		int x = read(),y = read();
		a[x].push_back(y);
		a[y].push_back(x);
	}
	for(int i = 1;i<=q;i++)
	{
		int x = read(),y = read();
		printf("%d\n",v[x]+v[y]+v[2]);
	}
	return 0;
}

