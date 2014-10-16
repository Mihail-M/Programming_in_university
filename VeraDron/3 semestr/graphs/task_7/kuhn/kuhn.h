#pragma once

#include <vector>
using namespace std;

namespace graph
{

namespace Kuhn {

class MaxMatching {
public:
    ///
    /// \brief max_matching
    /// \param n
    /// \param m
    /// \param gr_ - adjacency list
    /// \return vector with max_matching
    ///
    static vector<pair<int, int> > getMaxMatching(int n, int m, vector <vector <int> > &gr_);
private:
    static bool kuhn(int v, vector <vector <int> > &gr_);
     static
     bool *used;
    static int *mt;
};


}

}
