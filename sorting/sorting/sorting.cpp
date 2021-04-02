#include <iostream>
#include <chrono>
using namespace std;
void sort_by_choice(int* a, int n) // сортировка выбором
{
    for (int i = 0;i < n-1;++i)
    {
        int min = i;
        for (int j = i + 1;j < n;++j)
            if (a[j] < a[min])
                min = j;
        int m = a[i];
        a[i] = a[min];
        a[min] = m;
    }
}

void hoare_sorting(int* a,int first, int last) // сортировка хоара
{
    int l = first, r = last, base = a[(l + r)/2];
    while (l <= r)
    {
        while (a[l] < base)
            ++l;
        while (a[r] > base)
            --r;
        if (l < r)
        {
            int curr = a[l];
            a[l] = a[r];
            a[r] = curr;
        }
        if (l <= r)  // это условие нужно на случай, если опорный эл-нт попадает в один из боковых массивов
        {
            ++l;
            --r;
        }
    }

    if (l < last)
        hoare_sorting(a, l, last);
    if (r > first)
        hoare_sorting(a, first, r);
}

void time_sort_by_choice(int n) // removing the dependence of the selection sorting execution time on the number of elements in the array
{
    FILE* fout;
    char   c = '\n';
    char m[] = "N - Time";
    fopen_s(&fout, "output_sort_by_choice.txt", "w");
    fprintf(fout, "%s", m);
    fprintf(fout, "%c", c);
    for (int i = 0;i < n;++i)
    {
        int* a = (int*)malloc(i * sizeof(int));
        for (int j = 0;j < i;++j)
        {
            a[j] = rand();
        }   
        auto start = chrono::high_resolution_clock::now();
        sort_by_choice(a, i);
        auto end = chrono::high_resolution_clock::now();
        chrono::duration<float> diff = end - start;
        char   s[] = "-";
        fprintf(fout, "%i", i);
        fprintf(fout, "%s", s);
        fprintf(fout, "%i", int(diff.count() * 1000000000));
        fprintf(fout, "%c", c);
        free(a);
    }

}

void time_hoare_sorting(int n) // removing the dependence of the Hoare sorting execution time on the number of elements in the array
{
    FILE* fout;
    char   c = '\n';
    char m[] = "N - Time";
    fopen_s(&fout, "output_hoare_sorting.txt", "w");
    fprintf(fout, "%s", m);
    fprintf(fout, "%c", c);
    for (int i = 0;i < n;++i)
    {
        int* a = (int*)malloc(i * sizeof(int));
        for (int j = 0;j < i;++j)
        {
            a[j] = rand();
        }
        auto start = chrono::high_resolution_clock::now();
        hoare_sorting(a, 0,i-1);
        auto end = chrono::high_resolution_clock::now();
        chrono::duration<float> diff = end - start;
        char   s[] = "-";
        fprintf(fout, "%i", i);
        fprintf(fout, "%s", s);
        fprintf(fout, "%i", int(diff.count() * 1000000000));
        fprintf(fout, "%c", c);
        free(a);
    }

}

int main()
{
    int n, c;
    cout << " max n" << endl;
    cin >> n;
    cout << " what kind of sorting do you want:" << endl << "1 - sort_by_choice" << endl << "2 - hoare_sorting" << endl;
    cin >> c;
    if (c == 1)
        time_sort_by_choice(n);
    if (c == 2)
        time_hoare_sorting(n);
    
    return 0;
}