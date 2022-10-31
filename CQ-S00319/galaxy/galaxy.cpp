#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
const int N=5e5+10;
inline int read(){
	int x=0;
	bool flag=false;
	char ch=getchar();
	while(ch>'9'||ch<'0'){
		if(ch=='-')flag=true;
		ch=getchar();
	}
	while(ch<='9'&&ch>='0'){
		x=(x<<1)+(x<<3)+(ch^48);
		ch=getchar();
	}
	if(flag)return -x;
	return x;
}
struct path{
	int y;
	bool liv;
	bool operator<(const path &t)const{
		return y<t.y;
	}
};
vector<path>u[N];
int n,m,q;
int cnt[N],Sz[N];
int main(){
	freopen("galaxy.in","r",stdin);
	freopen("galaxy.out","w",stdout);
	n=read(),m=read();
	int opt,x,y;
	while(m--){
		x=read(),y=read();
		u[x].push_back((path){y,1});
	}
	int tot=0;
	for(int i=1;i<=n;i++){
		cnt[i]=Sz[i]=u[i].size();
		sort(u[i].begin(),u[i].end());
		tot+=Sz[i];
	}
	q=read();
	while(q--){
		opt=read(),x=read();
		if(opt==1){
			y=read();
			cnt[x]--,tot--;
			int l=0,r=Sz[x]-1,mid;
			while(l<=r){
				mid=l+r>>1;
				if(u[x][mid].y<=y)l=mid+1;
				else r=mid-1;
			}
			u[x][r].liv=0;
		}
		else if(opt==2){
			tot-=cnt[x],cnt[x]=0;
			for(int i=0;i<Sz[i];i++)
				u[x][i].liv=0;
		}
		else if(opt==3){
			y=read();
			cnt[x]++,tot++;
			int l=0,r=Sz[x]-1,mid;
			while(l<=r){
				mid=l+r>>1;
				if(u[x][mid].y<=y)l=mid+1;
				else r=mid-1;
			}
			u[x][r].liv=1;
		}
		else{
			tot+=Sz[x]-cnt[x],cnt[x]=Sz[x];
			for(int i=0;i<Sz[i];i++)
				u[x][i].liv=1;		
		}
		if(tot==n){
			for(int i=1;i<=n;i++){
				if(!cnt[i]){
					puts("NO");
					break;
				}
				if(i==n)
					puts("YES");
			}
		}
		else
			puts("NO");
	}
	return 0;
} 
