#include <iostream>
#include <string>


std::string seriesSum(int n)
{
    if (n == 0) { return "0.00"; }

    int x = 0;
    for (int i = 1; i <= n; ++i)
    {
        x = 1 / (3 * n - 2);
    }
    return std::to_string(x);
}


int main()
{
    std::string str = seriesSum(5);
    std::cout << str << '\n';
    std::cout << "hell\n";
    return 0;
}
