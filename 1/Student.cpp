#include <iostream>
#include <string>
using namespace std;

class Student
{

  string Surn;
  string Name;
  string Patr;
  string Date;
  string Adr;
  string NumbPh;
  string Faculty;
  int Dates;
  int Kurs;

public:
    Student () = default;

    Student(string surname, string name, string Patre, string Adress, string PhoneNumber, string Fac, int date, int Cource)
    {
        Surn = surname;
        Name = name;
        Patr = Patre;
        Adr = Adress;
        NumbPh = PhoneNumber;
        Faculty = Fac;
        Kurs = Cource;
        Dates = date;
    }

    ~Student() = default;



  void setSurn(string surname)
  {
      Surn = surname;
  }

  void setName(string name)
  {
	  Name = name;
  }

  void setPatr(string Patre)
  {
      Patr = Patre;
  }

  void setAdr(string Adress)
  {
      Adr = Adress;
  }

  void setNumbPh(string PhoneNumber)
  {
      NumbPh = PhoneNumber;
  }

  void setFaculty(string Fac)
  {
      Faculty = Fac;
  }

  void setKurs(int Cource)
  {
      Kurs = Cource;
  }

  void setDates(int date)
  {
    Dates = date;
  }




  string getSurn ()
  {
      return Surn;
  }

  string getName ()
  {
      return Name;
  }

  string getPatr ()
  {
      return Patr;
  }

  string getAdr ()
  {
    return Adr;
  }

  string getNumbPh ()
  {
      return NumbPh;
  }

  string getFaculty ()
  {
      return Faculty;
  }
  int getDate()
  {
      return Dates;
  }

  int getKurs ()
  {
    return Kurs;
  }



  void show()
  {
      if (!Surn.empty()) {
          cout << Surn << endl;
          cout << Name << endl;
          cout << Patr << endl;
          cout << Adr << endl;
          cout << NumbPh << endl;
          cout << Faculty << endl;
          cout << Kurs << endl;
      }
  }
};


int main() {
    Student People[5] = {
        Student("Tolmachev",
            "Mikhail",
            "Evgenyevich",
            "R-n-D",
            "81848",
            "MKIMT",
            1999,
            1),
        Student("Vladykin",
            "Ilya",
            "Sergeevich",
            "R-n-D",
            "81848",
            "IIVT",
            2005,
            1),
        Student("Sakhabutdinov",
            "Nikita",
            "Taufikdzhanovich",
            "R-n-D",
            "81848",
            "MKIMT",
            2001,
            1),
        Student("Rybalchenko",
            "DIma",
            "Sergeevich",
            "R-n-D",
            "81848",
            "qewr",
            1999,
            1)
    };
    string fac[2] = { "IIVT", "MKIMT" };


    for (auto peoples : People)
    {
        peoples.show();
        cout << endl;
    }

    cout << "__________" << endl;

    for (auto peoples : People)
    {
        for (auto facultet : fac)
        {
            if (peoples.getFaculty() == facultet)
            {
                peoples.show();
                cout << endl;
            }
        }
    }



    cout << "__________" << endl;



    for (auto peoples : People)
    {
        if (peoples.getDate() >= 2000)
        {
            peoples.show();
            cout << endl;
        }
    }
}
