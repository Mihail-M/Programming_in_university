#pragma once
const double EPS = 1e-10;
const int INF = 10000000;

class Gauss
{
public:
    Gauss(double **A, int n, int m);
    ~Gauss();
    ///вывести матрицу на экран
    void show();
    ///преобразовать матрицу к треугольному виду
    void toTriangle();
    /// вывести на экран частное решение системы
    bool showParticularSolution();
    /// вывести на экран частное решение системы с n-й переменной равной n(нужно для базиса)
    void showParticularSolution(int n);
    ///вывести базисное решение
    void showBasis();
    /// получить ранг матрицы
    int getRank();
private:
    /// приведена ли матрица к трекгольному виду
    bool triangled;
    /// найдено ли решение или нет
    bool solution;
    double **matrix;
    ///помогает считать, хранит текущий индекс скачков
    int *where;
    int countOfRows, countOfColumns;
    double *particularSolution;
    /// записывает частное решение в particularSolution
    /// возвращает 0, если нет решений
    /// 1, если оно одно, и INF если их беск много
    ///
    int getParticularSolution();

    void getParticularSolution(int n);

};

