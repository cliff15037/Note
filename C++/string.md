#include <iostream>
#include <sstream>
#include <string>

using namespace std;
// Driver Code
int main()
{   
    string s("Hello World!");
    cout<< s <<endl; // "Hello World!"
    
    
    s.erase(s.begin() + 4);  // Deletes character at position 4
    cout<< s <<endl; // "Hell World!"
    
    s.erase(s.begin() + 0, s.end() - 6);// Deletes all characters between 0th index and s.end() - 6
    cout<< s <<endl; // "World!"
    
    s.erase(1); // Deletes all characters except first one
    cout<< s <<endl; // H
    
    // Input string
    string str("1, 2, 3");
 
    // Object class of istringstream
    istringstream my_stream(str);
 
    // Variable to store the number n
    // and character ch
    char c;
    int n;
 
    // Traverse till input stream is valid
    while (my_stream >> n >> c) {
 
        cout << "That stream was successful: "
             << n << " :: " << c << "\n"; // n print number, c print ',' then, go to space so stop
    }
    cout << "The stream has failed."
         << "\n";
    
    /*
        rfind is used to find the first position of a char in reverse order, start from the end to the begin.
        string::nops is a return value as not found
        find is used to find the first position from begin
    */
    s = "hello world";
    size_t pos = s.rfind('l');
    if (pos != string::npos) { 
        cout << "Last 'l' found at position: " << pos << endl; // 9
    } else {
        cout << "Character not found." << endl;
    }
    
    pos = s.find('l');
    if (pos != std::string::npos) {
        cout << "First 'l' found at position: " << pos << endl; // 2
    } else {
        cout << "Character not found." << endl;
    }
    
    return 0;
}


/*
    istringstream use space as delimeter in default, but we can indicate it by ourselves using getline
*/
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;
int main() {
    string str = "apple/orange/banana";
    istringstream ss(str);
    string token;
    
    while (getline(ss, token, '/')) {
        // getline will put the string into token
        cout << token << endl;
    }
    return 0;
}





