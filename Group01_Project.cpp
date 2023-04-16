#include <bits/stdc++.h>
#include <iostream>
#include <cstring>
#include <fstream>
#include <conio.h>
#include <algorithm>

using namespace std;

struct student {
	int id, semester;
	string name, dob, department, email, contact, address, bloodGroup;
	bool isPaymentDone, isScholarshipCandidate, isGraduated;
	double completedCredits, cgpa;

	student *next, *prev;
};

student *head = NULL, *tail = NULL;

student *createStudent();
student *createStudent(int id);
student *createStudent(student *stud);
student *createStudent(int id, string name);

void insertStudent();
void insertStudent(int id);
void insertStudent(student *temp);
void insertStudent(int id, string name);

void updatePartialData();
void updateInfoByID();

void deleteAllInfo();
void deleteByID(int id);
void deleteByName(string name);
void deleteByCGPA(double cgpa, string dir);
void deleteByGradStatus();
void deleteProbatedStudents();

bool foundId(int id);
bool foundName(string name);

void searchById(int id);
void searchByName(string name);
void searchByCompletedCredits(double completedCredits, string dir);
void searchByCGPA(double cpga, string dir);
void searchByContact(string contact);
void searchByBloodGroup(string bloodGroup);
void searchByDepartment(string department);
void searchBySemester(int semester);
void searchByUnpaidStudents();
void searchByGraduateStudents();
void searchByProbationStudents();

void sortByID();
void sortByName();
void sortByCGPA();
void sortBySemester();
void sortByDepartment();
void sortByCompletedCredits();

int mainMenu();
void showStudentInfo();
void addStudentInfo();
void updateStudentInfo();
void deleteStudentInfo();
void searchStudentInfo();
void sortStudentInfo();
void generateReport();

void reportOfSpecificID(int id);
void reportOfEveryIDs();
void reportOfSemester(int sem);
void reportOfCGPA(double cgpa, string dir);
void reportOfProbatedStudent();

void printSpecificID(int id);
void printSpecificID(student *updCur);

int stringToInteger(string line);
double stringToDouble(string line);
void inputManipulation();
void outputManipulation();


// ------- ----- ------
// ------- ----- ------


int main(void) {
    inputManipulation();

    int input;
    do {
        input = mainMenu ();
        switch (input) {
        case 1:
            showStudentInfo();
            cout<<"\nPress any key to return Main Menu...";
            getch();
            break;
        case 2:
            addStudentInfo();
            break;
        case 3:
            updateStudentInfo();
            break;
        case 4:
            deleteStudentInfo();
            break;
        case 5:
            searchStudentInfo();
            break;
        case 6:
            sortStudentInfo();
            break;
        case 7:
            generateReport();
            break;
        case 0:
            outputManipulation();
            exit(0);
        default:
            cout << "\n\t\t\tInvalid Option!!" << "\n";
            cout << "\t\t       Please try again..." << "\n";
            cout << "\n";
            cout << "Press any key to continue...";
            getch();
        }
    } while (input != 0);
}


student *createStudent() {
    student *newStudent = new student();

    cout << "\nEnter ID: ";
    int id; cin >> id; newStudent -> id = id;
    cout << "Enter Name: ";
    string name; getline(cin >> ws, name); newStudent -> name = name;
    cout << "Enter Credit Count: ";
    double completedCredits; cin >> completedCredits; newStudent -> completedCredits = completedCredits;
    cout << "Enter CGPA: ";
    double cgpa; cin >> cgpa; newStudent -> cgpa = cgpa;
    cout << "Enter Date of Birth: ";
    string dob; getline(cin >> ws, dob); newStudent -> dob = dob;
    cout << "Enter Email: ";
    string email; getline(cin >> ws, email); newStudent -> email = email;
    cout << "Enter Contact: ";
    string contact; getline(cin >> ws, contact); newStudent -> contact = contact;
    cout << "Enter Address: ";
    string address; getline(cin >> ws, address); newStudent -> address = address;
    cout << "Enter Blood Group: ";
    string bloodGroup; getline(cin >> ws, bloodGroup); newStudent -> bloodGroup = bloodGroup;
    cout << "Enter Department: ";
    string department; getline(cin >> ws, department); newStudent -> department = department;
    cout << "Enter Semester(in digit): ";
    int semester; cin >> semester; newStudent -> semester = semester;

    cout << "Payment Done? If No, Press 0: ";
    int pd; cin >> pd;
    bool isPaymentDone;
    if (pd == 0) isPaymentDone = false;
    else isPaymentDone = true;
    newStudent -> isPaymentDone = isPaymentDone;

    cout << "Scholarship Candidate? If No, Press 0: ";
    int sc; cin >> sc;
    bool isScholarshipCandidate;
    if(sc == 0) isScholarshipCandidate = false;
    else isScholarshipCandidate = true;
    newStudent -> isScholarshipCandidate = isScholarshipCandidate;

    cout << "Graduated? If No, Press 0: " << flush;
    int grad; cin >> grad;
    bool isGraduated;
    if(grad == 0) isGraduated = false;
    else isGraduated = true;
    newStudent -> isGraduated = isGraduated;

    newStudent -> next = NULL;
    newStudent -> prev = NULL;

    return newStudent;
}

student *createStudent(int id) {
    student *newStudent = new student();

    newStudent -> id = id;
    newStudent -> name = "Not Given";
    newStudent -> completedCredits = -1;
    newStudent -> cgpa = -1;
    newStudent -> dob = "Not Given";
    newStudent -> email = "Not Given";
    newStudent -> contact = "Not Given";
    newStudent -> address = "Not Given";
    newStudent -> bloodGroup = "Not Given";
    newStudent -> department = "Not Given";
    newStudent -> semester = 0;
    newStudent -> isPaymentDone = false;
    newStudent -> isScholarshipCandidate = false;
    newStudent -> isGraduated = false;

    newStudent -> next = NULL;
    newStudent -> prev = NULL;

    return newStudent;
}

student *createStudent(student *stud){
    student *newStudent=new student();

    newStudent -> id = stud -> id;
    newStudent -> name = stud -> name;
    newStudent -> completedCredits = stud -> completedCredits;
    newStudent -> cgpa = stud -> cgpa;
    newStudent -> dob = stud -> dob;
    newStudent -> email = stud -> email;
    newStudent -> contact = stud -> contact;
    newStudent -> address = stud -> address;
    newStudent -> bloodGroup = stud -> bloodGroup;
    newStudent -> department = stud -> department;
    newStudent -> semester = stud -> semester;
    newStudent -> isPaymentDone = stud -> isPaymentDone;
    newStudent -> isScholarshipCandidate = stud -> isScholarshipCandidate;
    newStudent -> isGraduated = stud -> isGraduated;

    newStudent -> next = NULL;
    newStudent -> prev = NULL;

    return newStudent;
}

student *createStudent(int id, string name) {
    student *newStudent = new student();

    newStudent -> id = id;
    newStudent -> name = name;
    newStudent -> completedCredits = -1;
    newStudent -> cgpa = -1;
    newStudent -> dob = "Not Given";
    newStudent -> email = "Not Given";
    newStudent -> contact = "Not Given";
    newStudent -> address = "Not Given";
    newStudent -> bloodGroup = "Not Given";
    newStudent -> department = "Not Given";
    newStudent -> semester = 0;
    newStudent -> isPaymentDone = false;
    newStudent -> isScholarshipCandidate = false;
    newStudent -> isGraduated = false;

    newStudent -> next = NULL;
    newStudent -> prev = NULL;

    return newStudent;
}

void insertStudent() {
    student *newStd = createStudent();

    if(head == NULL) {
        head = newStd;
        tail = newStd;
    }
    else {
        tail -> next = newStd;
        newStd -> prev = tail;
        tail = newStd;
    }

    //update by nadim
    system("CLS");
    cout << "\t\t\tA new ID with All Information has been Created!";
    cout << "\n\nPress any key to continue.....";
    getch();
}

void insertStudent(int id) {
    student *newStd = createStudent(id);

    if(head == NULL) {
        head = newStd;
        tail = newStd;
    }
    else {
        tail -> next = newStd;
        newStd -> prev = tail;
        tail = newStd;
    }

    system("CLS");
    cout << "\t\t\tA new ID has been Created!";
    cout << "\n\nPress any key to continue.....";
    getch();

}

void insertStudent(student *stud) {
    student *newStd = createStudent(stud);

    if(head == NULL) {
        head = newStd;
        tail = newStd;
    }
    else {
        tail -> next = newStd;
        newStd -> prev = tail;
        tail = newStd;
    }

}

void insertStudent(int id, string name) {
    student *newStd = createStudent(id, name);

    if(head == NULL) {
        head = newStd;
        tail = newStd;
    }
    else {
        tail -> next = newStd;
        newStd -> prev = tail;
        tail = newStd;
    }

    system("CLS");
    cout << "\t\t\tA new ID with Name has been created!";
    cout << "\n\nPress any key to continue.....";
    getch();
}

void updatePartialData() {
    system("CLS");
    cout << "\t\t\tSTUDENT INFORMATION SYSTEM\n\n";
    cout << "\t\t\tUpdate Incomplete Information\n\n";

    student *updCur = head;
    while (updCur != NULL) {
        cout << "Now Updating ID: " << updCur -> id << endl;
        if (updCur -> name == "Not Given") {
            cout << "Enter Name: ";
            string name; getline(cin >> ws, name);
            updCur -> name = name;
        }
        if (updCur -> completedCredits == -1) {
            cout << "Enter Credits Completed: ";
            double completedCredits; cin >> completedCredits;
            updCur -> completedCredits = completedCredits;
        }
        if (updCur -> cgpa == -1) {
            cout << "Enter Current CGPA: ";
            double cgpa; cin >> cgpa;
            updCur -> cgpa = cgpa;
        }
        if (updCur -> dob == "Not Given") {
            cout << "Enter Date of Birth: ";
            string dob; getline(cin >> ws, dob);
            updCur -> dob = dob;
        }
        if (updCur -> email == "Not Given") {
            cout << "Enter Email: ";
            string email; getline(cin >> ws, email);
            updCur -> email = email;
        }
        if (updCur -> contact == "Not Given") {
            cout << "Enter Contact: ";
            string contact; getline(cin >> ws, contact);
            updCur -> contact = contact;
        }
        if (updCur -> address == "Not Given") {
            cout << "Enter Address: ";
            string address; getline(cin >> ws, address);
            updCur -> address = address;
        }
        if (updCur -> bloodGroup == "Not Given") {
            cout << "Enter BloodGroup: ";
            string bloodGroup; getline(cin >> ws, bloodGroup);
            updCur -> bloodGroup = bloodGroup;
        }
        if (updCur -> department == "Not Given") {
            cout << "Enter Department: ";
            string department; getline(cin >> ws, department);
            updCur -> department = department;
        }
        if (updCur -> semester == 0) {
            cout << "Enter Semester (in digit): ";
            int semester; cin>>semester;
            updCur -> semester = semester;
        }
        if (updCur -> isPaymentDone == false) {
            cout << "Is Payment Done? (0 or 1): ";
            bool isPaymentDone; cin >> isPaymentDone;
            updCur -> isPaymentDone = isPaymentDone;
        }
        if (updCur -> isScholarshipCandidate == false) {
            cout << "Is Scholarship Candidate? (0 or 1): ";
            bool isScholarshipCandidate; cin >> isScholarshipCandidate;
            updCur -> isScholarshipCandidate = isScholarshipCandidate;
        }
        if (updCur -> isGraduated == false) {
            cout << "Is Graduated? (0 or 1): ";
            bool isGraduated; cin >> isGraduated;
            updCur -> isGraduated = isGraduated;
        }

        updCur = updCur -> next;
        cout<<endl;
    }

    system("CLS");
    cout << "\n\n\t\t\tAll Incomplete Information has been Inserted!";
    cout << "\n\nPress any key to continue.....";
    getch();
}

void updateInfoByID() {
    system("CLS");
    string input;
    cout << "\t\t\tSTUDENT INFORMATION SYSTEM\n\n";
    cout << "\t\t\t      Update Queue\n\n";

    cout << "\nEnter an ID to Update: ";
    int id; cin >> id;
    student *updCur = head;
    while (updCur != NULL) {
        if (updCur -> id == id) break;
        updCur = updCur -> next;
    }
    if (updCur == NULL) {
        cout << "\n\t\t\tID was not found!" << endl;
        cout << "\t\t\tPlease try again..." << endl;
        getch();
        updateInfoByID();
        return;
    }
    cout << "Student ID: " << updCur -> id << endl;
    cout << "\nSerial\t" << "Info" << endl;
    cout << "1.\t" << "Name\t\t\t: " << updCur -> name << endl;
    cout << "2.\t" << "Credits\t\t\t: " << updCur -> completedCredits << endl;
    cout << "3.\t" << "CGPA\t\t\t: " << updCur -> cgpa << endl;
    cout << "4.\t" << "DoB\t\t\t: " << updCur -> dob << endl;
    cout << "5.\t" << "Email\t\t\t: " << updCur -> email << endl;
    cout << "6.\t" << "Contact\t\t\t: " << updCur -> contact << endl;
    cout << "7.\t" << "Address\t\t\t: " << updCur -> address << endl;
    cout << "8.\t" << "Blood Group\t\t: " << updCur -> bloodGroup << endl;
    cout << "9.\t" << "Department\t\t: " << updCur -> department << endl;
    cout << "10.\t" << "Semester\t\t: " << updCur -> semester << endl;
    cout << "11.\t" << "Paid?\t\t\t: " << updCur -> isPaymentDone << endl;
    cout << "12.\t" << "Scholarship Candidate?\t: " << updCur -> isScholarshipCandidate << endl;
    cout << "13.\t" << "Graduated?\t\t: " << updCur -> isGraduated << endl;

    string yn = "yes";
    while (yn == "yes") {
        cout << "\nWant to Update Anything? YES / NO : ";
        cin >> yn;
        transform(yn.begin(), yn.end(), yn.begin(), ::tolower);
        if (yn == "yes") {
            cout << "Enter a Serial to Update: ";
            int serial; cin >> serial;
            if (serial == 1) {
                cout << "\nEnter Name to Update: ";
                string name; cin >> name;
                updCur -> name = name;
            } else if (serial == 2) {
                cout << "Enter Credit Count to Update: ";
                double completedCredits; cin >> completedCredits;
                updCur -> completedCredits = completedCredits;
            } else if (serial == 3) {
                cout << "Enter CGPA to Update: ";
                double cgpa; cin >> cgpa;
                updCur -> cgpa = cgpa;
            } else if (serial == 4) {
                cout << "Enter Date of Birth to Update: ";
                string dob; cin >> dob;
                updCur -> dob = dob;
            } else if (serial == 5) {
                cout << "Enter Email to Update: ";
                string email; cin >> email;
                updCur -> email = email;
            } else if (serial == 6) {
                cout << "Enter Contact to Update: ";
                string contact; cin >> contact;
                updCur -> contact = contact;
            } else if (serial == 7) {
                cout << "Enter Address to Update: ";
                string address; cin >> address;
                updCur -> address = address;
            } else if (serial == 8) {
                cout << "Enter Blood Group to Update: ";
                string bloodGroup; cin >> bloodGroup;
                updCur -> bloodGroup = bloodGroup;
            } else if (serial == 9) {
                cout << "Enter Department to Update: ";
                string department; cin >> department;
                updCur -> department= department;
            } else if (serial == 10) {
                cout << "Enter Semester to Update (in digit): ";
                int semester; cin >> semester;
                updCur -> semester = semester;
            } else if (serial == 11) {
                cout << "Enter Payment Status to Update (0 or 1): ";
                bool isPaymentDone; cin >> isPaymentDone;
                updCur -> isPaymentDone = isPaymentDone;
            } else if (serial == 12) {
                cout << "Enter Scholarship Status to Update (0 or 1): ";
                bool isScholarshipCandidate; cin >> isScholarshipCandidate;
                updCur -> isScholarshipCandidate = isScholarshipCandidate;
            } else if (serial == 13) {
                cout << "Enter Graduate Status to Update (0 or 1): ";
                bool isGraduated; cin >> isGraduated;
                updCur -> isGraduated = isGraduated;
            } else {
                cout << "Invalid Serial!" << endl;
            }
        }
        else {
            updateStudentInfo();
        }
    }

}

void deleteAllInfo(){
    while (true) {
        student *temp = head;
        if (temp == NULL) {
            head = NULL;
            tail = NULL;
            return;
        }
        if (head == tail) {
            head = NULL;
            tail = NULL;
        }
        else {
            head = head -> next;
            head -> prev = NULL;
        }
        delete temp;
    }
}

void deleteByID(int id){
    if(head -> id == id) {
        student* temp = head;
        if (head == tail) {
            head = NULL;
            tail = NULL;
        }
        else {
            head = head -> next;
            head -> prev = NULL;
        }
        delete temp;
        return;
    }
    if(tail -> id == id) {
        student* temp = tail;
        if (head == tail) {
            head = NULL;
            tail = NULL;
        }
        else {
            tail = tail -> prev;
            tail -> next = NULL;
        }
        delete temp;
        return;
    }
    if(head == tail) {
        cout << "ID not found!" << endl;
        return;
    }
    student* cur = head;
    while(cur -> next -> id != id) {
        cur = cur -> next;
        if(cur -> next == NULL || cur == NULL) {
            cout << "ID not found!" << endl;
            return;
        }
    }
    student* temp = cur -> next;
    student* after_temp = temp -> next;
    cur -> next = cur -> next -> next;
    after_temp -> prev = cur;
    delete temp;

}

void deleteByName(string name){
    while (head && head -> name == name) {
        student* temp = head;
        if (head == tail) {
            head = NULL;
            tail = NULL;
        }
        else {
            head = head -> next;
            head -> prev = NULL;
        }
        delete temp;
    }
    while (tail && tail -> name == name) {
        student* temp = tail;
        if (head == tail) {
            head = NULL;
            tail = NULL;
        }
        else {
            tail = tail -> prev;
            tail -> next = NULL;
        }
        delete temp;
    }
    if(head == tail) {
        cout << "Name not found" << endl;
        return;
    }
    for (student *cur = head; cur != NULL; cur = cur -> next) {
        if (cur -> next != NULL && cur -> next -> name == name) {
            student *temp = cur -> next;
            student *after_temp = temp -> next;
            cur -> next = after_temp;
            after_temp -> prev = cur;
            delete temp;
        }
    }
}

void deleteByCGPA(double cgpa, string dir) {
    if (dir == "=") {
        while (head && head -> cgpa == cgpa) {
            student* temp = head;
            if (head == tail) {
                head = NULL;
                tail = NULL;
            }
            else {
                head = head -> next;
                head -> prev = NULL;
            }
            delete temp;
        }
        while (tail && tail -> cgpa == cgpa) {
            student* temp = tail;
            if (head == tail) {
                head = NULL;
                tail = NULL;
            }
            else {
                tail = tail -> prev;
                tail -> next = NULL;
            }
            delete temp;
        }
        if(head == tail) {
            // cout << "Some Process Done!\nNo Other ID Found to Delete by Required CGPA!" << endl;
            return;
        }

        for (student *cur = head; cur != NULL; cur = cur -> next) {
            if (cur -> next != NULL && cur -> next -> cgpa == cgpa) {
                student *temp = cur -> next;
                student *after_temp = temp -> next;
                cur -> next = after_temp;
                after_temp -> prev = cur;
                delete temp;
            }
        }
    }
    else if (dir == "<") {
        while (head && head -> cgpa < cgpa) {
            student* temp = head;
            if (head == tail) {
                head = NULL;
                tail = NULL;
            }
            else {
                head = head -> next;
                head -> prev = NULL;
            }
            delete temp;
        }
        while (tail && tail -> cgpa < cgpa) {
            student* temp = tail;
            if (head == tail) {
                head = NULL;
                tail = NULL;
            }
            else {
                tail = tail -> prev;
                tail -> next = NULL;
            }
            delete temp;
        }
        if(head == tail) {
            // cout << "Some Process Done!\nNo Other ID Found to Delete by Required CGPA!" << endl;
            return;
        }

        for (student *cur = head; cur != NULL; cur = cur -> next) {
            if (cur -> next != NULL && cur -> next -> cgpa < cgpa) {
                student *temp = cur -> next;
                student *after_temp = temp -> next;
                cur -> next = after_temp;
                after_temp -> prev = cur;
                delete temp;
            }
        }
    }
    else if (dir == ">") {
        while (head && head -> cgpa > cgpa) {
            student* temp = head;
            if (head == tail) {
                head = NULL;
                tail = NULL;
            }
            else {
                head = head -> next;
                head -> prev = NULL;
            }
            delete temp;
        }
        while (tail && tail -> cgpa > cgpa) {
            student* temp = tail;
            if (head == tail) {
                head = NULL;
                tail = NULL;
            }
            else {
                tail = tail -> prev;
                tail -> next = NULL;
            }
            delete temp;
        }
        if(head == tail) {
            // cout << "Some Process Done!\nNo Other ID Found to Delete by Required CGPA!" << endl;
            return;
        }

        for (student *cur = head; cur != NULL; cur = cur -> next) {
            if (cur -> next != NULL && cur -> next -> cgpa > cgpa) {
                student *temp = cur -> next;
                student *after_temp = temp -> next;
                cur -> next = after_temp;
                after_temp -> prev = cur;
                delete temp;
            }
        }
    }
    else if (dir == "<=") {
        while (head && head -> cgpa <= cgpa) {
            student* temp = head;
            if (head == tail) {
                head = NULL;
                tail = NULL;
            }
            else {
                head = head -> next;
                head -> prev = NULL;
            }
            delete temp;
        }
        while (tail && tail -> cgpa <= cgpa) {
            student* temp = tail;
            if (head == tail) {
                head = NULL;
                tail = NULL;
            }
            else {
                tail = tail -> prev;
                tail -> next = NULL;
            }
            delete temp;
        }
        if(head == tail) {
            // cout << "Some Process Done!\nNo Other ID Found to Delete by Required CGPA!" << endl;
            return;
        }

        for (student *cur = head; cur != NULL; cur = cur -> next) {
            if (cur -> next != NULL && cur -> next -> cgpa <= cgpa) {
                student *temp = cur -> next;
                student *after_temp = temp -> next;
                cur -> next = after_temp;
                after_temp -> prev = cur;
                delete temp;
            }
        }
    }
    else if (dir == ">=") {
        while (head && head -> cgpa >= cgpa) {
            student* temp = head;
            if (head == tail) {
                head = NULL;
                tail = NULL;
            }
            else {
                head = head -> next;
                head -> prev = NULL;
            }
            delete temp;
        }
        while (tail && tail -> cgpa >= cgpa) {
            student* temp = tail;
            if (head == tail) {
                head = NULL;
                tail = NULL;
            }
            else {
                tail = tail -> prev;
                tail -> next = NULL;
            }
            delete temp;
        }
        if(head == tail) {
            // cout << "Some Process Done!\nNo Other ID Found to Delete by Required CGPA!" << endl;
            return;
        }

        for (student *cur = head; cur != NULL; cur = cur -> next) {
            if (cur -> next != NULL && cur -> next -> cgpa >= cgpa) {
                student *temp = cur -> next;
                student *after_temp = temp -> next;
                cur -> next = after_temp;
                after_temp -> prev = cur;
                delete temp;
            }
        }
    }
}

void deleteByGradStatus() {
    while (head && head -> isGraduated == true) {
        student* temp = head;
        if (head == tail) {
            head = NULL;
            tail = NULL;
        }
        else {
            head = head -> next;
            head -> prev = NULL;
        }
        delete temp;
    }
    while (tail && tail -> isGraduated == true) {
        student* temp = tail;
        if (head == tail) {
            head = NULL;
            tail = NULL;
        }
        else {
            tail = tail -> prev;
            tail -> next = NULL;
        }
        delete temp;
    }
    if(head == tail) {
        // cout << "Some Process Done!\nNo Other ID Found to Delete by Required CGPA!" << endl;
        return;
    }

    for (student *cur = head; cur != NULL; cur = cur -> next) {
        if (cur -> next != NULL && cur -> next -> isGraduated == true) {
            student *temp = cur -> next;
            student *after_temp = temp -> next;
            cur -> next = after_temp;
            after_temp -> prev = cur;
            delete temp;
        }
    }
}

void deleteProbatedStudents() {
    while (head && head -> cgpa < 2.0) {
        student* temp = head;
        if (head == tail) {
            head = NULL;
            tail = NULL;
        }
        else {
            head = head -> next;
            head -> prev = NULL;
        }
        delete temp;
    }
    while (tail && tail -> cgpa < 2.0) {
        student* temp = tail;
        if (head == tail) {
            head = NULL;
            tail = NULL;
        }
        else {
            tail = tail -> prev;
            tail -> next = NULL;
        }
        delete temp;
    }
    if(head == tail) {
        // cout << "Some Process Done!\nNo Other ID Found to Delete by Required CGPA!" << endl;
        return;
    }

    for (student *cur = head; cur != NULL; cur = cur -> next) {
        if (cur -> next != NULL && cur -> next -> cgpa < 2.0) {
            student *temp = cur -> next;
            student *after_temp = temp -> next;
            cur -> next = after_temp;
            after_temp -> prev = cur;
            delete temp;
        }
    }
}

bool foundId(int id) {
    student *cur = head;
    while (cur != NULL) {
        if (cur -> id == id) {
            return true;
        } cur = cur -> next;
    } return false;
}

bool foundName(string name) {
    student *cur = head;
    while (cur != NULL) {
        if (cur -> name == name) {
            return true;
        } cur = cur -> next;
    } return false;
}

void searchById(int id) {
    student *cur = head;
    while (cur != NULL) {
        if (cur -> id == id) {
            printSpecificID(cur);
            return;
        } cur = cur -> next;
    }
    cout << "Invalid ID!" << endl;
}

void searchByName(string name) {
    cout << "Student List is Displayed by Name " << endl;
    student *cur = head;
    int cnt = 0;
    while (cur != NULL) {
        if (cur -> name == name) {
            printSpecificID(cur);
            cnt++;
        } cur = cur -> next;
    }
    if (cnt == 0) {
        cout << "Invalid Name!" << endl;
    }
}

void searchByCompletedCredits(double completedCredits, string dir) {
    cout << "Student List is Displayed by Completed Credits" << endl;
    student *cur = head;
    int cnt = 0;
    if (dir == "=") {
        while (cur != NULL) {
            if (cur -> completedCredits == completedCredits) {
                printSpecificID(cur);
                cnt++;
            } cur = cur -> next;
        }
    }
    else if (dir == "<") {
         while (cur != NULL) {
            if (cur -> completedCredits < completedCredits) {
                printSpecificID(cur);
                cnt++;
            } cur = cur -> next;
        }
    }
    else if (dir == ">") {
        while (cur != NULL) {
            if (cur -> completedCredits > completedCredits) {
                printSpecificID(cur);
                cnt++;
            } cur = cur -> next;
        }
    }
    else if (dir == ">=") {
        while (cur != NULL) {
            if (cur -> completedCredits >= completedCredits) {
                printSpecificID(cur);
                cnt++;
            } cur = cur -> next;
        }
    }
    else if (dir == "<=") {
        while (cur != NULL) {
            if (cur -> completedCredits <= completedCredits) {
                printSpecificID(cur);
                cnt++;
            } cur = cur -> next;
        }
    }

    if (cnt == 0) {
        cout << "Not found!" << endl;
    }
}

void searchByCGPA(double cgpa, string dir) {
    cout << "Student List is Displayed by CGPA" << endl;
    student *cur = head;
    int cnt = 0;

    if (dir == "=") {
        while (cur != NULL) {
            if (cur -> cgpa == cgpa) {
                printSpecificID(cur);
                cnt++;
            } cur = cur -> next;
        }
    }
    else if (dir == "<") {
         while (cur != NULL) {
            if (cur -> cgpa < cgpa) {
                printSpecificID(cur);
                cnt++;
            } cur = cur -> next;
        }
    }
    else if (dir == ">") {
        while (cur != NULL) {
            if (cur -> cgpa > cgpa) {
                printSpecificID(cur);
                cnt++;
            } cur = cur -> next;
        }
    }
    else if (dir == ">=") {
        while (cur != NULL) {
            if (cur -> cgpa >= cgpa) {
                printSpecificID(cur);
                cnt++;
            } cur = cur -> next;
        }
    }
    else if (dir == "<=") {
        while (cur != NULL) {
            if (cur -> cgpa <= cgpa) {
                printSpecificID(cur);
                cnt++;
            } cur = cur -> next;
        }
    }

    if (cnt == 0) {
        cout << "CGPA Not Found!" << endl;
    }
}

void searchByContact(string contact) {
    cout << "Student List is Displayed by Contact" << endl;
    student *cur = head;
    while (cur != NULL) {
        if (cur -> contact == contact) {
            printSpecificID(cur);
            return;
        } cur = cur -> next;
    }
    cout << "Invalid Contact Number!" << endl;
}

void searchByBloodGroup(string bloodGroup) {
    cout << "Student List is Displayed by Blood Group" << endl;
    student *cur = head;
    int cnt = 0;
    while (cur != NULL) {
        if (cur -> bloodGroup == bloodGroup) {
            printSpecificID(cur);
            cnt++;
        } cur = cur -> next;
    }
    if (cnt == 0) {
        cout << "Invalid Blood Group!" << endl;
    }
}

void searchByDepartment(string department) {
    cout << "Student List is Displayed by Department" << endl;
    student *cur = head;
    int cnt = 0;
    while (cur != NULL) {
        if (cur -> department == department) {
            printSpecificID(cur);
            cnt++;
        } cur = cur -> next;
    }
    if (cnt == 0) {
        cout << "Not found!" << endl;
    }
}

void searchBySemester(int semester) {
    cout << "Student List is Displayed by Semester" << endl;
    student *cur = head;
    int cnt = 0;
    while (cur != NULL) {
        if (cur -> semester == semester) {
            printSpecificID(cur);
            cnt++;
        } cur = cur -> next;
    }
    if (cnt == 0) {
        cout << "Not found!" << endl;
    }
}

void searchByUnpaidStudents(bool isPaymentDone) {
    cout << "Student List is Displayed by Payment Status" << endl;
    student *cur = head;
    int cnt = 0;
    while (cur != NULL) {
        if (cur -> isPaymentDone == false) {
            printSpecificID(cur);
            cnt++;
        } cur = cur -> next;
    }
    if (cnt == 0) {
        cout << "payment clear" << endl;
    }
}

void searchByGraduateStudents(bool isGraduated) {
    cout << "Student List is Displayed by Graduate Status" << endl;
    student *cur = head;
    int cnt = 0;
    while (cur != NULL) {
        if (cur -> isGraduated == true) {
            printSpecificID(cur);
            cnt++;
        } cur = cur -> next;
    }
    if (cnt == 0) {
        cout << "No Graduate Students!" << endl;
    }
}

void searchByProbationStudents() {
    cout << "Student List is Displayed by Probation Students" << endl;
    student *cur = head;
    int cnt = 0;
    while (cur != NULL) {
        if (cur -> cgpa < 2.00) {
            printSpecificID(cur);
            cnt++;
        } cur = cur -> next;
    }
    if (cnt == 0) {
        cout << "\n\nNo Probated Student!" << endl;
    }
}

void sortByID() {
    student *sorted = NULL;
    student *cur = head;

    while (cur != NULL) {
        student *next = cur -> next;
        cur -> prev = cur -> next = NULL;

        student* temp;
        if (sorted == NULL) {
            sorted = cur;
        }
        else if (sorted -> id >= cur -> id) {
            cur -> next = sorted;
            cur -> next -> prev = cur;
            sorted = cur;
        }
        else {
            temp = sorted;
            while (temp -> next != NULL && temp -> next -> id < cur -> id) {
                temp = temp -> next;
            }

            cur -> next = temp -> next;
            if (temp -> next != NULL) {
                cur -> next -> prev = cur;
            }
            temp -> next = cur;
            cur -> prev = temp;
        }
        cur = next;
    }

    head = sorted;
    student *studentTrv = head;
    while (studentTrv -> next != NULL) {
        studentTrv = studentTrv -> next;
    }
    tail -> prev = studentTrv -> prev;
    tail = studentTrv;
    tail -> next = NULL;
}

void sortByName(){
    student *sorted = NULL;
    student *cur = head;
    while (cur != NULL) {
        student *next = cur -> next;
        cur -> prev = cur -> next = NULL;

        student* temp;
        if (sorted == NULL) {
            sorted = cur;
        }
        else if (sorted -> name >= cur -> name) {
            cur -> next = sorted;
            cur -> next -> prev = cur;
            sorted = cur;
        }
        else {
            temp = sorted;
            while (temp -> next != NULL && temp -> next -> name < cur -> name) {
                temp = temp -> next;
            }

            cur -> next = temp -> next;
            if (temp -> next != NULL) {
                cur -> next -> prev = cur;
            }
            temp -> next = cur;
            cur -> prev = temp;
        }
        cur = next;
    }

    head = sorted;
    student *studentTrv = head;
    while (studentTrv -> next != NULL) {
        studentTrv = studentTrv -> next;
    }
    tail -> prev = studentTrv -> prev;
    tail = studentTrv;
    tail -> next = NULL;
}

void sortByCGPA(){
    student *sorted = NULL;
    student *cur = head;

    while (cur != NULL) {
        student *next = cur -> next;
        cur -> prev = cur -> next = NULL;

        student* temp;
        if (sorted == NULL) {
            sorted = cur;
        }
        else if (sorted -> cgpa >= cur -> cgpa) {
            cur -> next = sorted;
            cur -> next -> prev = cur;
            sorted = cur;
        }
        else {
            temp = sorted;
            while (temp -> next != NULL && temp -> next -> cgpa < cur -> cgpa) {
                temp = temp -> next;
            }

            cur -> next = temp -> next;
            if (temp -> next != NULL) {
                cur -> next -> prev = cur;
            }
            temp -> next = cur;
            cur -> prev = temp;
        }
        cur = next;
    }

    head = sorted;
    student *studentTrv = head;
    while (studentTrv -> next != NULL) {
        studentTrv = studentTrv -> next;
    }
    tail -> prev = studentTrv -> prev;
    tail = studentTrv;
    tail -> next = NULL;
}

void sortBySemester(){
    student *sorted = NULL;
    student *cur = head;

    while (cur != NULL) {
        student *next = cur -> next;
        cur -> prev = cur -> next = NULL;

        student* temp;
        if (sorted == NULL) {
            sorted = cur;
        }
        else if (sorted -> semester >= cur -> semester) {
            cur -> next = sorted;
            cur -> next -> prev = cur;
            sorted = cur;
        }
        else {
            temp = sorted;
            while (temp -> next != NULL && temp -> next -> semester < cur -> semester) {
                temp = temp -> next;
            }

            cur -> next = temp -> next;
            if (temp -> next != NULL) {
                cur -> next -> prev = cur;
            }
            temp -> next = cur;
            cur -> prev = temp;
        }
        cur = next;
    }

    head = sorted;
    student *studentTrv = head;
    while (studentTrv -> next != NULL) {
        studentTrv = studentTrv -> next;
    }
    tail -> prev = studentTrv -> prev;
    tail = studentTrv;
    tail -> next = NULL;
}

void sortByDepartment(){
    student *sorted = NULL;
    student *cur = head;

    while (cur != NULL) {
        student *next = cur -> next;
        cur -> prev = cur -> next = NULL;

        student* temp;
        if (sorted == NULL) {
            sorted = cur;
        }
        else if (sorted -> department >= cur -> department) {
            cur -> next = sorted;
            cur -> next -> prev = cur;
            sorted = cur;
        }
        else {
            temp = sorted;
            while (temp -> next != NULL && temp -> next -> department < cur -> department) {
                temp = temp -> next;
            }

            cur -> next = temp -> next;
            if (temp -> next != NULL) {
                cur -> next -> prev = cur;
            }
            temp -> next = cur;
            cur -> prev = temp;
        }
        cur = next;
    }

    head = sorted;
    student *studentTrv = head;
    while (studentTrv -> next != NULL) {
        studentTrv = studentTrv -> next;
    }
    tail -> prev = studentTrv -> prev;
    tail = studentTrv;
    tail -> next = NULL;
}

void sortByCompletedCredits(){
    student *sorted = NULL;
    student *cur = head;

    while (cur != NULL) {
        student *next = cur -> next;
        cur -> prev = cur -> next = NULL;

        student* temp;
        if (sorted == NULL) {
            sorted = cur;
        }
        else if (sorted -> completedCredits >= cur -> completedCredits) {
            cur -> next = sorted;
            cur -> next -> prev = cur;
            sorted = cur;
        }
        else {
            temp = sorted;
            while (temp -> next != NULL && temp -> next -> completedCredits < cur -> completedCredits) {
                temp = temp -> next;
            }

            cur -> next = temp -> next;
            if (temp -> next != NULL) {
                cur -> next -> prev = cur;
            }
            temp -> next = cur;
            cur -> prev = temp;
        }
        cur = next;
    }

    head = sorted;
    student *studentTrv = head;
    while (studentTrv -> next != NULL) {
        studentTrv = studentTrv -> next;
    }
    tail -> prev = studentTrv -> prev;
    tail = studentTrv;
    tail -> next = NULL;
}


int mainMenu() {
    system("CLS");
    cout << "\t\t\tSTUDENT INFORMATION SYSTEM\n\n";
    cout << "\t\t\t\tMain Menu\n\n";
    cout << "  I N D E X \n\n";
    cout << "\t1. Show Student List\n";
    cout << "\t2. Add Student Information\n";
    cout << "\t3. Update Student Information\n";
    cout << "\t4. Delete Student Information\n";
    cout << "\t5. Search Student Information\n";
    cout << "\t6. Sort Student List\n";
    cout << "\t7. Generate Report\n\n";
    cout << "\t0. Exit\n";

    cout << "\n   Enter Your Instruction: ";
    int input; cin >> input;
    return input;
}

void showStudentInfo() {
    system("CLS");
    cout<<"\t\t\tSTUDENT INFORMATION SYSTEM\n\n";
    cout<<"\t\t\t   All Information\n\n";
    student *temp = head;
    int cnt = 0;
    string output;
    while(temp != NULL) {
        cout << "  Student " << ++cnt << ":   ID - " << temp -> id << endl;

        cout << "\n\t" << "Info\n" << endl;
        cout << "\t" << "Name\t\t\t: " << temp -> name << endl;
        cout << "\t" << "Credits\t\t\t: " << temp -> completedCredits << endl;
        cout << "\t" << "CGPA\t\t\t: " << temp -> cgpa << endl;
        cout << "\t" << "Date of Birth\t\t: " << temp -> dob << endl;
        cout << "\t" << "Email\t\t\t: " << temp -> email << endl;
        cout << "\t" << "Contact\t\t\t: " << temp -> contact << endl;
        cout << "\t" << "Address\t\t\t: " << temp -> address << endl;
        cout << "\t" << "Blood Group\t\t: " << temp -> bloodGroup << endl;
        cout << "\t" << "Department\t\t: " << temp -> department << endl;
        cout << "\t" << "Semester\t\t: " << temp -> semester << endl;
        output=(temp -> isPaymentDone == 0) ? ": NO" : ": YES";
        cout << "\t" << "Paid?\t\t\t" << output << endl;
        output=(temp -> isScholarshipCandidate == 0) ? ": NO" : ": YES";
        cout << "\t" << "Scholarship Candidate?\t" << output << endl;
        output=(temp -> isGraduated == 0) ? ": NO" : ": YES";
        cout << "\t" << "Graduated?\t\t" << output << endl;
        temp = temp -> next;
        cout << "\n\n";
    }
    if (cnt==0) {
        cout<<"\n\n\n\tEmpty Student Information!\n\n";
    }

}

void addStudentInfo() {
    system("CLS");
    cout << "\t\t\tSTUDENT INFORMATION SYSTEM\n\n";
    cout << "\t\t\tInsert Information\n\n";

    cout << "\t1. Insert All Information\n";
    cout << "\t2. Insert By ID\n";
    cout << "\t3. Insert By ID & Name\n";
    cout << "\t<. Return to Main Menu\n";
    cout << "\n\t0. Exit\n";

    cout << "\nEnter your Instruction: ";
    string input; cin >> input;
    if (input=="1") {
        insertStudent();
    }
    else if (input=="2") {
        int ID;
        cout<<"\nEnter ID: ";
        cin>>ID;
        insertStudent(ID);
    }
    else if (input=="3") {
        int id;
        string name;
        cout<<"\nEnter ID: ";
        cin>>id;
        cout<<"Enter Name: ";
        getline(cin >> ws, name);
        insertStudent(id, name);
    }
    else if (input=="<") {
        return;
    }
    else if(input=="0") {
        outputManipulation();
        exit(0);
    }
    else {
        cout << "\n\t\t\tInvalid Option!!" << "\n";
        cout << "\t\t       Please try again..." << "\n";
        cout << "\n";
        cout << "Press any key to continue...";
        getch();
        addStudentInfo();
    }
    addStudentInfo();
}

void updateStudentInfo() {
    system("CLS");
    cout << "\t\t\tSTUDENT INFORMATION SYSTEM\n\n";
    cout << "\t\t\t    Update Information\n\n";

    cout << "\n\t1. Update By ID"<<endl;
    cout << "\t2. Update Incomplete Student List"<<endl;
    cout << "\t<. Return to Main Menu"<<endl;

    cout << "\n\t0. Exit"<<endl;

    cout << "\n\nEnter your Instruction: ";
    string input; cin >> input;

    if (input=="1") {
        updateInfoByID();
    }
    else if (input=="2") {
        updatePartialData();
    }
    else if (input=="<") {
        return;
    }
    else if (input=="0") {
        outputManipulation();
        exit(0);
    }
    else {
        cout << "\n\t\t\tInvalid Option!!" << "\n";
        cout << "\t\t       Please try again..." << "\n";
        cout << "\n";
        cout << "Press any key to continue...";
        getch();
        updateStudentInfo();
    }
}

void deleteStudentInfo() {
    system("CLS");
    cout << "\t\t\tSTUDENT INFORMATION SYSTEM\n\n";
    cout << "\t\t\t    Delete Information\n\n";

    cout << "\t1. Delete All Information\n";
    cout << "\t2. Delete By ID\n";
    cout << "\t3. Delete By Name\n";
    cout << "\t4. Delete By CGPA\n";
    cout << "\t5. Delete By Graduation Status\n";
    cout << "\t<. Return to Main Menu\n";

    cout<<"\n\t0. Exit\n";

    cout << "\nEnter your Instruction: ";
    string input; cin>>input;
    if (input=="1") {
        deleteAllInfo();
        system("CLS");
        cout<<"\t\t\tSTUDENT INFORMATION SYSTEM\n\n";
        cout<<"\t\t\t    Delete Information\n\n";
        cout<<"\n\n\t\t\tAll Information has been deleted!\n"<<endl;
        cout<<"\n\n\nPress any key to continue...";
        getch();
    }
    else if (input=="2") {
        int id;
        cout<<"\nEnter ID: ";
        cin>>id;
        system("CLS");
        cout<<"\t\t\tSTUDENT INFORMATION SYSTEM\n\n";
        cout<<"\t\t\t    Delete Information\n\n";
        if (foundId(id)) {
            deleteByID(id);
            cout << "\n\n\t\t\tAll Information of ID: " << id << " has been Removed!" << endl;
            cout << "\n\n\nPress any key to continue...";
            getch();
        }
        else {
            cout << "\t\tID Not Found!" << endl;
            cout << "\t\tPlease try again...";
            getch();
        }
        getch();
    } else if (input=="3") {
        string name;
        cout<<"\nEnter Name: ";
        getline(cin>>ws, name);
        system("CLS");
        cout<<"\t\t\tSTUDENT INFORMATION SYSTEM\n\n";
        cout<<"\t\t\t    Delete Information\n\n";
        if (foundName(name)) {
            deleteByName(name);
            cout << "\n\n\t\t\tAll Information of Name: " << name << " has been Removed!" << endl;
            cout << "\n\n\nPress any key to continue...";
        }
        else {
            cout << "\t\tID Not Found!" << endl;
            cout << "\t\tPlease try again...";
        }

        getch();
    }
    else if (input=="4") {
        double cgpa;
        cout << "\nEnter CGPA: ";
        cin >> cgpa;
        cout << "Enter Direction (=, <, >, <=, >=): ";
        string dir; cin >> dir;
        deleteByCGPA(cgpa, dir);
        system("CLS");
        cout<<"\t\t\tSTUDENT INFORMATION SYSTEM\n\n";
        cout<<"\t\t\t    Delete Information\n\n";
        cout << "\n\n\t\tAll Information of CGPA: " << cgpa << " with direction: " << dir << " has been Removed!" << endl;
        cout << "\n\n\nPress any key to continue...";
        getch();
    }
    else if (input=="5") {
        void deleteByGradStatus();
        system("CLS");
        cout<<"\t\t\tSTUDENT INFORMATION SYSTEM\n\n";
        cout<<"\t\t\t    Delete Information\n\n";
        cout << "\n\n\t\tAll Information of Graduated Students has been Removed!" << endl;
        cout << "\n\n\nPress any key to continue...";
        getch();
    }
    else if (input=="<") {
        return;
    }
    else if(input=="0") {
        outputManipulation();
        exit(0);
    }
    else {
        cout << "\n\t\t\tInvalid Option!!" << "\n";
        cout << "\t\t       Please try again..." << "\n";
        cout << "\n";
        cout << "Press any key to continue...";
        getch();
        deleteStudentInfo();
    }
    deleteStudentInfo();
}

void searchStudentInfo() {
    system("CLS");
    cout << "\t\t\tSTUDENT INFORMATION SYSTEM\n\n";
    cout << "\t\t\tSearch Information\n\n";

    cout << "\t1. Search By ID\n";
    cout << "\t2. Search By Name\n";
    cout << "\t3. Search By Contact\n";
    cout << "\t4. Search By CGPA\n";
    cout << "\t5. Search By Blood Group\n";
    cout << "\t6. Search By Semester\n";
    cout << "\t7. Search By Department\n";
    cout << "\t8. Search By Completed Credits\n";
    cout << "\t9. Search By Unpaid Students\n";
    cout << "\t10. Search By Graduate Students\n";
    cout << "\t11. Search By Probation Students\n";
    cout << "\t<. Return to Main Menu\n";

    cout << "\n\t0. Exit\n";

    cout << "\nEnter your Instruction: ";
    string input; cin>>input;

    system("CLS");
    cout << "\t\t\tSTUDENT INFORMATION SYSTEM\n\n";
    cout << "\t\t\tSearch Information\n\n";

    if (input == "1") {
        int id;
        cout<<"\nEnter ID to Search: ";
        cin>>id;
        searchById(id);
    }
    else if (input=="2") {
        string name;
        cout<<"\nEnter Name to Search: ";
        getline(cin>>ws, name);
        searchByName(name);
    }
    else if (input=="3") {
        string contact;
        cout<<"\nEnter Contact to Search: ";
        getline(cin>>ws, contact);
        searchByContact(contact);
    }
    else if (input=="4") {
        double cgpa;
        string dir;
        cout<<"\nEnter CGPA to Search: ";
        cin>>cgpa;
        cout<<"\nChoose an Option: \n";
        cout<<"\t<. Less than the CGPA\n";
        cout<<"\t>. Greater than the CGPA\n";
        cout<<"\t=. Equal to the CGPA\n";
        cout<<"\t<=. Less than or equal to the CGPA\n";
        cout<<"\t>=. Greater than or equal to the CGPA\n";

        cout<<"\nEnter your Instruction: ";
        getline(cin>>ws, dir);
        searchByCGPA(cgpa, dir);
    }
    else if (input=="5") {
        string bloodGroup;
        cout<<"\nEnter Blood Group to Search: ";
        getline(cin>>ws, bloodGroup);
        searchByBloodGroup(bloodGroup);
    }
    else if (input=="6") {
        int semester;
        cout<<"\nEnter Semester to Search: ";
        cin>>semester;
        searchBySemester(semester);
    }
    else if (input=="7") {
        string department;
        cout<<"\nEnter Department to Search: ";
        getline(cin>>ws, department);
        searchByDepartment(department);
    }
    else if (input=="8") {
        int completedCredits;
        string dir;
        cout<<"\nEnter Completed Credits to Search: ";
        cin>>completedCredits;
        cout<<"\nChoose an Option: \n";
        cout<<"\t<. Less than the Completed Credits\n";
        cout<<"\t>. Greater than the Completed Credits\n";
        cout<<"\t=. Equal to the Completed Credits\n";
        cout<<"\t<=. Less than or equal to the Completed Credits\n";
        cout<<"\t>=. Greater than or equal to the Completed Credits\n";

        cout<<"\nEnter your Instruction: ";
        getline(cin>>ws, dir);
        searchByCompletedCredits(completedCredits, dir);
    }
    else if (input=="9") {
        searchByUnpaidStudents(false);
    }
    else if (input=="10") {
        searchByGraduateStudents(true);
    }
    else if (input=="11") {
        searchByProbationStudents();
    }
    else if (input=="<") {
        return;
    }
    else if (input=="0") {
        outputManipulation();
        exit(0);
    }
    else {
        cout << "\n\t\t\tInvalid Option!!" << "\n";
        cout << "\t\t       Please try again..." << "\n";
        cout << "\n";
        cout << "Press any key to continue...";
        getch();
        searchStudentInfo();
    }
    cout<<"\n\n\nPress any key to continue...";
    getch();
    searchStudentInfo();
}

void sortStudentInfo() {
    system("CLS");

    string line;
    cout<<"\t\t\tSTUDENT INFORMATION SYSTEM\n\n";
    cout<<"\t\t\tSort Information\n\n";

    cout << "\t1. Sort By ID\n";
    cout << "\t2. Sort By Name\n";
    cout << "\t3. Sort By CGPA\n";
    cout << "\t4. Sort By Semester\n";
    cout << "\t5. Sort By Department\n";
    cout << "\t6. Sort By Completed Credits\n";
    cout << "\t<. Return to Main Menu\n";

    cout << "\n\t0. Exit\n";

    cout << "\nEnter your Instruction: ";
    string input; cin >> input;

    if (input=="1") {
        sortByID();
        system("CLS");
        cout<<"\t\t\tSTUDENT INFORMATION SYSTEM\n\n";
        cout<<"\t\t\tSort Information\n\n";
        cout<<"\n\n\tInformation is sorted by ID!\n";
        cout<<"\n\nDo you want to the Sorted Student List by ID? (YES / NO): ";
        getline(cin>>ws, line);
        transform(line.begin(), line.end(), line.begin(), ::tolower);
        if(line=="yes"){
            showStudentInfo();
            cout<<"\n\nPress any key to continue...";
            getch();
        }
    }
    else if (input=="2") {
        sortByName();
        system("CLS");
        cout<<"\t\t\tSTUDENT INFORMATION SYSTEM\n\n";
        cout<<"\t\t\tSort Information\n\n";
        cout<<"\n\n\tInformation is sorted by Name!\n";
        cout<<"\n\nDo you want to the Sorted Student List by Name? (YES / NO): ";
        getline(cin>>ws, line);
        transform(line.begin(), line.end(), line.begin(), ::tolower);
        if(line=="yes"){
            showStudentInfo();
            cout<<"\n\nPress any key to continue...";
            getch();
        }
    }
    else if (input=="3") {
        sortByCGPA();
        system("CLS");
        cout<<"\t\t\tSTUDENT INFORMATION SYSTEM\n\n";
        cout<<"\t\t\tSort Information\n\n";
        cout<<"\n\n\tInformation is sorted by CGPA!\n";
        cout<<"\n\nDo you want to the Sorted Student List by CGPA? (YES / NO): ";
        getline(cin>>ws, line);
        transform(line.begin(), line.end(), line.begin(), ::tolower);
        if(line=="yes"){
            showStudentInfo();
            cout<<"\n\nPress any key to continue...";
            getch();
        }
    }
    else if (input=="4") {
        sortBySemester();
        system("CLS");
        cout<<"\t\t\tSTUDENT INFORMATION SYSTEM\n\n";
        cout<<"\t\t\tSort Information\n\n";
        cout<<"\n\n\tInformation is sorted by Semester!\n";
        cout<<"\n\nDo you want to the Sorted Student List by Semester? (YES / NO): ";
        getline(cin>>ws, line);
        transform(line.begin(), line.end(), line.begin(), ::tolower);
        if(line=="yes"){
            showStudentInfo();
            cout<<"\n\nPress any key to continue...";
            getch();
        }
    }
    else if (input=="5") {
        sortByDepartment();
        system("CLS");
        cout<<"\t\t\tSTUDENT INFORMATION SYSTEM\n\n";
        cout<<"\t\t\tSort Information\n\n";
        cout<<"\n\n\tInformation is sorted by Department!\n";
        cout<<"\n\nDo you want to the Sorted Student List by Department? (YES / NO): ";
        getline(cin>>ws, line);
        transform(line.begin(), line.end(), line.begin(), ::tolower);
        if(line=="yes"){
            showStudentInfo();
            cout<<"\n\nPress any key to continue...";
            getch();
        }
    }
    else if (input=="6") {
        sortByCompletedCredits();
        system("CLS");
        cout<<"\t\t\tSTUDENT INFORMATION SYSTEM\n\n";
        cout<<"\t\t\tSort Information\n\n";
        cout<<"\n\n\tInformation is sorted by Completed Credits!\n";
        cout<<"\n\nDo you want to the Sorted Student List by Completed Credits? (YES / NO): ";
        getline(cin>>ws, line);
        transform(line.begin(), line.end(), line.begin(), ::tolower);
        if(line=="yes"){
            showStudentInfo();
            cout<<"\n\nPress any key to continue...";
            getch();
        }
    }
    else if (input=="<") {
        return;
    }
    else if (input=="0") {
        outputManipulation();
        exit(0);
    }
    else {
        cout << "\n\t\t\tInvalid Option!!" << "\n";
        cout << "\t\t       Please try again..." << "\n";
        cout << "\nPress any key to continue...";
        getch();
        sortStudentInfo();
    }
    sortStudentInfo();
}

void generateReport(){
    system("CLS");
    cout << "\t\t\tSTUDENT INFORMATION SYSTEM\n\n";
    cout << "\t\t\t    Report Manipulation\n\n";

    cout << "\t1. Report of Every IDs\n";
    cout << "\t2. Report of Specific ID\n";
    cout << "\t3. Report of Semester\n";
    cout << "\t4. Report of CGPA\n";
    cout << "\t5. Report of Probated Students\n";
    cout << "\t<. Return to Main Menu\n";

    cout<<"\n\t0. Exit\n";

    cout << "\nEnter your Instruction: ";
    string input; cin>>input;
    if (input=="1") {
        reportOfEveryIDs();
        system("CLS");
        cout<<"\t\t\tSTUDENT INFORMATION SYSTEM\n\n";
        cout<<"\t\t\t    Report Manipulation\n\n";
        cout<<"\n\n\t\t\tReport of Every IDs has been Created!\n"<<endl;
        cout<<"\n\n\nPress any key to continue...";
        getch();
    }
    else if (input=="2") {
        int id;
        cout<<"\n\nEnter ID: ";
        cin>>id;
        reportOfSpecificID(id);
        system("CLS");
        cout<<"\t\t\tSTUDENT INFORMATION SYSTEM\n\n";
        cout<<"\t\t\t    Report Manipulation\n\n";
        cout<<"\n\n\t\t\tReport of Specific ID has been Created!\n"<<endl;
        cout<<"\n\n\nPress any key to continue...";
        getch();
    } else if (input=="3") {
        int semester;
        cout<<"\n\nEnter Semester (in digit): ";
        cin>>semester;
        reportOfSemester(semester);
        system("CLS");
        cout<<"\t\t\tSTUDENT INFORMATION SYSTEM\n\n";
        cout<<"\t\t\t    Report Manipulation\n\n";
        cout<<"\n\n\t\t\tReport of Semester has been Created!\n"<<endl;
        cout<<"\n\n\nPress any key to continue...";
        getch();
    }
    else if (input=="4") {
        double cgpa;
        string dir;
        cout<<"\n\nEnter CGPA: ";
        cin>>cgpa;
        cout<<"\n\nEnter Direction ( = < > <= >= ): ";
        cin>>dir;
        reportOfCGPA(cgpa, dir);
        system("CLS");
        cout<<"\t\t\tSTUDENT INFORMATION SYSTEM\n\n";
        cout<<"\t\t\t    Report Manipulation\n\n";
        cout<<"\n\n\t\t\tReport of CGPA has been Created!\n"<<endl;
        cout<<"\n\n\nPress any key to continue...";
        getch();
    }
    else if (input=="5") {
        reportOfProbatedStudent();
        system("CLS");
        cout<<"\t\t\tSTUDENT INFORMATION SYSTEM\n\n";
        cout<<"\t\t\t    Report Manipulation\n\n";
        cout<<"\n\n\t\t\tReport of Probated Students has been Created!\n"<<endl;
        cout<<"\n\n\nPress any key to continue...";
        getch();
    }
    else if (input=="<") {
        return;
    }
    else if(input=="0") {
        outputManipulation();
        exit(0);
    }
    else {
        cout << "\n\t\t\tInvalid Option!!" << "\n";
        cout << "\t\t       Please try again..." << "\n";
        cout << "\n";
        cout << "Press any key to continue...";
        getch();
        generateReport();
    }
    generateReport();
}


void printSpecificID(int id) {
    student *updCur = head;
    while (updCur != NULL) {
        if (updCur -> id == id) break;
        updCur = updCur -> next;
    }
    if (updCur == NULL) return;

    cout << "\nDisplayed Info of ";
    cout << "ID: " << updCur -> id << endl;
    cout << "\nSerial\t" << "Info" << endl;
    cout << "\n1.\t" << "Name:\t\t" << updCur -> name << endl;
    cout << "2.\t" << "Credits:\t" << updCur -> completedCredits << endl;
    cout << "3.\t" << "CGPA:\t\t" << updCur -> cgpa << endl;
    cout << "4.\t" << "DoB:\t\t" << updCur -> dob << endl;
    cout << "5.\t" << "Email:\t\t" << updCur -> email << endl;
    cout << "6.\t" << "Contact:\t" << updCur -> contact << endl;
    cout << "7.\t" << "Address:\t" << updCur -> address << endl;
    cout << "8.\t" << "Blood Group:\t" << updCur -> bloodGroup << endl;
    cout << "9.\t" << "Department:\t" << updCur -> department << endl;
    cout << "10.\t" << "Semester:\t" << updCur -> semester << endl;
    cout << "11.\t" << "Paid?\t\t" << updCur -> isPaymentDone << endl;
    cout << "12.\t" << "Scholarship?\t" << updCur -> isScholarshipCandidate << endl;
    cout << "13.\t" << "Graduated?:\t" << updCur -> isGraduated << endl;
}

void printSpecificID(student *updCur) {
    cout << "\nDisplayed Info of ID: " << updCur -> id << endl;
    cout << "\n\t" << "Info" << endl;
    cout << "\n\t" << "Name:\t\t" << updCur -> name << endl;
    cout << "\t" << "Credits:\t" << updCur -> completedCredits << endl;
    cout << "\t" << "CGPA:\t\t" << updCur -> cgpa << endl;
    cout << "\t" << "DoB:\t\t" << updCur -> dob << endl;
    cout << "\t" << "Email:\t\t" << updCur -> email << endl;
    cout << "\t" << "Contact:\t" << updCur -> contact << endl;
    cout << "\t" << "Address:\t" << updCur -> address << endl;
    cout << "\t" << "Blood Group:\t" << updCur -> bloodGroup << endl;
    cout << "\t" << "Department:\t" << updCur -> department << endl;
    cout << "\t" << "Semester:\t" << updCur -> semester << endl;
    cout << "\t" << "Paid?\t\t" << updCur -> isPaymentDone << endl;
    cout << "\t" << "Scholarship?\t" << updCur -> isScholarshipCandidate << endl;
    cout << "\t" << "Graduated?:\t" << updCur -> isGraduated << endl;

}


void inputManipulation() {
    fstream newFile;
    newFile.open("dataset_new.txt", ios::in);
    if (newFile.is_open()) {
        string line;
        student *newStudent;
        int counter = 0;
        while (!newFile.eof()) {
            getline(newFile, line);
            if (counter % 14 == 0) {
                newStudent = new student();
                int id = stringToInteger(line);
                newStudent -> id = id;
            } else if (counter % 14 == 1) {
                newStudent -> name = line;
            } else if (counter % 14 == 2) {
                double credits = stod(line);
                newStudent -> completedCredits = credits;
            } else if (counter % 14 == 3) {
                double cgpa = stod(line);
                newStudent -> cgpa = cgpa;
            } else if (counter % 14 == 4) {
                newStudent -> dob = line;
            } else if (counter % 14 == 5) {
                newStudent -> email = line;
            } else if (counter % 14 == 6) {
                newStudent -> contact = line;
            } else if (counter % 14 == 7) {
                newStudent -> address = line;
            } else if (counter % 14 == 8) {
                newStudent -> bloodGroup = line;
            } else if (counter % 14 == 9) {
                newStudent -> department = line;
            } else if (counter % 14 == 10) {
                int semester = stringToInteger(line);
                newStudent -> semester = semester;
            } else if (counter % 14 == 11) {
                if (line == "0") {
                    newStudent -> isPaymentDone = false;
                } else newStudent -> isPaymentDone = true;
            } else if (counter % 14 == 12) {
                if (line == "0") {
                    newStudent -> isScholarshipCandidate = false;
                } else newStudent -> isScholarshipCandidate = true;
            } else if (counter % 14 == 13) {
                if (line == "0") {
                    newStudent -> isGraduated = false;
                } else newStudent -> isGraduated = true;

                insertStudent(newStudent);
            }
            counter++;
        }
        newFile.close();
    }
}

int stringToInteger(string line){
    int num = 0;
    int n = line.length();
    if(line == "0"){
        return 0;
    }
    else{
        for (int i = 0; i < n; i++)
            num = num * 10 + (int(line[i]) - 48);
        return num;
    }
}

void outputManipulation() {
    fstream newFile;
    newFile.open("dataset_new.txt", ios::out);
    if (newFile.is_open()) {
        student *cur = head;
        while (cur != NULL) {
            string c_id = to_string(cur -> id);
            newFile << c_id << endl;
            newFile << cur -> name << endl;
            string c_completedCredits = to_string(cur -> completedCredits);
            newFile << c_completedCredits << endl;
            string c_cgpa = to_string(cur -> cgpa);
            newFile << c_cgpa << endl;
            newFile << cur -> dob << endl;
            newFile << cur -> email << endl;
            newFile << cur -> contact << endl;
            newFile << cur -> address << endl;
            newFile << cur -> bloodGroup << endl;
            newFile << cur -> department << endl;
            newFile << cur -> semester <<endl;
            if(cur -> isPaymentDone==false)
                newFile << "0" << endl;
            else
                newFile << "1" << endl;
            if(cur -> isScholarshipCandidate==false)
                newFile << "0" << endl;
            else
                newFile << "1" << endl;
            if(cur -> isGraduated==false)
                newFile << "0" << endl;
            else
                newFile << "1" << endl;

            cur = cur -> next;
        }
    }
}

void reportOfSpecificID(int id) {
    student *cur = head;
    while (cur != NULL) {
        if (cur -> id == id) {
            fstream newFile;
            newFile.open("ReportBasedOnSpecificID.txt", ios::out);
            if (newFile.is_open()) {
                newFile << "\t\tReport on ID " << cur -> id << endl<<endl;
                newFile << "\n\t" << "Name:\t\t" << cur -> name << endl;
                newFile << "\t" << "Credits:\t" << cur -> completedCredits << endl;
                newFile << "\t" << "CGPA:\t\t" << cur -> cgpa << endl;
                newFile << "\t" << "DoB:\t\t" << cur -> dob << endl;
                newFile << "\t" << "Email:\t\t" << cur -> email << endl;
                newFile << "\t" << "Contact:\t" << cur -> contact << endl;
                newFile << "\t" << "Address:\t" << cur -> address << endl;
                newFile << "\t" << "Blood Group:\t" << cur -> bloodGroup << endl;
                newFile << "\t" << "Department:\t" << cur -> department << endl;
                newFile << "\t" << "Semester:\t" << cur -> semester << endl;
                if (cur -> isPaymentDone == true) {
                    newFile << "\t" << "Paid?\t\t" << "YES" << endl;
                } else newFile << "\t" << "Paid?\t\t" << "NO" << endl;
                if (cur -> isScholarshipCandidate == true) {
                    newFile << "\t" << "Scholarship?\t" << "YES"<< endl;
                } else  newFile << "\t" << "Scholarship?\t" << "NO" << endl;
                if (cur -> isGraduated == true) {
                    newFile << "\t" << "Graduated?:\t" << "YES" << endl;
                } else newFile << "\t" << "Graduated?:\t" << "NO" << endl;
            }
            cout << "ID Found & Report is Generated!" << endl;
            return;
        } cur = cur -> next;
    }
    cout << "ID Not Found!" << endl;
}

void reportOfEveryIDs() {
    fstream newFile;
    newFile.open("ReportBasedOnEveryIDs.txt", ios::out);
    if (newFile.is_open()) {
        newFile << "\t\tReport of Every IDs\n\n";
        student *cur = head;
        if(cur == NULL) {
            newFile << "No Available Information Found!" << endl;
        }
        while (cur != NULL) {
            newFile << "\t\tReport on ID " << cur -> id << endl;
            newFile << "\n\t" << "Name:\t\t" << cur -> name << endl;
            newFile << "\t" << "Credits:\t" << cur -> completedCredits << endl;
            newFile << "\t" << "CGPA:\t\t" << cur -> cgpa << endl;
            newFile << "\t" << "DoB:\t\t" << cur -> dob << endl;
            newFile << "\t" << "Email:\t\t" << cur -> email << endl;
            newFile << "\t" << "Contact:\t" << cur -> contact << endl;
            newFile << "\t" << "Address:\t" << cur -> address << endl;
            newFile << "\t" << "Blood Group:\t" << cur -> bloodGroup << endl;
            newFile << "\t" << "Department:\t" << cur -> department << endl;
            newFile << "\t" << "Semester:\t" << cur -> semester << endl;
            if (cur -> isPaymentDone == true) {
                newFile << "\t" << "Paid?\t\t" << "YES" << endl;
            } else newFile << "\t" << "Paid?\t\t" << "NO" << endl;
            if (cur -> isScholarshipCandidate == true) {
                 newFile << "\t" << "Scholarship?\t" << "YES"<< endl;
            } else  newFile << "\t" << "Scholarship?\t" << "NO" << endl;
            if (cur -> isGraduated == true) {
                newFile << "\t" << "Graduated?:\t" << "YES" << endl;
            } else newFile << "\t" << "Graduated?:\t" << "NO" << endl;

            newFile << endl << endl;
            cur = cur -> next;
        }
    }
}

void reportOfProbatedStudent() {
    fstream newFile;
    newFile.open("ReportBasedOnProbation.txt", ios::out);
    if (newFile.is_open()) {
        newFile << "\t\tReport on Probation Students\t" << endl << endl;
        student *cur = head;
        if(cur == NULL) {
            newFile << "\n\n\t\tNo Avalable Information Found!" << endl;
        }
        while (cur != NULL) {
            if (cur -> cgpa < 2.0) {
                newFile << "\t\tReport on ID " << cur -> id << endl;
                newFile << "\n\t" << "Name:\t\t" << cur -> name << endl;
                newFile << "\t" << "Credits:\t" << cur -> completedCredits << endl;
                newFile << "\t" << "CGPA:\t\t" << cur -> cgpa << endl;
                newFile << "\t" << "DoB:\t\t" << cur -> dob << endl;
                newFile << "\t" << "Email:\t\t" << cur -> email << endl;
                newFile << "\t" << "Contact:\t" << cur -> contact << endl;
                newFile << "\t" << "Address:\t" << cur -> address << endl;
                newFile << "\t" << "Blood Group:\t" << cur -> bloodGroup << endl;
                newFile << "\t" << "Department:\t" << cur -> department << endl;
                newFile << "\t" << "Semester:\t" << cur -> semester << endl;
                if (cur -> isPaymentDone == true) {
                    newFile << "\t" << "Paid?\t\t" << "YES" << endl;
                } else newFile << "\t" << "Paid?\t\t" << "NO" << endl;
                if (cur -> isScholarshipCandidate == true) {
                    newFile << "\t" << "Scholarship?\t" << "YES"<< endl;
                } else  newFile << "\t" << "Scholarship?\t" << "NO" << endl;
                if (cur -> isGraduated == true) {
                    newFile << "\t" << "Graduated?:\t" << "YES" << endl;
                } else newFile << "\t" << "Graduated?:\t" << "NO" << endl;

                newFile << endl << endl;
            }
            cur = cur -> next;
        }
    }
}

void reportOfSemester(int sem) {
    fstream newFile;
    newFile.open("ReportBasedOnSemester.txt", ios::out);
    if (newFile.is_open()) {
        newFile << "\t\tReport of Semester " << sem << " Students\t" << endl << endl;
        student *cur = head;
        if(cur == NULL) {
            newFile << "\n\n\t\tNo Avalable Information Found!" << endl;
        }
        while (cur != NULL) {
            if (cur -> semester == sem) {
                newFile << "\t\tReport on ID " << cur -> id << endl;
                newFile << "\n\t" << "Name:\t\t" << cur -> name << endl;
                newFile << "\t" << "Credits:\t" << cur -> completedCredits << endl;
                newFile << "\t" << "CGPA:\t\t" << cur -> cgpa << endl;
                newFile << "\t" << "DoB:\t\t" << cur -> dob << endl;
                newFile << "\t" << "Email:\t\t" << cur -> email << endl;
                newFile << "\t" << "Contact:\t" << cur -> contact << endl;
                newFile << "\t" << "Address:\t" << cur -> address << endl;
                newFile << "\t" << "Blood Group:\t" << cur -> bloodGroup << endl;
                newFile << "\t" << "Department:\t" << cur -> department << endl;
                newFile << "\t" << "Semester:\t" << cur -> semester << endl;
                if (cur -> isPaymentDone == true) {
                    newFile << "\t" << "Paid?\t\t" << "YES" << endl;
                } else newFile << "\t" << "Paid?\t\t" << "NO" << endl;
                if (cur -> isScholarshipCandidate == true) {
                    newFile << "\t" << "Scholarship?\t" << "YES"<< endl;
                } else  newFile << "\t" << "Scholarship?\t" << "NO" << endl;
                if (cur -> isGraduated == true) {
                    newFile << "\t" << "Graduated?:\t" << "YES" << endl;
                } else newFile << "\t" << "Graduated?:\t" << "NO" << endl;

                newFile << endl << endl;
            }
            cur = cur -> next;
        }
    }
}

void reportOfCGPA(double cgpa, string dir) {
    fstream newFile;
    newFile.open("ReportBasedOnCGPA.txt", ios::out);
    if (newFile.is_open()) {
        if (dir == "=") {
            newFile << "\t\tReport of Students having CGPA Equals to " << cgpa << endl << endl;
            student *cur = head;
            if(cur == NULL) {
                newFile << "\n\n\t\tNo Avalable Information Found!" << endl;
            }
            while (cur != NULL) {
                if (cur -> cgpa == cgpa) {
                    newFile << "\t\tReport on ID " << cur -> id << endl;
                    newFile << "\n\t" << "Name:\t\t" << cur -> name << endl;
                    newFile << "\t" << "Credits:\t" << cur -> completedCredits << endl;
                    newFile << "\t" << "CGPA:\t\t" << cur -> cgpa << endl;
                    newFile << "\t" << "DoB:\t\t" << cur -> dob << endl;
                    newFile << "\t" << "Email:\t\t" << cur -> email << endl;
                    newFile << "\t" << "Contact:\t" << cur -> contact << endl;
                    newFile << "\t" << "Address:\t" << cur -> address << endl;
                    newFile << "\t" << "Blood Group:\t" << cur -> bloodGroup << endl;
                    newFile << "\t" << "Department:\t" << cur -> department << endl;
                    newFile << "\t" << "Semester:\t" << cur -> semester << endl;
                    if (cur -> isPaymentDone == true) {
                        newFile << "\t" << "Paid?\t\t" << "YES" << endl;
                    } else newFile << "\t" << "Paid?\t\t" << "NO" << endl;
                    if (cur -> isScholarshipCandidate == true) {
                        newFile << "\t" << "Scholarship?\t" << "YES"<< endl;
                    } else  newFile << "\t" << "Scholarship?\t" << "NO" << endl;
                    if (cur -> isGraduated == true) {
                        newFile << "\t" << "Graduated?:\t" << "YES" << endl;
                    } else newFile << "\t" << "Graduated?:\t" << "NO" << endl;

                    newFile << endl << endl;
                }
                cur = cur -> next;
            }
        } else if (dir == "<") {
            newFile << "\t\tReport of Students having CGPA Less than " << cgpa << endl << endl;
            student *cur = head;
            if(cur == NULL) {
                newFile << "\n\n\t\tNo Avalable Information Found!" << endl;
            }
            while (cur != NULL) {
                if (cur -> cgpa < cgpa) {
                    newFile << "\t\tReport on ID " << cur -> id << endl;
                    newFile << "\n\t" << "Name:\t\t" << cur -> name << endl;
                    newFile << "\t" << "Credits:\t" << cur -> completedCredits << endl;
                    newFile << "\t" << "CGPA:\t\t" << cur -> cgpa << endl;
                    newFile << "\t" << "DoB:\t\t" << cur -> dob << endl;
                    newFile << "\t" << "Email:\t\t" << cur -> email << endl;
                    newFile << "\t" << "Contact:\t" << cur -> contact << endl;
                    newFile << "\t" << "Address:\t" << cur -> address << endl;
                    newFile << "\t" << "Blood Group:\t" << cur -> bloodGroup << endl;
                    newFile << "\t" << "Department:\t" << cur -> department << endl;
                    newFile << "\t" << "Semester:\t" << cur -> semester << endl;
                    if (cur -> isPaymentDone == true) {
                        newFile << "\t" << "Paid?\t\t" << "YES" << endl;
                    } else newFile << "\t" << "Paid?\t\t" << "NO" << endl;
                    if (cur -> isScholarshipCandidate == true) {
                        newFile << "\t" << "Scholarship?\t" << "YES"<< endl;
                    } else  newFile << "\t" << "Scholarship?\t" << "NO" << endl;
                    if (cur -> isGraduated == true) {
                        newFile << "\t" << "Graduated?:\t" << "YES" << endl;
                    } else newFile << "\t" << "Graduated?:\t" << "NO" << endl;

                    newFile << endl << endl;
                }
                cur = cur -> next;
            }
        } else if (dir == ">") {
            newFile << "\t\tReport of Students having CGPA Greater than " << cgpa << endl << endl;
            student *cur = head;
            if(cur == NULL) {
                newFile << "\n\n\t\tNo Avalable Information Found!" << endl;
            }
            while (cur != NULL) {
                if (cur -> cgpa > cgpa) {
                    newFile << "\t\tReport on ID " << cur -> id << endl;
                    newFile << "\n\t" << "Name:\t\t" << cur -> name << endl;
                    newFile << "\t" << "Credits:\t" << cur -> completedCredits << endl;
                    newFile << "\t" << "CGPA:\t\t" << cur -> cgpa << endl;
                    newFile << "\t" << "DoB:\t\t" << cur -> dob << endl;
                    newFile << "\t" << "Email:\t\t" << cur -> email << endl;
                    newFile << "\t" << "Contact:\t" << cur -> contact << endl;
                    newFile << "\t" << "Address:\t" << cur -> address << endl;
                    newFile << "\t" << "Blood Group:\t" << cur -> bloodGroup << endl;
                    newFile << "\t" << "Department:\t" << cur -> department << endl;
                    newFile << "\t" << "Semester:\t" << cur -> semester << endl;
                    if (cur -> isPaymentDone == true) {
                        newFile << "\t" << "Paid?\t\t" << "YES" << endl;
                    } else newFile << "\t" << "Paid?\t\t" << "NO" << endl;
                    if (cur -> isScholarshipCandidate == true) {
                        newFile << "\t" << "Scholarship?\t" << "YES"<< endl;
                    } else  newFile << "\t" << "Scholarship?\t" << "NO" << endl;
                    if (cur -> isGraduated == true) {
                        newFile << "\t" << "Graduated?:\t" << "YES" << endl;
                    } else newFile << "\t" << "Graduated?:\t" << "NO" << endl;

                    newFile << endl << endl;
                }
                cur = cur -> next;
            }
        } else if (dir == "<=") {
            newFile << "\t\tReport of Students having CGPA Equal or Less then " << cgpa << endl << endl;
            student *cur = head;
            if(cur == NULL) {
                newFile << "\n\n\t\tNo Avalable Information Found!" << endl;
            }
            while (cur != NULL) {
                if (cur -> cgpa <= cgpa) {
                    newFile << "\t\tReport on ID " << cur -> id << endl;
                    newFile << "\n\t" << "Name:\t\t" << cur -> name << endl;
                    newFile << "\t" << "Credits:\t" << cur -> completedCredits << endl;
                    newFile << "\t" << "CGPA:\t\t" << cur -> cgpa << endl;
                    newFile << "\t" << "DoB:\t\t" << cur -> dob << endl;
                    newFile << "\t" << "Email:\t\t" << cur -> email << endl;
                    newFile << "\t" << "Contact:\t" << cur -> contact << endl;
                    newFile << "\t" << "Address:\t" << cur -> address << endl;
                    newFile << "\t" << "Blood Group:\t" << cur -> bloodGroup << endl;
                    newFile << "\t" << "Department:\t" << cur -> department << endl;
                    newFile << "\t" << "Semester:\t" << cur -> semester << endl;
                    if (cur -> isPaymentDone == true) {
                        newFile << "\t" << "Paid?\t\t" << "YES" << endl;
                    } else newFile << "\t" << "Paid?\t\t" << "NO" << endl;
                    if (cur -> isScholarshipCandidate == true) {
                        newFile << "\t" << "Scholarship?\t" << "YES"<< endl;
                    } else  newFile << "\t" << "Scholarship?\t" << "NO" << endl;
                    if (cur -> isGraduated == true) {
                        newFile << "\t" << "Graduated?:\t" << "YES" << endl;
                    } else newFile << "\t" << "Graduated?:\t" << "NO" << endl;

                    newFile << endl << endl;
                }
                cur = cur -> next;
            }
        } else if (dir == ">=") {
            newFile << "\t\tReport of Students having CGPA Equal or Greater then " << cgpa << endl << endl;
            student *cur = head;
            if(cur == NULL) {
                newFile << "\n\n\t\tNo Avalable Information Found!" << endl;
            }
            while (cur != NULL) {
                if (cur -> cgpa >= cgpa) {
                    newFile << "\t\tReport on ID " << cur -> id << endl;
                    newFile << "\n\t" << "Name:\t\t" << cur -> name << endl;
                    newFile << "\t" << "Credits:\t" << cur -> completedCredits << endl;
                    newFile << "\t" << "CGPA:\t\t" << cur -> cgpa << endl;
                    newFile << "\t" << "DoB:\t\t" << cur -> dob << endl;
                    newFile << "\t" << "Email:\t\t" << cur -> email << endl;
                    newFile << "\t" << "Contact:\t" << cur -> contact << endl;
                    newFile << "\t" << "Address:\t" << cur -> address << endl;
                    newFile << "\t" << "Blood Group:\t" << cur -> bloodGroup << endl;
                    newFile << "\t" << "Department:\t" << cur -> department << endl;
                    newFile << "\t" << "Semester:\t" << cur -> semester << endl;
                    if (cur -> isPaymentDone == true) {
                        newFile << "\t" << "Paid?\t\t" << "YES" << endl;
                    } else newFile << "\t" << "Paid?\t\t" << "NO" << endl;
                    if (cur -> isScholarshipCandidate == true) {
                        newFile << "\t" << "Scholarship?\t" << "YES"<< endl;
                    } else  newFile << "\t" << "Scholarship?\t" << "NO" << endl;
                    if (cur -> isGraduated == true) {
                        newFile << "\t" << "Graduated?:\t" << "YES" << endl;
                    } else newFile << "\t" << "Graduated?:\t" << "NO" << endl;

                    newFile << endl << endl;
                }
                cur = cur -> next;
            }
        } else {
            newFile << "Invalid Direction to Predict!" << endl;
        }
    }
}

