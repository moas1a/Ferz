
#include <iostream>
#include <cassert>
using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");
    //создаем двумерный массив 8 на 8
    char d[8][8];
    for (int i = 0; i < 8; ++i) //строка
        for (int j = 0; j < 8; ++j)//столбец
            d[i][j] = '.';
    int a, b; 
    //cчитываем a и b
    std::cout << "Введите первое число: ";
    cin >> a;

    std::cout << "Введите второе число: ";
    cin >> b;

    unsigned int start_time = clock(); // берем текущее время
    --a; --b; // вычитаем из a и b единицу
    assert(a >= 0 && a < 8 && b >= 0 && b < 8); //создаем условие

    for (int i = 0; i < 8; ++i)
        for (int j = 0; j < 8; ++j)
            if (abs(i - a) == abs(j - b) || i == a || j == b) d[i][j] = '*'; //проверяем, являются ли i и j координатами, которые находятся на одной диагонали с a и b   и получаем абсолютное значение разности   i - a и j - b.
                                                                             // || i == a || j == b - проверяет, находится ли i на той же горизонтали или вертикали с a и b. Если хотя бы одно из этих условий истинно, то в элементе массива d с индексами [i][j] записывается символ *
    d[a][b] = 'Q'; //Q=ферзь

    for (int i = 0; i < 8; ++i)
    {
        for (int j = 0; j < 8; ++j)
            cout << d[i][j] << " "; 
        cout << endl;
    }
    unsigned int end_time = clock(); // записываем конечное время
    unsigned int search_time = end_time - start_time; // искомое время
    std::cout << "runtime = " << search_time / 1000.0 << std::endl; // время работы программы
}
