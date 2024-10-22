/***********************************************************************
 * Program2-Final.cpp
 * Final Version for Semester 2 - Assignment 2 - Program 2
 * Version: 1.0
 **********************************************************************/

/* Pre-Processor Directive */
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;
/*
Main- all the code is contained in main in this program
*/
int main() {
        /*This is the main title of the program that runs at
        the start so the user knows which program they are using*/
        cout << "Program 2 - Record Holiday Bookings";
        /*Opens the file where the name of the file matches
        whats inside the quotes*/
        ifstream inFile("HolidayOffers.txt");
        if (!inFile) {
            cerr << "Error: could not open file" << endl;
        return 1;
        }
        /*
        Read the lines of the file into a vector
        */
        vector<string> lines;
        string line;
        while (getline(inFile, line)) {
                lines.push_back(line);
        }
        /*Get the user to enter a country and a category from the list*/
        string Country;
        string Category;
        cout << "Enter Country: ";
        getline(cin, Country);
        cout << "Enter a Category From the List Below:\n"
        "<1> - Walking\n"
        "<2> - City Break\n"
        "<3> - Skiing\n";
        getline(cin, Category);
        /*Gets and displays the holidays with the
        chosen country and category*/
        bool found = false;
        for (int i = 0; i < lines.size(); i += 7) {
                if (lines[i+1] == Country && lines[i+2] == Category) {
                found = true;
                cout << "Holiday ID: " << lines[i] << endl;
                cout << "Country: " << lines[i+1] << endl;
                cout << "Category: " << lines[i+2] << endl;
                cout << "Description: " << lines[i+3] << endl;
                cout << "Start date: " << lines[i+4] << endl;
                cout << "Duration: " << lines[i+5] << endl;
                cout << "Price: " << lines[i+6] << endl;
                /*Gets the user details that are then used
                for the booking request file*/
                string CustomerName, Email, HolidayID;
                int NumAdults;
                cout << "Enter Name: ";
                getline(cin, CustomerName);
                cout << "Enter Email Address: ";
                getline(cin, Email);
                cout << "Enter the holiday ID: ";
                getline(cin, HolidayID);
                cout << "Enter Number of Adults: ";
                cin >> NumAdults;
                /*Saves the booing details into a file and if the file
                 is not found then an error is displayed*/
                ofstream outFile("HolidayBookingRequests.txt",ios::app);
                if (!outFile) {
                        cerr << "Error: Could Not Open File" << endl;
                        return 1;
                }
                outFile << CustomerName << endl;
                outFile << Email << endl;
                outFile << HolidayID << endl;
                outFile << NumAdults << endl;
                outFile.close();
                }
        }
        /*Below displays an error message if a search for a particular
        catagory and country are not met.
        It dosent display any other useful information.*/
        if (!found) {
                cout << "Error:\n Unsuccessful Search."
                "Please Try another "
                "country and/or category. " << endl;
        }
        /*Closing the file after everything is complete*/
        inFile.close();
        return 0;
}
/*Where the main bulk of the code will go and the
main will be used for initalising*/
void HolidayOffers(){

}
