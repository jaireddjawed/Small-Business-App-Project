
/*
 * Jaired J.
 * Johnny B.
 * Rhudy M.
 * Lauren H.
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
void sortAllItemsByPrice();
void displayAndPrintReceipt(string);

int main() {
    bool repeatOrderProcess = true;
    string customerName;
    
    cout << "Welcome to the Conjoined Triangles of Success Bakery!" << endl;
    cout << "Please enter your full name: ";
    cin >> customerName;
    
    while (repeatOrderProcess) {
        string cakeType;
        int cakeTypeLength = sizeof(cakeTypes)/sizeof(cakeTypes[0]);
        cout << "Please choose a cake type. Here are our available ones." << endl;
        
        for (int i = 0; i < cakeTypeLength; i++) {
            cout << i + 1 << ") " << cakeTypes[i] << endl;
        }
        
        cout << "Please enter a cake type: ";
        cout << "Please enter a cake type: ";
        char cakeChoice;
        cin >> cakeChoice;
        
        bool flag = true;
        while (flag)
        {
            switch(cakeChoice)
            {
                case '1':
                {
                    cakeType = "Chocolate";
                    flag = false;
                }
                    break;
                case '2':
                {
                    cakeType = "Carrot";
                    flag = false;
                }
                    break;
                case '3':
                {
                    cakeType = "Yellow";
                    flag = false;
                }
                    break;
                case '4':
                {
                    cakeType = "Oreo";
                    flag = false;
                }
                    break;
                case '5':
                {
                    cakeType = "Strawberry";
                    flag = false;
                }
                    break;
                default:
                {
                    cout << "Enter 1 through 5 to choose: ";
                    cin >> cakeChoice;
                }
                    
            }
        }
        string frostingType;
        int frostingTypeLength = sizeof(frostingTypes)/sizeof(frostingTypes[0]);
        cout << "Please choose a frosting type. Here are our available ones." << endl;
        
        for (int i = 0; i < frostingTypeLength; i++) {
            cout << i + 1 << ") " << frostingTypes[i] << endl;
        }
        
        cout << "Please enter a frosting type: ";
        char frostingChoice;
        
        cin >> frostingChoice;
        
        flag = true;
        while (flag)
        {
            
            switch(frostingChoice)
            {
                case '1':
                {
                    frostingType = "Chocolate";
                    flag = false;
                }
                    break;
                case '2':
                {
                    frostingType = "Vanilla";
                    flag = false;
                }
                    break;
                case '3':
                {
                    frostingType = "Cream Cheese";
                    flag = false;
                }
                    break;
                default:
                {
                    cout << "Enter 1 through 3 to choose: ";
                    cin >> frostingChoice;
                }
                    
            }
        }
        
        string fillingType;
        int fillingTypeLength = sizeof(fillingTypes)/sizeof(fillingTypes[0]);
        cout << "Please choose a filling type. Here are our available ones." << endl;
        
        for (int i = 0; i < fillingTypeLength; i++) {
            cout << i + 1 << ") " << fillingTypes[i] << endl;
        }
        
        char fillingChoice;
        cin >> fillingChoice;
        flag = true;
        while (flag)
        {
            
            switch(fillingChoice)
            {
                case '1':
                {
                    fillingType = "Fudge";
                    flag = false;
                }
                    break;
                case '2':
                {
                    fillingType = "Pudding";
                    flag = false;
                }
                    break;
                case '3':
                {
                    fillingType = "Custard";
                    flag = false;
                }
                    break;
                case '4':
                {
                    fillingType = "Mousse";
                    flag = false;
                }
                    break;
                default:
                {
                    cout << "Enter 1 through 4 to choose: ";
                    cin >> fillingChoice;
                }
                    
            }
        }
        
        double price = determineBaseCakePrice(cakeType, frostingType, fillingType);
        cout << price << endl;
        
        // add the new item to the user's cart
        userCakeTypes.push_back(cakeType);
        userFrostingTypes.push_back(frostingType);
        userFillingTypes.push_back(fillingType);
        cart.push_back(price);
        
        char repeatOrder;
        cout << "Would you like to make another order? (Yes (y) / No (n)): " << endl;
        cin >> repeatOrder;
        
        flag = true;
        while(flag)
        {
            switch (repeatOrder)
            {
                case 'y':
                {
                    repeatOrderProcess = true;
                    flag = false;
                }
                    break;
                case 'n':
                {
                    // if the user doesn't want to order again, print the receipt and end the program, otherwise repeat
                    repeatOrderProcess = false;
                    flag = false;
                    cout << "Thanks " << customerName << ", your order will be completed shortly." << endl;
                    displayAndPrintReceipt(customerName);
                }
                    break;
                    
                default:
                {
                    cout << "Enter y or n to choose: ";
                    cin >> repeatOrder;
                }
            }
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

void sortAllItemsByPrice() {
    int min_idx;

    for (int i = 0; i < cart.size() - 1; i++) {
        min_idx = i;
        for (int j = i + 1; i < cart.size(); j++) {
            if (cart.at(j) < cart.at(min_idx)) {
                min_idx = j;
            }
        }
        
        double temp = cart.at(min_idx);
        cart.at(min_idx) = cart.at(i);
        cart.at(i) = temp;
    }
}

// saves a receipt to a text file based on customer information
void displayAndPrintReceipt(string customerName) {
    auto_ptr<double>total(new double);
    
    ofstream writeReceiptFile;
    writeReceiptFile.open("receipt.txt", fstream::app);
    writeReceiptFile << "Order #" << rand() << endl;
    writeReceiptFile << "________________________________" << endl;
    writeReceiptFile << "Customer Name: " << customerName << endl;
    
    // loop through vector, print receipt, and save it to the file
    for ( int i = 0; i < cart.size(); i++) {
        writeReceiptFile << "Cake Type: " << userCakeTypes.at(i) << endl;
        writeReceiptFile << "Cake Frosting: " << userFrostingTypes.at(i) << endl;
        writeReceiptFile << "Cake Filling: " << userFillingTypes.at(i) << endl;
        writeReceiptFile << "Price: " << cart.at(i) << endl;
        *total+=cart.at(i);
    }

    writeReceiptFile << "Total: " << *total << endl;
    writeReceiptFile.close();
    total.reset();
}
