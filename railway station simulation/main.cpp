#include <iostream>
#include <thread>
#include <mutex>
#include <string>

std::mutex station;

class Train {
private:
    char type;
    int arrivalTime;
public:
    Train (char inType, int inArrivalTime) {
        type=inType;
        arrivalTime=inArrivalTime;
    }
    friend void trainTravel(Train *train);
};

void trainTravel(Train *train) {
    std::string command;
    std::this_thread::sleep_for(std::chrono::seconds(train->arrivalTime));
    station.lock();
    std::cout << "The train " << train->type << " arrived at the railway station" << std::endl;
    std::cout<<"enter the command"<<std::endl;
    std::cin>>command;
    while (command!="depart" && command!="Depart") {
        std::cout << "enter the command" << std::endl;
        std::cin >> command;
    }
    if (command=="depart" || command=="Depart") {
        std::cout << "The train " << train->type << " departed from the railway station" << std::endl;
        station.unlock();
    }
}


int main() {
    Train** train;
    train = new Train*[3];
    int trainArrivalTime;
    std::string command;
    std::cout << "Enter the arrival time for train A (in seconds):" << std::endl;
    std::cin>>trainArrivalTime;
    train[0]= new Train('A',trainArrivalTime);
    std::cout << "Enter the arrival time for train B (in seconds):" << std::endl;
    std::cin>>trainArrivalTime;
    train[1]= new Train('B',trainArrivalTime);
    std::cout << "Enter the arrival time for train C (in seconds):" << std::endl;
    std::cin>>trainArrivalTime;
    train[2]= new Train('C',trainArrivalTime);
    std::thread train1(trainTravel,train[0]);
    std::thread train2(trainTravel,train[1]);
    std::thread train3(trainTravel,train[2]);
    train1.join();
    train2.join();
    train3.join();
    return 0;
}
