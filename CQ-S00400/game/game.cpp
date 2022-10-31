#include<bits/stdc++.h>
#define int long long
#define inf 0x7fffffffffffffff
using namespace std;
int n,m,q,a[100001],b[100001],suma0[100001],suma1[100001],suma2[100001],sumb0[100001],sumb1[100001],sumb2[100001];
int belong1[100001],l1[1001],r1[1001],max1[1001],max2[1001],min1[1001],min2[1001],cnt1,p1,cnt2,p2,belong2[100001],l2[1001],r2[1001];
inline int cm1(int x,int y)
{
	int sum=-inf;
	if(belong1[x]==belong1[y])
	{
		for(int i=x;i<=y;i++)sum=max(sum,a[i]);
	}
	else
	{
		for(int i=x;i<=r1[belong1[x]];i++)sum=max(sum,a[i]);
		for(int i=belong1[x]+1;i<=belong1[y]-1;i++)sum=max(sum,max1[i]);
		for(int i=l1[belong1[y]];i<=y;i++)sum=max(sum,a[i]);
	}
	return sum;
}
inline int cm2(int x,int y)
{
	int sum=inf;
	if(belong1[x]==belong1[y])
	{
		for(int i=x;i<=y;i++)sum=min(sum,a[i]);
	}
	else
	{
		for(int i=x;i<=r1[belong1[x]];i++)sum=min(sum,a[i]);
		for(int i=belong1[x]+1;i<=belong1[y]-1;i++)sum=min(sum,min1[i]);
		for(int i=l1[belong1[y]];i<=y;i++)sum=min(sum,a[i]);
	}
	return sum;
}
inline int cm3(int x,int y)
{
	int sum=-inf;
	if(belong2[x]==belong2[y])
	{
		for(int i=x;i<=y;i++)sum=max(sum,b[i]);
	}
	else
	{
		for(int i=x;i<=r2[belong2[x]];i++)sum=max(sum,b[i]);
		for(int i=belong2[x]+1;i<=belong2[y]-1;i++)sum=max(sum,max2[i]);
		for(int i=l2[belong2[y]];i<=y;i++)sum=max(sum,b[i]);
	}
	return sum;
}
inline int cm4(int x,int y)
{
	int sum=inf;
	if(belong2[x]==belong2[y])
	{
		for(int i=x;i<=y;i++)sum=min(sum,b[i]);
	}
	else
	{
		for(int i=x;i<=r2[belong2[x]];i++)sum=min(sum,b[i]);
		for(int i=belong2[x]+1;i<=belong2[y]-1;i++)sum=min(sum,min2[i]);
		for(int i=l2[belong2[y]];i<=y;i++)sum=min(sum,b[i]);
	}
	return sum;
}
inline void init()
{
	cin>>n>>m>>q,p1=ceil(sqrt(n)),cnt1=ceil(n/p1),p2=ceil(sqrt(m)),cnt2=ceil(m/p2);
	for(int i=1;i<=n;i++)
	{
		cin>>a[i],suma0[i]=suma0[i-1],suma1[i]=suma1[i-1],suma2[i]=suma2[i-1];
		if(a[i]>0)suma0[i]++;
		if(a[i]==0)suma1[i]++;
		if(a[i]<0)suma2[i]++;
	}
	for(int i=1;i<=m;i++)
	{
		cin>>b[i],sumb0[i]=sumb0[i-1],sumb1[i]=sumb1[i-1],sumb2[i]=sumb2[i-1];
		if(b[i]>0)sumb0[i]++;
		if(b[i]==0)sumb1[i]++;
		if(b[i]<0)sumb2[i]++;
	}
	for(int i=1;i<=n;i++)belong1[i]=(i-1)/p1+1;
	for(int i=1;i<=m;i++)belong2[i]=(i-1)/p2+1;
	for(int i=1;i<=cnt1;i++)l1[i]=(i-1)*p1+1,r1[i]=i*p1;
	r1[cnt1]=n;
	for(int i=1;i<=cnt2;i++)l2[i]=(i-1)*p2+1,r2[i]=i*p2;
	r2[cnt2]=m;
	for(int i=1;i<=cnt1;i++)
	{
		max1[i]=-inf,min1[i]=inf;
		for(int j=l1[i];j<=r1[i];j++)
		{
			max1[i]=max(max1[i],a[j]),min1[i]=min(min1[i],a[j]);
//			max2[i]=max(max2[i],b[j]),min2[i]=min(min2[i],b[j]);
		}
	}
	for(int i=1;i<=cnt2;i++)
	{
		max2[i]=-inf,min2[i]=inf;
		for(int j=l2[i];j<=r2[i];j++)
		{
//			max1[i]=max(max1[i],a[j]),min1[i]=min(min1[i],a[j]);
			max2[i]=max(max2[i],b[j]),min2[i]=min(min2[i],b[j]);
		}		
	}
}
inline void solve()
{
	bool pd1=0;
	for(int i=1;i<=n;i++)
	{
		if(a[i]<=0)
		{
			pd1=1;
			break;
		}
	}
	for(int i=1;i<=m;i++)
	{
		if(b[i]<=0)
		{
			pd1=1;
			break;
		}
	}
	if(!pd1)
	{
		while(q--)
		{
			int aa,bb,x,y;
			cin>>aa>>bb>>x>>y;
			int x1=cm1(aa,bb),x2=cm2(aa,bb),x3=cm3(x,y),x4=cm4(x,y);
			cout<<x1*x4<<'\n';
		}
		return;
	}
	while(q--)
	{
		int aa,bb,x,y;
		cin>>aa>>bb>>x>>y;
		int sum1=suma0[bb]-suma0[aa-1],sum2=suma1[bb]-suma1[aa-1],sum3=suma2[bb]-suma2[aa-1],sum4=sumb0[y]-sumb0[x-1],sum5=sumb1[y]-sumb1[x-1],sum6=sumb2[y]-sumb2[x-1];
		if((sum2&&sum4&&sum6)||(sum5&&sum1&&!sum6))cout<<"0\n";
		else 
		{
			int x1=cm1(aa,bb),x2=cm2(aa,bb),x3=cm3(x,y),x4=cm4(x,y);
			if(aa==bb)
			{
				cout<<x4<<'\n';
				continue;
			}
			if(x==y)
			{
				cout<<x1<<'\n';
				continue;
			}
			int maxx=-0x7fffffffffffffff,minn=0x7fffffffffffffff,ans=-0x7fffffffffffffff;
			for(int i=aa;i<=bb;i++)
			{
				int sum=0x7fffffffffffffff;
				for(int j=x;j<=y;j++)
				{
					sum=min(sum,a[i]*b[j]);
				}
				ans=max(ans,sum);
			}	
//			cout<<max(x1*x4,x2*x3)<<'\n';
//			cout<<x1<<" "<<x2<<" "<<x3<<" "<<x4<<' ';
//			int maxf=-inf,minz=inf,ans=-inf/*max(x1*x4,x2*x3)*/;
//			for(int i=aa;i<=bb;i++)
//			{
//				if(a[i]>0ll)minz=min(minz,a[i]);
//				if(a[i]<0ll)maxf=max(maxf,a[i]);
//			}
//			int maxf1=-inf,minz1=inf/*max(x1*x4,x2*x3)*/;
//			for(int i=x;i<=y;i++)
//			{
//				if(b[i]>0ll)minz1=min(minz,b[i]);
//				if(b[i]<0ll)maxf1=max(maxf,b[i]);
//			}
//			if(sum4==0)
//			{
//				if(sum3==0)ans=max(ans,max(x1*x3,x2*x4));
//				else ans=max(ans,x3*x2);
//				else 
//				ans=max(ans,);
//				cout<<"a ";
//			}
//			if(sum6==0)
//			{
//				if(sum1==0)
//				ans=max(ans,max(x1*x3,x2*x4));
//				else ans=max(ans,x4*x1);
//				cout<<"b ";
//			}
//			if(sum1==0)
//			{
//				if(sum4)ans=max(ans,x3*x1);
//				else ans=max(ans,max(x1*x3,x2*x4));
//				cout<<"c ";
//			}
//			if(sum3==0)
//			{
//				if(sum6)ans=max(ans,x2*x4);
//				else ans=max(ans,max(x1*x3,x2*x4));
//				cout<<"d ";
//			}
//			if(sum1&&sum3&&sum4&&sum6)
//			{
//				cout<<minz<<" "<<maxf<<" ";
//				ans=max(ans,max(minz*x4,maxf*x3));
//				cout<<"e ";
//			}
//			if(sum1==0)
//			{
//				
//			}
//			ans=max(ans,max(minz*x4,maxf*x3));
			cout<<ans<<'\n';
		}
	}
}
signed main()
{
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	ios::sync_with_stdio(false);cin.tie(0),cout.tie(0);
	init(),solve();
	return 0;
}
/*
input1:
3 2 2
0 1 -2
-3 4
1 3 1 2
2 3 2 2

output1:
0
4
*/
/*
input2:
6 4 5
3 -1 -2 1 2 0
1 2 -1 -3
1 6 1 4
1 5 1 4
1 4 1 2
2 6 3 4
2 5 2 3

output2:
0
-2
3
2
-1
*/
