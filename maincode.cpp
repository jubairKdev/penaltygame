#include <windows.h>
#include <bits/stdc++.h>
#include <conio.h>
using namespace std ;

void gotoxy (int x, int y)
{
    COORD c ;
    c.X = x ;
    c.Y = y ;

    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c) ;
}

int main ()
{
    int col = 5 ;
    int row = 5 ;

    gotoxy(col, row) ;
    cout << "x" ;

    while (true)
    {
        int key = _getch() ;

        if (key == 13) break ;          // Enter quits

        if (key == 224 || key == 0)     // arrow key incoming
        {
            int dir = _getch() ;

            gotoxy(col, row) ;
            cout << " " ;               // erase old spot

            if (dir == 72) row-- ;   // up
            if (dir == 80 ) row++ ;  // down

            if (dir == 77) col++ ;      // right
            if (dir == 75) col-- ;      // left

            gotoxy(col, row) ;
            cout << "x" ;               // draw new spot
        }
    }

    return 0 ;

}
