// FileManagement.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <fstream> // working with files requires fstream to be included
#include <sstream> // to include string stream to read a row, from the file
using namespace std;

//structure definition
struct SuperMarket {
    string itemNo;
    string itemName;
    float itemPrice;

    //constructor
    SuperMarket(string ino = "", string iname = "", float iprice = 0) {
        itemNo = ino;
        itemName = iname;
        itemPrice = iprice;
    }

};

//function prototypes

int main()
{
    SuperMarket sm[2], supermarket;
      
   /* SuperMarket myData("wb101", "White Bread", 2.75);
    cout << myData.itemName;*/
    //Modes of opening the file - out, in, app
    //Write into the file using out mode for the first time. It will overwrite any content
    //Retrieve from the file usng in mode
    

    //ofstream outFile; //ofstream is the keyword that is used to declare a file handling variable
    //fstream appFile; //append mode
    //outFile.open("D:/Users/092834/OneDrive - UP Education/Desktop/CS103/July2021/FileManagement/supermarket.csv",ios::out);
    //outFile.open("D:/Users/092834/OneDrive - UP Education/Desktop/CS103/July2021/FileManagement/supermarkets.txt",ios::out);
     fstream appFile("supermarket.csv", ios::app);
    int i;
    for (i = 0; i < 2; i++) {
        cin.ignore();
        cout << "\nEnter the item number: ";
        getline(cin, sm[i].itemNo);

        cout << "\nEnter the item name: ";
        getline(cin, sm[i].itemName);

        cout << "\nEnter the item price: ";
        cin>> sm[i].itemPrice;

        //Writing with outFile or appending with appfile
        //outFile << sm[i].itemNo << "," << sm[i].itemName << "," << sm[i].itemPrice << endl;
        appFile << sm[i].itemNo << "," << sm[i].itemName << "," << sm[i].itemPrice <<endl;
    }

    appFile.close();


    //************************
    //Reading or retrieving from the file
    //************************

    //open file
   // ifstream inFile; //specifically to handle input mode
    //fstream handles all modes - in, out, app
   // inFile.open(, );

    ifstream inFile("supermarket.csv",ios::in);

    // struct Employee transaction;
    string line; //to store the line that is read from the line
    int linenum = 0; //used as loop index
    SuperMarket smarket[2];
    i=0;
    while (getline(inFile, line)) { //reads a line from csv file
        cout << line;
        istringstream linestream(line); //stringstream separates the line values
        string item;
        getline(linestream, item, ',');//read separated linestream values and store in item and add comma

        supermarket.itemNo = item; //store the separated value in structure member empname
        //cout << "\nitemNo: " << supermarket.itemNo;
        getline(linestream, item, ',');
        supermarket.itemName = item;

        getline(linestream, item, ',');
        stringstream ss(item); //convert the data type from string to int
        ss >> supermarket.itemPrice;//store the separated value in structure member empid
        
        smarket[linenum]= supermarket;//push the structure into the array 
        linenum++; //index variable incremented
    }
    int j;
    for (j = 0; j < 2; j++) {
        cout << "\nSupermarket item id: " << smarket[j].itemNo;
        cout << "\nSupermarket item name: " << smarket[j].itemName;
        cout << "\nSupermarket item price: " << smarket[j].itemPrice;
    }

    //close file
    inFile.close();
    

}//main

//functions