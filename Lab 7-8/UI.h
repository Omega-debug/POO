//
// Created by Mihnea Marinescu on 29.04.2023.
//

#ifndef LAB_7_8_UI_H
#define LAB_7_8_UI_H
#include"Service.h"

class UI {
private:
    Service service;

    int printMenu();
    void addTranzaction();
    void modificaTranzactie();
    void removeTranzactionZii();

    void printAll();
    void printAll_IN();
    void printAll_OUT();
    void printAll_Mai_Mare_Ca();
    void printAll_Egal();

    void soldulet();
    void SUMA_IN();
    void T_MAX_OUT();

    void FiltruIN();
    void FiltruIN2();

    void UNDO();

public:
    UI(Service &otherService);
    ~UI() = default;

    void start();
};


#endif //LAB_7_8_UI_H
