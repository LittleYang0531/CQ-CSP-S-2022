#include<bits/stdc++.h>
using namespace std;
long long n,m,k,x[3000],bian[2500][2500],jl[2500],ma,lj[2500];
void bb(long long a,long long b)
{
	bian[a][0]++;
	bian[a][bian[a][0]]=b;
}
void dt(long long a,long long z,long long g,long long s)
{
	if(z!=0)
	{
		for(long long l=1;l<=bian[a][0];l++)
		{
			if(g==0)lj[bian[a][l]]=1;
			dt(bian[a][l],z-1,g,s);
		}	
	} 
	else if(z==0&&g!=5)
	{
		if(g==0) lj[a]=1;
		if(jl[a]==0)
		{
		s+=x[a];
		jl[a]=1;
		for(long long j=k;j>=0;j--)
			for(long long l=1;l<=bian[a][0];l++)
				dt(bian[a][l],j,g+1,s);
		jl[a]=0;	
		}
	}
	if(g==5)
	{
		if(lj[a]==1)
		ma=max(s,ma);
		return ;
	}
}
int main()
{
	freopen("holiday.in","r",stdin);
	freopen("holiday.out","w",stdout);
	cin>>n>>m>>k;
	for(long long i=2;i<=n;i++) cin>>x[i];
	for(long long i=1;i<=m;i++){
		long long e,f;
		cin>>e>>f;
		bb(e,f);
		bb(f,e);
	}
	jl[1]=1;
	lj[1]=1;
	for(long long j=k;j>=0;j--)
		for(long long l=1;l<=bian[1][0];l++)
			 dt(bian[1][l],j,1,0);
	cout<<ma;
	return 0;
}
