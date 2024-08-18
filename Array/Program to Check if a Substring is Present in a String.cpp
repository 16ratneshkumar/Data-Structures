// Program to Check if a Substring is Present in a String


//==============================================
//  Interactive Programs (Input-Based)
//==============================================

//==============================================
// Start
//==============================================
#include <iostream>
#include <cstring>

std::string isSubstring(char str[], char sub[]) {
    int lenStr = strlen(str);
    int lenSub = strlen(sub);
    for (int i = 0; i <= lenStr - lenSub; i++) {
        int j;
        for (j = 0; j < lenSub; j++) {
            if (str[i + j] != sub[j]) {
                break;
            }
        }
        if (j == lenSub) {
            return "The substring is present in the string";
        }
    }
    return "The substring is not present in the string.";
}

int main() {
    char str[100], sub[100];
    std::cout << "Enter the main string: ";
    std::cin.getline(str, 100);
    std::cout << "Enter the substring: ";
    std::cin.getline(sub, 100);
    std::cout<<isSubstring(str, sub)<<std::endl;
    return 0;
}
//==============================================
// End
//==============================================




//==============================================
//  Non-Interactive Programs (No Input) 
//==============================================

//==============================================
// Start
//==============================================
#include <iostream>
#include <cstring>

std::string isSubstring(char str[], char sub[]) {
    int lenStr = strlen(str);
    int lenSub = strlen(sub);
    for (int i = 0; i <= lenStr - lenSub; i++) {
        int j;
        for (j = 0; j < lenSub; j++) {
            if (str[i + j] != sub[j]) {
                break;
            }
        }
        if (j == lenSub) {
            return "The substring is present in the string.";
        }
    }
    return "The substring is not present in the string.";
}

int main() {
    char str[]="Ratnesh Kumar";
    char sub[]="umar";
    std::cout<<isSubstring(str, sub)<<std::endl;
    return 0;
}
//==============================================
// End
//==============================================
