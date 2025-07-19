#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int r1, c1, r2, c2;
    cin >> r1 >> c1 >> r2 >> c2;

    // Torre
    int rook = (r1 == r2 || c1 == c2) ? 1 : 2;

    // Bispo
    int bishop;
    if ( (r1 + c1) % 2 != (r2 + c2) % 2 ) {
        bishop = 0;
    } else if ( abs(r1 - r2) == abs(c1 - c2) ) {
        // mesma diagonal
        bishop = 1;
    } else {
        // mesma cor, mas não na mesma diagonal
        bishop = 2;
    }

    // Rei
    int king = max( abs(r1 - r2), abs(c1 - c2) );

    cout << rook << " " << bishop << " " << king << endl;
    return 0;
}

