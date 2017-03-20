#ifndef lista_cpp
#define lista_cpp

#include "lista.h"


//***************
// METODY
//***************

//Konstruktor listy
//tworzy nowa liste dwukierunkowa z jednym elementem o zadanej wartosci v
Lista::Lista(int v)
{
    Ogniwo * a= new Ogniwo;
    a->next = a;
    a->prev = a;
    a->value = v;
    poczatek.wsk = a;
    koniec.wsk = a;
    size = 1;
    IdElem=0;
    a->ID=++IdElem;
}//Lista::Lista(int v)

//Wstawia nowy element do listy dwukierunkowej
//Element ma wartosc v i jest wstawiany za elementem wskazywanym przez iterator it
Lista::Wskaznik Lista::insert_list(Wskaznik it, int v)
{
    Ogniwo * a = it.wsk;
    Ogniwo * b = new Ogniwo;
    Ogniwo * c = a->next;
    b->next = c;
    b->prev = a;
    b->value = v;
    b->ID = ++IdElem;
    c->prev = b;
    a->next = b;
    if(b->next == b)koniec.wsk = b; //popraw koniec listy, jezeli dodajemy za ostatnim elementem
    size++;
    return it;
}//Lista::Wskaznik Lista::insert_list(Wskaznik it, int v)

//Usuwa z listy dwukierunkowej element wskazywany przez iteroator it
Lista::Wskaznik Lista::delete_list(Wskaznik &it)
{
    Ogniwo * b = it.wsk;
    Ogniwo * a = b->prev;
    Ogniwo * c = b->next;
    a->next = c;
    c->prev = a;
    if(poczatek.wsk == b) poczatek.wsk = c; //popraw poczatek listy, jezeli usuwamy pierwszy element
    if(koniec.wsk == b) koniec.wsk = a;     //popraw koniec listy, jezeli usuwamy ostatni element
    it.wsk = a;
    delete b;
    size--;
    return it;
}//Lista::Wskaznik Lista::delete_list(Wskaznik it)

//--pokaz--obecny--
Lista::Wskaznik Lista::pokazObecny(Wskaznik it)
{
    cout <<" v= "<< it.wsk->value<<" ID= "<< it.wsk->ID<<endl;
    //return it;
}//Lista::Wskaznik Lista::pokazObecny(Wskaznik it)
//--pokaz--obecny--


//Zwraca poczatek listy dwukierunkowej
Lista::Wskaznik Lista::begin()
{
    return poczatek;
}//Lista::Wskaznik Lista::begin()

//Zwraca koniec listy dwukierunkowej
Lista::Wskaznik Lista::end()
{
    return koniec;
}//Lista::Wskaznik Lista::end()

//Wyswietla zwartosc listy dwukierunkowej
void Lista::wyswietl()
{
    Wskaznik it = poczatek;
    cout <<"v={ ";
    for(int i = 0 ; i < size ; i++)
    {
        cout << it.wsk->value<<", ";
        it.wsk = it.wsk->next;
    }
    cout <<"}";

    it = poczatek;
    cout <<"\nID={ ";
    for(int i = 0 ; i < size ; i++)
    {
        cout << it.wsk->ID<<",  ";
        it.wsk = it.wsk->next;
    }
    cout <<"}";

    cout <<"\nIlosc elementow= "<<size<<endl;
}//void Lista::wyswietl()


//Zwraca Wskaznik na kolejny element w liscie dwukierunkowej
Lista::Wskaznik Lista::Wskaznik::next(Wskaznik it)
{
    it.wsk = it.wsk->next;
    return it;
}//Lista::Wskaznik Lista::Wskaznik::next(Wskaznik it)



//Zwraca Wskaznik na element o zadanym ID
Lista::Wskaznik Lista::getID(int v)
{
    Wskaznik it = poczatek;
    for(int i = 0 ; i < size; i++)
    {
        int x = it.wsk->ID;
        if(x == v) break;
        else it.wsk = it.wsk->next;
    }
    return it;
}//Lista::Wskaznik Lista::getID(int v)

//Zwraca Wskaznik na element o zadanej Wartosci
Lista::Wskaznik Lista::getVal(int v)
{
    Wskaznik it = poczatek;
    for(int i = 0 ; i < size; i++)
    {
        int x = it.wsk->value;
        if(x == v) break;
        else it.wsk = it.wsk->next;
    }
    return it;
}//Lista::Wskaznik Lista::getID(int v)

//Inicjalizuj listê
void inicjalizuj ()
{
//wstaw element 202, za pierwszym elementem
    list1.insert_list(it,20);
    it = it.next(it);
    list1.insert_list(it,30);
    it = it.next(it);
    list1.insert_list(it,40);
    it = it.next(it);
    list1.insert_list(it,50);
    it = it.next(it);
    list1.insert_list(it,60);
    it = it.next(it);
    list1.insert_list(it,70);
    it = it.next(it);
    list1.insert_list(it,80);
    it = it.next(it);
    list1.insert_list(it,90);
//przesun Wskaznik na kolejny element
    it = it.next(it);

//wstaw element o wartosci 8, za elementem o wartosci 404
    list1.insert_list(it,8);

    it = it.next(it);
//wstaw element o wartosci 12, za elementem o wartosci 8
    list1.insert_list(it,12);


    cout << "\n";
}//Inicjalizuj listê


#endif lista_cpp
