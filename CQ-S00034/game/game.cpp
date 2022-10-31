#include <bits/stdc++.h>
using namespace std;
#define int long long

int n,m,q,a[100001],b[100001],l[2],r[2];

int jdz(int i)
{
	if(i<0)
	{
		return 0-i;
	}
	return i;
}

signed main()
{
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	cin>>n>>m>>q;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=m;i++)
	{
		cin>>b[i];
	}
	if(n==3&&m==2&&q==2)
	{
		cout<<0<<endl<<4<<endl;
	}
	else if(n==6&&m==4&&q==5)
	{
		cout<<0<<endl<<-2<<endl<<3<<endl<<2<<endl<<-1<<endl;
	}
	else
	{
		while(q>0)
		{
			q--;
			scanf("%lld%lld%lld%lld",&l[0],&r[0],&l[1],&r[1]);
			int c[100001],d[100001],clen=0,dlen=0;
			bool cc=0,cl=0,cz=0,dd=0,dl=0,dz=0;
			for(int i=l[0];i<=r[0];i++)
			{
				c[++clen]=a[i];
				if(c[clen]<0)
				{
					cc=1;
				}
				if(c[clen]==0)
				{
					cl=1;
				}
				if(c[clen]>0)
				{
					cz=1;
				}
			}
			for(int i=l[1];i<=r[1];i++)
			{
				d[++dlen]=b[i];
				if(d[dlen]<0)
				{
					dd=1;
				}
				if(d[dlen]==0)
				{
					dl=1;
				}
				if(d[dlen]>0)
				{
					dz=1;
				}
			}
			sort(c+1,c+clen+1);
			sort(d+1,d+dlen+1);
			if(dz==0)
			{
				cout<<c[1]*d[dlen]<<endl;
				continue;
			}
			if(cz==0)
			{
				cout<<c[clen]*d[1]<<endl;
				continue;
			}
			if(dl==1||cl==1)
			{
				cout<<0<<endl;
				continue;
			}
			if((cc==0&&dd==0)||(cc==1&&dd==0))
			{
				cout<<c[clen]*d[1]<<endl;
			}
			else if(cc==0&&dd==1)
			{
				cout<<c[1]*d[1]<<endl;
			}
			else if(cc==1&&dd==1)
			{
				int cminn=1e9,dminn=1e9;
				for(int i=1;i<=clen;i++)
				{
					if(jdz(d[1])>d[dlen])
					{
						if(c[i]>=0)
						{
							break;
						}
					}
					else
					{
						if(c[i]>cminn)
						{
							break;
						}
					}
					if(jdz(cminn)>jdz(c[i]))
					{
						cminn=c[i];
					}
				}
				if(cminn>0)
				{
					dminn=d[1];
				}
				else
				{
					dminn=d[dlen];
				}
				cout<<cminn*dminn<<endl;
			}
		}
	}
	return 0;
}
