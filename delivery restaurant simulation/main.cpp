#include <iostream>
#include <thread>
#include <mutex>
#include <string>


std::mutex take_order;
std::mutex kitchen_access;

void makeOrder() {
    std::string order[5]={"pizza","soup","steak","salad","sushi"};
    take_order.lock();
    std::srand(std::time(nullptr));
    int orderTime = rand()%6+5;
    std::this_thread::sleep_for(std::chrono::seconds (orderTime));
    std::cout<<"order is made: "<<order[rand()%5]<<std::endl;
    take_order.unlock();
    kitchen_access.lock();
    std::srand(std::time(nullptr));
    int cookingTime = rand()%6+10;
    std::this_thread::sleep_for(std::chrono::seconds (cookingTime));
    kitchen_access.unlock();
    std::cout<<"kitchen took the order"<<std::endl;
}

void deliverOrder() {
    int count=0;
    while (count<10) {
        std::this_thread::sleep_for(std::chrono::seconds(30));
        std::cout << "courier took the orders" << std::endl;
        count++;
    }
}

int main() {
    std::thread order1(makeOrder);
    std::thread order2(makeOrder);
    std::thread order3(makeOrder);
    std::thread order4(makeOrder);
    std::thread order5(makeOrder);
    std::thread order6(makeOrder);
    std::thread order7(makeOrder);
    std::thread order8(makeOrder);
    std::thread order9(makeOrder);
    std::thread order10(makeOrder);
    std::thread courier(deliverOrder);
    order1.join();
    order2.join();
    order3.join();
    order4.join();
    order5.join();
    order6.join();
    order7.join();
    order8.join();
    order9.join();
    order10.join();
    courier.join();
    return 0;
}
