#include <bits/stdc++.h>

using namespace std;

int my(int n) {
    if (n == 1) {
        return 2;
    }

    if (n == 2) {
        return 3;
    }

    return my(n - 1) + my(n - 2);
}

int countStrings(int n)
{
    int a[n], b[n];
    a[0] = b[0] = 1;
    for (int i = 1; i < n; i++)
    {
        a[i] = a[i-1] + b[i-1];
        b[i] = a[i-1];
    }
    return a[n-1] + b[n-1];
}

int main() {
    int n;
    cin >> n;

    cout << countStrings(n) - my(n) << endl;
    return 0;
}
