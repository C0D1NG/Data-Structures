#include <iostream>
#include <algorithm>

bool MyFn(int i, int j) { return i < j; }

struct MyClass {
    bool operator()(int i, int j) { return i < j; }
} MyObj;

int main()
{
    int my_ints[] = { 3, 42, 21, 50, 69, 12, 9 };

    // Default comparison:
    std::cout << "The largest element is " << *std::max_element(my_ints, my_ints + 7) << '\n';

    // using function MyFn as comparison:
    std::cout << "The largest element is " << *std::max_element(my_ints, my_ints + 7, MyFn) << '\n';

    // using object MyObj as comparison:
    std::cout << "The largest element is " << *std::max_element(my_ints, my_ints + 7, MyObj) << '\n';

    return 0;
}
