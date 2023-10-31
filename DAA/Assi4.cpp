// #include <bits/stdc++.h>

// using namespace std;
// class Solution {
//   public:
//     bool isSafe1(int row, int col, vector < string > board, int n) {
//       // check upper element
//       int duprow = row;
//       int dupcol = col;

//       while (row >= 0 && col >= 0) {
//         if (board[row][col] == 'Q')
//           return false;
//         row--;
//         col--;
//       }

//       col = dupcol;
//       row = duprow;
//       while (col >= 0) {
//         if (board[row][col] == 'Q')
//           return false;
//         col--;
//       }

//       row = duprow;
//       col = dupcol;
//       while (row < n && col >= 0) {
//         if (board[row][col] == 'Q')
//           return false;
//         row++;
//         col--;
//       }
//       return true;
//     }

//   public:
//     void solve(int col, vector < string > & board, vector < vector < string >> & ans, int n) {
//       if (col == n) {
//         ans.push_back(board);
//         return;
//       }
//       for (int row = 0; row < n; row++) {
//         if (isSafe1(row, col, board, n)) {
//           board[row][col] = 'Q';
//           solve(col + 1, board, ans, n);
//           board[row][col] = '.';
//         }
//       }
//     }

//   public:
//     vector < vector < string >> solveNQueens(int n) {
//       vector < vector < string >> ans;
//       vector < string > board(n);
//       string s(n, '.');
//       for (int i = 0; i < n; i++) {
//         board[i] = s;
//       }
//       solve(0, board, ans, n);
//       return ans;
//     }
// };
// int main() {
//   int n ;
//   cin>>n;
//   Solution obj;
//   vector < vector < string >> ans = obj.solveNQueens(n);
//   for (int i = 0; i < ans.size(); i++) {
//     cout << "Arrangement " << i + 1 << "\n";
//     for (int j = 0; j < ans[0].size(); j++) {
//       cout << ans[i][j];
//       cout << endl;
//     }
//     cout << endl;
//   }
//   return 0;
// }


#include <bits/stdc++.h>
#define N 100
using namespace std;

int board[N];
int cnt = 0;

void queen(int, int);
void printboard(int);
int place(int, int);

int main()
{
    int n;
    cout << "Enter number of queens:- ";
    cin >> n;
    if (n < 4)
    {
        cout << "\nNo solutions exist for the given input!\n\n";
    }
    else
    {
        queen(1, n);

        if (!cnt)
        {
            cout << "\nNo solutions exist for the given input!\n";
        }
        else
        {
            cout << "\n"
                 << cnt << " solutions printed.\n ";
        }
    }

    return 0;
}
void printboard(int n)
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (board[i] == j)
            {
                cout << "1  ";
            }
            else
            {
                cout << "0  ";
            }
        }
        cout << endl;
    }
}
int place(int k, int i)
{
    for (int j = 1; j <= k; j++)
    {
        if ((board[j] == i) || board[j] - j == i - k || board[j] + j == i + k)
        {
            return 0;
        }
    }
    return 1;
}
void queen(int k, int n)
{
    int i;
    if (k >= n + 1)
    {
        cnt++;
        cout << "\nPossible solutuion no. " << cnt << ":\n";
        printboard(n);
        return;
    }
    for (int i = 1; i <= n; i++)
    {
        if (place(k, i) == 1)
        {
            board[k] = i;
            queen(k + 1, n);
            board[k] = 0;
        }
    }
}