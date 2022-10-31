#include<bits/stdc++.h>
using namespace std;
const int Maxn = 1e5+1;
#define in long long
in a[Maxn],b[Maxn];
in n,m,q,l1,l2,r1,r2;
int main() 
{
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	cin >> n >> m >> q;
	for(in i=1;i<=n;i++)	cin >> a[i];
	for(in i=1;i<=m;i++)	cin >> b[i];
	
	while(q--)
	{
		cin >> l1 >> r1 >> l2 >> r2;
		in a1=-1e9,a2=1e9,a3=-1e9,a4=1e9,b1=-1e9,b2=1e9;
		for(in i=l1;i<=r1;i++)
		{
			if(a[i]>=0){	a1=max(a1,a[i]);a2=min(a2,a[i]);}
			if(a[i]<=0){	a3=max(a3,a[i]);a4=min(a4,a[i]);}
		}
		for(in i=l2;i<=r2;i++)
		{
			if(b[i]<=0)		b2=min(b2,b[i]);
			if(b[i]>=0)		b1=max(b1,b[i]);
		}
		in s[5];
		if(a1==-1e9)
			if(a2!=1e9)	a1=a2;
			else	a1=1;
		if(a2==1e9)
			if(a1!=-1e9 && a1!=1)	a2=a1;
			else a2=1;
		if(a3==-1e9)
			if(a4!=1e9)	a3=a4;
			else	a3=-1;
		if(a4==1e9)
			if(a3!=-1e9 && a3!=-1)	a4=a3;
			else a4=-1;
		if(b1==-1e9)	b1=-1;
		if(b2==1e9)		b2=1;
		s[1]=a1*b2,s[2]=a2*b2,s[3]=a3*b1,s[4]=a4*b1;
		for(in i=1;i<=4;i++)
			if(s[i]>=1e9)	s[i]=-1e9;
		in ans=max(s[1],max(s[2],max(s[3],s[4])));
		cout<<ans<<endl;
	}
	return 0;
}

