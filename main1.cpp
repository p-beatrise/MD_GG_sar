/****
Vards, uzvards: Paula Beatrise Valtere

G20. Uzrakstit funkciju, kas ieliek saraksta elementu ar vertibu n pec pirma elementa ar vertibu m.

GG.** Vismaz viena no datu parbaudem jarealize, izmantojot iznemumsituaciju apstrades (exception handling) mehanismu.
****/
#include <iostream>
#include <algorithm>
#include "GGsar.h"
using namespace std;

int main(){

int ok=1;
do{

     List l;List l2;
     int i;
     cout<<"Ievadiet saraksta elementus. Lai beigtu ievadi, ievadiet '0'."<<endl;
     cin >> i;                                                ///Ievade, kamer nav sastapta 0

     while(i==0)
    {cout<<"Saraksts nevar but tukss. Ievadiet skaitli, kas nav '0': "<<endl; cin>>i;}

     while (i != 0)
        {
        l.add_element (i);              ///Metode elementu ievietosanai saraksta

        cout<<endl;
        cout << "Ievadiet saraksta elementus. Lai beigtu ievadi, ievadiet '0'." << endl;
        cin >> i;

        };

        cout<<endl;
        cout<<"Jusu ievaditais saraksts: "<<endl;

        l.print();      ///Metode saraksta izdrukai


        cout<<endl;

        int pirmav;
		cout<<"Kadu elementu velaties ievietot?"<<endl;
		cin>>pirmav;
		cout<<endl;
		int peckura;
		cout<<"Pec kadas elementa vertibas velaties ievietot "<<pirmav<<" ?"<<endl;
		cin>>peckura;
		cout<<endl;

        l.start();          ///Metode norades uzstadisanai uz saraksta sakumu


        bool nav=false;
        bool ir=true;

        try {l.eksiste(l.current, peckura); }             ///Metode vertibas eksistences parbaudei,
                                                          ///pec kuras japievieno elements

        catch(const char *e){cout<<e<<endl;ir=false;}           ///Iznemuma partversanas bloki
        catch(...){cout<<"Nezinama kluda!"<<endl;ir=false;}

        while(ir!=true){

        cout<<"Ievadiet skaitli velreiz:";
        cin>>peckura;

            try {l.eksiste(l.current, peckura); }

            catch(const char *e){cout<<e<<endl;nav=true;}
            catch(...){cout<<"Nezinama kluda!"<<endl;nav=true;}

        if(nav!=true)ir=true;
        nav=false;
        }

        l.start();

        Node* c;
        for (l.start();!l.end();l.next())c=l.current;   ///Cikls saraksta pedeja elementa noskaidrosanai

        l.start();

        if(c->num==peckura) l.searchh (c, peckura, pirmav);
        else {l.searchh (l.current, peckura, pirmav);}

        l.print();

        while (!l.is_empty())l.delete_element ();           ///Saraksta izdzesanas metode


cout<<"Ja velaties atkartot darbibas, spiediet '1', citadak - '0'."<<endl;
cin>>ok;
cout<<endl;
}while(ok!=0);
};
