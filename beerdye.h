#ifndef BEERDYE_H
#define BEERDYE_H
#include <iostream>
#include <array>

using namespace std;

void test();

bool throw_die();

bool math(int position);

void print_Menu_Options();

//void beerDyeTable::set_Player_Location(NPC x);

class NPC
{
    public:
        NPC(const string, const string, const int, const int, const int, const int, const bool);
        NPC();
        NPC(string name);
        NPC operator= (const NPC & rhs);
        friend ostream& operator<<(ostream& os, const NPC& NPC);
        void set_Name(string name);
        string get_Name();
        void set_is_NPC(bool NPC);
        bool is_NPC();
        void set_Placement(int placement);
        int get_Placement();
        void set_Partner(NPC* partner);
        NPC* get_Partner();
    private:
        string m_Name = "Crash Test Dummy"; //WHY IS STRING NOT A VARIABLE
        string m_Mood = "Nuetral";
        int m_Charisma = 5;
        int m_Confidence = 5;
        int m_Clumsiness = 5;
        int m_Intoxication = 0;
        bool m_Is_Bot = false;
        int m_Placement = 4; //0-fl, 1-fr, 2-cl, 3-cr
        NPC* m_Partner = NULL;
};

class Player: public NPC
{
    public:
    private:
};

class beerDyeTable
{
public:
    void set_Player_Location(NPC x, int placement);
    NPC* get_NPC_Location(int location);
private:
    NPC place_Holder;

    int far_Left = 0;
    int far_Middle = 1;
    int far_Right = 2;
    int far_Left_Cup = 3;
    int far_Right_Cup = 4;

    int close_Left = 5;
    int close_Middle = 6;
    int close_Right = 7;
    int close_Left_Cup = 8;
    int close_Right_Cup = 9;

    NPC pos_Far_Left = place_Holder;
    NPC pos_Far_Right = place_Holder;
    NPC pos_Close_Left = place_Holder;
    NPC pos_Close_Right = place_Holder;
};

NPC get_NPC(int choice);

beerDyeTable set_Player_Locations(beerDyeTable Table);

int random_Number_Generator(int min, int max);

void player_choice(NPC player);

beerDyeTable assign_Teams(beerDyeTable Table);

#include "beerdye.hpp"
#endif