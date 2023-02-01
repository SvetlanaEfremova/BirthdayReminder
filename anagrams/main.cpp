#include <iostream>
#include <string>
#include <map>

bool is_anagram(std::string str1, std::string str2) {
    std::map <std::string,char> map1,map2;
    for (int i=0; i<str1.length(); i++)
        map1.insert(std::pair<std::string,char>(str1[i]+std::to_string(i),str1[i]));
    for (int i=0; i<str2.length(); i++)
        map2.insert(std::pair<std::string,char>(str2[i]+std::to_string(i),str2[i]));
    int i=0;
    for (std::map<std::string,char>::iterator it=map1.begin(); it!=map1.end(); it++) {
        str1[i]=it->second;
        i++;
    }
    i=0;
    for (std::map<std::string ,char>::iterator it=map2.begin(); it!=map2.end(); it++) {
        str2[i]=it->second;
        i++;
    }
    if (str1==str2) return true;
    else
        return false;
}

int main() {
    std::string str1,str2;
    std::cout<<"Enter the first string"<<std::endl;
    std::getline(std::cin,str1);
    std::cout<<"Enter the second string"<<std::endl;
    std::getline(std::cin,str2);
    if (is_anagram(str1,str2))
        std::cout<<"The strings are anagrams";
    else
        std::cout<<"The strings are not anagrams";
    return 0;
}
