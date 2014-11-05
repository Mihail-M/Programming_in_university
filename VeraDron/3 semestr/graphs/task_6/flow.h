#pragma once
#include <queue>

using namespace std;
namespace Flow {

void init(int s);
bool bfs(int s, int t);
int max_flow(int s, int t, int _n, int **c_);

}
