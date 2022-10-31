#include<bits/stdc++.h>
using namespace std;
int q,n,m;
int in[1000001],in1[1000001],out[1000001];
bool graph[5001][5001];
bool check() {
	for(int i=1; i<=n; i++) {
		if(out[i]!=1) {
			return 0;
		}
	}
	return 1;
}
void destroy(int u) {
	for(int i=1;i<=n;i++){
		if(graph[i][u]){
			out[i]--;
		}
	}
}
void fix(int u) {
	for(int i=1;i<=n;i++){
		if(!graph[i][u]){
			out[i]++;
		}
	}
}
int read() {
	int w=0,f=1;
	char c=getchar();
	while(!isalnum(c)) {
		if(c=='-') {
			f=-1;
		}
		c=getchar();
	}
	while(isalnum(c)) {
		w*=10;
		w+=c-'0';
		c=getchar();
	}
	return w*f;
}
int main() {
	freopen("galaxy.in","r",stdin);
	freopen("galaxy.out","w",stdout);
	n=read();
	m=read();
	for(int i=1; i<=m; i++) {
		int u,v;
		u=read();
		v=read();
		graph[u][v]=1;
		in[v]++;
		out[u]++;
	}
	for(int i=1; i<=n; i++) {
		in1[i]=in[i];
	}
	q=read();
	while(q--) {
		int type;
		type=read();
		if(type==1) {
			int u,v;
			u=read();
			v=read();
			graph[u][v]=0;
			out[u]--;
			in[v]--;
		} else if(type==2) {
			int u;
			u=read();
			if(in[u]==0) {
				continue;
			} else {
				in[u]=0;
				destroy(u);
			}
		} else if(type==3) {
			int u,v;
			u=read();
			v=read();
			graph[u][v]=1;
			out[u]++;
			in[v]++;
		} else {
			int u;
			u=read();
			if(in[u]==in1[u]) {
				continue;
			} else {
				in[u]=in1[u];
				fix(u);
			}
		}
//		for(int i=1; i<=n; i++) {
//			cout<<"Point"<<i<<endl;
//			cout<<in[i]<<" "<<out[i]<<endl;
//		}
//		cout<<endl;
		if(check()){
			puts("YES");
		}else{
			puts("NO");
		}
	}
	return 0;
}
