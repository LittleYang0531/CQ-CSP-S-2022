#include <bits/stdc++.h>
#define int long long
#define gc getchar
#define pc putchar
#define space pc(' ')
#define enter pc('\n')
#define me(x,p) memset(x,p,sizeof(x))
#define pf printf
#define pb push_back
#define FOR(i,k,n,p) for(int (i)=(k);(i)<=(n);(i)+=(p))
#define ROF(i,k,n,p) for(int (i)=(k);(i)>=(n);(i)-=(p))
using namespace std ;
const int INF = 1e18+7 ;
const int N = 1e5+5 ;
int n,m,q,p1,p2,p3,p4,p5,ans ;
int q1,q2,q3,q4,q5 ;
int a[N],b[N] ;
inline void read(int &x)
{
	x = 0 ; int f = 0 ; char cc = gc() ;
	while(!isdigit(cc)) f |= (cc=='-'),cc = gc() ;
	while(isdigit(cc)) x = (x<<1)+(x<<3)+(cc^48),cc = gc() ;
	x = f?-x:x ;
}
void print(int x)
{
	if(x < 0) pc('-'),x = -x ;
	if(x > 9) print(x/10) ;
	pc(x%10+'0') ;
}
struct T
{
	struct Node
	{
		int l,r,qq1=0,qq2=0,qq3=0,qq4=-1,qq5=-INF ;
	}tr[N<<2] ;
	#define ls(x) (x<<1)
	#define rs(x) (x<<1|1)
	#define mid ((tr[x].l+tr[x].r)>>1 )
	#define pp1 tr[x].qq1
	#define pp2 tr[x].qq2
	#define pp3 tr[x].qq3
	#define pp4 tr[x].qq4
	#define pp5 tr[x].qq5
	inline void update(int x)
	{
		pp1 = min(tr[ls(x)].qq1,tr[rs(x)].qq1) ;
		if(tr[ls(x)].qq2 || tr[rs(x)].qq2)
		{
			if(tr[ls(x)].qq2) pp2 = tr[ls(x)].qq2 ;
			else pp2 = tr[rs(x)].qq2 ;
			if(tr[ls(x)].qq2 && tr[rs(x)].qq2)
				pp2 = max(tr[ls(x)].qq2,tr[rs(x)].qq2) ;
		}
		pp3 |= tr[ls(x)].qq3|tr[rs(x)].qq3 ;
		if((~tr[ls(x)].qq4) || (~tr[rs(x)].qq4))
		{
			if(~tr[ls(x)].qq4) pp4 = tr[ls(x)].qq4 ;
			else pp4 = tr[rs(x)].qq4 ;
			if((~tr[ls(x)].qq4) && (~tr[rs(x)].qq4)) pp4 = min(tr[ls(x)].qq4,tr[rs(x)].qq4) ;
		}
			
		pp5 = max(tr[ls(x)].qq5,tr[rs(x)].qq5) ;
	}
	void Build(int x,int le,int ri,int *v)
	{
		tr[x].l = le,tr[x].r = ri ;
		if(le == ri)
		{
			int i = le ;
			if(v[i] < 0) pp1 = v[i],pp2 = v[i] ;
			if(v[i] == 0) pp3 = 1 ;
			if(v[i] > 0) pp4 = v[i],pp5 = v[i] ;;
//			print(le),space,print(ri),space,print(pp4),enter ;
			return ;
		}
		Build(ls(x),le,mid,v),Build(rs(x),mid+1,ri,v) ;
		update(x) ;
//		print(le),space,print(ri),space,print(pp4),enter ;
	}
	inline void Calc(int ty,Node y,int pd)
	{
		if(!pd)
		{
//			if(a[i] < 0) p1 = min(p1,a[i]),p2 = p2?max(p2,a[i]):a[i] ;
//			if(a[i] == 0) p3 = 1 ;
//			if(a[i] > 0) p4 = (p4!=-1)?min(p4,a[i]):a[i],p5 = max(p5,a[i]) ;
//			if(ty == 5)
//			{
//				pf("p"),print(p5),space,print(y.qq5),space,print(y.l),space,print(y.r),enter ;
//			}
			if(ty == 1) p1 = min(p1,y.qq1) ;
			if(ty == 2)
			{
				if(y.qq2)
				p2 = p2?max(p2,y.qq2):y.qq2 ;
			 } 
			if(ty == 3) p3 |= y.qq3 ;
			if(ty == 4) 
			{
				if(y.qq4 != -1)	p4 = (p4!=-1)?min(p4,y.qq4):y.qq4 ;
			}
			if(ty == 5) p5 = max(p5,y.qq5) ;
		}
		else
		{
			if(ty == 1) q1 = min(q1,y.qq1) ;			
			if(ty == 2)
			{
				if(y.qq2)
				q2 = q2?max(q2,y.qq2):y.qq2 ;
			 } 
			if(ty == 3) q3 |= y.qq3 ;
			if(ty == 4) 
			{
				if(y.qq4 != -1)	q4 = (q4!=-1)?min(q4,y.qq4):y.qq4 ;
			}
			if(ty == 5) q5 = max(q5,y.qq5) ;
		}
	}
	void Query(int x,int le,int ri,int ty,int pd)
	{
//		pf("???: "),print(le),space,print(ri),space,print(tr[x].l),space,print(tr[x].r),enter ;
		if(tr[x].l >= le && tr[x].r <= ri)
		{
			Calc(ty,tr[x],pd) ; return ;
		}
		if(le <= mid) Query(ls(x),le,ri,ty,pd) ;
		if(mid < ri) Query(rs(x),le,ri,ty,pd) ;
	}
}S[3] ;
signed main()
{
	freopen("game.in","r",stdin) ;
	freopen("game.out","w",stdout) ;
	read(n),read(m),read(q) ;
	FOR(i,1,n,1) read(a[i]) ;
	FOR(i,1,m,1) read(b[i]) ;
	S[1].Build(1,1,n,a) ; 
	S[2].Build(1,1,m,b) ;	
	while(q--)
	{
		int l1,l2,r1,r2,ans = -INF ;
		q1 = 0,q2 = 0,q3 = 0,q4 = -1,q5 = -INF ;
		p1 = 0,p2 = 0,p3 = 0,p4 = -1,p5 = -INF ;
		read(l1),read(r1),read(l2),read(r2) ;
		S[1].Query(1,l1,r1,1,0) ;
		S[1].Query(1,l1,r1,2,0) ;
		S[1].Query(1,l1,r1,3,0) ;
		S[1].Query(1,l1,r1,4,0) ;
		S[1].Query(1,l1,r1,5,0) ;
		S[2].Query(1,l2,r2,1,1) ;
		S[2].Query(1,l2,r2,2,1) ;
		S[2].Query(1,l2,r2,3,1) ;
		S[2].Query(1,l2,r2,4,1) ;
		S[2].Query(1,l2,r2,5,1) ;
		if(p1 < 0)
		{
			if(q5 > 0) ans = max(ans,q5*p1) ;
			else if(q3) ans = max(ans,0ll) ;
			else if(q2) ans = max(ans,p1*q2) ;
		}
		if(p2)
		{
			if(q5 > 0) ans = max(ans,q5*p2) ;
			else if(q3) ans = max(ans,0ll) ;
			else if(q2) ans = max(ans,p2*q2) ;
		}
		if(p3) ans = max(ans,0ll) ;
		if(~p4)
		{
			if(q1 < 0) ans = max(q1*p4,ans) ;
			else if(q3) ans = max(ans,0ll) ;
			else if(~q4) ans = max(p4*q4,ans) ;
		}
		if(p5 > 0)
		{
			if(q1 < 0) ans = max(q1*p5,ans) ;
			else if(q3) ans = max(ans,0ll) ;
			else if(~q4) ans = max(p5*q4,ans) ;
		}
		print(ans),enter ;
	}
	return 0 ;
}
//寄了,玛丽太弱,后面的暴力都没打 


