#include <iostream>

using namespace std;

class Player
{
    int hp;
    int max_hp;
    int raw_damage_dealt;
    int combo_chance;
    string boots;
    string breastplate;
    string helmet;
    string sword;
    int money;
    int number_of_fights_played;
    int talent_coin;
 public:
    Player(int=100,int=100,int=5,int=5,
           string="lack",string="lack",string="lack",string="wooden",int=0,int=0,int=0);
    //void LoadFromFile();
    //void SaveToFile();
    //void hit();
    //void take_damage();
    //bool combo_hit();
    //void armor_change();
    //void sword_change();
    //void number_of_fights_change();

    friend void game();
    friend void armor_shop();
    friend void city();
    friend void cheats();
    friend void weapon_shop();
    friend void tavern();
    friend void character_development();
    friend void atack_tree();
    friend void defense_tree();
    friend void character_stats();
    friend void fight();
};

class Opponent
{
    string name;
    int hp;
    int max_hp;
    int damage;
    int combo_chance;
    string sword;
public:
    Opponent(string="John",int=100,int=100,int=10,int=5,string="iron");
    void show();
    int hit(int,string,int,string);
    //void take_damage();
    //bool combo_hit();

    friend void fight();
};

class Interfac
{
    int how_many_lines; bool cls;
    string header;      int col_header;
    bool separator_long;
    string first_line;  int col1;
    string second_line; int col2;
    string third_line;  int col3;
    string fourth_line; int col4;
    string fifth_line;  int col5;
    string sixth_line;  int col6;
    string seventh_line;int col7;
    string eighth_line; int col8;
    bool money_b, hp_b, to_freedom_b, talent_b;
    int money, hp, max_hp, to_freedom, talent;
    int menu_c;
public:
    Interfac(int=2,bool=true,string="HEAD",int=142,bool=true,string="lack",
             int=138,string="lack",int=138,string="lack",
             int=138,string="lack",int=138,string="lack",
             int=138,string="lack",int=138,string="lack",
             int=138,string="lack",int=138,
             bool=false,bool=false,bool=false,bool=false,
             int=0,int=100,int=100,int=100,int=0);
    void show_menu();

    friend int main();
    friend void city();
    friend void tavern();
    friend void character_development();
};

class Story
{
    int length_of_dialogue;
    ///contents///
    string content1;  string content2;  string content3;
    string content4;  string content5;  string content6;
    string content7;  string content8;  string content9;
    string content10; string content11; string content12;
    ///speakers///
    string speaker1;  string speaker2;  string speaker3;
    string speaker4;  string speaker5;  string speaker6;
    string speaker7;  string speaker8;  string speaker9;
    string speaker10; string speaker11; string speaker12;
public:
    Story(int=3,string="lack",string="lack",string="lack",
                string="lack",string="lack",string="lack",
                string="lack",string="lack",string="lack",
                string="lack",string="lack",string="lack",
          string="Judge: ",string="Judge: ",string="Judge: ",
          string="Judge: ",string="Judge: ",string="Judge: ",
          string="Judge: ",string="Judge: ",string="Judge: ",
          string="Judge: ",string="Judge: ",string="Judge: ");
    void show_story();
};

class Item
{
    int cost;
    string name;
    string description;
    string type;
    bool enabled;
public:
    Item(int=10,string="error",string="lack",string="lack",bool=true);
    void show();

    friend void armor_shop();
    friend void weapon_shop();
};

class Skill
{
    int number;
    int p_talent_coins;
    string description;
    string description2;
    int enabled;
    int x,y;
    int cost;
    int color;
public:
    Skill(int=0,int=0,string="description",string="0",int=0,int=1,int=1,int=2,int=140);
    void show();

    friend void atack_tree();
    friend void defense_tree();
} ;










