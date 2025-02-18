#include <iostream>
using namespace std;

class Patient {
    int *id;
    string *name;
    int *results;

public:
	
    Patient(int ID, string Name, int Results[10]) {
        id = new int(ID);
        name = new string(Name);
        results = new int[10];

        for (int i = 0; i < 10; ++i) {
            results[i] = Results[i];
        }
    }

    Patient(const Patient *obj) {
        id = new int(*obj->id);
        name = new string(*obj->name);
        results = new int[10];

        for (int i = 0; i < 10; ++i) {
            results[i] = obj->results[i];
        }
    }

    ~Patient() {
        delete id;
        delete name;
        delete[] results;
    }

    void display() {
        cout << "Patient Details:\n";
        cout << "ID: " << *id << endl;
        cout << "Name: " << *name << endl;
        cout << "Results: ";
        for (int i = 0; i < 10; ++i) {
            cout << results[i] << " ";
        }
        cout << endl;
        cout << "------------------------\n";
    }
};

int main() {
    
    int patientResults[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    Patient p1(123, "Ali", patientResults);
    p1.display(); 

    Patient p2(p1);
    p2.display();

    return 0;
}
