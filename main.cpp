#include <iostream>
#include <string>
#include <windows.h>
#include <vector>
#include <limits>
#include <algorithm>
#include <cctype>
#include <set>
#include <type_traits>
#include <time.h>
#include <cstdlib>
#include <iomanip>
#include <ctime>
#include <sstream>

using namespace std;

struct Account {
    string username;
    string email;
    string password;
    double money;
    double notApproved;
    bool status;
};

struct Product {
    string name;
    string category;
    string animal;
    string description;
    double price;
    int stock;
    bool status;
};

struct Cart {
    string email;
    int product;
    int quantity;
    bool status;
};

// struct Checkout {
//     string email;
//     int product;
//     int quantity;
//     string date;
// };

vector<Account> accounts;
vector<Product> products;
vector<Cart> carts;
// vector<Checkout> checkouts;

bool loginStatus = false;
string loginEmail = "";

//declaration of functions
void displayMenu();
void login();
void registration();
void accountProfile();
void menuAdmin(string choose);
void homeAdmin();
void searchAdmin();
void searchAcc();
void searchProducts();
void viewAccounts();
void editAccount(int accNumber);
void viewInventory();
void addItem();
void editItem(int p_num);
void viewCheckouts();
void menuCustomer(string choose);
void homeCustomer();
void foods();
void equipments();
void medicine();
void viewItem(int p_num);
void cart();
void menuCart(int p_num);
void checkout();
void invalidInput();
bool checkAccount(string accountType);
string checkInput(string choose);
int getRandomNumber(const vector<Product>& vec);
bool contains(const string& str, const string& searchProd);
template <typename T>
typename enable_if<is_same<T, Product>::value, vector<T>>::type
search(const vector<T>& items, const string& SearchTerm);
template <typename T>
typename enable_if<is_same<T, Account>::value, vector<T>>::type
search(const vector<T>& items, const string& SearchTerm);

int main() {

    // admin's account
    accounts.push_back({"admin", "admin", "admin", 0, 0, false});

    // customer's account
    accounts.push_back({"gabrielle", "gabrielleramos@gmail.com", "gab", 1000, 0, false});

    // add more account for test and presentation here

    // products for "cat" to the vector
    products.push_back({"Maxime (1 kilo)", "Food", "Cat", "5-6 weeks old higher", 90, 30, true});
    products.push_back({"Whiskas (1 kilo)", "Food", "Cat", "5-6 weeks old higher", 155, 30, false});
    products.push_back({"Cuties (1 kilo)", "Food", "Cat", "5-6 weeks old higher", 130, 30, true});
    products.push_back({"Smartheart (1 kilo)", "Food", "Cat", "5-6 weeks old higher", 165, 30, true});
    products.push_back({"Kitcat (1 kilo)", "Food", "Cat", "5-6 weeks old higher", 52, 30, true});
    products.push_back({"Whiskas (400 g)", "Food", "Cat", "1 Years above", 99, 30, true});
    products.push_back({"Goodest (85 g)", "Food", "Cat", "6 Months above", 28, 30, true});
    products.push_back({"Aozi (430 g)", "Food", "Cat", "7 Months above", 82, 30, true});
    products.push_back({"Lc Vit Plus (120ml)", "Medicine", "Cat", "12 weeks higher", 150, 30, true});
    products.push_back({"Pneumex (60ml)", "Medicine", "Cat", "3 months", 167, 30, true});
    products.push_back({"Advocate (4 kg)", "Medicine", "Cat", "9 weeks higher", 499, 30, true});
    products.push_back({"Wormeze (8 oz)", "Medicine", "Cat", "6 months higher", 719, 30, true});
    products.push_back({"Drontal (18.2 mg)", "Medicine", "Cat", "1 month higher", 313, 30, true});
    products.push_back({"Capstar (57 mg)", "Medicine", "Cat", "4 weeks higher", 475, 30, true});
    products.push_back({"Capaction (11.4 mg)", "Medicine", "Cat", "4 weeks higher", 137, 30, true});
    products.push_back({"Flea Guard (2.5 ml)", "Medicine", "Cat", "8 weeks higher", 125, 30, true});
    products.push_back({"Litter Box", "Equipment", "Cat", "Splash proof cat litter box", 260, 30, true});
    products.push_back({"Bed", "Equipment", "Cat", "Cat Bed House", 120, 30, true});
    products.push_back({"Scratching Posts", "Equipment", "Cat", "Cat Scratch Post ", 66, 30, true});
    products.push_back({"Toy Bell", "Equipment", "Cat", "Wiggly Ball Cat Bells", 57, 30, true});
    products.push_back({"Food/Water Bowl", "Equipment", "Cat", "2 in 1 Cat Bowl", 119, 30, true});
    products.push_back({"Collar ", "Equipment", "Cat", "Adjustable w/ bell", 48, 30, true});
    products.push_back({"Cage", "Equipment", "Cat", "Collapsible cage", 399, 30, true});
    products.push_back({"Litter Sand (10 L)", "Equipment", "Cat", "Lavender scent", 250, 30, true});

   // products for "dog" to the vector
    products.push_back({"Nutrichunks (500 g)", "Food", "Dog", "12 months old above", 250, 30, true});
    products.push_back({"Vitalamb (1kg)", "Food", "Dog", "15 months old above", 102, 30, true});
    products.push_back({"Pedigree (1kg)", "Food", "Dog", "4 weeks old above", 146, 30, true});
    products.push_back({"Top Breed (1kg)", "Food", "Dog", "4 months old above", 99, 30, true});
    products.push_back({"Royal Canin (500g)", "Food", "Dog", "ten months old above", 179, 30, true});
    products.push_back({"Pedigree Pouch (30g)", "Food", "Dog", "3 weeks old above", 32, 30, true});
    products.push_back({"Jerhigh Pouch (120g)", "Food", "Dog", "2 months old above", 50, 30, true});
    products.push_back({"SmartHeart Pouch (80g)", "Food", "Dog", "2 months old above", 39, 30, true});
    products.push_back({"Himalaya (100ml)", "Medicine", "Dog", "treats for liver, kidney, digestive, etc.", 265, 30, true});
    products.push_back({"Multivitamins (120 ml)", "Medicine", "Dog", "12 weeks above", 118, 30, true});
    products.push_back({"Nematocide (15ml)", "Medicine", "Dog", "against roundworms & hookworms", 115, 30, true});
    products.push_back({"Doxycycline (60 ml)", "Medicine", "Dog", "tetracycline antibiotic for anaplasma, heartworm & periodontal disease", 107, 30, true});
    products.push_back({"Nexgard (260 g)", "Medicine", "Dog", "protection for fleas, ticks & mites", 419, 30, true});
    products.push_back({"Wormgard (150 mg)", "Medicine", "Dog", "for control of all gastrointestinal worms", 165, 30, true});
    products.push_back({"Simparica trio (120 mg)", "Medicine", "Dog", "against naturally occurring flea & tick infestations", 495, 30, true});
    products.push_back({"Bravecto (98 mg)", "Medicine", "Dog", "for parasites", 394, 30, true});
    products.push_back({"Dog bowl", "Equipment", "Dog", "for placement of dog food & water", 75, 30, true});
    products.push_back({"Dog bed", "Equipment", "Dog", "for comfortable god sleep", 181, 30, true});
    products.push_back({"Dog backpack ", "Equipment", "Dog", "for owner's dog carrier", 189, 30, true});
    products.push_back({"Dog collar", "Equipment", "Dog", "for dog's restraint & protection", 98, 30, true});
    products.push_back({"Clothes", "Equipment", "Dog", "for dog's fashion & cold protection", 125, 30, true});
    products.push_back({"Diaper", "Equipment", "Dog", "for dog's urinary incontinence", 65, 30, true});
    products.push_back({"Muzzles", "Equipment", "Dog", "preventive equipment for dog's violence", 89, 30, true});
    products.push_back({"Dog crate", "Equipment", "Dog", "for dog's confinement", 120, 30, true});

    // products for "fish" to the vector
    products.push_back({"Fish flakes (20 g)", "Food", "Fish", "all ages of fish", 160, 30, true});
    products.push_back({"Fish pellets (50 g)", "Food", "Fish", "all ages of fish", 67, 30, true});
    products.push_back({"Pimafix (16 oz)", "Medicine", "Fish", "for fungal infections", 370, 30, true});
    products.push_back({"Aqua Guard (1L)", "Medicine", "Fish", "purifier for high water savings", 93, 30, true});
    products.push_back({"API Melafix (16 oz)", "Medicine", "Fish", "all- natural antibacterial treatment for fish infections", 350, 30, true});
    products.push_back({"Paracidol-Fw (100ml)", "Medicine", "Fish", "for external & internal parasitic infection", 124, 30, true});
    products.push_back({"Air pump", "Equipment", "Fish", "promotes gas exchange at water surface", 135, 30, true});
    products.push_back({"Aquarium (5 gal)", "Equipment", "Fish", "artificial habitats for fish", 290, 30, true});
    products.push_back({"Aquarium heater (50w)", "Equipment", "Fish", "keeps aquarium temperature warm", 199, 30, true});

    // products for "bird" to the vector
    products.push_back({"Bird seed mix (1k)", "Food", "Bird", "for all ages of bird", 30, 30, true});
    products.push_back({"African mix (1k)", "Food", "Bird", "for all ages of bird", 75, 30, true});
    products.push_back({"Parakeet (500 g)", "Food", "Bird", "for all ages of bird", 245, 30, true});
    products.push_back({"Premium mix (1k)", "Food", "Bird", "for all ages of bird", 68, 30, true});
    products.push_back({"Mynah bird food (1kg)", "Food", "Bird", "for all ages of bird", 195, 30, true});
    products.push_back({"Baytril (12,5 ml)", "Medicine", "Bird", "for bacterial infections", 240, 30, true});
    products.push_back({"Amtyl (500 g)", "Medicine", "Bird", "for prevention of CRD & fowl pox", 150, 30, true});
    products.push_back({"Enrofloxacin (20 ml)", "Medicine", "Bird", "for bacterial infections", 279, 30, true});
    products.push_back({"Pikoy BACTI Bird (10 ml)", "Medicine", "Bird", "for bird's systemic & bacterial infections", 148, 30, true});
    products.push_back({"Aviator Harness & Leash", "Equipment", "Bird", "for safely taking bird outside", 143, 30, true});
    products.push_back({"Bird cage", "Equipment", "Bird", "protects bird from getting out", 500, 30, true});
    products.push_back({"Bird feeder", "Equipment", "Bird", "equipment for placing bird food", 113, 30, true});

    homeCustomer();
}

void displayMenu() {
    system("cls");
    SetConsoleOutputCP(CP_UTF8); // line of code to print unicode/special/emoji characters

    // add condition when adding colors when menu is selected

    if (loginEmail == "admin") { //menu of admin
        cout << "┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓" << endl;
        cout << "┃\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t┃" << endl;
        cout << "┃\t\t\t\t██████╗░███████╗████████╗░░███████╗██╗░░██╗██████╗░██████╗░███████╗░██████╗░██████╗\t\t\t\t┃" << endl;
        cout << "┃\t\t\t\t██╔══██╗██╔════╝╚══██╔══╝░░██╔════╝╚██╗██╔╝██╔══██╗██╔══██╗██╔════╝██╔════╝██╔════╝\t\t\t\t┃" << endl;
        cout << "┃\t\t\t\t██████╔╝█████╗░░░░░██║░░░░░█████╗░░░╚███╔╝░██████╔╝██████╔╝█████╗░░╚█████╗░╚█████╗░\t\t\t\t┃" << endl;
        cout << "┃\t\t\t\t██╔═══╝░██╔══╝░░░░░██║░░░░░██╔══╝░░░██╔██╗░██╔═══╝░██╔══██╗██╔══╝░░░╚═══██╗░╚═══██╗\t\t\t\t┃" << endl;
        cout << "┃\t\t\t\t██║░░░░░███████╗░░░██║░░░░░███████╗██╔╝╚██╗██║░░░░░██║░░██║███████╗██████╔╝██████╔╝\t\t\t\t┃" << endl;
        cout << "┃\t\t\t\t╚═╝░░░░░╚══════╝░░░╚═╝░░░░░╚══════╝╚═╝░░╚═╝╚═╝░░░░░╚═╝░░╚═╝╚══════╝╚═════╝░╚═════╝░\t\t\t\t┃" << endl;
        cout << "┃\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t┃" << endl;
        cout << "┣━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┳━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫" << endl;
        cout << "┃\t\t\t\t\t\t\t\t\t┃\t\t\t\t\t\t\t\t\t┃" << endl;
        cout << "┃\t\t\t[S] Search\t[A] Account\t\t\t┃\t\t[C] Accounts\t[I] Products\t[O] Checkouts\t\t┃" << endl;
        cout << "┃\t\t\t\t\t\t\t\t\t┃\t\t\t\t\t\t\t\t\t┃" << endl;
        cout << "┣━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┻━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫" << endl;
        
    } else { //menu of customer
        cout << "┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓" << endl;
        cout << "┃\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t┃" << endl;
        cout << "┃\t\t\t\t██████╗░███████╗████████╗░░███████╗██╗░░██╗██████╗░██████╗░███████╗░██████╗░██████╗\t\t\t\t┃" << endl;
        cout << "┃\t\t\t\t██╔══██╗██╔════╝╚══██╔══╝░░██╔════╝╚██╗██╔╝██╔══██╗██╔══██╗██╔════╝██╔════╝██╔════╝\t\t\t\t┃" << endl;
        cout << "┃\t\t\t\t██████╔╝█████╗░░░░░██║░░░░░█████╗░░░╚███╔╝░██████╔╝██████╔╝█████╗░░╚█████╗░╚█████╗░\t\t\t\t┃" << endl;
        cout << "┃\t\t\t\t██╔═══╝░██╔══╝░░░░░██║░░░░░██╔══╝░░░██╔██╗░██╔═══╝░██╔══██╗██╔══╝░░░╚═══██╗░╚═══██╗\t\t\t\t┃" << endl;
        cout << "┃\t\t\t\t██║░░░░░███████╗░░░██║░░░░░███████╗██╔╝╚██╗██║░░░░░██║░░██║███████╗██████╔╝██████╔╝\t\t\t\t┃" << endl;
        cout << "┃\t\t\t\t╚═╝░░░░░╚══════╝░░░╚═╝░░░░░╚══════╝╚═╝░░╚═╝╚═╝░░░░░╚═╝░░╚═╝╚══════╝╚═════╝░╚═════╝░\t\t\t\t┃" << endl;
        cout << "┃\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t┃" << endl;
        cout << "┣━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┳━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫" << endl;
        cout << "┃\t\t\t\t\t\t\t\t\t┃\t\t\t\t\t\t\t\t\t┃" << endl;
        cout << "┃\t\t[S] Search\t[A] Account\t[C] Cart\t\t┃\t[H] Home\t[F] Foods\t[Q] Equipment\t[M] Medicine\t┃" << endl;
        cout << "┃\t\t\t\t\t\t\t\t\t┃\t\t\t\t\t\t\t\t\t┃" << endl;
        cout << "┣━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┻━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫" << endl;
    }
}

void login() {
    string email, password;
    int choose;

    displayMenu();
    
    cout << "┃\t\t[R] No Account? Register Now!\t\t\t      LOGIN  \t\t\t\t\t\t\t\t\t┃" << endl;
    cout << "┣━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫" << endl << endl;

    cout << "\t\t\t\t\t\t\t[action] Email: ";
    cin >> email;

    if (checkInput(email) == "alpha" && email.length() == 1) {
        transform(email.begin(), email.end(), email.begin(), ::tolower);

        if (email == "r") {
            registration();

        } else {
            menuCustomer(email);
            login();
        }

    } else {
        cout << "\t\t\t\t\t\t\t      Password: ";
        cin >> password;
        cout << endl;
        cout << "┣━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┳━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫" << endl;
        cout << "┃\t\t\t\t[1] Login\t\t\t\t┃\t\t\t\t[0] Clear\t\t\t\t┃" << endl;
        cout << "┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┻━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛" << endl;

        cout << "\t\t☛ Input action: ";
        cin >> choose;

        cout << "━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━" << endl;

        // check if string is inputted in an int variable
        if (cin.fail()) {
            invalidInput();

            cout << "\t\tClearing fields...";
            Sleep(2000);

            cin.clear(); // clear input
            cin.ignore(LONG_MAX, '\n'); // ignore any error

            login();

        } else {
            switch(choose) {
                case 0:
                    cout << "\t\tClearing fields...";
                    Sleep(3000);

                    login();
                    break;
                    
                case 1:
                    {
                        cout << "\t\tLogging In..." << endl;
                        Sleep(3000);

                        // iterate over registered users to find a match
                        bool found = false;
                        bool status;
                        for (const auto& account : accounts) {
                            if (email == account.email && password == account.password) {
                                found = true;
                                status = account.status; // check account's status
                                break;
                            }
                        }

                        if (!found) { // user's credentials did not match any registered users
                            cout << "\t\tInvalid email address or password." << endl;
                            Sleep(2000);

                            login();

                        } else if (status) { // user's account is banned
                            cout << "\t\tCannot login, your account is banned." << endl;
                            Sleep(2000);

                            login();
                            
                        } else {
                            loginStatus = true;
                            loginEmail = email;

                            cout << "\t\tLogin successful!";
                            Sleep(2000);

                            if (loginEmail == "admin") homeAdmin();
                            else homeCustomer();
                        }
                    }
                    break;
                    
                default:
                    invalidInput();

                    cout << "\t\tClearing fields...";
                    Sleep(2000);

                    login();
                    break;
            }
        }
    }
}

void registration() {
    string email, username, password;
    int choose;

    cout << username;

    displayMenu();

    cout << "┃\t\t\t\t\t\t\t\t  REGISTRATION      \t\t\t\t\t\t\t\t┃" << endl;
    cout << "┣━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫" << endl << endl;

    cout << "\t\t\t\t\t\t[action] Username: ";
    cin >> username;

    if (checkInput(username) == "alpha" && username.length() == 1) {
        transform(username.begin(), username.end(), username.begin(), ::tolower);

        menuCustomer(username);
        registration();

    } else {
        // add validation for username here

        cout << "\t\t\t\t\t\t\t    Email: ";
        cin >> email;

        // add validation for email here

        cout << "\t\t\t\t\t\t\t Password: ";
        cin >> password;

        // add validation for password & confirm password here
        
        cout << endl;
        cout << "┣━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┳━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫" << endl;
        cout << "┃\t\t\t\t[1] Register\t\t\t\t┃\t\t\t\t[0] Clear\t\t\t\t┃" << endl;
        cout << "┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┻━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛" << endl;
    
        cout << "\t\t☛ Input action: ";
        cin >> choose;

        cout << "━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━" << endl;

        // check if string is inputted in an int variable
        if (cin.fail()) {
            invalidInput();
            
            cout << "\t\tClearing fields...";
            Sleep(2000);

            cin.clear(); // clear input
            cin.ignore(LONG_MAX, '\n'); // ignore any error

            registration();

        } else {
            switch(choose) {
                case 0:
                    cout << "\t\tClearing fields...";
                    Sleep(3000);

                    registration();
                    break;
                
                case 1:
                    {
                        cout << "\t\tRegistering..." << endl;
                        Sleep(3000);

                        // Check if the email address is already registered
                        bool found = false;
                        for (const auto& account : accounts) {
                            if (email == account.email) {
                                // Email address is already registered
                                cout << "\t\tThat email address is already registered. Please try again." << endl;
                                found = true;
                                break;
                            }
                        }

                        if (!found) {
                            // Add the user's information to the vector
                            accounts.push_back({username, email, password, 0, 0, false});

                            cout << "\t\tRegistration successful!";
                            Sleep(2000);

                            login();

                        } else {
                            Sleep(2000);
                            registration();
                        }
                    }
                    break;
                
                default:
                    invalidInput();

                    cout << "\t\tClearing fields...";
                    Sleep(2000);

                    registration();
                    break;
            }
        }
    }
}

void accountProfile() {
    string choose, temp;
    int accNumber, choose1;
    double money;

    displayMenu();

    cout << "┃\t\t\t\t\t\t\t\t    PROFILE    \t\t\t\t\t\t\t\t\t┃" << endl;
    cout << "┣━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫" << endl << endl;

    //display user's credentials
    for (int i = 0; i < accounts.size(); i++) {
        if (loginEmail == accounts[i].email) {

            cout << "\t\t\t\t\t\t\t       Email: " << accounts[i].email << endl;
            cout << "\t\t\t\t\t\t\t[1] Username: " << accounts[i].username << endl;
            cout << "\t\t\t\t\t\t\t[2] Password: " << accounts[i].password << endl;
            cout << "\t\t\t\t\t\t\t     Petcoin: " << accounts[i].money << endl << endl;

            accNumber = i;
            break;
        }
    }

    if (loginEmail == "admin") {
        cout << "┣━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫" << endl;
        cout << "┃\t\t\t\t\t\t\t\t   [L] Logout     \t\t\t\t\t\t\t\t┃" << endl;
        cout << "┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛" << endl;

    } else {
        cout << "┣━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┳━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫" << endl;
        cout << "┃\t\t\t\t[+] Add Petcoin\t\t\t\t┃\t\t\t\t  [L] Logout  \t\t\t\t┃" << endl;
        cout << "┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┻━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛" << endl;
    }

    cout << "\t\t☛ Input [action]: ";
    cin >> choose;

    cout << "━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━" << endl;

    if (loginEmail != "admin" && choose == "+") {

        cout << "┃\t\t\t\t\t\t\t\tADD PETCOIN\t\t\t\t\t\t\t\t\t┃" << endl;
        cout << "┣━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫" << endl << endl;

        if (accounts[accNumber].notApproved != 0) {
            cout << "You still have " << accounts[accNumber].notApproved << " Petcoin still in queue for approval." << endl;
            Sleep(3000);

            accountProfile();

        } else {
            cout << "\t\t\t\t\t\t\tHow much : ";
            cin >> money;
        }

        // check if string is inputted in an int variable
        if (cin.fail()) {
            invalidInput();
            
            cout << "\t\tCanceling process...";
            Sleep(2000);

            cin.clear(); // clear input
            cin.ignore(LONG_MAX, '\n'); // ignore any error

            accountProfile();

        } else if (money > 0) {

            cout << endl;
            cout << "┣━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┳━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫" << endl;
            cout << "┃\t\t\t\t[1] Save\t\t\t\t┃\t\t\t\t[0] Cancel\t\t\t\t┃" << endl;
            cout << "┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┻━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛" << endl;

            cout << "\t\t☛ Input action: ";
            cin >> choose1;

            cout << "━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━" << endl;

            // check if string is inputted in an int variable
            if (cin.fail()) {
                invalidInput();
                
                cout << "\t\tCanceling process...";
                Sleep(2000);

                cin.clear(); // clear input
                cin.ignore(LONG_MAX, '\n'); // ignore any error

                accountProfile();

            } else {
                switch(choose1) {
                    case 0:
                        cout << "\t\tCanceling process...";
                        Sleep(3000);

                        accountProfile();
                        break;
                    
                    case 1:
                        accounts[accNumber].notApproved = money;

                        cout << "\t\tPetcoin will be added in your account, please wait for approval";
                        Sleep(3000);

                        accountProfile();
                        break;
                    
                    default:
                        invalidInput();

                        cout << "\t\tCanceling process...";
                        Sleep(2000);

                        accountProfile();
                        break;
                }
            }

        } else {
            cout << "\t\tMoney must not less than 0.";
            Sleep(2000);
            
            cout << "\t\tCanceling process...";
            Sleep(2000);
        }
        
    } else if (checkInput(choose) == "alpha" && choose.length() == 1) {
        transform(choose.begin(), choose.end(), choose.begin(), ::tolower);

        if (choose == "l") { // logout
            cout << "\t\tLogging out...";
            Sleep(3000);

            loginStatus = false;
            loginEmail = "";

            homeCustomer();

        } else {
            if (loginEmail == "admin") menuAdmin(choose);
            else menuCustomer(choose);

            accountProfile();
        }

    } else if (checkInput(choose) == "number" && stoi(choose) <= 2 && stoi(choose) > 0) {
        displayMenu();

        switch(stoi(choose)) {
            case 1:
                cout << "┃\t\t\t\t\t\t\t\tEDIT USERNAME\t\t\t\t\t\t\t\t\t┃" << endl;
                cout << "┣━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫" << endl << endl;
                cout << "\t\t\t\t\t\t\tOld username: " << accounts[accNumber].username << endl;
                cout << "\t\t\t\t\t\t  Enter new username: ";
                break;

            case 2:
                cout << "┃\t\t\t\t\t\t\t\tEDIT PASSWORD\t\t\t\t\t\t\t\t\t┃" << endl;
                cout << "┣━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫" << endl << endl;
                cout << "\t\t\t\t\t\t\tOld password: " << accounts[accNumber].password << endl;
                cout << "\t\t\t\t\t\t  Enter new password: ";
                break;
        }

        cin >> temp;

        cout << endl;
        cout << "┣━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┳━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫" << endl;
        cout << "┃\t\t\t\t[1] Save\t\t\t\t┃\t\t\t\t[0] Cancel\t\t\t\t┃" << endl;
        cout << "┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┻━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛" << endl;

        cout << "\t\t☛ Input action: ";
        cin >> choose1;

        cout << "━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━" << endl;

        // check if string is inputted in an int variable
        if (cin.fail()) {
            invalidInput();
            
            cout << "\t\tCanceling process...";
            Sleep(2000);

            cin.clear(); // clear input
            cin.ignore(LONG_MAX, '\n'); // ignore any error

            accountProfile();

        } else {
            switch(choose1) {
                case 0:
                    cout << "\t\tCanceling process...";
                    Sleep(3000);

                    accountProfile();
                    break;
                
                case 1:
                    if (stoi(choose) == 0) accounts[accNumber].username = temp; // change username
                    else if (stoi(choose) == 1) accounts[accNumber].password = temp; // change password

                    cout << "\t\tApplying changes...";
                    Sleep(3000);

                    accountProfile();
                    break;
                
                default:
                    invalidInput();

                    cout << "\t\tCanceling process...";
                    Sleep(2000);

                    accountProfile();
                    break;
            }
        }

    } else {
        invalidInput();
        accountProfile();
    }
}

void menuAdmin(string choose) {

    if (choose == "s") {
        searchAdmin();
    
    } else if (choose == "a") {
        accountProfile();

    } else if (choose == "c") {
        viewAccounts();

    } else if (choose == "i") {
        viewInventory();

    } else if (choose == "o") {
        viewCheckouts();

    } else {
        invalidInput();
    }
}

void homeAdmin() {
    viewAccounts();
}

void searchAdmin() {
    int choose;
    string searchTerm;
    
    displayMenu();

    cout << "┃\t\t\tSEARCH ➜\t\t\t\t[1] Accounts\t\t\t\t[2] Products\t\t\t\t┃" << endl;
    cout << "┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛" << endl;

    cout << "\t\t\t\tInput action: ";
    cin >> choose;

    cout << "━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━" << endl;

    if (cin.fail()) {
        invalidInput();

        cout << "\t\tClearing fields...";
        Sleep(2000);

        cin.clear(); // clear input
        cin.ignore(LONG_MAX, '\n'); // ignore any error

        searchAdmin();

    } else {
        switch (choose){
            case 1: searchAcc();
            case 2: searchProducts();
            default:
                invalidInput();
                searchAdmin();
        }
    }
}

void searchProducts() {
    string searchTerm, choose;

    displayMenu();
    
    cout << "\t\tEnter a search term:  ";
    cin >> searchTerm;

    vector<Product> results = search<Product>(products, searchTerm);

    cout << "┣━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┳━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┳━━━━━━━━━━━━━━━━━━━━━━━┳━━━━━━━━━━━━━━━━━━━━━━━┫" << endl;
    cout << "┃\t\t\tProduct Name\t\t\t┃\t\tCategory\t\t┃\t  Animal      \t┃\t  Price      \t┃" << endl;
    
    if (!results.empty()) {
        cout << "┣━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━╋━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━╋━━━━━━━━━━━━━━━━━━━━━━━╋━━━━━━━━━━━━━━━━━━━━━━━┫" << endl;
        cout << "┃\t\t\t\t\t\t\t┃\t\t\t\t\t┃\t\t\t┃\t\t\t┃" << endl;
       
        //displaying search results
        for (int i = 0; i < results.size(); i++) {
            for (int j = 0; j < products.size(); j++) {
                if (results[i].name == products[j].name) {
                    cout << "┃\t\t[" << j << "] " << results[i].name << "\t\t";

                    if (results[i].name.length() <= 10) cout << "\t\t";
                    else if (results[i].name.length() <= 19 && j < 10) cout << "\t";
                    else if (results[i].name.length() <= 18 && j >= 10) cout << "\t";

                    cout << "┃\t\t" << results[i].category;

                    if (results[i].category == "Food") cout << "\t";

                    cout << "\t\t┃\t   " << results[i].animal << "     \t┃\t  ₱ " << products[i].price << "      \t┃" << endl;

                    break;
                }
            }
        }
        
        cout << "┃\t\t\t\t\t\t\t┃\t\t\t\t\t┃\t\t\t┃\t\t\t┃" << endl;
        cout << "┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┻━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┻━━━━━━━━━━━━━━━━━━━━━━━┻━━━━━━━━━━━━━━━━━━━━━━━┛" << endl;

    } else {
        cout << "┣━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┻━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┻━━━━━━━━━━━━━━━━━━━━━━━┻━━━━━━━━━━━━━━━━━━━━━━━┫" << endl;
        cout << "┃\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t┃" << endl;
        cout << "┃\t\t\t\t\t\t\t\tNo result for: " << searchTerm << "\t\t\t\t\t\t\t\t┃" << endl;
        cout << "┃\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t┃" << endl;
        cout << "┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛" << endl;
    }

    cout << "\t\t☛ Input [action]: ";
    cin >> choose;

    cout << "━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━" << endl;

    if (checkInput(choose) == "alpha" && choose.length() == 1) {
        transform(choose.begin(), choose.end(), choose.begin(), ::tolower);

        if (loginEmail == "admin") menuAdmin(choose);
        else menuCustomer(choose);

        searchProducts();

    } else if (checkInput(choose) == "number" && products.size() > stoi(choose) && stoi(choose) >= 0) {
        if (loginEmail == "admin") editItem(stoi(choose));
        else viewItem(stoi(choose));

    } else {
        invalidInput();
        searchProducts();
    }       
}

void searchAcc() {
    string searchTerm, choose;

    displayMenu();

    cout << "\t\tEnter a search term:  ";
    cin >> searchTerm;

    vector<Account> results = search<Account>(accounts, searchTerm);
                
    cout << "┣━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┳━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┳━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫" << endl;
    cout << "┃\t\t\tUsername\t\t\t┃\t\t\t    Email    \t\t\t┃\t      Status  \t\t┃" << endl;

    if (!results.empty()) {
        cout << "┣━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━╋━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━╋━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫" << endl;
        cout << "┃\t\t\t\t\t\t\t┃\t\t\t\t\t\t\t┃\t\t\t\t┃" << endl;

        //displaying search results
        for (int i = 0; i < results.size(); i++) {
            for (int j = 1; j < accounts.size(); j++) {
                if (results[i].email == accounts[j].email) {
                    cout << "┃\t\t    [" << j << "] " << accounts[i].username << "    \t";

                    if (accounts[i].username.length() <= 10) cout << "\t\t";
                    else if (accounts[i].username.length() <= 19 && i < 10) cout << "\t";
                    else if (accounts[i].username.length() <= 18 && i >= 10) cout << "\t";
                    
                    cout << "┃\t\t" << accounts[i].email << "\t\t┃\t      ";

                    if (accounts[i].status) cout << "Banned  \t\t┃" << endl;
                    else cout << "Active  \t\t┃" << endl;

                    break;
                }
            }
        }

        cout << "┃\t\t\t\t\t\t\t┃\t\t\t\t\t\t\t┃\t\t\t\t┃" << endl;
        cout << "┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┻━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┻━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛" << endl;

    } else {
        cout << "┣━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┻━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┻━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫" << endl;
        cout << "┃\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t┃" << endl;
        cout << "┃\t\t\t\t\t\t\t\tNo result for: " << searchTerm << "\t\t\t\t\t\t\t\t┃" << endl;
        cout << "┃\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t┃" << endl;
        cout << "┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛" << endl;
    }

    cout << "\t\t☛ Input [action]: ";
    cin >> choose;

    cout << "━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━" << endl;

    if (checkInput(choose) == "alpha" && choose.length() == 1) {
        transform(choose.begin(), choose.end(), choose.begin(), ::tolower);

        menuAdmin(choose);
        searchAcc();

    } else if (checkInput(choose) == "number" && accounts.size() > stoi(choose) && stoi(choose) < 1) {
        editAccount(stoi(choose));

    } else {
        invalidInput();
        searchAcc();
    }    
}

void viewAccounts() {
    string choose;

    displayMenu();

    cout << "┃\t\t\t\t\t\t\t\tLIST OF ACCOUNTS\t\t\t\t\t\t\t\t┃" << endl;
    cout << "┣━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┳━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┳━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫" << endl;
    cout << "┃\t\t\tUsername\t\t\t┃\t\t\t    Email    \t\t\t┃\t      Status  \t\t┃" << endl;

    if (accounts.size() > 1) {
        cout << "┣━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━╋━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━╋━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫" << endl;
        cout << "┃\t\t\t\t\t\t\t┃\t\t\t\t\t\t\t┃\t\t\t\t┃" << endl;

        //displaying all accounts
        for (int i = 1; i < accounts.size(); i++) {
            cout << "┃\t\t    [" << i << "] " << accounts[i].username << "    \t";

            if (accounts[i].username.length() <= 10) cout << "\t\t";
            else if (accounts[i].username.length() <= 19 && i < 10) cout << "\t";
            else if (accounts[i].username.length() <= 18 && i >= 10) cout << "\t";
            
            cout << "┃\t\t" << accounts[i].email << "\t\t┃\t      ";

            if (accounts[i].status) cout << "Banned  \t\t┃" << endl;
            else cout << "Active  \t\t┃" << endl;
        }

        cout << "┃\t\t\t\t\t\t\t┃\t\t\t\t\t\t\t┃\t\t\t\t┃" << endl;
        cout << "┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┻━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┻━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛" << endl;

    } else {
        cout << "┣━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┻━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┻━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫" << endl;
        cout << "┃\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t┃" << endl;
        cout << "┃\t\t\t\t\t\t\t\tNo registered account yet!\t\t\t\t\t\t\t\t┃" << endl;
        cout << "┃\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t┃" << endl;
        cout << "┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛" << endl;
    }

    cout << "\t\t✎ To edit account, choose a number.\t\t\t\t" << endl;
    cout << "\t\t☛ Input [action]: ";
    cin >> choose;

    if (checkInput(choose) == "alpha" && choose.length() == 1) {
        transform(choose.begin(), choose.end(), choose.begin(), ::tolower);

        menuAdmin(choose);
        viewAccounts();

    } else if (checkInput(choose) == "number" && stoi(choose) < accounts.size() && stoi(choose) > 0) {

        editAccount(stoi(choose));

    } else {
        invalidInput();
        viewAccounts();
    }
}

void editAccount(int accNumber) {
    string choose, temp;
    int choose1;

    displayMenu();

    cout << endl;
    cout << "\t\t\t\t\tEditing account with an email: " << accounts[accNumber].email << endl << endl;
    cout << "\t\t\t\t\t\t\t[1] Username: " << accounts[accNumber].username << endl;
    cout << "\t\t\t\t\t\t\t[2] Password: " << accounts[accNumber].password << endl;
    cout << "\t\t\t\t\t\t\t[3]   Status: ";

    if (accounts[accNumber].status) cout << "Banned" << endl;
    else cout << "Active" << endl; 

    cout << "\t\t\t\t\t\t\t[4]  Petcoin: " << accounts[accNumber].money;

    if (accounts[accNumber].notApproved != 0) cout << "\t\tNeed approval: " << accounts[accNumber].notApproved << " Petcoin" << endl << endl;
    else cout << endl << endl;

    cout << "┣━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫" << endl;

    cout << "\t\t☛ Input [action]: ";
    cin >> choose;

    cout << "━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━" << endl;

    if (checkInput(choose) == "alpha" && choose.length() == 1) {
        transform(choose.begin(), choose.end(), choose.begin(), ::tolower);

        menuAdmin(choose);
        editAccount(accNumber);

    } else if (checkInput(choose) == "number" && stoi(choose) <= 4 && stoi(choose) >= 1) {
        if (accounts[accNumber].notApproved == 0) {
            cout << "\t\tThere is no Petcoin in queue for approval.";
            Sleep(3000);

            editAccount(accNumber);
        }

        displayMenu();

        switch(stoi(choose)) {
            case 1:
                cout << "┃\t\t\t\t\t\t\t\tEDIT USERNAME\t\t\t\t\t\t\t\t\t┃" << endl;
                cout << "┣━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫" << endl << endl;

                cout << "\t\t\t\t\t\t\tOld username: " << accounts[accNumber].username << endl;
                cout << "\t\t\t\t\t\t  Enter new username: ";

                cin >> temp;
                break;

            case 2:
                cout << "┃\t\t\t\t\t\t\t\tEDIT PASSWORD\t\t\t\t\t\t\t\t\t┃" << endl;
                cout << "┣━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫" << endl << endl;

                cout << "\t\t\t\t\t\t\tOld password: " << accounts[accNumber].password << endl;
                cout << "\t\t\t\t\t\t  Enter new password: ";

                cin >> temp;
                break;

            case 3:
                cout << "┃\t\t\t\t\t\t\t\tEDIT STATUS\t\t\t\t\t\t\t\t\t┃" << endl;
                cout << "┣━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫" << endl << endl;
                
                if (accounts[accNumber].status) cout << "\t\t\t\t\t\t\tStatus: Banned ⟶ Active  \t\t\t\t" << endl;
                else cout << "\t\t\t\t\t\t\tStatus: Active ⟶ Banned  \t\t\t\t" << endl;

                break;

            case 4:
                
                cout << "┃\t\t\t\t\t\t\t\tNEED APPROVAL\t\t\t\t\t\t\t\t\t┃" << endl;
                cout << "┣━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫" << endl << endl;
                cout << "\t\t\t\t\t\t\t\tPetcoin: " << accounts[accNumber].notApproved << endl;

                break;

            default:
                invalidInput();
                
                cout << "\t\tCanceling process...";
                Sleep(2000);

                editAccount(accNumber);
                break;
        }

        cout << endl;
        cout << "┣━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┳━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫" << endl;
        
        if (stoi(choose) == 4) cout << "┃\t\t\t\t[1] Approved\t\t\t\t┃\t\t\t\t[0] Not Approved\t\t\t\t┃" << endl;
        else cout << "┃\t\t\t\t[1] Save\t\t\t\t┃\t\t\t\t[0] Cancel\t\t\t\t┃" << endl;

        cout << "┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┻━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛" << endl;

        cout << "\t\t☛ Input action: ";
        cin >> choose1;

        cout << "━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━" << endl;

        //check if string is inputted in an int variable
        if (cin.fail()) {
            invalidInput();
            
            cout << "\t\tCanceling process...";
            Sleep(2000);

            cin.clear();//clear input
            cin.ignore(LONG_MAX, '\n');//ignore any error

            viewAccounts();

        } else {
            switch(choose1) {
                case 0:
                    if (stoi(choose) == 4) accounts[accNumber].notApproved = 0;
                    else {
                        cout << "\t\tCanceling process...";
                        Sleep(3000);

                        viewAccounts();
                    }
                    break;
                
                case 1:
                    switch(stoi(choose)) {
                        case 1: // edit user's username
                            accounts[accNumber].username = temp;
                            break;

                        case 2: // edit user's password
                            accounts[accNumber].password = temp;
                            break;

                        case 3: // edit user's status
                            if (accounts[accNumber].status) accounts[accNumber].status = false;
                            else accounts[accNumber].status = true;
                            break;

                        case 4: // edit user's status
                            accounts[accNumber].money += accounts[accNumber].notApproved;
                            accounts[accNumber].notApproved = 0;
                            break;
                    }

                    cout << "\t\tApplying changes...";
                    Sleep(3000);

                    viewAccounts();
                    break;
                
                default:
                    invalidInput();

                    cout << "\t\tCanceling process...";
                    Sleep(2000);

                    viewAccounts();
                    break;
            }
        }

    } else {
        invalidInput();
        editAccount(accNumber);
    }
}

void viewInventory() {
    string choose;

    displayMenu();

    cout << "|\t\t\t\t\t\t\t\tLIST OF PRODUCTS\t\t\t\t\t\t\t\t┃" << endl;
    cout << "┣━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┳━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┳━━━━━━━━━━━━━━━━━━━━━━━┳━━━━━━━━━━━━━━━━━━━━━━━┫" << endl;
    cout << "┃\t\t\tProduct Name\t\t\t┃\t\tCategory\t\t┃\t  Animal      \t┃\t  Price      \t┃" << endl;
    cout << "┣━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━╋━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━╋━━━━━━━━━━━━━━━━━━━━━━━╋━━━━━━━━━━━━━━━━━━━━━━━┫" << endl;
    cout << "┃\t\t\t\t\t\t\t┃\t\t\t\t\t┃\t\t\t┃\t\t\t┃" << endl;

    // displaying all products
    for (int i = 0; i < products.size(); ++i) {
        cout << "┃\t\t[" << i << "] " << products[i].name << "\t\t";

        if (products[i].name.length() <= 10) cout << "\t\t";
        else if (products[i].name.length() <= 19 && i < 10) cout << "\t";
        else if (products[i].name.length() <= 18 && i >= 10) cout << "\t";

        cout << "┃\t\t" << products[i].category;

        if (products[i].category == "Food") cout << "\t";

        cout << "\t\t┃\t   " << products[i].animal << "     \t┃\t  ₱ " << products[i].price << "      \t┃" << endl;
    }

    cout << "┃\t\t\t\t\t\t\t┃\t\t\t\t\t┃\t\t\t┃\t\t\t┃" << endl;
    cout << "┣━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┻━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┻━━━━━━━━━━━━━━━━━━━━━━━┻━━━━━━━━━━━━━━━━━━━━━━━┫" << endl;

    cout << "┃\t\t\t\t\t\t\t\t    [+] ADD PRODUCT    \t\t\t\t\t\t\t\t┃" << endl;
    cout << "┣━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫" << endl;

    cout << "\t\t✎ To edit account, choose a number.\t\t\t\t" << endl;
    cout << "\t\t☛ Input [action]: ";
    cin >> choose;

    cout << "┣━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫" << endl;

    if (choose == "+") {
        addItem();
    
    } else if (checkInput(choose) == "alpha" && choose.length() == 1) {
        transform(choose.begin(), choose.end(), choose.begin(), ::tolower);

        menuAdmin(choose);
        viewInventory();

    } else if (checkInput(choose) == "number" && stoi(choose) < products.size() && stoi(choose) <= 0) {
        editItem(stoi(choose));

    } else {
        invalidInput();
        viewInventory();
    }
}

void addItem() {
    string name, category, animal, description;
    double price;
    int choose, temp, stock;

    displayMenu();

    cout << "┃\t\t\t\t\t\t\t\tADD NEW PRODUCT\t\t\t\t\t\t\t\t\t┃" << endl;
    cout << "┣━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫" << endl << endl;
    cout << "\t\t\t\t\t  [action] Name: ";
    cin >> name;

    if (checkInput(name) == "alpha" && name.length() == 1) {
        transform(name.begin(), name.end(), name.begin(), ::tolower);

        menuAdmin(name);
        viewInventory();

    } else if (name.length() == 1) {
        cout << "┣━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫" << endl;
        invalidInput();
            
        cout << "\t\tCanceling process...";
        viewInventory();
    }

    cout << "\t⟶   [1] Food   [2] Equipment   [3] Medicine  ⟵" << endl;
    cout << "\t\t\t\t\tChoose category: ";
    cin >> temp;

    if (cin.fail() || temp > 3 || temp <= 0) {
        cout << "┣━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫" << endl;
        invalidInput();
            
        cout << "\t\tCanceling process...";
        Sleep(2000);

        cin.clear(); // clear input
        cin.ignore(LONG_MAX, '\n'); // ignore any error

        viewInventory();

    } else if (temp > 3 || temp <= 0) {
        cout << "┣━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫" << endl;
        invalidInput();
            
        cout << "\t\tCanceling process...";
        viewInventory();

    } else {
        switch(temp) {
            case 1:
                category = "Food";
                break;
            case 2:
                category = "Equipment";
                break;
            case 3:
                category = "Medicine";
                break;
        }
    }

    cout << "\t⟶   [1] Dog   [2] Cat   [3] Fish   [4] Bird  ⟵" << endl;
    cout << "\t\t\t\t\t  Choose animal: ";
    cin >> animal;

    if (cin.fail()) {
        cout << "┣━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫" << endl;
        invalidInput();
            
        cout << "\t\tCanceling process...";
        Sleep(2000);

        cin.clear(); // clear input
        cin.ignore(LONG_MAX, '\n'); // ignore any error

        viewInventory();

    } else if (temp > 4 || temp <= 0) {
        cout << "┣━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫" << endl;
        invalidInput();
            
        cout << "\t\tCanceling process...";
        Sleep(2000);

        viewInventory();

    } else {
        switch(temp) {
            case 1:
                category = "Dog";
                break;
            case 2:
                category = "Cat";
                break;
            case 3:
                category = "Fish";
                break;
            case 4:
                category = "Bird";
                break;
        }
    }

    cin.clear(); // clear input
    cin.ignore(LONG_MAX, '\n'); // ignore any error

    cout << "\t\t\t\t\t    Description: ";
    getline(cin, description);

    cout << "\t\t\t\t\t\t  Price: ";
    cin >> price;

    if (cin.fail()) {
        cout << "┣━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫" << endl;
        invalidInput();
            
        cout << "\t\tCanceling process...";
        Sleep(2000);

        cin.clear(); // clear input
        cin.ignore(LONG_MAX, '\n'); // ignore any error

        viewInventory();
    } else if (price <= 0) {
        cout << "┣━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫" << endl;
        cout << "\tPrice must not less than 1.";
        Sleep(3000);
            
        cout << "\t\tCanceling process...";
        Sleep(2000);

        viewInventory();

    } 

    cout << "\t\t\t\t\t\t  Stock: ";
    cin >> stock;

    if (cin.fail()) {
        invalidInput();
            
        cout << "\t\tCanceling process...";
        Sleep(2000);

        cin.clear(); // clear input
        cin.ignore(LONG_MAX, '\n'); // ignore any error

        viewInventory();
    } else if (stock <= 0) {
        cout << "┣━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫" << endl;
        cout << "\t\tStock must not less than 1.";
        Sleep(3000);
        
        cout << "\t\tCanceling process...";
        Sleep(2000);

        viewInventory();

    } 

    cout << endl;
    cout << "┣━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┳━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫" << endl;
    cout << "┃\t\t\t\t[1] Save\t\t\t\t┃\t\t\t\t[0] Cancel\t\t\t\t┃" << endl;
    cout << "┣━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┻━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫" << endl;
    
    cout << "\t\t☛ Input action: ";
    cin >> choose;

    cout << "┣━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫" << endl;

    if (cin.fail()) {
        invalidInput();
            
        cout << "\t\tCanceling process...";
        Sleep(2000);

        cin.clear(); // clear input
        cin.ignore(LONG_MAX, '\n'); // ignore any error

        viewInventory();

    } else {
        switch(choose) {
            case 0:
                cout << "\t\tCanceling process...";
                Sleep(3000);

                viewInventory();
                break;
                
            case 1: // adding product in the vector
                products.push_back({name, category, animal, description, price, stock, true});

                cout << "\t\tAdding product...";
                Sleep(3000);

                viewInventory();
                break;
                
            default:
                invalidInput();

                cout << "\t\tCanceling process...";
                Sleep(2000);

                viewInventory();
                break;
        }
    }
}

void editItem(int p_num) {
    string choose, temp;
    int choose1;

    displayMenu();

    cout << endl;
    cout << "\t\t\t\t\t\t\t[1] Product Name: " << products[p_num].name << endl;
    cout << "\t\t\t\t\t\t\t[2]    Category: " << products[p_num].category << endl;
    cout << "\t\t\t\t\t\t\t[3]      Animal: " << products[p_num].animal << endl;
    cout << "\t\t\t\t\t\t\t[4] Description: " << products[p_num].description << endl;
    cout << "\t\t\t\t\t\t\t[5]       Price: ₱ " << products[p_num].price << endl;
    cout << "\t\t\t\t\t\t\t[6]       Stock: " << products[p_num].stock << " pieces" << endl;
    cout << "\t\t\t\t\t\t\t[7]      Status: ";
    
    if (products[p_num].status) cout << "Displayed" << endl << endl;
    else cout << "Not Displayed" << endl << endl;

    cout << "┣━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫" << endl;

    cout << "\t\t☛ Input [action]: ";
    cin >> choose;

    cout << "┣━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫" << endl;

    if (checkInput(choose) == "alpha" && choose.length() == 1) {
        transform(choose.begin(), choose.end(), choose.begin(), ::tolower);

        menuAdmin(choose);
        viewInventory();

    } else if (checkInput(choose) == "number" && stoi(choose) <= 7 && stoi(choose) >= 1) {
        displayMenu();

        switch(stoi(choose)) {
            case 1:
                cout << "┃\t\t\t\t\t\t\t      EDIT PRODUCT NAME  \t\t\t\t\t\t\t\t┃" << endl;
                cout << "┣━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫" << endl << endl;

                cout << "\t\t\t\t\t\t\tOld product name: " << products[p_num].name << endl;
                cout << "\t\t\t\t\t\t  Enter new product name: ";
                cin >> temp;

                break;
                
            case 2:
                cout << "┃\t\t\t\t\t\t\t\tEDIT CATEGORY\t\t\t\t\t\t\t\t\t┃" << endl;
                cout << "┣━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫" << endl << endl;

                cout << "\t\t\t\t\t\t\tOld category: " << products[p_num].category << endl;
                cout << "\t\t\t\t\t\t⟶   [1] Food   [2] Equipment   [3] Medicine  ⟵" << endl;
                cout << "\t\t\t\t\t\t  Enter new category: ";
                cin >> temp;

                if (checkInput(temp) == "number") {
                    if (stoi(temp) > 3 || stoi(temp) <= 0) {
                        cout << "┣━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫" << endl;
                        invalidInput();
                                
                        cout << "\t\tCanceling process...";
                        viewInventory();

                    } else {
                        switch(stoi(temp)) {
                            case 1:
                                temp = "Food";
                                break;
                            case 2:
                                temp = "Equipment";
                                break;
                            case 3:
                                temp = "Medicine";
                                break;
                        }
                    }

                } else {
                    cout << "┣━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫" << endl;
                    invalidInput();
                                
                    cout << "\t\tCanceling process...";
                    Sleep(2000);

                    viewInventory();
                }

                break;

            case 3:
                cout << "┃\t\t\t\t\t\t\t\tEDIT ANIMAL\t\t\t\t\t\t\t\t\t┃" << endl;
                cout << "┣━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫" << endl << endl;

                cout << "\t\t\t\t\t\t\tOld animal: " << products[p_num].animal << endl;
                cout << "\t\t\t\t\t\t⟶   [1] Dog   [2] Cat   [3] Fish   [4] Bird  ⟵" << endl;
                cout << "\t\t\t\t\t\t  Enter new animal: ";
                cin >> temp;

                if (checkInput(temp) == "number") {
                    if (stoi(temp) > 4 || stoi(temp) <= 0) {
                        cout << "┣━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫" << endl;
                        invalidInput();
                                
                        cout << "\t\tCanceling process...";
                        Sleep(2000);

                        viewInventory();

                    } else {
                        switch(stoi(temp)) {
                            case 1:
                                temp = "Dog";
                                break;
                            case 2:
                                temp = "Cat";
                                break;
                            case 3:
                                temp = "Fish";
                                break;
                            case 4:
                                temp = "Bird";
                                break;
                        }
                    }

                } else {
                    cout << "┣━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫" << endl;
                    invalidInput();
                                
                    cout << "\t\tCanceling process...";
                    Sleep(2000);

                    viewInventory();
                }
                break;

            case 4:
                cout << "┃\t\t\t\t\t\t\t      EDIT DESCRIPTION  \t\t\t\t\t\t\t\t┃" << endl;
                cout << "┣━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫" << endl << endl;

                cout << "\t\t\t\t\t\t\tOld description: " << products[p_num].description << endl;
                cout << "\t\t\t\t\t\t  Enter new description: ";

                cin.clear(); // clear input
                cin.ignore(LONG_MAX, '\n'); // ignore any error
                getline(cin, temp);

                break;

            case 5:
                cout << "┃\t\t\t\t\t\t\t\tEDIT PRICE\t\t\t\t\t\t\t\t\t┃" << endl;
                cout << "┣━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫" << endl << endl;

                cout << "\t\t\t\t\t\t\tOld price: " << products[p_num].price << endl;
                cout << "\t\t\t\t\t\t  Enter new price: ";
                cin >> temp;

                if (checkInput(temp) == "number" && stoi(temp) <= 0) {
                    cout << "┣━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫" << endl;
                    cout << "\t\tPrice must not less than 1." << endl;
                    Sleep(3000);
                                
                    cout << "\t\tCanceling process...";
                    Sleep(2000);

                    viewInventory();

                } else {
                    cout << "┣━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫" << endl;
                    invalidInput();
                                
                    cout << "\t\tCanceling process...";
                    Sleep(2000);

                    viewInventory();
                }
                break;

            case 6:
                cout << "┃\t\t\t\t\t\t\t\tEDIT STOCK\t\t\t\t\t\t\t\t\t┃" << endl;
                cout << "┣━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫" << endl << endl;

                cout << "\t\t\t\t\t\t\tOld stock: " << products[p_num].stock << endl;
                cout << "\t\t\t\t\t\t  Enter new stock: ";
                cin >> temp;

                if (checkInput(temp) == "number" && stoi(temp) <= 0) {
                    cout << "┣━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫" << endl;
                    cout << "\t\tStock must not less than 1." << endl;
                    Sleep(3000);
                                
                    cout << "\t\tCanceling process...";
                    Sleep(2000);

                    viewInventory();

                } else {
                    cout << "┣━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫" << endl;
                    invalidInput();
                                
                    cout << "\t\tCanceling process...";
                    Sleep(2000);

                    viewInventory();
                }
                break;

            case 7:
                cout << "┃\t\t\t\t\t\t\t\tEDIT STATUS\t\t\t\t\t\t\t\t\t┃" << endl;
                cout << "┣━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫" << endl << endl;
                    
                if (products[p_num].status) cout << "\t\t\t\t\t\t\tStatus: Display ⟶   Not Display  \t\t\t\t";
                else cout << "\t\t\t\t\t\t\tStatus: Not Display ⟶   Display  \t\t\t\t";

                break;
        }

        cout << endl;
        cout << "┣━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┳━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫" << endl;
        cout << "┃\t\t\t\t[1] Save\t\t\t\t┃\t\t\t\t[0] Cancel\t\t\t\t┃" << endl;
        cout << "┣━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┻━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫" << endl;

        cout << "\t\t☛ Input action: ";
        cin >> choose1;

        cout << "┣━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫" << endl;

        if (cin.fail()) {
            invalidInput();
                
            cout << "\t\tCanceling process...";
            Sleep(2000);

            cin.clear(); // clear input
            cin.ignore(LONG_MAX, '\n'); // ignore any error

            viewInventory();

        } else {
            switch(stoi(choose)) {
                case 0:
                    cout << "\t\tCanceling process...";
                    Sleep(3000);

                    viewInventory();
                    break;
                
                case 1:
                    switch(stoi(choose)) {
                        case 1: // edit name of product
                            products[p_num].name = temp;
                            break;

                        case 2: // edit category of product
                            products[p_num].category = temp;
                            break;

                        case 3: // edit animal of product
                            products[p_num].animal = temp;
                            break;

                        case 4: // edit description of product
                            products[p_num].description = temp;
                            break;

                        case 5: // edit price of product
                            products[p_num].price = stod(temp);
                            break;

                        case 6: // edit stock of product
                            products[p_num].stock = stoi(temp);
                            break;

                        case 7: // edit status of product
                            if (products[p_num].status) products[p_num].status = false;
                            else products[p_num].status = true;
                            break;    
                    }

                    cout << "\t\tApplying changes...";
                    Sleep(3000);

                    viewInventory();
                    break;
                
                default:
                    invalidInput();

                    cout << "\t\tCanceling process...";
                    Sleep(2000);

                    viewInventory();
                    break;
            }
        }

    } else {
        invalidInput();
        viewInventory();
    }
}

void viewCheckouts() {
    string choose;

    displayMenu();

    cout << "|\t\t\t\t\tLIST OF CHECKOUTS\t\t\t\t\t|" << endl;
    cout << "+-----------------------------------------------------------------------------------------------+" << endl;

    // if (products.size() > 0) {
    //     for (int i = 0; i < products.size(); i++) {
    //         cout << "[" << i << "] " << products[i].name << endl;
    //     }

    // } else {
    //     cout << "No checkouts yet!" << endl;
    // }

    cout << "+-----------------------------------------------------------------------------------------------+" << endl;

    cout << "\t\t\t\t Input action: ";
    cin >> choose;
    
    menuAdmin(choose);
}

void menuCustomer(string choose) {

    if (choose == "h") {
        homeCustomer();

    } else if (choose == "s") {
        searchProducts();

    } else if (choose == "a") {
        if (!loginStatus) {
            cout << "┣━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫" << endl;
            cout << "\t\tNo account logged in yet, redirecting to LOGIN";

            login();
        }
        else accountProfile();

    } else if (choose == "c") {
        if (!loginStatus) {
            cout << "┣━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫" << endl;
            cout << "\t\tNo account logged in yet, redirecting to LOGIN";

            login();
        }
        else cart();

    } else if (choose == "f") {
        foods();

    } else if (choose == "q") {
        equipments();

    } else if (choose == "m") {
        medicine();

    } else {
        invalidInput();
    }
}

void homeCustomer() {
    string choose;
    srand(time(nullptr));
    set<int> selected;

    displayMenu();

    cout << "┃\t\t\t\t\t\t\t\t      HOME          \t\t\t\t\t\t\t\t┃" << endl;
    cout << "┣━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┳━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┳━━━━━━━━━━━━━━━━━━━━━━━┳━━━━━━━━━━━━━━━━━━━━━━━┫" << endl;
    cout << "┃\t\t\tProduct Name\t\t\t┃\t\tCategory\t\t┃\t  Animal      \t┃\t  Price      \t┃" << endl;
    cout << "┣━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━╋━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━╋━━━━━━━━━━━━━━━━━━━━━━━╋━━━━━━━━━━━━━━━━━━━━━━━┫" << endl;
    cout << "┃\t\t\t\t\t\t\t┃\t\t\t\t\t┃\t\t\t┃\t\t\t┃" << endl;

    for (int i = 0; i < 10; ++i) {
        int index = getRandomNumber(products);
        
        // check if the generated number has been already selected
        while (selected.count(index) > 0) {
            index = getRandomNumber(products);
        }

        // inserting random number in set
        selected.insert(index);

        // displaying products base on numbers in set
        if (products[index].status) {
            cout << "┃\t\t[" << index << "] " << products[index].name << "\t\t";

            if (products[index].name.length() <= 10) cout << "\t\t";
            else if (products[index].name.length() <= 19 && index < 10) cout << "\t";
            else if (products[index].name.length() <= 18 && index >= 10) cout << "\t";

            cout << "┃\t\t" << products[index].category;

            if (products[index].category == "Food") cout << "\t";

            cout << "\t\t┃\t   " << products[index].animal << "     \t┃\t  ₱ " << products[index].price << "      \t┃" << endl;
        }
    }

    cout << "┃\t\t\t\t\t\t\t┃\t\t\t\t\t┃\t\t\t┃\t\t\t┃" << endl;
    cout << "┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┻━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┻━━━━━━━━━━━━━━━━━━━━━━━┻━━━━━━━━━━━━━━━━━━━━━━━┛" << endl;

    cout << "\t\t☛ Input [action]: ";
    cin >> choose;

    cout << "━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━" << endl;

    if (checkInput(choose) == "alpha" && choose.length() == 1) {
        transform(choose.begin(), choose.end(), choose.begin(), ::tolower);

        menuCustomer(choose);
        homeCustomer();

    } else if (checkInput(choose) == "number" && products.size() > stoi(choose) && stoi(choose) >= 0) {
        viewItem(stoi(choose));

    } else {
        invalidInput();
        homeCustomer();
    }
}

void foods() {
    string choose;

    displayMenu();

    cout << "┃\t\t\t\t\t\t\t\t      FOODS         \t\t\t\t\t\t\t\t┃" << endl;
    cout << "┣━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┳━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┳━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫" << endl;
    cout << "┃\t\t\t\tProduct Name\t\t\t\t┃\t\t  Animal      \t\t┃\t      Price  \t\t┃" << endl;
    cout << "┣━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━╋━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━╋━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫" << endl;
    cout << "┃\t\t\t\t\t\t\t\t\t┃\t\t\t\t\t┃\t\t\t\t┃" << endl;

    // display products on category food
    for (int i = 0; i < products.size(); i++) {
        if (products[i].category == "Food" && products[i].status) {
            cout << "┃\t\t\t[" << i << "] " << products[i].name << "\t\t\t";

            if (products[i].name.length() <= 10) cout << "\t\t";
            else if (products[i].name.length() <= 19 && i < 10) cout << "\t";
            else if (products[i].name.length() <= 18 && i >= 10) cout << "\t";

            cout << "┃\t\t   " << products[i].animal << "     \t\t┃\t      ₱ " << products[i].price << "  \t\t┃" << endl;
        }
    }

    cout << "┃\t\t\t\t\t\t\t\t\t┃\t\t\t\t\t┃\t\t\t\t┃" << endl;
    cout << "┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┻━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┻━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛" << endl;

    cout << "\t\t☛ Input [action]: ";
    cin >> choose; 

    cout << "━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━" << endl;

    if (checkInput(choose) == "alpha" && choose.length() == 1) {
        transform(choose.begin(), choose.end(), choose.begin(), ::tolower);

        menuCustomer(choose);
        foods();

    } else if (checkInput(choose) == "number" && products.size() > stoi(choose) && stoi(choose) >= 0 && products[stoi(choose)].category == "Food") {
        viewItem(stoi(choose));

    } else {
        invalidInput();
        foods();
    }
}

void equipments() {
    string choose;

    displayMenu();
    
    cout << "┃\t\t\t\t\t\t\t\t   EQUIPMENTS       \t\t\t\t\t\t\t\t┃" << endl;
    cout << "┣━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┳━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┳━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫" << endl;
    cout << "┃\t\t\t\tProduct Name\t\t\t\t┃\t\t  Animal      \t\t┃\t      Price  \t\t┃" << endl;
    cout << "┣━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━╋━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━╋━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫" << endl;
    cout << "┃\t\t\t\t\t\t\t\t\t┃\t\t\t\t\t┃\t\t\t\t┃" << endl;

    // display products on category equipment
    for (int i = 0; i < products.size(); i++) {
        if (products[i].category == "Equipment" && products[i].status) {
            cout << "┃\t\t\t[" << i << "] " << products[i].name << "\t\t\t";

            if (products[i].name.length() <= 10) cout << "\t\t";
            else if (products[i].name.length() <= 19 && i < 10) cout << "\t";
            else if (products[i].name.length() <= 18 && i >= 10) cout << "\t";

            cout << "┃\t\t   " << products[i].animal << "     \t\t┃\t      ₱ " << products[i].price << "  \t\t┃" << endl;
        }
    }

    cout << "┃\t\t\t\t\t\t\t\t\t┃\t\t\t\t\t┃\t\t\t\t┃" << endl;
    cout << "┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┻━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┻━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛" << endl;

    cout << "\t\t☛ Input [action]: ";
    cin >> choose; 

    cout << "━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━" << endl;

    if (checkInput(choose) == "alpha" && choose.length() == 1) {
        transform(choose.begin(), choose.end(), choose.begin(), ::tolower);

        menuCustomer(choose);
        equipments();

    } else if (checkInput(choose) == "number" && products.size() > stoi(choose) && stoi(choose) >= 0 && products[stoi(choose)].category == "Equipment") {
        viewItem(stoi(choose));

    } else {
        invalidInput();
        equipments();
    }
}

void medicine() {
    string choose;

    displayMenu();

    cout << "┃\t\t\t\t\t\t\t\t     MEDICINE         \t\t\t\t\t\t\t\t┃" << endl;
    cout << "┣━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┳━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┳━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫" << endl;
    cout << "┃\t\t\t\tProduct Name\t\t\t\t┃\t\t  Animal      \t\t┃\t      Price  \t\t┃" << endl;
    cout << "┣━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━╋━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━╋━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫" << endl;
    cout << "┃\t\t\t\t\t\t\t\t\t┃\t\t\t\t\t┃\t\t\t\t┃" << endl;

    // display products on category medicine
    for (int i = 0; i < products.size(); i++) {
        if (products[i].category == "Medicine" && products[i].status) {
            cout << "┃\t\t\t[" << i << "] " << products[i].name << "\t\t\t";

            if (products[i].name.length() <= 10) cout << "\t\t";
            else if (products[i].name.length() <= 19 && i < 10) cout << "\t";
            else if (products[i].name.length() <= 18 && i >= 10) cout << "\t";

            cout << "┃\t\t   " << products[i].animal << "     \t\t┃\t      ₱ " << products[i].price << "  \t\t┃" << endl;
        }
    }

    cout << "┃\t\t\t\t\t\t\t\t\t┃\t\t\t\t\t┃\t\t\t\t┃" << endl;
    cout << "┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┻━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┻━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛" << endl;

    cout << "\t\t\t\t Input action: ";
    cin >> choose; 

    cout << "━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━" << endl;

    if (checkInput(choose) == "alpha" && choose.length() == 1) {
        transform(choose.begin(), choose.end(), choose.begin(), ::tolower);
        
        menuCustomer(choose);
        medicine();

    } else if (checkInput(choose) == "number" && products.size() > stoi(choose) && stoi(choose) >= 0 && products[stoi(choose)].category == "Medicine") {
        viewItem(stoi(choose));

    } else {
        invalidInput();
        medicine();
    }
}

void viewItem(int p_num) {
    string choose;
    int quantity;

    displayMenu();

    cout << endl;
    cout << "\t\t\t\t\t\t\tProduct Name: " << products[p_num].name << endl;
    cout << "\t\t\t\t\t\t\t    Category: " << products[p_num].category << endl;
    cout << "\t\t\t\t\t\t\t      Animal: " << products[p_num].animal << endl;
    cout << "\t\t\t\t\t\t\t Description: " << products[p_num].description << endl;
    cout << "\t\t\t\t\t\t\t       Price: ₱ " << products[p_num].price << endl;
    cout << "\t\t\t\t\t\t\t       Stock: " << products[p_num].stock << " pieces" << endl << endl;

    cout << "\t\t\t\t\t\t   [action] Quantity: ";
    cin >> choose; 

    cout << endl;

    if (checkInput(choose) == "alpha" && choose.length() == 1) {
        menuCustomer(choose);
        viewItem(p_num);

    } else if (checkInput(choose) == "number") {
        if (stoi(choose) > 0 && products[p_num].stock >= stoi(choose)) {
            quantity = stoi(choose);

            cout << "┣━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┳━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫" << endl;
            cout << "┃\t\t\t\t[T] Add to Cart\t\t\t\t┃\t\t\t\t[B] Buy Now\t\t\t\t┃" << endl;
            cout << "┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┻━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛" << endl;

            cout << "\t\t☛ Input [action]: ";
            cin >> choose;

            cout << "━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━" << endl;

            if (checkInput(choose) == "alpha" && choose.length() == 1) {
                transform(choose.begin(), choose.end(), choose.begin(), ::tolower);

                if (loginStatus) {
                    if (choose == "t") {
                        // check if user has the product in cart
                        auto it = find_if(carts.begin(), carts.end(), [&](const Cart& c) {
                            return c.email == loginEmail && c.product == p_num;
                        });

                        // system will attempt to add quantity to existing product in cart
                        if (it != carts.end()) { 
                            for(int i = 0; i < carts.size(); i++) {
                                if(carts[i].email == loginEmail && carts[i].product == p_num) {
                                    // user cannot add more when quantity in cart and new quantity added is more than stock of product
                                    if (carts[i].quantity + quantity > products[p_num].stock) cout << "Cannot add more because of limited stock, please try again." << endl;
                                    else { // user added quantity for the product in cart
                                        carts[i].quantity += quantity;

                                        cout << "\t\tProduct: " << products[p_num].name << " is already in the cart, and " << quantity << " more is added.";
                                    }
                                    break;
                                }
                            }
                            
                        } else { // user add product in cart if not exist
                            carts.push_back({loginEmail, p_num, quantity, false});

                            cout << "\t\tProduct: " << products[p_num].name << " is added in your cart.";
                        }

                        Sleep(3000);

                        cart();

                    } else if (choose == "b") {
                        // add push_back for checkout
                        checkout();

                    } else {
                        menuCustomer(choose);
                        viewItem(p_num);
                    }

                } else {
                    login();
                }

            } else {
                cout << "━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━" << endl;
                invalidInput();
                viewItem(p_num);
            }

        } else {
            cout << "━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━" << endl;
            invalidInput();

            cout << "\t\tQuantity must not less than 0 or higher than stock number!";
            Sleep(2000);

            viewItem(p_num);
        }

    } else {
        invalidInput();
        viewItem(p_num);
    }
}

void cart() {
    string choose;
    int p_count = 0, count = 0, check_count = 0;
    double total = 0;

    displayMenu();

    cout << "┃\t\t\t\t\t\t\t\t      Cart        \t\t\t\t\t\t\t\t┃" << endl;
    cout << "┣━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┳━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┳━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫" << endl;
    cout << "┃\t\t\t\tProduct Name\t\t\t\t┃\t\t  Price      \t\t┃\t    Quantity  \t\t┃" << endl;
    
    // check if user has any product in cart
    auto it = find_if(carts.begin(), carts.end(), [&](const Cart& c) {
        return c.email == loginEmail;
    });

    if (it != carts.end()) {
    
        cout << "┣━━━━━━━┳━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━╋━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━╋━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫" << endl;
        cout << "┃\t┃\t\t\t\t\t\t\t\t┃\t\t\t\t\t┃\t\t\t\t┃" << endl;

        // counter for number of product in user's cart
        for (int j = 0; j < carts.size(); j++) {
            if (carts[j].email == loginEmail) p_count++;
        }

        // display user's product in cart
        for (int i = 0; i < carts.size(); i++) {
            if (carts[i].email == loginEmail) {

                int p_num = carts[i].product;

                if (!carts[i].status) cout << "┃   ☐";
                else {
                    cout << "┃  ✅";
                    check_count++;
                    total += (products[p_num].price * carts[i].quantity);
                }

                cout << "   ┃\t\t[" << p_num << "] " << products[p_num].name << "\t\t\t";

                if (products[p_num].name.length() <= 10) cout << "\t\t";
                else if (products[p_num].name.length() <= 19 && p_num < 10) cout << "\t";
                else if (products[p_num].name.length() <= 18 && p_num >= 10) cout << "\t";

                cout << "┃\t\t   ₱ " << products[p_num].price << "     \t\t┃\t       " << carts[i].quantity << "  \t\t┃" << endl;

                string details = products[p_num].animal + "\'s " + products[p_num].category;

                cout << "┃       ┃\t\t  ✱  " << details << "     \t\t";

                if (details.length() <= 10) cout << "\t\t";
                else if (details.length() <= 18 && p_num >= 10) cout << "\t";

                cout << "┃\t\t\t\t\t┃\t\t\t\t┃" << endl;
                
                // increment for separation line
                count++;
                
                // separation for multiple product in cart
                if (count > 0 && p_count != count) {
                    cout << "┃\t┃\t\t\t\t\t\t\t\t┃\t\t\t\t\t┃\t\t\t\t┃" << endl;
                    cout << "┣━━━━━━━╋━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━╋━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━╋━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫" << endl;
                    cout << "┃\t┃\t\t\t\t\t\t\t\t┃\t\t\t\t\t┃\t\t\t\t┃" << endl;
                }
            }
        }
    
        cout << "┃\t┃\t\t\t\t\t\t\t\t┃\t\t\t\t\t┃\t\t\t\t┃" << endl;
        
        if (check_count == 0) cout << "┗━━━━━━━┻━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┻━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┻━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛" << endl;
        else {
            cout << "┣━━━━━━━┻━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┻━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━╋━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫" << endl;
            cout << "┃\t\t\t\t[O] Checkout\t\t\t\t\t\t\tTotal:\t\t┃\t     ₱ " << total << "  \t\t┃" << endl;
            cout << "┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┻━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛" << endl;
        }

        cout << "\t\t✎ To de/select, edit or delete product in cart, choose the product's number." << endl;

    } else {
        cout << "┣━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┻━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┻━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫" << endl;
        cout << "┃\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t┃" << endl;
        cout << "┃\t\t\t\t\t\t\t\tNo product in cart yet!\t\t\t\t\t\t\t\t┃" << endl;
        cout << "┃\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t┃" << endl;
        cout << "┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┻━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛" << endl;
    }

    cout << "\t\t☛ Input [action]: ";
    cin >> choose; 
    
    if (checkInput(choose) == "alpha" && choose.length() == 1) {
        transform(choose.begin(), choose.end(), choose.begin(), ::tolower);

        if (choose == "o") {
            checkout();
            
        } else {
            menuCustomer(choose);
            cart();
        }
        
    } else if (checkInput(choose) == "number" && products.size() > stoi(choose) && stoi(choose) >= 0) {
        // check if user has the product in cart
        it = find_if(carts.begin(), carts.end(), [&](const Cart& c) {
            return c.email == loginEmail && c.product == stoi(choose);
        });

        if (it != carts.end()) menuCart(stoi(choose));
        else {
            cout << "━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━" << endl;
            invalidInput();

            cout << "\t\tNo product number exist in your cart";
            Sleep(2000);

            cart();
        }

    } else {
        cout << "━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━" << endl;
        invalidInput();
        cart();
    }
}

void menuCart(int p_num) {
    string choose;
    int quantity;

    cout << "┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┳━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┳━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓" << endl;
    cout << "┃           [O] De/Select for Checkout          ┃                  [D] Delete                   ┃                   [E] Edit                    ┃" << endl;
    cout << "┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┻━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┻━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛" << endl;

    cout << "\t\t☛ Input action: ";
    cin >> choose; 

    cout << "━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━" << endl;

    if (choose == "o") { //select or deselect product for checkout
        for(int i = 0; i < carts.size(); i++) {
            if(carts[i].email == loginEmail && carts[i].product == p_num) {
                cout << "\t\tProduct: " << products[p_num].name;

                if (carts[i].status) {
                    carts[i].status = false;
                    cout << " is deselected for checkout." << endl;
                } else {
                    carts[i].status = true;
                    cout << " is selected for checkout." << endl;
                }
                break;
            }
        }

    } else if (choose == "d") { // delete product in cart
        carts.erase(remove_if(carts.begin(), carts.end(), [&](const Cart& c) {
            return c.email == loginEmail && c.product == p_num;
        }), carts.end());

        cout << "Product: " << products[p_num].name << " is deleted in your cart.";

    } else if (choose == "e") { // edit quantity for the product in cart
        for(int i = 0; i < carts.size(); i++) {
            if(carts[i].email == loginEmail && carts[i].product == p_num) {
                cout << "\t\t\t\t\t\t\tOld quantity: " << carts[i].quantity << endl;
                cout << "\t\t\t\t\t\t  Enter new quantity: ";
                cin >> quantity;

                cout << "━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━" << endl;
                
                if (quantity > products[p_num].stock) cout << "Cannot edit quantity because of limited stock, please try again." << endl;
                else { // user edit quantity for the product
                    carts[i].quantity = quantity;

                    cout << "\t\tEditing product successful.";
                }
                break;
            }
        }
    } else {
        invalidInput();
    }

    Sleep(2000);
    cart();
}

void checkout() {
    displayMenu();

    cout << "checkout"; 
}

void invalidInput() {
    cout << "\t\tInvalid input, please try again" << endl;
    Sleep(3000);
}

string checkInput(string choose) {
    bool only_alpha = false, only_digit = false;

    for (char c : choose) {
        if (isalpha(c)) only_alpha = true;  // the character is not alphabet
        else if (isdigit(c)) only_digit = true;  // the character is not a digit
    }

    if (only_alpha) return "alpha";
    else if (only_digit) return "number";

    return "invalid";
}

// generate random number base on count of product
int getRandomNumber(const vector<Product>& vec) {
    return rand() % vec.size();
}

// check if searchTerm is in any searchable lists
bool contains(const string& str, const string& searchTerm) {
    return str.find(searchTerm) != string::npos;
}

template <typename T> // template for struct
typename enable_if<is_same<T, Product>::value, vector<T>>::type // setting template to struct Product
search(const vector<T>& items, const string& SearchTerm) {
    vector<T> results;

    // convert the search term to lower case
    string lowerCaseSearchTerm = SearchTerm;
    transform(lowerCaseSearchTerm.begin(), lowerCaseSearchTerm.end(), lowerCaseSearchTerm.begin(), ::tolower);
        
    for (const auto& product : items) {

        // convert the products name, category, animals, and description to lower case
        string lowerCaseName = product.name;
        transform(lowerCaseName.begin(), lowerCaseName.end(), lowerCaseName.begin(), ::tolower);
        string lowerCaseCategory = product.category;
        transform(lowerCaseCategory.begin(), lowerCaseCategory.end(), lowerCaseCategory.begin(), ::tolower);
        string lowerCaseAnimal = product.animal;
        transform(lowerCaseAnimal.begin(), lowerCaseAnimal.end(), lowerCaseAnimal.begin(), ::tolower);
        string lowerCaseDescription = product.description;
        transform(lowerCaseDescription.begin(), lowerCaseDescription.end(), lowerCaseDescription.begin(), ::tolower);

        // search the lower case version of the product  name, category,animals, and description
        if (contains(lowerCaseName, lowerCaseSearchTerm) ||
            contains(lowerCaseCategory, lowerCaseSearchTerm) ||
            contains(lowerCaseAnimal, lowerCaseSearchTerm) ||
            contains(lowerCaseDescription, lowerCaseSearchTerm)) {
            results.push_back(product);
        }
    }

    return results;
}

template <typename T> // template for struct
typename enable_if<is_same<T, Account>::value, vector<T>>::type // setting template to struct Account
search(const vector<T>& items, const string& SearchTerm) {
    vector<T> results;

    // convert the search term to lower case
    string lowerCaseSearchTerm = SearchTerm;
    transform(lowerCaseSearchTerm.begin(), lowerCaseSearchTerm.end(), lowerCaseSearchTerm.begin(), ::tolower);
        
    for (const auto& account : items) {

        // ccnvert the accounts username, email and status to lower case
        string lowerCaseUsername = account.username;
        transform(lowerCaseUsername.begin(), lowerCaseUsername.end(), lowerCaseUsername.begin(), ::tolower);
        string lowerCaseEmail = account.email;
        transform(lowerCaseEmail.begin(), lowerCaseEmail.end(), lowerCaseEmail.begin(), ::tolower);
        
        string lowerCaseStatus;

        if (account.status) lowerCaseStatus = "Banned";
        else lowerCaseStatus = "Active";
        
        transform(lowerCaseStatus.begin(), lowerCaseStatus.end(), lowerCaseStatus.begin(), ::tolower);

        // search the lower case version of the account username, email and status
        if (contains(lowerCaseUsername, lowerCaseSearchTerm) ||
            contains(lowerCaseEmail, lowerCaseSearchTerm) ||
            contains(lowerCaseStatus, lowerCaseSearchTerm)) {
            results.push_back(account);
        }
    }

    return results;
}
