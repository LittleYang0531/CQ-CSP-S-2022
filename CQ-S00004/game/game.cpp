#include<cmath>
#include<cstdio>
#include<algorithm>
using namespace std;
int n,m,k,x1,y1,x2,y2;
int a[100005],b[100005];
long long int RMQ[100005][20][8];
long long int Do(int i,int j,int num){
	int k=log2(j-i+1);
	if(num&1){
		return RMQ[i][k][num]>RMQ[j-(1<<k)+1][k][num]?RMQ[j-(1<<k)+1][k][num]:RMQ[i][k][num];
	}else{
		return RMQ[i][k][num]<RMQ[j-(1<<k)+1][k][num]?RMQ[j-(1<<k)+1][k][num]:RMQ[i][k][num];
	}
}
int read(){
	int a=1,b=0;
	char ch=getchar();
	while(ch<'0'||ch>'9'){
		a=ch=='-'?-1:1,ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		b=(b<<1)+(b<<3)+ch-'0',ch=getchar();
	}
	return a*b;
}
void write(long long int num){
	if(num<0){
		putchar('-');
		num=(~num)+1;
	}
	if(num>=10){
		write(num/10);
	}
	putchar(num%10+'0');
}
int main(){
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	n=read(),m=read(),k=read();
//	printf("OK1");
	for(int i=1;i<=n;i++){
		a[i]=read();
//		printf("|%d|",a[i][0]);
		if(a[i]<0){
			RMQ[i][0][0]=-1,RMQ[i][0][1]=2147483647;
		}else{
			RMQ[i][0][0]=RMQ[i][0][1]=a[i];
		}
		if(a[i]>0){
			RMQ[i][0][2]=-2147483647;
			RMQ[i][0][3]=1;
		}else{
			RMQ[i][0][2]=RMQ[i][0][3]=a[i];
		}
	}
//	printf("OK2");
	for(int j=1;(1<<j)<=n;j++){
		for(int i=1;i+(1<<j)-1<=n;i++){
			RMQ[i][j][0]=RMQ[i][j-1][0]>RMQ[i+(1<<j-1)][j-1][0]?RMQ[i][j-1][0]:RMQ[i+(1<<j-1)][j-1][0];
			RMQ[i][j][1]=RMQ[i][j-1][1]<RMQ[i+(1<<j-1)][j-1][1]?RMQ[i][j-1][1]:RMQ[i+(1<<j-1)][j-1][1];
			RMQ[i][j][2]=RMQ[i][j-1][2]>RMQ[i+(1<<j-1)][j-1][2]?RMQ[i][j-1][2]:RMQ[i+(1<<j-1)][j-1][2];
			RMQ[i][j][3]=RMQ[i][j-1][3]<RMQ[i+(1<<j-1)][j-1][3]?RMQ[i][j-1][3]:RMQ[i+(1<<j-1)][j-1][3];	
		}
	}
	for(int i=1;i<=m;i++){
		b[i]=read();
		if(b[i]<0){
			RMQ[i][0][4]=-1,RMQ[i][0][5]=2147483647;
		}else{
			RMQ[i][0][4]=RMQ[i][0][5]=b[i];
		}
		if(b[i]>0){
			RMQ[i][0][6]=-2147483647,RMQ[i][0][7]=1;
		}else{
			RMQ[i][0][6]=RMQ[i][0][7]=b[i];
		}
	}
	for(int j=1;(1<<j)<=m;j++){
		for(int i=1;i+(1<<j)-1<=m;i++){
			RMQ[i][j][4]=RMQ[i][j-1][4]>RMQ[i+(1<<j-1)][j-1][4]?RMQ[i][j-1][4]:RMQ[i+(1<<j-1)][j-1][4];
			RMQ[i][j][5]=RMQ[i][j-1][5]<RMQ[i+(1<<j-1)][j-1][5]?RMQ[i][j-1][5]:RMQ[i+(1<<j-1)][j-1][5];
			RMQ[i][j][6]=RMQ[i][j-1][6]>RMQ[i+(1<<j-1)][j-1][6]?RMQ[i][j-1][6]:RMQ[i+(1<<j-1)][j-1][6];
			RMQ[i][j][7]=RMQ[i][j-1][7]<RMQ[i+(1<<j-1)][j-1][7]?RMQ[i][j-1][7]:RMQ[i+(1<<j-1)][j-1][7];	
		}
	}
	for(int i=1;i<=k;i++){
		x1=read(),y1=read(),x2=read(),y2=read();
//		printf("[%d]\n",Do(x2,y2,7));
		if(Do(x2,y2,7)>=0){//对面没有负数
//			printf("[[%d]]\n",sum1);
			if(Do(x1,y1,0)<=0){//我没有正数 
				write(Do(x2,y2,4)*Do(x1,y1,2));
			}else{
				write(Do(x2,y2,5)*Do(x1,y1,0));
			}
		}else{
//			printf("[[%d]]\n",Do(x2,y2,4));
			if(Do(x2,y2,4)<=0){//对面没有正数 
//				printf("[[[%d %d %d]]]\n",Do(x1,y1,3),Do(x2,y2,6),Do(x1,y1,1));
				if(Do(x1,y1,3)>=0){//我没有负数 
					write(Do(x2,y2,7)*Do(x1,y1,1));
				}else{
					write(Do(x2,y2,6)*Do(x1,y1,3));
				}
			}else{//对面有正有负 
//				printf("[[[%d]]]\n",Do(x1,y1,0));
				if(Do(x1,y1,0)<=0){//我们没有正数 
					write(Do(x1,y1,2)*Do(x2,y2,4));
				}else{
//					printf("[[[[%d]]]]\n",Do(x1,y1,3));
					if(Do(x1,y1,3)>=0){//我们没有负数 
						write(Do(x1,y1,1)*Do(x2,y2,7));
					}else{
//						printf("[[[[[%d %d %d %d]]]]]\n",Do(x1,y1,2),Do(x2,y2,4),Do(x1,y1,1),Do(x2,y2,7));
						write(max(Do(x1,y1,2)*Do(x2,y2,4),Do(x1,y1,1)*Do(x2,y2,7)));
					}
				}
			}
		}
		printf("\n");
	}
	return 0;
}
/*
3 3 1
1 2 3
-1 -2 -3
1 3 1 3
*/
