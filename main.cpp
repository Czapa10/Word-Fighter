#include <iostream>
#include <windows.h>
#include <cstdlib>
#include <stdio.h>
#include <time.h>
#include <fstream>
#include "class.h"

using namespace std;

uint_fast16_t c1; //color
bool background_grey1=1;//1-grey 0-black
bool iena[12],sena[4]; //shops
short ata_ena[12],def_ena[12]; //character development
string sentence; int average_write_time; //fight
bool game_over=false;
int_fast8_t dialogue_value;
bool game_start=1;

void col1();
void cls();
void settings();
void credits();
void new_game();
void city();
void armor_shop();
void buy_want(string type);
void buy_false(string type);
void ena_false(short version);
void weapon_shop();
void skill_buy();
void character_development();
void tavern();
void fight();
void cheats();
void exit_game();
void atack_tree();
void defense_tree();
void character_stats();
void gotoxy1(short x,short y);
void sword_color(string x);
void sentences();
void BOSS1();
void BOSS2();
void BOSS2_2();
void special_item(string item,string specification);
void save_to_file();
void load_from_file();

Player p;

int main()
{
    if(game_start)
    {
        fstream file;
        file.open("save.txt",ios::in);

        string line;
        int line_number=1;

        if(file.good()==true)
        {
            getline(file,line);
            background_grey1 = atoi(line.c_str());
        }
        file.close();
    }
    game_start=0;
    //////////////////////////

    srand(time(NULL));

    //////////////////////////
    for(int i=0;i<12;i++)
    {
        iena[i]=true;
        ata_ena[i+1]=2;
        def_ena[i+1]=2;
    }
    for(int i=0;i<4;i++)
    {
        sena[i]=true;
    }
    ata_ena[0]=1;
    def_ena[0]=1;

    if(background_grey1)system("color 8f");
    else{system("color 0f");Background b(false); b.background_change();}

    Interfac i1(5,true,"                        WORD FIGHTER",142,true,"New game",
                138,"Continue",138,"Credits",139,"Settings",137,"Exit",140);
    i1.show_menu();

        switch(i1.menu_c)
        {
            case 1: new_game();           break;
            case 2: load_from_file();     break;
            case 3: credits();            break;
            case 4: settings();           break;
            case 5: exit(0);              break;
            default:
                {
                    c1=140; col1(); //red
                    cout<<"This option does not exist!";
                    Sleep(1000);
                }
        }

    return 0;
}

void col1()
{
    if(background_grey1==false)
    {
        if(c1==128)c1=15;//black -> white
        if(c1==129)c1=9; //dark blue -> blue
        if(c1==130)c1=2; //dark green
        if(c1==131)c1=3; //dark blue
        if(c1==132)c1=4; //dark red
        if(c1==133)c1=5; //dark pink
        if(c1==134)c1=6; //dark yellow
        if(c1==135)c1=7; //grey
        if(c1==136)c1=0; //background colors
        if(c1==137)c1=9;//blue
        if(c1==138)c1=10;//green
        if(c1==139)c1=11;//light blue
        if(c1==140)c1=12;//red
        if(c1==141)c1=13;//pink
        if(c1==142)c1=14;//yellow
        if(c1==143)c1=15;//white
    }
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),c1);
}

void cls()
{
    system("cls");
}

void credits()
{
    cls();
    c1=139; col1();
    cout<<"The game is created by Grzegorz Bednorz";
    getchar();getchar();
    main();
}

void settings()
{
    cls();
    c1=142; col1();
    cout<<"SETTINGS:"<<endl;
    c1=143; col1();
    cout<<"-----------------------------------------------------------"<<endl;
    c1=138; col1();
    cout<<"1. Background color"<<endl;
    c1=140; col1();
    cout<<"2. exit"<<endl;
    c1=143; col1();cout<<"-----------------------------------------------------------"<<endl;
    c1=129; col1(); cout<<"Enter the number:";
    int settings_c; cin>>settings_c;

    switch(settings_c)
    {
    case 1:
        {
a:          Interfac set1(3,1,"BACKGROUND COLOR",142,0,"grey",128,"black",128,"exit",140);
            set1.show_menu();

            switch(set1.menu_c)
            {
                case 1:
                     {
                         system("color 8f");
                         background_grey1=true;
                         Background b;
                         b.background_change();
                     } break;
                case 2:
                    {
                        system("color 0f");
                        background_grey1=false;
                        Background b(false);
                        b.background_change();
                    } break;
                case 3: settings(); break;
                default:
                    {
                        c1=140; col1(); //red
                        cout<<"This option does not exist!";
                        Sleep(1000);
                    }
            }
            goto a;
        }
    case 2: main();
    default:
        {
            c1=140; col1(); //red
            cout<<"This option does not exist!";
            Sleep(1000);
            settings();
        }
    }

}

void new_game()
{
    if(game_over)
    {
        p.hp=100;
        p.max_hp=100;
        p.all_max_hp=100;
        p.raw_damage_dealt=5;
        p.combo_chance=5;
        p.boots="lack";
        p.breastplate="lack";
        p.helmet="lack";
        p.sword="wooden";
        p.money=0;
        p.number_of_fights_played=0;
        p.talent_coin=0;
    }

    Story s1(3,1,"You are condemned for arena.",
             "To free yourself you must win hundred fights in a row.",
             "Good Luck!");
    s1.show_story();

    game_over=true;

    city();
}

void city()
{
    for(;;)
    {
        Interfac i(7,true,"CITY",142,true,"Armor shop",
                   138,"Weapon shop",138,"Character development",
                   138,"Tavern",142,"Fight",139,"Save",129,
                   "Exit",140,"",0,true,true,true,true,
                   p.money,p.hp,p.all_max_hp,100-p.number_of_fights_played,p.talent_coin);
        i.show_menu();

        switch(i.menu_c)
        {
            case 1: armor_shop(); break;
            case 2: weapon_shop(); break;
            case 3: character_development(); break;
            case 4: tavern(); break;
            case 5: fight(); break;
            case 6: save_to_file(); break;
            case 7: exit_game(); break;
            case 666: cheats(); break;
            default:
                {
                    c1=140; col1();
                    cout<<endl<<"This option does not exist!"<<endl;
                    Sleep(1000);
                }
        }
    }
}

void armor_shop()
{
    short shop_c;

    cls(); c1=142; col1();
    cout<<"ARMOR SHOP"<<endl;

    c1=143; col1(); //grey
    cout<<"-----------------------------------------------------------"<<endl;

    c1=137; col1(); //green
    cout<<"You wearing: ";

    c1=142; col1();
    cout<<"                             Your money: "<<p.money<<endl;

    c1=143; col1(); //grey
    cout<<"-----------------"<<endl;

    c1=138; col1();
    cout<<"boots:       ";
    c1=128; col1();
    cout<<p.boots<<endl;

    c1=138; col1();
    cout<<"breastplate: ";
    c1=128; col1();
    cout<<p.breastplate<<endl;

    c1=138; col1();
    cout<<"helmet:      ";
    c1=128; col1();
    cout<<p.helmet<<endl;

    c1=143; col1(); //white
    cout<<"-----------------"<<endl<<endl;

    c1=142; col1(); //yellow
    cout<<"Shop:"<<endl;

    c1=143; col1(); //white
    cout<<"-----------------"<<endl<<endl;

    c1=128; col1(); //black
    cout<<"1. Boots"<<endl<<"2. Breastplate"<<endl<<
    "3. Helmets"<<endl;
    c1=140; col1();
    cout<<"4. Exit"<<endl;

    c1=143; col1(); //white
    cout<<"-----------------"<<endl;

    c1=137; col1();
    cout<<"Choose the number: ";
    cin>>shop_c;
        if( !cin )
        {
            cin.clear();//error control
            cin.sync();
        }

    switch(shop_c)///choise(boots,breastplates,helmets)
    {
    case 1:
        {
            short boots_c;

            for(;;)
            {
                Boots:

                cls();
                c1=142; col1();
                cout<<"Boots";

                c1=142; col1();
                cout<<"                             Your money: "<<p.money<<endl;

                c1=143; col1(); //white
                cout<<"-----------------"<<endl;

                Item i1(10,"leather","These boots add you 10 hp"," boots",iena[0]);
                c1=128; col1();
                cout<<"1. ";  i1.show();

                Item i2(25,"iron","These boots add you 20 hp","    boots",iena[1]);
                c1=128; col1();
                cout<<"2. ";  i2.show();

                Item i3(60,"diamond","These boots add you 30 hp"," boots",iena[2]);
                c1=128; col1();
                cout<<"3. ";  i3.show();

                Item i4(100,"platinum","These boots add you 40 hp","boots",iena[3]);
                c1=128; col1();
                cout<<"4. ";  i4.show();

                c1=140; col1();
                cout<<"5. Exit"<<endl;

                c1=143; col1(); //white
                cout<<"-----------------"<<endl;

                c1=142; col1();
                cout<<"Choose the number:";
                cin>>boots_c;
                if( !cin )
                {
                    cin.clear();//error control
                    cin.sync();
                }

                switch(boots_c)///choose, which BOOTS
                {
                case 1:
                    {
                        if(i1.enabled==false) {ena_false(1); goto Boots;}

                        if(i1.cost<=p.money)
                        {
                            string b1;
                            buy_want("boots");
                            cin>>b1;
                            if((b1=="y")||(b1=="Y"))
                            {
                                p.money-=i1.cost;
                                p.boots="leather";
                                iena[0]=false;
                                p.all_max_hp+=10;
                                p.hp+=10;
                                if(def_ena[2]==0)
                                {
                                    p.all_max_hp+=10;
                                    p.hp+=10;
                                }
                                armor_shop();
                            }
                        }
                        else
                        {
                            buy_false("money");
                        }
                    }break;

                case 2:
                    {
                        if(i2.enabled==false) {ena_false(1); goto Boots;}

                        if(i2.cost<=p.money)
                        {
                            string b2;
                            buy_want("boots");
                            cin>>b2;
                            if((b2=="y")||(b2=="Y"))
                            {
                                p.money-=i2.cost;
                                p.boots="iron";
                                iena[0]=false;
                                iena[1]=false;
                                p.all_max_hp+=20;
                                p.hp+=20;
                                if(def_ena[4]==0)
                                {
                                    p.all_max_hp+=15;
                                    p.hp+=15;
                                }
                                armor_shop();
                            }
                        }
                        else
                        {
                            buy_false("money");
                        }
                    }break;

                    case 3:
                    {
                        if(i3.enabled==false) {ena_false(1); goto Boots;}

                        if(i3.cost<=p.money)
                        {
                            string b3;
                            buy_want("boots");
                            cin>>b3;
                            if((b3=="y")||(b3=="Y"))
                            {
                                p.money-=i3.cost;
                                p.boots="diamond";
                                iena[0]=false;
                                iena[1]=false;
                                iena[2]=false;
                                p.all_max_hp+=30;
                                p.hp+=30;
                                if(def_ena[6]==0)
                                {
                                    p.all_max_hp+=20;
                                    p.hp+=20;
                                }
                                armor_shop();
                            }
                        }
                        else
                        {
                            buy_false("money");
                        }
                    }break;

                    case 4:
                    {
                        if(i4.enabled==false) {ena_false(1); goto Boots;}

                        if(i4.cost<=p.money)
                        {
                            string b4;
                            buy_want("boots");
                            cin>>b4;
                            if((b4=="y")||(b4=="Y"))
                            {
                                p.money-=i4.cost;
                                p.boots="platinum";
                                iena[0]=false;
                                iena[1]=false;
                                iena[2]=false;
                                iena[3]=false;
                                p.all_max_hp+=40;
                                p.hp+=40;
                                if(def_ena[8]==0)
                                {
                                    p.all_max_hp+=25;
                                    p.hp+=25;
                                }
                                armor_shop();
                            }
                        }
                        else
                        {
                            buy_false("money");
                        }
                    }break;


                case 5:
                    {
                        armor_shop();
                    }
                }
            }
        case 2:
            {
            short breastplate_c;

            for(;;)
            {
                Breastplate:

                cls();
                c1=142; col1();
                cout<<"Breastplates";

                c1=142; col1();
                cout<<"                             Your money: "<<p.money<<endl;

                c1=143; col1(); //white
                cout<<"-----------------"<<endl;

                Item i5(15,"leather","These item add you 20 hp"," breastplate",iena[4]);
                c1=128; col1();
                cout<<"1. ";  i5.show();

                Item i6(35,"iron","These item add you 35 hp","    breastplate",iena[5]);
                c1=128; col1();
                cout<<"2. ";  i6.show();

                Item i7(75,"diamond","These item add you 50 hp"," breastplate",iena[6]);
                c1=128; col1();
                cout<<"3. ";  i7.show();

                Item i8(125,"platinum","These item add you 70 hp","breastplate",iena[7]);
                c1=128; col1();
                cout<<"4. ";  i8.show();

                c1=140; col1();
                cout<<"5. Exit"<<endl;

                c1=143; col1(); //white
                cout<<"-----------------"<<endl;

                c1=142; col1();
                cout<<"Choose the number:";
                cin>>breastplate_c;
                if( !cin )
                {
                    cin.clear();//error control
                    cin.sync();
                }

                switch(breastplate_c)
                {
                case 1:
                    {
                        if(i5.enabled==false) {ena_false(1); goto Breastplate;}

                        if(i5.cost<=p.money)
                        {
                            string b5;
                            buy_want("breastplate");
                            cin>>b5;
                            if((b5=="y")||(b5=="Y"))
                            {
                                p.money-=i5.cost;
                                p.breastplate="leather";
                                iena[4]=false;
                                p.all_max_hp+=20;
                                p.hp+=20;
                                if(def_ena[2]==0)
                                {
                                    p.all_max_hp+=10;
                                    p.hp+=10;
                                }
                                armor_shop();
                            }
                        }
                        else
                        {
                            buy_false("money");
                        }
                    }break;

                case 2:
                    {
                        if(i6.enabled==false) {ena_false(1); goto Breastplate;}

                        if(i6.cost<=p.money)
                        {
                            string b6;
                            buy_want("breastplate");
                            cin>>b6;
                            if((b6=="y")||(b6=="Y"))
                            {
                                p.money-=i6.cost;
                                p.breastplate="iron";
                                iena[4]=false;
                                iena[5]=false;
                                p.all_max_hp+=35;
                                p.hp+=35;
                                if(def_ena[4]==0)
                                {
                                    p.all_max_hp+=15;
                                    p.hp+=15;
                                }
                                armor_shop();
                            }
                        }
                        else
                        {
                            buy_false("money");
                        }
                    }break;

                    case 3:
                    {
                        if(i6.enabled==false) {ena_false(1); goto Breastplate;}

                        if(i7.cost<=p.money)
                        {
                            string b7;
                            buy_want("breastplate");
                            cin>>b7;
                            if((b7=="y")||(b7=="Y"))
                            {
                                p.money-=i7.cost;
                                p.breastplate="diamond";
                                iena[4]=false;
                                iena[5]=false;
                                iena[6]=false;
                                p.all_max_hp+=50;
                                p.hp+=50;
                                if(def_ena[6]==0)
                                {
                                    p.all_max_hp+=20;
                                    p.hp+=20;
                                }
                                armor_shop();
                            }
                        }
                        else
                        {
                            buy_false("money");
                        }
                    }break;

                    case 4:
                    {
                        if(i8.enabled==false) {ena_false(1); goto Breastplate;}

                        if(i8.cost<=p.money)
                        {
                            string b8;
                            buy_want("breastplate");
                            cin>>b8;
                            if((b8=="y")||(b8=="Y"))
                            {
                                p.money-=i8.cost;
                                p.breastplate="platinum";
                                iena[4]=false;
                                iena[5]=false;
                                iena[6]=false;
                                iena[7]=false;
                                p.all_max_hp+=70;
                                p.hp+=70;
                                if(def_ena[8]==0)
                                {
                                    p.all_max_hp+=25;
                                    p.hp+=25;
                                }
                                armor_shop();
                            }
                        }
                        else
                        {
                            buy_false("money");
                        }
                    }break;


                case 5:
                    {
                        armor_shop();
                    }
                }
            }
            }break;
        case 3:
            {
            short helmets_c;

            for(;;)
            {
                Helmet:

                cls();
                c1=142; col1();
                cout<<"Helmets";

                c1=142; col1();
                cout<<"                             Your money: "<<p.money<<endl;

                c1=143; col1(); //white
                cout<<"-----------------"<<endl;

                Item i9(10,"leather","These helmet add you 10 hp"," helmet",iena[8]);
                c1=128; col1();
                cout<<"1. ";  i9.show();

                Item i10(20,"iron","These helmet add you 15 hp","    helmet",iena[9]);
                c1=128; col1();
                cout<<"2. ";  i10.show();

                Item i11(30,"diamond","These helmet add you 25 hp"," helmet",iena[10]);
                c1=128; col1();
                cout<<"3. ";  i11.show();

                Item i12(40,"platinum","These helmet add you 35 hp","helmet",iena[11]);
                c1=128; col1();
                cout<<"4. ";  i12.show();

                c1=140; col1();
                cout<<"5. Exit"<<endl;

                c1=143; col1(); //white
                cout<<"-----------------"<<endl;

                c1=142; col1();
                cout<<"Choose the number:";
                cin>>helmets_c;
                if( !cin )
                {
                    cin.clear();//error control
                    cin.sync();
                }

                switch(helmets_c)
                {
                case 1:
                    {
                        if(i9.enabled==false) {ena_false(1); goto Helmet;}

                        if(i9.cost<=p.money)
                        {
                            string b9;
                            buy_want("helmet");
                            cin>>b9;
                            if((b9=="y")||(b9=="Y"))
                            {
                                p.money-=i9.cost;
                                p.helmet="leather";
                                iena[8]=false;
                                p.all_max_hp+=10;
                                p.hp+=10;
                                if(def_ena[2]==0)
                                {
                                    p.all_max_hp+=10;
                                    p.hp+=10;
                                }
                                armor_shop();
                            }
                        }
                        else
                        {
                            buy_false("money");
                        }
                    }break;

                case 2:
                    {
                        if(i10.enabled==false) {ena_false(1); goto Helmet;}

                        if(i10.cost<=p.money)
                        {
                            string b10;
                            buy_want("helmet");
                            cin>>b10;
                            if((b10=="y")||(b10=="Y"))
                            {
                                p.money-=i10.cost;
                                p.helmet="iron";
                                iena[8]=false;
                                iena[9]=false;
                                p.all_max_hp+=15;
                                p.hp+=15;
                                if(def_ena[4]==0)
                                {
                                    p.all_max_hp+=15;
                                    p.hp+=15;
                                }
                                armor_shop();
                            }
                        }
                        else
                        {
                            buy_false("money");
                        }
                    }break;

                    case 3:
                    {
                        if(i11.enabled==false) {ena_false(1); goto Helmet;}

                        if(i11.cost<=p.money)
                        {
                            string b11;
                            buy_want("helmet");
                            cin>>b11;
                            if((b11=="y")||(b11=="Y"))
                            {
                                p.money-=i11.cost;
                                p.helmet="diamond";
                                iena[8]=false;
                                iena[9]=false;
                                iena[10]=false;
                                p.all_max_hp+=25;
                                p.hp+=25;
                                if(def_ena[6]==0)
                                {
                                    p.all_max_hp+=20;
                                    p.hp+=20;
                                }
                                armor_shop();
                            }
                        }
                        else
                        {
                            buy_false("money");
                        }
                    }break;

                    case 4:
                    {
                        if(i12.enabled==false) {ena_false(1); goto Helmet;}

                        if(i12.cost<=p.money)
                        {
                            string b12;
                            buy_want("helmet");
                            cin>>b12;
                            if((b12=="y")||(b12=="Y"))
                            {
                                p.money-=i12.cost;
                                p.helmet="platinum";
                                iena[8]=false;
                                iena[9]=false;
                                iena[10]=false;
                                iena[11]=false;
                                p.all_max_hp+=35;
                                p.hp+=35;
                                if(def_ena[8]==0)
                                {
                                    p.all_max_hp+=25;
                                    p.hp+=25;
                                }
                                armor_shop();
                            }
                        }
                        else
                        {
                            buy_false("money");
                        }
                    }break;


                case 5:
                    {
                        armor_shop();
                    }
                }
            }
        case 4:
            {
                city();
            }

        default:
            {
               c1=140; col1();
               cout<<endl<<"This option does not exist!"<<endl;
               Sleep(1000);
                }
            }
        }
    }
}
void buy_want(string type)
{
    cls();
    c1=128; col1();
    cout<<"Do you want buy this "<<type<<"?"<<endl<<endl;
    c1=129; col1();
    cout<<"Write "; c1=138; col1(); cout<<"y";
    c1=129; col1(); cout<<" if you want, or "; c1=140; col1();
    cout<<"n"; c1=129; col1(); cout<<" if you don't want: ";
}

void buy_false(string type)
{
    c1=140; col1();
    cout<<"You don't have enough "<<type<<"!";
    Sleep(1000);
}

void ena_false(short version)
{
    c1=140; col1();
    if(version==1)cout<<"This item has been bought!";
    else if(version==2)cout<<"This skill has been bought!";
    else if(version==3)cout<<"This skill isn't enabled!";
    Sleep(1000);
}
void weapon_shop()
{
    for(;;)
    {
        cls();

        c1=142; col1();
        cout<<"WEAPON SHOP:"<<endl;
        c1=143; col1();

        cout<<"-----------------------------------------------------------"<<endl;
        c1=137; col1();
        cout<<"You have:                             ";
        c1=142; col1();
        cout<<"Your money: "<<p.money<<endl;
        c1=143; col1();
        cout<<"-----------------"<<endl;
        c1=138; col1();
        cout<<"Sword:  ";
        c1=128; col1();
        cout<<p.sword<<endl;
        c1=143; col1();
        cout<<"-----------------"<<endl<<endl;

        c1=142; col1();
        cout<<"Shop:"<<endl;
        c1=143; col1();
        cout<<"-----------------"<<endl;

        c1=128; col1(); cout<<"1. ";
        Item s1(20,"stone    ","It asks 15 dp.","sword",sena[0]);
        s1.show();

        c1=128; col1(); cout<<"2. ";
        Item s2(50,"iron     ","It asks 25 dp.","sword",sena[1]);
        s2.show();

        c1=128; col1(); cout<<"3. ";
        Item s3(90,"diamond  ","It asks 40 dp.","sword",sena[2]);
        s3.show();

        c1=128; col1(); cout<<"4. ";
        Item s4(140,"platinium","It asks 55 dp.","sword",sena[3]);
        s4.show();

        c1=140; col1();
        cout<<"5.exit"<<endl;

        c1=143; col1();
        cout<<"-----------------"<<endl;
        c1=142; col1();
        cout<<"Choose the number:";

        short weapon_c;
        cin>>weapon_c;

        switch(weapon_c)
        {
        case 1:
             {
                if(s1.enabled==false) {ena_false(1); weapon_shop();}

                if(s1.cost<=p.money)
                {
                    string a1;
                    buy_want("sword");
                    cin>>a1;
                    if((a1=="y")||(a1=="Y"))
                    {
                        p.money-=s1.cost;
                        p.sword="stone";
                        sena[0]=false;
                        weapon_shop();
                    }
                }
                else
                {
                    buy_false("money");
                }
            }break;

        case 2:
            {
                if(s2.enabled==false) {ena_false(1); weapon_shop();}

                if(s2.cost<=p.money)
                {
                    string a2;
                    buy_want("sword");
                    cin>>a2;
                    if((a2=="y")||(a2=="Y"))
                    {
                        p.money-=s2.cost;
                        p.sword="iron";
                        sena[0]=false;
                        sena[1]=false;
                        if(ata_ena[6]==0)p.raw_damage_dealt+=30;
                        weapon_shop();
                    }
                }
                else
                {
                    buy_false("money");
                }
            }break;

        case 3:
            {
                if(s3.enabled==false) {ena_false(1); weapon_shop();}

                if(s3.cost<=p.money)
                {
                    string a3;
                    buy_want("sword");
                    cin>>a3;
                    if((a3=="y")||(a3=="Y"))
                    {
                        p.money-=s3.cost;
                        p.sword="diamond";
                        sena[0]=false;
                        sena[1]=false;
                        sena[2]=false;
                        weapon_shop();
                    }
                }
                else
                {
                    buy_false("money");
                }
            }break;
        case 4:
            {
                if(s4.enabled==false) {ena_false(1); weapon_shop();}

                if(s4.cost<=p.money)
                {
                    string a4;
                    buy_want("sword");
                    cin>>a4;
                    if((a4=="y")||(a4=="Y"))
                    {
                        p.money-=s4.cost;
                        p.sword="platinum";
                        sena[0]=false;
                        sena[1]=false;
                        sena[2]=false;
                        sena[3]=false;
                        if(ata_ena[10]==0)p.raw_damage_dealt+=20;
                        weapon_shop();
                    }
                }
                else
                {
                    buy_false("money");
                }
            }break;
        case 5:
            {
                city();
            }
        default:
            {
                c1=140; col1();
                cout<<endl<<"This option does not exist!"<<endl;
                Sleep(1000);
            }
        }
    }
}

void character_development()
{
    Interfac cd(4,true,"CHARACTER DEVELOPMENT  ",142,true,"Atack tree",140,
                "Defense tree",137,"Character statistics",139,"exit",142,"",0,"",0,"",0,"",0,
                false,false,false,true,0,0,0,0,p.talent_coin);
    cd.show_menu();

    switch(cd.menu_c)
    {
        case 1: atack_tree();       break;
        case 2: defense_tree();     break;
        case 3: character_stats();  break;
        case 4: city();             break;
        default:
        {
            c1=140; col1();
            cout<<endl<<"This option does not exist!"<<endl;
            Sleep(1000);
            character_development();
        }
    }
}

void atack_tree()
{
    cls(); c1=142; col1();
    cout<<"ATACK TREE   ";
    c1=139; col1();
    cout<<"talent coins: "<<p.talent_coin<<endl;
    c1=143; col1();
    cout<<"-----------------------------------------------------------"<<endl;
    ///skills positions
    Skill to_damage1(1,p.talent_coin,"+10 to damage","0",ata_ena[0],20,3,1);
    to_damage1.show();

    Skill to_combo1(2,p.talent_coin,"+5% chance to combo","0",ata_ena[1],5,5,1);
    to_combo1.show();

    Skill to_damage2(3,p.talent_coin,"+10 to damage","0",ata_ena[2],35,5);
    to_damage2.show();

    Skill to_combo2(4,p.talent_coin,"+10% chance to combo","0",ata_ena[3],5,7);
    to_combo2.show();

    Skill to_damage3(5,p.talent_coin,"+10 to damage","+20 to wooden sword",ata_ena[4],35,7);
    to_damage3.show();

    Skill to_combo3(6,p.talent_coin,"+5% chance to combo","+10 to stone sword",ata_ena[5],5,10);
    to_combo3.show();

    Skill to_damage4(7,p.talent_coin,"+10 to damage","+30 to iron sword",ata_ena[6],35,10,3);
    to_damage4.show();

    Skill to_combo4(8,p.talent_coin,"+5% chance to combo","0",ata_ena[7],5,13);
    to_combo4.show();

    Skill to_damage5(9,p.talent_coin,"+10 to damage","0",ata_ena[8],35,13);
    to_damage5.show();

    Skill to_combo5(10,p.talent_coin,"+5% chance to combo","+10 to diamond sword",ata_ena[9],5,15,3);
    to_combo5.show();

    Skill to_damage6(11,p.talent_coin,"+15 to damage","+20 to platinum sword",ata_ena[10],35,15,4);
    to_damage6.show();

    Skill final_ata(12,p.talent_coin,"+35 to damage","+10% chance to combo",ata_ena[11],20,18,5);
    final_ata.show();

    c1=140; col1();
    cout<<endl<<endl<<"                   0.exit"<<endl;

    c1=142; col1();
    cout<<"-----------------------------------------------------------"<<endl;

    short ata_c;
    c1=129; col1();
    cout<<"Choose the number:";
    cin>>ata_c;

    string ata;

    switch(ata_c)
    {
        case 0: character_development(); break;
        case 1:
            {
                if(to_damage1.enabled==0) ena_false(2);
                else if(to_damage1.enabled==2) ena_false(3);
                else
                {
                    if(p.talent_coin<to_damage1.cost) buy_false("talent coins");
                    else
                    {
                        buy_want("skill");
                        cin>>ata;
                        if(ata=="y"||ata=="Y")
                        {
                            p.talent_coin-=to_damage1.cost;
                            ata_ena[0]=0;
                            ata_ena[1]=1;
                            ata_ena[2]=1;
                            p.raw_damage_dealt+=10;
                        }
                    }
                }
                atack_tree();
            }break;
        case 2:
            {
                if(to_combo1.enabled==0) ena_false(2);
                else if(to_combo1.enabled==2) ena_false(3);
                else
                {
                    if(p.talent_coin<to_combo1.cost) buy_false("talent coins");
                    else
                    {
                        buy_want("skill");
                        cin>>ata;
                        if(ata=="y"||ata=="Y")
                        {
                            p.talent_coin-=to_combo1.cost;
                            ata_ena[1]=0;
                            ata_ena[3]=1;
                            p.combo_chance+=5;
                        }
                    }
                }
                atack_tree();
            }break;
        case 3:
            {
                if(to_damage2.enabled==0) ena_false(2);
                else if(to_damage2.enabled==2) ena_false(3);
                else
                {
                    if(p.talent_coin<to_damage2.cost) buy_false("talent coins");
                    else
                    {
                        buy_want("skill");
                        cin>>ata;
                        if(ata=="y"||ata=="Y")
                        {
                            p.talent_coin-=to_damage2.cost;
                            ata_ena[2]=0;
                            ata_ena[4]=1;
                            p.raw_damage_dealt+=10;
                        }
                    }
                }
                atack_tree();
            }break;
        case 4:
            {
                if(to_combo2.enabled==0) ena_false(2);
                else if(to_combo2.enabled==2) ena_false(3);
                else
                {
                    if(p.talent_coin<to_combo2.cost) buy_false("talent coins");
                    else
                    {
                        buy_want("skill");
                        cin>>ata;
                        if(ata=="y"||ata=="Y")
                        {
                            p.talent_coin-=to_combo2.cost;
                            ata_ena[3]=0;
                            ata_ena[5]=1;
                            p.combo_chance+=10;
                        }
                    }
                }
                atack_tree();
            }break;
        case 5:
            {
                if(to_damage3.enabled==0) ena_false(2);
                else if(to_damage3.enabled==2) ena_false(3);
                else
                {
                    if(p.talent_coin<to_damage3.cost) buy_false("talent coins");
                    else
                    {
                        buy_want("skill");
                        cin>>ata;
                        if(ata=="y"||ata=="Y")
                        {
                            p.talent_coin-=to_damage3.cost;
                            ata_ena[4]=0;
                            ata_ena[6]=1;
                            p.raw_damage_dealt+=10;
                            if(p.sword=="wooden")p.raw_damage_dealt+=20;
                        }
                    }
                }
                atack_tree();
            }break;
        case 6:
            {
                if(to_combo3.enabled==0) ena_false(2);
                else if(to_combo3.enabled==2) ena_false(3);
                else
                {
                    if(p.talent_coin<to_combo3.cost) buy_false("talent coins");
                    else
                    {
                        buy_want("skill");
                        cin>>ata;
                        if(ata=="y"||ata=="Y")
                        {
                            p.talent_coin-=to_combo3.cost;
                            ata_ena[5]=0;
                            ata_ena[7]=1;
                            p.combo_chance+=5;///and to stone sword +10
                        }
                    }
                }
                atack_tree();
            }break;
        case 7:
            {
                if(to_damage4.enabled==0) ena_false(2);
                else if(to_damage4.enabled==2) ena_false(3);
                else
                {
                    if(p.talent_coin<to_damage4.cost) buy_false("talent coins");
                    else
                    {
                        buy_want("skill");
                        cin>>ata;
                        if(ata=="y"||ata=="Y")
                        {
                            p.talent_coin-=to_damage4.cost;
                            ata_ena[6]=0;
                            ata_ena[8]=1;
                            p.raw_damage_dealt+=10;
                            if(p.sword=="iron")p.raw_damage_dealt+=30;
                        }
                    }
                }
                atack_tree();
            }break;
        case 8:
            {
                if(to_combo4.enabled==0) ena_false(2);
                else if(to_combo4.enabled==2) ena_false(3);
                else
                {
                    if(p.talent_coin<to_combo4.cost) buy_false("talent coins");
                    else
                    {
                        buy_want("skill");
                        cin>>ata;
                        if(ata=="y"||ata=="Y")
                        {
                            p.talent_coin-=to_combo4.cost;
                            ata_ena[7]=0;
                            ata_ena[9]=1;
                            p.combo_chance+=5;
                        }
                    }
                }
                atack_tree();
            }break;
        case 9:
            {
                if(to_damage5.enabled==0) ena_false(2);
                else if(to_damage5.enabled==2) ena_false(3);
                else
                {
                    if(p.talent_coin<to_damage5.cost) buy_false("talent coins");
                    else
                    {
                        buy_want("skill");
                        cin>>ata;
                        if(ata=="y"||ata=="Y")
                        {
                            p.talent_coin-=to_damage5.cost;
                            ata_ena[8]=0;
                            ata_ena[10]=1;
                            p.raw_damage_dealt+=10;
                        }
                    }
                }
                atack_tree();
            }break;
        case 10:
            {
                if(to_combo5.enabled==0) ena_false(2);
                else if(to_combo5.enabled==2) ena_false(3);
                else
                {
                    if(p.talent_coin<to_combo5.cost) buy_false("talent coins");
                    else
                    {
                        buy_want("skill");
                        cin>>ata;
                        if(ata=="y"||ata=="Y")
                        {
                            p.talent_coin-=to_combo5.cost;
                            ata_ena[9]=0;
                            if(ata_ena[11]==2)ata_ena[11]=1;
                            p.combo_chance+=5;///and to diamond sword +10
                        }
                    }
                }
                atack_tree();
            }break;
        case 11:
            {
                if(to_damage6.enabled==0) ena_false(2);
                else if(to_damage6.enabled==2) ena_false(3);
                else
                {
                    if(p.talent_coin<to_damage6.cost) buy_false("talent coins");
                    else
                    {
                        buy_want("skill");
                        cin>>ata;
                        if(ata=="y"||ata=="Y")
                        {
                            p.talent_coin-=to_damage6.cost;
                            ata_ena[10]=0;
                            if(ata_ena[11]==2)ata_ena[11]=1;
                            p.raw_damage_dealt+=15;
                            if(p.sword=="platinum")p.raw_damage_dealt+=20;
                        }
                    }
                }
                atack_tree();
            }break;
        case 12:
            {
                if(final_ata.enabled==0) ena_false(2);
                else if(final_ata.enabled==2) ena_false(3);
                else
                {
                    if(p.talent_coin<final_ata.cost) buy_false("talent coins");
                    else
                    {
                        buy_want("skill");
                        cin>>ata;
                        if(ata=="y"||ata=="Y")
                        {
                            p.talent_coin-=final_ata.cost;
                            ata_ena[11]=0;
                            p.raw_damage_dealt+=35;
                            p.combo_chance+=10;
                        }
                    }
                }
                atack_tree();
            }break;
    }

}

void defense_tree()
{
    cls(); c1=142; col1();
    cout<<"ATACK TREE   ";
    c1=139; col1();
    cout<<"talent coins: "<<p.talent_coin<<endl;
    c1=143; col1();
    cout<<"-----------------------------------------------------------"<<endl;
    ///skills positions
    Skill defend1(1,p.talent_coin,"+10 to max hp","0",def_ena[0],20,3,1,137);
    defend1.show();

    Skill defend2(2,p.talent_coin,"+20 to max hp","0",def_ena[1],5,5,2,137);
    defend2.show();

    Skill defend3(3,p.talent_coin,"+10 hp to one","leather item",def_ena[2],35,5,2,137);
    defend3.show();

    Skill defend4(4,p.talent_coin,"+10 to max hp","0",def_ena[3],5,8,2,137);
    defend4.show();

    Skill defend5(5,p.talent_coin,"+15 hp to one","iron item",def_ena[4],35,8,2,137);
    defend5.show();

    Skill defend6(6,p.talent_coin,"+20 to max hp","0",def_ena[5],5,11,2,137);
    defend6.show();

    Skill defend7(7,p.talent_coin,"+20 hp to one","diamond item",def_ena[6],35,11,3,137);
    defend7.show();

    Skill defend8(8,p.talent_coin,"+20 to max hp","0",def_ena[7],5,14,2,137);
    defend8.show();

    Skill defend9(9,p.talent_coin,"+25 hp to one","platinum item",def_ena[8],35,14,4,137);
    defend9.show();

    Skill defend10(10,p.talent_coin,"+50 to max hp","0",def_ena[9],20,17,4,137);
    defend10.show();

    c1=140; col1();
    cout<<endl<<endl<<"                   0.exit"<<endl;

    c1=142; col1();
    cout<<"-----------------------------------------------------------"<<endl;

    short def_c;
    c1=129; col1();
    cout<<"Choose the number:";
    cin>>def_c;

    string def;

    switch(def_c)
    {
        case 0: character_development(); break;
        case 1:
            {
                if(defend1.enabled==0) ena_false(2);
                else if(defend1.enabled==2) ena_false(3);
                else
                {
                    if(p.talent_coin<defend1.cost) buy_false("talent coins");
                    else
                    {
                        buy_want("skill");
                        cin>>def;
                        if(def=="y"||def=="Y")
                        {
                            p.talent_coin-=defend1.cost;
                            def_ena[0]=0;
                            def_ena[1]=1;
                            def_ena[2]=1;
                            p.max_hp+=10;
                            p.all_max_hp+=10;
                            p.hp+=10;
                        }
                    }
                }
            }break;
        case 2:
            {
                if(defend2.enabled==0) ena_false(2);
                else if(defend2.enabled==2) ena_false(3);
                else
                {
                    if(p.talent_coin<defend2.cost) buy_false("talent coins");
                    else
                    {
                        buy_want("skill");
                        cin>>def;
                        if(def=="y"||def=="Y")
                        {
                            p.talent_coin-=defend2.cost;
                            def_ena[1]=0;
                            def_ena[3]=1;
                            p.max_hp+=20;
                            p.all_max_hp+=20;
                            p.hp+=20;
                        }
                    }
                }
            }break;
        case 3:
            {
                if(defend3.enabled==0) ena_false(2);
                else if(defend3.enabled==2) ena_false(3);
                else
                {
                    if(p.talent_coin<defend3.cost) buy_false("talent coins");
                    else
                    {
                        buy_want("skill");
                        cin>>def;
                        if(def=="y"||def=="Y")
                        {
                            p.talent_coin-=defend3.cost;
                            def_ena[2]=0;
                            def_ena[4]=1;
                            if(p.boots=="leather"){p.all_max_hp+=10;p.hp+=10;}
                            if(p.breastplate=="leather"){p.all_max_hp+=10;p.hp+=10;}
                            if(p.helmet=="leather"){p.all_max_hp+=10;p.hp+=10;}
                        }
                    }
                }
            }break;
        case 4:
            {
                if(defend4.enabled==0) ena_false(2);
                else if(defend4.enabled==2) ena_false(3);
                else
                {
                    if(p.talent_coin<defend4.cost) buy_false("talent coins");
                    else
                    {
                        buy_want("skill");
                        cin>>def;
                        if(def=="y"||def=="Y")
                        {
                            p.talent_coin-=defend4.cost;
                            def_ena[3]=0;
                            def_ena[5]=1;
                            p.max_hp+=10;
                            p.all_max_hp+=10;
                            p.hp+=10;
                        }
                    }
                }
            }break;
        case 5:
            {
                if(defend5.enabled==0) ena_false(2);
                else if(defend5.enabled==2) ena_false(3);
                else
                {
                    if(p.talent_coin<defend5.cost) buy_false("talent coins");
                    else
                    {
                        buy_want("skill");
                        cin>>def;
                        if(def=="y"||def=="Y")
                        {
                            p.talent_coin-=defend5.cost;
                            def_ena[4]=0;
                            def_ena[6]=1;
                            if(p.boots=="iron"){p.all_max_hp+=15;p.hp+=15;}
                            if(p.breastplate=="iron"){p.all_max_hp+=15;p.hp+=15;}
                            if(p.helmet=="iron"){p.all_max_hp+=15;p.hp+=15;}
                        }
                    }
                }
            }break;
        case 6:
            {
                if(defend6.enabled==0) ena_false(2);
                else if(defend6.enabled==2) ena_false(3);
                else
                {
                    if(p.talent_coin<defend6.cost) buy_false("talent coins");
                    else
                    {
                        buy_want("skill");
                        cin>>def;
                        if(def=="y"||def=="Y")
                        {
                            p.talent_coin-=defend6.cost;
                            def_ena[5]=0;
                            def_ena[7]=1;
                            p.max_hp+=20;
                            p.all_max_hp+=20;
                            p.hp+=20;
                        }
                    }
                }
            }break;
        case 7:
            {
                if(defend7.enabled==0) ena_false(2);
                else if(defend7.enabled==2) ena_false(3);
                else
                {
                    if(p.talent_coin<defend7.cost) buy_false("talent coins");
                    else
                    {
                        buy_want("skill");
                        cin>>def;
                        if(def=="y"||def=="Y")
                        {
                            p.talent_coin-=defend7.cost;
                            def_ena[6]=0;
                            def_ena[8]=1;
                            if(p.boots=="diamond"){p.all_max_hp+=20;p.hp+=20;}
                            if(p.breastplate=="diamond"){p.all_max_hp+=20;p.hp+=20;}
                            if(p.helmet=="diamond"){p.all_max_hp+=20;p.hp+=20;}
                        }
                    }
                }
            }break;
        case 8:
            {
                if(defend8.enabled==0) ena_false(2);
                else if(defend8.enabled==2) ena_false(3);
                else
                {
                    if(p.talent_coin<defend8.cost) buy_false("talent coins");
                    else
                    {
                        buy_want("skill");
                        cin>>def;
                        if(def=="y"||def=="Y")
                        {
                            p.talent_coin-=defend8.cost;
                            def_ena[7]=0;
                            if(def_ena[9]==2)def_ena[9]=1;
                            p.max_hp+=20;
                            p.all_max_hp+=20;
                            p.hp+=20;
                        }
                    }
                }
            }break;
        case 9:
            {
                if(defend9.enabled==0) ena_false(2);
                else if(defend9.enabled==2) ena_false(3);
                else
                {
                    if(p.talent_coin<defend9.cost) buy_false("talent coins");
                    else
                    {
                        buy_want("skill");
                        cin>>def;
                        if(def=="y"||def=="Y")
                        {
                            p.talent_coin-=defend9.cost;
                            def_ena[8]=0;
                            if(def_ena[9]==2)def_ena[9]=1;
                            if(p.boots=="platinum"){p.all_max_hp+=25;p.hp+=25;}
                            if(p.breastplate=="platinum"){p.all_max_hp+=25;p.hp+=25;}
                            if(p.helmet=="platinum"){p.all_max_hp+=25;p.hp+=25;}
                        }
                    }
                }
            }break;
        case 10:
            {
                if(defend10.enabled==0) ena_false(2);
                else if(defend10.enabled==2) ena_false(3);
                else
                {
                    if(p.talent_coin<defend10.cost) buy_false("talent coins");
                    else
                    {
                        buy_want("skill");
                        cin>>def;
                        if(def=="y"||def=="Y")
                        {
                            p.talent_coin-=defend10.cost;
                            def_ena[9]=0;
                            p.max_hp+=50;
                            p.all_max_hp+=50;
                            p.hp+=50;
                        }
                    }
                }
            }break;
        }defense_tree();
}

void character_stats()
{
    short all_damage=p.raw_damage_dealt;
    short all_combo=p.combo_chance;

    cls();
    c1=142; col1();
    cout<<"CHARACTER STATISTICS:"<<endl;
    c1=143; col1();
    cout<<"-----------------------------------------------------------"<<endl;

    c1=142; col1();
    cout<<"money: "<<p.money;

    c1=139; col1();
    gotoxy1(20,3);
    cout<<"talent coins: "<<p.talent_coin;

    c1=138; col1();
    gotoxy1(40,3);
    cout<<"fights played: "<<p.number_of_fights_played<<endl;

    c1=140; col1();
    cout<<"health: ";
    if(p.hp>=p.max_hp)cout<<p.max_hp<<"/"<<p.max_hp;
    else cout<<p.hp<<"/"<<p.all_max_hp;

    c1=137; col1();
    gotoxy1(20,4);
    cout<<"raw damage: "<<p.raw_damage_dealt;

    c1=132; col1();
    gotoxy1(40,4);
    cout<<"combo chance: "<<p.combo_chance<<"%"<<endl;

    c1=143; col1();
    cout<<"-----------------------------------------------------------"<<endl;
    c1=142; col1();
    cout<<"EQUIPMENT STATISTICS:"<<endl;
    c1=143; col1();
    cout<<"-----------------------------------------------------------"<<endl;

    //sword//
    c1=128; col1();
    cout<<"sword: ";
    c1=137; col1();
    cout<<p.sword;
    c1=132; col1();
    gotoxy1(25,8);
    cout<<"sword damage: ";
    c1=142; col1();
    if     (p.sword=="wooden")    {cout<<"8";all_damage+=8;}
    else if(p.sword=="stone")     {cout<<"15";all_damage+=15;}
    else if(p.sword=="iron")      {cout<<"25";all_damage+=25;}
    else if(p.sword=="diamond")   {cout<<"40";all_damage+=40;}
    else if(p.sword=="hangman")   {cout<<"20";all_damage+=20;}
    else                          {cout<<"55";all_damage+=55;}

    ///aditional damage | sword + skill tree
    c1=139; col1();
    if((p.sword=="wooden")&&(ata_ena[4]==0))    {cout<<"+20";all_damage+=20;}
    if((p.sword=="iron")&&(ata_ena[6]==0))      {cout<<"+30";all_damage+=30;}
    if((p.sword=="platinum")&&(ata_ena[10]==0)) {cout<<"+20";all_damage+=20;}
    ///aditional combo chance | sword + skill tree
    if((p.sword=="stone")&&(ata_ena[5]==0))     {cout<<" +10% combo chance";all_combo+=10;}
    if((p.sword=="diamond")&&(ata_ena[9]==0))   {cout<<" +10% combo chance";all_combo+=10;}

    cout<<endl;

    //boots//
    c1=128; col1();
    cout<<"boots: ";
    c1=137; col1();
    cout<<p.boots;
    c1=132; col1();
    gotoxy1(25,9);
    cout<<"boots hp: ";
    c1=142; col1();
    if     (p.boots=="leather") cout<<"10";
    else if(p.boots=="iron")    cout<<"20";
    else if(p.boots=="diamond") cout<<"30";
    else if(p.boots=="platinum")cout<<"40";
    else                        cout<<"0";

    ///aditional max hp
    c1=139; col1();
    if((p.boots=="leather")&&(def_ena[2]==0))   cout<<"+10";
    if((p.boots=="iron")&&(def_ena[4]==0))      cout<<"+15";
    if((p.boots=="diamond")&&(def_ena[6]==0))   cout<<"+20";
    if((p.boots=="platinum")&&(def_ena[8]==0))  cout<<"+25";
    cout<<endl;

    //breastplate//
    c1=128; col1();
    cout<<"breastplate: ";
    c1=137; col1();
    cout<<p.breastplate;
    c1=132; col1();
    gotoxy1(25,10);
    cout<<"breastplate hp: ";
    c1=142; col1();
    if     (p.breastplate=="leather") cout<<"20";
    else if(p.breastplate=="iron")    cout<<"35";
    else if(p.breastplate=="diamond") cout<<"50";
    else if(p.breastplate=="platinum")cout<<"70";
    else                        cout<<"0";

    ///aditional max hp
    c1=139; col1();
    if((p.breastplate=="leather")&&(def_ena[2]==0))   cout<<"+10";
    if((p.breastplate=="iron")&&(def_ena[4]==0))      cout<<"+15";
    if((p.breastplate=="diamond")&&(def_ena[6]==0))   cout<<"+20";
    if((p.breastplate=="platinum")&&(def_ena[8]==0))  cout<<"+25";
    cout<<endl;

    //helmet//
    c1=128; col1();
    cout<<"helmet: ";
    c1=137; col1();
    cout<<p.helmet;
    c1=132; col1();
    gotoxy1(25,11);
    cout<<"helmet hp: ";
    c1=142; col1();
    if     (p.helmet=="leather") cout<<"10";
    else if(p.helmet=="iron")    cout<<"15";
    else if(p.helmet=="diamond") cout<<"25";
    else if(p.helmet=="platinum")cout<<"35";
    else                        cout<<"0";

    ///aditional max hp
    c1=139; col1();
    if((p.helmet=="leather")&&(def_ena[2]==0))   cout<<"+10";
    if((p.helmet=="iron")&&(def_ena[4]==0))      cout<<"+15";
    if((p.helmet=="diamond")&&(def_ena[6]==0))   cout<<"+20";
    if((p.helmet=="platinum")&&(def_ena[8]==0))  cout<<"+25";

    c1=143; col1();
    cout<<endl<<"-----------------------------------------------------------"<<endl;
    c1=142; col1();
    cout<<"ALL STATISTICS:"<<endl;
    c1=143; col1();
    cout<<"-----------------------------------------------------------"<<endl;

    ///health
    c1=140; col1();
    cout<<"health: "<<p.hp<<"/"<<p.all_max_hp;

    ///damage
    c1=137; col1();
    cout<<"  damage: "<<all_damage;

    ///combo
    c1=132; col1();
    cout<<"  combo: "<<all_combo<<"%";

    getchar();getchar();
    character_development();
}

void tavern()
{
    Interfac t(2,true,"TAVERN",142,true,"sleep - cost:5",138,"exit",140,"",0,"",0,"",0,
               "",0,"",0,"",0,true,true,false,false,p.money,p.hp,p.all_max_hp);
               t.show_menu();

    switch(t.menu_c)
    {
    case 1:
        {
            if(p.hp==p.all_max_hp)
            {
                c1=138; col1();
                cout<<endl<<"You have max hp!";
                Sleep(1000); tavern();
            }
            if(p.money<5)
            {
                buy_false("money");
                tavern();
            }
            else
            {
                p.money-=5;
                p.hp=p.all_max_hp;
                tavern();
            }
        }break;
    case 2: city(); break;
    default:
        {
            c1=140; col1();
            cout<<endl<<"This option does not exist!"<<endl;
            Sleep(1000); tavern();
        }
    }
}

void fight()
{
    string opo_name;
    short opo_hp,opo_max_hp,opo_damage,opo_combo_chance;

    if(p.number_of_fights_played==0)
    {opo_name="Mark"; opo_hp=50; opo_max_hp=50; opo_damage=5; opo_combo_chance=1;}

    else if(p.number_of_fights_played==1)
    {opo_name="John"; opo_hp=55; opo_max_hp=55; opo_damage=3; opo_combo_chance=70;}

    else if(p.number_of_fights_played==2)
    {opo_name="Joffrey"; opo_hp=60; opo_max_hp=60; opo_damage=7; opo_combo_chance=5;}

    else if(p.number_of_fights_played==3)
    {opo_name="Gilly"; opo_hp=60; opo_max_hp=60; opo_damage=8; opo_combo_chance=15;}

    else if(p.number_of_fights_played==4)
    {opo_name="Gendry"; opo_hp=65; opo_max_hp=65; opo_damage=5; opo_combo_chance=25;}

    else if(p.number_of_fights_played==5)
    {opo_name="Shae"; opo_hp=70; opo_max_hp=70; opo_damage=4; opo_combo_chance=55;}

    else if(p.number_of_fights_played==6)
    {opo_name="Eddison"; opo_hp=80; opo_max_hp=80; opo_damage=9; opo_combo_chance=7;}

    else if(p.number_of_fights_played==7)
    {opo_name="Berengar"; opo_hp=85; opo_max_hp=85; opo_damage=10; opo_combo_chance=4;}

    else if(p.number_of_fights_played==8)
    {opo_name="Markus"; opo_hp=95; opo_max_hp=95; opo_damage=7; opo_combo_chance=30;}

    else if(p.number_of_fights_played==9)
    {opo_name="Klara"; opo_hp=105; opo_max_hp=105; opo_damage=6; opo_combo_chance=25;}

    else if(p.number_of_fights_played==10)
    {opo_name="Hangman (BOSS)"; opo_hp=140; opo_max_hp=140; opo_damage=10; opo_combo_chance=15;}

    else if(p.number_of_fights_played==11)
    {opo_name="Chaja"; opo_hp=115; opo_max_hp=115; opo_damage=8; opo_combo_chance=12;}

    else if(p.number_of_fights_played==12)
    {opo_name="Gregory"; opo_hp=125; opo_max_hp=125; opo_damage=8; opo_combo_chance=10;}

    else if(p.number_of_fights_played==13)
    {opo_name="Maya"; opo_hp=130; opo_max_hp=130; opo_damage=7; opo_combo_chance=30;}

    else if(p.number_of_fights_played==14)
    {opo_name="Gea"; opo_hp=135; opo_max_hp=135; opo_damage=8; opo_combo_chance=15;}

    else if(p.number_of_fights_played==15)
    {opo_name="Liam"; opo_hp=135; opo_max_hp=135; opo_damage=9; opo_combo_chance=7;}

    else if(p.number_of_fights_played==16)
    {opo_name="Emma"; opo_hp=140; opo_max_hp=140; opo_damage=8; opo_combo_chance=20;}

    else if(p.number_of_fights_played==17)
    {opo_name="Oliver"; opo_hp=125; opo_max_hp=40; opo_damage=12; opo_combo_chance=25;}

    else if(p.number_of_fights_played==18)
    {opo_name="Lukas"; opo_hp=140; opo_max_hp=140; opo_damage=7; opo_combo_chance=50;}

    else if(p.number_of_fights_played==19)
    {opo_name="Anna"; opo_hp=155; opo_max_hp=155; opo_damage=6; opo_combo_chance=10;}

    else if(p.number_of_fights_played==20)
    {opo_name="Scypion (BOSS)"; opo_hp=200; opo_max_hp=200; opo_damage=8; opo_combo_chance=75;}

    else if(p.number_of_fights_played==21)
    {opo_name="Hana"; opo_hp=160; opo_max_hp=160; opo_damage=10; opo_combo_chance=10;}

    else if(p.number_of_fights_played==22)
    {opo_name="Drey"; opo_hp=175; opo_max_hp=175; opo_damage=9; opo_combo_chance=20;}

    else if(p.number_of_fights_played==23)
    {opo_name="Walt"; opo_hp=170; opo_max_hp=170; opo_damage=12; opo_combo_chance=5;}

    else if(p.number_of_fights_played==24)
    {opo_name="Titus"; opo_hp=180; opo_max_hp=180; opo_damage=11; opo_combo_chance=25;}

    else if(p.number_of_fights_played==25)
    {opo_name="Peppa"; opo_hp=180; opo_max_hp=180; opo_damage=9; opo_combo_chance=50;}

    else if(p.number_of_fights_played==26)
    {opo_name="Miran"; opo_hp=185; opo_max_hp=185; opo_damage=13; opo_combo_chance=5;}

    else if(p.number_of_fights_played==27)
    {opo_name="Keyla"; opo_hp=175; opo_max_hp=175; opo_damage=12; opo_combo_chance=35;}

    else if(p.number_of_fights_played==28)
    {opo_name="Kaven"; opo_hp=195; opo_max_hp=195; opo_damage=10; opo_combo_chance=20;}

    else if(p.number_of_fights_played==29)
    {opo_name="Tilo"; opo_hp=205; opo_max_hp=205; opo_damage=7; opo_combo_chance=70;}

    else if(p.number_of_fights_played==30)
    {opo_name="Atreus (BOSS)"; opo_hp=100; opo_max_hp=100; opo_damage=25; opo_combo_chance=20;}

    Opponent o(opo_name,opo_hp,opo_max_hp,opo_damage,opo_combo_chance);

    o.show();
    short opo_show_c;
    cin>>opo_show_c;

    switch(opo_show_c)
    {
        case 0: city(); break;
        case 1:
            {
                if(p.number_of_fights_played==10)
                {
                    BOSS1();
                    if(dialogue_value==1)o.damage+=1;
                    else if(dialogue_value==2)o.damage+=3;
                }
                if(p.number_of_fights_played==20){BOSS2();}
Match:
                int sword,hit_number=0,op_hit_number=0;
                bool first_attack=true;
                clock_t match_start, match_stop; double match_time;
                int match_damage=0,opponent_damage=0,combo_number=0,incorrect_sentences=0;

                match_start=clock();

                while((p.hp>0)&&(o.hp>0))
                {
                    ///draw
                    c1=140; col1();
                    cls();
                    cout<<"YOUR HP: "<<p.hp<<"/"<<p.max_hp;
                    c1=128; col1(); cout<<" | ";
                    c1=132; col1(); cout<<"OPPONENT HP: "<<o.hp<<"/"<<o.max_hp;
                    gotoxy1(15,2);
                    sword_color(o.sword);
                    cout<<"|";
                    gotoxy1(13,3); c1=128; col1();
                    cout<<"O ";
                    sword_color(o.sword);
                    cout<<"|";
                    gotoxy1(12,4);
                    c1=128; col1();
                    cout<<"-:-";
                    c1=132; col1();
                    cout<<"{";
                    gotoxy1(13,5);
                    c1=128; col1();
                    cout<<"|"<<endl<<endl;

                    ///sword damage
                    if((p.sword=="wooden")&&(ata_ena[4]!=0)) sword=8;
                    else if((p.sword=="wooden")&&(ata_ena[4]==0)) sword=28;

                    else if(p.sword=="stone") sword=15;

                    else if((p.sword=="iron")&&(ata_ena[6]!=0)) sword=25;
                    else if((p.sword=="iron")&&(ata_ena[6]==0)) sword=55;

                    else if(p.sword=="diamond") sword=40;

                    else if((p.sword=="platinum")&&(ata_ena[10]!=0)) sword=55;
                    else if((p.sword=="platinum")&&(ata_ena[10]==0)) sword=75;

                    else if(p.sword=="hangman") sword=20;

                    ///enter sentence and time
                    string player_sentence;
                    clock_t start, stop; double time;
                    sentences();

                    c1=142; col1();
                    cout<<"Rewrite this: "<<sentence<<endl<<"              ";
Attack:
                    start=clock();
                    getline(cin,player_sentence);
                    stop = clock();
                    time = (double)(stop-start) / CLOCKS_PER_SEC;

                    if(first_attack==true){first_attack=false;goto Attack;}

                    hit_number++;

                    ///check sentence, damage count
                    if(player_sentence==sentence)
                    {
                        short raw_damag;

                        if(time>average_write_time)
                        {
                            if(time<=average_write_time*1.2)
                                raw_damag = average_write_time*0.9;
                            if((time>average_write_time*1.2)&&(time<=average_write_time*1.6))
                                raw_damag = average_write_time*0.7;
                            if((time>average_write_time*1.6)&&(time<=average_write_time*2))
                                raw_damag = average_write_time*0.5;
                            if((time>average_write_time*2)&&(time<=average_write_time*2.5))
                                raw_damag = average_write_time*0.3;
                            if(time>average_write_time*2.5)
                                raw_damag = average_write_time*0.2;
                        }
                        else if(time<average_write_time)
                        {
                            if(time>=average_write_time*0.9)
                                raw_damag = average_write_time*1.1;
                            if((time<average_write_time*0.9)&&(time>=average_write_time*0.7))
                                raw_damag = average_write_time*1.2;
                            if((time<average_write_time*0.7)&&(time>=average_write_time*0.5))
                                raw_damag = average_write_time*1.4;
                            if((time<average_write_time*0.5)&&(time>=average_write_time*0.3))
                                raw_damag = average_write_time*1.6;
                            if(time<average_write_time*0.3)
                                raw_damag = average_write_time*2;
                        }
                        else{raw_damag = average_write_time;}

                        short help;
                        help=((raw_damag*p.raw_damage_dealt*sword)/50);

                        ///combo count
                        bool combo=false;
                        short combo_help;

                        combo_help=rand()%100+1;
                        if(combo_help<=p.combo_chance)
                        {combo=true; help=help*2; combo_number++;}

                        c1=132; col1();
                        if(combo)cout<<endl<<"You have combo and took "<<help<<" hp your opponent"<<endl;
                        else cout<<endl<<"You took "<<help<<" hp your opponent!"<<endl;
                        Sleep(2000);
                        o.hp-=help;

                        match_damage+=help;
                    }
                    else if(player_sentence=="exit1234") city();//emergency exit
                    else
                    {
                        c1=140; col1();
                        cout<<endl<<"The wrong sentence was entered!"<<endl;
                        incorrect_sentences++;
                        Sleep(1000);
                    }

                    if(o.hp<1)break;
                    ///opponent damage
                    short opponent_damage1;
                    opponent_damage1=o.hit(o.damage,o.sword,o.combo_chance,o.name);
                    p.hp-=opponent_damage1;
                    opponent_damage+=opponent_damage1;
                    op_hit_number++;
                }

                match_stop=clock();
                match_time = (match_stop-match_start) / CLOCKS_PER_SEC;

                int match_money,match_exp=0;

                if(o.hp<=0)//player win
                {
                    ///money with match
                    if(p.number_of_fights_played<5){p.money+=7;match_money=7;}
                    if(p.number_of_fights_played<10&&p.number_of_fights_played>=5)  {p.money+=8;match_money=8;}
                    if(p.number_of_fights_played<15&&p.number_of_fights_played>=10) {p.money+=11;match_money=11;}
                    if(p.number_of_fights_played<20&&p.number_of_fights_played>=15) {p.money+=15;match_money=15;}
                    if(p.number_of_fights_played<25&&p.number_of_fights_played>=20) {p.money+=18;match_money=18;}
                    if(p.number_of_fights_played<30&&p.number_of_fights_played>=25) {p.money+=20;match_money=20;}
                    if(p.number_of_fights_played<35&&p.number_of_fights_played>=30) {p.money+=21;match_money=21;}
                    if(p.number_of_fights_played<40&&p.number_of_fights_played>=35) {p.money+=23;match_money=23;}
                    if(p.number_of_fights_played<45&&p.number_of_fights_played>=40) {p.money+=25;match_money=25;}
                    if(p.number_of_fights_played<50&&p.number_of_fights_played>=45) {p.money+=26;match_money=26;}
                    if(p.number_of_fights_played<55&&p.number_of_fights_played>=50) {p.money+=27;match_money=27;}
                    if(p.number_of_fights_played<60&&p.number_of_fights_played>=55) {p.money+=28;match_money=28;}
                    if(p.number_of_fights_played<65&&p.number_of_fights_played>=60) {p.money+=30;match_money=30;}
                    if(p.number_of_fights_played<70&&p.number_of_fights_played>=65) {p.money+=31;match_money=31;}
                    if(p.number_of_fights_played<75&&p.number_of_fights_played>=70) {p.money+=33;match_money=33;}
                    if(p.number_of_fights_played<80&&p.number_of_fights_played>=75) {p.money+=35;match_money=35;}
                    if(p.number_of_fights_played<85&&p.number_of_fights_played>=80) {p.money+=36;match_money=36;}
                    if(p.number_of_fights_played<90&&p.number_of_fights_played>=85) {p.money+=37;match_money=37;}
                    if(p.number_of_fights_played<95&&p.number_of_fights_played>=90) {p.money+=38;match_money=38;}
                    if(p.number_of_fights_played<100&&p.number_of_fights_played>=95){p.money+=40;match_money=40;}

                    ///exp with match
                    if((p.number_of_fights_played==5)||(p.number_of_fights_played==10)||
                      (p.number_of_fights_played==15)||(p.number_of_fights_played==20)||
                      (p.number_of_fights_played==25)||(p.number_of_fights_played==30)||
                      (p.number_of_fights_played==35)||(p.number_of_fights_played==40)||
                      (p.number_of_fights_played==45)||(p.number_of_fights_played==50)||
                      (p.number_of_fights_played==55)||(p.number_of_fights_played==60)||
                      (p.number_of_fights_played==65)||(p.number_of_fights_played==70)||
                      (p.number_of_fights_played==75)||(p.number_of_fights_played==80)||
                      (p.number_of_fights_played==85)||(p.number_of_fights_played==90)||
                      (p.number_of_fights_played==95)||(p.number_of_fights_played==99))
                        {p.talent_coin+=2;match_exp=2;}

                    if(p.number_of_fights_played==20)
                    {
                        BOSS2_2();
                        if(dialogue_value==1)match_money+=30;
                    }

                    ///statistics screen
                    cls();
                    c1=142; col1();
                    cout<<"MATCH STATISTICS:"<<endl;
                    c1=143; col1();
                    cout<<"-----------------------------------------------------------";
                    getchar();
                    c1=129; col1(); cout<<"\a- Match time: "<<match_time<<" seconds";
                    getchar();
                    c1=143; col1(); cout<<"-----------------"<<endl;
                    c1=138; col1(); cout<<"\a- You needed "<<hit_number<<" blows to defeat your opponent."<<endl;
                    c1=139; col1(); cout<<"- Your damage average: "<<match_damage/hit_number<<endl;
                    c1=142; col1(); cout<<"- You had "<<combo_number<<" combos."<<endl;
                    c1=132; col1(); cout<<"- incorrect sentences: "<<incorrect_sentences;
                    getchar();
                    c1=143; col1(); cout<<"-----------------"<<endl;
                    c1=137; col1(); cout<<"\a- Opponent took you "<<opponent_damage<<" hp."<<endl;
                    c1=140; col1(); if(op_hit_number>0) cout<<"- Opponent damage average "<<opponent_damage/op_hit_number<<endl;
                    else cout<<"- Opponent damage average 0"<<endl;
                    c1=142; col1(); cout<<"- Opponent had "<<o.combo_number<<" combos."<<endl;
                    getchar();

                    ///rewards screen
                    c1=138; col1();
                    cout<<"MATCH REWARDS:"<<endl;
                    c1=143; col1();
                    cout<<"-----------------------------------------------------------";
                    getchar();
                    c1=142; col1();cout<<"\a- earned MONEY: "<<match_money;
                    getchar();
                    c1=139; col1();cout<<"\a- got EXP: "<<match_exp;
                    getchar();
                    if(p.number_of_fights_played==20)
                    {
                        c1=138; col1();cout<<"\a- got DAMAGE points: 1"<<endl;
                        getchar();
                    }
                    if(p.number_of_fights_played==10) special_item("hangman sword","damage: 20");

                    p.number_of_fights_played++;
                    city();
                }
                else
                {
                    cls();
                    c1=142; col1();
                cout<<"  _______  _______  __   __  _______    _______  __   __  _______  ______   "<<endl
                    <<" |       ||   _   ||  |_|  ||       |  |       ||  | |  ||       ||    _ |  "<<endl
                    <<" |    ___||  |_|  ||       ||    ___|  |   _   ||  |_|  ||    ___||   | ||  "<<endl
                    <<" |   | __ |       ||       ||   |___   |  | |  ||       ||   |___ |   |_||_ "<<endl
                    <<" |   ||  ||       ||       ||    ___|  |  |_|  ||       ||    ___||    __  |"<<endl
                    <<" |   |_| ||   _   || ||_|| ||   |___   |       | |     | |   |___ |   |  | |"<<endl
                    <<" |_______||__| |__||_|   |_||_______|  |_______|  |___|  |_______||___|  |_|"<<endl;
                    Sleep(1000);
                    c1=143; col1();
                    cout<<endl<<"click enter!";
                    getchar();
                    game_over=true;
                    main();
                }
            }
        default:
            {
                c1=140; col1(); //red
                cout<<"This option does not exist!";
                Sleep(1000);
                fight();
            }
    }

}

void sentences()
{
    uint_fast8_t lot;
    lot=rand()%57;

    if(lot==0)
    {
        sentence="It's a simple task.";
        average_write_time=8;
    }
    else if(lot==1)
    {
        sentence="Wololo Wololo WOLOLO!";
        average_write_time=10;
    }
    else if(lot==2)
    {
        sentence="It's not working.";
        average_write_time=7;
    }
    else if(lot==3)
    {
        sentence="You know nothing Jon Snow.";
        average_write_time=9;
    }
    else if(lot==4)
    {
        sentence="-Hi I'm new here. -Aaa";
        average_write_time=10;
    }
    else if(lot==5)
    {
        sentence="It is only with the heart that one can see rightly.";
        average_write_time=20;
    }
    else if(lot==6)
    {
        sentence="What is essential is invisible to the eye.";
        average_write_time=17;
    }
    else if(lot==7)
    {
        sentence="-The sleeper be with you. -Aaaa";
        average_write_time=12;
    }
    else if(lot==8)
    {
        sentence="It is such a mysterious place, the land of tears.";
        average_write_time=18;
    }
    else if(lot==9)
    {
        sentence="Grown-ups never understand anything by themselves";
        average_write_time=18;
    }
    else if(lot==10)
    {
        sentence="it is tiresome for children to be always explaining things to them.";
        average_write_time=21;
    }
    else if(lot==11)
    {
        sentence="But eyes are blind. You have to look with the heart.";
        average_write_time=18;
    }
    else if(lot==12)
    {
        sentence="Only the children know what they are looking for.";
        average_write_time=16;
    }
    else if(lot==13)
    {
        sentence="One only understands the things that one tames.";
        average_write_time=15;
    }
    else if(lot==14)
    {
        sentence="What a queer planet!";
        average_write_time=6;
    }
    else if(lot==15)
    {
        sentence="No one is ever satisfied where he is.";
        average_write_time=12;
    }
    else if(lot==16)
    {
        sentence="It is far more difficult to judge oneself than others.";
        average_write_time=19;
    }
    else if(lot==17)
    {
        sentence="If you succeed in judging yourself correctly";
        average_write_time=17;
    }
    else if(lot==18)
    {
        sentence="then you are truly a man of wisdom.";
        average_write_time=12;
    }
    else if(lot==19)
    {
        sentence="If you love a flower which happens to be on a star";
        average_write_time=18;
    }
    else if(lot==20)
    {
        sentence="it is sweet at night to gaze at the sky.";
        average_write_time=15;
    }
    else if(lot==21)
    {
        sentence="All the stars are a riot of flowers.";
        average_write_time=14;
    }
    else if(lot==22)
    {
        sentence="One runs the risk of weeping a little";
        average_write_time=14;
    }
    else if(lot==23)
    {
        sentence="Ready to work.";
        average_write_time=6;
    }
    else if(lot==24)
    {
        sentence="Yes, milord?";
        average_write_time=5;
    }
    else if(lot==25)
    {
        sentence="If you want.";
        average_write_time=6;
    }
    else if(lot==26)
    {
        sentence="That's it. I'm dead.";
        average_write_time=9;
    }
    else if(lot==27)
    {
        sentence="You're the king!? Well, I didn't vote for you.";
        average_write_time=16;
    }
    else if(lot==28)
    {
        sentence="We found a witch! May we burn her?";
        average_write_time=13;
    }
    else if(lot==29)
    {
        sentence="Help! Help! I'm being repressed!";
        average_write_time=12;
    }
    else if(lot==30)
    {
        sentence="A horse kicked me once. It hurt.";
        average_write_time=12;
    }
    else if(lot==31)
    {
        sentence="D'oh!";
        average_write_time=4;
    }
    else if(lot==32)
    {
        sentence="What do you need?";
        average_write_time=8;
    }
    else if(lot==33)
    {
        sentence="For Lordaeron!";
        average_write_time=6;
    }
    else if(lot==34)
    {
        sentence="Tis only a flesh wound!";
        average_write_time=10;
    }
    else if(lot==35)
    {
        sentence="I've got the beast in my sights.";
        average_write_time=12;
    }
    else if(lot==36)
    {
        sentence="Shoot to kill!";
        average_write_time=8;
    }
    else if(lot==37)
    {
        sentence="Where's me drink?";
        average_write_time=9;
    }
    else if(lot==38)
    {
        sentence="Don't shoot shoot shoot that thing at me.";
        average_write_time=16;
    }
    else if(lot==39)
    {
        sentence="I await your command.";
        average_write_time=10;
    }
    else if(lot==40)
    {
        sentence="For honor, for freedom!";
        average_write_time=10;
    }
    else if(lot==41)
    {
        sentence="My favorite color is blue! No, yellow!";
        average_write_time=15;
    }
    else if(lot==42)
    {
        sentence="I come to cleanse this land.";
        average_write_time=12;
    }
    else if(lot==43)
    {
        sentence="For the memory of Quel'thalas!";
        average_write_time=13;
    }
    else if(lot==44)
    {
        sentence="I smell magic in the air.";
        average_write_time=12;
    }
    else if(lot==45)
    {
        sentence="What's the flight plan?";
        average_write_time=10;
    }
    else if(lot==46)
    {
        sentence="This bomb's for you!";
        average_write_time=10;
    }
    else if(lot==47)
    {
        sentence="Someone gave me the bird!";
        average_write_time=11;
    }
    else if(lot==48)
    {
        sentence="An elf would have thought of something better.";
        average_write_time=16;
    }
    else if(lot==49)
    {
        sentence="Probability of success: Zero.";
        average_write_time=11;
    }
    else if(lot==50)
    {
        sentence="Look, I'm an engineer, my time is valuable.";
        average_write_time=15;
    }
    else if(lot==51)
    {
        sentence="I'll do my best!";
        average_write_time=10;
    }
    else if(lot==52)
    {
        sentence="I live to serve all believers.";
        average_write_time=12;
    }
    else if(lot==53)
    {
        sentence="Strike with great vengeance!";
        average_write_time=11;
    }
    else if(lot==54)
    {
        sentence="I want to be your sledge hammer!";
        average_write_time=13;
    }
    else if(lot==55)
    {
        sentence="Any fish and chip shops around here?";
        average_write_time=13;
    }
    else if(lot==56)
    {
        sentence="Let's get pissed!";
        average_write_time=10;
    }
}

void BOSS1()
{
    Story boss1_s1(2,1," You've come too far."," I'll crush you with one hand",
                "","","","","","","","","","","Hangman:","Hangman:");
                boss1_s1.show_story();
    Interfac boss1_c1(3,false,"0",1,0,"I don't think so.",138,"Fuck you!",138,
                        "Say nothing",138);
boss1:
                boss1_c1.show_menu();
                cout<<endl;
    switch(boss1_c1.menu_c)
    {
    case 1:
        {
            Story boss1_s2(2,0," Fight Bastard!"," your opponent is pissed and he got 1 extra damage points",
                           "","","","","","","","","","","Hangman:","Game: ");
                    boss1_s2.show_story();
                    dialogue_value=1;
        }break;
    case 2:
        {
            Story boss1_s3(2,0," Aaaa!"," your opponent is pissed and he got 3 extra damage points",
                           "","","","","","","","","","","Hangman:","Game: ");
                    boss1_s3.show_story();
                    dialogue_value=2;
        }break;
    case 3:dialogue_value=0;break;
    default:
        {
            c1=140; col1(); //red
            cout<<"This option does not exist!"<<endl;
            Sleep(1000);
            goto boss1;
        }break;
    }
}

void BOSS2()
{
    Story boss2_s1(2,1," You've won so many fights."," With me, however, it will not be easy for you.",
                   "","","","","","","","","","","Scypion:","Scypion:");
            boss2_s1.show_story();
}

void BOSS2_2()
{
    Story boss2_s2(2,1," Save me!"," I will give you a lot of money!",
                   "","","","","","","","","","","Scypion:","Scypion:");
            boss2_s2.show_story();

    Interfac boss2_c1(2,false,"0",1,0,"Give me your money and never show up again.",138,"Die!",138);
boss2:      boss2_c1.show_menu();
    cout<<endl;

    switch(boss2_c1.menu_c)
    {
    case 1:
        {
            Story boss2_s3(2,0," Here it is."," You got 30 money.",
                   "","","","","","","","","","","Scypion:","Game:");
            boss2_s3.show_story();
            p.money+=30;
            dialogue_value=1;
        }break;
    case 2:
        {
            Story boss2_s4(2,0," Be cursed!"," You got 1 damage point.",
                   "","","","","","","","","","","Scypion:","Game:");
            boss2_s4.show_story();
            p.raw_damage_dealt++;
            dialogue_value=2;
        }break;
    default:
        {
            c1=140; col1(); //red
            cout<<"This option does not exist!"<<endl;
            Sleep(1000);
            goto boss2;
        }break;
    }
}

void special_item(string item,string specification)
{
    cls(); c1=137; col1();
    cout<<"Boss dropped SPECIAL ITEM:"<<endl;

    c1=142; col1(); cout<<item<<": ";
    c1=139; col1(); cout<<specification<<endl<<endl;

    c1=142; col1();
    if(p.number_of_fights_played==10)
    {
        cout<<"Your sword"<<": ";
        c1=139; col1();
        if(p.sword=="wooden")cout<<"damage: 8"<<endl<<endl;
        else if(p.sword=="stone")cout<<"damage: 15"<<endl<<endl;
        else if(p.sword=="iron")cout<<"damage: 25"<<endl<<endl;
        else if(p.sword=="diamond")cout<<"damage: 40"<<endl<<endl;
        else if(p.sword=="platinum")cout<<"damage: 55"<<endl<<endl;
    }
    c1=138; col1(); cout<<"Do you want take this item? Enter Y or N:";
    string c;
    cin>>c;

    if((c=="Y")||(c=="y"))
    {
        if(p.number_of_fights_played==10)
        {
            p.sword="hangman";
        }
    }
    else if((c=="N")||(c=="n")){}
    else
    {
        c1=140; col1(); //red
        cout<<"This option does not exist!"<<endl;
        Sleep(1000);
        if(p.number_of_fights_played==10)special_item("hangman sword","damage: 20");
    }
}

void cheats()
{
    string cheat;

    c1=128; col1();
    cout<<":";
    cin>>cheat;

    if(cheat=="0")city();
    else if(cheat=="money")
    {
        short money_n;
        cout<<":";
        cin>>money_n;
        if((money_n>=0)&&(money_n<100000))p.money=money_n;

    }
    else if(cheat=="man")
    {
        cout<<"money"<<endl;
        cout<<"hp"<<endl;
        cout<<"maxhp"<<endl;
        cout<<"exp"<<endl;
        cout<<"skills0"<<endl;
        cout<<"match"<<endl;
        cout<<"attribute(combo,damage,maxhp)"<<endl;
        getchar();getchar();
    }
    else if(cheat=="hp")
    {
        short hp_n;
        cout<<":";
        cin>>hp_n;
        if((hp_n>0)&&(hp_n<=p.max_hp))p.hp=hp_n;
    }
    else if(cheat=="maxhp")
    {
        p.hp=p.max_hp;
    }
    else if(cheat=="exp")
    {
        uint32_t exp_n;
        cout<<":";
        cin>>exp_n;
        if((exp_n>=0)&&(exp_n<1000))p.talent_coin=exp_n;
    }
    else if(cheat=="skills0")
    {
        for(int i=0;i<12;i++)
        {
        ata_ena[i+1]=2;
        def_ena[i+1]=2;
        }
        ata_ena[0]=1;
        def_ena[0]=1;
    }
    else if(cheat=="match")
    {
        int_fast8_t match_n;
        cout<<":";
        cin>>match_n;
        if((match_n<100)&&(match_n>=0))p.number_of_fights_played = match_n;

    }
    else if(cheat=="attribute(combo)")
    {
        int_fast8_t combo_n;
        cout<<":";
        cin>>combo_n;
        if((combo_n>=0)&&(combo_n<101))p.combo_chance=combo_n;
    }
    else if(cheat=="attribute(damage)")
    {
        int_fast16_t damage_n;
        cout<<":";
        cin>>damage_n;
        if((damage_n>0)&&(damage_n<1000))p.raw_damage_dealt=damage_n;
    }
    else if(cheat=="attribute(maxhp)")
    {
        int_fast16_t maxhp_n;
        cout<<":";
        cin>>maxhp_n;
        if((maxhp_n>0)&&(maxhp_n<1000))p.max_hp=maxhp_n;
        if(maxhp_n<p.hp) p.hp=maxhp_n;
    }
    city();
}

void exit_game()
{
    string exit_game_c;

    for(;;)
    {
        cls();
        c1=142; col1(); //yellow
        cout<<"Are you sure, that you want exit the game?"<<endl
        <<"If you haven't save the game, you will lose"<<endl<<"progress in the game."<<endl;
        c1=143; col1();
        cout<<"-----------------------------------------------------------"<<endl;
        c1=138; col1(); //green
        cout<<"y - yes"<<endl;
        c1=140; col1(); //red
        cout<<"n - no"<<endl;
        c1=143; col1();
        cout<<"-----------------------------------------------------------"<<endl;
        c1=137; col1(); //blue
        cout<<"Write y or n and confirm with ENTER: ";
        cin>>exit_game_c;

        if((exit_game_c=="y")||(exit_game_c=="Y")) main();
        else if((exit_game_c=="n")||(exit_game_c=="N")) city();
        else
        {
            c1=140; col1(); //red
            cout<<endl<<"This option does not exist!"<<endl;
            Sleep(1000);
        }
    }
}

void gotoxy1(short x,short y)
{
  COORD c;
  c.X=x-1;
  c.Y=y-1;
  SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),c);
}

void sword_color(string x)
{
    if(x=="wooden")  c1=132;
    if(x=="stone")   c1=135;
    if(x=="iron")    c1=143;
    if(x=="diamond") c1=139;
    if(x=="platinum")c1=131;
    col1();
}

void save_to_file()
{
    fstream file;
    file.open("save.txt",ios::out);

    file<<background_grey1<<endl;           //1
    file<<p.hp<<endl;                       //2
    file<<p.max_hp<<endl;                   //3
    file<<p.all_max_hp<<endl;               //4
    file<<p.raw_damage_dealt<<endl;         //5
    file<<p.combo_chance<<endl;             //6
    file<<p.boots<<endl;                    //7
    file<<p.breastplate<<endl;              //8
    file<<p.helmet<<endl;                   //9
    file<<p.sword<<endl;                    //10
    file<<p.money<<endl;                    //11
    file<<p.number_of_fights_played<<endl;  //12
    file<<p.talent_coin<<endl;              //13
    file<<iena[0]<<endl;                    //14
    file<<iena[1]<<endl;                    //15
    file<<iena[2]<<endl;                    //16
    file<<iena[3]<<endl;                    //17
    file<<iena[4]<<endl;                    //18
    file<<iena[5]<<endl;                    //19
    file<<iena[6]<<endl;                    //20
    file<<iena[7]<<endl;                    //21
    file<<iena[8]<<endl;                    //22
    file<<iena[9]<<endl;                    //23
    file<<iena[10]<<endl;                   //24
    file<<iena[11]<<endl;                   //25
    file<<sena[0]<<endl;                    //26
    file<<sena[1]<<endl;                    //27
    file<<sena[2]<<endl;                    //28
    file<<sena[3]<<endl;                    //29
    file<<ata_ena[0]<<endl;                 //30
    file<<ata_ena[1]<<endl;                 //31
    file<<ata_ena[2]<<endl;                 //32
    file<<ata_ena[3]<<endl;                 //33
    file<<ata_ena[4]<<endl;                 //34
    file<<ata_ena[5]<<endl;                 //35
    file<<ata_ena[6]<<endl;                 //36
    file<<ata_ena[7]<<endl;                 //37
    file<<ata_ena[8]<<endl;                 //38
    file<<ata_ena[9]<<endl;                 //39
    file<<ata_ena[10]<<endl;                //40
    file<<ata_ena[11]<<endl;                //41
    file<<def_ena[0]<<endl;                 //42
    file<<def_ena[1]<<endl;                 //43
    file<<def_ena[2]<<endl;                 //44
    file<<def_ena[3]<<endl;                 //45
    file<<def_ena[4]<<endl;                 //46
    file<<def_ena[5]<<endl;                 //47
    file<<def_ena[6]<<endl;                 //48
    file<<def_ena[7]<<endl;                 //49
    file<<def_ena[8]<<endl;                 //50
    file<<def_ena[9]<<endl;                 //51
    file<<def_ena[10]<<endl;                //52
    file<<def_ena[11]<<endl;                //53

    file.close();

    city();
}

void load_from_file()
{
    fstream file;
    file.open("save.txt",ios::in);

    if(file.good()==false)
    {
        c1=140; col1();
        cout<<"Save is not exist";
        Sleep(1000);
        main();
    }

    string line;
    int line_number=1;

    while(getline(file,line))
    {
        switch(line_number)
        {
            case 2:  p.hp = atoi(line.c_str()); break;
            case 3:  p.max_hp = atoi(line.c_str()); break;
            case 4:  p.all_max_hp = atoi(line.c_str()); break;
            case 5:  p.raw_damage_dealt = atoi(line.c_str()); break;
            case 6:  p.combo_chance = atoi(line.c_str()); break;
            case 7:  p.boots = line; break;
            case 8:  p.breastplate = line; break;
            case 9:  p.helmet = line; break;
            case 10: p.sword = line; break;
            case 11: p.money = atoi(line.c_str()); break;
            case 12: p.number_of_fights_played = atoi(line.c_str()); break;
            case 13: p.talent_coin = atoi(line.c_str()); break;
            case 14: iena[0] = atoi(line.c_str()); break;
            case 15: iena[1] = atoi(line.c_str()); break;
            case 16: iena[2] = atoi(line.c_str()); break;
            case 17: iena[3] = atoi(line.c_str()); break;
            case 18: iena[4] = atoi(line.c_str()); break;
            case 19: iena[5] = atoi(line.c_str()); break;
            case 20: iena[6] = atoi(line.c_str()); break;
            case 21: iena[7] = atoi(line.c_str()); break;
            case 22: iena[8] = atoi(line.c_str()); break;
            case 23: iena[9] = atoi(line.c_str()); break;
            case 24: iena[10] = atoi(line.c_str()); break;
            case 25: iena[11] = atoi(line.c_str()); break;
            case 26: sena[0] = atoi(line.c_str()); break;
            case 27: sena[1] = atoi(line.c_str()); break;
            case 28: sena[2] = atoi(line.c_str()); break;
            case 29: sena[3] = atoi(line.c_str()); break;
            case 30: ata_ena[0] = atoi(line.c_str()); break;
            case 31: ata_ena[1] = atoi(line.c_str()); break;
            case 32: ata_ena[2] = atoi(line.c_str()); break;
            case 33: ata_ena[3] = atoi(line.c_str()); break;
            case 34: ata_ena[4] = atoi(line.c_str()); break;
            case 35: ata_ena[5] = atoi(line.c_str()); break;
            case 36: ata_ena[6] = atoi(line.c_str()); break;
            case 37: ata_ena[7] = atoi(line.c_str()); break;
            case 38: ata_ena[8] = atoi(line.c_str()); break;
            case 39: ata_ena[9] = atoi(line.c_str()); break;
            case 40: ata_ena[10] = atoi(line.c_str()); break;
            case 41: ata_ena[11] = atoi(line.c_str()); break;
            case 42: def_ena[0] = atoi(line.c_str()); break;
            case 43: def_ena[1] = atoi(line.c_str()); break;
            case 44: def_ena[2] = atoi(line.c_str()); break;
            case 45: def_ena[3] = atoi(line.c_str()); break;
            case 46: def_ena[4] = atoi(line.c_str()); break;
            case 47: def_ena[5] = atoi(line.c_str()); break;
            case 48: def_ena[6] = atoi(line.c_str()); break;
            case 49: def_ena[7] = atoi(line.c_str()); break;
            case 50: def_ena[8] = atoi(line.c_str()); break;
            case 51: def_ena[9] = atoi(line.c_str()); break;
            case 52: def_ena[10] = atoi(line.c_str()); break;
            case 53: def_ena[11] = atoi(line.c_str()); break;
        }
        line_number++;
    }
    file.close();

    city();
}




