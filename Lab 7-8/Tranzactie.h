//
// Created by Mihnea Marinescu on 24.04.2023.
//

class Tranzactie {
private:
    int ziua;
    int suma;
    char *tip;
    char *descriere;

public:
    Tranzactie();
    Tranzactie(int ziua, int suma, char *tip, char *descriere);
    Tranzactie(const Tranzactie  &otherTranzactie);
    Tranzactie(Tranzactie&& other);

    ~Tranzactie();

    Tranzactie &operator=(const Tranzactie &otherTranzactie);
    bool operator==(const Tranzactie &t);

    int getZiua();
    int getSuma();
    char *getTip();
    char *getDescriere();

    void setZiua(int ziua);
    void setSuma(int suma);
    void setTip(char *tip);
    void setDescriere(char *descriere);



};


