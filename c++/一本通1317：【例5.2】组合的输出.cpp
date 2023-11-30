#include<bits/stdc++.h>
using namespace std;
int n,r;
int ans[21];

void dfs(int idx){
	if(idx==r+1){
		for(int i=1;i<=r;i++){
			printf("%3d", ans[i]);
		}
		put("");
		return;
	}
	for(int i=ans[idx-1]+1;i<=n;i++){
			ans[idx]=i;
			dfs(idx+1);
	}
}

int main(){
	cin>>n>>r;
	dfs(1);
	return 0;
}

