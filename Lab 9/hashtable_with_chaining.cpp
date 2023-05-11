#include <iostream>
#include "linkedlist.cpp"
using namespace std;

struct HashTable{
    int MAX_LENGTH = 4;
    int MAX_CHAIN_LENGTH = 2;
    LinkedList * password = new LinkedList[MAX_LENGTH];

    bool isFull(){
        bool full = true;
        for (int i = 0; i < MAX_LENGTH; i++){
            if(password[i].head == NULL){
                full = false;
            }
        }
        return full;
    }

    int hashfunc(string user_name){
        int sum = 0;
        int hash = 0;
        for(int i = 0;i< user_name.length(); i++){
            sum += int(user_name[i]);
        }
        hash = sum % MAX_LENGTH;
        return hash;
    }

    bool is_slot_empty(int hash){
        bool empty;
        if(password[hash].head==NULL){
            empty = true;
        }
        else{
            empty=false;
        }
        return empty;
    }

    void insert(string user_name,string user_password){
        int hash;
        bool empty;
        hash = hashfunc(user_name);
        empty = is_slot_empty(hash);

        if(empty){
            password[hash].insert(user_name.data(),user_password.data());
            cout<<"User added\n";
        }
        else{
            if(password[hash].length < MAX_CHAIN_LENGTH){
                password[hash].insert(user_name.data(),user_password.data());
                cout<<"User added\n";
            }
            else{
                cout<<"Reached max chain length!\n";
            }
        }
    }

    void print_hashtable(){
        for(int i=0;i<MAX_LENGTH;i++){
            cout<<"["<<i<<"]-->";
            password[i].print_list();
        }
    }
    



    void hash_lookup(string user_name){
        int hash;
        bool empty;
        hash = hashfunc(user_name);
        empty = is_slot_empty(hash);

        if(empty){
            cout << "User does not exist.\n";
        }
        else{
            Node* current = password[hash].head;
            bool found = false;

            while(current != NULL) { 
                if(current->user_name == user_name) {
                    cout << "Password: " << current->password << "\n";
                    found = true;
                    break;
                }
                current = current->link;
            }

            if(!found) {
                cout << "User does not exist.\n";
            }
        }
    }
};

int main(){
    cout<< "1. Insert\n2. Hash lookup password\n3. Print Hashtable\n-1.Exiting\n";
    HashTable * hashtbl = new HashTable;

    cout<< hashtbl->isFull()<<"\n";

    int command=0;
    string user_name;
    string password;

    while (command!=-1){
        cout << "Type command: ";
        cin >> command;

        switch (command){
            case 1:
                cout << "Enter user name: ";
                cin >> user_name;
                cout << "Enter password to be saved: ";
                cin >> password;
                hashtbl->insert(user_name,password);
                break;

            case 2:
                cout << "Enter user name to look up password:";
                cin >> user_name;
                hashtbl->hash_lookup(user_name);
                break;

            case 3:
                hashtbl->print_hashtable();
                break;

            case -1:
                hashtbl->print_hashtable();
                cout << "Exiting...\n";
                break;
        }
    }

    return 0;
}
