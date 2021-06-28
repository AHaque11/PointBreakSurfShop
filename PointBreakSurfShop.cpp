// PointBreakSurfShop.cpp : 

/* ************************************************************************************************************************************************************************************************************************************************

    Johnny Utah owns a surf shop on the beach called “Point Break Surf Shop”. Johnny sells surfboards in 3 three sizes: small (2 meters), medium (3 meters),
    and large (4 meters). The cost of one small surfboard is $175.00, one medium is $190.00, and one large is $200.00.  Write a program that will make the
    surf shop operational.  Your program should allow the user to do the following:

        * Buy any surfboard in any size and in any quanity.
        * At any time show the total number of surfboards of each size sold.
        * At any time show the total money made.

             Your program must consist of "int main()" and at least the following functions:

                void ShowUsage();
                * a function to show the user how to use the program.
                void MakePurchase(int& iTotalSmall, int& iTotalMedium, int& iTotalLarge);
                * a function to sell surfboards.
                void DisplayPurchase(const int iTotalSmall, const int iTotalMedium, const int iTotalLarge);
                * function to show the number of surfboards of each size sold.
                void DisplayTotal(const int iTotalSmall, const int iTotalMedium, const int iTotalLarge);
                * a function to show the total amount of money made.

        In your program you must define the functions as they are defined above. Do not change the signature (the name, parameters or the return value) or you will be marked down.

        Your program should not use any global variables and the cost of the surfboards must be declared as named constants.

        Your program should look and perform identically as the example below.

        Add one more surfboard size of XXXS.


************************************************************************************************************************************************************************************************************************************************* */

#include <iostream>
#include <iomanip>
#include <string>

using namespace std;



// Declare the surfboard prices as const values
const double smallPrice = 175.00;
const double mediumPrice = 190.00;
const double largePrice = 200.00;
const double xxxsmallPrice = 120.00;


// Declare the functions
void ShowUsage();
void MakePurchase(int& iTotalSmall, int& iTotalMedium, int& iTotalLarge, int& iTotalXXXSmall);
void DisplayPurchase(const int iTotalSmall, const int iTotalMedium, const int iTotalLarge, const int iTotalXXXSmall);
void DisplayTotal(const int iTotalSmall, const int iTotalMedium, const int iTotalLarge, const int iTotalXXXSmall);


int main()
{
    // Display heading in the console
    cout << "************************************************************" << endl;
    cout << "***** Welcome to my Johnny Utah's PointBreak Surf Shop *****" << endl;
    cout << "************************************************************" << endl;

    ShowUsage(); // Show the program options


    char selection = ' ';   // Variable to store the user's selected program option

    int numSmall = 0;       // Variable to store the quantity of small surfboards
    int numMedium = 0;      // Variable to store the quantity of medium surfboards
    int numLarge = 0;       // Variable to store the quantity of large surfboards
    int numXXXSmall = 0;    // Variable to store the quantity of xxxsmall surfboards


    while (selection)       // While a character is entered
    {
        cout << "\n" << "\nPlease enter selection: ";       // Prompt the user for a selection
        cin >> selection;                           // Store the user's choice in the variable

        if (tolower(selection) == 's')                  // If the user enters 's', call the ShowUsage function
        {
            ShowUsage();
        }
        else if (tolower(selection) == 'p')             // If the user enters 'p', call the MakePurchase function
        {
            MakePurchase(numSmall, numMedium, numLarge, numXXXSmall);
        }
        else if (tolower(selection) == 'c')             // If the user enters 'c', 
        {
            if (numSmall == 0 && numMedium == 0 && numLarge == 0 && numXXXSmall == 0)   // and if no quantity of surfboards has been entered, show this message
            {
                cout << "No purchases made yet." << endl;
            }
            else                                                    // If a quantity was entered, call the DisplayPurchase function
            {
                DisplayPurchase(numSmall, numMedium, numLarge, numXXXSmall);
            }
        }
        else if (tolower(selection) == 't')         // If the user enters 't', 
        {
            if (numSmall == 0 && numMedium == 0 && numLarge == 0 && numXXXSmall == 0)   // and if no quantity of surfboards has been entered, show this message
            {
                cout << "No purchases made yet." << endl;
            }
            else                                                    // If a quantity was entered, call the DisplayTotal function
            {
                DisplayTotal(numSmall, numMedium, numLarge, numXXXSmall);
            }
        }
        else if (tolower(selection) == 'q')         // If the user enters 'q', show this message and exit the program
        {
            cout << "\nThank You" << endl;
            return 1;
        }
        else                                        // If the user does not enter 's', 'c', 't', or 'q', show this message
        {
            cout << "Not a valid entry." << endl;
        }
    }



    system("pause");
    return 0;
}



void ShowUsage()
{
    // Display the program options in the console
    cout << "\nTo show program usage press \'S\'";
    cout << "\nTo purchase a surfboard press \'P\'";
    cout << "\nTo display current purchases press \'C\'";
    cout << "\nTo display total amount due press \'T\'";
    cout << "\nTo quit the program press \'Q\'" << endl;

}


void MakePurchase(int& iTotalSmall, int& iTotalMedium, int& iTotalLarge, int& iTotalXXXSmall)
{

    int quantity = 0;   // Variable to store the quatity of surfboard
    char size = ' ';    // Variable to store the surfboard size

    // Propmt the user and store the input in the variables
    cout << "Please enter the quantity and size (X = XXX small, S = small, M = medium, L = large) of surfboard you would like to purchase: ";
    cin >> quantity >> size;

    // For each particular size of surfboard the user enters, add the user's entered quantity to the 
    // total number of that surfboard size (declared in the main function)
    if (tolower(size) == 's')
    {
        iTotalSmall += quantity;
    }
    else if (tolower(size) == 'm')
    {
        iTotalMedium += quantity;
    }
    else if (tolower(size) == 'l')
    {
        iTotalLarge += quantity;
    }
    else if (tolower(size) == 'x')
    {
        iTotalXXXSmall += quantity;
    }


}


void DisplayPurchase(const int iTotalSmall, const int iTotalMedium, const int iTotalLarge, const int iTotalXXXSmall)
{
    cout << "\nCurrent order: " << "\n";

    // If at least one surfboard of a particular size was purchased, display
    // the total quantity of that surfboard size
    if (iTotalSmall > 0)
    {
        cout << "   " << iTotalSmall << " small boards" << endl;
    }

    if (iTotalMedium > 0)
    {
        cout << "   " << iTotalMedium << " medium boards" << endl;
    }

    if (iTotalLarge > 0)
    {
        cout << "   " << iTotalLarge << " large boards" << endl;
    }

    if (iTotalXXXSmall > 0)
    {
        cout << "   " << iTotalXXXSmall << " XXX small boards" << endl;
    }
}


void DisplayTotal(const int iTotalSmall, const int iTotalMedium, const int iTotalLarge, const int iTotalXXXSmall)
{
    double costSmall = 0;       // Variable to store the cost of all small surfboards
    double costMedium = 0;      // Variable to store the cost of all medium surfboards
    double costLarge = 0;       // Variable to store the cost of all large surfboards
    double costXXXSmall = 0;    // Variable to store the cost of all xxxsmall surfboards
    double totalDue = 0;        // Variable to store the total cost of the order


    cout << "\nOrder total: " << "\n";

    // If at least one surfboard of a particular size was purchased, calculate
    // the cost of the total number of that size. Add the total for each size to 
    // the overall total of the order.
    if (iTotalSmall > 0)
    {
        costSmall = iTotalSmall * smallPrice;

        cout << fixed << setprecision(2);
        cout << "   " << iTotalSmall << " small surfboard(s) -- $" << costSmall << endl;

        totalDue += costSmall;
    }

    if (iTotalMedium > 0)
    {
        costMedium = iTotalMedium * mediumPrice;

        cout << fixed << setprecision(2);
        cout << "   " << iTotalMedium << " medium surfboard(s) -- $" << costMedium << endl;

        totalDue += costMedium;
    }

    if (iTotalLarge > 0)
    {
        costLarge = iTotalLarge * largePrice;

        cout << fixed << setprecision(2);
        cout << "   " << iTotalLarge << " large surfboard(s) -- $" << costLarge << endl;

        totalDue += costLarge;
    }

    if (iTotalXXXSmall > 0)
    {
        costXXXSmall = iTotalXXXSmall * xxxsmallPrice;

        cout << fixed << setprecision(2);
        cout << "   " << iTotalXXXSmall << " XXX small surfboard(s) -- $" << costXXXSmall << endl;

        totalDue += costLarge;
    }


    // Display the total amount due after listing the totals for each surfboard size.
    cout << "\n Total amount due: $" << totalDue << endl;

}
