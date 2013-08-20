#include <conio.h>
#include <iostream>
#include <windows.h>

using namespace std;

struct Point
    { 
      public:
        int x;
        int y;
    };
const int height = 7;
const int width = 20;

void draw (int board, Point obgect);

    
int main ()
{
  int board=0;
  
  Point obgect;
      obgect.x =1;
      obgect.y =1;
  draw(board ,obgect);
  cout<< board << "\n";
  cout<< obgect.x << "\n";
  cout<< obgect.y << "\n";
  cout<< "GAME OVER!!!!\n\n" ;
  cout<< "Press ENTER to continue...";
  //cin.get ();
  getch();
  return 0;
}

void draw (int board, Point obgect)
{
     for (int counterH = 0; counterH < height; counterH++) 
     {
       for (int counterW = 0; counterW < width; counterW++)
         {
                 if (counterW == obgect.x && counterH == obgect.y)
                    {
                    cout << "*";
                    continue;
                    }
                 if (counterW == board && counterH == 5) //height board
                    {
                    cout << "_";
                   continue;
                    }
                 cout << "-" ;
         }
     cout << "\n";
     }
}