#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    ifstream input;
    input.open("aplusb.in");
    int a, b;
    input >> a >> b;
    input.close();

    ofstream output;
    output.open("aplusb.out");
    output << a+b;
    output.close(); 
    return 0;
}