#include<bits/stdc++.h>
using namespace std;
int n,all,sta[20],ans;

void dfs(int now,int ld,int rd,int d){
	if(now==all){
		ans++;
		return;
	}
	int pos=all&(~(now|ld|rd|sta[d]));
	int p;
	while(pos){
		p=pos&-pos;
		pos-=p;
		dfs(now+p,(ld+p)<<1,(rd+p)>>1,d+1);
	}
}

int main(){
	scanf("&d",n);
	all=(1<<n)-1;
	char c[20];
	for(int i=1;i<=n;i++){
		scanf("%c",c+1);
		getchar();
		for(int j=1;j<=n;j++){
			if(c[j]=='.')	sta[i]|=(1<<(n-j));
		}
	}
	dfs(0,0,0,1);
	
	return 0;
}

