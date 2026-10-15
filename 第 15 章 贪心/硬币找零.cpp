#include<iostream>
#include<vector>
using namespace std;
//贪心算法的正确思路是尽可能的在当前位置一次性拿完，一次循环而不是嵌套循环
void coinChangeGreedy(vector<int> &coins, int val) { 
	int i = coins.size()-1;
	vector<int> tmp;
	while(i>=0){ 
		while(coins[i]<=val){
			val -= coins[i];
			tmp.push_back(coins[i]);
		}
		i--;
	}
	if(val==0)
		for(int j=tmp.size()-1;j>=0;j--)
			cout<<tmp[j]<<" ";
	else
		cout<<"没法凑";
}

int main(){
	vector<int> coins = {1,2,3,4,5,6,9,10};
	coinChangeGreedy(coins,16);
}