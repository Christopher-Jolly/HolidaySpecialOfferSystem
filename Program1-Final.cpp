/***********************************************************************
 * Program1-Final.cpp
 * Final Version for Semester 2 - Assignment 2 - Program 1
 * Version: 1.0
 **********************************************************************/

/* Pre-Processor Directive */
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;
/*Constants*/
const string FILENAME = "HolidayOffers.txt";
const int MinimumRecords = 20;
/* Struct */
struct HolidayRecord {
    string HolidayID;
    string Country;
    string Category;
    string Description;
    string StartDate;
    int Duration;
    float Price;
};
/*
This is a function to read the records from a file and
store them in a vector.
*/
void ReadRecords(vector<HolidayRecord>& records) {
    ifstream infile(FILENAME);
    if (infile.is_open()) {
        string line;
        while (getline(infile, line)) {
            HolidayRecord record;
            record.HolidayID = line;
            getline(infile, record.Country);
            getline(infile, record.Category);
            getline(infile, record.Description);
            getline(infile, record.StartDate);
            infile >> record.Duration;
            infile >> record.Price;
            infile.ignore();//Used for the new line character
            records.push_back(record);
        }
        infile.close();
    } else {
        cout << "Error opening file.\n " << FILENAME <<
        ". No records read." << endl;
    }
}

/*
This is a function to write records to a file from
being stored in a vector.
*/
void WriteRecords(const vector<HolidayRecord>& records) {

    ofstream outfile(FILENAME);
    if (outfile.is_open()) {
        for (const auto& record : records) {
            outfile << record.HolidayID << endl;
            outfile << record.Country << endl;
            outfile << record.Category << endl;
            outfile << record.Description << endl;
            outfile << record.StartDate << endl;
            outfile << record.Duration << endl;
            outfile << record.Price << endl;
        }
        outfile.close();
    } else {
        cout << "Error:" << FILENAME <<
        ".\nFile Could not be opened.\n" << endl;
    }

}
/*
This is a function to add a new record to the vector.
*/
void AddRecord(vector<HolidayRecord>& records) {
    HolidayRecord record;
    cout << "Enter HolidayID(8 Characters):";
    cin >> record.HolidayID;
    cout << "Enter Country: ";
    cin.ignore();//Used for the new line character
    getline(cin, record.Country);
    cout << "Enter a Category From the List Below:\n"
    "<1> - Walking \n<2> - City Break\n<3> - Skiing";
    getline(cin, record.Category);
    cout << "Enter Description:";
    getline(cin, record.Description);
    cout << "Enter Start Date(YYYY-MM-DD):";
    getline(cin, record.StartDate);
    cout << "Enter Duration:";
    cin >> record.Duration;
    cout << "Enter Price:";
    cin >> record.Price;
    records.push_back(record);
    cout << "Record Successfully Added" << endl;
}
/*
This is a function to delete a record from the vector.
*/
void DeleteRecord(vector<HolidayRecord>& records) {
    string holidayIDToDelete;
    cout << "<2> - Delete Main Menu:\n Select a Record to Delete:\n";
    cin >> holidayIDToDelete;
    for (auto it = records.begin(); it != records.end(); ++it) {
        if (it->HolidayID == holidayIDToDelete) {
            records.erase(it);
            cout << "Record" << holidayIDToDelete <<
            " Has Been Deleted" << endl;
            return;
        }
    }
    cout << "Error:\n" << holidayIDToDelete <<
    "not found.\nOr Not a Valid Entry" << endl;
}
/*
This is a function to update a record in a vector
*/
void UpdateRecord(vector<HolidayRecord>& records) {
        string holidayIDToUpdate;
        //Get Holiday ID
        cout << "Enter HolidayID(8 Characters):";
        cin >> holidayIDToUpdate;
        for (auto& record : records) {
                if (record.HolidayID == holidayIDToUpdate) {
                        cout << "<3> - Update Main Menu: \n"
                        "Enter Data Below:\n"
                        "Leave blank to use current input:" << endl;
                        cout << "Enter a Country:";
                        cin.ignore();//Used for the new line character
                        getline(cin, record.Country);
                        if (record.Country.empty()) {
                                record.Country = record.Country;
                        }
                        cout <<"Enter a Category From the List Below:\n"
                        "<1> - Walking\n"
                        "<2> - City Break\n"
                        "<3> - Skiing\n";
                        getline(cin, record.Category);
                        if (record.Category.empty()) {
                                record.Category = record.Category;
                        }
                        cout << "Enter Description:\n";
                        getline(cin, record.Description);
                        if (record.Description.empty()) {
                                record.Description = record.Description;
                        }
                        cout << "Enter Start Date:\n";
                        getline(cin, record.StartDate);
                        if (record.StartDate.empty()) {
                                record.StartDate = record.StartDate;
                        }
                        cout << "Enter Duration:\n";
                        string durationString;
                        getline(cin, durationString);
                        if (!durationString.empty()) {
                                record.Duration = stoi(durationString);
                        }
                        cout << "Enter Price:\n";
                        string priceString;
                        getline(cin, priceString);
                        if (!priceString.empty()) {
                                record.Price = stof(priceString);
                        }
                        cout << "Holiday record with HolidayID " << holidayIDToUpdate << " updated successfully." << endl;
                        return;
                }
        }
}
/*
This is the main part of the program where the main loop of the program
is and where the other functions get called from.
A simple switch statement is used for the choice of the menu and a
do while is used to make sure that nothing else is chosen.
This also helps with validation.
*/
int main() {
        /*This is the main title of the program that runs at
        the start so the user knows which program they are using*/
        cout << "Program 1 - Maintain Special Holidays" << endl;
    vector<HolidayRecord> records;
    /*Reads in the records from the file before
    the rest of the program starts.*/
    ReadRecords(records);
    int choice;
    do {
        /*This is the main menu for the mian part of the program*/
        cout << "Main Menu: Select a Menu Option:" << endl;
        cout << "<1> - Add" << endl;
        cout << "<2> - Delete" << endl;
        cout << "<3> - Update" << endl;
        cout << "<4> - Save" << endl;
        cout << "<5> -  Exit" << endl;
        cout << "> ";
        cin >> choice;
        switch (choice) {
            case 1:
                AddRecord(records);//Adding a new records function
                break;
            case 2:
                DeleteRecord(records);//Deleting a record function
                break;
            case 3:
                UpdateRecord(records);//Updating a record function
                break;
            case 4:
                WriteRecords(records);//Writing a record
                cout << "Records saved to file" << endl;
                break;
            case 5://Exiting the program
                cout << "Exiting Program." << endl;
                break;
            default:
                cout << "Error:\nNot a Valid Entry.\n" << endl;
                break;
        }
    } while (choice != 5);
    return 0;
}
