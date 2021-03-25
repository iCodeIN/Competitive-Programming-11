#include <iostream>
#include <vector>
#include <set>
using namespace std;

int dx[] = {1, 0, -1, 0, 1, -1};
int dy[] = {0, 1, 0, -1, 1, -1};

bool DFS(int sx, int sy, vector<vector<char>> &board, string s, set<pair<int, int>> &st, int m, int n)
{

    cout << "start : ";
    cout << sx << " " << sy << endl;
    if (s.size() == 0)
    {
        cout << "end : ";
        cout << sx << " " << sy << " " << 1 << endl;
        return true;
    }

    if (s[0] != board[sx][sy])
    {
        cout << "end : ";
        cout << sx << " " << sy << " " << 0 << endl;
        return false;
    }
    if (s.size() == 1)
    {
        cout << "end : ";
        cout << sx << " " << sy << " " << 1 << endl;
        return true;
    }

    bool ans = false;

    for (int i = 0; i < 6 and ans == false; i++)
    {
        if (sx + dx[i] < 0 or sx + dx[i] >= m or sy + dy[i] < 0 or sy + dy[i] >= n)
        {
            continue;
        }
        if (st.find({sx + dx[i], sy + dy[i]}) != st.end())
        {
            continue;
        }
        st.insert({sx + dx[i], sy + dy[i]});
        ans = ans or DFS(sx + dx[i], sy + dy[i], board, s.substr(1), st, m, n);
        st.erase({sx + dx[i], sy + dy[i]});
    }
    cout << "end : ";
    cout << sx << " " << sy << " " << ans << endl;
    return ans;
}

bool hasPath(vector<vector<char>> &board, int m, int n)
{

    string s = "CODINGNINJA";
    set<pair<int, int>> st;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (board[i][j] == s[0])
            {
                st.insert({i, j});
                if (DFS(i, j, board, s, st, m, n) == true)
                {
                    return true;
                }
                st.clear();
            }
        }
    }
    return false;
}

int main()
{
    int n, m;
    cin >> n >> m;

    vector<vector<char>> board(n, vector<char>(m));

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            cin >> board[i][j];
        }
    }

    cout << (hasPath(board, n, m) ? 1 : 0);
}