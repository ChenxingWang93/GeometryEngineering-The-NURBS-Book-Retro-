void Horner2(double** a, int n, int m, double u0, double v0, double S) {
    double b[n+1];
    for (int i = 0; i <= n; i++)
    {
        /* code */
        Horner1(a[i], m, v0, b[i]); // a[i][] is the ith row
    }
    Horner1(b, n, u0, S);
}