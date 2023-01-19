#include <iostream>
#include <string>
using namespace std;
string A, B;
int lcs[1005][1005];
int main() {
    cout<<"Enter First String:";
    cin >> A;
    cout<<"Second String:";
    cin >> B;
    int m=A.length(),n=B.length();
    for (int i=0;i<=m;i++) {
        for (int j=0;j<=n;j++) {
            if (i==0 || j==0)
                lcs[i][j]=0;
            else if (A[i-1]==B[j-1]) {
                lcs[i][j]=lcs[i-1][j-1]+1;
            }
             else {
                lcs[i][j]=max(lcs[i-1][j],lcs[i][j-1]);
          }
        }
      }
    cout <<"Length of LCS:" << lcs[m][n] << endl;
    return 0;
}

