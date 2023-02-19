#include <graphics.h>
#include <stdlib.h>
#include <conio.h>

int main()
{
    int gddriver = DETECT, gmode, errorcode;
    initgraph(&gddriver, &gmode, "");

    for(int i=0; i < 1000; i++)
        line(rand()%1024,rand()%800,rand()%1024,rand()%800);
 
    getch();
    closegraph;
    return 0;
}
