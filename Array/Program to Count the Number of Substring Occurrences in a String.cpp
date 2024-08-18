// Program to Count the Number of Substring Occurrences in a String


////==============================================
//  Interactive Programs (Input-Based)
//==============================================

//==============================================
// Start
//==============================================
#include <iostream>
#include <cstring>

int countOccurrences(char str[], char sub[]) {
    int lenStr = strlen(str);
    int lenSub = strlen(sub);
    int num=0;
    for (int i = 0; i <= lenStr - lenSub; i++) {
        int j;
        for (j = 0; j < lenSub; j++) {
            if (str[i + j] != sub[j]) {
                break;
            }
            num++;
        }
    }
    return num/lenSub;
}

int main() {
    char str[100], sub[100];
    std::cout << "Enter the main string: ";
    std::cin.getline(str, 100);
    std::cout << "Enter the substring: ";
    std::cin.getline(sub, 100);
    std::cout << "The substring occurs " << countOccurrences(str, sub)<< " times in the string." << std::endl;
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

int countOccurrences(char str[], char sub[]) {
    int lenStr = strlen(str);
    int lenSub = strlen(sub);
    int num=0;
    for (int i = 0; i <= lenStr - lenSub; i++) {
        int j;
        for (j = 0; j < lenSub; j++) {
            if (str[i + j] != sub[j]) {
                break;
            }
            num++;
        }
    }
    return num/lenSub;
}

int main() {
    char str[]="Ratnesh Kumar";
    char sub[]="at";
    std::cout << "The substring occurs " << countOccurrences(str, sub)<< " times in the string." << std::endl;
    return 0;
}
//==============================================
// End
//==============================================
