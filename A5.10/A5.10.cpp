#include <iostream>
#include <vector>
using namespace std;

/* Function to degree elevate a surface 't' times */
void DegreeElevateSurface(int n, int p, vector<double>& U, int m, int q, vector<double>& V, 
                          vector<vector<double>>& Pw, char dir, int t,
                          int& nh, vector<double>& Uh, int& mh, vector<double>& Vh, 
                          vector<vector<double>>& Qw) {
    if (dir == 'U') {
        /* Allocate memory for Bezier and NextBezier strips */
        /* Initialize knot vectors and first row of control points */
        /* Initialize Bezier strip */
        /* Set variables */
        
        /* While loop */
        // while(b < m) {
            // Get multiplicity
            // Get ub, r, oldr, etc
            // Save alfas
        // }
        
        /* For loop */
        for (int j = 0; j <= m; j++) {
            /* Insert knot */
            /* Degree elevate Bezier row[j] */
            /* Remove knot */
            /* Save new control points */
            /* Initialize for next pass through */
        }
        
        /* Update knot vector */
        /* Update variables */
        /* Get end knots */
    }
    else if (dir == 'V') {
        /* Similar code as above with u- and v-directional parameters switched */
    }
}

int main() {
    /* Example usage */
    int n = 5, p = 3, m = 10;
    int q = 4, t = 2, nh, mh;
    char dir = 'U';
    vector<double> U = {0, 0, 0, 0, 1, 2, 3, 4, 5, 5, 5, 5};
    vector<double> V = {0, 0, 0, 0, 1, 2, 3, 4, 5, 5, 5, 5};
    vector<vector<double>> Pw(n + 1, vector<double>(m + 1, 0.0));
    vector<double> Uh, Vh;
    vector<vector<double>> Qw;

    /* Call the function */
    DegreeElevateSurface(n, p, U, m, q, V, Pw, dir, t, nh, Uh, mh, Vh, Qw);

    return 0;
}