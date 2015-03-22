#include "affichage.h"
#include <fstream>
#include <sstream>

Affichage::Affichage()
{
    //ctor
}

Affichage::~Affichage()
{
    //dtor
}

void Affichage::header()
{
    system("cls");
    cout<<"*************************************************"<<endl;
    cout<<"**         Algorithmes numeriques Labo 2       **"<<endl;
    cout<<"** Calcul des zeros avec m�thode du point fixe **"<<endl;
    cout<<"*************************************************"<<endl;
    cout<<endl<<endl;
}

void Affichage::menu()
{
    cout<<"  1. Recherche des zeros pour x/(1-x^2)"<<endl;
    cout<<"  2. Recherche des zeros pour sin(x)-x / 13"<<endl;
    cout<<"  3. Readme"<<endl;
    cout<<"  4. Fin"<<endl;
    cout<<endl;
}

int Affichage::menuBegin()
{
    int rep = 0;

    header();
    menu();
    cout<<"  Saisissez un choix du menu (1 a 4): ";
    cin>>rep;
    return rep;
}

int Affichage::menuNotValid()
{
    int rep = 0;

    header();
    menu();
    cout<<"  Commande non valide. Recommencez. "<<endl;
    cout<<"  Saisissez un choix du menu (1 a 4): ";
    cin>>rep;
    return rep;
}
double Affichage::saisieValeur(const double &valeurMin, const double &valeurMax)
{
    double valeurDeRetour= valeurMin-1;
    while(true)
    {
        cout << "   Saisissez une valeure entre " << valeurMin << " et " << valeurMax << ": ";
        cin >> valeurDeRetour;

        if(cin.eof() || cin.bad())
        {
            cerr << "Une erreur interne est survenue." << endl;
            if(cin.eof() || valeurDeRetour <= valeurMin || valeurDeRetour >=valeurMax)
            {
                break;
            }
            viderBuffer();
            continue;
        }
        else if(cin.fail() || valeurDeRetour <= valeurMin ||valeurDeRetour >=valeurMax)
        {
            cerr << "Erreur, saisie incorrecte." << endl;
            viderBuffer();
            continue;
        }
        break;
    }
    return valeurDeRetour;
}

void Affichage::viderBuffer()
{
    cin.clear();
    cin.seekg(0, ios::end);

    if(!cin.fail())
    {
        cin.ignore(numeric_limits<streamsize>::max());
    }
    else
    {
        cin.clear();
    }
}


void Affichage::readme()
{
    system("cls");
    ifstream in("./readme.txt");

    if(!in)
    {
        cout << "Cannot open input file.\n";
    }
    else
    {
        char str[255];

        while(in)
        {
            in.getline(str, 255);  // delim defaults to '\n'
            if(in) cout << str << endl;
        }
        in.close();
    }
    system("pause");
}
void Affichage::pressKey()
{
    cout << endl << "Pressez une touche pour continuer" << endl;
    getch();
}
