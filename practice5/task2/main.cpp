#include <iostream>

template <typename T, int n>
int check_index(T (&arr)[n], int a)
{
    try
    {
        if(a>=n) throw 1;
        else if (a<0) throw 0;
        return a;
    }
    catch (const int err)
    {
        if(err) return 0;
        else return n-1;
    }
}

int main()
{
    int arr[10];
    for(int i = 0; i < 10; i++)
    {
        arr[i] = i;
    }
    std::cout << arr[check_index(arr, 5)] << "\n";
    std::cout << arr[check_index(arr, -20)] << "\n";
    std::cout << arr[check_index(arr, 20)] << "\n";
}