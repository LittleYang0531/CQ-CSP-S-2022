#include <bits/stdc++.h>

using namespace std;

const int MAX_N = 2500 + 5;

const int MAX_M = 10000 + 5;

int n,m,k,a[MAX_N],b[MAX_N][MAX_N];

int Last[MAX_N],End[MAX_M<<1],Next[MAX_M<<1],tote;

inline void addedge(int x,int y){End[++tote]=y,Next[tote]=Last[x],Last[x]=tote;}

struct node{
	int num,dis;
	inline bool operator < (const node &a) const {
		return dis>a.dis;
	}
};

bool vis[MAX_N];

int dis[MAX_N];

priority_queue<node> q;

void dijkstra(int S){
	for(int i=1;i<=n;++i) dis[i]=1e9,vis[i]=0;
	dis[S]=0;
	q.push((node){S,0});
	while(q.size()){
		int x=q.top().num;q.pop();
		if(vis[x]) continue;
		vis[x]=1;
		for(int i=Last[x];i;i=Next[i]){
			int y=End[i];
			if(dis[y]>dis[x]+1){
				dis[y]=dis[x]+1;
				if(!vis[y]) q.push((node){y,dis[y]});
			}
		}
	}
}

vector<int> v[MAX_N];

int num[100 + 5],len=1,s[100 + 5];

inline void add(int x){
	int tot=0;
	while(x){
		s[++tot]=x%10;
		x/=10;
	}
//	for(int i=tot;i>=1;--i) printf("%d",s[i]);
//	printf("\n");
	for(int i=1;i<=tot;++i) num[i]+=s[i];
//	for(int i=1;i<=tot;++i) while(num[i]>=10) num[i]-=10,num[i+1]++;
//	while(num[len+1]>0) len++;
}

int anslen,ans[100 + 5];

inline void getmax(){
//	cout<<len<<" "<<anslen<<endl;
	for(int i=max(len,anslen);i>=1;--i){
//		printf("%d %d\n",num[i],ans[i]);
		if(num[i]>ans[i]){
			for(int j=1;j<=len;++j) ans[j]=num[j];
			anslen=len;
			return;
		}
		else if(num[i]<ans[i]){
			return;
		}
	}
}

inline void print(){
	for(int i=anslen;i>=1;--i) printf("%d",ans[i]);
	printf("\n");
}

int main(){
	freopen("holiday.in","r",stdin);
	freopen("holiday.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	k++;
	for(int i=2;i<=n;++i) scanf("%d",&a[i]);
	for(int i=1;i<=m;++i){
		int x,y;
		scanf("%d%d",&x,&y);
		addedge(x,y);
		addedge(y,x);
	}
	for(int i=1;i<=n;++i){
		dijkstra(i);
		for(int j=1;j<=n;++j){
			if(i!=j && dis[j]<=k && j!=1){
				v[i].push_back(j);
//				printf("%d -> %d\n",i,j);
				b[i][j]=b[j][i]=1;
			}
		}
	}
	for(int i=1;i<=n;++i){
		sort(v[i].begin(),v[i].end(),[](int x,int y){
			return a[x]>a[y];
		});
	}
	memset(vis,0,sizeof(vis));
//	long long ans=0;//Òª¸ß¾« 
	for(auto A:v[1]){
		if(vis[A]) continue;
		for(auto B:v[A]){
			if(A==B) continue;
			for(auto C:v[B]){
				if(A==C|| B==C) continue;
				for(auto D:v[C]){
					if(A==D|| B==D || C==D) continue;
					if(b[D][1]){
//						cout<<A<<" "<<B<<" "<<C<<" "<<D<<endl;
//						ans=max(ans,(long long)a[A]+a[B]+a[C]+a[D]);
						add(a[A]);
						add(a[B]);
						add(a[C]);
						add(a[D]);
						while(num[len+1]) len++;
						for(int i=1;i<=len;++i){
							if(num[i]>=10){
								num[i+1]+=num[i]/10;
								num[i]%=10;
							}
						}
						while(num[len+1]) len++;
						getmax();
//						print();
//						if(len>=5){//5708 8378 6220 9666
//							printf("%d %d %d %d\n",a[A],a[B],a[C],a[D]);
//							for(int i=len;i>=1;--i) printf("%d",num[i]);
//							printf("\n");
//						}
//						
//						printf("\n");
						for(int i=1;i<=len;++i) num[i]=0;
						len=1;
//						memset(num,0,sizeof(num));
//						len=1;
//						print();
//						printf("%lld\n",ans);
						vis[D]=1;
						break;
//						return 0;
					}
				}
			}
		}
	}
//	printf("%lld\n",ans);
print();
	return 0;
}
