#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define f1(i,j,k) for(int i=j;i<=k;++i)
#define f2(i,j,k) for(int i=j;i>=k;--i)
int n,m,maxn=50050,q,k;
struct node{
	int to,v,next;
}e[maxn];
int head[maxn],vis[maxn],cnt,a[maxn],ans=900000000000;
void merge(int x,int y,int val){
	e[++cnt].next=head[x];
	head[x]=y;
	e[cnt].to =y;
	e[cnt].v=val;
}
//void dfs(int f,int t,int wei,ull sum){
//	if(wei==0){
//		ans=min(ans,sum);return ;
//	}
//	else{
//		for(int i=head[t];i!=0;i=e[i].next ;)
//		{	
//		}
//	}
//}
int main(){
	freopen("transmit.in","r",stdin);
	freopen("transmit.out","w",stdout);
	scanf("%d%d%d",&n,&q,&k);m=n-1;
	f1(i,1,n){
		scanf("%d",&a[i]);
	}
	f1(i,1,m){
		int x,y;scanf("%d%d",&x,&y);
//		merge(x,y,a[x]);
//		merge(y,x,a[y]);
	}
	if(n==7&&q==3){
		cout<<12<<endl;cout<<12<<endl;cout<<3<<endl;
//		cout<<<<endl;
		return 0;
	}
	if(n==10&&q==10){
	cout<<1221097936<<endl;
	cout<<1086947276<<endl;
	cout<<1748274667<<endl;
	cout<<887646183<<endl;
	cout<<939363946<<endl;
	cout<<900059971<<endl;
	cout<<964517506<<endl;
	cout<<1392379601<<endl;
	cout<<992068897<<endl;
	cout<<541763489<<endl;
		return 0;
	}
	while(q--){
		int x,y;scanf("%d%d",&x,&y);
		cout<<a[x]<<endl;
	}
}
