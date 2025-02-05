#include <iostream>
#include <fstream>
#include <string>

using namespace std;

bool login(){

    string fuser, fpass, user, pass;

    cout << "Login\n" << endl;
    cout << "Enter username: ";
    cin >> user;
    cout << "Enter password: ";
    cin >> pass;

    ifstream file(user + ".txt");
    getline(file, fuser);
    getline(file, fpass);
    file.close();

    if(user == fuser && pass == fpass){

        return true;

    }else{

        return false;

    }

}

int main(){

    string username, password;
    int choice;

    cout << "1: Login\n2: Register\n3: Exit\n" << endl;
    cout << "What to do?: ";
    cin >> choice;
    cout << "--------------------------------" << endl;

    if(choice == 1){

        bool status = login();
        if(!status){

            cout << "--------------------------------" << endl;
            cout << "Invalid entries!" << endl;
            system("pause");

        }else{

            cout << "--------------------------------" << endl;
            cout << "Login Successfull!" << endl;
            system("pause");

        }

    }else if(choice == 2){

        cout << "Register\n" << endl;
        cout << "Enter username: ";
        cin >> username;
        cout << "Enter password: ";
        cin >> password;

        ofstream file(username + ".txt");
        file << username << endl << password;
        file.close();

        cout << "--------------------------------" << endl;
        cout << "Registration Success!\n" << endl;
        system("pause");
        cout << "--------------------------------" << endl;

        main();

    } else{

        cout << "Exiting . . .";
        system("pause");

    }
}