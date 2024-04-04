#include <iostream>
#include <vector>
using namespace std;

/* Function to compute point on power basis curve using Horner's method */
double Horner1(vector<double>& a, int n, double u0) {
    double C = a[n];
    for (int i = n - 1; i >= 0; i--)
    {
        C = C * u0 + a[i];
    }
    return C;
}

int main() {
    /* Example usage */
    vector<double> coefficients = {1, 2, 3};    //Example coefficients
    int degree = 2;     //Example degree
    double point = 2.5;     //Example point
    double result = Horner1(coefficients, degree, point);
    cout << "Result: " << result << endl;
    return 0;
}