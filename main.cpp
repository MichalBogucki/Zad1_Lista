#include "lista.h"
#include "lista.cpp"

int main()
{
    int wybor,wart;
    inicjalizuj ();
//-----------menu-------------
    while (1)
    {
    cout << "\n";
    list1.wyswietl();
    cout << "\n-----------menu-------------\n";
    cout << "\t 0. Poczatek"<< endl;
    cout << "\t 10. Wybierz element po ID"<< endl;
    cout << "\t 11. Wybierz element po Wartosci"<< endl;
    cout << "\t 2. Stworz element"<< endl;
    cout << "\t 3. Usun obecny element"<< endl;
    cout << "\t 9. EXIT"<< endl;
    cout << "------------------------------\n";
    cout << "\Obecny wskaznik =="; list1.pokazObecny(it);
    cout <<"Wybierz opcje: ";
    cin>>wybor;
    switch(wybor)
        {
        case 0:
        it = list1.poczatek;
        break;
        case 10:
            cout<<" Podaj ID: "<<endl;
            cin>>wart;
            it = list1.getID(wart);
        break;
        case 11:
            cout<<" Podaj wartosc: "<<endl;
            cin>>wart;
            it = list1.getVal(wart);
        break;
        case 2:
            cout<<" Podaj wartosc: "<<endl;
            cin>>wart;
            list1.insert_list(it,wart);
            it = it.next(it);
        break;
        case 3:
            list1.delete_list(it);
        break;
        case 9:
            cout<<endl<<"_koniec_"<<endl;
            exit(0);
        break;

        default:
        cout<<endl<<"...Niewlasciwy...wybor..."<<endl;
        break;
        }
    }
return 0;
}

