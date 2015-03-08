#include "affichage.h"
#include "floatencode.h"
#include <fstream>

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
    cout<<"**         Algorithmes numeriques Labo 1       **"<<endl;
    cout<<"**   Codage d'un nombre flottant sur 17 bits   **"<<endl;
    cout<<"*************************************************"<<endl;
    cout<<endl<<endl;
}

void Affichage::menu()
{
    cout<<"  1. Encodage d'un nombre"<<endl;
    cout<<"  2. Additionner deux nombres"<<endl;
    cout<<"  3. Informations"<<endl;
    cout<<"  4. Readme"<<endl;
    cout<<"  9. Fin"<<endl;
    cout<<endl;
}

int Affichage::menuBegin()
{
    int rep = 0;

    header();
    menu();
    cout<<"  Saisissez un choix du menu (1 a 9): ";
    cin>>rep;
    return rep;
}

int Affichage::menuNotValid()
{
    int rep = 0;

    header();
    menu();
    cout<<"  Commande non valide. Recommencez. "<<endl;
    cout<<"  Saisissez un choix du menu (1 a 9): ";
    cin>>rep;
    return rep;
}

void Affichage::info()
{
    header();
    cout<<"  info"<<endl;
    cout<<endl;
    system("pause");
}

void Affichage::encode()
{
    double num = 0;

    header();
    cout<<"  Saisissez un nombre a encoder: ";
    cin>>num;
    // ici faire un test si num est bien un nombre
    FloatEncode userFloat(num);
    cout<<"  Le nombre encode vaut: "<<userFloat.getBitset()<<endl<<endl;
    cout<<"  s = "<<userFloat.get_s()<<endl;
    cout<<"  e = "<<userFloat.get_e()<<endl;
    cout<<"  m = "<<userFloat.get_m()<<endl<<endl;
    cout<<"  Le nombre decode vaut: "<<userFloat.getDouble()<<endl<<endl;
    system("pause");
}

void Affichage::addition()
{
    double num1 = 0;
    double num2 = 0;

    header();
    cout<<"  Saisissez un premier nombre: ";
    cin>>num1;
    cout<<"  Saisissez un second nombre: ";
    cin>>num2;

    // ici faire un test si num est bien un nombre
    FloatEncode userFloat1(num1);
    FloatEncode userFloat2(num2);
    FloatEncode result(0);
    result = FloatEncode::add(userFloat1, userFloat2);

    cout<<"  Le nombre encode vaut: "<<result.getBitset()<<endl<<endl;
    cout<<"  s = "<<result.get_s()<<endl;
    cout<<"  e = "<<result.get_e()<<endl;
    cout<<"  m = "<<result.get_m()<<endl<<endl;
    cout<<"  Le nombre decode vaut: "<<result.getDouble()<<endl<<endl;
    system("pause");
}

void Affichage::readme()
{

 ifstream in("./readme.txt");

  if(!in) {
    header();
    cout << "Cannot open input file.\n";
  }
  else {

      char str[255];

      while(in) {
        in.getline(str, 255);  // delim defaults to '\n'
        if(in) cout << str << endl;
      }
      in.close();
  }
  system("pause");
}

