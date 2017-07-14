//dołączenie bibliotek
#include <iostream>
#include <cstdlib>
#include <stdio.h>
#include <fstream>
#include <string>
#include <windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <sys/stat.h>
#include <ctype.h>
#include <time.h>
#include <math.h>

using namespace std;
typedef unsigned const short int UCSINT;
//stałe
UCSINT T_0=10,T_1=20,T_2=40,T_3=60,T_4=80,T_5=100;
UCSINT P_0=5,P_1=30,P_2=70,P_3=110,P_4=160,P_5=260;
//zmienne globalne
int iWybor;
clock_t start, stop;
double czas;
string login,haslo_u,haslo,login_u;
int ratusz,koszary,tartak,kamieniolom,kopalnia,drewno,kamien,zloto;
//nagłowki metod
void wyjdz();

void budowanie_licznik(int nr_budynku);

void kasuj_wiersz( const string sciezka, const size_t wiersz );

void lista();

void zapis(string l);

void zapisdopliku(int d,int k,int z,int jb,string l);

void budowanie(string l);

void ekranglowny();

void zalogowano(string l);

bool usunkonto();

void zmienhaslo(string nick);

void zarejestruj();

void zaloguj();

void wyloguj();

int produkcja(int poziom);

double oblicz_czas();



int policz_ile_dodac(double czas,int numer);
//funkcja głowna
int main()
{
    while(1)
    {
        ekranglowny();
    }
    return 0;
}
void zalogowano(string l)
{
    int iWybor;
    system("cls");
    start=clock();
    cout<<"Panel uzytkownika"<<endl;
    cout<<"-----------------"<<endl;
    cout<<"Login: "<<l<<endl;
    cout<<"Drewno: "<<drewno<<"     (Produkcja= "<<produkcja(tartak)<<" surowcow na godzine)"<<endl;
    cout<<"Kamien: "<<kamien<<"     (Produkcja= "<<produkcja(kamieniolom)<<" surowcow na godzine)"<<endl;
    cout<<"Zloto: "<<zloto<<"     (Produkcja= "<<produkcja(kopalnia)<<" surowcow na godzine)"<<endl<<endl;
    cout<<"MENU"<<endl;
    cout<<"-------------------"<<endl;
    cout<<"Zmien haslo(1): "<<endl;
    cout<<"Usun konto (2): "<<endl;
    cout<<"Lista graczy (3): "<<endl;
    cout<<"Ekran budowania(4): "<<endl;
    cout<<"Wyjdz(5): "<<endl;
    cout<<"Wyloguj(6): "<<endl;
    do
    {
        cin>>iWybor;
        if(iWybor==1)
        {
            zmienhaslo(l);
        }
        else if(iWybor==2)
        {
            if(usunkonto()==true)
            {
                ekranglowny();
            }
            else
            {
                zalogowano(l);
            }
        }
        else if (iWybor==3)
        {
            system("cls");
            Sleep(150);
            lista();

        }
        else if (iWybor==4)
        {
            budowanie(l);

        }
        else if (iWybor==5)
        {
            stop=clock();
            wyjdz();
            exit(0);
        }
        else if (iWybor==6)
        {
            system("cls");
            stop=clock();
            wyloguj();
            ekranglowny();

        }
        else
        {
            cout<<"Nie ma takiej opcji"<<endl;
            Sleep(1001);
        }
    }
    while(iWybor!=2);
}
void ekranglowny()
{
    cout<<"MENU"<<endl;
    cout<<"-----------------------"<<endl;
    cout<<"1.Zaloguj sie"<<endl;
    cout<<"2.Zarejestruj sie"<<endl;
    cout<<"3.Koniec"<<endl;
    cin>>iWybor;
    switch(iWybor)
    {
    case 1:
    {
        zaloguj();
    }
    break;
    case 2:
    {

        zarejestruj();
    }
    break;
    case 3:
    {
        exit(1);
    }
    break;
    default:
    {
        cout<<"Nie ma takiej opcji";
        Sleep(1001);
        exit(1);
    }
    }
}
void budowanie(string l)
{
    int wybor;
    system("cls");
    cout<<"MENU BUDOWY"<<endl;
    cout<<"-----------"<<endl;
    cout<<"SUROWCE:"<<endl;
    cout<<"Drewno: "<<drewno<<endl;
    cout<<"Kamien: "<<kamien<<endl;
    cout<<"Zloto: "<<zloto<<endl;
    cout<<"ROZBUDOWA"<<endl;
    cout<<"-----------------------------------------------------------"<<endl;
    cout<<"Ratusz("<<ratusz<<" lvl)-nacisnij 1 aby rozbudowac ( 50 , 20 , 30 )"<<endl;
    cout<<"Koszary("<<koszary<<" lvl)-nacisnij 2 aby rozbudowac ( 30 , 47 , 70 )"<<endl;
    cout<<"Tartak("<<tartak<<" lvl)-nacisnij 3 aby rozbudowac ( 10 , 50 , 30 )"<<endl;
    cout<<"Kamieniolom("<<kamieniolom<<" lvl)-nacisnij 4 aby rozbudowac ( 20 , 50 , 20 )"<<endl;
    cout<<"Kopalnia zlota("<<kopalnia<<" lvl)-nacisnij 5 aby rozbudowac ( 40 , 60 , 10 )"<<endl;
    cout<<"Wyjdz-nacisnij 6"<<endl;
    cin>>wybor;
    switch(wybor)
    {
    case 1:
    {
        zapisdopliku(drewno,kamien,zloto,1,l);
    }
    break;
    case 2:
    {
        zapisdopliku(drewno,kamien,zloto,2,l);
    }
    break;
    case 3:
    {
        zapisdopliku(drewno,kamien,zloto,3,l);
    }
    break;
    case 4:
    {
        zapisdopliku(drewno,kamien,zloto,4,l);
    }
    break;
    case 5:
    {
        zapisdopliku(drewno,kamien,zloto,5,l);
    }
    break;
    case 6:
    {
        wyjdz();
        exit(0);
    }
    default:
    {
        cout<<"Nie ma takiej opcji w menu"<<endl;
        Sleep(1001);
    }
    break;
    }
}
//d=drewno k=kamien z=zloto jb=numer budynku l=login
void zapisdopliku(int d,int k,int z,int jb,string l)
{
    int budynek=jb;
    /**
    1.Ratusz
    2.Koszary
    3.Tartak
    4.Kamieniołom
    5.Kopalnia zlota
     */
    switch(budynek)
    {
    case 1:
    {
        ratusz++;
        drewno=drewno-50;
        kamien=kamien-20;
        zloto=zloto-30;
        system("cls");

        budowanie_licznik(1);

        zapis(l);
        zalogowano(login);
    }
    break;
    case 2:
    {
        koszary++;
        drewno=drewno-30;
        kamien=kamien-47;
        zloto=zloto-70;
        system("cls");
        budowanie_licznik(2);
        zapis(l);
        zalogowano(login);
    }
    break;
    case 3:
    {
        tartak++;
        drewno=drewno-10;
        kamien=kamien-50;
        zloto=zloto-30;
        system("cls");
        budowanie_licznik(3);
        zapis(l);
        zalogowano(login);
    }
    break;
    case 4:
    {
        kamieniolom++;
        drewno=drewno-20;
        kamien=kamien-50;
        zloto=zloto-20;
        system("cls");
        budowanie_licznik(4);
        zapis(l);
        zalogowano(login);
    }
    break;
    case 5:
    {
        kopalnia++;
        drewno=drewno-40;
        kamien=kamien-60;
        zloto=zloto-10;
        system("cls");
        budowanie_licznik(5);
        zapis(l);
        zalogowano(login);
    }
    break;
    }
}
void zapis(string l)
{
    string plikn=l+".txt";
    fstream haslo;
    haslo.open(plikn.c_str(),ios::out);
    haslo<<l<<endl;
    haslo<<haslo_u<<endl;
    haslo<<drewno<<endl;
    haslo<<kamien<<endl;
    haslo<<zloto<<endl;
    haslo<<ratusz<<endl;
    haslo<<koszary<<endl;
    haslo<<tartak<<endl;
    haslo<<kamieniolom<<endl;
    haslo<<kopalnia<<endl;
}
bool usunkonto()
{

    char wybor;
    system("cls");
    cout<<"Czy jestes pewny ze chcesz usnac konto? Wpisz 'T' lub 'N': ";
    cin>>wybor;
    string linia[100];
    string plikn=login+".txt";
    string wiersz;
    if(wybor=='T'||wybor=='t')
    {
        DeleteFileA(plikn.c_str());
        fstream plik;

        int nr_lini=1;
        int x=0;
        string linia2;
        plik.open("lista.txt",ios::in);

        while(getline(plik,wiersz))
        {
            switch(nr_lini)
            {
            case 1:
                linia[x]=wiersz;
                break;
            case 2:
                linia[x]=wiersz;
                break;
            case 3:
                linia[x]=wiersz;
                break;
            case 4:
                linia[x]=wiersz;
                break;
            case 5:
                linia[x]=wiersz;
                break;
            case 6:
                linia[x]=wiersz;
                break;
            case 7:
                linia[x]=wiersz;
                break;
            case 8:
                linia[x]=wiersz;
                break;
            case 9:
                linia[x]=wiersz;
                break;
            case 10:
                linia[x]=wiersz;
                break;

            }

            nr_lini++;
            x++;

        }
        int ktory;
        for(int i=0; i<=x; i++)
        {
            if(linia[i]==login)
            {
                ktory=i;
            }
        }
        cout<<linia[ktory];
        kasuj_wiersz("lista.txt",ktory+1);
        plik.close();
        system("cls");
        cout<<"Konto pomyslnie usuniete";
        Sleep(1000);
        system("cls");

        return true;

    }
    else if(wybor=='N'||wybor=='n')
    {
        cout<<"Zostaniesz przeniesiony do panelu gry"<<endl;
        Sleep(1000);
        system("cls");
        zalogowano(login);
    }
}
void zmienhaslo(string nick)
{

    bool spr=false;
    fstream haslo;
    string starehaslo;
    string plikn=nick+".txt";
    string nowehaslo,pow;
    system("cls");
    do
    {
        cout<<"Podaj stare haslo: ";
        cin>>starehaslo;
        cout<<endl<<"Podaj nowe haslo,ktore musi skladac sie z minimum 6 liter i 2 cyfr: ";
        cin>>nowehaslo;
        cout<<endl<<"Powtorz nowe haslo: ";
        cin>>pow;
        int  dlug=pow.length();
        int licznik=0,licznik2=0;
        for(int i=0; i<dlug; i++)
        {
            if(islower( pow[i])|| isupper(pow[i]))
            {
                licznik++;
            }
        }
        for(int i=0; i<dlug; i++)
        {
            if(isdigit(pow[i]))
            {
                licznik2++;
            }
        }
        if(starehaslo==haslo_u&&nowehaslo==pow&&pow.length()>=8&&licznik>=6&&licznik2>=2)
        {
            czas = (double)(stop - start) / CLOCKS_PER_SEC;
            cout<<endl<<"Twoje haslo zostalo zmienione"<<endl;
            haslo.open(plikn.c_str(),ios::out);
            haslo<<nick<<endl;
            haslo<<nowehaslo<<endl;
            haslo<<drewno+policz_ile_dodac(czas,1)<<endl;
            haslo<<kamien+policz_ile_dodac(czas,2)<<endl;
            haslo<<zloto+policz_ile_dodac(czas,3)<<endl;
            haslo<<ratusz<<endl;
            haslo<<koszary<<endl;
            haslo<<tartak<<endl;
            haslo<<kamieniolom<<endl;
            haslo<<kopalnia<<endl;
            Sleep(1000);
            system("cls");
            spr=true;
            ekranglowny();
            haslo.close();
        }
        else
        {
            cout<<endl<<"Hasla sa rozne lub haslo ma mniej niz 8 znakow lub stare haslo jest nieprawidlow lub nie skladaja sie z okreslonej ilosci znakow";
            Sleep(1000);
            system("cls");

        }
    }
    while(spr==false);
}
void zarejestruj()
{
    fstream rej;
    fstream lista;
    fstream sprawdzanie;
    string haslo_rej,haslo_pow;
    system("cls");
    cout<<"Podaj login: ";
    cin>>login;
    cout<<"Halo musi skladac sie z minimum 6 liter i 2 cyfr"<<endl;
    cout<<"Podaj haslo: ";
    cin>>haslo_rej;
    cout<<"Powtorz haslo: ";
    cin>>haslo_pow;
    string nick=login+".txt";
    int  dlug=haslo_rej.length();
    int licznik=0,licznik2=0;
    for(int i=0; i<dlug; i++)
    {
        if(islower( haslo_rej[i])|| isupper(haslo_rej[i]))
        {
            licznik++;
        }
    }
    for(int i=0; i<dlug; i++)
    {
        if(isdigit(haslo_rej[i]))
        {
            licznik2++;
        }
    }
    struct stat buf;
    //Odczytywanie statystyk pliku
    if ( stat(nick.c_str(), &buf) == 0 )
    {
        cout<<"Uzytkownik o takiej nazwie istnieje"<<endl;
        Sleep(1001);
        zarejestruj();
    }
    else

        if(haslo_rej==haslo_pow && haslo_rej.length()>=8&&licznik>=6&&licznik2>=2)
        {
            cout<<"Twoje konto zostalo zalozone"<<endl;
            lista.open("lista.txt",ios::app);
            lista<<login<<endl;
            rej.open(nick.c_str(),ios::out);
            rej<<login<<endl;
            rej<<haslo_rej<<endl;
            rej<<"10000"<<endl;
            rej<<"10000"<<endl;
            rej<<"10000"<<endl;
            rej<<"0"<<endl;
            rej<<"0"<<endl;
            rej<<"0"<<endl;
            rej<<"0"<<endl;
            rej<<"0"<<endl;
            Sleep(1000);
            system("cls");
            rej.close();
            ekranglowny();
        }

        else
        {
            cout<<"Hasla sa rozne lub haslo ma mniej niz 8 znakow lub nie skladaja sie z okreslonej ilosci znakow"<<endl;
            Sleep(1002);
            zarejestruj();
        }
    rej.close();
}
void zaloguj()
{
    bool ok=false;
    do
    {

        system("cls");
        fstream plik;
        string linia;
        cout<<"Podaj login: ";
        cin>>login_u;
        cout<<"Podaj haslo: ";
        cin>>haslo_u;
        string plikn=login_u+".txt";
        int nr_lini=1;

        struct stat buf;
        /* Odczytywanie statystyk pliku */
        if ( stat(plikn.c_str(), &buf) == 0 )
        {
            plik.open(plikn.c_str(),ios::in);
            while(getline(plik,linia))
            {
                switch(nr_lini)
                {
                case 1:
                    login=linia;
                    break;
                case 2:
                    haslo=linia;
                    break;
                case 3:
                    drewno=atoi(linia.c_str());
                    break;
                case 4:
                    kamien=atoi(linia.c_str());
                    break;
                case 5:
                    zloto=atoi(linia.c_str());
                    break;
                case 6:
                    ratusz=atoi(linia.c_str());
                    break;
                case 7:
                    koszary=atoi(linia.c_str());
                    break;
                case 8:
                    tartak=atoi(linia.c_str());
                    break;
                case 9:
                    kamieniolom=atoi(linia.c_str());
                    break;
                case 10:
                    kopalnia=atoi(linia.c_str());
                    break;
                }
                nr_lini++;

            }
            plik.close();
            if(login_u==login&&haslo==haslo_u)
            {
                cout<<endl<<"Pomyslnie zalogowano";
                cout<<endl<<"Za chwile zostaniesz przeniesiony do panelu gracza";
                Sleep(1000);
                ok=true;
                zalogowano(login);

            }
            else
            {
                system("cls");
                cout<<"Zle haslo";
                ok=false;
                Sleep(1001);
            }
        }
        else
        {
            system("cls");
            cout<<"Nie ma takiego uzytkownika"<<endl;
            ok=false;
            Sleep(1000);


        }
        system("cls");
    }
    while(ok!=true);
}
void budowanie_licznik(int nr_budynku)
{

    switch(nr_budynku)
    {
    case 1:
    {
        switch(ratusz)
        {
        case 0:
        {
            for(int i=T_0; i>=1; i--)
            {
                cout<<"Trwa rozbudowa ratusza na "<<ratusz<<" lvl."<<endl;
                cout<<"Zostało "<<i<<" sec"<<endl;
                Sleep(1000);
                system("cls");
            }
        }
        break;
        case 1:
        {
            for(int i=T_1; i>=1; i--)
            {
                cout<<"Trwa rozbudowa ratusza na "<<ratusz<<" lvl."<<endl;
                cout<<"Zostało "<<i<<" sec"<<endl;
                Sleep(1000);
                system("cls");
            }
        }
        break;
        case 2:
        {
            for(int i=T_2; i>=1; i--)
            {
                cout<<"Trwa rozbudowa ratusza na "<<ratusz<<" lvl."<<endl;
                cout<<"Zostało "<<i<<" sec"<<endl;
                Sleep(1000);
                system("cls");
            }
        }
        break;
        case 3:
        {
            for(int i=T_3; i>=1; i--)
            {
                cout<<"Trwa rozbudowa ratusza na "<<ratusz<<" lvl."<<endl;
                cout<<"Zostało "<<i<<" sec"<<endl;
                Sleep(1000);
                system("cls");
            }
        }
        break;
        case 4 :
        {
            for(int i=T_4; i>=1; i--)
            {
                cout<<"Trwa rozbudowa ratusza na "<<ratusz<<" lvl."<<endl;
                cout<<"Zostało "<<i<<" sec"<<endl;
                Sleep(1000);
                system("cls");
            }
        }
        break;
        case 5:
        {
            for(int i=T_5; i>=1; i--)
            {
                cout<<"Trwa rozbudowa ratusza na "<<ratusz<<" lvl."<<endl;
                cout<<"Zostało "<<i<<" sec"<<endl;
                Sleep(1000);
                system("cls");
            }
        }
        break;

        case 6:
        {
            cout<<"Nie mozna rozbudowac budynku na 6 lvl"<<endl;
            Sleep(1400);
            ratusz--;
            zalogowano(login_u);
        }
        break;
        }
    }
    break;
    case 2:
    {
        switch(koszary)
        {
        case 0:
        {
            for(int i=T_0; i>=1; i--)
            {
                cout<<"Trwa rozbudowa koszar na "<<koszary<<" lvl."<<endl;
                cout<<"Zostało "<<i<<" sec"<<endl;
                Sleep(1000);
                system("cls");
            }
        }
        break;
        case 1:
        {
            for(int i=T_1; i>=1; i--)
            {
                cout<<"Trwa rozbudowa koszar na "<<koszary<<" lvl."<<endl;
                cout<<"Zostało "<<i<<" sec"<<endl;
                Sleep(1000);
                system("cls");
            }
        }
        break;
        case 2:
        {
            for(int i=T_2; i>=1; i--)
            {
                cout<<"Trwa rozbudowa koszar na "<<koszary<<" lvl."<<endl;
                cout<<"Zostało "<<i<<" sec"<<endl;
                Sleep(1000);
                system("cls");
            }
        }
        break;
        case 3:
        {
            for(int i=T_3; i>=1; i--)
            {
                cout<<"Trwa rozbudowa koszar na "<<koszary<<" lvl."<<endl;
                cout<<"Zostało "<<i<<" sec"<<endl;
                Sleep(1000);
                system("cls");
            }
        }
        break;
        case 4 :
        {
            for(int i=T_4; i>=1; i--)
            {
                cout<<"Trwa rozbudowa koszary na "<<koszary<<" lvl."<<endl;
                cout<<"Zostało "<<i<<" sec"<<endl;
                Sleep(1000);
                system("cls");
            }
        }
        break;
        case 5:
        {
            for(int i=T_5; i>=1; i--)
            {
                cout<<"Trwa rozbudowa koszary na "<<koszary<<" lvl."<<endl;
                cout<<"Zostało "<<i<<" sec"<<endl;
                Sleep(1000);
                system("cls");
            }
        }
        break;

        case 6:
        {
            cout<<"Nie mozna rozbudowac budynku na 6 lvl"<<endl;
            Sleep(1400);
            koszary--;
            zalogowano(login_u);
        }
        break;
        }
    }
    break;
    case 3:
    {
        switch(tartak)
        {
        case 0:
        {
            for(int i=T_0; i>=1; i--)
            {
                cout<<"Trwa rozbudowa tartaku na "<<tartak<<" lvl."<<endl;
                cout<<"Zostało "<<i<<" sec"<<endl;
                Sleep(1000);
                system("cls");
            }
        }
        break;
        case 1:
        {
            for(int i=T_1; i>=1; i--)
            {
                cout<<"Trwa rozbudowa tartaku na "<<tartak<<" lvl."<<endl;
                cout<<"Zostało "<<i<<" sec"<<endl;
                Sleep(1000);
                system("cls");
            }
        }
        break;
        case 2:
        {
            for(int i=T_2; i>=1; i--)
            {
                cout<<"Trwa rozbudowa tartaku na "<<tartak<<" lvl."<<endl;
                cout<<"Zostało "<<i<<" sec"<<endl;
                Sleep(1000);
                system("cls");
            }
        }
        break;
        case 3:
        {
            for(int i=T_3; i>=1; i--)
            {
                cout<<"Trwa rozbudowa tartaku na "<<tartak<<" lvl."<<endl;
                cout<<"Zostało "<<i<<" sec"<<endl;
                Sleep(1000);
                system("cls");
            }
        }
        break;
        case 4 :
        {
            for(int i=T_4; i>=1; i--)
            {
                cout<<"Trwa rozbudowa tartak na "<<tartak<<" lvl."<<endl;
                cout<<"Zostało "<<i<<" sec"<<endl;
                Sleep(1000);
                system("cls");
            }
        }
        break;
        case 5:
        {
            for(int i=T_5; i>=1; i--)
            {
                cout<<"Trwa rozbudowa tartak na "<<tartak<<" lvl."<<endl;
                cout<<"Zostało "<<i<<" sec"<<endl;
                Sleep(1000);
                system("cls");
            }
        }
        break;

        case 6:
        {
            cout<<"Nie mozna rozbudowac budynku na 6 lvl"<<endl;
            Sleep(1400);
            tartak--;
            zalogowano(login_u);
        }
        break;
        }
    }
    break;
    case 4:
    {
        switch(kamieniolom)
        {
        case 0:
        {
            for(int i=T_0; i>=1; i--)
            {
                cout<<"Trwa rozbudowa kamieniolomu na "<<kamieniolom<<" lvl."<<endl;
                cout<<"Zostało "<<i<<" sec"<<endl;
                Sleep(1000);
                system("cls");
            }
        }
        break;
        case 1:
        {
            for(int i=T_1; i>=1; i--)
            {
                cout<<"Trwa rozbudowa kamieniolomu na "<<kamieniolom<<" lvl."<<endl;
                cout<<"Zostało "<<i<<" sec"<<endl;
                Sleep(1000);
                system("cls");
            }
        }
        break;
        case 2:
        {
            for(int i=T_2; i>=1; i--)
            {
                cout<<"Trwa rozbudowa kamieniolomu na "<<kamieniolom<<" lvl."<<endl;
                cout<<"Zostało "<<i<<" sec"<<endl;
                Sleep(1000);
                system("cls");
            }
        }
        break;
        case 3:
        {
            for(int i=T_3; i>=1; i--)
            {
                cout<<"Trwa rozbudowa kamieniolomu na "<<kamieniolom<<" lvl."<<endl;
                cout<<"Zostało "<<i<<" sec"<<endl;
                Sleep(1000);
                system("cls");
            }
        }
        break;
        case 4 :
        {
            for(int i=T_4; i>=1; i--)
            {
                cout<<"Trwa rozbudowa kamieniolom na "<<kamieniolom<<" lvl."<<endl;
                cout<<"Zostało "<<i<<" sec"<<endl;
                Sleep(1000);
                system("cls");
            }
        }
        break;
        case 5:
        {
            for(int i=T_5; i>=1; i--)
            {
                cout<<"Trwa rozbudowa kamieniolom na "<<kamieniolom<<" lvl."<<endl;
                cout<<"Zostało "<<i<<" sec"<<endl;
                Sleep(1000);
                system("cls");
            }
        }
        break;

        case 6:
        {
            cout<<"Nie mozna rozbudowac budynku na 6 lvl"<<endl;
            Sleep(1400);
            kamieniolom--;
            zalogowano(login_u);
        }
        break;
        }
    }
    break;
    case 5:
    {
        switch(kopalnia)
        {
        case 0:
        {
            for(int i=T_0; i>=1; i--)
            {
                cout<<"Trwa rozbudowa kopalni zlota na "<<kopalnia<<" lvl."<<endl;
                cout<<"Zostało "<<i<<" sec"<<endl;
                Sleep(1000);
                system("cls");
            }
        }
        break;
        case 1:
        {
            for(int i=T_1; i>=1; i--)
            {
                cout<<"Trwa rozbudowa kopalni zlota na "<<kopalnia<<" lvl."<<endl;
                cout<<"Zostało "<<i<<" sec"<<endl;
                Sleep(1000);
                system("cls");
            }
        }
        break;
        case 2:
        {
            for(int i=T_2; i>=1; i--)
            {
                cout<<"Trwa rozbudowa kopalni zlota na "<<kopalnia<<" lvl."<<endl;
                cout<<"Zostało "<<i<<" sec"<<endl;
                Sleep(1000);
                system("cls");
            }
        }
        break;
        case 3:
        {
            for(int i=T_3; i>=1; i--)
            {
                cout<<"Trwa rozbudowa kopalni zlota na "<<kopalnia<<" lvl."<<endl;
                cout<<"Zostało "<<i<<" sec"<<endl;
                Sleep(1000);
                system("cls");
            }
        }
        break;
        case 4 :
        {
            for(int i=T_4; i>=1; i--)
            {
                cout<<"Trwa rozbudowa kopalnia na "<<kopalnia<<" lvl."<<endl;
                cout<<"Zostało "<<i<<" sec"<<endl;
                Sleep(1000);
                system("cls");
            }
        }
        break;
        case 5:
        {
            for(int i=T_5; i>=1; i--)
            {
                cout<<"Trwa rozbudowa kopalnia na "<<kopalnia<<" lvl."<<endl;
                cout<<"Zostało "<<i<<" sec"<<endl;
                Sleep(1000);
                system("cls");
            }
        }
        break;

        case 6:
        {
            cout<<"Nie mozna rozbudowac budynku na 6 lvl"<<endl;
            Sleep(1400);
            kopalnia--;
            zalogowano(login_u);
        }
        break;
        }
    }
    break;
    }
}
void lista()
{
    fstream plik;
    string linia;
    int nr_lini=1;
    string login[100];
    int i=0;
    cout<<"LISTA GRACZY"<<endl;
    cout<<"------------"<<endl;
    plik.open("lista.txt",ios::in);
    while(getline(plik,linia))
    {
        switch(nr_lini)
        {
        case 1 :
            login[i]=linia;
            break;
        case 2 :
            login[i]=linia;
            break;
        case 3 :
            login[i]=linia;
            break;
        case 4 :
            login[i]=linia;
            break;
        case 5 :
            login[i]=linia;
            break;
        case 6 :
            login[i]=linia;
            break;
        case 7:
            login[i]=linia;
            break;
        case 8:
            login[i]=linia;
            break;
        case 9:
            login[i]=linia;
            break;
        case 10:
            login[i]=linia;
            break;
        }
        nr_lini++;
        i++;
    }
    for(int i=1; i<nr_lini; i++)
    {
        cout<<i<<". "<<login[i-1]<<endl;
    }
    cout<<endl<<endl<<"Wyroc do panelu uzytkownika(b)"<<endl;
    char wybor;
    cin>>wybor;
    if(wybor=='b'||wybor=='B')
    {
        zalogowano(login_u);
    }
}
void wyjdz()
{
    czas = (double)(stop - start) / CLOCKS_PER_SEC;

    string plikn=login_u+".txt";
    fstream wyjdz;
    wyjdz.open(plikn.c_str(),ios::out);
    wyjdz<<login_u<<endl;
    wyjdz<<haslo<<endl;
    wyjdz<<drewno+policz_ile_dodac(czas,1)<<endl;
    wyjdz<<kamien+policz_ile_dodac(czas,2)<<endl;
    wyjdz<<zloto+policz_ile_dodac(czas,3)<<endl;
    wyjdz<<ratusz<<endl;
    wyjdz<<koszary<<endl;
    wyjdz<<tartak<<endl;
    wyjdz<<kamieniolom<<endl;
    wyjdz<<kopalnia<<endl;
    wyjdz.close();
}
void kasuj_wiersz( const string sciezka, const size_t wiersz )
{
    vector < string > vec;
    ifstream in( sciezka.c_str() );
    string tmp;
    while( getline( in, tmp ) ) vec.push_back( tmp );
    in.close();
    ofstream out( sciezka.c_str() );
    for( size_t i = 0; i < vec.size(); ++i )
    {
        if( i + 1 != wiersz ) out << vec[ i ] << endl;
    }
    out.close();
}
int produkcja(int poziom)
{
    switch(poziom)
    {
    case 0:
    {
        return P_0;
    }
    break;
    case 1:
    {
        return P_1;
    }
    break;
    case 2:
    {
        return P_2;
    }
    break;
    case 3:
    {
        return P_3;
    }
    break;
    case 4:
    {
        return P_4;
    }
    break;
    case 5:
    {
        return P_5;
    }
    break;


    }
}
void  wyloguj()
{
    czas = (double)(stop - start) / CLOCKS_PER_SEC;

    string plikn=login_u+".txt";
    fstream wyjdz;
    wyjdz.open(plikn.c_str(),ios::out);
    wyjdz<<login_u<<endl;
    wyjdz<<haslo<<endl;
    wyjdz<<drewno+policz_ile_dodac(czas,1)<<endl;
    wyjdz<<kamien+policz_ile_dodac(czas,2)<<endl;
    wyjdz<<zloto+policz_ile_dodac(czas,3)<<endl;
    wyjdz<<ratusz<<endl;
    wyjdz<<koszary<<endl;
    wyjdz<<tartak<<endl;
    wyjdz<<kamieniolom<<endl;
    wyjdz<<kopalnia<<endl;
    wyjdz.close();
}

int policz_ile_dodac(double czas,int numer)
{
    double d=produkcja(tartak);
    double k=produkcja(kamieniolom);
    double z=produkcja(kopalnia);
    switch(numer)
    {
    case 1 :
    {
        d*=3600;
        double w=czas/d;
        return ceil(w);
    }
    break;
    case 2 :
    {
        d*=3600;
        double w=czas/k;
        return ceil(w);
    }
    break;
    case 3 :
    {
        d*=3600;
        double w=czas/z;
        return ceil(w);
    }
    break;
    }
}
