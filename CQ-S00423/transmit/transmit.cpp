#include<stdio.h>
#include<vector>
#include<queue>
inline int read(){
	int x=0;
	char s=getchar();
	while(s<'0'||s>'9')s=getchar();
	while(s>='0'&&s<='9'){
		x=(x<<3)+(x<<1)+(s^48);
		s=getchar();
	}
	return x;
}
inline void write(const long long&x){
	if(x>9)write(x/10);
	putchar(x%10^48);
}
std::vector<int>v[200005],v1[200005];
int n,m,k;
struct Node{
	int to,cnt;
};
void edge(const int&s){
	std::queue<Node>q;
	q.push((Node){s,0});
	while(!q.empty()){
		Node t1=q.front();q.pop();
		v1[s].push_back(t1.to);
		if(t1.cnt==k)continue;
		for(const int&i:v[t1.to]){
			q.push((Node){i,t1.cnt+1});
		}
	}
}
struct node{
	int to;
	long long val;
	inline bool operator<(const node&x)const{
		return val>x.val;
	}
};
const long long inf=0x3f3f3f3f3f3f3f3f;
int dfn[200005];
long long dis[200005];
bool vis[200005];
int a[200005];
int idx;
long long bfs(const int&st,const int&ed){
	std::priority_queue<node>q;
	q.push((node){st,a[st]});
	dis[st]=a[st];
	vis[st]=false;
	while(!q.empty()){
		node t1=q.top();q.pop();
		if(t1.to==ed)return dis[t1.to];
		if(dfn[t1.to]==idx&&vis[t1.to])continue;
		dfn[t1.to]=idx;vis[t1.to]=true;
		for(const int&i:v1[t1.to]){
			if(dfn[i]!=idx)dfn[i]=idx,dis[i]=inf,vis[i]=false;
			if(dis[i]>dis[t1.to]+a[i]){
				dis[i]=dis[t1.to]+a[i];
				q.push((node){i,dis[i]});
			}
		}
	}
	return -114514;
}
int main(){
	freopen("transmit.in","r",stdin);
	freopen("transmit.out","w",stdout);
	n=read();m=read();k=read();
	for(int i=1;i<=n;a[i++]=read());
	for(int i=1,x,y;i<n;++i){
		x=read();y=read();
		v[x].push_back(y);
		v[y].push_back(x);
	}
	for(int i=1;i<=n;++i)edge(i);
	for(int i=1,x,y;i<=m;++i){
		x=read();y=read();
		++idx;
		write(bfs(x,y));
		putchar(10);
	}
	return 0;
}
/*
7 3 3
1 2 3 4 5 6 7
1 2
1 3
2 4
2 5
3 6
3 7
4 7
5 6
1 2
*/
