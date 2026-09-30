//
//  main.cpp
//  MyTool
//
//  Created by Omar Asiri on 19/04/1448 AH.
//

#include <iostream>
#include <string>
#include <cctype>

using namespace std;

string numbertobinaray(int number){
    string binary;
    
    for (int i = 4; i >= 0; i--)
        binary += ((number >> i ) & 1) ? '1' : '0';
    
    return binary;
}

int binaryToNumber(string binary){
    int number = 0;
    
    for (char bit : binary)
        number = number * 2 + (bit - '0');
    
    return number;
}

string encode(string text){
    string result;
    
    for (char c : text){
        c = toupper(c);
        
        int number;
        
        if (c >= 'A' && c <= 'Z')
            number = c - 'A' +1;
        
        else if (c == ' ')
            number = 27;
        
        else if (c == '.')
            number = 28;
        
        else continue;
        
        result += numbertobinaray(number);
    }
    return result;
}

string decode(string binary){
    string result;
    
    for (size_t i = 0; i < binary.length(); i += 5){
        string chunk = binary.substr(i, 5);
        
        int number = binaryToNumber(chunk);
        
        if (number >= 1 && number <= 26)
            result += char('A' + number - 1);
        
        else if (number == 27)
            result += ' ';
        else if (number == 28)
            result += '.';
    }
    return result;
}

int main(){
    string text;
    
    cout << "Enter Text: ";
    getline(cin, text);
    
    string binary = encode(text);
    
    cout << "\nBinary:\n";
    cout << binary << '\n';
    
    cout << "\nDecode:\n";
    cout << decode(binary) << '\n';
    
    return 0;
}
