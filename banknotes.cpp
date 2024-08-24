// In this problem you have to read an integer value and calculate the 
// smallest possible number of banknotes in which the value may be 
// decomposed. The possible banknotes are 100, 50, 20, 10, 5, 2 and 1. 
// Print the read value and the list of banknotes.

// Input
// The input file contains an integer value N (0 < N < 1000000).

// Output
// Print the read number and the minimum quantity of each necessary 
// banknotes in Portuguese language, as the given example. Do not 
// forget to print the end of line after each line, otherwise you 
// will receive “Presentation Error”.

#include <iostream>

int main() {
    int N;
    std::cin >> N;
    std::cout << N << std::endl;
    std::cout << N / 100 << " nota(s) de R$ 100,00" << std::endl;
    N %= 100;
    std::cout << N / 50 << " nota(s) de R$ 50,00" << std::endl;
    N %= 50;
    std::cout << N / 20 << " nota(s) de R$ 20,00" << std::endl;
    N %= 20;
    std::cout << N / 10 << " nota(s) de R$ 10,00" << std::endl;
    N %= 10;
    std::cout << N / 5 << " nota(s) de R$ 5,00" << std::endl;
    N %= 5;
    std::cout << N / 2 << " nota(s) de R$ 2,00" << std::endl;
    N %= 2;
    std::cout << N / 1 << " nota(s) de R$ 1,00" << std::endl;
    return 0;
}