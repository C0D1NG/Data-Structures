#include <iostream>
#include <numeric>
 
int main()
{
    int arr[] = { 5, 3, 7, 9, 2 };
 
    int sum = std::accumulate(std::begin(arr), std::end(arr), 0, std::plus<int>());
    std::cout << sum;
 
    return 0;
}
