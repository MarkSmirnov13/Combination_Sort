#include <iostream>
#include <vector>
#include <fstream>

using namespace std;
template <typename T> // declare new template T


/**
 *
 * @tparam T
 * @param array
 */
void Comb(vector<T> &array)
{
    double fakt = 1.2473309; // factor of decreasing
    double step = array.size() - 1; // the step of sort

    while (step >= 1) // while there is more than 1 in difference between two indexes
    {
        for (int i = 0; i + step < array.size(); ++i) // looking for bad pairs
            if (array[i] > array[i + step]) // if pair is not in correct order
                swap(array[i], array[i + step]); // swap that bad pair
        step /= fakt; // count the step using the rule of sort
    }

    // if there is only 1 in difference between two indexes -> start bubble sort
    for (int i = 0; i < array.size() - 1; i++) // looking for bad pairs
    {
        bool swapped = false; // if array is in correct order
        for (int j = 0; j < array.size() - i - 1; j++) // looking for bad pairs
            if (array[j] > array[j + 1]) // if pair is not in correct order
            {
                swap(array[j], array[j + 1]); // swap that bad pair
                swapped = true; // array is in correct order
            }

        if (!swapped) // if array is in correct order
            break; // go to main
    }
}

int main()
{
    ifstream Fin("input.txt"); // declare and open input File
    vector<string> array; // declare vector
    unsigned long a; // declare number of elements
    long t; // declare the time parameter

    t = clock(); // set timer

    Fin >> a; // read number "a" from the input File

    array.resize(a); // resize array to correct size

    for (int i = 0; i < a; i++) // read the array to vector from the input File
        Fin >> array[i];
    Fin.close(); // close input File

    Comb(array); // sort the array

    t = clock() - t; // count the time of sort

    ofstream Fout("output.txt"); // declare and open output File

    for (int i = 0; i < a; i++) // write the array in correct order
        Fout << array[i] << endl;

    Fout << t << "ms"<< endl; // write the sort time

    Fout.close();// close output File

    return 0;
}
