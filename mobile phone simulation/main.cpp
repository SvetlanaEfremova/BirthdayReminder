#include <iostream>
#include <string>
#include <vector>

class Number {
private:
    std::string number;
public:
    bool checkNumber() {
        bool ok = true;
        if (number.length() == 12 && number[0] == '+' && number[1] == '7') {
            for (int i = 2; i < 12; i++) {
                if (number[i] < '0' || number[i] > '9') {
                    ok = false;
                    break;
                }
            }
        } else
            ok = false;
        return ok;
    }
    void setNumber(std::string newNumber) {
        number=newNumber;
    }
    std::string getNumber() {
        return number;
    }
};

class Contact {
private:
    std::string name;
    Number contactNumber;
public:
    void setContactName (std::string newName) {
        name=newName;
    }
    void setContactNumber (Number *newNumber) {
        contactNumber=*newNumber;
    }
    std::string getContactName(){
        return name;
    }
    Number getContactNumber() {
        return contactNumber;
    }
};

class Phone {
private:
    std::vector<Contact> phoneBook;
public:
void add() {
    Contact *newContact = new Contact;
    std::string newName;
    Number *newNumber = new Number;
    std::string enteredNumber;
    std::cout<<"Enter the phone number to add:"<<std::endl;
    std::cin>>enteredNumber;
    newNumber->setNumber(enteredNumber);
    if (newNumber->checkNumber()) {
        std::cout<<"Enter the name to add:"<<std::endl;
        std::cin>>newName;
        newContact->setContactName(newName);
        newContact->setContactNumber(newNumber);
        phoneBook.push_back(*newContact);
    }
    else
        std::cout<<"The number is incorrect"<<std::endl;
    delete newNumber;
    delete newContact;
}
void call() {
    bool ok=false;
    std::string input;
    int contactIndex;
    std::cout<<"Enter the name or the number to call:"<<std::endl;
    std::cin>>input;
    for (int i=0;i<phoneBook.size();i++) {
        if (phoneBook[i].getContactName()==input || phoneBook[i].getContactNumber().getNumber()==input) {
            contactIndex=i;
            ok=true;
            break;
        }
    }
    if (ok) {
        std::cout<<"CALL: "<<phoneBook[contactIndex].getContactNumber().getNumber()<<std::endl;
    }
    else
        std::cout<<"No contact found"<<std::endl;
}
void sms(){
    bool ok=false;
    std::string input;
    int contactIndex;
    std::string text;
    std::cout<<"Enter the name or the number to send a message:"<<std::endl;
    std::cin>>input;
    for (int i=0;i<phoneBook.size();i++) {
        if (phoneBook[i].getContactName()==input || phoneBook[i].getContactNumber().getNumber()==input) {
            contactIndex=i;
            ok=true;
            break;
        }
    }
    if (ok) {
        std::cout<<"Enter the message:"<<std::endl;
        std::cin>>text;
        std::cout<<"The message was sent to this number: "<<phoneBook[contactIndex].getContactNumber().getNumber()<<std::endl;
    }
}
};


int main() {
    Phone* phone=new Phone;
    std::string operation;
    std::cout<<"Enter the operation"<<std::endl;
    std::cin>>operation;
    while (operation!="exit" && operation!="Exit") {
        if (operation=="add" || operation=="Add") {
            phone->add();
        }
        else if (operation=="call" || operation=="Call")
            phone->call();
        else if (operation=="sms" || operation=="Sms" || operation=="SMS")
            phone->sms();
        std::cout<<"Enter the operation"<<std::endl;
        std::cin>>operation;
    }
    delete phone;
    return 0;
}
