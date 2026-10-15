#include <windows.h>
#include <bits/stdc++.h>
#include <conio.h>
using namespace std ;

const int ROWS = 9 ;
const int COLS = 49 ;
const int START_X = 7 ; // where the field begins on screen
const int START_Y = 3 ;

void gotoxy (int x, int y)
{
    COORD c ;
    c.X = x ;
    c.Y = y ;

    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c) ;
}

void drawFrame ()
{
    for (int x = START_X - 1 ; x <= START_X + COLS ; x++)
    {
        gotoxy(x, START_Y - 1) ;
        cout << '-' ;                       // top bar
        gotoxy(x, START_Y + ROWS) ;
        cout << '-' ;                       // ground line
    }
    for (int y = START_Y ; y < START_Y + ROWS ; y++)
    {
        gotoxy(START_X - 1, y) ;
        cout << '|' ;                       // left post
        gotoxy(START_X + COLS, y) ;
        cout << '|' ;                       // right post
    }
}

int main ()
{
    int result=0 ; // goal or no goal
    drawFrame() ;

    int row = ROWS / 2 ; // starting position
    int col = COLS / 2;

    gotoxy(START_X + col, START_Y + row) ;
    cout << "X" ;

    while (true)
    {
        int key = _getch() ;

        if (key == 13) {result=1 ;break ;}          // Enter quits

        if (key == 224 || key == 0)     // arrow key incoming
        {
            int dir = _getch() ;

            gotoxy(START_X + col, START_Y + row) ;
            cout << " " ;               // erase old spot

            if (dir == 72 && row>0) row-- ;   // up
            if (dir == 80  && row< ROWS -1 ) row++ ;  // down

            if (dir == 77 && col< COLS -1) col++ ;      // right
            if (dir == 75 && col > 0) col-- ;      // left

            gotoxy(START_X + col, START_Y + row) ;
            cout << "X" ;               // draw new spot
        }
    }

    gotoxy (0, START_Y + ROWS + 3) ;// park the cursor below the field
    if (result)
        cout << "GOALLLLL!!!" ;

    return 0 ;

}
