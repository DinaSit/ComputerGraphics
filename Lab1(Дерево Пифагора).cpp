#include <graphics.h>
#define pi 3.1415926536

void pifagor(int n, int x0,int y0,int a,double fi,double alpha)
{
    if (n == 0) return ;
    n --;
    
    int x1, y1, x2, y2, x3, y3, x4, y4;
    
    int lt = (int)(a * cos(alpha)); // left roof line
    int rt = (int)(a * sin(alpha)); // right roof line
    
    x1 = (int)(x0 + a * cos(fi));      y1 = (int)(y0 - a * sin(fi));
    x2 = (int)(x1 - a * sin(fi));      y2 = (int)(y1 - a * cos(fi));
    x3 = (int)(x0 - a * sin(fi));      y3 = (int)(y0 - a * cos(fi));
    x4 = (int)(x3 + lt * cos(fi + alpha));
    y4 = (int)(y3 - lt * sin(fi + alpha));

    line(x0, y0, x1, y1);
    line(x1, y1, x2, y2);
    line(x2, y2, x3, y3);
    line(x3, y3, x0, y0);
    
    pifagor(n, x3, y3, lt, fi + alpha, alpha); //left square
    pifagor(n, x4, y4, rt, fi + alpha - pi/2, alpha); // right square
}

int main()
{
    int gddriver = DETECT, gmode, errorcode;
    initgraph(&gddriver, &gmode, "");

    pifagor(10, 1024, 750, 150, 0, pi/6);
 
    getch();
    closegraph;
    return 0;
}
