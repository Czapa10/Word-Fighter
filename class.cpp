#include <iostream>
#include "class.h"
#include <windows.h>
#include <stdio.h>

using namespace std;

int c;
void col()//This procedure change the colors
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),c);
}

void gotoxy(int x, int y)
{
  COORD c;
  c.X=x-1;
  c.Y=y-1;
  SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),c);
}

///////////////////////////////////////////////////////////////////////////////

Player::Player(int hp1,int max_hp1,int raw_damage_dealt1,int combo_chance1,
               string boots1,string breastplate1,string helmet1,string sword1,
               int money1,int number_of_fights_played1,int talent_coin1)
{
    hp                      = hp1;
    max_hp                  = max_hp1;
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

Oponent::Oponent(string name1,int hp1,int max_hp1,int damage1,int combo_chance1)
{
    name         = name1;
    hp           = hp1;
    max_hp       = max_hp1;
    damage       = damage1;
    combo_chance = combo_chance1;
}

void Oponent::show()
{
    system("cls");
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

    cout<<header;

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

    cout<<endl;
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
    cout<<"Choose the number: ";
    cin>>menu_c;
            if( !cin )
        {
            cin.clear(); //error control
            cin.sync();
        }
}

///////////////////////////////////////////////////////////////////////////////

Story::Story(int length,string c1,string c2,string c3,
             string c4,string c5,string c6,string c7,
             string c8,string c9,string c10,string c11,
             string c12,string s1,string s2,string s3,
             string s4,string s5,string s6,string s7,
             string s8,string s9,string s10,string s11,
             string s12)
{
    length_of_dialogue=length;
    content1=c1; content2=c2;   content3=c3;   content4=c5;
    content5=c5; content6=c6;   content7=c7;   content8=c8;
    content9=c9; content10=c10; content11=c11; content12=c11;
    speaker1=s1; speaker2=s2;   speaker3=s3; speaker4=s4;
    speaker5=s5; speaker6=s6;   speaker7=s7; speaker8=s8;
    speaker9=s9; speaker10=s10; speaker11=s11; speaker12=s12;
}

void Story::show_story()
{
    system("cls");

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





