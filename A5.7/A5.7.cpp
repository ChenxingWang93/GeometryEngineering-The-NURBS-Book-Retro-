#include <iostream>
#include <vector>
using namespace std;
#define U_DIRECTION 0
#define V_DIRECTION 1

void DecomposeSurface(int n, int p, vector<double> U, int m, int q, vector<double> V, vector<vector<vector<double>>> Pw, int dir, int& nb, vector<vector<vector<double>>>& Qw, int mult) {
    
    if (dir == U_DIRECTION)
    {
        int a = p;
        int b = p + 1;
        nb = 0;
        for (int i = 0; i <= p; i++)
        {
            for (int row = 0; row <= m; row++)
            {
                Qw[nb][i][row] = Pw[i][row][0];
            }
        }
        while (b < m)
        {
            nb++;
            /* Code for getting mult, numerator, alfas, save, s, etc. */
            if (b < m)
            {
                for (int i = p - mult; i <= p; i++)
                {
                    for (int row = 0; row < m; row++)
                    {
                        Qw[nb][i][row] = Pw[b - p + i][row][0];
                    }
                }
                a = b;
                b = b + 1;
            }
        }
    }
    else if (dir == V_DIRECTION)
    {
        /* Similar logic as above, but with u- and v-directional parameters switched 与上述逻辑类似，但 u- & v- 方向 参数互换 */
    }
}

int main() {
    /* Example usage */
    /* Example value */
    int n = 5;
    /* Example value */
    int p = 3;
    vector<float> U = { /* Example U values */ };
    int m = 7;
    int q = 4;
    vector<float> V = { /* Example V values */ };
    /* Example 3D control points */
    vector<vector<vector<float>>> Pw(n + 1, vector<vector<float>>(m + 1, vector<float>(3)));

    /* Example value */
    int dir = U_DIRECTION;
    int nb;

    /* Resulting Bezier patches */
    vector<vector<vector<float>>> Qw;
    
    return 0;
}