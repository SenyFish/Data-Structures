#include<iostream>
#include<vector>
using namespace std;
void maxCapacity(vector<int> &ht){
	int left=0,right=ht.size()-1;
	int ht_size=0,max=0;
//维护一个最大值，如果max<ht_size就将ht_size赋值给history
	while(left<right){ //思考为什么不能写成left!=right
	if(ht[left]>ht[right])
		ht_size = ht[right]*(right-left);
	else //思考为什么不能写成else if(ht[left]<ht[right])
		ht_size = ht[left]*(right-left);
	if(max<ht_size)
		max = ht_size;	
	if(ht[left]>ht[right])
		right--;
	else //思考为什么不能写成else if(ht[left]<ht[right])
		left++;
	}
	cout<<max;
}
int main(){
	vector<int> ht={3,8,5,2,7,7,3,4};
	maxCapacity(ht);
}