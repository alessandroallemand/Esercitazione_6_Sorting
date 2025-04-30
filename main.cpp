#include <cmath> // contiene floor
#include <iostream>
#include <numeric> // contiene iota
#include <sstream>
#include <chrono> // https://en.cppreference.com/w/cpp/chrono

#include "SortingAlgorithm.hpp"
using namespace std;

template<typename T>
string ArrayToString(const vector<T>& v)
{
    string str;
    ostringstream toString;
    toString << "[ ";
    for (const T& e: v)
        toString << e << " ";
    toString << "]";

    return toString.str();
}

struct ClassObj{
    double value;

};

inline bool operator< (const ClassObj& a, const ClassObj& b) { return a.value < b.value; }

int main(int argc, char *argv[])
{
    size_t m = 10;

    if(argc > 1)
    {
        istringstream convert(argv[1]);
        convert >> m;
        cout << "use value: "  << m << endl;
    }
    else
        // Se non sono stati passati argomenti, stampa il valore di defaul(m=10)
        cerr << "use default value: "  << m << endl;

    //Vettore ordinato di int compresi tra -4 e m-4
    vector<int> v1(m);
    std::iota(v1.begin(), v1.end(), -4);

    cout << "v1: " << endl;
    cout << ArrayToString(v1) << endl;

    /*creo un vettore non ordinato (randomico) che va da 0 a 1*/
    vector<double> v2(m);
    for(size_t i = 0; i < m; i++)
        v2[i] = rand() / ((double)RAND_MAX);

    cout << "v2: " << endl;
    cout << ArrayToString(v2) << endl;

    /*attraverso questo codice mi creo un vettore misto, ordinato per metà e randomico per l'altra metà*/
    vector<int> v3(m, 0);
    for(size_t i = floor(m * 0.5) + 1; i < m; i++)
        v3[i] = rand() % 1000;
    copy(v1.begin(), v1.begin() + floor(m * 0.5) + 1, v3.begin());

    cout << "v3: " << endl;
    cout << ArrayToString(v3) << endl;

    unsigned int num_experiment = 100;

    /*faccio una media (su 100 campioni) del tempo che ci mette l'algoritmo Bubblesort ad ordinare il vettore ordinato v1*/
    double time_elapsed_Bubble_v1 = 0.0;
    for(unsigned int t = 0; t < num_experiment; t++)
    {
        vector<int> v(v1);

        std::chrono::steady_clock::time_point start_time = std::chrono::steady_clock::now();
        SortLibrary::BubbleSort<int>(v);
        std::chrono::steady_clock::time_point end_time = std::chrono::steady_clock::now();
        time_elapsed_Bubble_v1 += std::chrono::duration_cast<std::chrono::microseconds>(end_time - start_time).count();
    }
    time_elapsed_Bubble_v1 /= num_experiment;

    cout << " BubbleSort - v1: " << time_elapsed_Bubble_v1 << endl;

    /*faccio una media (su 100 campioni) del tempo che ci mette l'algoritmo Bubblesort ad ordinare il vettore ordinato v2*/
    double time_elapsed_Bubble_v2 = 0.0;
    for(unsigned int t = 0; t < num_experiment; t++)
    {
        vector<double> v(v2);

        std::chrono::steady_clock::time_point start_time = std::chrono::steady_clock::now();
        SortLibrary::BubbleSort<double>(v);
        std::chrono::steady_clock::time_point end_time = std::chrono::steady_clock::now();
        time_elapsed_Bubble_v2 += std::chrono::duration_cast<std::chrono::microseconds>(end_time - start_time).count();
    }
    time_elapsed_Bubble_v2 /= num_experiment;

    cout << "BubbleSort - v2: " << time_elapsed_Bubble_v2 << endl;

    /*faccio una media (su 100 campioni) del tempo che ci mette l'algoritmo Bubblesort ad ordinare il vettore ordinato v3*/
    double time_elapsed_Bubble_v3 = 0.0;
    for(unsigned int t = 0; t < num_experiment; t++)
    {
        vector<int> v(v3);

        std::chrono::steady_clock::time_point start_time = std::chrono::steady_clock::now();
        SortLibrary::BubbleSort<int>(v);
        std::chrono::steady_clock::time_point end_time = std::chrono::steady_clock::now();
        time_elapsed_Bubble_v3 += std::chrono::duration_cast<std::chrono::microseconds>(end_time - start_time).count();
    }
    time_elapsed_Bubble_v3 /= num_experiment;

    cout << " BubbleSort - v3: " << time_elapsed_Bubble_v3 << endl;

    /*faccio una media (su 100 campioni) del tempo che ci mette l'algoritmo Heapsort ad ordinare il vettore ordinato v1*/
    double time_elapsed_Heap_v1 = 0.0;
    for(unsigned int t = 0; t < num_experiment; t++)
    {
        vector<int> v(v1);

        std::chrono::steady_clock::time_point start_time = std::chrono::steady_clock::now();
        SortLibrary::HeapSort<int>(v);
        std::chrono::steady_clock::time_point end_time = std::chrono::steady_clock::now();
        time_elapsed_Heap_v1 += std::chrono::duration_cast<std::chrono::microseconds>(end_time - start_time).count();
    }
    time_elapsed_Heap_v1 /= num_experiment;

    cout << "HeapSort - v1: " << time_elapsed_Heap_v1 << endl;

    /*faccio una media (su 100 campioni) del tempo che ci mette l'algoritmo Heapsort ad ordinare il vettore ordinato v2*/
    double time_elapsed_Heap_v2 = 0.0;
    for(unsigned int t = 0; t < num_experiment; t++)
    {
        vector<double> v(v2);

        std::chrono::steady_clock::time_point start_time = std::chrono::steady_clock::now();
        SortLibrary::HeapSort<double>(v);
        std::chrono::steady_clock::time_point end_time = std::chrono::steady_clock::now();
        time_elapsed_Heap_v2 += std::chrono::duration_cast<std::chrono::microseconds>(end_time - start_time).count();
    }
    time_elapsed_Heap_v2 /= num_experiment;

    cout << " HeapSort - v2: " << time_elapsed_Heap_v2 << endl;


    /*faccio una media (su 100 campioni) del tempo che ci mette l'algoritmo Heapsort ad ordinare il vettore ordinato v3*/
    double time_elapsed_heap_v3 = 0.0;
    for(unsigned int t = 0; t < num_experiment; t++)
    {
        vector<int> v(v3);

        std::chrono::steady_clock::time_point start_time = std::chrono::steady_clock::now();
        SortLibrary::HeapSort<int>(v);
        std::chrono::steady_clock::time_point end_time = std::chrono::steady_clock::now();
        time_elapsed_heap_v3 += std::chrono::duration_cast<std::chrono::microseconds>(end_time - start_time).count();
    }
    time_elapsed_heap_v3 /= num_experiment;

    cout << " HeapSort - v3: " << time_elapsed_heap_v3 << endl;


    return 0;
}