#include <graphics.h>

void myline(int x1,int y1, int x2,int y2, int c)
{ 
    int N = abs(x2 - x1);
	int M = abs(y2 - y1);
	int	x = x1;
	int y = y1;
	int buf = 0;
	// первая точка линии
	putpixel(x1, y1, c);
	// инверсия
	if (y2 < y1)
	{
		y = y2;
		y2 = y1;
	}
	if (x2 < x1)
	{
		x = x2;
		x2 = x1;
	}
	
	if (M <= N)
	{
		for (x += 1; x <= x2; x++)
		{
			buf += M;
			if (buf >= N)
				while (buf >= N)
				{
					buf -= N;
    				y++;
    				putpixel (x, y, c);
    			}
  			else
    			putpixel (x, y, c);
		}
	}
	else
	{
		for (y += 1; y <= y2; y++)
		{
			buf += N;
			if (buf >= M)
				while (buf >= M)
				{
					buf -= M;
					x++;
					putpixel(x, y, c);
				}
			else
				putpixel(x, y, c);
		}
	}
}

void mycirc(int x0,int y0, int r, int c)
{
    int i = 0, j = r;
    //первые точки на окружности
    putpixel(x0, y0 + j, c);
    putpixel(x0, y0 - j, c);
    putpixel(x0 + j, y0, c);
    putpixel(x0 - j, y0, c);
 
    while (j >= i) {
    	// вычисление погрешностей в точках
        int e = pow(i, 2) + pow(j, 2) - pow(r, 2);
        int eg = pow(i + 1, 2) + pow(j, 2) - pow(r, 2);
        int ed = pow(i + 1, 2) + pow(j - 1, 2) - pow(r, 2);
        int ev = pow(i, 2) + pow(j - 1, 2) - pow(r, 2);
 
        if (e < 0) { // Пиксель внутри окружности
            if (abs(eg) < abs(ed))
                i++;
            else
                i++, j--;
        } else {
            if (abs(ed) < abs(ev))
                i++, j--;
            else
                j--;
        }
		
        putpixel(x0 + i, y0 + j, c);
        putpixel(x0 + i, y0 - j, c);
        putpixel(x0 - i, y0 + j, c);
        putpixel(x0 - i, y0 - j, c);
        putpixel(x0 + j, y0 + i, c);
        putpixel(x0 + j, y0 - i, c);
        putpixel(x0 - j, y0 + i, c);
        putpixel(x0 - j, y0 - i, c);
    }
}

int main()
{
    int gddriver = DETECT, gmode, errorcode;
    initgraph(&gddriver, &gmode, "");

    myline(50, 120, 370, 120, 3);
    mycirc(800, 500, 150, 4);
 
    getch();
    closegraph;
    return 0;
}

/* тесты для myline():
вертикальная, сверху-вниз     myline(120, 50, 120, 370, 3);
вертикальная, снизу-вверх     myline(120, 370, 120, 50, 3);
слева-направо, горизонтальная myline(50, 120, 370, 120, 3);
справа-налево, горизонтальная myline(370, 120, 50, 120, 3);
слева-направо, сверху-вниз    myline(50, 120, 370, 400, 3);
слева-направо, снизу-вверх    myline(50, 400, 370, 120, 3);
справа-налево, сверху-вниз    myline(370, 120, 50, 400, 3);
справа-налево, снизу-вверх    myline(370, 400, 50, 120, 3);
*/
