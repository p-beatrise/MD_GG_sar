#include "../GGsar/GGsar.h"
#include <iostream>
using namespace std;

List::List () { first = last = current = NULL; };      /// Konstruktora metode tuksa saraksta izveidei


void List::add_element (int n)      /// Metode elementu pievienosanai saraksta beigas
{
 Node *p = new Node (n);
 if (first == NULL) first = last = p;
 else last = last -> next = p;
 current =p;
};


void List::delete_element ()            /// Metode elementa izdzesanai no saraksta sakuma
{
 Node *p = first;
 if(!is_empty())
 { if (current == first) current = first-> next;
 first = first -> next;
 delete p;
 if(is_empty())last = NULL;
 }
};


bool List::is_empty () { return (first == NULL); };     ///Metode saraksta tuksuma parbaudei


void List::start () { current = first; };           ///Metode norades uzstadisanai uz saraksta sakumu


bool List::end () { return (current == NULL); };       /// Metode parbaudei vai norade ir nonakusi aiz saraksta beigam


void List::next(){if (!end())current = current -> next;};  /// Metode norades uzstadisanai uz saraksta nakamo elementu


void List::searchh(Node *after, int pecka, int ko){   ///Galvena metode
                                                    ///Metode izveleta skaitla iesprausanai saraksta noteikta vieta

bool ir=false;;

    Node* p = new Node(ko);

while(after!=NULL){         ///Cikls, kamer nav sasniegtas saraksta beigas

    if(after->num==pecka) {         ///Elementa pievienosana, ja tas neatrodas saraksta beigas

        p->next=after->next;
        after->next=p;
        ir=true;
        break;
    }

     if (after == last && after->num==pecka){
            last = p;      ///Elementa pievienosana, ja tas atrodas saraksta beigas
            current=p;
            ir=true;break;}

after=after->next;
}

if(ir!=true)throw 0;                    ///Pazinojuma mesanas bloks

}


bool List::eksiste(Node *after,int pecka) {  ///Metode elementa eksistences parbaudei saraksta


   while(after!=NULL){

    if(after->num==pecka) return true;
    after=after->next;
   }
    ///Bloks pazinojuma mesanai
  throw "Jusu izveletais skaitlis, pec kura ievietot izveleto vertibu nav saraksta atrodams!";
   }


bool List::garums(Node *after,Node *after2){       ///Metode sarakstu garuma parbaudei

 int gar=0, gar2=0;

 while(after!=NULL){
                        ///Cikli saraksta garuma parbaudei
    gar++;
    after=after->next;
}

 while(after2!=NULL){

    gar2++;
    after2=after2->next;
}

if(gar!=gar2) return false;
 else return true;
 }


 bool List::vai_vienads(Node *after,Node *after2) {       ///Metode sarakstu identiskuma parbaudei


while(after!=NULL){

if(after->num!=after2->num)return false;

after=after->next;
after2=after2->next;
}
return true;
 }


void List::print()      /// Metode visa saraksta izdrukai
{
    for (start(); !end(); next())
    cout << current->num << endl;
cout << endl;
};
