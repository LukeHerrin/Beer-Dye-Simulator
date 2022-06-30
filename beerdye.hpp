#ifndef BEERDYE_HPP
#define BEERDYE_HPP
#include <iostream>
#include <ctime>
#include <array> // I dont know if I actually need this

using namespace std;

void test()
{
    cout << "TEST" << endl;
    return;
}

void NPC::set_Placement(int placement)
{
    m_Placement = placement;
    return;
}

void print_Menu_Options()
{
    cout << "------------------------------" << endl;
    cout << "| Option 1: Throw Dice       |" << endl;
    cout << "| Option 2: Taunt FIX ME!!!  |" << endl;
    cout << "| Option 3: Drink FIX ME!!!  |" << endl;
    cout << "------------------------------" << endl;

    cout << "Please select an option: ";
    return;
}

void player_choice(NPC player)
{
    int option = 0;

    if(player.is_NPC() == false)
    {
        print_Menu_Options();

        cin >> option;

        /*
            There needs to be a better way to validate input, currently I have only seen this way
            it works for all types of input except those that start with a number 
            for ex:
                1ergjgk
                2ijlkhn,m
            okay so it didnt work at all so I will simply not use it for now
        */
        while (option > 3 || option < 1 || cin.fail())
        {
            /*
            if(cin.fail())
            {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(),’\n’);
                //system("clear");
                cout << "Error: Please enter a valid option!" << endl;
                print_Menu_Options();
                cin >> option;
            }
            */
            
            system("clear");
            cout << "Error: Please enter a valid option!" << endl;
            print_Menu_Options();
            cin >> option;
        }   
    }
    else
    {
        int min = 1;
        int max = 3;
        option = random_Number_Generator(min, max);
    }

    system("clear");

    switch (option)
    {
    case 1:
        throw_die();
        break;
    case 2:
        cout << "FIX ME!!! This is the taunt option" << endl;
        break;
    case 3:
        cout << "FIX ME!!! This the drink option" << endl;
        break;
    default:
        cout << "FIX ME!!! ONLY ENTER OPTIONS 1-3" << endl;
        break;
    }
    return;
}

bool math(int position)
{
    bool sucess = false;
    //function calls to determine if shot is made based on function calls and math
    //all these calculations require positions being set up so this will have to wait

    //position in relation to partner
        //synergy
    //player position in relation to how far target is
    //more I cant think of

    //I think I want all of those to give %'s and to average them all or subtract from 100% something like that

    if(sucess == false)
    {
        cout << "Rats you missed" << endl; //will add a function to randomly select dialog
    }
    else if(sucess == true)
    {
        cout << "You hit!" << endl;
    }

    return sucess; //Just for now
}

bool throw_die()
{
    cout << "This is the throw function!!!" << endl;
    //if player is on far or close side // will asses this later
    int aim = 0;
    system("clear");

    cout << "This is a little primative but for now, just choose a number" << endl << endl;
    
    cout << "Far Left:        -0-" << endl;
    cout << "Far Middle:      -1-" << endl;
    cout << "Far Right:       -2-" << endl;
    cout << "Far Left Cup:    -3-" << endl;
    cout << "Far Right Cup:   -4-" << endl;
    cout << "Close Left:      -5-" << endl;
    cout << "Close Middle:    -6-" << endl;
    cout << "Close Right:     -7-" << endl;
    cout << "Close Left Cup:  -8-" << endl;
    cout << "Close Right Cup: -9-" << endl;

    cout << "aim: ";
    cin >> aim;

    system("clear");

    switch (aim)
    {
    case 0: //far_left
        cout << "Aiming for Far Left Area" << endl;
        math(0);
        break;
    case 1: //far_middle
        cout << "Aiming for Far Middle Area" << endl;
        math(1);
        break;
    case 2: //far_right
        cout << "Aiming for Far Right Area" << endl;
        math(2);
        break;
    case 3: //far_left_cup
        cout << "Aiming for Far Left Cup" << endl;
        math(3);
        break;
    case 4: //far_right_cup
        cout << "Aiming for Far Right Cup" << endl;
        math(4);
        break;
    case 5: //close_left
        cout << "Aiming for Close Left Area" << endl;
        math(5);
        break;
    case 6: //close_middle
        cout << "Aiming for Close Middle Area" << endl;
        math(6);
        break;
    case 7: //close_right
        cout << "Aiming for Close Right Area" << endl;
        math(7);
        break;
    case 8: //close_left_cup
        cout << "Aiming for Close Left Cup" << endl;
        math(8);
        break;
    case 9: //close_right_cup
        cout << "Aiming for Close Right Cup" << endl;
        math(9);
        break;
    default:
        cout << "FIX ME!!! YOU'VE HIT DEFAULT" << endl;
        break;
    }
    return 0;
}

void beerDyeTable::set_Player_Location(NPC x, int placement)
{
    /*
    if (pos_Far_Left = place_Holder) 
    {
        pos_Far_Left = x; 
    }
    else if (pos_Far_Right = place_Holder)
    {
        pos_Far_Right = x; 
    }
    else if (pos_Close_Left = place_Holder) 
    {
        pos_Close_Left = x; 
    }
    else 
    {
        pos_Close_Right = x; 
    }
    */
    switch (placement)
    {
    case 0:
        //cout << "FIX ME!!! CASE 0" << endl;
        //cout << pos_Far_Left.m_Name << endl; // trying to test names here
        pos_Far_Left = x;
        pos_Far_Left.set_Placement(0);
        break;
    case 1:
        //cout << "FIX ME!!! CASE 1" << endl;
        pos_Far_Right = x;
        pos_Far_Right.set_Placement(1);
        break;
    case 2:
        //cout << "FIX ME!!! CASE 2" << endl;
        pos_Close_Left = x;
        pos_Close_Left.set_Placement(2);
        break;
    case 3:
        //cout << "FIX ME!!! CASE 3" << endl;
        pos_Close_Right = x;
        pos_Close_Right.set_Placement(3);
        break;
    
    default:
        cout << "NOTHING TO FIX HERE YOUR JUST AN IDIOT" << endl;
        break;
    }
    return;
}

beerDyeTable set_Player_Locations(beerDyeTable Table)
{
    
    NPC Player = get_NPC(0);// = get_NPC(); //get npc will return an NPC from an array list with a static counter
    NPC NPC_1 = get_NPC(1);
    NPC NPC_2 = get_NPC(2);
    NPC NPC_3 = get_NPC(3);
    //NPC NPC_3;
    /*
    ATTENTION!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
    using the default constructor causes a memory leak and I have no idea why
    */
    
    NPC players [4] = {Player, NPC_1, NPC_2, NPC_3};
    
    cout << "set_Player_Locations acessed" << endl;
    for(int i = 0; i < 4; i++)
    {
        Table.set_Player_Location(players[i], i);
    }
    return Table;
}

NPC NPC::operator= (const NPC & rhs)
{
    static int counter = 0;
    //cout << endl << endl << "times called: " << counter << endl;

    //cout << "operator= overload acessed" << endl;
    //cout << "calling object m_Name: " << m_Name << endl;
    //cout << "rhs object m_Name: " << rhs.m_Name << endl;
    m_Name = rhs.m_Name;
    //cout << "calling object m_Name after being assigned: " << m_Name << endl << endl;
    m_Mood = rhs.m_Mood;
    m_Charisma = rhs.m_Charisma;
    m_Confidence = rhs.m_Confidence;
    m_Clumsiness = rhs.m_Clumsiness;
    m_Intoxication = rhs.m_Intoxication;
    m_Placement = rhs.m_Placement;
    m_Partner = rhs.m_Partner;
    counter++;
    return *this;
}

ostream& operator<<(ostream& os, const NPC& NPC)
{
    os << NPC.m_Name;
    return os;
}

void NPC::set_Name(string name)
{
    m_Name = name;
    return;
}

int random_Number_Generator(int min, int max)
{
    int random_Number = 0;
    random_Number = (rand() % (max - min + 1) + min);
    return random_Number;
}

bool NPC::is_NPC()
{
    bool NPC = false;
    if(m_Is_Bot == true)
        NPC = true;
    return NPC;
}

/*
void NPC::set_is_NPC(NPC player)
{

    player.is_NPC = false;

}
*/

NPC::NPC(const string name, const string mood, const int charisma, const int confidence, const int clumsiness, const int intoxication, const bool bot)
{
    m_Name = name;
    m_Mood = mood;
    m_Charisma = charisma;
    m_Confidence = confidence;
    m_Clumsiness = clumsiness;
    m_Intoxication = intoxication;
    m_Is_Bot = bot;
    m_Placement = 4;
    m_Partner = NULL;
}

NPC::NPC()
{
    m_Name = "Crash Test Dummy";
    m_Mood = "Nuetral";
    m_Charisma = 5;
    m_Confidence = 5;
    m_Clumsiness = 5;
    m_Intoxication = 0;
    m_Is_Bot = true;
    m_Placement = 4;
    m_Partner = NULL;
}

NPC::NPC(const string name)
{
    m_Name = name;
    m_Mood = "Nuetral";
    m_Charisma = 5;
    m_Confidence = 5;
    m_Clumsiness = 5;
    m_Intoxication = 0;
    m_Is_Bot = true;
    m_Placement = 4;
    m_Partner = NULL;
}

NPC get_NPC(int choice)
{
    static int counter = 0;
    //cout << "get_NPC acessed: RUN " << counter << endl;
    static int list_size = 3;
    static bool player_taken = false;
    static bool peyton_taken = false;
    static bool dave_taken = false;
    static bool test_taken = false;

    NPC to_return;

    //"characters"
    NPC player("Player", "Nuetral", 5, 5, 5, 0, false);
    NPC peyton("Peyton", "Nuetral", 10, 10, 0, 10, true);
    NPC dave("Crack Head Dave", "Crazy", 0, 0, 0, 10, true);
    NPC test("Test", "Gay", 5, 5, 5, 0, false);
    NPC arr[3] = {player, peyton, dave};

    switch (choice)
    {
    case 0:
        if(player_taken == true)
        {
        cout << "Player is taken, please choose from this updated list" << endl;
        cout << "{";
        for(int i = 0; i < list_size; i++)
        {
            NPC temp = arr[i];
            cout << temp.get_Name() << ",";
        }
        //cout << "}" << endl << "THIS SHOULD BE THE END OF THE RUN" << endl << endl;
        //at this point need to reprompt
        }
        else
        {
            //cout << "Player Selected!!!" << endl;
            //arr.remove(const NPC &player); // I need to write my own damn remove
            player_taken = true;
            to_return = player;
            list_size--;
        }
        break;
    
    case 1:
        if(peyton_taken == true)
        {
        cout << "Peyton is taken, please choose from this updated list" << endl;
        cout << "{";
        for(int i = 0; i < list_size; i++)
        {
            NPC temp = arr[i];
            cout << temp.get_Name() << ",";
        }
        //cout << "}" << endl << "THIS SHOULD BE THE END OF THE RUN" << endl << endl;
        //at this point need to reprompt
        }
        else
        {
            //cout << "Peyton Selected!!!" << endl;
            //arr.remove(const NPC &player); // I need to write my own damn remove
            peyton_taken = true;
            to_return = peyton;
            list_size--;
        }
        break;
    case 2:
        if(dave_taken == true)
        {
        cout << "Dave is taken, please choose from this updated list" << endl;
        cout << "{";
        for(int i = 0; i < list_size; i++)
        {
            NPC temp = arr[i];
            cout << temp.get_Name() << ",";
        }
        //cout << "}" << endl << "THIS SHOULD BE THE END OF THE RUN" << endl << endl;
        //at this point need to reprompt
        }
        else
        {
            //cout << "Dave Selected!!!" << endl;
            //arr.remove(const NPC &player); // I need to write my own damn remove
            dave_taken = true;
            to_return = dave;
            list_size--;
        }
        break;
    case 3:
        if(test_taken == true)
        {
        cout << "Test is taken, please choose from this updated list" << endl;
        cout << "{";
        for(int i = 0; i < list_size; i++)
        {
            NPC temp = arr[i];
            cout << temp.get_Name() << ",";
        }
        //cout << "}" << endl << "THIS SHOULD BE THE END OF THE RUN" << endl << endl;
        //at this point need to reprompt
        }
        else
        {
            //cout << "Dave Selected!!!" << endl;
            //arr.remove(const NPC &player); // I need to write my own damn remove
            test_taken = true;
            to_return = test;
            list_size--;
        }
        break;
    default:
        cout << "Your all out of characters again" << endl;
        break;
    }

    
    /*
    else if(peyton_taken == true)
    {
        //arr.remove(const NPC &peyton);
        to_return = peyton;
    }
    else if(dave_taken == true)
    {
        //arr.remove(const NPC &dave);
        to_return = dave;
    }
    else
        cout << "Your all out of characters" << endl;
    */
    counter++;
    return to_return;
}

string NPC::get_Name()
{
    return m_Name;
}

void NPC::set_is_NPC(bool NPC)
{
    m_Is_Bot = NPC;
    return;
}

NPC* beerDyeTable::get_NPC_Location(int location)
{
    NPC* Desired_NPC = NULL;
    switch (location)
    {
    case 0:
        Desired_NPC = &pos_Far_Left;
        break;
    case 1:
        Desired_NPC = &pos_Far_Right;
        break;
    case 2:
        Desired_NPC = &pos_Close_Left;
        break;
    case 3:
        Desired_NPC = &pos_Close_Right;
        break;
    default:
        cout << "THERE ARE ONLY 4 LOCATIONS!!!" << endl;
        break;
    }
    return Desired_NPC;
}

int NPC::get_Placement()
{
    return m_Placement;
}

void NPC::set_Partner(NPC* partner)
{
    m_Partner = partner;
    return;
}

beerDyeTable assign_Teams(beerDyeTable Table)
{
    cout << "assign_Teams accessed" << endl;
    NPC* far_Left = Table.get_NPC_Location(0);
    NPC* far_Right = Table.get_NPC_Location(1);
    NPC* close_Left = Table.get_NPC_Location(2);
    NPC* close_Right = Table.get_NPC_Location(3);
    far_Left->set_Partner(far_Right);
    far_Right->set_Partner(far_Left);
    close_Left->set_Partner(close_Right);
    close_Right->set_Partner(close_Left);
    return Table;
}

NPC* NPC::get_Partner()
{
    return m_Partner;
}

#endif