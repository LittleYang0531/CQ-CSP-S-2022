#include<bits/stdc++.h>
#define int long long
using namespace std;
inline int read(){
	int x=0,f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		x=(x<<1)+(x<<3)+(ch^48);
		ch=getchar();
	}
	return x*f;
} 
const int N=2510,M=1e4+10;
int to[M<<1],net[M<<1],hed[N],cnt,val[N],cnt1;
struct node{
	int id,j,k,q[5],val;
	node(int x,int y,int z,int *dff,int va){
		id=x,j=y,k=z,val=va;
		for(int i=0;i<=4;i++)q[i]=dff[i];
	}
	bool operator<(const node va)const{
		return va.val>val;
	}
};
struct fg{
	int val,q[5];
}dp[N][5][105];
void add(int x,int y){
	to[++cnt]=y,net[cnt]=hed[x],hed[x]=cnt;
}
priority_queue<node>q;

signed main(){
	freopen("holiday.in","r",stdin);
	freopen("holiday.out","w",stdout);
	int n=read(),m=read(),k1=read();
	for(int i=2;i<=n;i++){
		val[i]=read();
	}
	for(int i=1;i<=m;i++){
		int x=read(),y=read();
		add(x,y),add(y,x);
	}
	int sd[5]={0,0,0,0,0};
	q.push(node(1,0,0,sd,1));
	dp[1][0][0].val=1;
	dp[1][0][0].q[0]=1;
	while(!q.empty()){
		node x=q.top();
		q.pop();
		if(dp[x.id][x.j][x.k].val!=x.val){
			continue;
		}
		for(int i=hed[x.id];i;i=net[i]){
			int y=to[i];
			if(x.j!=4&&dp[x.id][x.j][x.k].val+val[x.id]>dp[y][x.j+1][1].val){
				int f=1;
				for(int j=0;j<=x.j;j++){
					if(dp[x.id][x.j][x.k].q[j]==x.id)f=0;
				}
				if(f){
					dp[y][x.j+1][1].val=dp[x.id][x.j][x.k].val+val[x.id];
					for(int j=0;j<=x.j;j++){
						dp[y][x.j+1][1].q[j]=dp[x.id][x.j][x.k].q[j];
					}
					dp[y][x.j+1][1].q[x.j+1]=x.id;
					q.push(node(y,x.j+1,1,dp[x.id][x.j][x.k].q,dp[y][x.j+1][1].val));
				}
			}
			if(x.k<=k1&&dp[x.id][x.j][x.k].val>dp[y][x.j][x.k+1].val){
				dp[y][x.j][x.k+1].val=dp[x.id][x.j][x.k].val;
				for(int j=0;j<=x.j;j++){
					dp[y][x.j][x.k+1].q[j]=dp[x.id][x.j][x.k].q[j];
				}
				q.push(node(y,x.j,x.k+1,dp[y][x.j][x.k+1].q,dp[y][x.j][x.k+1].val));
			}
			++cnt1;
		}
	}
//	cout<<cnt1<<endl;
	int ans=0;
	for(int i=1;i<=k1+1;i++){
		ans=max(ans,dp[1][4][i].val);
//		for(int j=0;j<=4;j++){
//			printf("%lld ",dp[1][4][i].q[j]);
//		}
//		cout<<endl<<dp[1][4][i].val<<endl;
	}
	printf("%lld",ans-1);
	return 0;
}
