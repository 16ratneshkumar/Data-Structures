// Program to Compare Two Arrays for Equality


//==============================================
//  Interactive Programs (Input-Based)
//==============================================

//==============================================
// Start
//==============================================
#include <iostream>
std::string compare(int arr1[], int arr2[], int size) {
    for (int i = 0; i < size; i++) {
        if (arr1[i] != arr2[i]) {
            return "Arrays are not equal";
        }
    }
    return "Arrays are equal";
}

int main() {
    int size;
    std::cout << "Enter Size of Array:: ";
    std::cin >> size;
    int arr1[size], arr2[size];
    std::cout << "Enter Elements of First Array:: " << std::endl;
    for (int i = 0; i < size; i++) {std::cin >> arr1[i];}
    std::cout << "Enter Elements of Second Array:: " << std::endl;
    for (int i = 0; i < size; i++) {std::cin >> arr2[i];}
    std::cout << compare(arr1, arr2, size) << std::endl;
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
std::string compare(int arr1[], int arr2[]) {
    for (int i = 0; i < 5; i++) {
        if (arr1[i] != arr2[i]) {
            return "Arrays are not equal";
        }
    }
    return "Arrays are equal";
}

int main() {
    // Test case 1
    int arr1[5] = {1, 2, 3, 4, 5};
    int arr2[5] = {1, 2, 3, 4, 5};
    std::cout << compare(arr1, arr2) << std::endl;

    // Test case 2
    int arr3[5] = {1, 2, 3, 4, 5};
    int arr4[5] = {1, 2, 3, 4, 6};
    std::cout << compare(arr3, arr4) << std::endl;
    return 0;
}
//==============================================
// End
//==============================================