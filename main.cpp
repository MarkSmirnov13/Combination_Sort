#include <iostream>
#include <vector>
#include <fstream>

using namespace std;
template <typename T>
void comb(vector<T> &sort)
{
    int n = 0; // количество перестановок
    double fakt = 1.2473309; // фактор уменьшения
    double step = sort.size() - 1;

    while (step >= 1)
    {
        for (int i = 0; i + step < sort.size(); ++i)
        {
            if (sort[i] > sort[i + step])
            {
                swap(sort[i], sort[i + step]);
                n++;
            }
        }
        step /= fakt;
    }
    // сортировка пузырьком
    for (int i = 0; i < sort.size() - 1; i++)
    {
        bool swapped = false;
        for (int j = 0; j < sort.size() - i - 1; j++)
        {
            if (sort[j] > sort[j + 1]) {
                swap(sort[j], sort[j + 1]);
                swapped = true;
                ++n;
            }
        }

        if (!swapped)
            break;
    }
}

int main()
{
    ifstream Fin("input.txt");
    vector<string> sort;
    int a;
    long t;
    t = clock();

    Fin >> a;

    sort.resize(a);

    for (int i = 0; i < a; i++)
        Fin >> sort[i];
    Fin.close();

    comb(sort);

    t = clock() - t;
    ofstream Fout("output.txt");
    for (int i = 0; i < a; i++)
        Fout << sort[i] << endl;

    Fout << t << "ms"<< endl;

    Fout.close();
    return 0;
}