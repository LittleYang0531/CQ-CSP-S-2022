#include<bits/stdc++.h>
using namespace std;
int n,Q,k;
int V[900];
int tu[300][300]={0};
int b[900];
int shu[900][3]={0};//´Óxµ½y 
bool  G[100]={0};
int tot=1,x,y;

int main()
{
	//freopen("transmit.in","r",stdin);
	//freopen("transmit.out","w",stdout);
	
	cin>>n>>Q>>k;
	for(int i=1;i<=n;i++) shu[i][1]=900;
	for(int i=1;i<=n;i++)
		cin>>V[i];
	for(int i=1;i<=n-1;i++)
	{
		int h,j;
		cin>>h>>j;
		tu[h][j]=1;
		tu[j][h]=1;
	}
	for(int i=1;i<=Q;i++)
	{
		int step;
		cin>>x>>y;
		if(tu[x][y]==1)  
		{
			b[i]==V[x]+V[y];
			break;
		}
		shu[x][1]=0;
		int t=0,max=999;
		for(int j=1;j<=n;j++)
		{
			for(int k=1;k<=n;k++)
			{
				if(tu[x][k]) x=k,t++;	
				if(x==y) break;
				
			}
			if(t<max) t=max;
		}
		for(int k=1;k<=n;k++)
		{
			int min=99999;
			for(int j=1;j<=n;j++)
			{
				if(tu[x][j]&&min>V[j]) min=j; 
			}
			if(V[min]+V[x]<shu[min][1]);	
		}
	}
	for(int i=1;i<=Q;i++)
	{
		cout<<b[i]<<endl;
	}
	return 0;
}

