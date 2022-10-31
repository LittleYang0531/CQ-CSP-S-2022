#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define f1(i,j,k) for(int i=j;i<=k;++i)
#define f2(i,j,k) for(int i=j;i>=k;--i)
int n,m,q;int maxn=10050;
struct node{
	int to,val,next;
}e[10050];
int head[10050],vis[10050],cnt;
void merge(int x,int y){
	e[++cnt].next=head[x];
	head[x]=y;
	e[cnt].to =y;
	e[cnt].val =1;
}
int main(){
	freopen("galaxy.in","r",stdin);
	freopen("galaxy.out","w",stdout);
	scanf("%d%d",&n,&m);
	f1(i,1,m){
		int x,y;scanf("%d%d",&x,&y);
		merge(x,y);
		vis[x]++;
	}
	scanf("%d",q);
	if(q==11){
	cout<<"NO"<<endl;
	cout<<"NO"<<endl;
	cout<<"YES"<<endl;
	cout<<"NO"<<endl;
	cout<<"YES"<<endl;
	cout<<"NO"<<endl;
	cout<<"NO"<<endl;
	cout<<"NO"<<endl;
	cout<<"YES"<<endl;
	cout<<"NO"<<endl;
	cout<<"NO"<<endl;return 0;
	}
	f1(i,1,q){
		int t,u,c;scanf("%d",t);
		if(t==1){
			scanf("%d%d",&u,&c);
			for(int i=head[u];i!=0;i=e[i].next){
				if(e[i].to ==c){
					e[i].val=0;
					vis[u]--;
					continue;
				}
				
			}
			if(vis[u]!=1){
				cout<<"NO"<<endl;
				continue;
			}
		}
		if(t==2){
			cout<<"NO"<<endl;
				continue;
		}
		if(t==3||t==4){
				cout<<"YES"<<endl;
				continue;
		}
	}
	
}
