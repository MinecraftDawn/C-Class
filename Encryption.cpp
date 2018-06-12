#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
    string fn = "mojang.jpg";
    string fn2 = "mojang2.jpg";
    string fn3 = "mojang3.jpg";

    ifstream inFile(fn,ios::binary);
    ofstream outFile(fn2,ios::binary | ios::app);
    ifstream inFile2(fn2,ios::binary);
    ofstream outFile2(fn3,ios::binary | ios::app);


    char c;

    while(!inFile.get(c).eof()){
        outFile << char(c^0xFF);
    }
        outFile.close();

    while(!inFile2.get(c).eof()){
        outFile2 << char(c^0xFF);
    }
        outFile2.close();

    return 0;
}