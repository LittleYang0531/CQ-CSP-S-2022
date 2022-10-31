#include<cstdio>
#include<vector>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<cmath>
#define N 100005
#define ll long long
#define INF_INT 0x3f3f3f3f
using namespace std;
char c;
int flag;
inline void rd(ll &x){
	x=0;
	flag=1;
	c=getchar();
	while((c<'0'||c>'9')&&c!='-')c=getchar();
	if(c=='-')c=getchar(),flag=-1;
	while(c>='0'&&c<='9'){
		x=(x<<1)+(x<<3)+c-48;
		c=getchar();
	}
	x*=flag;
}
int n,m,Q,tp,sp1=1,sp2;
ll a[N],b[N],l1,r1,l2,r2;
bool vis[3][1005][1005];
ll mx[3][N][32],mn[3][N][32];
void ST(int id){
	if(id==1){
		for(int i=1;i<=n;i++)
			mn[id][i][0]=mx[id][i][0]=a[i];
	}	
	else{
		for(int i=1;i<=m;i++)
			for(int j=1;j<=32;j++)
				mn[id][i][j]=INF_INT;
		for(int i=1;i<=m;i++)
			mn[id][i][0]=mx[id][i][0]=b[i];
	}
		
	if(id==1)
		for(int j=1;j<=log2(n);j++)
			for(int i=1;i<=n-(1<<j)+1;i++){
				mx[id][i][j]=max(mx[id][i][j-1],mx[id][i+(1<<j-1)][j-1]);
				mn[id][i][j]=min(mn[id][i][j-1],mn[id][i+(1<<j-1)][j-1]);
			}
	else
		for(int j=1;j<=log2(m);j++)
			for(int i=1;i<=m-(1<<j)+1;i++){
				mx[id][i][j]=max(mx[id][i][j-1],mx[id][i+(1<<j-1)][j-1]);
				mn[id][i][j]=min(mn[id][i][j-1],mn[id][i+(1<<j-1)][j-1]);
			}
}
inline ll ask_min(int id,ll x,ll y){
	tp=log2(y-x+1);
	return min(mn[id][x][tp],mn[id][y-(1<<tp)+1][tp]);
}
inline ll ask_max(int id,ll x,ll y){
	tp=log2(y-x+1);
	return max(mx[id][x][tp],mx[id][y-(1<<tp)+1][tp]);
}
inline void solve(){
	rd(l1),rd(r1),rd(l2),rd(r2);
	ll ans=-INF_INT,sum=INF_INT;
	ll maxx1=ask_max(1,l1,r1);
	ll	minn1=ask_min(1,l1,r1);
	ll maxx2=ask_max(2,l2,r2);
	ll minn2=ask_min(2,l2,r2);
	ll p1=vis[1][l1][r1],p2=vis[2][l2][r2];	
	if(minn1>0&&minn2>0){
		printf("%lld\n",(ll)maxx1*minn2);
		return ;
	}
	if(maxx1<0&&maxx2<0){
		printf("%lld\n",(ll)minn1*maxx2);
		return ;
	}
	for(int i=l1;i<=r1;i++){
		sum=INF_INT;
		for(int j=l2;j<=r2;j++){
			sum=min(sum,(ll)a[i]*b[j]);
			if(sum<ans)break;
		}
		ans=max(ans,sum);
	}
	printf("%lld\n",ans);
	return ;			
//	if(l1==r1){
//		if(maxx1<0){
//			if(minn2>0)
//				ans=(ll)maxx1*maxx2;
//			else 
//				if(p2)ans=0;
//				else ans=(ll)maxx1*maxx2;
//		}
//		else if(maxx1==0)ans=0;
//		else {
//			if(maxx2<0)
//				ans=(ll)maxx1*minn2;
//			else 
//				if(p2)ans=0;
//				else ans=(ll)maxx1*minn2;
//		}
//	}
//	else{
//		if(maxx2<0){
//			if(minn1>0)
//				ans=(ll)maxx2*minn1;
//			else {
//				if(p1)ans=0;
//				ans=max(ans,(ll)maxx2*maxx1);
//			}
//		}
//		else if(maxx2==0)ans=0;
//		else {
//			if(maxx1>0)
//				ans=(ll)maxx2*maxx1;
//			else{
//				if(p1)ans=0;
//				ans=max(ans,(ll)maxx*maxx1);
//			}
//		}
//	}
//	printf("%d %d %d %d\n",maxx1,minn1,maxx2,minn2);
//	cout<<p1<<" "<<p2<<endl;
//	if(maxx1<=0&&minn2<=0)
//		if(p1)ans=0;
//		else ans=(ll)maxx1*minn1;
//	else if(minn1>=0&&minn2<=0)
//		ans=(ll)minn1*minn2;
//	else if(maxx1>0){
//		if(minn1<0){
//			if(maxx2>0)
//				if(p1)ans=0;
//				else ans=min((ll)maxx1*minn2,(ll)maxx2*minn1);
//			else
//				ans=minn1*maxx2;
//		}
//	}
//	printf("%lld\n",ans);
}
int main(){
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	cin>>n>>m>>Q;
	for(int i=1;i<=n;i++)rd(a[i]),sp1&=(a[i]>0);
	for(int i=1;i<=m;i++)rd(b[i]),sp1&=(b[i]>0);
	for(int i=1;i<=m;i++){
		for(int j=i+1;j<=m;j++)
			vis[2][i][j]=((vis[2][i][j-1]+(b[j]==0))>0);
	}
	ST(1);
	ST(2);
	while(Q--){
		solve();
	}
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
