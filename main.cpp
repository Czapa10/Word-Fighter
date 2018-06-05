#include <iostream>
#include <windows.h>
#include <cstdlib>
#include <stdio.h>
#include "class.h"

using namespace std;

int c1;
bool iena[12],sena[4];
int ata_ena[12],def_ena[12];

void col1();
void cls();
void credits();
void new_game();
void city();
void armor_shop();
void buy_want();
void buy_false();
void ena_false();
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
void gotoxy1(int x,int y);
void sword_color(string x);

Player p;

int main()
{
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

    system("color 8f");

    Interfac i1(4,true,"                        WORD FIGHTER",142,true,"New game",
                138,"Continue",138,"Credits",139,"Exit",140);

    i1.show_menu();

        switch(i1.menu_c)
        {
            case 1: new_game();           break;
            case 2://{new_g=false; game();} break;
            case 3: credits();            break;
            case 4: exit(0);              break;
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

void new_game()
{
    Story s1(3,"You are condemned for arena.",
             "To free yourself you must win hundred fights in a row.",
             "Good Luck!");
    s1.show_story();

    city();
}

void city()
{
    int city_c;

    for(;;)
    {
        Interfac i(7,true,"CITY",142,true,"Armor shop",
                   138,"Weapon shop",138,"Character development",
                   138,"Tavern",142,"Fight",139,"Save",129,
                   "Exit",140,"",0,true,true,true,true,
                   p.money,p.hp,p.max_hp,100-p.number_of_fights_played,p.talent_coin);
        i.show_menu();

        switch(i.menu_c)
        {
            case 1: armor_shop(); break;
            case 2: weapon_shop(); break;
            case 3: character_development(); break;
            case 4: tavern(); break;
            case 5: fight(); break;
            case 6: //p.SaveToFile(); break;
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
    int help_money;
    int shop_c;

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
            int boots_c;

            for(;;)
            {
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
                        if(i1.enabled==false) ena_false();

                        if(i1.cost<=p.money)
                        {
                            string b1;
                            buy_want();
                            cin>>b1;
                            if(b1=="y")
                            {
                                p.money-=i1.cost;
                                p.boots="leather";
                                iena[0]=false;
                                armor_shop();
                            }
                        }
                        else
                        {
                            buy_false();
                        }
                    }break;

                case 2:
                    {
                        if(i2.enabled==false) ena_false();

                        if(i2.cost<=p.money)
                        {
                            string b2;
                            buy_want();
                            cin>>b2;
                            if(b2=="y")
                            {
                                p.money-=i2.cost;
                                p.boots="iron";
                                iena[0]=false;
                                iena[1]=false;
                                armor_shop();
                            }
                        }
                        else
                        {
                            buy_false();
                        }
                    }break;

                    case 3:
                    {
                        if(i3.enabled==false) ena_false();

                        if(i3.cost<=p.money)
                        {
                            string b3;
                            buy_want();
                            cin>>b3;
                            if(b3=="y")
                            {
                                p.money-=i3.cost;
                                p.boots="diamond";
                                iena[0]=false;
                                iena[1]=false;
                                iena[2]=false;
                                armor_shop();
                            }
                        }
                        else
                        {
                            buy_false();
                        }
                    }break;

                    case 4:
                    {
                        if(i4.enabled==false) ena_false();

                        if(i4.cost<=p.money)
                        {
                            string b4;
                            buy_want();
                            cin>>b4;
                            if(b4=="y")
                            {
                                p.money-=i4.cost;
                                p.boots="platinum";
                                iena[0]=false;
                                iena[1]=false;
                                iena[2]=false;
                                iena[3]=false;
                                armor_shop();
                            }
                        }
                        else
                        {
                            buy_false();
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
            int breastplate_c;

            for(;;)
            {
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
                        if(i5.enabled==false) ena_false();

                        if(i5.cost<=p.money)
                        {
                            string b5;
                            buy_want();
                            cin>>b5;
                            if(b5=="y")
                            {
                                p.money-=i5.cost;
                                p.breastplate="leather";
                                iena[4]=false;
                                armor_shop();
                            }
                        }
                        else
                        {
                            buy_false();
                        }
                    }break;

                case 2:
                    {
                        if(i6.enabled==false) ena_false();

                        if(i6.cost<=p.money)
                        {
                            string b6;
                            buy_want();
                            cin>>b6;
                            if(b6=="y")
                            {
                                p.money-=i6.cost;
                                p.breastplate="iron";
                                iena[4]=false;
                                iena[5]=false;
                                armor_shop();
                            }
                        }
                        else
                        {
                            buy_false();
                        }
                    }break;

                    case 3:
                    {
                        if(i6.enabled==false) ena_false();

                        if(i7.cost<=p.money)
                        {
                            string b7;
                            buy_want();
                            cin>>b7;
                            if(b7=="y")
                            {
                                p.money-=i7.cost;
                                p.breastplate="diamond";
                                iena[4]=false;
                                iena[5]=false;
                                iena[6]=false;
                                armor_shop();
                            }
                        }
                        else
                        {
                            buy_false();
                        }
                    }break;

                    case 4:
                    {
                        if(i8.enabled==false) ena_false();

                        if(i8.cost<=p.money)
                        {
                            string b8;
                            buy_want();
                            cin>>b8;
                            if(b8=="y")
                            {
                                p.money-=i8.cost;
                                p.breastplate="platinum";
                                iena[4]=false;
                                iena[5]=false;
                                iena[6]=false;
                                iena[7]=false;
                                armor_shop();
                            }
                        }
                        else
                        {
                            buy_false();
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
            int helmets_c;

            for(;;)
            {
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
                        if(i9.enabled==false) ena_false();

                        if(i9.cost<=p.money)
                        {
                            string b9;
                            buy_want();
                            cin>>b9;
                            if(b9=="y")
                            {
                                p.money-=i9.cost;
                                p.helmet="leather";
                                iena[8]=false;
                                armor_shop();
                            }
                        }
                        else
                        {
                            buy_false();
                        }
                    }break;

                case 2:
                    {
                        if(i10.enabled==false) ena_false();

                        if(i10.cost<=p.money)
                        {
                            string b10;
                            buy_want();
                            cin>>b10;
                            if(b10=="y")
                            {
                                p.money-=i10.cost;
                                p.helmet="iron";
                                iena[8]=false;
                                iena[9]=false;
                                armor_shop();
                            }
                        }
                        else
                        {
                            buy_false();
                        }
                    }break;

                    case 3:
                    {
                        if(i11.enabled==false) ena_false();

                        if(i11.cost<=p.money)
                        {
                            string b11;
                            buy_want();
                            cin>>b11;
                            if(b11=="y")
                            {
                                p.money-=i11.cost;
                                p.helmet="diamond";
                                iena[8]=false;
                                iena[9]=false;
                                iena[10]=false;
                                armor_shop();
                            }
                        }
                        else
                        {
                            buy_false();
                        }
                    }break;

                    case 4:
                    {
                        if(i12.enabled==false) ena_false();

                        if(i12.cost<=p.money)
                        {
                            string b12;
                            buy_want();
                            cin>>b12;
                            if(b12=="y")
                            {
                                p.money-=i12.cost;
                                p.helmet="platinum";
                                iena[8]=false;
                                iena[9]=false;
                                iena[10]=false;
                                iena[11]=false;
                                armor_shop();
                            }
                        }
                        else
                        {
                            buy_false();
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
void buy_want()
{
    cls();
    c1=128; col1();
    cout<<"Do you want buy this item?"<<endl<<endl;
    c1=129; col1();
    cout<<"Write "; c1=138; col1(); cout<<"y";
    c1=129; col1(); cout<<" if you want, or "; c1=140; col1();
    cout<<"n"; c1=129; col1(); cout<<" if you don't want: ";
}
void buy_want2()
{
    cls();
    c1=128; col1();
    cout<<"Do you want buy this item?"<<endl<<endl;
    c1=129; col1();
    cout<<"Write "; c1=138; col1(); cout<<"y";
    c1=129; col1(); cout<<" if you want, or "; c1=140; col1();
    cout<<"n"; c1=129; col1(); cout<<" if you don't want: ";
}

void buy_false()
{
    c1=140; col1();
    cout<<"You don't have enough money!";
    Sleep(1000);
}

void buy_false2()
{
    c1=140; col1();
    cout<<"You don't have enough talent coins!";
    Sleep(1000);
}

void ena_false()
{
    c1=140; col1();
    cout<<"This item has been bought!";
    Sleep(1000);
    armor_shop();
}
void ena_false2()
{
    c1=140; col1();
    cout<<"This item has been bought!";
    Sleep(1000);
    weapon_shop();
}
void ena_false3()
{
    c1=140; col1();
    cout<<"This skill has been bought!";
    Sleep(1000);

}
void ena_false4()
{
    c1=140; col1();
    cout<<"This skill isn't enabled!";
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

        int weapon_c;
        cin>>weapon_c;

        switch(weapon_c)
        {
        case 1:
             {
                if(s1.enabled==false) ena_false2();

                if(s1.cost<=p.money)
                {
                    string a1;
                    buy_want();
                    cin>>a1;
                    if(a1=="y")
                    {
                        p.money-=s1.cost;
                        p.sword="stone";
                        sena[0]=false;
                        weapon_shop();
                    }
                }
                else
                {
                    buy_false();
                }
            }break;

        case 2:
            {
                if(s2.enabled==false) ena_false2();

                if(s2.cost<=p.money)
                {
                    string a2;
                    buy_want();
                    cin>>a2;
                    if(a2=="y")
                    {
                        p.money-=s2.cost;
                        p.sword="iron";
                        sena[0]=false;
                        sena[1]=false;
                        weapon_shop();
                    }
                }
                else
                {
                    buy_false();
                }
            }break;

        case 3:
            {
                if(s3.enabled==false) ena_false2();

                if(s3.cost<=p.money)
                {
                    string a3;
                    buy_want();
                    cin>>a3;
                    if(a3=="y")
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
                    buy_false();
                }
            }break;
        case 4:
            {
                if(s4.enabled==false) ena_false2();

                if(s4.cost<=p.money)
                {
                    string a4;
                    buy_want();
                    cin>>a4;
                    if(a4=="y")
                    {
                        p.money-=s4.cost;
                        p.sword="platinum";
                        sena[0]=false;
                        sena[1]=false;
                        sena[2]=false;
                        sena[3]=false;
                        weapon_shop();
                    }
                }
                else
                {
                    buy_false();
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

    int ata_c;
    c1=129; col1();
    cout<<"Choose the number:";
    cin>>ata_c;

    string ata;

    switch(ata_c)
    {
        case 0: character_development(); break;
        case 1:
            {
                if(to_damage1.enabled==0) ena_false3();
                else if(to_damage1.enabled==2) ena_false4();
                else
                {
                    if(p.talent_coin<to_damage1.cost) buy_false2();
                    else
                    {
                        buy_want2();
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
                if(to_combo1.enabled==0) ena_false3();
                else if(to_combo1.enabled==2) ena_false4();
                else
                {
                    if(p.talent_coin<to_combo1.cost) buy_false2();
                    else
                    {
                        buy_want2();
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
                if(to_damage2.enabled==0) ena_false3();
                else if(to_damage2.enabled==2) ena_false4();
                else
                {
                    if(p.talent_coin<to_damage2.cost) buy_false2();
                    else
                    {
                        buy_want2();
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
                if(to_combo2.enabled==0) ena_false3();
                else if(to_combo2.enabled==2) ena_false4();
                else
                {
                    if(p.talent_coin<to_combo2.cost) buy_false2();
                    else
                    {
                        buy_want2();
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
                if(to_damage3.enabled==0) ena_false3();
                else if(to_damage3.enabled==2) ena_false4();
                else
                {
                    if(p.talent_coin<to_damage3.cost) buy_false2();
                    else
                    {
                        buy_want2();
                        cin>>ata;
                        if(ata=="y"||ata=="Y")
                        {
                            p.talent_coin-=to_damage3.cost;
                            ata_ena[4]=0;
                            ata_ena[6]=1;
                            p.raw_damage_dealt+=10;///and to wooden sword +20
                        }
                    }
                }
                atack_tree();
            }break;
        case 6:
            {
                if(to_combo3.enabled==0) ena_false3();
                else if(to_combo3.enabled==2) ena_false4();
                else
                {
                    if(p.talent_coin<to_combo3.cost) buy_false2();
                    else
                    {
                        buy_want2();
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
                if(to_damage4.enabled==0) ena_false3();
                else if(to_damage4.enabled==2) ena_false4();
                else
                {
                    if(p.talent_coin<to_damage4.cost) buy_false2();
                    else
                    {
                        buy_want2();
                        cin>>ata;
                        if(ata=="y"||ata=="Y")
                        {
                            p.talent_coin-=to_damage4.cost;
                            ata_ena[6]=0;
                            ata_ena[8]=1;
                            p.raw_damage_dealt+=10;///and to iron sword +30
                        }
                    }
                }
                atack_tree();
            }break;
        case 8:
            {
                if(to_combo4.enabled==0) ena_false3();
                else if(to_combo4.enabled==2) ena_false4();
                else
                {
                    if(p.talent_coin<to_combo4.cost) buy_false2();
                    else
                    {
                        buy_want2();
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
                if(to_damage5.enabled==0) ena_false3();
                else if(to_damage5.enabled==2) ena_false4();
                else
                {
                    if(p.talent_coin<to_damage5.cost) buy_false2();
                    else
                    {
                        buy_want2();
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
                if(to_combo5.enabled==0) ena_false3();
                else if(to_combo5.enabled==2) ena_false4();
                else
                {
                    if(p.talent_coin<to_combo5.cost) buy_false2();
                    else
                    {
                        buy_want2();
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
                if(to_damage6.enabled==0) ena_false3();
                else if(to_damage6.enabled==2) ena_false4();
                else
                {
                    if(p.talent_coin<to_damage6.cost) buy_false2();
                    else
                    {
                        buy_want2();
                        cin>>ata;
                        if(ata=="y"||ata=="Y")
                        {
                            p.talent_coin-=to_damage6.cost;
                            ata_ena[10]=0;
                            if(ata_ena[11]==2)ata_ena[11]=1;
                            p.raw_damage_dealt+=15;///and to platinum sword +25
                        }
                    }
                }
                atack_tree();
            }break;
        case 12:
            {
                if(final_ata.enabled==0) ena_false3();
                else if(final_ata.enabled==2) ena_false4();
                else
                {
                    if(p.talent_coin<final_ata.cost) buy_false2();
                    else
                    {
                        buy_want2();
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

    int def_c;
    c1=129; col1();
    cout<<"Choose the number:";
    cin>>def_c;

    string def;

    switch(def_c)
    {
        case 0: character_development(); break;
        case 1:
            {
                if(defend1.enabled==0) ena_false3();
                else if(defend1.enabled==2) ena_false4();
                else
                {
                    if(p.talent_coin<defend1.cost) buy_false2();
                    else
                    {
                        buy_want2();
                        cin>>def;
                        if(def=="y"||def=="Y")
                        {
                            p.talent_coin-=defend1.cost;
                            def_ena[0]=0;
                            def_ena[1]=1;
                            def_ena[2]=1;
                            p.max_hp+=10;
                            p.hp+=10;
                        }
                    }
                }
            }break;
        case 2:
            {
                if(defend2.enabled==0) ena_false3();
                else if(defend2.enabled==2) ena_false4();
                else
                {
                    if(p.talent_coin<defend2.cost) buy_false2();
                    else
                    {
                        buy_want2();
                        cin>>def;
                        if(def=="y"||def=="Y")
                        {
                            p.talent_coin-=defend2.cost;
                            def_ena[1]=0;
                            def_ena[3]=1;
                            p.max_hp+=20;
                            p.hp+=20;
                        }
                    }
                }
            }break;
        case 3:
            {
                if(defend3.enabled==0) ena_false3();
                else if(defend3.enabled==2) ena_false4();
                else
                {
                    if(p.talent_coin<defend3.cost) buy_false2();
                    else
                    {
                        buy_want2();
                        cin>>def;
                        if(def=="y"||def=="Y")
                        {
                            p.talent_coin-=defend3.cost;
                            def_ena[2]=0;
                            def_ena[4]=1;
                        }
                    }
                }
            }break;
        case 4:
            {
                if(defend4.enabled==0) ena_false3();
                else if(defend4.enabled==2) ena_false4();
                else
                {
                    if(p.talent_coin<defend4.cost) buy_false2();
                    else
                    {
                        buy_want2();
                        cin>>def;
                        if(def=="y"||def=="Y")
                        {
                            p.talent_coin-=defend4.cost;
                            def_ena[3]=0;
                            def_ena[5]=1;
                            p.max_hp+=10;
                            p.hp+=10;
                        }
                    }
                }
            }break;
        case 5:
            {
                if(defend5.enabled==0) ena_false3();
                else if(defend5.enabled==2) ena_false4();
                else
                {
                    if(p.talent_coin<defend5.cost) buy_false2();
                    else
                    {
                        buy_want2();
                        cin>>def;
                        if(def=="y"||def=="Y")
                        {
                            p.talent_coin-=defend5.cost;
                            def_ena[4]=0;
                            def_ena[6]=1;
                        }
                    }
                }
            }break;
        case 6:
            {
                if(defend6.enabled==0) ena_false3();
                else if(defend6.enabled==2) ena_false4();
                else
                {
                    if(p.talent_coin<defend6.cost) buy_false2();
                    else
                    {
                        buy_want2();
                        cin>>def;
                        if(def=="y"||def=="Y")
                        {
                            p.talent_coin-=defend6.cost;
                            def_ena[5]=0;
                            def_ena[7]=1;
                            p.max_hp+=20;
                            p.hp+=20;
                        }
                    }
                }
            }break;
        case 7:
            {
                if(defend7.enabled==0) ena_false3();
                else if(defend7.enabled==2) ena_false4();
                else
                {
                    if(p.talent_coin<defend7.cost) buy_false2();
                    else
                    {
                        buy_want2();
                        cin>>def;
                        if(def=="y"||def=="Y")
                        {
                            p.talent_coin-=defend7.cost;
                            def_ena[6]=0;
                            def_ena[8]=1;
                        }
                    }
                }
            }break;
        case 8:
            {
                if(defend8.enabled==0) ena_false3();
                else if(defend8.enabled==2) ena_false4();
                else
                {
                    if(p.talent_coin<defend8.cost) buy_false2();
                    else
                    {
                        buy_want2();
                        cin>>def;
                        if(def=="y"||def=="Y")
                        {
                            p.talent_coin-=defend8.cost;
                            def_ena[7]=0;
                            if(def_ena[9]==2)def_ena[9]=1;
                            p.max_hp+=20;
                            p.hp+=20;
                        }
                    }
                }
            }break;
        case 9:
            {
                if(defend9.enabled==0) ena_false3();
                else if(defend9.enabled==2) ena_false4();
                else
                {
                    if(p.talent_coin<defend9.cost) buy_false2();
                    else
                    {
                        buy_want2();
                        cin>>def;
                        if(def=="y"||def=="Y")
                        {
                            p.talent_coin-=defend9.cost;
                            def_ena[8]=0;
                            if(def_ena[9]==2)def_ena[9]=1;
                        }
                    }
                }
            }break;
        case 10:
            {
                if(defend10.enabled==0) ena_false3();
                else if(defend10.enabled==2) ena_false4();
                else
                {
                    if(p.talent_coin<defend10.cost) buy_false2();
                    else
                    {
                        buy_want2();
                        cin>>def;
                        if(def=="y"||def=="Y")
                        {
                            p.talent_coin-=defend10.cost;
                            def_ena[9]=0;
                            p.max_hp+=50;
                            p.hp+=50;
                        }
                    }
                }
            }break;
        }defense_tree();
}

void character_stats()
{
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
    cout<<"health: "<<p.hp<<"/"<<p.max_hp;

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
    if     (p.sword=="wooden")    cout<<"8";
    else if(p.sword=="stone")     cout<<"15";
    else if(p.sword=="iron")      cout<<"25";
    else if(p.sword=="diamond")   cout<<"40";
    else                          cout<<"55";

    ///aditional damage | sword + skill tree
    c1=139; col1();
    if((p.sword=="wooden")&&(ata_ena[4]==0))    cout<<"+20";
    if((p.sword=="iron")&&(ata_ena[6]==0))      cout<<"+30";
    if((p.sword=="platinum")&&(ata_ena[10]==0)) cout<<"+20";
    ///aditional combo chance | sword + skill tree
    if((p.sword=="stone")&&(ata_ena[5]==0))     cout<<" +10% combo chance";
    if((p.sword=="diamond")&&(ata_ena[9]==0))   cout<<" +10% combo chance";

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

    getchar();getchar();
    character_development();
}

void tavern()
{
    Interfac t(2,true,"TAVERN",142,true,"sleep - cost:5",138,"exit",140,"",0,"",0,"",0,
               "",0,"",0,"",0,true,true,false,false,p.money,p.hp,p.max_hp);
               t.show_menu();

    switch(t.menu_c)
    {
    case 1:
        {
            if(p.hp==p.max_hp)
            {
                c1=138; col1();
                cout<<endl<<"You have max hp!";
                Sleep(1000); tavern();
            }
            if(p.money<10)
            {
                buy_false();
                tavern();
            }
            else
            {
                p.money-=5;
                p.hp=p.max_hp;
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
    int opo_hp,opo_max_hp,opo_damage,opo_combo_chance;

    if(p.number_of_fights_played==0)
    {opo_name="Mark"; opo_hp=50; opo_max_hp=50; opo_damage=5; opo_combo_chance=1;}

    else if(p.number_of_fights_played==1)
    {opo_name="John"; opo_hp=55; opo_max_hp=55; opo_damage=3; opo_combo_chance=70;}

    else if(p.number_of_fights_played==2)
    {opo_name="Joffrey"; opo_hp=60; opo_max_hp=55; opo_damage=7; opo_combo_chance=5;}

    else if(p.number_of_fights_played==3)
    {opo_name="Gilly"; opo_hp=60; opo_max_hp=55; opo_damage=8; opo_combo_chance=15;}

    else if(p.number_of_fights_played==4)
    {opo_name="Gendry"; opo_hp=65; opo_max_hp=65; opo_damage=5; opo_combo_chance=25;}

    else if(p.number_of_fights_played==5)
    {opo_name="Shae"; opo_hp=35; opo_max_hp=35; opo_damage=4; opo_combo_chance=55;}

    else if(p.number_of_fights_played==6)
    {opo_name="Eddison"; opo_hp=60; opo_max_hp=60; opo_damage=9; opo_combo_chance=7;}

    Oponent o(opo_name,opo_hp,opo_max_hp,opo_damage,opo_combo_chance);

    o.show();
    int opo_show_c;
    cin>>opo_show_c;

    switch(opo_show_c)
    {
        case 0: city(); break;
        case 1:
            {
                while((p.hp>0)&&(o.hp>0))
                {
                    c1=140; col1();
                    cls();
                    cout<<"YOUR HP: "<<p.hp<<"/"<<p.max_hp;
                    c1=128; col1(); cout<<" | ";
                    c1=132; col1(); cout<<"OPPONENT HP: "<<o.hp<<"/"<<o.max_hp;
                    gotoxy1(15,3);
                    sword_color(o.sword);
                    cout<<"|";
                    gotoxy1(13,4); c1=128; col1();
                    cout<<"O ";
                    sword_color(o.sword);
                    cout<<"|";
                    gotoxy1(12,5);
                    c1=128; col1();
                    cout<<"-:-";
                    c1=132; col1();
                    cout<<"{";
                    gotoxy1(13,6);
                    c1=128; col1();
                    cout<<"|"<<endl;
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

void cheats()
{
    string cheat;

    c1=128; col1();
    cout<<":";
    cin>>cheat;

    if(cheat=="0")city();
    else if(cheat=="money")
    {
        int money_n;
        cout<<":";
        cin>>money_n;
        if((money_n>=0)&&(money_n<100000))
        {
            p.money=money_n;
        }
    }
    else if(cheat=="man")
    {
        cout<<"money"<<endl;
        cout<<"hp"<<endl;
        cout<<"maxhp"<<endl;
        cout<<"exp"<<endl;
        cout<<"skills0"<<endl;
        cout<<"match"<<endl;
        getchar();getchar();
    }
    else if(cheat=="hp")
    {
        int hp_n;
        cout<<":";
        cin>>hp_n;
        if((hp_n>0)&&(hp_n<=p.max_hp))
        {
            p.hp=hp_n;
        }
    }
    else if(cheat=="maxhp")
    {
        p.hp=p.max_hp;
    }
    else if(cheat=="exp")
    {
        int exp_n;
        cout<<":";
        cin>>exp_n;
        if((exp_n>=0)&&(exp_n<1000))
        {
            p.talent_coin=exp_n;
        }
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
        int match_n;
        cout<<":";
        cin>>match_n;
        if((match_n<100)&&(match_n>=0))
        {
            p.number_of_fights_played = match_n;
        }
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

        if(exit_game_c=="y") main();
        else if(exit_game_c=="n") city();
        else
        {
            c1=140; col1(); //red
            cout<<endl<<"This option does not exist!"<<endl;
            Sleep(1000);
        }
    }
}

void gotoxy1(int x, int y)
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

