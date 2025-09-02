// 先实现一个无向图，若两个商品出现在同一个小票上，在两个商品间做一条无向边
// 边采用邻接矩阵实现，aij表示两个节点间的边数
// 最终看哪两个节点之间的无向边最多
#include <algorithm>
#include <iostream>
#include <set>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

int main(void) {
    unordered_map<string, int> edges;
    while (true) {
        set<char> iv_set;
        string invoice;
        cin >> invoice;
        if (invoice == "00000") {
            break;
        }
        for (int i = 0; i < invoice.length(); i++) {
            iv_set.insert(invoice[i]);
        }
        for (set<char>::iterator it = iv_set.begin(); it != iv_set.end(); it++) {
            for (set<char>::iterator jt = iv_set.begin(); jt != iv_set.end(); jt++) {
                if (it != jt) {
                    string edge_name = "";
                    if (*it > *jt) edge_name = edge_name + (*jt) + (*it);
                    if (*it < *jt) edge_name = edge_name + (*it) + (*jt);
                    if (edge_name != "") {
                        edges[edge_name]++;
                    }
                }
            }
        }
    }
    int max_key = edges.begin()->second;
    for (unordered_map<string, int>::iterator it = edges.begin(); it != edges.end(); it++) {
        if (it->second > max_key) {
            max_key = it->second;
        }
    }
    for (unordered_map<string, int>::iterator it = edges.begin(); it != edges.end(); it++) {
        if (it->second == max_key) {
            cout << it->first;
        }
    }
}
