#include "Canvas.h"
#include <math.h>
#include <iostream>

Canvas::Canvas(int width, int height)
{
    this->width = width;
    this->height = height;
    this->matrice = new char*[height];
    for (int i = 0; i < height; i++)
        matrice[i] = new char[width];
}

void Canvas::DrawCircle(int x, int y, int ray, char ch)
{
    for (int i = x - ray; i <= x + ray; i++)
        for (int j = y - ray; j <= y + ray; j++)
            if (ray * ray==(i - x) * (i - x) + (j - y) * (j - y))
                matrice[i][j] = ch;
}

void Canvas::FillCircle(int x, int y, int ray, char ch)
{
    for (int i = x - ray; i <= x + ray; i++)
        for (int j = y - ray; j < y + ray; j++)
            if (ray * ray >= (i - x) * (i - x) + (j - y) * (j - y))
                matrice[i][j] = ch;
}

void Canvas::DrawRect(int left, int top, int right, int bottom, char ch)
{
    for (int i=left;i<=right;i++)
    {
        matrice[top][i] = ch;
        matrice[bottom][i] = ch;
    }
    for (int i=top;i<=bottom;i++)
    {
        matrice[i][left] = ch;
        matrice[i][right] = ch;
    }
}

void Canvas::FillRect(int left, int top, int right, int bottom, char ch)
{
    for (int i = top; i <= bottom; i++)
        for (int j = left; j <= right; j++)
            matrice[i][j] = ch;
}

void Canvas::SetPoint(int x, int y, char ch)
{
    matrice[y][x] = ch;
}

void Canvas::DrawLine(int x1, int y1, int x2, int y2, char ch)
{
    int dx = abs(x2 - x1);
    int sx = x1 < x2 ? 1 : -1;
    int dy = -abs(y2 - y1);
    int sy = y1 < y2 ? 1 : -1;
    int error = dx + dy;

    while (true)
    {
        matrice[y1][x1] = ch;
        if (x1 == x2 && y1 == y2)
            break;
        int e2 = 2 * error;
        if (e2 > dy)
        {
            if (x1 == x2)
                break;
            error += dy;
            x1 = x1 + sx;
        }
        if (e2<=dx)
        {
            if (y1 == y2)
                break;
            error = error + dx;
            y1    = y1 + sy;
        }
    }
}

void Canvas::Print()
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
            std::cout << matrice[i][j];
        std::cout << '\n';
    }
}

void Canvas::Clear()
{
    for (int i = 0; i < height; i++)
        for (int j = 0; j < width; j++)
            matrice[i][j] = ' ';
}
