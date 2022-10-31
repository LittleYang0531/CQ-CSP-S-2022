#include<bits/stdc++.h>
using namespace std;
int n,m,k,cnt[10000][10000],v[10000];
struct road{
	int num;
	int v;
}r[10010];
bool cmp(road a,road b){
	return a.v>b.v;
}
bool a[10000][10000];
bool f(int x,int y,int step){
	if(step>k) return 0;
	if(a[x][y]) return 1;
	for(int i = 1;i<=n;i++){
		if(a[x][i]){
			if(f(i,y,step+1)){
				return 1;
			}
		}
	}
	return 0;
}
int ans(){
	int anss = 0;
	for(int a = 2;a<=n;a++){
		for(int b = 2;b<=n;b++){
			for(int c = 2;c<=n;c++){
				for(int d = 2;d<=n;d++){
					if(a==b||a==c||a==d||b==c||b==d||c==d){
						continue;
					}
					if(f(1,a,0)&&f(a,b,0)&&f(b,c,0)&&f(c,d,0)){
						anss = max(anss,r[a].v + r[b].v + r[c].v + r[d].v); 
					}
				}
			}
		}
	}
	return anss;
}
int main(){
	freopen("holiday.in","r",stdin);
	freopen("holiday.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for(int i = 2;i<=n;i++){
		scanf("%d",&r[i].v);
		r[i].num = i;
	}
	for(int i = 1;i<=n;i++){
		int x,y;
		scanf("%d%d",&x,&y);
		a[x][y] = 1;
		a[i][i] = 1;
	}
	cout << ans();
	fclose(stdin); 
	fclose(stdout);
	return 0;
}
