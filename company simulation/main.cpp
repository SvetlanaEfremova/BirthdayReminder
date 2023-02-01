#include <iostream>
#include <string>
#include <ctime>

class Employee {
private:
public:
    std::string name;
    bool busy=false;
    char task;
    Employee (int number1, int number2) {  //номер команды и номер сотрудника в команде
        name="Worker #"+std::to_string(number1)+"-"+std::to_string(number2);
    }
};

class Head {
private:
    int directive;
public:
    void setDirective (int inDirective) {
        directive=inDirective;
        std::cout<<"The head has a directive for managers: "<<directive<<std::endl;
    }
    int getDirective () {
        return directive;
    }
};

class Team {
private:
    Employee** workers;  //сотрудники команды
public:
    int number;  //номер коман
    int numberOfWorkers=0;
    Team (int inNumber, int inNumberOfWorkers) {
        number=inNumber;
        numberOfWorkers=inNumberOfWorkers;
        workers = new Employee* [numberOfWorkers];
        for (int i=0; i<numberOfWorkers; i++)
            workers[i] = new Employee(number, i);
    }
    void addNewTask (int inNumberOfTasks){
        for (int i=0; i<inNumberOfTasks; i++)
            if (!(workers[i]->busy)) {
                workers[i]->busy=true;
                srand(time(nullptr));
                workers[i]->task= "ABC"[(rand() % 3)];
                std::cout<<workers[i]->name<<" got a task "<<workers[i]->task<<std::endl;
            }
    }
    bool allBusy () {  //все ли в команде заняты
        bool teamBusy = true;
        if (numberOfWorkers == 0)
            teamBusy=false;
        else for (int i = 0; i < numberOfWorkers; i++) {
                if (!(workers[i]->busy))
                    teamBusy = false;
            }
        return teamBusy;
    }
};

class Manager {
private:
    int directive; //указание от руководителя
    int number;
public:
    class Team* team; //указатель на команду менеджера
    std::string name;
    Manager (class Team* inTeam) {
        team=inTeam;
    }
    void setDirective (int inDirective) {
        directive=inDirective;
        std::cout<<name<<" got a directive"<<std::endl;
    }
    void setNumber() {
        number=team->number;
        name="Manager #"+std::to_string(number);
    }
    int numberOfTasks() {
        std::srand(directive+number);
        return rand()%(team->numberOfWorkers+1);
    }
};


int main() {
    int numberOfTeams, numberOfMembers=0, directive;
    Team** teams;
    Manager** managers;
    Head* head;
    bool allTeamsBusy=false; //все ли сотрудники заняты
    std::cout<<"Enter the number of teams:"<<std::endl;
    std::cin>>numberOfTeams;
    teams = new Team*[numberOfTeams];
    managers = new Manager*[numberOfTeams];
    head = new Head;
    for (int i=0; i<numberOfTeams; i++) {  //создаём команды
        std::cout<<"Enter the number of members in team #"<<i<<":"<<std::endl;
        std::cin>>numberOfMembers;
        teams[i] = new Team (i,numberOfMembers);
        managers[i] = new Manager (teams[i]);
        managers[i]->setNumber();
    }
    while (!allTeamsBusy) {
        std::cout<<"Enter directive:"<<std::endl;
        std::cin>>directive;
        head->setDirective(directive);
        for (int i=0; i<numberOfTeams; i++) {
            if (!(teams[i]->allBusy())) {
                managers[i]->setDirective(head->getDirective());
                teams[i]->addNewTask(managers[i]->numberOfTasks());
                break;
            }
        }
        allTeamsBusy=true; //проверям, есть ли команды, в которых есть не занятые сотрудники
        for (int i=0; i<numberOfTeams; i++) {
            if (! (teams[i]->allBusy())) {
                allTeamsBusy = false;
                break;
            }
        }
    }
    delete[] teams;
    delete[] managers;
    delete head;
    return 0;
}
