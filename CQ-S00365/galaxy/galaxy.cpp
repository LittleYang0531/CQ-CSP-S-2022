#include<bits/stdc++.h>
using namespace std;

int read(){
	int x=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9'){ if(c=='-') f=-1;c=getchar(); }
	while('0'<=c&&c<='9') x=(x<<1)+(x<<3)+c-'0',c=getchar();
	return x*f;
}

void File(){
	freopen("galaxy.in","r",stdin);
	freopen("galaxy.out","w",stdout);
}

int n,m;
int tot=0;
set<int> v[500005];
vector<int> q[500005];
int chu[500005],ru[500005];

int main(){
	File();cin>>n>>m;
	for(int i=1,x,y;i<=m;i++) x=read(),y=read(),chu[x]++,ru[y]++,v[y].insert(x),q[y].push_back(x);
	for(int i=1;i<=n;i++) tot+=chu[i]==1;
	int T;cin>>T;
	int op=0,x,y;
	int qwqqwq=0;
	F__k:;if(!(T--)) goto ZXL;{
		op=read();
		if(op==1){
			x=read(),y=read();
			if(chu[x]==1) tot--;
			v[y].erase(x);
			chu[x]--,ru[y]--;
			if(chu[x]==1) tot++;
		}
		if(op==2){
			x=read();
			for(auto y:v[x]){
				if(chu[y]==1) tot--;
				chu[y]--;
				if(chu[y]==1) tot++;
			}
			v[x].clear();
		}
		if(op==3){
			x=read(),y=read();
			if(chu[x]==1) tot--;
			v[y].insert(x);
			chu[x]++,ru[y]++;
			if(chu[x]==1) tot++;
		}
		if(op==4){
			x=read();
			for(auto y:q[x]) if(v[x].find(y)==v[x].end()){
				if(chu[y]==1) tot--;
				chu[y]++,ru[x]++;v[x].insert(y);
				if(chu[y]==1) tot++;
			}
		}
		printf("%s\n",tot==n?"YES":"NO");
	}goto F__k;ZXL:;
	
	return 0;
}
/*
3 6
2 3
2 1
1 2
1 3
3 1
3 2
3
1 3 2
1 2 3
1 1 3

*/
