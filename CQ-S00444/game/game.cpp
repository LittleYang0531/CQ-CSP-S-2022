#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int n,m,q,a[N],b[N],bl1[N],bl2[N],l[1005],ll[1005],r[1005],rr[1005],maxa[1005],mina[1005],maxb[1005],minb[1005];
inline void Build1()
{
	int tn=sqrt(n),num=0,cnt=0;
	for(int i=1;i<=n;++i)
	{
		if(cnt%tn==0) ++num;
		++cnt;
		bl1[i]=num;
		maxa[num]=max(maxa[num],a[i]);
		mina[num]=min(mina[num],a[i]);
	}
	for(int i=1;i<=num;++i)
	l[i]=(i-1)*tn+1,r[i]=i*tn;
	r[num]=n;
}
inline void Build2()
{
	int tm=sqrt(m),num=0,cnt=0;
	for(int i=1;i<=m;++i)
	{
		if(cnt%tm==0) ++num;
		++cnt;
		bl2[i]=num;
		maxb[num]=max(maxb[num],b[i]);
		minb[num]=min(minb[num],b[i]);
	}
	for(int i=1;i<=num;++i)
	ll[i]=(i-1)*tm+1,rr[i]=i*tm;
	rr[num]=n;
}
int Aska1(int L,int R)
{
	int ans=0;
	if(L==l[bl1[L]]&&R==r[bl1[R]])
	{
		for(int i=l[bl1[L]];i<=r[bl1[R]];++i)
		ans=max(ans,maxa[i]);
		return ans;
	}
	if(bl1[L]==bl1[R])
	{
		for(int i=L;i<=R;++i)
		ans=max(ans,a[i]);
		return ans;
	}
	for(int i=L;i<=r[bl1[L]];++i)
	ans=max(ans,a[i]);
	for(int i=l[bl1[R]];i<=R;++i)
	ans=max(ans,a[i]);
	for(int i=bl1[L]+1;i<bl1[R];++i)
	ans=max(ans,maxa[i]);
	return ans;
}
int Aska2(int L,int R)
{
	int ans=INT_MAX;
	if(L==l[bl1[L]]&&R==r[bl1[R]])
	{
		for(int i=l[bl1[L]];i<=r[bl1[R]];++i)
		ans=min(ans,mina[i]);
		return ans;
	}
	if(bl1[L]==bl1[R])
	{
		for(int i=L;i<=R;++i)
		ans=min(ans,a[i]);
		return ans;
	}
	for(int i=L;i<=r[bl1[L]];++i)
	ans=min(ans,a[i]);
	for(int i=l[bl1[R]];i<=R;++i)
	ans=min(ans,a[i]);
	for(int i=bl1[L]+1;i<bl1[R];++i)
	ans=min(ans,mina[i]);
	return ans;
}
int Askb1(int L,int R)
{
	int ans=0;
	if(L==ll[bl2[L]]&&R==rr[bl2[R]])
	{
		for(int i=ll[bl2[L]];i<=rr[bl2[R]];++i)
		ans=max(ans,maxb[i]);
		return ans;
	}
	if(bl2[L]==bl2[R])
	{
		for(int i=L;i<=R;++i)
		ans=max(ans,b[i]);
		return ans;
	}
	for(int i=L;i<=rr[bl2[L]];++i)
	ans=max(ans,b[i]);
	for(int i=ll[bl2[R]];i<=R;++i)
	ans=max(ans,b[i]);
	for(int i=bl2[L]+1;i<bl2[R];++i)
	ans=max(ans,maxb[i]);
	return ans;
}
int Askb2(int L,int R)
{
	int ans=INT_MAX;
	if(L==ll[bl2[L]]&&R==rr[bl2[R]])
	{
		for(int i=ll[bl2[L]];i<=rr[bl2[R]];++i)
		ans=min(ans,minb[i]);
		return ans;
	}
	if(bl2[L]==bl2[R])
	{
		for(int i=L;i<=R;++i)
		ans=min(ans,b[i]);
		return ans;
	}
	for(int i=L;i<=rr[bl2[L]];++i)
	ans=min(ans,b[i]);
	for(int i=ll[bl2[R]];i<=R;++i)
	ans=min(ans,b[i]);
	for(int i=bl2[L]+1;i<bl2[R];++i)
	ans=min(ans,minb[i]);
	return ans;
}
int main()
{
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL),cout.tie(NULL);
	
	cin>>n>>m>>q;
	int flag=0;
	for(int i=1;i<=n;++i)cin>>a[i];
	for(int i=1;i<=m;++i) cin>>b[i];
	memset(minb,0x3f,sizeof minb);
	memset(mina,0x3f,sizeof mina);
	Build1(),Build2();
	while(q--)
	{
		int l1,l2,r1,r2,mx,mi;
		cin>>l1>>r1>>l2>>r2;
		if(l2==r2)
		{
			mi=b[l2];
			if(mi<0) mx=Aska2(l1,r1);
			else if(!mi)
			{
				cout<<"0\n";
				continue;
			}
			else mx=Aska1(l1,r1);
		}
		else if(l1==r1)
		{
			mx=a[l1];
			if(mx<0) mi=Askb1(l2,r2);
			else if(!mx)
			{
				cout<<"0\n";
				continue;
			}
			else mi=Askb2(l2,r2);
		}
		else mx=Aska1(l1,r1),mi=Askb2(l2,r2);
//		cout<<mi<<" "<<mx<<"\n";
		cout<<mx*mi<<"\n";
	}
	return 0;
}
/*
4 4 3
2 3 2 8
0 1 2 3
1 3 1 3
2 3 1 4
1 3 2 4
-----------
4 4 3
-1 3 2 8
0 1 2 -2
1 1 1 3
2 3 1 1
3 3 2 4
*/
