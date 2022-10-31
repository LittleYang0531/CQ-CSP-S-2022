#include<bits/stdc++.h>
using namespace std;
struct tree
{
	long long l,r,maxn,minn;
}tra[1000005],trb[1000005];
long long n,m,q,a[100005],b[100005],ansa,ansb;
/*void builda(int p,int l,int r)
{
	tra[p].l=l,tra[p].r=r;
	if(l==r)
	{
		tra[p].maxn=a[l];
		return;
	}
	int mid=(l+r)/2;
	builda(p*2,l,mid);
	builda(p*2+1,mid+1,r);
	tra[p].maxn=max(tra[p*2].maxn,tra[p*2+1].maxn);
}*/
void buildb(long long p,long long l,long long r)
{
	trb[p].l=l,trb[p].r=r;
	if(l==r)
	{
		trb[p].minn=b[l];
		//cout<<"BMINpoint "<<trb[p].l<<" "<<trb[p].r<<" "<<trb[p].minn<<endl;
		return;
	}
	long long mid=(l+r)/2;
	buildb(p*2,l,mid);
	buildb(p*2+1,mid+1,r);
	trb[p].minn=min(trb[p*2].minn,trb[p*2+1].minn);
	//cout<<"BMIN "<<trb[p].l<<" "<<trb[p].r<<" "<<trb[p].minn<<endl;
}
void query(long long p,long long l2,long long r2)
{
	if(trb[p].l==l2&&trb[p].r==r2)
	{
		//cout<<"query "<<trb[p].l<<" "<<trb[p].r<<" "<<trb[p].minn<<endl;
		ansb=trb[p].minn;
		return;
	}
	long long mid=(trb[p].l+trb[p].r)/2;
	if(mid>=r2) query(p*2,trb[p].l,mid);
	else if(mid<l2) query(p*2+1,mid+1,trb[p].r);
	else
	{
		query(p*2,trb[p].l,mid);
		query(p*2+1,mid+1,trb[p].r);
	}
}
int main()
{
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	cin>>n>>m>>q;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	//builda(1,1,n);
	for(int i=1;i<=m;i++)
	{
		cin>>b[i];
	}
	buildb(1,1,m);
	for(int i=1;i<=q;i++)
	{
		long long l1,r1,l2,r2;
		cin>>l1>>r1>>l2>>r2;
		if(l1==r1&&l2==r2)
		{
			cout<<a[l1]*b[l2]<<endl;
			continue;
		}
		query(1,l2,r2);
		bool temp=false;
		for(int j=l2;j<=r2;j++)
		{
			if(b[j]>0)
			{
				//cout<<"true"<<endl;
				temp=true;
				break;
			}
		}
		ansa=-INT_MAX;
		for(int j=l1;j<=r1;j++)
		{
			if(a[j]<0&&temp==true) continue;
			//cout<<ansa<<" "<<a[j]<<" "<<ansb<<endl;;
			ansa=max(ansa,ansb*a[j]);
		}
		cout<<ansa<<endl;
	}
	return 0;
}
