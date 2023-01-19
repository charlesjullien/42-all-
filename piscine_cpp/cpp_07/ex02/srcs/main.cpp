#include "../includes/Array.hpp"
#define SIZE 10
int main()
{
    int i;
    int val;

    i = 0;
    Array<int> tab(SIZE);

    int *other_tab = new int[SIZE];

    std::srand(std::time(NULL));

    while (i < SIZE)
    {
        val = rand();
        tab[i] = val;
        other_tab[i] = val;
        i++;
    }
    i = 0;

    Array<int> tmp = tab;
    Array<int> test(tmp);

    while (i < SIZE)
    {
        if (tab[i] != other_tab[i] || tmp[i] != test[i])
        {
            std::cerr << "Wrong copy or assignation" << std::endl;
            return (1);
        }
        i++;
    }
    i = 0;

    try
    {
        std::cout << tab[9] << std::endl;
        std::cout << test[9] << std::endl;
        std::cout << tab[28] << std::endl;// tab[28] est out of range... exception 
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }

    try
    {
        tab[SIZE] = 0;
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }

    delete[] other_tab;

    return (0);
}