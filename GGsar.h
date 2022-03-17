#include <iostream>

class Node      ///Saraksta mezgla klases dekleracija
{
public:
int num;
Node* next;
Node (int n) { num = n; next = NULL; };
};


class List      ///Saraksta klases deklaracija
{
protected:
 Node *first, *last;
public:
 Node *current;
public:

 List ();    ///Konstruktora metode tuksa saraksta izveide

 void add_element (int n);      /// Metode elementu pievienosanai saraksta beigas

 bool is_empty ();       ///Metode saraksta tuksuma parbaudei

 void start ();      ///Metode norades uzstadisanai uz saraksta sakumu

 bool end ();       /// Metode parbaudei vai norade ir nonakusi aiz saraksta beigam

 void next();    /// Metode norades uzstadisanai uz saraksta nakamo elementu

 void delete_element ();     /// Metode elementa izdzesanai no saraksta sakuma

 void searchh(Node *after, int pecka, int ko);      ///Metode izveleta skaitla iesprausanai saraksta noteikta vieta

 bool eksiste(Node *after,int pecka);           ///Metode elementa eksistences parbaudei saraksta

 bool vai_vienads(Node *after,Node *after2);        ///Metode sarakstu identiskuma parbaudei

 bool garums(Node *after,Node *after2);          ///Metode sarakstu garuma parbaudei

 void print();      /// Metode visa saraksta izdrukai
};
