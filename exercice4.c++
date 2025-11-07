#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class strategietri {
public:
    virtual void trier(vector<string>& v) = 0;
    virtual ~strategietri() = default;
};

class tricroissant : public strategietri {
public:
    void trier(vector<string>& v) override {
        sort(v.begin(), v.end());
    }
};

class tridecroissant : public strategietri {
public:
    void trier(vector<string>& v) override {
        sort(v.rbegin(), v.rend());
    }
};

class triparlongueur : public strategietri {
public:
    void trier(vector<string>& v) override {
        sort(v.begin(), v.end(), [](const string& a, const string& b) {
            return a.size() < b.size();
        });
    }
};

class gestionnairetri {
    strategietri* strategie;
public:
    gestionnairetri(strategietri* s = nullptr) : strategie(s) {}
    void definirstrategie(strategietri* s) { strategie = s; }
    void trier(vector<string>& v) {
        if (strategie) strategie->trier(v);
    }
};

int main() {
    vector<string> mots = {"banane", "pomme", "kiwi", "fraise"};
    gestionnairetri g;
    tricroissant croissant;
    tridecroissant decroissant;
    triparlongueur longueur;

    g.definirstrategie(&croissant);
    g.trier(mots);
    for (auto& m : mots) cout << m << " ";
    cout << endl;

    g.definirstrategie(&decroissant);
    g.trier(mots);
    for (auto& m : mots) cout << m << " ";
    cout << endl;

    g.definirstrategie(&longueur);
    g.trier(mots);
    for (auto& m : mots) cout << m << " ";
    cout << endl;

    return 0;
}
