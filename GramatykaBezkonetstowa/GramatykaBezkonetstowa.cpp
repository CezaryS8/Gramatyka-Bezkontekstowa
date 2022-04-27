// GramatykaBezkonetstowa.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <iostream>
#include <string>
#include <ctime>
#include <algorithm>

using namespace std;

string S();
string A();
string B();
void wys_pos_kan(string lancuchy[], int max, int n);
void opis();

bool czy_unik(string lancuchy[], int ile) {

    for (int i = 0; i < ile; i++) {
        if (lancuchy[i] == lancuchy[ile])
            return false;
    }
    return true;
}

int main()
{
    srand(time(NULL));
    int n;
    int max_l = 0;
    opis();
    cout << "Ile różnych łańcuchów wypisać? " << endl;
    cin >> n;
    cout << endl;
    string * lancuchy = new string[n];
  
    for (int i = 0; i < n; i++) {
        lancuchy[i] = S();
        while (!czy_unik(lancuchy, i))
            lancuchy[i] = S();

        if (lancuchy[i].length() > max_l)
            max_l = lancuchy[i].length();
    }
    wys_pos_kan(lancuchy, max_l, n);
}



string S() {
    return A() + "0" + B();
}

string A() {
    if (rand() % 2) return "0" + A();
    else return "";
}

string B() {
    int r = rand() % 3;
    if (r == 2) return "0" + B();
    else if (r == 1) return "1" + B();
    else return "";
}

void wys_pos_kan(string lancuchy[], int max, int n) {
    for (int i = 1; i < n; i++) {
        for (int j = i; j >= 1; j--) {
            int al = lancuchy[j].length();
            int bl = lancuchy[j - 1].length();
            if (al < bl)
                swap(lancuchy[j], lancuchy[j - 1]);
            else if (al == bl) {
                if (lancuchy[j] < lancuchy[j - 1])
                    swap(lancuchy[j], lancuchy[j - 1]);
            }
        }
    }
    for (int i = 0; i < n; i++)
        cout << lancuchy[i] << endl;
}

void opis() {
    cout << "Gramatyka bezkontekstowa" << endl;
    cout << "G = ( V, T, P, S ) , gdzie" << endl;
    cout << "V = { S, A, B }," << endl;
    cout << "T = { 0, 1 }," << endl;;
    cout << "P = { S→A0B,   A→0A|ε,   B→0B|1B|ε }" << endl << endl;

}
