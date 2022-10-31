#include <bits/stdc++.h>
using namespace std;
int n,m,q,a[100005],b[100005],l1,r1,l2,r2,sta[100005][15],stb[100005][15],lg2[100005],pw2[15];
void STa(){
	for(int i=1;i<=n;i++) sta[i][0]=a[i];
	for(int i=1;i<=lg2[n];i++){
		int len=pw2[i];
		for(int j=1;j<=n-len+1;j++){
			sta[j][i]=max(sta[j][i-1],sta[j+len/2][i-1]);
		}
	}
}
void STb(){
	memset(stb,0x3f,sizeof stb);
	for(int i=1;i<=m;i++) stb[i][0]=b[i];
	for(int i=1;i<=lg2[m];i++){
		int len=pw2[i];
		for(int j=1;j<=m-len+1;j++){
			stb[j][i]=min(stb[j][i-1],stb[j+len/2][i-1]);
		//	printf("j=%d i=%d stb=%lld\n",j,i,stb[j][i]);
		}
	}
}
int get_max_a(int lp,int rp){
	int len=rp-lp+1;
	int tmp=lg2[len];
	int factlen=pw2[tmp];
	return max(sta[lp][tmp],sta[rp-factlen+1][tmp]);
}
int get_min_b(int lp,int rp){
	int len=rp-lp+1;
	int tmp=lg2[len];
	int factlen=pw2[tmp];
//	cout<<len<<" "<<tmp<<" "<<factlen<<" "<<lp<<" "<<tmp<<" "<<stb[lp][tmp]<<" "<<rp-factlen+1<<" "<<tmp<<" "<<stb[rp-factlen+1][tmp]<<endl;
	return min(stb[lp][tmp],stb[rp-factlen+1][tmp]);
}
int main(){
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	scanf("%d%d%d",&n,&m,&q);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	for(int i=1;i<=m;i++) scanf("%d",&b[i]);
	pw2[0]=1;
	for(int i=1;i<=max(n,m);i++) lg2[i]=log2(i);
	for(int i=1;i<=lg2[max(n,m)];i++) pw2[i]=pw2[i-1]*2;
	STa();
	STb();
	for(int i=1;i<=q;i++){
		scanf("%d%d%d%d",&l1,&r1,&l2,&r2);
		printf("%lld\n",1ll*get_max_a(l1,l2)*1ll*get_min_b(r1,r2));
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
