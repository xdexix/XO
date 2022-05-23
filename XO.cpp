#include <iostream>
#include <sstream>
#include <string.h>
#include <Windows.h>

using namespace std;

class Point
{
    int x;
    int y;
    string cont;
public:
    Point()
    {
        x = 0;
        y = 0;
        cont = " ";
    }
    Point(int _x, int _y, string _cont)
    {
        x = _x;
        y = _y;
        cont = _cont;
    }
    string Container()
    {
        return cont;
    }
    void New_Container(string _cont)
    {
        cont = _cont;
    }
};

class Field
{
    Point f[3][3];
public:
    Field()
    {
        stringstream ss;
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                ss << j * 3 + i + 1;
                f[i][j] = Point(i, j, ss.str());
                ss.str("");
            }
        }
    }
    void Print()
    {
        cout << f[0][0].Container() << "|" << f[1][0].Container() << "|" << f[2][0].Container() << endl;
        cout << f[0][1].Container() << "|" << f[1][1].Container() << "|" << f[2][1].Container() << endl;
        cout << f[0][2].Container() << "|" << f[1][2].Container() << "|" << f[2][2].Container() << endl;
    }
    string Check()
    {
        int num = 0;
        for (int i = 0; i < 3; i++)
        {
            if ((f[i][0].Container() == f[i][1].Container()) && f[i][1].Container() == f[i][2].Container())
                return f[i][0].Container();
            if ((f[0][i].Container() == f[1][i].Container()) && f[1][i].Container() == f[2][i].Container())
                return f[0][i].Container();
        }
        if ((f[0][0].Container() == f[1][1].Container()) && f[1][1].Container() == f[2][2].Container())
            return f[0][0].Container();
        if ((f[2][0].Container() == f[1][1].Container()) && f[1][1].Container() == f[0][2].Container())
            return f[2][0].Container();
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                if (f[i][j].Container() == "X" || f[i][j].Container() == "O")
                    num++;
            }
        }
        if (num == 9)
            return "nobody";
        return " ";
    }
    void Play(string sign)
    {
        string v;
        bool Pass = false;
        while (!Pass)
        {
            cout << "Enter container " << sign << " >> ";
            cin >> v;
            if (v == "O" || v == "X")
                continue;
            for (int i = 0; i < 3; i++)
            {
                for (int j = 0; j < 3; j++)
                {
                    if (f[i][j].Container() == v)
                    {
                        f[i][j].New_Container(sign);
                        Pass = true;
                    }
                }
            }
        }
    }

    void C_Play(string sign)
    {
        bool Pass = false;
        cout << "Computer play" << endl;
        while (true)
        {
            for (int i = 0; i < 3; i++)
            {
                if (f[i][0].Container() == f[i][1].Container() && f[i][2].Container() != "O" && f[i][2].Container() != "X")
                {
                    f[i][2].New_Container(sign); Pass = true; break;
                }
                if (f[i][0].Container() == f[i][2].Container() && f[i][1].Container() != "O" && f[i][1].Container() != "X")
                {
                    f[i][1].New_Container(sign); Pass = true; break;
                }
                if (f[i][1].Container() == f[i][2].Container() && f[i][0].Container() != "O" && f[i][0].Container() != "X")
                {
                    f[i][0].New_Container(sign); Pass = true; break;
                }
                if (f[0][i].Container() == f[1][i].Container() && f[2][i].Container() != "O" && f[2][i].Container() != "X")
                {
                    f[2][i].New_Container(sign); Pass = true; break;
                }
                if (f[0][i].Container() == f[2][i].Container() && f[1][i].Container() != "O" && f[1][i].Container() != "X")
                {
                    f[1][i].New_Container(sign); Pass = true; break;
                }
                if (f[1][i].Container() == f[2][i].Container() && f[0][i].Container() != "O" && f[0][i].Container() != "X")
                {
                    f[0][i].New_Container(sign); Pass = true; break;
                }
            }
            if (Pass) break;
            if (f[0][0].Container() == f[1][1].Container() && f[2][2].Container() != "O" && f[2][2].Container() != "X")
            {
                f[2][2].New_Container(sign); Pass = true; break;
            }
            if (f[0][0].Container() == f[2][2].Container() && f[1][1].Container() != "O" && f[1][1].Container() != "X")
            {
                f[1][1].New_Container(sign); Pass = true; break;
            }
            if (f[1][1].Container() == f[2][2].Container() && f[0][0].Container() != "O" && f[0][0].Container() != "X")
            {
                f[0][0].New_Container(sign); Pass = true; break;
            }
            if (f[0][2].Container() == f[1][1].Container() && f[2][0].Container() != "O" && f[2][0].Container() != "X")
            {
                f[2][0].New_Container(sign); Pass = true; break;
            }
            if (f[2][0].Container() == f[0][2].Container() && f[1][1].Container() != "O" && f[1][1].Container() != "X")
            {
                f[1][1].New_Container(sign); Pass = true; break;
            }
            if (f[2][0].Container() == f[1][1].Container() && f[0][2].Container() != "O" && f[0][2].Container() != "X")
            {
                f[0][2].New_Container(sign); Pass = true; break;
            }
            if (!Pass)
                if (f[1][1].Container() != "O" && f[1][1].Container() != "X")
                {
                    f[1][1].New_Container(sign);
                    break;
                }
                else if (f[1][1].Container() == "O" || f[1][1].Container() == "X")
                {
                    bool br = false;
                    for (int i = 0; i < 3; i++)
                    {
                        for (int j = 0; j < 3; j++)
                        {
                            if (f[i][j].Container() != "O" && f[i][j].Container() != "X")
                            {
                                f[i][j].New_Container(sign);
                                br = true;
                                break;
                            }
                            if (br == true) break;
                        }
                        if (br == true) break;
                    }
                    if (br == true) break;
                }
            break;
        }
    }
};

string RevSign(string sign)
{
    if (sign == "O")
        return "X";
    else
        return "O";
}

void Game()
{
    system("cls");
    string Winner = " ";
    Field game; string sign = " "; char first = ' '; char mode = ' ';
    cout << "Do you want play with computer or with another player? (c - computer, p - 2nd player)" << endl;
    while (mode != 'c' && mode != 'p')
    {
        cout << " >> ";
        cin >> mode;
    }
    cout << "Choose your sign (O or X)" << endl;
    while (sign != "X" && sign != "O")
    {
        cout << " >> ";
        cin >> sign;
    }
    if (mode == 'c')
    {
        cout << "Do you want to play first? (Y - yes or N - no)" << endl;
        while (first != 'Y' && first != 'N')
        {
            cout << " >> ";
            cin >> first;
        }
    }
    while (Winner != "O" && Winner != "X" && Winner != "nobody")
    {
        system("cls");
        game.Print();
        if (mode == 'c' && first == 'Y')
        {
            game.Play(sign);
            Winner = game.Check();
            system("cls");
            game.Print();
            if (Winner != "O" && Winner != "X" && Winner != "nobody")
                game.C_Play(RevSign(sign));
        }
        if (mode == 'c' && first == 'N')
        {
            game.C_Play(RevSign(sign));
            Winner = game.Check();
            system("cls");
            game.Print();
            if (Winner != "O" && Winner != "X" && Winner != "nobody")
                game.Play(sign);
        }
        if (mode == 'p')
        {
            game.Play(sign);
            Winner = game.Check();
            system("cls");
            game.Print();
            if (Winner != "O" && Winner != "X" && Winner != "nobody")
                game.Play(RevSign(sign));
        }
        Winner = game.Check();
    }
    system("cls");
    game.Print();
    cout << endl << "Winner is " << Winner << "!" << endl << endl;
    for (int i = 5; i > 0; i--)
    {
        cout << "Countinue will be automatically in " << i << " seconds" << endl;
        Sleep(1000);
    }
}

void main()
{
    while (true)
        Game();
}
