'''C++  

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

'''

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


int main()
{

    string s = "abc";
    cout<<s<<endl;
    
    s += "1";
    cout<<s<<endl;// abc1
    
    s += '2';
    cout<<s<<endl;// abc12
    
    s.push_back('3'); // push_back can only accept char
    cout<<s<<endl;// abc123
    
    s.append("4"); // append can only accept string directly
    cout<<s<<endl;// abc1234
    
    s.append(1, '5'); // but append can accept char in this way, means append one of 5 in the end
    cout<<s<<endl; // abc12345
    
    s.append(s, 2, 5);// append 
    cout<<s<<endl; // abc12345c1234
    
    return 0;
}


int main()
{

    std::string str = "12345";
    std::string substr = "34";
    
    size_t idxFind = str.find('2');
    cout<<idxFind<<endl;// 1
    
    size_t pos = str.find(substr);
    cout<<pos<<endl; // 2
    
    // If substr found, erase it from str
    if (pos != std::string::npos) {
        str.erase(pos, substr.length());
    }
    cout<<str<<endl; // 125
    
    // delete from position untill npos
    str.erase(1, std::string::npos);
    cout<<str<<endl; // 1
    
    str = "abc";
    str.erase();
    cout<<str<<endl; // ""
    
    return 0;
}
