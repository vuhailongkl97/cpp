#include <iostream>
using namespace std;


/*
 * print out format \127 mean get value in ascii with 127 in octal
 */

void print_out(void)
{
    cout << "Who goes with F\127rgus?\012" << endl;
}


int main(void)
{
    print_out();

    char a = 'A';
    char b = L'A';

    return 0;
}
