#ifndef lista_h
#define lista_h

#include<iostream>
#include<cstdio>
#include<cstdlib>
using namespace std;

//Deklaracja klasy listy dwukierunkowej
class Lista
{
    public:
    class Ogniwo
    {
        public:
        Ogniwo * next;
        Ogniwo * prev;
        int value;
        int ID;
    };
    class Wskaznik
    {
        public:
        Ogniwo * wsk;
        Wskaznik next(Wskaznik it);
    };
    Lista(int v);
    void wyswietl();
    Wskaznik poczatek;
    Wskaznik koniec;
    Wskaznik insert_list(Wskaznik it, int v);
    Wskaznik delete_list(Wskaznik &it);
    Wskaznik pokazObecny(Wskaznik it);
    Wskaznik begin();
    Wskaznik end();
    Wskaznik getID(int v);
    Wskaznik getVal(int v);
    int size, IdElem;
};
//uwtorz liste z elementem o wartosci 101
    Lista list1(10);

//pobierz Wskaznik na pierwszy element listy
    Lista::Wskaznik it = list1.begin();

void inicjalizuj ();

#endif lista_h
