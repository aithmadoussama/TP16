#include <iostream>
#include <string>
using namespace std;

class forme
{
public:
    virtual void afficher() const = 0;
    virtual ~forme() = default;
};

class cercle : public forme {
    double rayon;
public:
    cercle(double r = 1.0) : rayon(r) {}
    void afficher() const override {
        cout << "cercle de rayon " << rayon << endl;
    }
};

class carre : public forme {
    double cote;
public:
    carre(double c = 1.0) : cote(c) {}
    void afficher() const override {
        cout << "carre de cote " << cote << endl;
    }
};

class triangle : public forme {
    double base, hauteur;
public:
    triangle(double b = 1.0, double h = 1.0) : base(b), hauteur(h) {}
    void afficher() const override {
        cout << "triangle de base " << base << " et de hauteur " << hauteur << endl;
    }
};

class fabriquedeforme {
public:
    static forme* creer(const string& type) {
        if (type == "cercle") {
            return new cercle(5.0);
        } 
        else if (type == "carre") {
            return new carre(4.0);
        } 
        else if (type == "triangle") {
            return new triangle(3.0, 6.0);
        } 
        else {
            cout << "type inconnu : " << type << endl;
            return nullptr;
        }
    }
};

int main() {
    forme* f1 = fabriquedeforme::creer("cercle");
    forme* f2 = fabriquedeforme::creer("carre");
    forme* f3 = fabriquedeforme::creer("triangle");
    forme* f4 = fabriquedeforme::creer("etoile");

    if (f1) f1->afficher();
    if (f2) f2->afficher();
    if (f3) f3->afficher();

    delete f1;
    delete f2;
    delete f3;
    delete f4;

    return 0;
}
