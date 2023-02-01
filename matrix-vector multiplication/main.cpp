#include <iostream>

int main() {
    int a[4][4];
    int b[4][4];
    std::cout<<"Enter the elements of the first matrix:"<<std::endl;  //ввод матриц
    for (int i=0; i<4; i++)
        for (int j=0; j<4; j++)
            std::cin>>a[i][j];
    std::cout<<"Enter the elements of the second matrix:"<<std::endl;
    for (int i=0; i<4; i++)
        for (int j=0; j<4; j++)
            std::cin>>b[i][j];
    bool equal = true;                  //сравнение матриц
    int i=0;
    while (equal==true && i<4) {
        for (int j = 0; j < 4; j++)
            if (a[i][j]!=b[i][j]) {
                equal=false;
                break;
            }
        i++;
    }
    if (equal)
        std::cout<<"The matrices are equal";
    else
        std::cout<<"The matrices are different";
    return 0;
}
