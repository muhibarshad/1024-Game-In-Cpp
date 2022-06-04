//This game is developed by Muhib Arshad_(muhib7353)
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <conio.h>
#include <iomanip>
using namespace std;
void moveup();
const int row = 4;
const int col = 4;
int main()
{

    bool flag = false;
    int count = 0;
    int matrix[row][col];
    int y = time(0);
    srand(y);
    char startgame;
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            matrix[i][j] = 0;
        }
    }
    int rando_startCol = rand() % 4;
    int rando_startRow = rand() % 4;
    int rando_startCol2 = rand() % 4;
    int rando_startRow2 = rand() % 4;
    matrix[rando_startRow][rando_startCol] = (rand() % 2) + 1;
    matrix[rando_startRow2][rando_startCol2] = (rand() % 2) + 1;
    for (int i = 0; i < 5; i++)
    {
        cout << endl;
    }
    cout << "\t\t\t\t\t To start the game!" << endl;
    cout << endl;
    cout << "\t\t\t\t\t Enter the S:";
    startgame = getch();
    startgame = tolower(startgame);
    while (startgame != 's')
    {
        cout << endl;
        cout << endl;
        cout << "\t\t\t\t\tInvalid key!" << endl;
        cout << endl;
        cout << "\t\t\t\t\tPlease enter the valid Key:";
        startgame = getch();
    }
    startgame = tolower(startgame);
    if (startgame == 's')
    {
        system("cls");
        do
        {
            for (int i = 0; i < 5; i++)
            {
                cout << endl;
            }
            cout << "\t\t\t\t\tEnter W to move upward:" << endl;
            cout << "\t\t\t\t\tEnter S to move downward:" << endl;
            cout << "\t\t\t\t\tEnter A to move left:" << endl;
            cout << "\t\t\t\t\tEnter D to move right:" << endl;
            cout << "\t\t\t\t\tEnter Q to quit the game:" << endl;
            cout << endl;
            for (int i = 0; i < row; i++)
            {
                cout << "\t\t\t\t ------------------------------------------" << endl;
                cout << "\t\t\t\t ";
                for (int j = 0; j < col; j++)
                {
                    cout << "|    ";
                    cout << matrix[i][j] << "    ";
                }
                cout << " |";
                cout << endl;
            }
            cout << "\t\t\t\t -------------------------------------------" << endl;
            char ch;
            for (int i = 0; i < 3; i++)
            {
                cout << endl;
            }
            cout << "\t\t\t\t\tEnter the valid key:";
            ch = getch();
            ch = tolower(ch);
            while (ch != 'd' && ch != 'a' && ch != 'w' && ch != 's')
            {
                cout << endl;
                cout << endl;
                cout << "\t\t\t\t\tInvalid Input:" << endl;
                cout << "\t\t\t\t\tplease Enter the valid input:";
                ch = getch();
            }
            ch = tolower(ch);
            switch (ch)
            {
            case 'd':
            {
                system("cls");
                for (int i = 0; i < col - 1; i++)
                {
                    for (int j = 0; j < row; j++)
                    {
                        if (matrix[j][i] == matrix[j][i + 1])
                        {
                            matrix[j][i + 1] += matrix[j][i];
                            if (matrix[j][i + 1] == 1024)
                            {
                                for (int i = 0; i < 10; i++)
                                {
                                    cout << endl;
                                }
                                flag = true;
                                cout << "\t\t\t\t\tYou Win the game!:" << endl;
                            }
                            matrix[j][i] = 0;
                            for (int k = 0; k < row; k++)
                            {
                                for (int l = 0; l < col - 1; l++)
                                {
                                    if (matrix[k][l + 1] == 0)
                                    {
                                        int temp;
                                        temp = matrix[k][l + 1];
                                        matrix[k][l + 1] = matrix[k][l];
                                        matrix[k][l] = temp;
                                    }
                                }
                            }
                        }
                    }
                }

                int randomrow;
                int randomcol;
                randomcol = rand() % 4;
                randomrow = rand() % 4;
                if (matrix[randomrow][randomcol] == 0)
                {
                    matrix[randomrow][randomcol] = (rand() % 2) + 1;
                }
                else
                {
                    while (matrix[randomrow][randomcol] != 0)
                    {
                        int x = time(0);
                        srand(x);
                        randomcol = rand() % 4;
                        randomrow = rand() % 4;
                        if (matrix[randomrow][randomcol] == 0)
                        {
                            break;
                        }
                    }
                    matrix[randomrow][randomcol] = (rand() % 2) + 1;
                }

                int gameover = 0;
                for (int i = 0; i < row; i++)
                {
                    for (int j = 0; j < col; j++)
                    {
                        if (matrix[i][j] != 0)
                        {
                            gameover++;
                        }
                    }
                }
                if (gameover == 16)
                {
                    flag = true;
                    cout << "Game over" << endl;
                }
                break;
            }
            case 'a':
            {
                system("cls");
                for (int i = col - 1; i > 0; i--)
                {
                    for (int j = 0; j < row; j++)
                    {
                        if (matrix[j][i] == matrix[j][i - 1])
                        {
                            matrix[j][i - 1] += matrix[j][i];
                            if (matrix[j][i - 1] == 1024)
                            {
                                for (int i = 0; i < 10; i++)
                                {
                                    cout << endl;
                                }
                                flag = true;
                                cout << "\t\t\t\t\tYou Win the game!:" << endl;
                            }
                            matrix[j][i] = 0;
                            for (int k = 0; k < row; k++)
                            {
                                for (int l = col - 1; l > 0; l--)
                                {
                                    if (matrix[k][l - 1] == 0)
                                    {
                                        int temp;
                                        temp = matrix[k][l - 1];
                                        matrix[k][l - 1] = matrix[k][l];
                                        matrix[k][l] = temp;
                                    }
                                }
                            }
                        }
                    }
                }

                int randomrow;
                int randomcol;
                randomcol = rand() % 4;
                randomrow = rand() % 4;
                if (matrix[randomrow][randomcol] == 0)
                {
                    matrix[randomrow][randomcol] = (rand() % 2) + 1;
                }
                else
                {
                    while (matrix[randomrow][randomcol] != 0)
                    {
                        int x = time(0);
                        srand(x);
                        randomcol = rand() % 4;
                        randomrow = rand() % 4;
                        if (matrix[randomrow][randomcol] == 0)
                        {
                            break;
                        }
                    }
                    matrix[randomrow][randomcol] = (rand() % 2) + 1;
                }

                int gameover = 0;
                for (int i = 0; i < row; i++)
                {
                    for (int j = 0; j < col; j++)
                    {
                        if (matrix[i][j] != 0)
                        {
                            gameover++;
                        }
                    }
                }
                if (gameover == 16)
                {
                    flag = true;
                    cout << "Game over" << endl;
                }
                break;
            }
            case 'w':
            {
                system("cls");
                for (int i = row - 1; i > 0; i--)
                {
                    for (int j = 0; j < col; j++)
                    {
                        if (matrix[i][j] == matrix[i - 1][j])
                        {
                            matrix[i - 1][j] += matrix[i][j];
                            if (matrix[i - 1][j] == 1024)
                            {
                                for (int i = 0; i < 10; i++)
                                {
                                    cout << endl;
                                }
                                flag = true;
                                cout << "\t\t\t\t\tYou Win the game!:" << endl;
                            }
                            matrix[i][j] = 0;
                            for (int k = 0; k < col; k++)
                            {
                                for (int l = row - 1; l > 0; l--)
                                {
                                    if (matrix[l - 1][k] == 0)
                                    {
                                        int temp;
                                        temp = matrix[l - 1][k];
                                        matrix[l - 1][k] = matrix[l][k];
                                        matrix[l][k] = temp;
                                    }
                                }
                            }
                        }
                    }
                }

                int randomrow;
                int randomcol;
                randomcol = rand() % 4;
                randomrow = rand() % 4;
                if (matrix[randomrow][randomcol] == 0)
                {
                    matrix[randomrow][randomcol] = (rand() % 2) + 1;
                }
                else
                {
                    while (matrix[randomrow][randomcol] != 0)
                    {
                        int x = time(0);
                        srand(x);
                        randomcol = rand() % 4;
                        randomrow = rand() % 4;
                        if (matrix[randomrow][randomcol] == 0)
                        {
                            break;
                        }
                    }
                    matrix[randomrow][randomcol] = (rand() % 2) + 1;
                }

                int gameover = 0;
                for (int i = 0; i < row; i++)
                {
                    for (int j = 0; j < col; j++)
                    {
                        if (matrix[i][j] != 0)
                        {
                            gameover++;
                        }
                    }
                }
                if (gameover == 16)
                {
                    flag = true;
                    cout << "Game over" << endl;
                }
                break;
            }
            case 's':
            {
                system("cls");
                for (int i = 0; i < row - 1; i++)
                {
                    for (int j = 0; j < col; j++)
                    {
                        if (matrix[i][j] == matrix[i + 1][j])
                        {
                            matrix[i + 1][j] += matrix[i][j];
                            if (matrix[i + 1][j] == 1024)
                            {
                                for (int i = 0; i < 10; i++)
                                {
                                    cout << endl;
                                }
                                flag = true;
                                cout << "\t\t\t\t\tYou Win the game!:" << endl;
                            }
                            matrix[i][j] = 0;
                            for (int k = 0; k < col; k++)
                            {
                                for (int l = 0; l < row - 1; l++)
                                {
                                    if (matrix[l + 1][k] == 0)
                                    {
                                        int temp;
                                        temp = matrix[l + 1][k];
                                        matrix[l + 1][k] = matrix[l][k];
                                        matrix[l][k] = temp;
                                    }
                                }
                            }
                        }
                    }
                }

                int randomrow;
                int randomcol;
                randomcol = rand() % 4;
                randomrow = rand() % 4;
                if (matrix[randomrow][randomcol] == 0)
                {
                    matrix[randomrow][randomcol] = (rand() % 2) + 1;
                }
                else
                {
                    while (matrix[randomrow][randomcol] != 0)
                    {
                        int x = time(0);
                        srand(x);
                        randomcol = rand() % 4;
                        randomrow = rand() % 4;
                        if (matrix[randomrow][randomcol] == 0)
                        {
                            break;
                        }
                    }
                    matrix[randomrow][randomcol] = (rand() % 2) + 1;
                }

                int gameover = 0;
                for (int i = 0; i < row; i++)
                {
                    for (int j = 0; j < col; j++)
                    {
                        if (matrix[i][j] != 0)
                        {
                            gameover++;
                        }
                    }
                }
                if (gameover == 16)
                {
                    flag = true;
                    cout << "Game over" << endl;
                }
                break;
            }
            }

        } while (flag == false);
    }

    return 0;
}
