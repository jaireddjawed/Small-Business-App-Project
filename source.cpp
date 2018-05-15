/*
 * Jaired J.
 * Johnny B.
 * Rhudy M.
 * Group: Conjoined Triangle of Success
 * Program Purpose: To record all orders for a bakery and display a receipt for the customer
 */

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

using namespace std;

string cakeTypes[] = {"Chocolate", "Carrot", "Yellow", "Oreo", "Strawberry"};
string frostingTypes[] = {"Chocolate", "Vanilla", "Cream Cheese"};
string fillingTypes[] = {"Fudge", "Pudding", "Custard", "Mousse"};

// vectors for the user's orders, will be used to print receipt laterss
vector<string> userCakeTypes;
vector<string> userFrostingTypes;
vector<string> userFillingTypes;
vector<double> cart;

// a parallel, 3d array that lists all possible prices
const double prices[5][3][4] = {
    {
        {10.12, 12.34, 13.34, 14.80},
        {13.10, 13.12, 10.20, 14.99},
        {10.20, 10.22, 15.23, 39.99},
    },
    {
        {12.22, 12.39, 13.45, 15.32},
        {11.11, 14.23, 11.21, 24.99},
        {11.20, 22.22, 23.33, 89.99},
    },
    {
        {10.12, 12.34, 13.34, 14.80},
        {13.10, 13.12, 10.20, 14.99},
        {10.20, 10.22, 15.23, 59.99},
    },
    {
        {10.12, 12.34, 13.34, 14.80},
        {13.10, 13.12, 10.20, 14.99},
        {10.20, 10.22, 15.23, 69.99},
    },
    {
        {10.14, 12.34, 17.38, 49.80},
        {13.34, 15.12, 10.02, 13.07},
        {10.20, 12.34, 14.20, 29.99},
    },
};

double determineBaseCakePrice(string, string, string);
int getItemIndexFromArray(string, string[], int);
void displayAndPrintReceipt(string * , string * , string * , string * , double *);

int main() {
    bool repeatOrderProcess = true;
    unique_ptr<string> customerName(new string);

    cout << "Welcome to the Conjoined Triangles of Success Bakery!" << endl;
    cout << "Please enter your full name: ";
    cin >> *customerName;

    while (repeatOrderProcess) {
        string cakeType;
        int cakeTypeLength = sizeof(cakeTypes)/sizeof(cakeTypes[0]);
        cout << "Please choose a cake type. Here are our available ones." << endl;

        for (int i = 0; i < cakeTypeLength; i++) {
            cout << i + 1 << ") " << cakeTypes[i] << endl;
        }

        cout << "Please enter a cake type: ";
        cin >> cakeType;

        string frostingType;
        int frostingTypeLength = sizeof(frostingTypes)/sizeof(frostingTypes[0]);
        cout << "Please choose a frosting type. Here are our available ones." << endl;

        for (int i = 0; i < frostingTypeLength; i++) {
            cout << i + 1 << ") " << frostingTypes[i] << endl;
        }

        cout << "Please enter a frosting type: ";
        cin >> frostingType;

        string fillingType;
        int fillingTypeLength = sizeof(fillingTypes)/sizeof(fillingTypes[0]);
        cout << "Please choose a filling type. Here are our available ones." << endl;

        for (int i = 0; i < fillingTypeLength; i++) {
            cout << i + 1 << ") " << fillingTypes[i] << endl;
        }

        cout << "Please enter a filling type: ";
        cin >> fillingType;

        double price = determineBaseCakePrice(cakeType, frostingType, fillingType);
        cout << price << endl;

        // add the new item to the user's cart
        userCakeTypes.push_back(cakeType);
        userFrostingTypes.push_back(frostingType);
        userFillingTypes.push_back(fillingType);
        cart.push_back(price);

        string repeatOrder;
        cout << "Would you like to make another order? (Yes (Y) / No (N) ): " << endl;
        cin >> repeatOrder;
        
        // if the user doesn't want to order again, print the receipt and end the program, otherwise repeat
        if (repeatOrder == "no") {
            repeatOrderProcess = false;
            // display and print reciept
            cout << "Thanks " << *customerName << ", your order will be completed shortly." << endl;
        }
    }

    return 0;
}

// generates a price for the cake based off of the cake type, frosting type, and filling type
double determineBaseCakePrice(string cakeType, string frostingType, string fillingType) {
    int cakeTypeLength = sizeof(cakeTypes)/sizeof(cakeTypes[0]);
    int frostingTypeLength = sizeof(frostingTypes)/sizeof(frostingTypes[0]);
    int fillingTypeLength = sizeof(fillingTypes)/sizeof(fillingTypes[0]);

    int cakeTypeIndex = getItemIndexFromArray(cakeType, cakeTypes, cakeTypeLength);
    int frostingTypeIndex = getItemIndexFromArray(frostingType, frostingTypes, frostingTypeLength);
    int fillingTypeIndex = getItemIndexFromArray(fillingType, fillingTypes, fillingTypeLength);

    // loop through the prices array, if all indexes match then return a price
    for (int cake = 0; cake < cakeTypeLength; cake++) {
        for (int frosting = 0; frosting < frostingTypeLength; frosting++) {
            for (int filling = 0; filling < fillingTypeLength; filling++) {
                if (cake == cakeTypeIndex && frosting == frostingTypeIndex && filling == fillingTypeIndex) {
                    return prices[cake][frosting][filling];
                }
            }
        }
    }

    return 0.00;
}

// returns the index of a value of it exists, otherwise returns -1
int getItemIndexFromArray(string itemName, string items[], int itemLength) {
    for (int i = 0; i < itemLength; i++) {
        if (itemName == items[i]) {
            return i;
        }
    }

    return -1;
}

// saves a receipt to a text file based on customer information
void displayAndPrintReceipt(string *customerName, string *cakeType, string *frostingType, string *fillingType, double * price) {

    ofstream writeReceiptFile;
    writeReceiptFile.open("receipt.txt", fstream::app);

    // loop through vector, print receipt, and save it to the file
    for ( int i = 0; i < cart.size(); i++) {
        writeReceiptFile << "Order #" << rand() << endl;
        writeReceiptFile << "________________________________" << endl;
        writeReceiptFile << "Customer Name: " << *customerName << endl;
        writeReceiptFile << "Cake Type: " << userCakeTypes.at(i) << endl;
        writeReceiptFile << "Cake Frosting: " << userFrostingTypes.at(i) << endl;
        writeReceiptFile << "Cake Filling: " << userFillingTypes.at(i) << endl;
        writeReceiptFile << "Total: " << cart.at(i) << endl;
    }

    writeReceiptFile.close();
}
