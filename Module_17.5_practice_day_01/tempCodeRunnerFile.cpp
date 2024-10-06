#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> numbers;  // To store the input numbers
    int num;
    
    // Keep reading until there is no valid input (EOF or invalid data)
    while (cin >> num) {
        numbers.push_back(num);  // Store the number
    }

    // Output the numbers (optional, just for verification)
    cout << "You entered: ";
    for (int n : numbers) {
        cout << n << " ";
    }

    return 0;
}
