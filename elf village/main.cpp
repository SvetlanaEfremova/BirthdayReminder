#include <iostream>
#include <ctime>
#include <string>

class Branch {
private:
    Branch *parent;
    Branch **child= nullptr;
    std::string elfName;
    int numberOfBranches=0;
    bool hasAnElf = false;
public:
    void setElfName(std::string inElfName) {
        hasAnElf=true;
        elfName=inElfName;
    }
    Branch(Branch* inParent) {
        parent = inParent;
    }
    void setNumberOfBranches (int inNumberOfBranches) {
        numberOfBranches=inNumberOfBranches;
    }
    int getNumberOfBranches () {
        return numberOfBranches;
    }

    void setBranches() {
        if (this->parent== nullptr) { //для дерева
            int minNumOfBranches=3;
            int maxNumOfBranches=5;
            std::srand(time(nullptr));
            int numOfBranches = std::rand() % (maxNumOfBranches - minNumOfBranches + 1) +minNumOfBranches;
            this->setNumberOfBranches(numOfBranches);
            std::string enteredName;
            child = new Branch *[numOfBranches];
            for (int i=0; i<numOfBranches; i++) {
                child[i]= new Branch(this);
                std::cout<<"Enter the elf name or none:"<<std::endl;
                std::cin>>enteredName;
                if (enteredName!="none" && enteredName!="None")
                    child[i]->setElfName(enteredName);
            }
            for (int i=0; i<numOfBranches; i++)
                child[i]->setBranches();
        }
        else if (this->parent->parent==nullptr) { //для больших веток
            int minNumOfBranches=2;
            int maxNumOfBranches=3;
            std::srand(time(nullptr));
            int numOfBranches = std::rand() % (maxNumOfBranches - minNumOfBranches + 1) +minNumOfBranches;
            this->setNumberOfBranches(numOfBranches);
            std::string enteredName;
            child = new Branch *[numOfBranches];
            for (int i=0; i<numOfBranches; i++) {
                child[i]= new Branch(this);
                std::cout<<"Enter the elf name or none:"<<std::endl;
                std::cin>>enteredName;
                if (enteredName!="none" && enteredName!="None")
                    child[i]->setElfName(enteredName);
            }
        }
    }

    Branch* findElf(std::string inElfName) {
        if (this->hasAnElf && this->elfName==inElfName) {
               return this;
           }
        else if (this->child!= nullptr)
            for (int i=0; i<this->getNumberOfBranches(); i++) {
                if (child[i]->findElf(inElfName)!= nullptr)
                    return child[i]->findElf(inElfName);
            }
           return nullptr;
    }

    int countNeighbours () {
        int n=0;
        if (this->parent!=nullptr) {  //не ходим по дереву
            if (this->parent->parent!= nullptr && this->child!= nullptr) {  //если это большая ветка
                if (this->hasAnElf)
                    n++;
                for (int i=0; i<this->numberOfBranches; i++) {
                    if (this->child[i]->hasAnElf)
                        n++;
                }
            }
            else if (this->child== nullptr){  //если это средняя ветка
                if (this->parent->hasAnElf)
                    n++;
                for (int i=0; i<this->parent->numberOfBranches; i++) {
                    if (this->parent->child[i]->hasAnElf)
                        n++;
                }
            }
        }
        n--;  //исключаем эльфа, для которого считали соседей
        return n;
    }
};

int main() {
    Branch** tree;
    tree = new Branch*[5];
    std::string name;
    for (int i=0; i<5; i++) {
        tree[i] = new Branch(nullptr);
        tree[i]->setBranches();
    }
    std::cout<<"Enter the name of the elf to count neighbours for:"<<std::endl;
    std::cin>>name;
    for (int i=0; i<5; i++) {
        if (tree[i]->findElf(name)!= nullptr)
            std::cout<<"Number of neighbours: "<<tree[i]->findElf(name)->countNeighbours();
    }
    delete[] tree;
    return 0;
}
