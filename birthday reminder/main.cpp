#include <iostream>
#include <string>
#include <ctime>
#include <iomanip>
#include <vector>

struct friendData
{
    std::string name;
    std::tm birthDate;
};


int main() {
    std::string operation;
    std::cout<<"Enter the name of a friend or end"<<std::endl;
    std::cin>>operation;
    std::vector<friendData> friends;
    while (operation!="end" && operation!="End") {
        friendData friendInfo;
        friendInfo.name=operation;
        std::time_t t=std::time(nullptr);
        std::tm birthDate=*std::localtime(&t);
        std::cout<<"Enter the friend's birth day in YYYY/MM/DD format"<<std::endl;
        std::cin>>std::get_time(&birthDate,"%Y/%m/%d");\
        friendInfo.birthDate=birthDate;
        friends.push_back(friendInfo);
        std::cout<<"Enter the name of a friend or end"<<std::endl;
        std::cin>>operation;
    }
    std::time_t t=std::time(nullptr);
    std::tm today=*std::localtime(&t);      //задаём текущую дату
    int minMonthDifference=11;
    int minDayDifference=30;
    for (int i=0; i<friends.size(); i++) {
        if ((friends[i].birthDate.tm_mon-today.tm_mon>0 || friends[i].birthDate.tm_mon-today.tm_mon==0 && friends[i].birthDate.tm_mday-today.tm_mday>=0)
             && (friends[i].birthDate.tm_mon-today.tm_mon<minMonthDifference || friends[i].birthDate.tm_mon-today.tm_mon==minMonthDifference && friends[i].birthDate.tm_mday-today.tm_mday<minDayDifference)) {
            minMonthDifference=friends[i].birthDate.tm_mon-today.tm_mon;
            minDayDifference=friends[i].birthDate.tm_mday-today.tm_mday;
        }
    }
    for (int i=0; i<friends.size(); i++) {
        if (friends[i].birthDate.tm_mon-today.tm_mon==minMonthDifference && friends[i].birthDate.tm_mday-today.tm_mday==minDayDifference)
            if (minMonthDifference==0 && minDayDifference==0)
                std::cout<<"Today is "<<friends[i].name<<"'s birthday!"<<std::endl;
            else
              std::cout<<"The closest birthday is "<<friends[i].name<<"'s: "<<friends[i].birthDate.tm_mon+1<<"/"<<friends[i].birthDate.tm_mday<<std::endl;
    }
    return 0;
}
