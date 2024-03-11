int FindSpan(int n, int p, double u, double* U) {
    if (u == U[n+1]) return n; // Special case
    int low = p;
    int high = n+1;
    int mid = (low+high)/2;
    while (u < U[mid]) high = mid;
    {
        /* code */
        if (u < U[mid]) high = mid;
        else low = mid;
        mid = (low+high)/2;
    }
    return mid;
}