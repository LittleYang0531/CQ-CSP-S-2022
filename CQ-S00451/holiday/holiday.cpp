#include<bits/stdc++.h>
using namespace std;
int point[305];
bool fl[305][305][105];
int read(){
	int x=0;
	char ch=getchar();
	while(ch<'0'||ch>'9')ch=getchar();
	while(ch>='0'&&ch<='9'){
		x=(x<<3)+(x<<1)+(ch^48);
		ch=getchar();
	}
	return x;
}
int main() {
	freopen("holiday.in","r",stdin);
	freopen("holiday.out","w",stdout);
	int n,m,k;
	n=read(),m=read(),k=read();
	for(int i=2; i<=n; i++)point[i]=read();
	for(int i=1;i<=n;i++)fl[i][i][0]=true;
	for(int i=1; i<=m; i++) {
		int x,y;
		x=read(),y=read();
		fl[x][y][0]=fl[y][x][0]=true;
	}
	for(int tmp=1; tmp<=k; tmp++) {
		for(int l=1; l<=n; l++) {
			for(int i=1; i<=n; i++) {
				for(int j=1; j<=n; j++) {
					fl[i][j][tmp]|=(fl[i][l][tmp-1]&&fl[l][j][0]);
				}
			}
		}
	}
	int ans=-1;
	for(int i=2; i<=n; i++) {
		if(!fl[1][i][k])continue;
		for(int j=i+1; j<=n; j++) {
			if(!fl[i][j][k])continue;
			for(int l=j+1;l<=n;l++){
				if(!fl[j][l][k])continue;
				for(int x=l+1;x<=n;x++){
					if(fl[l][x][k]&&fl[x][1][k]){
						ans=max(ans,point[i]+point[j]+point[l]+point[x]);
					}
				}
			}
		}
	}
	cout<<ans;
	return 0;
}


