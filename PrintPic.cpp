#include <iostream>
#include <vector>
using namespace std;

// Function to print a vector of strings in reverse order
void printPictureBackwards(const vector<string>& picture) {
    for (int i = picture.size() - 1; i >= 0; --i) {
        cout << picture[i] << endl;
    }
}

int main() {
    
    printPictureBackwards(picture);

    return 0;
}
