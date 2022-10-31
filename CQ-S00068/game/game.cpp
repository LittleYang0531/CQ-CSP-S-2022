#include<bits/stdc++.h>
using namespace std;
int n,m,q,a[100005],b[100005];
int Log[100005];
int f_a_max[100005][18],f_a_min[100005][18];
int f_b_max[100005][18],f_b_min[100005][18];
int f_q_max[100005][18],f_q_min[100005][18];//aÊý×éÖÐmax(<0) min(>0)
void rmq_q()
{
	for(int i=1;i<=n;i++)f_a_max[i][0]=a[i],f_a_min[i][0]=a[i];
	for(int i=1;i<=n;i++)
	{
		if(a[i]<=0)f_q_max[i][0]=a[i];
		else f_q_max[i][0]=-0x3f3f3f3f;
	}
	for(int i=1;i<=n;i++)
	{
		if(a[i]>=0)f_q_min[i][0]=a[i];
		else f_q_min[i][0]=0x3f3f3f3f;
	}	
	for(int j=1;j<=Log[n];j++)
	{
		for(int i=1;i+(1<<j)-1<=n;i++)
		{
			f_q_max[i][j]=max(f_q_max[i][j-1],f_q_max[i+(1<<j-1)][j-1]);
			f_a_max[i][j]=max(f_a_max[i][j-1],f_a_max[i+(1<<j-1)][j-1]);
			f_q_min[i][j]=min(f_q_min[i][j-1],f_q_min[i+(1<<j-1)][j-1]);
			f_a_min[i][j]=min(f_a_min[i][j-1],f_a_min[i+(1<<j-1)][j-1]);
		}
	}
}
void rmq_l()
{
	for(int i=1;i<=n;i++)f_b_max[i][0]=b[i],f_b_min[i][0]=b[i];
	for(int j=1;j<=Log[n];j++)
	{
		for(int i=1;i+(1<<j)-1<=n;i++)
		{
			f_b_max[i][j]=max(f_b_max[i][j-1],f_b_max[i+(1<<j-1)][j-1]);
			f_b_min[i][j]=min(f_b_min[i][j-1],f_b_min[i+(1<<j-1)][j-1]);
		}
	}
}
void prepare()
{
	rmq_q();
	rmq_l();
}
int l1,r1,l2,r2;
long long ask_a_max(int l,int r)
{
	long long ans;
	int s=Log[r-l+1];
	ans=max(f_a_max[l][s],f_a_max[r-(1<<s)+1][s]);
}
long long ask_a_min(int l,int r)
{
	long long ans;
	int s=Log[r-l+1];
	ans=min(f_a_min[l][s],f_a_min[r-(1<<s)+1][s]);
}
long long ask_b_max(int l,int r)
{
	long long ans;
	int s=Log[r-l+1];
	ans=max(f_b_max[l][s],f_b_max[r-(1<<s)+1][s]);
}
long long ask_b_min(int l,int r)
{
	long long ans;
	int s=Log[r-l+1];
	ans=min(f_b_min[l][s],f_b_min[r-(1<<s)+1][s]);
}
long long ask_q_max(int l,int r)
{
	long long ans;
	int s=Log[r-l+1];
	ans=max(f_q_max[l][s],f_q_max[r-(1<<s)+1][s]);
}
long long ask_q_min(int l,int r)
{
	long long ans;
	int s=Log[r-l+1];
	ans=min(f_q_min[l][s],f_q_min[r-(1<<s)+1][s]);
}
void work()
{
	long long a_min,a_max,b_min,b_max,q_min,q_max;
	cin>>l1>>r1>>l2>>r2;
	a_min=ask_a_min(l1,r1);
	a_max=ask_a_max(l1,r1);
	b_min=ask_b_min(l2,r2);
	b_max=ask_b_max(l2,r2);
	q_min=ask_q_min(l1,r1);
	q_max=ask_q_max(l1,r1);
//	cout<<a_min<<' '<<a_max<<' '<<b_min<<' '<<b_max<<' '<<q_min<<' '<<q_max<<'\n';
	if(a_min>0)
	{
		if(b_min>0)
		{
			cout<<a_max*b_min<<'\n';
		}
		else
		{
			cout<<a_min*b_min<<'\n';
		}
	}
	else
	{
		if(a_max>0)
		{
			if(b_min>0)
			{
				cout<<a_max*b_min<<'\n';
			}
			else
			{
				if(b_max<0)
				{
					cout<<a_min*b_max<<'\n';
				}
				else
				{
					cout<<max(q_max*b_max,q_min*b_min)<<'\n';
				}
			}
		}
		else
		{
			if(b_min>0)
			{
				cout<<a_max*b_max<<'\n';
			}
			else
			{
				if(b_max>0)
				{
					cout<<a_max*b_max<<'\n';
				}
				else
				{
					cout<<a_min*b_max<<'\n';
				}
			}
		}
	}
}
int main()
{	
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
	cin>>n>>m>>q;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=m;i++)cin>>b[i];
	for(int i=2;i<=max(n,m);i++)Log[i]=Log[i/2]+1;
	prepare();
	while(q--)work();
	return 0;
}
/*
3 2 2
0 1 -2
-3 4
1 3 1 2
2 3 2 2

6 4 5
3 -1 -2 1 2 0
1 2 -1 -3
1 6 1 4
1 5 1 4
1 4 1 2
2 6 3 4
2 5 2 3
*/
