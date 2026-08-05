#include<iostream>
using namespace std;

string customerName;
int customerID, customerType, meterType;

void registerCustomer()
{
    cout << "Enter Customer Name: ";
    cin >> customerName;
    cout << "Enter Customer ID: ";
    cin >> customerID;
    cout << "1. Household\n2. Commercial\n";
    cout << "Enter Customer Type: ";
    cin >> customerType;
    cout << "1. First Meter\n2. Second Meter\n";
    cout << "Enter Meter Type: ";
    cin >> meterType;
}

double calculateConsumption(int units)
{
    double rates[8] = {12.21, 14.53, 31.51, 38.41, 41.62, 43.04, 44.18, 49.10};

    if(units <= 100)
        return units * rates[0];
    else if(units <= 200)
        return units * rates[1];
    else if(units <= 300)
        return units * rates[2];
    else if(units <= 400)
        return units * rates[3];
    else if(units <= 500)
        return units * rates[4];
    else if(units <= 600)
        return units * rates[5];
    else if(units <= 700)
        return units * rates[6];
    else
        return units * rates[7];
}

double calculateGST(double amount)
{
    return amount * 0.18;
}

double calculateIncomeTax(double amount)
{
    if(customerType == 1)
        return amount * 0.10;
    else
        return amount * 0.15;
}

double calculateDuty(double amount)
{
    return amount * 0.015;
}

double calculateFixedCharges(int units)
{
    if(units >= 301 && units <= 400)
        return 200;
    else if(units >= 401 && units <= 500)
        return 400;
    else if(units >= 501 && units <= 600)
        return 600;
    else if(units >= 601 && units <= 700)
        return 800;
    else if(units > 700)
        return 1000;
    else
        return 0;
}

void calculateBill()
{
    int units;
    cout << "Enter Units Consumed: ";
    cin >> units;

    double consumption = calculateConsumption(units);
    double duty = calculateDuty(consumption);
    double gst = calculateGST(consumption);
    double incomeTax = calculateIncomeTax(consumption);
    double fixedCharges = calculateFixedCharges(units);
    double meterRent = 250;
    double tvFee = 35;

    double totalBill = consumption + duty + gst +
                        incomeTax + fixedCharges +
                        meterRent + tvFee;

    cout << "\n========== LESCO BILL ==========\n";
    cout << "Customer Name: " << customerName << endl;
    cout << "Customer ID: " << customerID << endl;
    cout << "Units Consumed: " << units << endl;
    cout << "Consumption Charges: Rs. " << consumption << endl;
    cout << "Electricity Duty: Rs. " << duty << endl;
    cout << "Fixed Charges: Rs. " << fixedCharges << endl;
    cout << "Meter Rent: Rs. " << meterRent << endl;
    cout << "TV Fee: Rs. " << tvFee << endl;
    cout << "GST: Rs. " << gst << endl;
    cout << "Income Tax: Rs. " << incomeTax << endl;
    cout << "Total Bill: Rs. " << totalBill << endl;
    cout << "===============================\n";
}

void newConnection()
{
    double charges = 0;

    if(customerType == 1)
    {
        if(meterType == 1)
            charges = 2500;
        else
            charges = 5000;
    }
    else
    {
        if(meterType == 1)
            charges = 35000;
        else
            charges = 70000;
    }

    charges += 250000;

    cout << "\nNew Connection Charges: Rs. "
         << charges << endl;
}

void displayCustomer()
{
    cout << "\nCustomer Name: " << customerName << endl;
    cout << "Customer ID: " << customerID << endl;

    if(customerType == 1)
        cout << "Customer Type: Household" << endl;
    else
        cout << "Customer Type: Commercial" << endl;
}

int main()
{
    registerCustomer();

    int choice;

    do
    {
        cout << "\n===== MAIN MENU =====\n";
        cout << "1. Calculate Bill\n";
        cout << "2. New Connection\n";
        cout << "3. View Customer Details\n";
        cout << "4. Exit\n";
        cout << "Enter Choice: ";
        cin >> choice;

        switch(choice)
        {
        case 1:
            calculateBill();
            break;
        case 2:
            newConnection();
            break;
        case 3:
            displayCustomer();
            break;
        case 4:
            cout << "Program Ended\n";
            break;
        default:
            cout << "Invalid Choice\n";
        }

    } while(choice != 4);

    return 0;
}

#include<iostream>
using namespace std;

string customerName, contactNumber;
int orderType, persons;

string foodItems[8] = {
    "Chicken Burger",
    "Zinger Burger",
    "Pizza Small",
    "Pizza Large",
    "Chicken Biryani",
    "BBQ Platter",
    "Fries",
    "Cold Drink"
};

double prices[8] = {
    450, 550, 900, 1800,
    350, 1200, 250, 120
};

double foodBill = 0;

void registerCustomer()
{
    cout << "Enter Customer Name: ";
    cin >> customerName;
    cout << "Enter Contact Number: ";
    cin >> contactNumber;
    cout << "1. Dine In\n2. Take Away\n";
    cout << "Enter Order Type: ";
    cin >> orderType;
    cout << "Enter Number of Persons: ";
    cin >> persons;
}

void displayMenu()
{
    cout << "\n===== FOOD MENU =====\n";
    for(int i=0; i<8; i++)
    {
        cout << i+1 << ". "
             << foodItems[i]
             << " - Rs. "
             << prices[i] << endl;
    }
}

void placeOrder()
{
    int itemNo, quantity;
    cout << "Enter Item Number: ";
    cin >> itemNo;
    cout << "Enter Quantity: ";
    cin >> quantity;

    foodBill = foodBill + (prices[itemNo-1] * quantity);

    cout << "Item Added Successfully\n";
}

double calculateServiceCharges()
{
    if(orderType == 1)
        return foodBill * 0.10;
    else
        return foodBill * 0.05;
}

double calculateGST()
{
    return foodBill * 0.16;
}

double calculateDiscount()
{
    if(foodBill >= 3000 && foodBill <= 5000)
        return foodBill * 0.05;
    else if(foodBill > 5000 && foodBill <= 10000)
        return foodBill * 0.10;
    else if(foodBill > 10000)
        return foodBill * 0.15;

    return 0;
}

void calculateBill()
{
    double serviceCharges = calculateServiceCharges();
    double gst = calculateGST();
    double discount = calculateDiscount();

    double total =
        foodBill + serviceCharges + gst - discount;

    cout << "\n======= RESTAURANT BILL =======\n";
    cout << "Customer Name: " << customerName << endl;
    cout << "Food Bill: Rs. " << foodBill << endl;
    cout << "Service Charges: Rs. "
         << serviceCharges << endl;
    cout << "GST: Rs. " << gst << endl;
    cout << "Discount: Rs. "
         << discount << endl;

    if(total > 5000)
        cout << "Free Delivery Applied\n";

    cout << "Total Payable: Rs. "
         << total << endl;
    cout << "===============================\n";
}

void customerDetails()
{
    cout << "\nCustomer Name: "
         << customerName << endl;
    cout << "Contact Number: "
         << contactNumber << endl;
    cout << "Persons: "
         << persons << endl;
}

int main()
{
    registerCustomer();

    int choice;

    do
    {
        cout << "\n===== MAIN MENU =====\n";
        cout << "1. View Food Menu\n";
        cout << "2. Place Order\n";
        cout << "3. Calculate Bill\n";
        cout << "4. View Customer Details\n";
        cout << "5. Exit\n";
        cout << "Enter Choice: ";
        cin >> choice;

        switch(choice)
        {
        case 1:
            displayMenu();
            break;
        case 2:
            placeOrder();
            break;
        case 3:
            calculateBill();
            break;
        case 4:
            customerDetails();
            break;
        case 5:
            cout << "Program Ended\n";
            break;
        default:
            cout << "Invalid Choice\n";
        }

    } while(choice != 5);

    return 0;
}

#include<iostream>
using namespace std;

string customerName;
int customerID, customerType, paymentMethod;

string items[8] = {
    "Rice",
    "Sugar",
    "Cooking Oil",
    "Milk Pack",
    "Tea Pack",
    "Flour",
    "Eggs",
    "Detergent"
};

double prices[8] = {
    350,180,580,220,
    450,950,320,600
};

double grossBill = 0;

void registerCustomer()
{
    cout << "Enter Customer Name: ";
    cin >> customerName;
    cout << "Enter Customer ID: ";
    cin >> customerID;
    cout << "1. Regular Customer\n2. Member Customer\n";
    cout << "Enter Customer Type: ";
    cin >> customerType;
    cout << "1. Cash\n2. Card\n";
    cout << "Enter Payment Method: ";
    cin >> paymentMethod;
}

void displayItems()
{
    cout << "\n===== GROCERY ITEMS =====\n";
    for(int i=0; i<8; i++)
    {
        cout << i+1 << ". "
             << items[i]
             << " - Rs. "
             << prices[i] << endl;
    }
}

void addToCart()
{
    int itemNo, quantity;
    cout << "Enter Item Number: ";
    cin >> itemNo;
    cout << "Enter Quantity: ";
    cin >> quantity;

    grossBill += prices[itemNo-1] * quantity;

    cout << "Item Added Successfully\n";
}

double calculateTax()
{
    return grossBill * 0.05;
}

double membershipDiscount()
{
    if(customerType == 2)
        return grossBill * 0.07;
    return 0;
}

double billDiscount()
{
    if(grossBill >= 5000 && grossBill <= 10000)
        return grossBill * 0.05;
    else if(grossBill > 10000)
        return grossBill * 0.10;
    return 0;
}

double cardCharges()
{
    if(paymentMethod == 2)
        return grossBill * 0.02;
    return 0;
}

void calculateBill()
{
    double tax = calculateTax();
    double memberDis = membershipDiscount();
    double billDis = billDiscount();
    double cardCharge = cardCharges();

    double total =
        grossBill + tax + cardCharge
        - memberDis - billDis;

    int generatedPoints = total / 100;
    int oldPoints;

    cout << "Enter Existing Loyalty Points: ";
    cin >> oldPoints;

    int totalPoints = generatedPoints + oldPoints;

    int choice;
    cout << "Press 1 to Redeem Points\n";
    cout << "Press 2 to Continue\n";
    cin >> choice;

    if(choice == 1)
    {
        total = total - totalPoints;
    }

    cout << "\n====== GROCERY BILL ======\n";
    cout << "Customer Name: "
         << customerName << endl;
    cout << "Gross Bill: Rs. "
         << grossBill << endl;
    cout << "Sales Tax: Rs. "
         << tax << endl;
    cout << "Member Discount: Rs. "
         << memberDis << endl;
    cout << "Bill Discount: Rs. "
         << billDis << endl;
    cout << "Card Charges: Rs. "
         << cardCharge << endl;
    cout << "Loyalty Points: "
         << totalPoints << endl;
    cout << "Total Payable: Rs. "
         << total << endl;
    cout << "==========================\n";
}

void customerDetails()
{
    cout << "\nCustomer Name: "
         << customerName << endl;
    cout << "Customer ID: "
         << customerID << endl;
}

int main()
{
    registerCustomer();

    int choice;

    do
    {
        cout << "\n===== MAIN MENU =====\n";
        cout << "1. View Grocery Items\n";
        cout << "2. Add Items To Cart\n";
        cout << "3. Calculate Bill\n";
        cout << "4. View Customer Details\n";
        cout << "5. Exit\n";
        cout << "Enter Choice: ";
        cin >> choice;

        switch(choice)
        {
        case 1:
            displayItems();
            break;
        case 2:
            addToCart();
            break;
        case 3:
            calculateBill();
            break;
        case 4:
            customerDetails();
            break;
        case 5:
            cout << "Program Ended\n";
            break;
        default:
            cout << "Invalid Choice\n";
        }

    }while(choice != 5);

    return 0;
}

#include<iostream>
#include<string>
using namespace std;

string userName, email, city, customerType;
int paymentMethod;

string products[8] = {
    "T-Shirt",
    "Jeans",
    "Shoes",
    "Watch",
    "Handbag",
    "Headphones",
    "Mobile Cover",
    "Perfume"
};

float prices[8] = {1200,3500,5000,2500,4200,3000,700,2800};
float productTotal = 0;

void registerUser()
{
    cin.ignore();
    cout << "Enter User Name: ";
    getline(cin, userName);
    cout << "Enter Email: ";
    getline(cin, email);
    cout << "Enter City: ";
    getline(cin, city);
    cout << "Customer Type (New/Returning): ";
    getline(cin, customerType);
    cout << "Payment Method\n";
    cout << "1. Cash on Delivery\n";
    cout << "2. Debit/Credit Card\n";
    cout << "Enter Choice: ";
    cin >> paymentMethod;
}

void displayProducts()
{
    cout << "\n===== PRODUCT LIST =====\n";
    for(int i=0;i<8;i++)
    {
        cout << i+1 << ". "
             << products[i]
             << " - Rs. "
             << prices[i]
             << endl;
    }
}

void addToCart()
{
    int productNo, quantity;
    cout << "\nEnter Product Number: ";
    cin >> productNo;
    cout << "Enter Quantity: ";
    cin >> quantity;

    if(productNo>=1 && productNo<=8)
    {
        productTotal += prices[productNo-1] * quantity;
        cout << "Product Added Successfully!\n";
    }
    else
    {
        cout << "Invalid Product Number!\n";
    }
}

float calculateGST()
{
    return productTotal * 0.17;
}

float deliveryCharges()
{
    if(city=="Lahore" || city=="Karachi" || city=="Islamabad")
        return 250;
    return 500;
}

float customerDiscount()
{
    if(customerType=="New" || customerType=="new")
        return productTotal * 0.05;
    return productTotal * 0.10;
}

float orderDiscount()
{
    if(productTotal>=5000 && productTotal<=10000)
        return productTotal * 0.05;
    else if(productTotal>10000)
        return productTotal * 0.12;
    return 0;
}

float paymentCharges()
{
    if(paymentMethod==2)
        return productTotal * 0.025;
    return 0;
}

void checkoutBill()
{
    float gst = calculateGST();
    float delivery = deliveryCharges();
    float customerDisc = customerDiscount();
    float orderDisc = orderDiscount();
    float paymentFee = paymentCharges();

    float finalBill =
        productTotal +
        gst +
        delivery +
        paymentFee -
        customerDisc -
        orderDisc;

    cout << "\n========== ONLINE SHOPPING BILL ==========\n";
    cout << "User Name: "
         << userName << endl;
    cout << "City: "
         << city << endl;
    cout << "Customer Type: "
         << customerType << endl;
    cout << "\nProduct Total: Rs. "
         << productTotal;
    cout << "\nGST: Rs. "
         << gst;
    cout << "\nDelivery Charges: Rs. "
         << delivery;
    cout << "\nCustomer Discount: Rs. "
         << customerDisc;
    cout << "\nOrder Discount: Rs. "
         << orderDisc;
    cout << "\nPayment Charges: Rs. "
         << paymentFee;
    cout << "\n--------------------------------------------";
    cout << "\nFinal Payable Amount: Rs. "
         << finalBill;
    cout << "\nThank You for Shopping :)";
    cout << "\n==========================================\n";
}

void userDetails()
{
    cout << "\nUser Name: "
         << userName;
    cout << "\nEmail: "
         << email;
    cout << "\nCity: "
         << city;
    cout << "\nCustomer Type: "
         << customerType << endl;
}

int main()
{
    registerUser();

    int choice;

    do
    {
        cout << "\n===== ONLINE SHOPPING MENU =====\n";
        cout << "1. View Products\n";
        cout << "2. Add Product To Cart\n";
        cout << "3. Calculate Checkout Bill\n";
        cout << "4. View User Details\n";
        cout << "5. Exit\n";
        cout << "Enter Choice: ";
        cin >> choice;

        switch(choice)
        {
        case 1:
            displayProducts();
            break;
        case 2:
            addToCart();
            break;
        case 3:
            checkoutBill();
            break;
        case 4:
            userDetails();
            break;
        case 5:
            cout << "Program Ended.\n";
            break;
        default:
            cout << "Invalid Choice!\n";
        }

    }while(choice!=5);

    return 0;
}

#include<iostream>
#include<string>
using namespace std;

string clientName, businessName, businessType;
int campaignDays;
int selectedPlatform = 0;

string platforms[3] = {
    "Instagram",
    "Facebook",
    "LinkedIn"
};

float platformCharges[3] = {
    15000,
    12000,
    20000
};

void registerClient()
{
    cin.ignore();
    cout << "Enter Client Name: ";
    getline(cin, clientName);
    cout << "Enter Business Name: ";
    getline(cin, businessName);
    cout << "Business Type (Small/Medium/Corporate): ";
    getline(cin, businessType);
    cout << "Campaign Duration (Days): ";
    cin >> campaignDays;
}

void displayPlatforms()
{
    cout << "\n===== SOCIAL MEDIA PLATFORMS =====\n";
    for(int i=0; i<3; i++)
    {
        cout << i+1 << ". "
             << platforms[i]
             << " - Rs. "
             << platformCharges[i]
             << endl;
    }
}

void selectPlatform()
{
    cout << "\nSelect Platform (1-3): ";
    cin >> selectedPlatform;

    if(selectedPlatform < 1 || selectedPlatform > 3)
    {
        cout << "Invalid Selection!\n";
        selectedPlatform = 0;
    }
    else
    {
        cout << "Platform Selected Successfully!\n";
    }
}

float calculatePostDesignCost()
{
    int staticPosts, reelPosts, carouselPosts;

    cout << "\nEnter Number of Static Posts: ";
    cin >> staticPosts;
    cout << "Enter Number of Reel/Video Posts: ";
    cin >> reelPosts;
    cout << "Enter Number of Carousel Posts: ";
    cin >> carouselPosts;

    return (staticPosts * 1000) +
           (reelPosts * 2500) +
           (carouselPosts * 1800);
}

float calculateHandlingFee(float adBudget)
{
    if(adBudget < 50000)
        return adBudget * 0.05;
    else if(adBudget <= 100000)
        return adBudget * 0.08;
    else
        return adBudget * 0.10;
}

float calculateExtraCharges()
{
    if(campaignDays > 30)
        return (campaignDays - 30) * 500;
    return 0;
}

float calculateDiscount(float total)
{
    if(businessType == "Small" || businessType == "small")
        return total * 0.05;
    else if(businessType == "Medium" || businessType == "medium")
        return total * 0.08;
    else
        return total * 0.10;
}

float calculateGST(float total)
{
    return total * 0.16;
}

void calculateCampaignCost()
{
    if(selectedPlatform == 0)
    {
        cout << "Please Select Platform First!\n";
        return;
    }

    float postCost = calculatePostDesignCost();
    float adBudget;
    cout << "Enter Advertisement Budget: ";
    cin >> adBudget;

    float handlingFee = calculateHandlingFee(adBudget);
    float extraCharges = calculateExtraCharges();
    float platformFee =
        platformCharges[selectedPlatform - 1];

    float subTotal =
        platformFee +
        postCost +
        adBudget +
        handlingFee +
        extraCharges;

    float gst = calculateGST(subTotal);
    float discount = calculateDiscount(subTotal);

    float finalBill =
        subTotal +
        gst -
        discount;

    cout << "\n========== SOCIAL MEDIA CAMPAIGN BILL ==========\n";
    cout << "Client Name: "
         << clientName << endl;
    cout << "Business Name: "
         << businessName << endl;
    cout << "Business Type: "
         << businessType << endl;
    cout << "Selected Platform: "
         << platforms[selectedPlatform - 1] << endl;
    cout << "Campaign Duration: "
         << campaignDays
         << " Days\n";
    cout << "\nPlatform Management Charges: Rs. "
         << platformFee;
    cout << "\nPost Design Cost: Rs. "
         << postCost;
    cout << "\nAd Budget: Rs. "
         << adBudget;
    cout << "\nAd Handling Fee: Rs. "
         << handlingFee;
    cout << "\nExtra Duration Charges: Rs. "
         << extraCharges;
    cout << "\nGST: Rs. "
         << gst;
    cout << "\nDiscount: Rs. "
         << discount;
    cout << "\n--------------------------------------------------";
    cout << "\nFinal Campaign Cost: Rs. "
         << finalBill;
    cout << "\n================================================\n";
}

void displayClientDetails()
{
    cout << "\nClient Name: "
         << clientName;
    cout << "\nBusiness Name: "
         << businessName;
    cout << "\nBusiness Type: "
         << businessType;
    cout << "\nCampaign Duration: "
         << campaignDays
         << " Days\n";
}

int main()
{
    registerClient();

    int choice;

    do
    {
        cout << "\n===== SOCIAL MEDIA MENU =====\n";
        cout << "1. View Platforms\n";
        cout << "2. Select Platform\n";
        cout << "3. Calculate Campaign Cost\n";
        cout << "4. View Client Details\n";
        cout << "5. Exit\n";
        cout << "Enter Choice: ";
        cin >> choice;

        switch(choice)
        {
        case 1:
            displayPlatforms();
            break;
        case 2:
            selectPlatform();
            break;
        case 3:
            calculateCampaignCost();
            break;
        case 4:
            displayClientDetails();
            break;
        case 5:
            cout << "Program Ended.\n";
            break;
        default:
            cout << "Invalid Choice!\n";
        }

    } while(choice != 5);

    return 0;
}

#include<iostream>
#include<string>
using namespace std;

string username, password;
string titles[20];
string contents[20];
int totalEntries = 0;

void registerUser()
{
    cout << "\n===== REGISTER =====\n";
    cout << "Enter Username: ";
    cin >> username;
    cout << "Enter Password: ";
    cin >> password;
    cout << "\nRegistration Successful!\n";
}

bool login()
{
    string user, pass;
    cout << "\n===== LOGIN =====\n";
    cout << "Enter Username: ";
    cin >> user;
    cout << "Enter Password: ";
    cin >> pass;

    if(user == username && pass == password)
    {
        cout << "\nLogin Successful!\n";
        return true;
    }

    cout << "\nInvalid Username or Password!\n";
    return false;
}

void createEntry()
{
    if(totalEntries >= 20)
    {
        cout << "\nDiary Full!\n";
        return;
    }

    cin.ignore();
    cout << "\nEnter Title: ";
    getline(cin, titles[totalEntries]);
    cout << "Enter Content: ";
    getline(cin, contents[totalEntries]);

    totalEntries++;

    cout << "\nEntry Added Successfully!\n";
}

void viewAllEntries()
{
    if(totalEntries == 0)
    {
        cout << "\nNo Entries Found!\n";
        return;
    }

    cout << "\n===== ALL ENTRIES =====\n";
    for(int i = 0; i < totalEntries; i++)
    {
        cout << i + 1 << ". "
             << titles[i] << endl;
    }
}

void readFullEntry()
{
    int entryNo;
    cout << "\nEnter Entry Number: ";
    cin >> entryNo;

    if(entryNo < 1 || entryNo > totalEntries)
    {
        cout << "Invalid Entry Number!\n";
        return;
    }

    cout << "\nTitle: "
         << titles[entryNo - 1];
    cout << "\nContent: "
         << contents[entryNo - 1]
         << endl;
}

void editEntry()
{
    int entryNo;
    cout << "\nEnter Entry Number To Edit: ";
    cin >> entryNo;

    if(entryNo < 1 || entryNo > totalEntries)
    {
        cout << "Invalid Entry Number!\n";
        return;
    }

    cin.ignore();
    cout << "Enter New Title: ";
    getline(cin, titles[entryNo - 1]);
    cout << "Enter New Content: ";
    getline(cin, contents[entryNo - 1]);

    cout << "\nEntry Updated Successfully!\n";
}

void deleteEntry()
{
    int entryNo;
    cout << "\nEnter Entry Number To Delete: ";
    cin >> entryNo;

    if(entryNo < 1 || entryNo > totalEntries)
    {
        cout << "Invalid Entry Number!\n";
        return;
    }

    for(int i = entryNo - 1; i < totalEntries - 1; i++)
    {
        titles[i] = titles[i + 1];
        contents[i] = contents[i + 1];
    }

    totalEntries--;

    cout << "\nEntry Deleted Successfully!\n";
}

void deleteAllEntries()
{
    totalEntries = 0;
    cout << "\nAll Entries Deleted Successfully!\n";
}

int main()
{
    registerUser();

    if(!login())
        return 0;

    int choice;

    do
    {
        cout << "\n===== PERSONAL STUDENT DIARY =====\n";
        cout << "1. Create New Diary Entry\n";
        cout << "2. View All Entries\n";
        cout << "3. Read Full Entry\n";
        cout << "4. Edit Entry\n";
        cout << "5. Delete One Entry\n";
        cout << "6. Delete All Entries\n";
        cout << "7. Exit\n";
        cout << "Enter Choice: ";
        cin >> choice;

        switch(choice)
        {
        case 1:
            createEntry();
            break;
        case 2:
            viewAllEntries();
            break;
        case 3:
            readFullEntry();
            break;
        case 4:
            editEntry();
            break;
        case 5:
            deleteEntry();
            break;
        case 6:
            deleteAllEntries();
            break;
        case 7:
            cout << "\nProgram Ended.\n";
            break;
        default:
            cout << "\nInvalid Choice!\n";
        }

    } while(choice != 7);

    return 0;
}

