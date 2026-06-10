#include <iostream>
using namespace std;
char b[3][3] = {
    {'1','2','3'},
    {'4','5','6'},
    {'7','8','9'}
};
void displayBoard()
{
    cout << endl;
    cout << b[0][0] << " | " << b[0][1] << " | " << b[0][2] << endl;
    cout << "--|---|--" << endl;
    cout << b[1][0] << " | " << b[1][1] << " | " << b[1][2] << endl;
    cout << "--|---|--" << endl;
    cout << b[2][0] << " | " << b[2][1] << " | " << b[2][2] << endl;
    cout << endl;
}
bool checkWin()
{
    for(int i=0;i<3;i++)
    {
        if(b[i][0]==b[i][1] && b[i][1]==b[i][2]) return true;
        if(b[0][i]==b[1][i] && b[1][i]==b[2][i]) return true;
    }
    if(b[0][0]==b[1][1] && b[1][1]==b[2][2]) return true;
    if(b[0][2]==b[1][1] && b[1][1]==b[2][0]) return true;
    return false;
}
int main()
{
    char player = 'X';
    int move, count = 0;
    char again;
    do
    {
        b[0][0]='1'; b[0][1]='2'; b[0][2]='3';
        b[1][0]='4'; b[1][1]='5'; b[1][2]='6';
        b[2][0]='7'; b[2][1]='8'; b[2][2]='9';
        player='X';
        count=0;
        while(true)
        {
            displayBoard();
            cout << "Player " << player << ", enter position: ";
            cin >> move;
            int r=(move-1)/3;
            int c=(move-1)%3;
            if(move<1 || move>9 || b[r][c]=='X' || b[r][c]=='O')
            {
                cout << "Invalid Move" << endl;
                continue;
            }
            b[r][c]=player;
            count++;
            if(checkWin())
            {
                displayBoard();
                cout << "Player " << player << " Wins!" << endl;
                break;
            }
            if(count==9)
            {
                displayBoard();
                cout << "Game Draw!" << endl;
                break;
            }
            if(player=='X')
                player='O';
            else
                player='X';
        }
        cout << "Play Again? (y/n): ";
        cin >> again;

    } while(again=='y' || again=='Y');
    return 0;
}