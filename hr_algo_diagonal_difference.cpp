#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char* argv[]) {
    int n;
    cin >> n;

    vector<vector<int> > a(
        n,
        vector<int>(n, 0)
    );
    for(int a_i = 0; a_i < n; a_i++){
        for(int a_j = 0; a_j < n; a_j++){
            cin >> a[a_i][a_j];
        }
    }

    // print matrix
    /*
    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
    */

    int primary_diagonal = 0;
    int secondary_diagonal = 0;
    for(int i=0;i<n;i++) {
        primary_diagonal += a[i][i];
        secondary_diagonal += a[i][n-1-i];
    }
    int diff = abs(primary_diagonal - secondary_diagonal);
    cout << diff << endl;
    return 0;
}
