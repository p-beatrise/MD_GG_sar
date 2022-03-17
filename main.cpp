/****
Vards, uzvards: Paula Beatrise Valtere

G20. Uzrakstit funkciju, kas ieliek saraksta elementu ar vertibu n pec pirma elementa ar vertibu m.

GG.** Vismaz viena no datu parbaudem jarealize, izmantojot iznemumsituaciju apstrades (exception handling) mehanismu.
****/

#include <iostream>
#include "../GGsar/GGsar.h"
using namespace std;

bool test_A (){
List test, A;
for(int i=1; i<=5; i++){    ///Saraksta "1 2 3 4 5" izveides cikls

       test.add_element (i);
    }
 for(int i=1; i<=5; i++){    ///Saraksta "1 2 3 99 4 5" izveides cikls

       if(i==4)A.add_element (99);
       A.add_element (i);
    }

int ko=99;
int pecka=3;

test.start();

test.searchh(test.current, pecka, ko);      ///Metode skaitla ievietosanai saraksta

test.start();
A.start();

if(test.garums(test.current,A.current)){        ///Metode sarakstu garumu noteiksanai
test.start();
A.start();
  return test.vai_vienads(test.current,A.current);      ///Metode sarakstu identiskuma noteiksanai
}
else return false;
}

bool test_B(){

List test, B;
for(int i=1; i<=5; i++){    ///Saraksta "1 2 3 4 5" izveides cikls

       test.add_element (i);
    }

for(int i=1; i<=5; i++){    ///Saraksta "1 2 3 4 5 99" izveides cikls

       B.add_element (i);
       if(i==5)B.add_element (99);
    }

int ko=99;
int pecka=5;

test.start();

test.searchh(test.current, pecka, ko);      ///Metode skaitla ievietosanai saraksta

test.start();
B.start();

if(test.garums(test.current,B.current)){        ///Metode sarakstu garumu noteiksanai
 test.start();
B.start();
  return test.vai_vienads(test.current,B.current);      ///Metode sarakstu identiskuma noteiksanai
}
else return false;
}

bool test_C(){

List test, C;

for(int i=1; i<=5; i++){    ///Saraksta "1 1 2 3 4 5" izveides cikls

       if(i==1)test.add_element (1);
       test.add_element (i);
    }

for(int i=1; i<=5; i++){    ///Saraksta "1 99 1 2 3 4 5" izveides cikls

       if(i==1)C.add_element (1);
       if(i==1)C.add_element (99);
       C.add_element (i);
    }

int ko=99;
int pecka=1;

test.start();

test.searchh(test.current, pecka, ko);      ///Metode skaitla ievietosanai saraksta

test.start();
C.start();

if(test.garums(test.current,C.current)){        ///Metode sarakstu garumu noteiksanai
 test.start();
C.start();
  return test.vai_vienads(test.current,C.current);      ///Metode sarakstu identiskuma noteiksanai


}
else return false;

}

bool test_D(){

List test;

for(int i=1; i<=5; i++){    ///Saraksta "1 1 2 3 4 5" izveides cikls

       if(i==1)test.add_element (1);
       test.add_element (i);
    }


int ko=99;
int pecka=78;

test.start();
try{(test.searchh(test.current, ko,  pecka));}                    ///Iznemuma situacijas apstrades funkcija

catch(int error) {if(error==0) return 1;                ///Iznemuma partversanas bloki
                    else return 0;}
catch(...) {return 0;}

}

int main()
{

cout<<"Testi:"<<endl;
cout<<test_A ()<<endl;          ///Vienibtesti
cout<<test_B ()<<endl;
cout<<test_C ()<<endl;
cout<<test_D ()<<endl;
}
