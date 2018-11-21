#include <iostream>
using namespace std;

// toutos en o customer mas
class Customer {
public:
    Customer();
    bool exist; // touto an ine true simeni oti iparxi..an ine false simeni oti ne iparxi
    int id; // touto en to id mas
    char name[100];
    char surname[100];
};

Customer::Customer() { // touto en to custructor tou Customer...opote dimiourgite enas customer 8a kamni to exist false..
    exist = false;
}

class Customers {
public:
    Customers();
    void display_customers(); // touto enna kamni display enan customer
    void add_customer(); // touto add
    void delete_customer(); // je touto delete
private:
    Customer cust[100]; // dame dimiourgoume 100 customer..dld to custructor pou ides tou proigoumenou class enna extelesti 100 fores..
    int current_id; // touto en to id number pou enna pianni o neos customer
};

Customers::Customers() { // touto en to custructor tou Customers to opio kamni initialize to current_id se 100 epidi 8eloume to oi customers na arkefkoun pou to 100 je pano
    current_id = 100;
}

void Customers::display_customers() { // dame kamnoume to display
    bool empty = true; // touto an ine true simeni oti en iparxoun customers
    cout << endl;
    for (int i=0; i<100; i++)
        if (cust[i].exist) {
            empty = false; // dame kamnoume to false..ara iparxoun
            cout << cust[i].id << " " << cust[i].name << " " << cust[i].surname << endl; // dame tiponoume to id to name je to surname tou ka8e customer
        }

    if (empty) // an en true tote enna tiposi oti en eshi customers
        cout << "there are no customers" << endl;
}

void Customers::add_customer() {
    int index = -1; // touto en to index pou enna valoume ton neo customer...ekamato -1 etsi an den evri xoro enna mini -1 je enna 3eroume oti en eshi xori
    for (int i=0; i<100; i++) // dame psaxni gia to proto false
        if (cust[i].exist == false) {
            index = i; // je valli to i sto index
            break;
        }
    cout << endl;
    if (index == -1) // an emine -1 simeni oti en ivre xoro
        cout << "out of memory" << endl;
    else { // dame kamnoume add ton customer
        cout << "Name: ";
        cin >> cust[index].name;
        cout << "Surname: ";
        cin >> cust[index].surname;
        cust[index].id = current_id++; // dame valloume to id tou je pros8etoume 1 sto current_id
        cust[index].exist = true; // dame laloume oti pleon iparxi toutos o customer
        cout << endl << "customer with id " << cust[index].id << " has been added" << endl; // dame laloume oti ekamamen ton add
    }
}

void Customers::delete_customer() {
    // dame kamnoume delete ton customer me to id tou
    int id;
    cout << endl << "Customer id: ";
    cin >> id;
    for (int i=0; i<100; i++) // dame psaxnoume stous customers
        if (cust[i].exist && cust[i].id == id) { // je an ton evri
            cust[i].exist = false; // kamniton remove
            break;
        }
}

int menu() { // touto en to menu je epistrefi ti e8kiavase
    int i;
    cout << "[1] display customers" << endl;
    cout << "[2] add customer" << endl;
    cout << "[3] delete customer" << endl;
    cout << "[0] exit" << endl;
    cout << endl << "select a number [1-3]: ";
    cin >> i;
    return i;
}

int main() { // je touto en to main
    Customers customers; // dame exoume to class Customers
    int i; // touto enna pianni oti epistrepsi to menu()

    while ((i = menu()) != 0) { // an to i en otidipote extos pou 0 tote enna mpi sto switch je meta enna 3ana di3i to menu
        switch(i) {
            case 1: // an e8kiale3e na kami display
                customers.display_customers();
                getchar(); // en opos to pause touto
                getchar();
                break;
            case 2: // an e8kiale3e na kami add
                customers.add_customer();
                getchar();
                getchar();
                break;
            case 3: // an e8kiale3e na kami delete
                customers.delete_customer();
                getchar();
                getchar();
                break;
            default: // an en otidipote allo tote enna tou di3i minima
                cout << "wrong input" << endl;
                getchar();
                getchar();
        }
    }

}
