#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

struct Studentas {
    string vardas, pav;
    vector<int> paz;
    int egzaminas; 
    double galutinis; //Galutinis rezultatas
};

int main()
{
    Studentas A;
    int n; //Pazymiu skaicius
    int suma = 0; //Pazymiu suma (Vidurkiui apskaiciuoti)
    int choice = 0; //Galutinio rez. isvedimo pasirinkimas
    double vidurkis = 0, mediana = 0;

    cout << "Iveskite studento varda ir pavarde: \n"; 
    cout << "Vardas: ";
    //change: do while vardas, pav, n, paz != exception || != null
    cin >> A.vardas;
    cout << "Pavarde: ";
    cin >> A.pav;

    cout << "Iveskite studento pazymiu skaiciu: ";
    cin >> n;

    cout << "Iveskite studento pazymius: \n";
    for (int i = 0; i < n; i++) {
        int temp; //Temp pazymys
        cout << "Pazymys: ";
        cin >> temp;
        A.paz.push_back(temp);
        cout << "\n";

        suma += temp;
    }
    cout << "Iveskite studento egzamino bala: ";
    cin >> A.egzaminas;

    //console.clear()???
    cout << "\nKaip norite isvesti galutini rezultata?\n 1 - Vidurkis, 2 - Mediana\n";
    cin >> choice;
    if(choice == 1){
        vidurkis = suma / (double)n; //Suskaiciuojamas vidurkis
        A.galutinis = 0.4 * vidurkis + 0.6 * A.egzaminas;

        cout << "Pavarde     Vardas         Galutinis(Vid.)\n";
        cout << "------------------------------------------\n";
        cout << A.pav << "           " << A.vardas << "              " << setprecision(2) << A.galutinis;
    }
    else if(choice == 2){
        sort(A.paz.begin(), A.paz.end());
        //Patikrinti medianos radimo buda
        if (n % 2 == 0) {
            mediana = (A.paz[n / 2 - 1] + A.paz[n / 2])/2;
        }
        else {
            mediana = A.paz[n / 2];
        }
        A.galutinis = 0.4 * mediana + 0.6 * A.egzaminas;

        cout << "Pavarde     Vardas         Galutinis(Med.)\n";
        cout << "------------------------------------------\n";
        cout << A.pav << "           " << A.vardas << "              " << A.galutinis;
    }
    else {
        cout << "neveikia";
    }
    return 0;
}