#include <iostream>
#include <vector>
using namespace std;


class Person {
public:
    string name;
    int age;
    string contact;

    Person() {}
    Person(string n, int a, string c) {
        name = n;
        age = a;
        contact = c;
    }
};


class Patient : public Person {
public:
    int patientId;
    string disease;

    Patient(int id, string n, int a, string c, string d)
        : Person(n, a, c), patientId(id), disease(d) {}
};


class Doctor : public Person {
public:
    int doctorId;
    string specialization;

    Doctor(int id, string n, int a, string c, string sp)
        : Person(n, a, c), doctorId(id), specialization(sp) {}
};


class Appointment {
public:
    int apptId;
    int patientId;
    int doctorId;
    string date;

    Appointment(int a, int p, int d, string dt) {
        apptId = a;
        patientId = p;
        doctorId = d;
        date = dt;
    }
};


class HospitalSystem {
    vector<Patient> patients;
    vector<Doctor> doctors;
    vector<Appointment> appts;

    int nextPatientId = 1;
    int nextDoctorId = 1;
    int nextApptId = 1;

public:

   
    void addPatient() {
        string name, contact, disease;
        int age;

        cout << "Enter Name: ";
        cin >> name;
        cout << "Enter Age: ";
        cin >> age;
        cout << "Enter Contact: ";
        cin >> contact;
        cout << "Enter Disease: ";
        cin >> disease;

        patients.push_back(Patient(nextPatientId, name, age, contact, disease));
        cout << "Patient added with ID: " << nextPatientId << endl;
        nextPatientId++;
    }

    
    void addDoctor() {
        string name, contact, spec;
        int age;

        cout << "Enter Name: ";
        cin >> name;
        cout << "Enter Age: ";
        cin >> age;
        cout << "Enter Contact: ";
        cin >> contact;
        cout << "Enter Specialization: ";
        cin >> spec;

        doctors.push_back(Doctor(nextDoctorId, name, age, contact, spec));
        cout << "Doctor added with ID: " << nextDoctorId << endl;
        nextDoctorId++;
    }

   
    void bookAppointment() {
        int pid, did;
        string date;

        cout << "Enter Patient ID: ";
        cin >> pid;
        cout << "Enter Doctor ID: ";
        cin >> did;
        cout << "Enter Date: ";
        cin >> date;

        appts.push_back(Appointment(nextApptId, pid, did, date));
        cout << "Appointment booked with ID: " << nextApptId << endl;
        nextApptId++;
    }

    
    void viewPatients() {
        cout << "\n---- Patient List ----\n";
        for (auto &p : patients) {
            cout << "ID: " << p.patientId << "  Name: " << p.name
                 << "  Age: " << p.age << "  Disease: " << p.disease << endl;
        }
    }

   
    void viewDoctors() {
        cout << "\n---- Doctor List ----\n";
        for (auto &d : doctors) {
            cout << "ID: " << d.doctorId << "  Name: " << d.name
                 << "  Spec: " << d.specialization << endl;
        }
    }


    void viewAppointments() {
        cout << "\n---- Appointments ----\n";
        for (auto &a : appts) {
            cout << "Appt ID: " << a.apptId << "  PatientID: " << a.patientId
                 << "  DoctorID: " << a.doctorId << "  Date: " << a.date << endl;
        }
    }
};


int main() {
    HospitalSystem hs;
    int choice;

    while (true) {
        cout << "\n=== Hospital Management Menu ===\n";
        cout << "1. Add Patient\n";
        cout << "2. Add Doctor\n";
        cout << "3. Book Appointment\n";
        cout << "4. View All Patients\n";
        cout << "5. View All Doctors\n";
        cout << "6. View All Appointments\n";
        cout << "7. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
        case 1: hs.addPatient(); break;
        case 2: hs.addDoctor(); break;
        case 3: hs.bookAppointment(); break;
        case 4: hs.viewPatients(); break;
        case 5: hs.viewDoctors(); break;
        case 6: hs.viewAppointments(); break;
        case 7: 
            cout << "Exiting...\n"; 
            return 0;
        default: 
            cout << "Invalid choice!\n";
        }
    }
}