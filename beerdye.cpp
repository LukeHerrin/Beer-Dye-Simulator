#include "beerdye.h"
#include <iostream>
#include <ctime>

using namespace std;

int main()
{
    srand(time(NULL));

    beerDyeTable Table; // creation of the table
    //Table.set_Player_Location(CTD, placement); //this is for individual placemnts but the other function does everyone
    Table = set_Player_Locations(Table);
    Table = assign_Teams(Table);

    NPC* far_Left = Table.get_NPC_Location(0);
    NPC* far_Right = Table.get_NPC_Location(1);
    NPC* close_Left = Table.get_NPC_Location(2);
    NPC* close_Right = Table.get_NPC_Location(3);

    /*
    cout << "Far Left Name: " << far_Left->get_Name() << endl;
    cout << "Far Left Location: " << far_Left->get_Placement() << endl;
    cout << "Far Left Partner Name: " << (far_Left->get_Partner())->get_Name() << endl;
    cout << "Far Left Partner Location: " << (far_Left->get_Partner())->get_Placement() << endl << endl;

    cout << "Far Right Name: " << far_Right->get_Name() << endl;
    cout << "Far Right Location: " << far_Right->get_Placement() << endl;
    cout << "Far Right Partner Name: " << (far_Right->get_Partner())->get_Name() << endl;
    cout << "Far Right Partner Location: " << (far_Right->get_Partner())->get_Placement() << endl << endl;

    cout << "Close Left Name: " << close_Left->get_Name() << endl;
    cout << "Close Left Location: " << close_Left->get_Placement() << endl;
    cout << "Close Left Partner Name: " << (close_Left->get_Partner())->get_Name() << endl; //only line to cause leaks
    cout << "Close Left Partner Location: " << (close_Left->get_Partner())->get_Placement() << endl << endl;

    cout << "Close Right Name: " << close_Right->get_Name() << endl;
    cout << "Close Right Location: " << close_Right->get_Placement() << endl;
    cout << "Close Right Partner Name: " << (close_Right->get_Partner())->get_Name() << endl;
    cout << "Close Right Partner Location: " << (close_Right->get_Partner())->get_Placement() << endl << endl;
    */  

    /*
    cout << "Testing player at far left: " << Table.get_NPC_Location(0) << endl;
    cout << "Testing player at far right: " << Table.get_NPC_Location(1) << endl;
    cout << "Testing player at close left: " << Table.get_NPC_Location(2) << endl;
    cout << "Testing player at close right: " << Table.get_NPC_Location(3) << endl;
    */

    /*
    for(int i = 0; i < 100; i++)
    {
        cout << random_Number_Generator(1, 3) << endl;
    }
    */

    /*
    int a = 0;
    while(1)
    {
    if(cin.fail())
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max());
        cout << “You have entered wrong input” << endl;
        cin >> a;
    }
    if(!cin.fail())
        break;
    }

    cout<<“the number is: “<<a<<endl;
    */


    
    NPC joey_garcia("Joey_Garcia");
    cout << joey_garcia << endl;
    joey_garcia.set_is_NPC(false);
    player_choice(joey_garcia); // this isnt working I dont know why // but it is working????
    return 0;
}