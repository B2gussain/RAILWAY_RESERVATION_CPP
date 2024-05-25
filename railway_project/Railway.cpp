#include <bits/stdc++.h>
using namespace std;
class railway
{
private:
    int main_choice,
        admin_choice,
        user_choice,
        train_no,
        first_class_ticket_cost,
        second_class_ticket_cost,
        first_class_seat,
        second_class_seat,
        y_n_choice,
        Ticket_type_choice,
        no_seats,
        pay_amount;
    int F = 0;
    int S = 0;
    ifstream read;
    ofstream write;
    char train_name[20], passenger_age[3], bording_pt[20], destinatio_pt[20], passenger_name[20], date[15];
    string Email_id;
    string filename;
public:
    void main_menu();
    void admin();
    void add_train_details();
    void avaliable_trains();
    void display_passenger_details();
    void user();
    void reserve_ticket();
    void cancle_ticket();
    void deleteFile(const string &efilename);
};
// $$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$   MAIN MENU   $$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$
void railway::main_menu()
{
    system("cls");
    cout << "\n************************************************** RAILWAY RESERVATION **************************************************" << endl;
    cout << "Main Menu" << endl;
    cout << "1.Admin" << endl;
    cout << "2.User" << endl;
    cout << "3.Exit" << endl;
    cin >> main_choice;
    switch (main_choice)
    {
    case 1:
        admin();
        break;

    case 2:
        user();
        break;

    case 3:
        exit(0);
        break;

    default:
        cout << "Invalid Input";
        break;
    }
}
// $$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$   ADMIN MODE   $$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$
void railway::admin()
{
    system("cls");
    cout << "*********************************************** Admin Mode *************************************************************" << endl;
    cout << "1.Add New Train Details:" << endl;
    cout << "2.Available Trains:" << endl;
    cout << "3.Display Passenger Details" << endl;
    cout << "4.GO To Main Menu" << endl;
    cout << "5.Exit" << endl;
    cin >> admin_choice;
    switch (admin_choice)
    {
    case 1:
        system("cls");
        add_train_details();
        break;

    case 2:
        system("cls");
        avaliable_trains();
        cout << "Do you want to stay in Admin mode" << endl;
        cout << "1.YES" << endl;
        cout << "2.NO" << endl;
        cin >> y_n_choice;
        if (y_n_choice == 1)
        {
            system("cls");
            admin();
        }
        else
        {
            system("cls");
            main_menu();
        }
        break;

    case 3:
        system("cls");
        display_passenger_details();
        break;
    case 4:
        system("cls");
        main_menu();
        break;

    case 5:
        exit(0);
        break;

    default:
        system("cls");
        cout << "Invalid Input";
        admin();
        break;
    }
}
// $$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$   ADD TRAIN DETAILS   $$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$
void railway::add_train_details()
{
    system("cls");
    cout << "*********************************************** ADD TRAIN DETAILS ***********************************************************" << endl;
    write.open("avaliable_train.txt", ios::app);
    cout << "*Enter New Train Details" << endl;
    cout << "Train_NO:";
    cin >> train_no;
    cout << "Train_Name:";
    cin >> train_name;
    cout << "Bording_Point:";
    cin >> bording_pt;
    cout << "Destination_Point:";
    cin >> destinatio_pt;
    cout << "Number_of_First-Class_Tickets:";
    cin >> first_class_seat;
    cout << "First_Class_Ticket-Cost:";
    cin >> first_class_ticket_cost;
    cout << "Number_of_Second-Class_Tickets:";
    cin >> second_class_seat;
    cout << "Second_Class_Ticket-Cost:";
    cin >> second_class_ticket_cost;
    cout << "Date of Travel(dd-mm-yy):";
    cin >> date;
    cout << "\n**Details Added Successfully" << endl;

    // Write data to file
    write << train_no << endl;
    write << train_name << endl;
    write << bording_pt << endl;
    write << destinatio_pt << endl;
    write << first_class_seat << endl;
    write << first_class_ticket_cost << endl;
    write << second_class_seat << endl;
    write << second_class_ticket_cost << endl;
    write << date << endl;
    write.close();

    cout << "Do you want to stay in Admin mode" << endl;
    cout << "1.YES" << endl;
    cout << "2.NO" << endl;
    cin >> y_n_choice;
    if (y_n_choice == 1)
    {
        system("cls");
        admin();
    }
    else
    {
        system("cls");
        main_menu();
    }
}
// $$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$       AVALIABLE TRAINS       $$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$
void railway::avaliable_trains()
{
    system("cls");
    cout << "\n***************************************************** AVALIABLE TRAINS **********************************************************************" << endl;
    cout << "" << endl;
    read.open("avaliable_train.txt", ios::in);
    cout << "Train_No"
         << "\tTrain_Name"
         << "\tBord_Pt"
         << "\t\tDest_Pt"
         << "\t\tF_Cls_Seat"
         << "\tFCS_Price"
         << "\tS_Cls_Seat"
         << "\tSCS_Price"
         << "\tDate(dd-mm-yy)" << endl;
    cout << "" << endl;
    // Read and display train data until the end of file is reached
    while (read >> train_no >> train_name >> bording_pt >> destinatio_pt >> first_class_seat >> first_class_ticket_cost >> second_class_seat >> second_class_ticket_cost >> date)
    {
        cout << setw(4) << train_no << "\t     " << setw(13) << train_name << "   " << setw(10) << bording_pt << "\t     " << setw(10) << destinatio_pt << "\t\t  " << setw(6) << first_class_seat << setw(6) << "\t  " << first_class_ticket_cost << setw(8) << "\t  " << second_class_seat << setw(8) << "\t   " << second_class_ticket_cost << setw(10) << "" << date << endl;
        cout << "" << endl;
    }

    // Close the file
    read.close();
}
// $$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$   Display passenger Details   $$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$
void railway::display_passenger_details()
{
    int mticket_number;
    system("cls");
    cout << "*********************************************** DISPLAY PASSENGER DETAILS ***********************************************************" << endl;
    cout << "\n*****************  Passengers Details *****************" << endl;
    cout << "Enter Your Ticket Number: ";
    cin >> mticket_number;

    string passenger_ticket_no_detail = "Ticket Id Folder/" + to_string(mticket_number) + ".txt";
    if (filesystem::exists(passenger_ticket_no_detail))
    {
        read.open(passenger_ticket_no_detail, ios::in);
        if (read.is_open())
        {
            string line;
            while (getline(read, line))
            {
                cout << line << endl;
            }
            read.close();
        }
        else
        {
            cout << "Unable to Get details of the ticket" << endl;
        }
    }
    else
    {

        cout << "Ticket Not Found";
    }
    cout << "Do you want to stay in User mode" << endl;
    cout << "1.YES" << endl;
    cout << "2.NO" << endl;
    cout << "Enter Option : ";
    cin >> y_n_choice;
    if (y_n_choice == 1)
    {
        system("cls");
        user();
    }
    else
    {
        system("cls");
        main_menu();
    }
}
// $$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$   USER MODE   $$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$
void railway::user()
{
    system("cls");
    cout << "******************************************************** USER MODE ********************************************************************" << endl;
    cout << "1.Reserve Tickets" << endl;
    cout << "2.Cancle Tickets" << endl;
    cout << "3.Available Trains" << endl;
    cout << "4.Go To Main Menu" << endl;
    cout << "5.Exit" << endl;
    cin >> user_choice;
    switch (user_choice)
    {
    case 1:
        system("cls");
        reserve_ticket(); // reserve function call//
        cout << "Do you want to stay in User mode" << endl;
        cout << "1.YES" << endl;
        cout << "2.NO" << endl;
        cin >> y_n_choice;
        if (y_n_choice == 1)
        {
            system("cls");
            user();
        }
        else
        {
            system("cls");
            main_menu();
        }
        break;

    case 2:
        system("cls");
        cancle_ticket();

        break;
    case 3:
        system("cls");
        avaliable_trains();
        cout << "Do you want to stay in User mode" << endl;
        cout << "1.YES" << endl;
        cout << "2.NO" << endl;
        cin >> y_n_choice;
        if (y_n_choice == 1)
        {
            system("cls");
            user();
        }
        else
        {
            system("cls");
            main_menu();
        }
        break;
    case 4:
        system("cls");
        main_menu();
    case 5:
        system("cls");
        exit(0);

        break;
    default:
        cout << "Invalid Input";
        user();
        break;
    }
}
// $$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$    RESERVED TICKETS   $$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$
void railway::reserve_ticket()
{
    system("cls");
    avaliable_trains();
    srand(time(0));
    int temp_train_no,
        temp_first_class_ticket_cost,
        temp_second_class_seat,
        temp_first_class_seat,
        temp_second_class_ticket_cost;
    string passengerId;

    char temp_train_name[20], temp_bording_pt[20], temp_destinatio_pt[20], temp_date[15];
    cout << "*Reserve the Ticket" << endl;
    cout << "Enter Passenger ID :";
    cin >> passengerId;
    string passFolder = "passengers Id Folder/" + passengerId + ".txt";

    if (!filesystem::exists("passengers Id Folder"))
    {
        filesystem::create_directory("passengers Id Folder");
    }
    // Check if the file exists
    if (filesystem::exists(passFolder))
    {
        // File exists, open it in append mode
        ofstream file(passFolder, ios::app);
        if (file.is_open())
        {
            file.close();
        }
        else
        {
            cout << "Error " << endl;
        }
    }
    else
    {
        // File does not exist, create a new file
        ofstream file(passFolder);
    }

    if (!filesystem::exists("Ticket Id Folder"))
    {
        filesystem::create_directory("Ticket Id Folder");
    }
    int ticketNo = rand();
    string ticketFolder = "Ticket Id Folder/" + to_string(ticketNo).append(".txt");
    // Check if the file exists
    while (filesystem::exists(ticketFolder))
    {
        ticketNo = rand();
        ticketFolder = "Ticket Id Folder/" + to_string(ticketNo).append(".txt");
    }
    // Reset the file pointer to the beginning of the file
    read.open("avaliable_train.txt", ios::in);
    read.clear();            // Clear any error flags
    read.seekg(0, ios::beg); // Set the file pointer to the beginning
    cout << "Train_No:";
    cin >> train_no;
    bool found = false;
    if (read.is_open())
    {
        while (read >> temp_train_no >> temp_train_name >> temp_bording_pt >> temp_destinatio_pt >> temp_first_class_seat >> temp_first_class_ticket_cost >> temp_second_class_seat >> temp_second_class_ticket_cost >> temp_date)
        {
            if (train_no == temp_train_no)
            {
                found = true;
                cout << "Train_Name:" << temp_train_name
                     << "\nBording Point:" << temp_bording_pt
                     << "\nDestination Point:" << temp_destinatio_pt
                     << "\nFirst_Class_Ticket_Price:" << temp_first_class_ticket_cost
                     << "\nSecond_Class_Ticket_Price:" << temp_second_class_ticket_cost << endl;
                break;
            }
        }
        read.close();
    }
    else
    {
        cout << "Unable to open file" << endl;
    }

    if (!found)
    {
        cout << "Train not found." << endl;
        return;
    }

    cout << "\nEnter the Choice" << endl;
    cout << "1.First_Class_Ticket" << endl;
    cout << "2.Second_Class_Ticket" << endl;
    cin >> Ticket_type_choice;

    ofstream file(passFolder, ios::app);
    ofstream ticfile(ticketFolder);
    switch (Ticket_type_choice)
    {
    case 1:
        cout << "Your ticket no. :" << ticketNo << endl;
        if (file.is_open())
        {
            file
                << ticketNo << "\n";

            file.close();
        }
        else
        {
            filesystem::remove(ticketFolder);
            cout << "Error in getting ticket id for passenger " << endl;
            break;
        }
        if (ticfile.is_open())
        {
            // Write data to the file
            ticfile << "Passenger ID: " << passengerId << endl;
            ticfile << "Train Number: " << temp_train_no << endl;
            ticfile << "Train Name: " << temp_train_name << endl;
            ticfile << "Boarding Point: " << temp_bording_pt << endl;
            ticfile << "Destination Point: " << temp_destinatio_pt << endl;
            ticfile << "Ticket Type: First_Class_Ticket" << endl;
            ticfile << "Ticket Cost: " << temp_first_class_ticket_cost << endl;
            cout << "Number of Seats Required:";
            cin >> no_seats;
            ticfile << "Number of Seats Booked "
                    << no_seats;
            for (int i = 1; i <= no_seats; i++)
            {
                cout << "Passenger Name:";
                cin >> passenger_name;
                cout << "Passenge Age:";
                cin >> passenger_age;

                ticfile << "\n"
                        << i
                        << "Passenegr Name:"
                        << passenger_name;
                ticfile << "\n"
                        << i
                        << "Passengr Age:"
                        << passenger_age;

                F += temp_first_class_ticket_cost;
            }
            cout << "_" << endl;
            cout << "Amount Pay:" << F << endl;
            ticfile << "\nTotal Cost :"
                    << F;
            cout << "_" << endl;
            ticfile.close();
        }
        else
        {
            filesystem::remove(ticketFolder);
            cout << "Error: Unable to create the ticket file." << endl;
            break;
        }

        break;
    case 2:
        cout << "Your ticket no. :" << ticketNo << endl;
        if (file.is_open())
        {
            file
                << ticketNo << "\n";

            file.close();
        }
        else
        {
            filesystem::remove(ticketFolder);
            cout << "Error in getting ticket id for passenger " << endl;
            break;
        }
        if (ticfile.is_open())
        {
            // Write data to the file
            ticfile << "Passenger ID: " << passengerId << endl;
            ticfile << "Train Number: " << temp_train_no << endl;
            ticfile << "Train Name: " << temp_train_name << endl;
            ticfile << "Boarding Point: " << temp_bording_pt << endl;
            ticfile << "Destination Point: " << temp_destinatio_pt << endl;
            ticfile << "Ticket Type: First_Class_Ticket" << endl;
            ticfile << "Ticket Cost: " << temp_first_class_ticket_cost << endl;
            cout << "Number of Seats Required : ";
            cin >> no_seats;
            ticfile << "Number of Seats Booked : "
                    << no_seats;
            for (int i = 1; i <= no_seats; i++)
            {
                cout << "Passenger Name : ";
                cin >> passenger_name;
                cout << "Passenger Age : ";
                cin >> passenger_age;

                ticfile << "\n"
                        << i
                        << "Passenger Name :"
                        << passenger_name;
                ticfile << "\n"
                        << i
                        << "Passenger Age :"
                        << passenger_age;

                S += temp_second_class_ticket_cost;
            }
            cout << "____________________________________" << endl;
            cout << "Amount Pay:" << S << endl;
            ticfile << "\nTotal Cost :"
                    << S;
            cout << "____________________________________" << endl;
            ticfile.close();
        }
        else
        {
            filesystem::remove(ticketFolder);
            cout << "Error: Unable to create the ticket file." << endl;
            break;
        }

        break;
    default:
        cout << "Invalid Input";
        break;
    }
}

// $$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$   CANCLE TICKETS   $$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$
void railway::cancle_ticket()
{
    int option;
    string filename, passid, ticketid;
    cout << "*********************************************** CANCLE TICKETS ***********************************************************" << endl;
    cout << "Select One Option \n 1.) Cancel ticket using passenger Id \n 2.) Cancel ticket using Ticket Id \n Enter Option : ";
    cin >> option; // Corrected variable name
    if (option == 1)
    {
        cout << "Enter Passenger Id : ";
        cin >> passid;
        string passFolder = "passengers Id Folder/" + passid + ".txt";
        if (filesystem::exists(passFolder))
        {
            // File exists, open it in append mode
            cout << passid << " Founded" << endl;
        }
        else
        {
            cout << "passenger id Not found " << endl;
            cancle_ticket();
        }
        cout << "Showing all tickets Booked by you" << endl;
        read.open(passFolder, ios::in);
        if (read.is_open())
        {
            int i = 1;
            string line;
            while (getline(read, line))
            {
                // Process the line here
                cout << i << " " << line << endl;
                i++;
            }
            read.close();
        }
        else
        {
            cout << "Unable to get tickets details of the passenger at this time" << endl;
        }
        cout << "Enter Number of the ticket : ";
        cin >> option;
        read.open(passFolder, ios::in);
        string passFolderTemp = "passengers Id Folder/temp.txt";
        ofstream outFile(passFolderTemp, ios::app);
        if (read.is_open())
        {
            int i = 1;
            string line;
            while (getline(read, line))
            {
                if (i != option)
                {
                    outFile << line << endl;
                }
                if (i == option)
                {
                    ticketid = line;
                }
                i++;
            }
            read.close();
            outFile.close();
        }
        else
        {
            cout << "Unable to cancel ticket" << endl;
        }
        try
        {
            filesystem::rename(passFolderTemp, passFolder);
        }
        catch (const filesystem::filesystem_error &e)
        {
            cout << "Error file: " << e.what() << endl;
            exit(0);
        }
        string ticketFolder = "Ticket Id Folder/" + ticketid + ".txt";
        try
        {
            filesystem::remove(ticketFolder);
            cout << "Ticket Cancel Successfully" << endl;
        }
        catch (const filesystem::filesystem_error &e)
        {
            cout << "Error cancelling ticket : " << e.what() << endl;
        }
    }
    else if (option == 2)
    {
        cout << "Enter Ticket Id : ";
        cin >> ticketid;

        string ticketFolder = "Ticket Id Folder/" + ticketid + ".txt";
        if (!filesystem::exists(ticketFolder))
        {
            cout << "Ticket not found" << endl;
            return;
        }

        ifstream read(ticketFolder);
        if (!read.is_open())
        {
            cout << "Unable to get ticket details" << endl;
            return;
        }

        // Read the first line which contains the passenger ID
        string line;
        getline(read, line);
        string passengerId = line.substr(14); // Extract the passenger ID from the line
        read.close();

        string passFolder = "passengers Id Folder/" + passengerId + ".txt";
        if (!filesystem::exists(passFolder))
        {
            return;
        }

        // Create a temporary file
        string passFolderTemp = "passengers Id Folder/temp.txt";
        ofstream outFile(passFolderTemp, ios::trunc); // Open in truncation mode to overwrite existing content
        if (!outFile.is_open())
        {
            return;
        }

        // Read the original file, skip the line with ticketid, and write the rest to the temporary file
        read.open(passFolder);
        if (!read.is_open())
        {
            return;
        }

        while (getline(read, line))
        {
            if (line != ticketid)
            {
                outFile << line << endl;
            }
        }

        // Close the file streams
        read.close();
        outFile.close();

        // Rename the temporary file to overwrite the original passenger file
        try
        {
            filesystem::rename(passFolderTemp, passFolder);
            cout << "Ticket canceled successfully" << endl;
        }
        catch (const filesystem::filesystem_error &e)
        {
            cout << "Error in canceling: " << e.what() << endl;
        }

        // Remove the ticket file
        try
        {
            filesystem::remove(ticketFolder);
        }
        catch (const filesystem::filesystem_error &e)
        {
            cout << "Error removing ticket : " << e.what() << endl;
        }
    }
    else
    {
        cout << "Invalid Input ! Try again ........." << endl;
        cancle_ticket();
    }
    cout << "Do you want to stay in User mode" << endl;
    cout << "1.YES" << endl;
    cout << "2.NO" << endl;
    cin >> y_n_choice;
    if (y_n_choice == 1)
    {
        system("cls");
        user();
    }
    else
    {
        system("cls");
        main_menu();
    }
}
int main()
{
    railway t;
    t.main_menu();
}
