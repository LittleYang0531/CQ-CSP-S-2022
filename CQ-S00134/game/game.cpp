#include<bits/stdc++.h>
#define int long long
using namespace std;
inline int read(){
	int s=0,f=1;char ch=getchar();
	while(!isdigit(ch)){
		if(ch=='-') f=-1;
		ch=getchar();
	}
	while(isdigit(ch)) s=s*10+ch-'0',ch=getchar();
	return s*f;
}
void write(int x){
	if(x<0) putchar('-'),x=-x;
	if(x>9) write(x/10);
	putchar(x%10+'0');
}
const int MAXN=1e5+3,INF=1e18+10;
bool xx;
int a[2][MAXN],len[MAXN],sum_x[MAXN],sum_y[MAXN];
struct number{
	vector<int>ve;
};
int max_z(int x,int y){
	return max(x,y);
}
int min_z(int x,int y){
	if(x==0) return y;
	if(y==0) return x;
	return min(x,y);
}
int min_f(int x,int y){
	return min(x,y);
}
int max_f(int x,int y){
	if(x==0) return y;
	if(y==0) return x;
	return max(x,y);
}
struct ST1{
	int z_max[MAXN][18],z_min[MAXN][18],f_max[MAXN][18],f_min[MAXN][18];
//	for(int i=1;i<=N;++i) f_max[MAXN][0]=INT_MIN,f_min
	void build(int now,int N){
		for(int i=1;i<=N;++i){
			if(a[now][i]>0) z_max[i][0]=z_min[i][0]=a[now][i];
			else f_max[i][0]=f_min[i][0]=a[now][i];
		}
		for(int j=1;j<=17;++j)
			for(int i=1;i+(1<<j)-1<=N;++i){
				z_max[i][j]=max_z(z_max[i][j-1],z_max[i+(1<<(j-1))][j-1]);
				f_max[i][j]=max_f(f_max[i][j-1],f_max[i+(1<<(j-1))][j-1]);
				z_min[i][j]=min_z(z_min[i][j-1],z_min[i+(1<<(j-1))][j-1]);
				f_min[i][j]=min_f(f_min[i][j-1],f_min[i+(1<<(j-1))][j-1]);
			}
	}
	number query(int l,int r){
		int ln=len[r-l+1];
		number num;
		int x=0;
		x=max_z(z_max[l][ln],z_max[r-(1<<ln)+1][ln]);
		if(x!=0) num.ve.push_back(x);x=0;
		x=max_f(f_max[l][ln],f_max[r-(1<<ln)+1][ln]);
		if(x!=0) num.ve.push_back(x);x=0;
		x=min_z(z_min[l][ln],z_min[r-(1<<ln)+1][ln]);
		if(x!=0) num.ve.push_back(x);x=0;
		x=min_f(f_min[l][ln],f_min[r-(1<<ln)+1][ln]);
		if(x!=0) num.ve.push_back(x);x=0;
		return num;
	}
}x,y;	
bool  xxx;
signed main(){
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
//	cout<<(&xxx-&xx)/1024.0/1024.0<<endl;
	int N=read(),M=read(),Q=read();
	len[1]=0;for(int i=2;i<=1e5;++i) len[i]=len[i>>1]+1;
	for(int i=1;i<=N;++i) a[0][i]=read(),sum_x[i]=sum_x[i-1]+(a[0][i]==0?1:0);
	for(int i=1;i<=M;++i) a[1][i]=read(),sum_y[i]=sum_y[i-1]+(a[1][i]==0?1:0);
	x.build(0,N),y.build(1,M);
//	for(int i=0;i<=N;++i) printf("%lld\n",sum_x[i]);
	while(Q--){
		int l1=read(),r1=read(),l2=read(),r2=read();
		number qx=x.query(l1,r1);
//		printf("%lld %lld\n",l1,r1);
		number qy=y.query(l2,r2);
		int ans=-INF;
//		for(auto v:qx.ve) printf(" %lld ",v);putchar('\n');
//		for(auto v:qy.ve) printf("%lld ",v);
		for(auto v:qx.ve){
			int now=INF;
			for(int i=0;i<(int)qy.ve.size();++i) now=min(now,qy.ve[i]*v);
			ans=max(ans,now);
		}
		if(sum_x[r1]-sum_x[l1-1]) ans=max(ans,0ll);
		if(sum_y[r2]-sum_y[l2-1]) ans=min(ans,0ll);
		write(ans),putchar('\n');
	}
	return 0 ;	
}
