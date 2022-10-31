#include<cmath>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
#define maxn 100005
#define LL long long
#define inf 0x7fffffff/2
int n,m,q;
int a[maxn];
int b[maxn];
int fl1=1;
int f1_max[maxn][20];
int f1_min[maxn][20];
int f2_max[maxn][20];
int f2_min[maxn][20];
int fz[maxn][20];
int ff[maxn][20];
void RMQ()
{
	for(int i=1;i<=n;i++) f1_max[i][0]=f1_min[i][0]=a[i];
	for(int i=1;i<=m;i++) f2_max[i][0]=f2_min[i][0]=b[i];
	for(int j=1;j<=log2(n);j++)
		for(int i=1;i+(1<<j)-1<=n;i++)
		{
			f1_max[i][j]=max(f1_max[i][j-1],f1_max[i+(1<<j-1)][j-1]);
			f1_min[i][j]=min(f1_min[i][j-1],f1_min[i+(1<<j-1)][j-1]);
		}
	for(int j=1;j<=log2(m);j++)
		for(int i=1;i+(1<<j)-1<=m;i++)
		{
			f2_max[i][j]=max(f2_max[i][j-1],f2_max[i+(1<<j-1)][j-1]);
			f2_min[i][j]=min(f2_min[i][j-1],f2_min[i+(1<<j-1)][j-1]);
//			cout<<"! "<<i<<' '<<j<<' '<<f2_min[i][j]<<'\n';
		}
	for(int i=1;i<=n;i++)
		if(a[i]>=0) fz[i][0]=a[i],ff[i][0]=inf;
		else fz[i][0]=inf,ff[i][0]=-a[i];
	for(int j=1;j<=log2(n);j++)
		for(int i=1;i+(1<<j)-1<=n;i++)
		{
			fz[i][j]=min(fz[i][j-1],fz[i+(1<<j-1)][j-1]);
			ff[i][j]=min(ff[i][j-1],ff[i+(1<<j-1)][j-1]);
//			cout<<"! "<<" zheng : "<<i<<' '<<j<<' '<<fz[i][j]<<'\n';
		}
}
int Ask1(int l,int r,int op)
{
	int k=log2(r-l+1);
//	cout<<"Max from "<<l<<" with "<<k<<" is "<<f1_max[l][k]<<'\n';
//	cout<<"Max from "<<r-(1<<k)+1<<" with "<<k<<" is "<<f1_max[r-(1<<k)+1][k]<<'\n';
//	cout<<"Min from "<<l<<" with "<<k<<" is "<<f1_min[l][k]<<'\n';
//	cout<<"Min from "<<r-(1<<k)+1<<" with "<<k<<" is "<<f1_min[r-(1<<k)+1][k]<<'\n';
	if(op==0) return max(f1_max[l][k],f1_max[r-(1<<k)+1][k]);
	else return min(f1_min[l][k],f1_min[r-(1<<k)+1][k]);
}
int Ask2(int l,int r,int op)
{
	int k=log2(r-l+1);
//	cout<<"Max from "<<l<<" with "<<k<<" is "<<f2_max[l][k]<<'\n';
//	cout<<"Max from "<<r-(1<<k)+1<<" with "<<k<<" is "<<f2_max[r-(1<<k)+1][k]<<'\n';
//	cout<<"Min from "<<l<<" with "<<k<<" is "<<f2_min[l][k]<<'\n';
//	cout<<"Min from "<<r-(1<<k)+1<<" with "<<k<<" is "<<f2_min[r-(1<<k)+1][k]<<'\n';
	if(op==0) return max(f2_max[l][k],f2_max[r-(1<<k)+1][k]);
	else return min(f2_min[l][k],f2_min[r-(1<<k)+1][k]);
}

int Ask3(int l,int r,int op)
{
	int k=log2(r-l+1);
//	cout<<"k : "<<k<<'\n';
//	cout<<"Ask3 "<<l<<' '<<fz[l][k]<<' '<<(r-(1<<k)+1)<<' '<<fz[r-(1<<k)+1][k]<<'\n';
	if(op>0) return min(fz[l][k],fz[r-(1<<k)+1][k]);
	else return min(ff[l][k],ff[r-(1<<k)+1][k]);
}
signed main()
{
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>n>>m>>q;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]<0) fl1=0;
	}
	for(int i=1;i<=m;i++) 
	{
		cin>>b[i];
		if(b[i]<0) fl1=0;
	}
	/*
	if(n<=1000 && m<=1000 && q<=1000)
	{
		int l,r,ll,rr;
		while(q--)
		{
			cin>>l>>r>>ll>>rr;
			int fl_f=0,fl_z=0;
			for(int i=ll;i<=rr;i++)
				fl_z=max(fl_z,b[i]),fl_f=min(fl_f,b[i]);
			if(fl_z>0 && fl_f<0)
			{
				LL Max=-0x7fffffffffffffff/2;
				for(int i=l;i<=r;i++)
					if(a[i]<0)
					{
						if(1LL*fl_z*a[i]>Max) Max=1LL*fl_z*a[i];
					}
					else
					{
						if(1LL*fl_f*a[i]>Max) Max=1LL*fl_f*a[i];
					}
				cout<<Max<<'\n';
			}
			else
				if(fl_z>0 && fl_f>=0)
				{
//					cout<<fl_z<<" ? "<<fl_f<<'\n';
					int Max=-inf,Min=inf;
					for(int i=l;i<=r;i++) Max=max(Max,a[i]);
					if(Max>=0)
						for(int i=ll;i<=rr;i++) Min=min(Min,b[i]);
					else
					{
						Min=-inf;
						for(int i=ll;i<=rr;i++) Min=max(Min,b[i]);
					}
					cout<<1LL*Max*Min<<'\n';
				}
				else
				{
					int Max=-inf,Min=inf;
					for(int i=l;i<=r;i++) Min=min(Min,a[i]);
					if(Min<=0)
						for(int i=ll;i<=rr;i++) Max=max(Max,b[i]);
					else
					{
						Max=inf;
						for(int i=ll;i<=rr;i++) Max=min(Max,b[i]);
					}
//					cout<<Max<<" ! "<<Min<<'\n';
//					cout<<-1<<'\n';
//					for(int i=ll;i<=rr;i++) Max=max(Max,b[i]);
					cout<<1LL*Max*Min<<'\n';
				}
		}
		return 0;
	}
	*/
	RMQ();
//	if(fl1)
//	{
//		int l,r,ll,rr;
//		while(q--)
//		{
//			cin>>l>>r>>ll>>rr;
//			int Max=Ask1(l,r,0);
//			int Min=Ask2(ll,rr,1);
////			int k=log2(rr-ll+1);
////			cout<<"! "<<k<<'\n';
////			cout<<"! "<<ll<<' '<<rr<<' '<<" is "<<f2_min[ll][k]<<' '<<f2_min[rr-(1<<k)][k]<<'\n';
////			cout<<Min<<' '<<Max<<'\n';
//			cout<<1LL*Min*Max<<'\n';
//		}
//		return 0;
//	}
	int l,r,ll,rr;
	while(q--)
	{
		cin>>l>>r>>ll>>rr;
		int fl_f=Ask2(ll,rr,1),fl_z=Ask2(ll,rr,0);
//		for(int i=ll;i<=rr;i++)
//			fl_z=max(fl_z,b[i]),fl_f=min(fl_f,b[i]);
		if(fl_z>0 && fl_f<0)
		{
			int Max=Ask1(l,r,0),Min=Ask1(l,r,1);
			if(Max<0) cout<<1LL*fl_z*Max<<'\n';
			else if(Min>0) cout<<1LL*fl_f*Min<<'\n';
			else
			{
//				cout<<"! "<<-1LL*fl_z*Ask3(l,r,-1)<<' '<<1LL*fl_f*Ask3(l,r,1)<<'\n';
				cout<<max(-1LL*fl_z*Ask3(l,r,-1),1LL*fl_f*Ask3(l,r,1))<<'\n';
			}
			
//			for(int i=l;i<=r;i++)
//				if(a[i]<0)
//				{
//					if(1LL*fl_z*a[i]>Max) Max=1LL*fl_z*a[i];
//				}
//				else
//				{
//					if(1LL*fl_f*a[i]>Max) Max=1LL*fl_f*a[i];
//				}
//			cout<<Max<<'\n';
		}
		else
			if(fl_z>0 && fl_f>=0)
			{
				int Max=-inf,Min=inf;
				Max=Ask1(l,r,0);
//				for(int i=l;i<=r;i++) Max=max(Max,a[i]);
				if(Max>=0)
				{
					Min=Ask2(ll,rr,1);
//					for(int i=ll;i<=rr;i++) Min=min(Min,b[i]);
				}
				else
				{
					Min=Ask2(ll,rr,0);
//					for(int i=ll;i<=rr;i++) Min=max(Min,b[i]);
				}
				cout<<1LL*Max*Min<<'\n';
			}
			else
			{
				int Max=-inf,Min=inf;
				Min=Ask1(l,r,1);
//				for(int i=l;i<=r;i++) Min=min(Min,a[i]);
				if(Min<=0)
				{
					Max=Ask2(ll,rr,0);
//					for(int i=ll;i<=rr;i++) Max=max(Max,b[i]);
				}
				else
				{
					Max=Ask2(ll,rr,1);
//					for(int i=ll;i<=rr;i++) Max=min(Max,b[i]);
				}
				cout<<1LL*Max*Min<<'\n';
			}
	}
	return 0;
}
/*
important test:

Input 1:
6 7 2
1 2 3 4 5 6
7 6 5 4 3 2 1
1 2 4 5
4 6 3 7
*/
