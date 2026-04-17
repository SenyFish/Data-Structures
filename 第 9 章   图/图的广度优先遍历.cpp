#include <iostream>
#include <vector>
#include <queue>
using namespace std;
class GraphAdjMat{
private:
	vector<int> v1; //v1的size为图中顶点的个数，存的是顶点值
	vector<vector<int>> v2; //v2容器用来存储邻接矩阵
	queue<int> q1;
public:
	void test(){ //测试函数
	    v1 ={0,1,2,3,4,5,6,7,8};
		v2 ={
		    {0,1,0,1,0,0,0,0,0}, // 0
		    {1,0,1,0,1,0,0,0,0}, // 1
		    {0,1,0,0,0,1,0,0,0}, // 2
		    {1,0,0,0,1,0,1,0,0}, // 3
		    {0,1,0,1,0,1,0,1,0}, // 4
		    {0,0,1,0,1,0,0,0,1}, // 5
		    {0,0,0,1,0,0,0,1,0}, // 6
		    {0,0,0,0,1,0,1,0,1}, // 7
		    {0,0,0,0,0,1,0,1,0}  // 8
		};
	}
	
	void Print() const {
		for(int i=0;i<v1.size();i++){
			for(int j=0;j<v1.size();j++)
				cout<<v2[i][j]<<" ";
			cout<<endl;
			}		
	}
	
	vector<int> graphBFS(){ //广度优先遍历
		vector<int> res;
		q1.push(v1[0]);
		for(int i=0;i<v1.size();i++){
			if(i!=0){
				q1.pop();
			}
			res.push_back(q1.front());
			for(int j=0;j<v1.size();j++)
				if(v2[i][j]==1){
					q1.push(v1[j]);				
				}			
		}

		return res;
	}

};

int main(){
	GraphAdjMat G1;
	G1.test();
	G1.Print();
	vector<int> res = G1.graphBFS();
	cout<<"================"<<endl;
	for(int i=0;i<res.size();i++)
		cout<<res[i]<<" ";
}
