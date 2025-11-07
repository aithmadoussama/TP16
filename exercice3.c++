#include <iostream>
#include <vector>
#include <string>
using namespace std;

class observateur {
public:
    virtual void mettreajour(float temp, float hum, float pres) = 0;
    virtual ~observateur() = default;
};

class stationmeteo {
    vector<observateur*> observateurs;
    float temperature, humidite, pression;
public:
    void ajouter(observateur* o) { observateurs.push_back(o); }
    void setmesures(float t, float h, float p) {
        temperature = t;
        humidite = h;
        pression = p;
        notifier();
    }
    void notifier() {
        for (auto o : observateurs)
            o->mettreajour(temperature, humidite, pression);
    }
};

class affichagetemperature : public observateur {
public:
    void mettreajour(float temp, float, float) override {
        cout << "temperature : " << temp << "°c" << endl;
    }
};

class affichagehumidite : public observateur {
public:
    void mettreajour(float, float hum, float) override {
        cout << "humidite : " << hum << "%" << endl;
    }
};

int main() {
    stationmeteo station;
    affichagetemperature temp;
    affichagehumidite hum;
    station.ajouter(&temp);
    station.ajouter(&hum);
    station.setmesures(25.5, 60, 1013);
    return 0;
}
