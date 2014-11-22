#include <bits/stdc++.h>

using namespace std;

int main() {
    ifstream inputFile ("words.txt");
    ofstream outputFile ("results.txt");
    transform(istream_iterator<string>(inputFile), istream_iterator<string>(),
            ostream_iterator<int>(outputFile, "\n"), mem_fun_ref(&string::length));
    return 0;
}
