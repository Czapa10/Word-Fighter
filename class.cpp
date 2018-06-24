#include <iostream>
#include "class.h"
#include <windows.h>
#include <stdio.h>
#include <time.h>

using namespace std;

uint_fast8_t c;
bool background_grey=1;
void col()//This procedure change the colors
{
    if(background_grey==false)
    {
        if(c==128)c=15;//black -> white
        if(c==129)c=9; //dark blue -> blue
        if(c==130)c=2; //dark green
        if(c==131)c=3; //dark blue
        if(c==132)c=4; //dark red
        if(c==133)c=5; //dark pink
        if(c==134)c=6; //dark yellow
        if(c==135)c=7; //grey
        if(c==136)c=0; //background colors
        if(c==137)c=9;//blue
        if(c==138)c=10;//green
        if(c==139)c=11;//light blue
        if(c==140)c=12;//red
        if(c==141)c=13;//pink
        if(c==142)c=14;//yellow
        if(c==143)c=15;//white
    }
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),c);
}

void gotoxy(uint_fast8_t x, uint_fast8_t y)
{
  COORD c;
  c.X=x-1;
  c.Y=y-1;
  SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),c);
}

///////////////////////////////////////////////////////////////////////////////

Player::Player(int hp1,int max_hp1,int all_max_hp1,int raw_damage_dealt1,int combo_chance1,
               string boots1,string breastplate1,string helmet1,string sword1,
               int money1,int number_of_fights_played1,int talent_coin1)
{
    hp                      = hp1;
    max_hp                  = max_hp1;
    all_max_hp              = all_max_hp1;
    raw_damage_dealt        = raw_damage_dealt1;
    combo_chance            = combo_chance1;
    boots                   = boots1;
    breastplate             = breastplate1;
    helmet                  = helmet1;
    sword                   = sword1;
    money                   = money1;
    number_of_fights_played = number_of_fights_played1;
    talent_coin             = talent_coin1;
}

///////////////////////////////////////////////////////////////////////////////

Opponent::Opponent(string name1,int hp1,int max_hp1,int damage1,int combo_chance1,string sword1,int combo_number1)
{
    name         = name1;
    hp           = hp1;
    max_hp       = max_hp1;
    damage       = damage1;
    combo_chance = combo_chance1;
    sword        = sword1;
    combo_number = combo_number1;
}

void Opponent::show()
{
    system("cls");
    c=142; col();
    cout<<"YOUR OPPONENT STATISTICS:"<<endl;
    c=143; col();
    cout<<"-----------------------------------------------------------"<<endl;
    c=128; col();
    cout<<"name: "<<name<<endl;
    c=140; col();
    cout<<"hp: "<<hp<<endl;
    c=139; col();
    cout<<"damage: "<<damage<<endl;
    c=138; col();
    cout<<"combo chance: "<<combo_chance<<endl;
    c=143; col();
    cout<<"-----------------------------------------------------------"<<endl;
    c=140; col();
    cout<<"0.exit"<<endl;
    c=142; col();
    cout<<"1.fight"<<endl;
    c=143; col();
    cout<<"-----------------"<<endl;
}

int Opponent::hit(int raw_damage,string sword,int combo_chance,string name)
{
    ///sword damage
    int sword_damage;
    if(sword=="wooden") sword_damage=8;
    if(sword=="stone") sword_damage=15;
    if(sword=="iron") sword_damage=25;
    if(sword=="diamond") sword_damage=40;
    if(sword=="platinum") sword_damage=55;

    ///raw damage
    int all_damage = damage*sword_damage;

    ///combo
    int draw;
    srand(time(NULL));
    draw=rand()%100+1;

    bool combo=false;
    if(draw<combo_chance)combo=true;

    ///draw
    draw=rand()%10+1;

    ///final damage
    all_damage+=draw;
    if(combo) all_damage = all_damage*2;
    all_damage = all_damage/20;

    ///write damage on screen
    c=140; col();
    if(combo==false)cout<<endl<<name<<" took you "<<all_damage<<" hp!";
    else {cout<<endl<<name<<" have combo and took you "<<all_damage<<" hp!"; combo_number++;}
    Sleep(2000);

    return all_damage;
}

///////////////////////////////////////////////////////////////////////////////

Interfac::Interfac(int how_many_lines1,bool cls1,string header1,
                   int col_header1,bool separator_long1,
                   string first_line1,   int c1,
                   string second_line1,  int c2,
                   string third_line1,   int c3,
                   string fourth_line1,  int c4,
                   string fifth_line1,   int c5,
                   string sixth_line1,   int c6,
                   string seventh_line1, int c7,
                   string eighth_line1,  int c8,
                   bool money_b1, bool hp_b1, bool to_freedom_b1, bool talent_b1,
                   int money1, int hp1, int max_hp1, int to_freedom1, int talent1)
{
    how_many_lines=how_many_lines1;
    cls=cls1;
    header=header1; col_header=col_header1;
    separator_long=separator_long1;
    first_line=first_line1; col1=c1;
    second_line=second_line1; col2=c2;
    third_line=third_line1; col3=c3;
    fourth_line=fourth_line1; col4=c4;
    fifth_line=fifth_line1; col5=c5;
    sixth_line=sixth_line1; col6=c6;
    seventh_line=seventh_line1; col7=c7;
    eighth_line=eighth_line1; col8=c8;
    money_b=money_b1; hp_b=hp_b1; to_freedom_b=to_freedom_b1; talent_b=talent_b1;
    money=money1; hp=hp1; max_hp=max_hp1; to_freedom=to_freedom1; talent=talent1;
}

void Interfac::show_menu()
{
    if(cls==true)system("cls");
    c=col_header; col();

    if(header!="0")cout<<header;

    ///statistics
    if(money_b==true)
    {
        c=142; col();
        cout<<"    money: "<<money;
    }
    if(hp_b==true)
    {
        c=140; col();
        cout<<"  hp: "<<hp<<"/"<<max_hp;
    }
    if(to_freedom_b==true)
    {
        c=138; col();
        cout<<"  games left: "<<to_freedom;
    }
    if(talent_b==true)
    {
        c=139; col();
        cout<<"  talent coins: "<<talent;
    }

    if(header!="0")cout<<endl;
    c=143; col(); //white
    if(separator_long==true)
    cout<<"-----------------------------------------------------------"<<endl;
    else
    cout<<"-----------------"<<endl;

    if(how_many_lines>0)
    {c=col1; col();
    cout<<"1. "<<first_line<<endl;}

    if(how_many_lines>1)
    {c=col2; col();
    cout<<"2. "<<second_line<<endl;}

    if(how_many_lines>2)
    {c=col3; col();
    cout<<"3. "<<third_line<<endl;}

    if(how_many_lines>3)
    {c=col4; col();
    cout<<"4. "<<fourth_line<<endl;}

    if(how_many_lines>4)
    {c=col5; col();
    cout<<"5. "<<fifth_line<<endl;}

    if(how_many_lines>5)
    {c=col6; col();
    cout<<"6. "<<sixth_line<<endl;}

    if(how_many_lines>6)
    {c=col7; col();
    cout<<"7. "<<seventh_line<<endl;}

    if(how_many_lines>7)
    {c=col8; col();
    cout<<"8. "<<eighth_line<<endl;}

    c=143; col(); //white
    if(separator_long==true)
    cout<<"-----------------------------------------------------------"<<endl;
    else
    cout<<"-----------------"<<endl;

    c=137; col(); //blue
    cout<<"Enter the number: ";
    cin>>menu_c;
            if( !cin )
        {
            cin.clear(); //error control
            cin.sync();
        }
}

///////////////////////////////////////////////////////////////////////////////

Story::Story(int length,bool cls1,string c1,string c2,string c3,
             string c4,string c5,string c6,string c7,
             string c8,string c9,string c10,string c11,
             string c12,string s1,string s2,string s3,
             string s4,string s5,string s6,string s7,
             string s8,string s9,string s10,string s11,
             string s12)
{
    length_of_dialogue=length;  cls=cls1;
    content1=c1; content2=c2;   content3=c3;   content4=c5;
    content5=c5; content6=c6;   content7=c7;   content8=c8;
    content9=c9; content10=c10; content11=c11; content12=c11;
    speaker1=s1; speaker2=s2;   speaker3=s3; speaker4=s4;
    speaker5=s5; speaker6=s6;   speaker7=s7; speaker8=s8;
    speaker9=s9; speaker10=s10; speaker11=s11; speaker12=s12;
}

void Story::show_story()
{
    if(cls==true)system("cls");

        c=142; col(); //yellow
        cout<<speaker1;
        c=128; col(); //black
        cout<<content1<<endl;
        getchar();getchar();

    if(length_of_dialogue>1)
    {
        c=142; col(); //yellow
        cout<<speaker2;
        c=128; col(); //black
        cout<<content2<<endl;
        getchar();
    }

    if(length_of_dialogue>2)
    {
        c=142; col(); //yellow
        cout<<speaker3;
        c=128; col(); //black
        cout<<content3;
        cout<<endl;
        getchar();
    }

    if(length_of_dialogue>3)
    {
        c=142; col(); //yellow
        cout<<speaker4;
        c=128; col(); //black
        cout<<content4<<endl;
        getchar();getchar();
    }

    if(length_of_dialogue>4)
    {
        c=142; col(); //yellow
        cout<<speaker5;
        c=128; col(); //black
        cout<<content5<<endl;
        getchar();getchar();
    }

    if(length_of_dialogue>5)
    {
        c=142; col(); //yellow
        cout<<speaker6;
        c=128; col(); //black
        cout<<content6<<endl;
        getchar();getchar();
    }

    if(length_of_dialogue>6)
    {
        c=142; col(); //yellow
        cout<<speaker7;
        c=128; col(); //black
        cout<<content7<<endl;
        getchar();getchar();
    }

    if(length_of_dialogue>7)
    {
        c=142; col(); //yellow
        cout<<speaker8;
        c=128; col(); //black
        cout<<content8<<endl;
        getchar();getchar();
    }

    if(length_of_dialogue>8)
    {
        c=142; col(); //yellow
        cout<<speaker9;
        c=128; col(); //black
        cout<<content9<<endl;
        getchar();getchar();
    }

    if(length_of_dialogue>9)
    {
        c=142; col(); //yellow
        cout<<speaker10;
        c=128; col(); //black
        cout<<content10<<endl;
        getchar();getchar();
    }

    if(length_of_dialogue>10)
    {
        c=142; col(); //yellow
        cout<<speaker11;
        c=128; col(); //black
        cout<<content11<<endl;
        getchar();getchar();
    }

    if(length_of_dialogue>11)
    {
        c=142; col(); //yellow
        cout<<speaker12;
        c=128; col(); //black
        cout<<content12<<endl;
        getchar();getchar();
    }
}

///////////////////////////////////////////////////////////////////////////////

Item::Item(int c,string n,string d,string t,bool e)
{
    cost=c;
    name=n;
    description=d;
    type=t;
    enabled=e;
}

void Item::show()
{
    c=137; col();
    if(enabled==false)
    {
        c=135; col();
    }
    cout<<name;
    cout<<" "<<type;
    c=128; col();
    if(enabled==false)
    {
        c=135; col();
    }
    cout<<" "<<description;
    c=142; col();
    if(enabled==false)
    {
        c=135; col();
    }
    cout<<"  cost: "<<cost<<endl;
}

///////////////////////////////////////////////////////////////////////////////

Skill::Skill(int n,int p_tal,string d,string d2,int e,int x1,int y1,int cos,int col)
{
    number=n;
    p_talent_coins=p_tal;
    description=d;
    description2=d2;
    enabled=e;
    x=x1;
    y=y1;
    cost=cos;
    color=col;
}

void Skill::show()
{
    gotoxy(x,y);
    c=128; col();
    cout<<number<<".";
    c=color;                   ///0-owned;1-to buy;2-unenabled
    if((color==140)&&(enabled==1))c=132;
    if((color==137)&&(enabled==1))c=129;
    if(enabled==2)                c=135;
    col();
    cout<<description;
    if(description2!="0")
    {
        gotoxy(x+2,y+1);
        cout<<description2;
    }

    if(enabled==1)c=138;
    else if(enabled==2)c=135;
    else c=136;
    col();
    cout<<"|"<<cost<<"|";
}

Background::Background(bool background1){background=background1;}

void Background::background_change()
{
    background_grey=background;
}






