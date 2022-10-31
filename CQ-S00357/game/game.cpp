#include<stdio.h>
#define LL long long
const int N=1e5+5;
int n,m,a[N],b[N],fa,fb,ma,mi;
LL my_max(LL x,LL y){
	return x>y?x:y;
}
LL my_min(LL x,LL y){
	return x<y?x:y;
}
void write(LL x){
	if(x<0){x=~x+1;putchar('-');}
	if(x>9)	write(x/10);
	putchar(x%10+'0');
}
int main(){
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	int w;scanf("%d%d%d",&n,&m,&w);
	for(int i=1;i<=n;i++){scanf("%d",&a[i]);fa=a[i]<0?1:fa;ma=my_max(ma,a[i]);}
	for(int i=1;i<=m;i++){scanf("%d",&b[i]);fb=b[i]<0?1:fb;mi=my_min(mi,b[i]);}
	while(w--)
	{
		int l1,r1,l2,r2,f=1;scanf("%d%d%d%d",&l1,&r1,&l2,&r2);
		for(int i=l1;i<=r1;i++){if(fb&&!a[i]){putchar('0');f=0;}break;}
		if(f)
		{
			LL ans=-1e18;
			for(int i=l1;i<=r1;i++)
			{
				LL t=1e18;
				for(int j=l2;j<=r2;j++)	t=my_min(t,a[i]*b[j]);
				ans=my_max(ans,t);
			}
			printf("%lld",ans);
		}
		putchar('\n');
	}
	return 0;
}
