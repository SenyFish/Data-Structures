// ------ 图的邻接矩阵存储表示 ------
#include <iostream>
#include <cstring>
using namespace std;

#define MaxInt 32767
#define MVNum 100

typedef char VertexType;              // 顶点的数据类型
typedef int ArcType;                  // 边权值的数据类型

// 定义返回状态类型
typedef int Status;
const int OK = 1;
const int ERROR = 0;

// 图的邻接矩阵存储结构
typedef struct {
    VertexType vexs[MVNum];           // 顶点表
    ArcType arcs[MVNum][MVNum];       // 邻接矩阵
    int vexnum, arcnum;               // 当前顶点数和边数
} AMGraph;

// 查找顶点位置的函数，返回顶点在顶点表中的索引（假设顶点存在）
int LocateVex(AMGraph &G, VertexType v) {
    for (int i = 0; i < G.vexnum; ++i) {
        if (G.vexs[i] == v)           // 找到顶点
            return i;
    }
    return -1;                        // 未找到返回-1
}

// ----- 采用邻接矩阵表示法，创建无向网G -----
Status CreateUDN(AMGraph &G) {
	cout<<"输入总顶点数、总边数";
    cin >> G.vexnum >> G.arcnum;      // 输入总顶点数、总边数
    for (int i = 0; i < G.vexnum; ++i)
		 
        cin >> G.vexs[i];             // 依次输入点的信息

    for (int i = 0; i < G.vexnum; ++i)
        for (int j = 0; j < G.vexnum; ++j)
            G.arcs[i][j] = MaxInt;    // 初始化邻接矩阵，边的权值均置为极大值MaxInt

    VertexType v1, v2;                // 边的两个顶点
    int w;                            // 边的权值
    for (int k = 0; k < G.arcnum; ++k) {
        cin >> v1 >> v2 >> w;         // 输入一条边依附的顶点及权值
        int i = LocateVex(G, v1);     // 确定v1在顶点数组中的下标
        int j = LocateVex(G, v2);     // 确定v2在顶点数组中的下标
        if (i == -1 || j == -1) {
            cerr << "输入的顶点不存在！" << endl;
            return ERROR;
        }
        G.arcs[i][j] = w;             // 边<v1, v2>的权值置为w
        G.arcs[j][i] = w;             // 对称边<v2, v1>的权值置为w
    }
    return OK;
}

// 主函数，用于测试
int main() {
    AMGraph G;
    if (CreateUDN(G) == OK) {
        cout << "图创建成功！" << endl;
        cout << "邻接矩阵：" << endl;
        for (int i = 0; i < G.vexnum; ++i) {
            for (int j = 0; j < G.vexnum; ++j) {
                if (G.arcs[i][j] == MaxInt)
                    cout << "∞ ";
                else
                    cout << G.arcs[i][j] << " ";
            }
            cout << endl;
        }
    } else {
        cout << "图创建失败！" << endl;
    }
    return 0;
}

