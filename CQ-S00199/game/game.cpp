#include<stdio.h>
#include<algorithm>
using std::max;
using std::min;
const int inf=2000000000;
const long long infll=1000000000000000000;
struct node{
	int maxNum;
	int minNum;
	int _maxNum;
	int _minNum;
};
node t[400005],t2[400005];
int n,m,q;
int a[100005];
int b[100005];
int l,r,L,R;
node ans,ans2;
long long sum;
void build(int p,int L,int R)
{
	if(L==R)
	{
		t[p].maxNum=t[p].minNum=a[L];
		if(a[L]>0)
		{
			t[p]._minNum=a[L];
			t[p]._maxNum=-inf;
		}
		else
		{
			t[p]._maxNum=a[L];
			t[p]._minNum=inf;
		}
	}
	else
	{
		int mid=L+R>>1;
		build(p<<1,L,mid);
		build(p<<1|1,mid+1,R);
		t[p].maxNum=max(t[p<<1].maxNum,t[p<<1|1].maxNum);
		t[p].minNum=min(t[p<<1].minNum,t[p<<1|1].minNum);
		t[p]._maxNum=max(t[p<<1]._maxNum,t[p<<1|1]._maxNum);
		t[p]._minNum=min(t[p<<1]._minNum,t[p<<1|1]._minNum);
	}
}
void build2(int p,int L,int R)
{
	if(L==R)
	{
		t2[p].maxNum=t2[p].minNum=b[L];
	}
	else
	{
		int mid=L+R>>1;
		build2(p<<1,L,mid);
		build2(p<<1|1,mid+1,R);
		t2[p].maxNum=max(t2[p<<1].maxNum,t2[p<<1|1].maxNum);
		t2[p].minNum=min(t2[p<<1].minNum,t2[p<<1|1].minNum);
	}
}
void query(int p,int L,int R,int l,int r)
{
	if(l<=L&&r>=R)
	{
		ans.maxNum=max(ans.maxNum,t[p].maxNum);
		ans.minNum=min(ans.minNum,t[p].minNum);
		ans._maxNum=max(ans._maxNum,t[p]._maxNum);
		ans._minNum=min(ans._minNum,t[p]._minNum);
	}
	else
	{
		int mid=L+R>>1;
		if(l<=mid)
		{
			query(p<<1,L,mid,l,r);
		}
		if(r>mid)
		{
			query(p<<1|1,mid+1,R,l,r);
		}
	}
}
void query2(int p,int L,int R,int l,int r)
{
	if(l<=L&&r>=R)
	{
		ans2.maxNum=max(ans2.maxNum,t2[p].maxNum);
		ans2.minNum=min(ans2.minNum,t2[p].minNum);
	}
	else
	{
		int mid=L+R>>1;
		if(l<=mid)
		{
			query2(p<<1,L,mid,l,r);
		}
		if(r>mid)
		{
			query2(p<<1|1,mid+1,R,l,r);
		}
	}
}
int main()
{
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	scanf("%d%d%d",&n,&m,&q);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
	}
	for(int i=1;i<=m;i++)
	{
		scanf("%d",&b[i]);
	}
	build(1,1,n);
	build2(1,1,m);
	for(int i=1;i<=q;i++)
	{
		scanf("%d%d%d%d",&l,&r,&L,&R);
		ans.maxNum=-inf;
		ans.minNum=inf;
		ans._maxNum=-inf;
		ans._minNum=inf;
		ans2.maxNum=-inf;
		ans2.minNum=inf;
		query(1,1,n,l,r);
		query2(1,1,m,L,R);
//		printf("q:\n");
//		printf("%d %d %d %d\n",ans.maxNum,ans.minNum,ans._maxNum,ans._minNum);
//		printf("%d %d\n",ans2.maxNum,ans2.minNum);
		sum=min((long long)ans.maxNum*ans2.maxNum,(long long)ans.maxNum*ans2.minNum);
		sum=max(sum,min((long long)ans.minNum*ans2.maxNum,(long long)ans.minNum*ans2.minNum));
		if(ans._maxNum>-inf)
		{
			sum=max(sum,min((long long)ans._maxNum*ans2.maxNum,(long long)ans._maxNum*ans2.minNum));
		}
		if(ans._minNum<inf)
		{
			sum=max(sum,min((long long)ans._minNum*ans2.maxNum,(long long)ans._minNum*ans2.minNum));
		}
		printf("%lld\n",sum);
	}
	return 0;
}
/*
6 4 5
3 -1 -2 1 2 0
1 2 -1 -3
1 6 1 4
1 5 1 4
1 4 1 2
2 6 3 4
2 5 2 3
*/
