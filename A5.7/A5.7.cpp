#include <iostream>
#include <vector>
using namespace std;

#define U_DIRECTION 0
#define V_DIRECTION 1

void DecomposeSurface(int n, int p, vector<float> U, int m, int q, vector<float> V, vector<vector<vector<float>>>& Pw, int dir, int& nb, vector<vector<vector<float>>>& Qw) {
    if (dir == U_DIRECTION)
    {
        int a = p;
        int b = p + 1;
        nb = 0;
        for (int i = 0; i <= p; i++)
        {
            for (int row = 0; row <= m; row++)
            {
                Qw[nb][i][row] = Pw[i][row];
            }
        }
        while (b < m)
        {
            int mult;
            /* get mult */
            if (mult < p) {
                for (int j = 1; j <= p - mult; j++)
                {
                    float save, s;
                    /* save = ...; */
                    /* s = ...; */
                }
                for (int k = p; k >= s; k--)
                {
                    float alfa;
                    /* get alfa */
                    for (int row = 0; row < /* specify row condition */; row++)
                    {
                        Qw[nb][k][row] = alfa * Qw[nb][k][row] + (1.0 - alfa) * Qw[nb][k - 1][row];
                    }
                }
                if (b < m)
                {
                    for (int row = 0; row < /* specify row condition */; row++)
                    {
                        Qw[nb + 1][save][row] = Qw[nb][p][row];
                    }
                }
            }
            nb++;
            if (b < m)
            {
                for (int i = p - mult; i <= p; i++)
                {
                    for (int row = 0; row < /* specify row condition */; row++)
                    {
                        Qw[nb][i][row] = Pw[b - p + i][row];
                    }
                }
                a = b;
                b = b + 1;
            }
        }
    }
    else if (dir == V_DIRECTION)
    {
        /* Similar logic as above, but with u- and v-directional parameters switched */
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