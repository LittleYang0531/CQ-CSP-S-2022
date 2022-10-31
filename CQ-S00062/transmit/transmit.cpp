#include<bits/stdc++.h>
using namespace std;
const int maxn=2*1e5+1;
int cnt,h[maxn],t[maxn],nx[maxn],x,y;
int n,q,k;
int v[maxn];
void add(int x,int y)
{
	cnt++,t[cnt]=y,nx[cnt]=h[x],h[x]=cnt;
	cnt++,t[cnt]=x,nx[cnt]=h[y],h[y]=cnt;
}
int main()
{
	freopen("transmit.in","r",stdin);
	freopen("transmit.out","w",stdout);
	cin >> n >> q >> k;
	for(int i=1;i<=n;i++)	cin >> v[i];
	for(int i=1;i<n;i++)
	{
		cin >> x >> y;
		add(x,y);
	}
	while(q--)
	{
		int s,t,sum;
		cin >> s >> t;
		sum=v[s]+v[t];
		cout<<sum<<endl;
	}
	return 0;
}

