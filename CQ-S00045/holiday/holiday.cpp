#include<bits/stdc++.h>
using namespace std;

int n,m,k,o[3000],maxx=INT_MIN,s[2505][2505];
void id5(int x1,int x2,int x3,int x4){
	if(s[x4][1]==1){
		maxx=max(maxx,o[x1]+o[x2]+o[x3]+o[x4]);
	}else return;
}
void id4(int x1,int x2,int x3){
	for(int i=2;i<=n;i++){
		if(x3!=i){
			if(s[x3][i]==1){
				id5(x1,x2,x3,i);
			}
		}
	}
	return ;
}
void id3(int x1,int x2){
	for(int i=2;i<=n;i++){
		if(x2!=i){
			if(s[x2][i]==1){
				id4(x1,x2,i);
			}
		}
	}
	return ;
}
void id2(int x){
	for(int i=2;i<=n;i++){
		if(x!=i){
			if(s[x][i]==1){
				id3(x,i);
			}
		}
	}
	return ;
}
void id1(int x){
	if(s[1][x]==1){
		id2(x);
	}
	return ;
}

int main(){
	freopen("holiday.in","r",stdin);
	freopen("holiday.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for(int i=2;i<=n;i++){
		scanf("%d",&o[i]);
	}
	for(int i=1;i<=m;i++){
		int x,y;
		scanf("%d%d",&x,&y);
		s[x][y]++;
		s[y][x]++;
	}
	for(int i=2;i<=n;i++){
		id1(i);
	}
	printf("%d",maxx);
	return 0;
}
