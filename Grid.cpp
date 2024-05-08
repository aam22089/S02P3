#include "Grid.hpp"

Grid::Grid(int rows, int cols)
{
    this->rows = rows;
    this->cols = cols;
    for (int i = 0; i < rows; i++)
    {
        tablero.push_back({});
        for (int j = 0; j < cols; j++)
        {
            tablero[i].push_back(0);
        }
    }

    this->siguiente = vector<vector<int>>(rows, vector<int>(cols, 0));
}
Grid::Grid(int n, int w, int h)
{
    this->rows = n;
    this->cols = n;
    this->w = w;
    this->h = h;
    for (int i = 0; i < this->rows; i++)
    {
        tablero.push_back({});
        for (int j = 0; j < this->cols; j++)
        {
            tablero[i].push_back(0);
        }
    }
    this->siguiente = vector<vector<int>>(rows, vector<int>(cols, 0));
}

void Grid::drawTo(RenderWindow &window)
{
    int sizeX = this->w / this->cols;
    int sizeY = this->h / this->rows;

    for (int i = 0; i < this->rows; i++)
    {
        for (int j = 0; j < this->cols; j++)
        {
            RectangleShape rect(Vector2f(sizeX, sizeY));
            rect.setPosition(Vector2f(j * sizeX, i * sizeY));
            if (tablero[j][i] == 1)
            {
                rect.setFillColor(Color::Green);
            }
            window.draw(rect);
        }
    }
}

void Grid::toggle(int x, int y)
{
    int sizeX = this->w / this->cols;
    int sizeY = this->h / this->rows;

    int indexX = x / sizeX;
    int indexY = y / sizeY;

    tablero[indexX][indexY] = 1;
}

void Grid::update()
{
    int speed=1;
    for (int i = 0; i < this->rows; i++)
    {
        for (int j = 0; j < this->cols; j++)
        {
            if(tablero[i][j]==1)
            {
                if(tablero[i][j+speed]==0)
                tablero[i][j+speed]=1
            }
    }
    
}
}
<<<<<<< HEAD
=======

// int Grid::calcularVecinos(int i, int j)
// {
//     int vecinos = 0;
//     // arriba a la izquierda
//     if (i > 0 && j > 0 && this->tablero[i - 1][j - 1] == 1)
//         vecinos++;
//     // arriba
//     if (j > 0 && this->tablero[i][j - 1] == 1)
//         vecinos++;
//     // arriba a la derecha
//     if (j > 0 && i < this->rows - 1 && this->tablero[i + 1][j - 1] == 1)
//         vecinos++;

//     // izquierda
//     if (i > 0 && this->tablero[i - 1][j] == 1)
//         vecinos++;
//     // derecha
//     if (i < this->rows - 1 && this->tablero[i + 1][j] == 1)
//         vecinos++;

//     // abajo a la izquierda
//     if (i > 0 && j < this->cols - 1 && this->tablero[i - 1][j + 1] == 1)
//         vecinos++;
//     // // abajo
//     if (j < this->cols - 1 && this->tablero[i][j + 1] == 1)
//         vecinos++;
//     // abajo a la derecha
//     if (i < this->rows - 1 && j < this->cols - 1 && this->tablero[i + 1][j + 1] == 1)
//         vecinos++;

//     return vecinos;
// }
>>>>>>> c05f96b892fe9741355a449b1df7aaf4f01bb320
