#include <bits/stdc++.h>

using namespace std;

bool checkifwinnerexists(char mat[3][3], int player)
{
    char check;
    if (player == 1)
    {
        check = 'O';
    }
    else
    {
        check = 'X';
    }

    bool flag = false;
    for (int i = 0; i < 3; i++)
    {
        if (mat[i][0] == check && mat[i][1] == check && mat[i][2] == check)
        {
            flag = true;
        }
        if (mat[0][i] == check && mat[1][i] == check && mat[2][i] == check)
        {
            flag = true;
        }
    }
    if (mat[0][0] == check && mat[1][1] == check && mat[2][2] == check)
    {
        flag = true;
    }
    if (mat[0][2] == check && mat[1][1] == check && mat[2][0] == check)
    {
        flag = true;
    }

    return flag;
}

bool checktie(char mat[3][3])
{
    bool flag = true;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (mat[i][j] == '.')
            {
                flag = false;
            }
        }
    }

    return flag;
}

int main()
{
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    char mat[3][3];
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            mat[i][j] = '.';
        }
    }

    bool flag = false;
    int player = 1;
    while (!flag)
    {
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                cout << mat[i][j] << " ";
            }
            cout << endl;
        }
        int row, col;
        cout << "enter the row and col Mr. player  " << player << endl;
        scanf("%d %d", &row, &col);
        if (mat[row - 1][col - 1] != '.')
        {
            cout << "your choice is already occupied. please enter another choice" << endl;
            continue;
        }
        if (player == 1)
        {
            mat[row - 1][col - 1] = 'O';
        }
        else
        {
            mat[row - 1][col - 1] = 'X';
        }

        if (checkifwinnerexists(mat, player))
        {
            cout << "player - " << player << " wins";
            break;
        }

        if (checktie(mat))
        {
            cout << "its a tie game" << endl;
            break;
        }

        if (player == 1)
        {
            player = 2;
        }
        else
        {
            player = 1;
        }
    }

    return 0;
}