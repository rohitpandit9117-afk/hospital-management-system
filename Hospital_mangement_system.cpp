#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <iomanip>
using namespace std;

/*
========================================================
           HOSPITAL MANAGEMENT SYSTEM
========================================================
Project Language : C++
Compiler         : g++
Platform         : VS Code
========================================================
*/



// ======================================================
//                 PATIENT CLASS
// ======================================================

class Patient
{
private:
    int patientId;
    string name;
    int age;
    string gender;
    string phone;
    string address;
    string disease;

public:

    // Default Constructor
    Patient()
    {
        patientId = 0;
        name = "";
        age = 0;
        gender = "";
        phone = "";
        address = "";
        disease = "";
    }

    // Function to register patient
    void registerPatient()
    {
        cout << "\n========================================\n";
        cout << "        PATIENT REGISTRATION\n";
        cout << "========================================\n";

        cout << "Enter Patient ID: ";
        cin >> patientId;

        cin.ignore();

        cout << "Enter Patient Name: ";
        getline(cin, name);

        cout << "Enter Age: ";
        cin >> age;

        cin.ignore();

        cout << "Enter Gender: ";
        getline(cin, gender);

        cout << "Enter Phone Number: ";
        getline(cin, phone);

        cout << "Enter Address: ";
        getline(cin, address);

        cout << "Enter Disease/Problem: ";
        getline(cin, disease);

        cout << "\nPatient Registered Successfully!\n";
    }

    // Display patient information
    void displayPatient()
    {
        cout << "\n----------------------------------------\n";
        cout << "Patient ID      : " << patientId << endl;
        cout << "Patient Name    : " << name << endl;
        cout << "Age             : " << age << endl;
        cout << "Gender          : " << gender << endl;
        cout << "Phone           : " << phone << endl;
        cout << "Address         : " << address << endl;
        cout << "Disease         : " << disease << endl;
        cout << "----------------------------------------\n";
    }

    // Return patient ID
    int getPatientId()
    {
        return patientId;
    }

    // Save patient in file
    void saveToFile()
    {
        ofstream file("patients.txt", ios::app);

        if (file.is_open())
        {
            file << patientId << endl;
            file << name << endl;
            file << age << endl;
            file << gender << endl;
            file << phone << endl;
            file << address << endl;
            file << disease << endl;
            file << "------------------------" << endl;

            file.close();
        }
    }
};


// ======================================================
//                 DOCTOR CLASS
// ======================================================

class Doctor
{
private:
    int doctorId;
    string name;
    string specialization;
    string qualification;
    string timing;
    double fee;

public:

    // Constructor
    Doctor(
        int id,
        string n,
        string s,
        string q,
        string t,
        double f)
    {
        doctorId = id;
        name = n;
        specialization = s;
        qualification = q;
        timing = t;
        fee = f;
    }

    // Display doctor information
    void displayDoctor()
    {
        cout << "\n----------------------------------------\n";
        cout << "Doctor ID       : " << doctorId << endl;
        cout << "Doctor Name     : " << name << endl;
        cout << "Specialization  : " << specialization << endl;
        cout << "Qualification   : " << qualification << endl;
        cout << "Timing          : " << timing << endl;
        cout << "Consultation Fee: Rs. " << fee << endl;
        cout << "----------------------------------------\n";
    }

    int getDoctorId()
    {
        return doctorId;
    }

    string getDoctorName()
    {
        return name;
    }

    double getFee()
    {
        return fee;
    }
};


// ======================================================
//                 APPOINTMENT CLASS
// ======================================================

class Appointment
{
private:
    int appointmentId;
    int patientId;
    int doctorId;
    string patientName;
    string doctorName;
    string date;
    string time;
    string status;

public:

    // Constructor
    Appointment()
    {
        appointmentId = 0;
        patientId = 0;
        doctorId = 0;
        patientName = "";
        doctorName = "";
        date = "";
        time = "";
        status = "Booked";
    }

    // Book appointment
    void bookAppointment(
        int aId,
        int pId,
        int dId,
        string pName,
        string dName)
    {
        appointmentId = aId;
        patientId = pId;
        doctorId = dId;
        patientName = pName;
        doctorName = dName;

        cin.ignore();

        cout << "Enter Appointment Date (DD/MM/YYYY): ";
        getline(cin, date);

        cout << "Enter Appointment Time: ";
        getline(cin, time);

        status = "Booked";

        cout << "\nAppointment Booked Successfully!\n";
    }

    // Display appointment
    void displayAppointment()
    {
        cout << "\n========================================\n";
        cout << "       APPOINTMENT DETAILS\n";
        cout << "========================================\n";

        cout << "Appointment ID : " << appointmentId << endl;
        cout << "Patient ID     : " << patientId << endl;
        cout << "Patient Name   : " << patientName << endl;
        cout << "Doctor ID      : " << doctorId << endl;
        cout << "Doctor Name    : " << doctorName << endl;
        cout << "Date           : " << date << endl;
        cout << "Time           : " << time << endl;
        cout << "Status         : " << status << endl;
    }

    // Save appointment
    void saveToFile()
    {
        ofstream file("appointments.txt", ios::app);

        if (file.is_open())
        {
            file << appointmentId << endl;
            file << patientId << endl;
            file << doctorId << endl;
            file << patientName << endl;
            file << doctorName << endl;
            file << date << endl;
            file << time << endl;
            file << status << endl;
            file << "------------------------" << endl;

            file.close();
        }
    }
};


// ======================================================
//                 BILL CLASS
// ======================================================

class Bill
{
private:
    int billId;
    int patientId;
    string patientName;

    double consultationFee;
    double medicineFee;
    double testFee;
    double roomFee;
    double otherCharges;

    double subtotal;
    double discount;
    double finalAmount;

public:

    // Constructor
    Bill()
    {
        billId = 0;
        patientId = 0;

        consultationFee = 0;
        medicineFee = 0;
        testFee = 0;
        roomFee = 0;
        otherCharges = 0;

        subtotal = 0;
        discount = 0;
        finalAmount = 0;
    }

    // Generate bill
    void generateBill(
        int bId,
        int pId,
        string pName,
        double doctorFee)
    {
        billId = bId;
        patientId = pId;
        patientName = pName;

        consultationFee = doctorFee;

        cout << "\n========================================\n";
        cout << "             BILL GENERATION\n";
        cout << "========================================\n";

        cout << "Bill ID       : " << billId << endl;
        cout << "Patient ID    : " << patientId << endl;
        cout << "Patient Name  : " << patientName << endl;

        cout << "\nConsultation Fee : Rs. "
             << consultationFee << endl;

        cout << "Enter Medicine Charges: Rs. ";
        cin >> medicineFee;

        cout << "Enter Test Charges: Rs. ";
        cin >> testFee;

        cout << "Enter Room Charges: Rs. ";
        cin >> roomFee;

        cout << "Enter Other Charges: Rs. ";
        cin >> otherCharges;

        subtotal =
            consultationFee +
            medicineFee +
            testFee +
            roomFee +
            otherCharges;

        cout << "\nEnter Discount (%): ";
        double discountPercent;
        cin >> discountPercent;

        discount = subtotal * discountPercent / 100;

        finalAmount = subtotal - discount;

        displayBill();

        saveToFile();
    }

    // Display bill
    void displayBill()
    {
        cout << "\n========================================\n";
        cout << "             HOSPITAL BILL\n";
        cout << "========================================\n";

        cout << left << setw(25)
             << "Patient ID"
             << ": " << patientId << endl;

        cout << left << setw(25)
             << "Patient Name"
             << ": " << patientName << endl;

        cout << "----------------------------------------\n";

        cout << left << setw(25)
             << "Consultation Fee"
             << ": Rs. " << consultationFee << endl;

        cout << left << setw(25)
             << "Medicine Charges"
             << ": Rs. " << medicineFee << endl;

        cout << left << setw(25)
             << "Test Charges"
             << ": Rs. " << testFee << endl;

        cout << left << setw(25)
             << "Room Charges"
             << ": Rs. " << roomFee << endl;

        cout << left << setw(25)
             << "Other Charges"
             << ": Rs. " << otherCharges << endl;

        cout << "----------------------------------------\n";

        cout << left << setw(25)
             << "Subtotal"
             << ": Rs. " << subtotal << endl;

        cout << left << setw(25)
             << "Discount"
             << ": Rs. " << discount << endl;

        cout << "----------------------------------------\n";

        cout << left << setw(25)
             << "FINAL AMOUNT"
             << ": Rs. " << finalAmount << endl;

        cout << "========================================\n";
        cout << "          THANK YOU!\n";
        cout << "========================================\n";
    }

    // Save bill to file
    void saveToFile()
    {
        ofstream file("bills.txt", ios::app);

        if (file.is_open())
        {
            file << "Bill ID: " << billId << endl;
            file << "Patient ID: " << patientId << endl;
            file << "Patient Name: " << patientName << endl;

            file << "Consultation Fee: "
                 << consultationFee << endl;

            file << "Medicine Charges: "
                 << medicineFee << endl;

            file << "Test Charges: "
                 << testFee << endl;

            file << "Room Charges: "
                 << roomFee << endl;

            file << "Other Charges: "
                 << otherCharges << endl;

            file << "Subtotal: "
                 << subtotal << endl;

            file << "Discount: "
                 << discount << endl;

            file << "Final Amount: "
                 << finalAmount << endl;

            file << "================================\n";

            file.close();
        }
    }
};


// ======================================================
//             GLOBAL VECTORS
// ======================================================

vector<Patient> patients;
vector<Appointment> appointments;


// ======================================================
//             DISPLAY HOSPITAL HEADER
// ======================================================

void hospitalHeader()
{
    cout << "\n\n";
    cout << "================================================\n";
    cout << "           CITY CARE HOSPITAL\n";
    cout << "          MANAGEMENT SYSTEM\n";
    cout << "================================================\n";
}


// ======================================================
//             DOCTOR LIST FUNCTION
// ======================================================

void showDoctors(vector<Doctor>& doctors)
{
    cout << "\n========================================\n";
    cout << "             DOCTOR DETAILS\n";
    cout << "========================================\n";

    for (int i = 0; i < doctors.size(); i++)
    {
        doctors[i].displayDoctor();
    }
}


// ======================================================
//             PATIENT REGISTRATION
// ======================================================

void patientRegistration()
{
    Patient p;

    p.registerPatient();

    p.saveToFile();

    patients.push_back(p);
}


// ======================================================
//             DISPLAY ALL PATIENTS
// ======================================================

void displayAllPatients()
{
    if (patients.empty())
    {
        cout << "\nNo patient records found.\n";
        return;
    }

    cout << "\n========================================\n";
    cout << "            ALL PATIENTS\n";
    cout << "========================================\n";

    for (int i = 0; i < patients.size(); i++)
    {
        patients[i].displayPatient();
    }
}


// ======================================================
//             SEARCH PATIENT
// ======================================================

void searchPatient()
{
    if (patients.empty())
    {
        cout << "\nNo patient records available.\n";
        return;
    }

    int id;

    cout << "\nEnter Patient ID to search: ";
    cin >> id;

    bool found = false;

    for (int i = 0; i < patients.size(); i++)
    {
        if (patients[i].getPatientId() == id)
        {
            cout << "\nPatient Found!\n";

            patients[i].displayPatient();

            found = true;
            break;
        }
    }

    if (!found)
    {
        cout << "\nPatient not found.\n";
    }
}


// ======================================================
//             BOOK APPOINTMENT
// ======================================================

void bookAppointment(vector<Doctor>& doctors)
{
    if (patients.empty())
    {
        cout << "\nFirst register a patient.\n";
        return;
    }

    int patientId;

    cout << "\nEnter Patient ID: ";
    cin >> patientId;

    int patientIndex = -1;

    for (int i = 0; i < patients.size(); i++)
    {
        if (patients[i].getPatientId() == patientId)
        {
            patientIndex = i;
            break;
        }
    }

    if (patientIndex == -1)
    {
        cout << "\nPatient not found.\n";
        return;
    }

    showDoctors(doctors);

    int doctorId;

    cout << "\nEnter Doctor ID: ";
    cin >> doctorId;

    int doctorIndex = -1;

    for (int i = 0; i < doctors.size(); i++)
    {
        if (doctors[i].getDoctorId() == doctorId)
        {
            doctorIndex = i;
            break;
        }
    }

    if (doctorIndex == -1)
    {
        cout << "\nDoctor not found.\n";
        return;
    }

    Appointment a;

    int appointmentId =
        appointments.size() + 1001;

    a.bookAppointment(
        appointmentId,
        patientId,
        doctorId,
        "Patient",
        doctors[doctorIndex].getDoctorName()
    );

    a.saveToFile();

    appointments.push_back(a);
}


// ======================================================
//             DISPLAY APPOINTMENTS
// ======================================================

void displayAppointments()
{
    if (appointments.empty())
    {
        cout << "\nNo appointments found.\n";
        return;
    }

    cout << "\n========================================\n";
    cout << "          ALL APPOINTMENTS\n";
    cout << "========================================\n";

    for (int i = 0; i < appointments.size(); i++)
    {
        appointments[i].displayAppointment();
    }
}


// ======================================================
//             GENERATE BILL
// ======================================================

void generatePatientBill(vector<Doctor>& doctors)
{
    if (patients.empty())
    {
        cout << "\nNo patients registered.\n";
        return;
    }

    int patientId;

    cout << "\nEnter Patient ID: ";
    cin >> patientId;

    int patientIndex = -1;

    for (int i = 0; i < patients.size(); i++)
    {
        if (patients[i].getPatientId() == patientId)
        {
            patientIndex = i;
            break;
        }
    }

    if (patientIndex == -1)
    {
        cout << "\nPatient not found.\n";
        return;
    }

    showDoctors(doctors);

    int doctorId;

    cout << "\nEnter Doctor ID: ";
    cin >> doctorId;

    int doctorIndex = -1;

    for (int i = 0; i < doctors.size(); i++)
    {
        if (doctors[i].getDoctorId() == doctorId)
        {
            doctorIndex = i;
            break;
        }
    }

    if (doctorIndex == -1)
    {
        cout << "\nDoctor not found.\n";
        return;
    }

    Bill bill;

    int billId = 5001;

    bill.generateBill(
        billId,
        patientId,
        "Patient",
        doctors[doctorIndex].getFee()
    );
}


// ======================================================
//             MAIN FUNCTION
// ======================================================

int main()
{
    // ------------------------------------------
    // Doctor data
    // ------------------------------------------

    vector<Doctor> doctors;

    doctors.push_back(
        Doctor(
            101,
            "Raj Kumar",
            "General Physician",
            "MBBS",
            "10 AM - 2 PM",
            500
        )
    );

    doctors.push_back(
        Doctor(
            102,
            "Amit Sharma",
            "Cardiologist",
            "MD Cardiology",
            "3 PM - 6 PM",
            1000
        )
    );

    doctors.push_back(
        Doctor(
            103,
            "Neha Singh",
            "Dentist",
            "BDS",
            "11 AM - 3 PM",
            700
        )
    );

    doctors.push_back(
        Doctor(
            104,
            "Priya Verma",
            "Dermatologist",
            "MD Dermatology",
            "4 PM - 7 PM",
            800
        )
    );


    // ------------------------------------------
    // Main Menu
    // ------------------------------------------

    int choice;

    do
    {
        hospitalHeader();

        cout << "\n1. Patient Registration";
        cout << "\n2. Doctor Details";
        cout << "\n3. Book Appointment";
        cout << "\n4. Generate Bill";
        cout << "\n5. Display All Patients";
        cout << "\n6. Search Patient";
        cout << "\n7. Display Appointments";
        cout << "\n8. Exit";

        cout << "\n\nEnter Your Choice: ";
        cin >> choice;


        switch (choice)
        {
            case 1:
                patientRegistration();
                break;

            case 2:
                showDoctors(doctors);
                break;

            case 3:
                bookAppointment(doctors);
                break;

            case 4:
                generatePatientBill(doctors);
                break;

            case 5:
                displayAllPatients();
                break;

            case 6:
                searchPatient();
                break;

            case 7:
                displayAppointments();
                break;

            case 8:
                cout << "\nThank you for using";
                cout << " Hospital Management System!\n";
                break;

            default:
                cout << "\nInvalid choice!";
        }

    } while (choice != 8);

    return 0;
}