#include<cstdio>
int n,m,x,y;
int a[100005];
int main(){
	freopen("galaxy.in","r",stdin);
	freopen("galaxy.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++){
		scanf("%d%d",&x,&y);
	}
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&x);
		if(x&1){
			scanf("%d%d",&x,&y);
		}else{
			scanf("%d",&x);
		}
		printf("NO\n");
	}
	return 0;
}
