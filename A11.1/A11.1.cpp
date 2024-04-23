#include <iostream>
#include <vector>
using namespace std;

void ConstBasedSurfMod1(
    int n, int m, int p, int q,
    vector<double> U, vector<double> V,
    vector<vector<Point>> Pw,
    vector<ConstraintNode> CList,
    int R, 
    int& M, int& N, 
    Matrix A, 
    vector<int> CpInd
) {
    int Nmax = max((n + 1) * (m + 1), R * (p + 1) * (q + 1));
    Matrix B(M, vector<double>(Nmax, 0.0));

    vector<vector<int>> Map(n + 1, vector<int>(m + 1, -1));
    int brow = 0;
    N = 0;

    for (int r = 0; r < R; r++)
    {
        Point uv = ExtractFromList(Clist[r]);
        Matrix FreeCp(p + 1, vector<bool>(q + 1, false));
        FreeCtrlPts(uv.u, uv.v, FreeCp);

        int uspan = FindSpan(n, p, uv.u, U);
        int vspan = FindSpan(m, q, uv.v, V);

        for (int i = 0; i <= p; i++)
        {
            for (int j = 0; j <= q; j++)
            {
                if (FreeCp[i][j])
                {
                    int iup = i + i + uspan - p;
                    int jvp = j + vspan - q;

                    if (Map[iup][jvp] == -1)
                    {
                        Map[iup][jvp] = N;
                        CpInd[N] = jvp * (n + 1) + iup;
                        N++;
                    }
                }
            }
        }


        Matrix Funs(p + 1, vector<vector<vector<double>>>(q + 1, vector<vector<double>>(2, vector<double>(2, 0.0))));
        RatDersBasisFuns(uv.u, uv.v, Funs);

        for (int c = 0; c < CList[r].constraints.size(); c++)
        {
            int k = CList[r].constraints[c].k;
            int l = CList[r].constraints[c].l;

            for (int i = 0; i <= p; i++)
            {
                for (int j = 0; j <= q; j++)
                {
                    int alf = Map[i + uspan - p][j + vspan - q];
                    if (alf >= 0)
                    {
                        B[brow][alf] = Funs[k][l][i][j];
                    }
                }
            }
            brow++;
        }
    }

    /* System overdetermined */
    if (M > N) return 1;
    if (M == N)
    {
        if (B is singular) return 2;
        else {
            A = Inverse(B);
            return 0;
        }
    }
    if (IsSingular(Transpose(B) * B)) return 2;
    else {
        A = Transpose(B) * Inverse(Transpose(B) * B);
        return 0;
    }
}

