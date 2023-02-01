#include <iostream>

int main() {
  int n;
  std::string s;
  std::cout<<"Input a number:\n";
  std::cin>>n;
  while (n<0 || n>3999) {
    std::cout<<"Wrong input, try again:\n";
    std::cin>>n;
  }
  int t=n/1000;   //Кол-во тысяч
  for (int i=0; i<t; i++)
    s+='M';
  n=n%1000;
  int h=n/100; //кол-во сотен
   if (h==4)
     s=s+'C'+'D';
   else if (h==9)
     s=s+'C'+'M';
   else if (h>=1 && h<=3)
    for (int i=0; i<h; i++)
     s+='C';
   else if (h>=5 && h<9) {
    s+='D';
    for (int i=5; i<h; i++)
     s+='C';
   }
   n=n%100;
   int d=n/10;  // кол-во десятков
   if (d==4)
    s=s+'X'+'L';
   else if (d==9)
    s=s+'X'+'C';
   else if (d>=1 && d<=3)
    for (int i=0; i<d; i++)
     s+='X';
   else if (d>=5 && d<9) {
    s+='L';
    for (int i=5; i<d; i++)
     s+='X';
   }
   n=n%10;      //кол-во единиц
   if (n==4)
    s=s+'I'+'V';
   else if (n==9)
    s=s+'I'+'X';
   else if (n>=1 && n<=3)
    for (int i=0; i<n; i++)
     s+='I';
   else if (n>=5 && n<9) {
    s+='V';
    for (int i=5; i<n; i++)
     s+='I';
   }
  std::cout<<s;
}