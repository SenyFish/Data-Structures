#include<iostream>
#include<vector>
#include <algorithm>
using namespace std;
//因为背包里的物品可以拆分，所以可以一部分一部分的拿
struct Items{
	int weight;
	int val;
	float unit_val;
	Items(int i,int j):weight(i),val(j),unit_val(1.0*val/weight){}
};
void fractionalKnapsack(vector<Items> &i1,int cap){
	sort(i1.begin(),i1.end(),[](Items& a, Items& b) {return a.unit_val > b.unit_val;}); //lambda表达式，意思是从大到小排序
	float max_val=0;
	int i=0;
	while(i<i1.size()&&i1[i].weight<=cap){//思考为什么不加上cap>0这个判断条件、i<i1.size()为什么在i1[i].weight<=cap前面而不是后面？
		cap -= i1[i].weight;
		max_val += i1[i].val;
		i++;
	}
	if(i<i1.size()&&cap>0) //思考为什么要加上i<i1.size()判断条件
		max_val += i1[i].unit_val * cap;
	cout<<max_val;
}
int main(){
	vector<Items> i1={
		Items{20,120},
		Items{40,210},
		Items{10,50},
		Items{30,150},
		Items{50,240}
	};
	int cap=50;
	fractionalKnapsack(i1,cap);
}