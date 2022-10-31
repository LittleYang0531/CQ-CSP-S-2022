#include <bits/stdc++.h>
#define ll long long
using namespace std;
void read(int &x)
{
	x=0;int f=1;char c=getchar();
	while(!('0'<=c&&c<='9')){if(c=='-')f=-1;c=getchar();}
	while('0'<=c&&c<='9'){x=x*10+c-'0';c=getchar();}
	x*=f;
}
int cnt0[100005],cntp[100005],cntn[100005],lg[100005],Cnt[100005];
int a[100005],b[100005];
int Pa1[100005][21],Pi1[100005][21],Na1[100005][21],Ni1[100005][21];
int Pa2[100005][21],Pi2[100005][21],Na2[100005][21],Ni2[100005][21];
void Init1(int N)
{
	for(int i=1;i<=N;i++)
	{
		lg[i]=log(i)/log(2);
		Pa1[i][0]=a[i]>0?a[i]:0;
		Pi1[i][0]=a[i]>0?a[i]:1e9+1;
		Na1[i][0]=a[i]<0?a[i]:-1e9-1;
		Ni1[i][0]=a[i]<0?a[i]:0;
	}
	for(int j=1;j<=lg[N];j++)
	{
		for(int i=1;i+(1<<j)-1<=N;i++)
		{
			Pa1[i][j]=max(Pa1[i][j-1],Pa1[i+(1<<(j-1))][j-1]);
			Pi1[i][j]=min(Pi1[i][j-1],Pi1[i+(1<<(j-1))][j-1]);
			Na1[i][j]=max(Na1[i][j-1],Na1[i+(1<<(j-1))][j-1]);
			Ni1[i][j]=min(Ni1[i][j-1],Ni1[i+(1<<(j-1))][j-1]);
		}
	}
}
void Init2(int N)
{
	lg[0]=-1;
	for(int i=1;i<=N;i++)
	{
		lg[i]=lg[i>>1]+1;
		Pa2[i][0]=b[i]>0?b[i]:0;
		Pi2[i][0]=b[i]>0?b[i]:1e9+1;
		Na2[i][0]=b[i]<0?b[i]:-1e9-1;
		Ni2[i][0]=b[i]<0?b[i]:0;
	}
	for(int j=1;j<=lg[N];j++)
	{
		for(int i=1;i+(1<<j)-1<=N;i++)
		{
			Pa2[i][j]=max(Pa2[i][j-1],Pa2[i+(1<<(j-1))][j-1]);
			Pi2[i][j]=min(Pi2[i][j-1],Pi2[i+(1<<(j-1))][j-1]);
			Na2[i][j]=max(Na2[i][j-1],Na2[i+(1<<(j-1))][j-1]);
			Ni2[i][j]=min(Ni2[i][j-1],Ni2[i+(1<<(j-1))][j-1]);
		}
	}
}
int querypa1(int l,int r)
{
	int t=lg[r-l+1];
	return max(Pa1[l][t],Pa1[r-(1<<t)+1][t]);
}
int querypa2(int l,int r)
{
	int t=lg[r-l+1];
	return max(Pa2[l][t],Pa2[r-(1<<t)+1][t]);
}
int queryna1(int l,int r)
{
	int t=lg[r-l+1];
	return max(Na1[l][t],Na1[r-(1<<t)+1][t]);
}
int queryna2(int l,int r)
{
	int t=lg[r-l+1];
	return max(Na2[l][t],Na2[r-(1<<t)+1][t]);
}
int querypi1(int l,int r)
{
	int t=lg[r-l+1];
	return min(Pi1[l][t],Pi1[r-(1<<t)+1][t]);
}
int querypi2(int l,int r)
{
	int t=lg[r-l+1];
	return min(Pi2[l][t],Pi2[r-(1<<t)+1][t]);
}
int queryni1(int l,int r)
{
	int t=lg[r-l+1];
	return min(Ni1[l][t],Ni1[r-(1<<t)+1][t]);
}
int queryni2(int l,int r)
{
	int t=lg[r-l+1];
	return min(Ni2[l][t],Ni2[r-(1<<t)+1][t]);
}
inline int Abs(int x){return x>=0?x:-x;}
bool C(int x){return 1<=Abs(x)&&Abs(x)<=1e9;}
int main() {
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	int n,m,q;
	read(n);read(m);read(q);
	for(int i=1;i<=n;i++) read(a[i]),Cnt[i]=Cnt[i-1]+(a[i]==0);
	for(int i=1;i<=m;i++)
	{
		read(b[i]);
		cnt0[i]=cnt0[i-1]+(b[i]==0);
		cntp[i]=cntp[i-1]+(b[i]>0);
		cntn[i]=cntn[i-1]+(b[i]<0);	
	}
	Init1(n); Init2(m);
	for(int qwq=1;qwq<=q;qwq++)
	{
		int l1,r1,l2,r2;
		read(l1);read(r1);read(l2);read(r2);
//		if(qwq==298)
//		{
//			cerr<<l1<<" "<<r1<<" "<<l2<<" "<<r2<<endl;
//			for(int i=l1;i<=r1;i++) cerr<<a[i]<<" ";cerr<<endl;
//			for(int i=l2;i<=r2;i++) cerr<<b[i]<<" ";cerr<<endl;	
//		}
		ll pa1,pa2,na1,na2,pi1,pi2,ni1,ni2,z1=Cnt[r1]-Cnt[l1-1],z2=cnt0[r2]-cnt0[l2-1];
		ll Ans=-1e18-1;
		pa1=querypa1(l1,r1); na1=queryna1(l1,r1);
		pa2=querypa2(l2,r2); na2=queryna2(l2,r2);
		pi1=querypi1(l1,r1); ni1=queryni1(l1,r1);
		pi2=querypi2(l2,r2); ni2=queryni2(l2,r2);
		ll res1=1e18,res2=1e18,res3=1e18,res4=1e18;
		if(C(pa1))
		{
			if(C(na2)) res1=min(res1,pa1*na2);
			if(C(ni2)) res1=min(res1,pa1*ni2);
			if(C(pa2)) res1=min(res1,pa1*pa2);
			if(C(pi2)) res1=min(res1,pa1*pi2);
			if(z2) res1=min(res1,0ll);
		}
		else res1=-1e18-1;
		if(C(na1))
		{
			if(C(na2)) res2=min(res2,na1*na2);
			if(C(ni2)) res2=min(res2,na1*ni2);
			if(C(pa2)) res2=min(res2,na1*pa2);
			if(C(pi2)) res2=min(res2,na1*pi2);
			if(z2) res2=min(res2,0ll);
		}
		else res2=-1e18-1;
		if(C(pi1))
		{
			if(C(na2)) res3=min(res3,pi1*na2);
			if(C(ni2)) res3=min(res3,pi1*ni2);
			if(C(pa2)) res3=min(res3,pi1*pa2);
			if(C(pi2)) res3=min(res3,pi1*pi2);
			if(z2) res3=min(res3,0ll);
		}
		else res3=-1e18-1;
		if(C(ni1))
		{
			if(C(na2)) res4=min(res4,ni1*na2);
			if(C(ni2)) res4=min(res4,ni1*ni2);
			if(C(pa2)) res4=min(res4,ni1*pa2);
			if(C(pi2)) res4=min(res4,ni1*pi2);
			if(z2) res4=min(res4,0ll);
		}
		else res4=-1e18-1;
		Ans=max(max(res1,res2),max(res3,res4));
		if(z1) Ans=max(Ans,0ll);
		printf("%lld\n",Ans);
	}
	return 0;
}
/*
清夜无尘，月色如银，酒斟时，须满十分；浮名浮利，虚苦劳神，叹隙中驹，石中火，梦中身。
虽抱文章，开口谁亲，且陶陶，乐尽天真；几时归去，作个闲人，对一张琴，一壶酒，一溪云。

#include <bits/stdc++.h>
#define ll long long
using namespace std;
void read(int &x)
{
	x=0;int f=1;char c=getchar();
	while(!('0'<=c&&c<='9')){if(c=='-')f=-1;c=getchar();}
	while('0'<=c&&c<='9'){x=x*10+c-'0';c=getchar();}
	x*=f;
}
int cnt0[100005],cntp[100005],cntn[100005],lg[100005],Cnt[100005];
int a[100005],b[100005];
int Pa1[100005][21],Pi1[100005][21],Na1[100005][21],Ni1[100005][21];
int Pa2[100005][21],Pi2[100005][21],Na2[100005][21],Ni2[100005][21];
void Init1(int N)
{
	for(int i=1;i<=N;i++)
	{
		lg[i]=log(i)/log(2);
		Pa1[i][0]=a[i]>0?a[i]:0;
		Pi1[i][0]=a[i]>0?a[i]:1e9+1;
		Na1[i][0]=a[i]<0?a[i]:-1e9-1;
		Ni1[i][0]=a[i]<0?a[i]:0;
	}
	for(int j=1;j<=lg[N];j++)
	{
		for(int i=1;i+(1<<j)-1<=N;i++)
		{
			Pa1[i][j]=max(Pa1[i][j-1],Pa1[i+(1<<(j-1))][j-1]);
			Pi1[i][j]=min(Pi1[i][j-1],Pi1[i+(1<<(j-1))][j-1]);
			Na1[i][j]=max(Na1[i][j-1],Na1[i+(1<<(j-1))][j-1]);
			Ni1[i][j]=min(Ni1[i][j-1],Ni1[i+(1<<(j-1))][j-1]);
		}
	}
}
void Init2(int N)
{
	lg[0]=-1;
	for(int i=1;i<=N;i++)
	{
		lg[i]=lg[i>>1]+1;
		Pa2[i][0]=b[i]>0?b[i]:0;
		Pi2[i][0]=b[i]>0?b[i]:1e9+1;
		Na2[i][0]=b[i]<0?b[i]:-1e9-1;
		Ni2[i][0]=b[i]<0?b[i]:0;
	}
	for(int j=1;j<=lg[N];j++)
	{
		for(int i=1;i+(1<<j)-1<=N;i++)
		{
			Pa2[i][j]=max(Pa2[i][j-1],Pa2[i+(1<<(j-1))][j-1]);
			Pi2[i][j]=min(Pi2[i][j-1],Pi2[i+(1<<(j-1))][j-1]);
			Na2[i][j]=max(Na2[i][j-1],Na2[i+(1<<(j-1))][j-1]);
			Ni2[i][j]=min(Ni2[i][j-1],Ni2[i+(1<<(j-1))][j-1]);
		}
	}
}
int querypa1(int l,int r)
{
	int t=lg[r-l+1];
	return max(Pa1[l][t],Pa1[r-(1<<t)+1][t]);
}
int querypa2(int l,int r)
{
	int t=lg[r-l+1];
	return max(Pa2[l][t],Pa2[r-(1<<t)+1][t]);
}
int queryna1(int l,int r)
{
	int t=lg[r-l+1];
	return max(Na1[l][t],Na1[r-(1<<t)+1][t]);
}
int queryna2(int l,int r)
{
	int t=lg[r-l+1];
	return max(Na2[l][t],Na2[r-(1<<t)+1][t]);
}
int querypi1(int l,int r)
{
	int t=lg[r-l+1];
	return min(Pi1[l][t],Pi1[r-(1<<t)+1][t]);
}
int querypi2(int l,int r)
{
	int t=lg[r-l+1];
	return min(Pi2[l][t],Pi2[r-(1<<t)+1][t]);
}
int queryni1(int l,int r)
{
	int t=lg[r-l+1];
	return min(Ni1[l][t],Ni1[r-(1<<t)+1][t]);
}
int queryni2(int l,int r)
{
	int t=lg[r-l+1];
	return min(Ni2[l][t],Ni2[r-(1<<t)+1][t]);
}
int main() {
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	int n,m,q;
	read(n);read(m);read(q);
	for(int i=1;i<=n;i++) read(a[i]),Cnt[i]=Cnt[i-1]+(a[i]==0);
	for(int i=1;i<=m;i++)
	{
		read(b[i]);
		cnt0[i]=cnt0[i-1]+(b[i]==0);
		cntp[i]=cntp[i-1]+(b[i]>0);
		cntn[i]=cntn[i-1]+(b[i]<0);	
	}
	Init1(n); Init2(m);
	while(q--)
	{
		int l1,r1,l2,r2;
		read(l1);read(r1);read(l2);read(r2);
		int Zero=cnt0[r2]-cnt0[l2-1],Pos=cntp[r2]-cntp[l2-1],Neg=cntn[r2]-cntn[l2-1];
//		for(int i=0;i<=n;i++) cerr<<lg[i]<<" ";
		if(Pos&&Neg)
		{
			ll Val1,Val2,Val3;
			if(querypi1(l1,r1)<=0||querypi1(l1,r1)>1e9) Val1=-1e18-1; 
			else Val1=1ll*querypi1(l1,r1)*queryni2(l2,r2);
			if(queryna1(l1,r1)>=0||queryna1(l1,r1)<-1e9) Val2=-1e18-1;
			else Val2=1ll*queryna1(l1,r1)*querypa2(l2,r2);
			Val3=(Cnt[r1]-Cnt[l1-1]>0)?0:-1e18-1;
//			cerr<<Val1<<" "<<Val2<<" "<<Val3<<endl;
			printf("%lld\n",min(max(Val1,max(Val2,Val3)),Zero?0:(ll)1e18));
		}
		else if(Pos)
		{
//			cerr<<q<<endl;
			ll Val1,Val2,Val3;
//			cerr<<querypa1(l1,r1)<<" "<<querypi2(l2,r2)<<endl;
			if(querypa1(l1,r1)<=0||querypa1(l1,r1)>1e9) Val1=-1e18-1;
			else Val1=1ll*querypa1(l1,r1)*querypi2(l2,r2);
			if(queryna1(l1,r1)>=0||queryna1(l1,r1)<-1e9) Val2=-1e18-1;
			else Val2=1ll*queryna1(l1,r1)*querypi2(l2,r2);
			Val3=(Cnt[r1]-Cnt[l1-1]>0)?0:-1e18-1;
//			cerr<<Val1<<" "<<Val2<<" "<<Val3<<endl;
			printf("%lld\n",min(max(Val1,max(Val2,Val3)),Zero?0:(ll)1e18));
		}
		else if(Neg)
		{
			ll Val1,Val2,Val3;
			if(queryni1(l1,r1)>=0||queryni1(l1,r1)<-1e9) Val1=-1e18-1;
			else Val1=1ll*queryni1(l1,r1)*queryna2(l2,r2);
			if(querypi1(l1,r1)<=0||querypi1(l1,r1)>1e9) Val2=-1e18-1;
			else Val2=1ll*querypi1(l1,r1)*queryna2(l2,r2);
			Val3=(Cnt[r1]-Cnt[l1-1]>0)?0:-1e18-1;
			printf("%lld\n",min(max(Val1,max(Val2,Val3)),Zero?0:(ll)1e18));
		}
		else puts("0");
	}
	return 0;
}
清夜无尘，月色如银，酒斟时，须满十分；浮名浮利，虚苦劳神，叹隙中驹，石中火，梦中身。
虽抱文章，开口谁亲，且陶陶，乐尽天真；几时归去，作个闲人，对一张琴，一壶酒，一溪云。
*/


