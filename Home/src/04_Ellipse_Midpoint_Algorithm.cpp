#include <graphics.h>
#include <iostream>
using namespace std;

void drawEllipse(int xc, int yc, int x, int y) {
    putpixel(xc + x, yc + y, WHITE);
    putpixel(xc - x, yc + y, WHITE);
    putpixel(xc + x, yc - y, WHITE);
    putpixel(xc - x, yc - y, WHITE);
}

void midpointEllipse(int xc, int yc, int rx, int ry) {
    float dx, dy, d1, d2, x, y;
    x = 0;
    y = ry;

    d1 = (ry * ry) - (rx * rx * ry) + (0.25 * rx * rx);
    dx = 2 * ry * ry * x;
    dy = 2 * rx * rx * y;

    while (dx < dy) {
        drawEllipse(xc, yc, x, y);

        if (d1 < 0) {
            x++;
            dx = dx + (2 * ry * ry);
            d1 = d1 + dx + (ry * ry);
        } else {
            x++;
            y--;
            dx = dx + (2 * ry * ry);
            dy = dy - (2 * rx * rx);
            d1 = d1 + dx - dy + (ry * ry);
        }
    }

    d2 = ((ry * ry) * ((x + 0.5) * (x + 0.5))) + ((rx * rx) * ((y - 1) * (y - 1))) - (rx * rx * ry * ry);

    while (y >= 0) {
        drawEllipse(xc, yc, x, y);

        if (d2 > 0) {
            y--;
            dy = dy - (2 * rx * rx);
            d2 = d2 + (rx * rx) - dy;
        } else {
            y--;
            x++;
            dx = dx + (2 * ry * ry);
            dy = dy - (2 * rx * rx);
            d2 = d2 + dx - dy + (rx * rx);
        }
    }
}

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, (char*)"");

    int xc, yc, rx, ry;
    cout << "Enter center of ellipse (xc, yc): ";
    cin >> xc >> yc;
    cout << "Enter x-radius (rx): ";
    cin >> rx;
    cout << "Enter y-radius (ry): ";
    cin >> ry;


    midpointEllipse(xc, yc, rx, ry);
    
    setcolor(WHITE);
    outtextxy(10, 10, "Sabin Shrestha");
    getch();
    closegraph();
    return 0;
}
