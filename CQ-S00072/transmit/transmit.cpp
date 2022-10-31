#include<bits/stdc++.h>
using namespace std;
int n,Q,k;
int v[200005];
struct Node{
	int to,next;
}e[200005];
int cnt=0;
int h[200005];
int ans=0;
int minn=0x7fffffff;
void add(int x,int y){
	cnt++;
	e[cnt].next=h[x];
	e[cnt].to=y;
	h[x]=cnt;
}
void dfs(int x,int fa){
	for(int i=h[x];i;i=e[i].next){
		int y=e[i].to;
		cnt++;
		minn=min(v[y],minn);
//		cout<<"Y"<<y<<endl;
//		cout<<cnt<<endl;
		if(cnt==k){
			cnt=0;
			ans+=minn;
//			cout<<minn<<endl;
			minn=0x7fffffff;
		}
		if(y==fa){
			ans+=minn;
			return;
		}
		dfs(y,x);
		ans-=minn;
		cnt--;
		
	}
}
int main()
{
	freopen("transmit.in","r",stdin);
	freopen("transmit.out","w",stdout);
	cin>>n>>Q>>k;
	for(int i=1;i<=n;++i){
		scanf("%d",&v[i]);
	}
	for(int i=1;i<n;++i){
		int a,b;
		scanf("%d%d",&a,&b);
		add(a,b);
		add(b,a);
	}
	for(int i=1;i<=Q;++i){
		int x,y;
		scanf("%d%d",&x,&y);
		ans=v[x]+v[y];
		cnt=0;
		dfs(x,y);
		printf("%d\n",ans);
	}
	return 0;
}
