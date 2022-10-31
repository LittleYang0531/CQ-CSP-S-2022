#include<bits/stdc++.h>
#define ls Tree[p].lc
#define rs Tree[p].rc 
using namespace std;
const int MAXN=2505;
int n,m;
int K;
int x,y;
long long s[MAXN];
struct Martix{
	bool val[MAXN][MAXN];
	int n,m;
	void clear()
	{
		memset(val,0,sizeof(val));
	}
	void init()
	{
		clear();
		for(int i=1;i<=n;i++)
		{
			val[i][i]=1;
		}
	}
	Martix operator*(const Martix x)const{
		Martix Res;
		Res.n=n;
		Res.m=x.m;
		Res.clear();
		for(int k=1;k<=m;k++)
		{
			for(int i=1;i<=n;i++)
			{
				for(int j=1;j<=x.m;j++)
				{
					Res.val[i][j]|=(val[i][k]&x.val[k][j]); 
				}
			}
		}
		return Res;
	} 
}A;
Martix Pow(Martix a,int b)
{
	Martix Res;
	Res.n=a.n;
	Res.m=a.m;
	Res.init();
	Martix Base=a;
	while(b)
	{
		if(b&1)
		{
			Res=(Res*Base);
		}
		Base=(Base*Base);
		b>>=1;
	}
	return Res;
}
struct node{
	long long val;
	int u;
	bool operator<(const node x)const{
		return val<x.val;
	}
};
priority_queue<node>Rec[MAXN];
int main()
{
	freopen("holiday.in","r",stdin);
	freopen("holiday.out","w",stdout);
	scanf("%d %d %d",&n,&m,&K);
	A.clear();
	A.n=n;
	A.m=n;
	for(int i=2;i<=n;i++)
	{
		scanf("%lld",&s[i]);
	}
	for(int i=1;i<=m;i++)
	{
		scanf("%d %d",&x,&y);
		A.val[x][y]=1;
		A.val[y][x]=1;
	}
	for(int i=1;i<=n;i++)
	{
		A.val[i][i]=1;
	}
	Martix New=Pow(A,(K+1));
	long long Res=0; 
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(i==j)
			{
				continue;
			}
			if(New.val[i][j]&&New.val[j][1]&&j!=1)
			{
				node sx;
				sx.u=j;
				sx.val=s[j];
				Rec[i].push(sx);		 
			}
		}
	}
	
	
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(i==j)
			{				
				continue;
			}
			if(i==1)
			{
				continue;
			}
			if(j==1)
			{
				continue;
			}
			if(New.val[i][j]&&(Rec[i].size())&&(Rec[j].size()))
			{
				long long Tot=0;
				
				Tot+=s[i]+s[j];
				node U=Rec[i].top();
				node V=Rec[j].top();
				Rec[i].pop();
				Rec[j].pop();
				if(U.u!=j&&U.u!=V.u&&V.u!=i)
				{
					Tot+=U.val;
					Tot+=V.val;
					Res=max(Tot,Res); 
				 } 
				 else
				 {
				 	node Nu,Nv;
				 	bool Fu=0,Fv=0;
				 	if(U.u==j)
				 	{
				 		if(Rec[i].size())
				 		{
				 			Nu=Rec[i].top();
				 			Rec[i].pop();
				 			Fu=1;
						 }
						 else
						 {
						 	Rec[i].push(U);
							Rec[j].push(V);
						 	continue;
						 }
					}
					else
					{
						Nu=U;
					}
					if(V.u==i)
				 	{
				 		if(Rec[j].size())
				 		{
				 			Nv=Rec[j].top();
				 			Rec[j].pop();
				 			Fv=1;
						 }
						 else
						 {
						 	Rec[i].push(U);
							Rec[j].push(V);
						 	continue;
						 }
					}
					else
					{
						Nv=V;
					}
					if(Nu.u==Nv.u)
					{
						if(Rec[i].size())
						{
							if(Rec[i].top().u==j)
							{
								node Fake=Rec[i].top();
								Rec[i].pop();
								if(Rec[i].size())
								{
									Res=max(Tot+Rec[i].top().val+Nv.val,Res);
								}
								Rec[i].push(Fake);
							}
							else
							{
								Res=max(Tot+Rec[i].top().val+Nv.val,Res); 
							}
						}
						if(Rec[j].size())
						{
							if(Rec[j].top().u==i)
							{
								node Fake=Rec[j].top();
								Rec[j].pop();
								if(Rec[j].size())
								{
									Res=max(Tot+Rec[j].top().val+Nu.val,Res);
								}
								Rec[j].push(Fake);
							}
							else
							{
								Res=max(Tot+Rec[j].top().val+Nu.val,Res); 
							}
						}
					}
					else
					{
						Tot+=Nu.val;
						Tot+=Nv.val;
						Res=max(Tot,Res); 
					}
					if(Fu)
					{
						Rec[i].push(Nu);
					}
					if(Fv)
					{
						Rec[j].push(Nv);
					}
				 }
				Rec[i].push(U);
				Rec[j].push(V);
			}
		}
	}
	printf("%lld\n",Res);
	return 0;
}
