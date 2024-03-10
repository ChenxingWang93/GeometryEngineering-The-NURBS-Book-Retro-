void Bernstein(int i, int n, double u, double B) {
    double temp[n+1];
    double u1 = 1.0 - u;

    for (int j = 0; j <= n; j++) {
        temp[j] = 0.0;
    }
    temp[n - i] = 1.0;

    for (int k = 1; k <= n; k++) {
        for (int j = n; j >= k; j--) {
            temp[j] = u1 * temp[j] + u * temp[j - 1];
        }
    }
    
    B = temp[n];
    
}