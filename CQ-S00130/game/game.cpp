#include<cstdio>
#include<cmath>
#include<set>
#include<vector>
#include<queue>
#include<stack>
#include<map> 
#include<iostream>
#include<algorithm>
#include<bitset>
#include<unordered_map>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/hash_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
#define LL long long
inline int read(){
	int x=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-')f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		x=x*10+c-'0';
		c=getchar();
	}
	return x*f;
}
const int mod=998244353;
inline int add(int x,int y){
	return x+y>=mod?x+y-mod:x+y;
}
inline int dec(int x,int y){
	return x-y<0?x-y+mod:x-y; 
}
inline int qkpow(int a,int b){
	int res=1,base=a;
	while(b){
		if(b&1)res=1ll*res*base%mod;
		base=1ll*base*base%mod;
		b>>=1;
	}
	return res;
}
int n,m,q,a[100005],b[100005],Log[100005],tmp1[5],tmp2[5];
int f1[100005][21][4];
int f2[100005][21][4];
const int INF1=2e9;
const int INF2=-2e9;
inline int query1(int l,int r,int p){
	int k=Log[r-l+1];
	if(p==0||p==2)return min(f1[l][k][p],f1[r-(1<<k)+1][k][p]);
	return max(f1[l][k][p],f1[r-(1<<k)+1][k][p]);
}
inline int query2(int l,int r,int p){
	int k=Log[r-l+1];
	if(p==0||p==2)return min(f2[l][k][p],f2[r-(1<<k)+1][k][p]);
	return max(f2[l][k][p],f2[r-(1<<k)+1][k][p]);
}
signed main(){
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	n=read(),m=read(),q=read();
	for(int i=1;i<=n;i++)a[i]=read(); 
	for(int i=1;i<=m;i++)b[i]=read();
	Log[1]=0;
	for(int i=2;i<=100000;i++)Log[i]=Log[i>>1]+1;
	//0 2 minn
	//1 3 maxx
	//0 1 查询负数
	//2 3 查询正数 
	for(int i=1;i<=n;i++){
		if(a[i]<0)f1[i][0][0]=f1[i][0][1]=a[i],f1[i][0][2]=INF1,f1[i][0][3]=INF2;
		else f1[i][0][2]=f1[i][0][3]=a[i],f1[i][0][0]=INF1,f1[i][0][1]=INF2;
	}
	for(int i=1;i<=m;i++){
		if(b[i]<0)f2[i][0][0]=f2[i][0][1]=b[i],f2[i][0][2]=INF1,f2[i][0][3]=INF2;
		else f2[i][0][2]=f2[i][0][3]=b[i],f2[i][0][0]=INF1,f2[i][0][1]=INF2;
	}
	for(int j=1;(1<<j)<=n;j++){
		for(int i=1;i+(1<<j)-1<=n;i++){
			f1[i][j][0]=min(f1[i][j-1][0],f1[i+(1<<(j-1))][j-1][0]);
			f1[i][j][1]=max(f1[i][j-1][1],f1[i+(1<<(j-1))][j-1][1]);
			f1[i][j][2]=min(f1[i][j-1][2],f1[i+(1<<(j-1))][j-1][2]);
			f1[i][j][3]=max(f1[i][j-1][3],f1[i+(1<<(j-1))][j-1][3]);
		}
	}
	for(int j=1;(1<<j)<=m;j++){
		for(int i=1;i+(1<<j)-1<=m;i++){
			f2[i][j][0]=min(f2[i][j-1][0],f2[i+(1<<(j-1))][j-1][0]);
			f2[i][j][1]=max(f2[i][j-1][1],f2[i+(1<<(j-1))][j-1][1]);
			f2[i][j][2]=min(f2[i][j-1][2],f2[i+(1<<(j-1))][j-1][2]);
			f2[i][j][3]=max(f2[i][j-1][3],f2[i+(1<<(j-1))][j-1][3]);
		}
	}
	while(q--){
		LL res=-2e18;
		int l1,r1,l2,r2;
	//	scanf("%d %d %d %d",&l1,&r1,&l2,&r2);
		l1=read(),r1=read(),l2=read(),r2=read(); 
		int len1=0,len2=0;
		for(int i=0;i<4;i++){
			int val=query1(l1,r1,i);
			if(val!=INF1&&val!=INF2)
				tmp1[++len1]=val;
		}
		for(int i=0;i<4;i++){
			int val=query2(l2,r2,i);
			if(val!=INF1&&val!=INF2)
				tmp2[++len2]=val;
		}
		/*
		cout<<len1<<":";
		for(int i=1;i<=len1;i++)cout<<tmp1[i]<<" ";
		cout<<endl;
		cout<<len2<<":";
		for(int i=1;i<=len2;i++)cout<<tmp2[i]<<" ";
		cout<<endl;
		*/
		for(int i=1;i<=len1;i++){
			LL minn=2e18;
			for(int j=1;j<=len2;j++)
				minn=min(minn,1ll*tmp1[i]*tmp2[j]);
			res=max(res,minn);
		}
		printf("%lld\n",res);
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
