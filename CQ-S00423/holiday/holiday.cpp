#include<stdio.h>
#include<vector>
#include<queue>
std::vector<int>v[2505];
bool v1[2505][2505];
int n,m,k;
struct Node{
	int to,cnt;
};
void edge(const int&s){
	std::queue<Node>q;
	q.push((Node){s,-1});
	while(!q.empty()){
		Node t1=q.front();q.pop();
		if(v1[s][t1.to])continue;
		v1[s][t1.to]=true;
		if(t1.cnt==k)continue;
		for(const int&i:v[t1.to]){
			q.push((Node){i,t1.cnt+1});
		}
	}
}
struct node{
	int vis[4];
	int to,cnt,val;
	inline bool operator<(const node&x)const{
		if(cnt!=x.cnt)return cnt>x.cnt;
		return val<x.val;
	}
};
int a[2505];
int bfs(){
	std::priority_queue<node>q;
	q.push((node){{0,0,0,0},1,0,0});
	int tong[5]={};
	while(!q.empty()){
		node t1=q.top();q.pop();
		tong[t1.cnt]++;
		if(t1.cnt==4){
			if(v1[t1.to][1])return t1.val;
			continue;
		}
		if(tong[t1.cnt]>300)continue;
		for(int i=1;i<=n;++i){
			if(!v1[t1.to][i])continue;
			if(i==1||i==t1.vis[0]||i==t1.vis[1]||i==t1.vis[2])continue;
			node t2=t1;
			t2.vis[t2.cnt++]=i;
			t2.to=i;
			t2.val+=a[i];
			q.push(t2);
		}
	}
	return -114514;
}
int main(){
	freopen("holiday.in","r",stdin);
	freopen("holiday.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for(int i=2;i<=n;scanf("%d",&a[i++]));
	for(int x,y;m--;){
		scanf("%d%d",&x,&y);
		v[x].push_back(y);
		v[y].push_back(x);
	}
	for(int i=1;i<=n;++i)edge(i);
	printf("%d",bfs());
	return 0;
}
/*
8 8 1
9 7 1 8 2 3 6
1 2
2 3
3 4
4 5
5 6
6 7
7 8
8 1

7 9 0
1 1 1 2 3 4
1 2
2 3
3 4
1 5
1 6
1 7
5 4
6 4
7 4
*/
