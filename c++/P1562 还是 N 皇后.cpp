#include<bits/stdc++.h>
using namespace std;
int n;
int ans[15];
bool vis[50];
bool jvis[50];
bool hvis[50];
bool pvis[50][50];
int sum;
void dfs(int idx){
	if(idx==n+1){
		sum++;
		return;
	}
	for(int i=1;i<=n;i++){
		if(!vis[i]&&!jvis[idx+i]&&!hvis[idx-i+n]&&!pvis[idx][i]){
			ans[idx]=i;
			vis[i]=1;
			jvis[idx+i]=1;
			hvis[idx-i+n]=1;
			dfs(idx+1);
			vis[i]=0;
			jvis[idx+i]=0;
			hvis[idx-i+n]=0;
		}
	}
}
int main(){
	sum=0;
	cin>>n;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			char a;
			scanf(" %c",&a);
			if(a=='*'){
				pvis[i][j]=0;
			}else{
				pvis[i][j]=1;
			}
		}	
	}
	dfs(1);
	cout<<sum;
	return 0;
}

