/**
 * @file Clavier.h
 * @author DAGUENET Clément
 * @brief Fait sous Visual Studio Code puis remis sous Netbeans
 * @date 2022-02-17
 */
#ifndef CLAVIER_H
#define CLAVIER_H

#include <termios.h>
#include <unistd.h>
#include <cstdio>
#include <iostream>

using namespace std;

class Clavier
{
public:
    enum TOUCHES
    {
        NO,     // ! N'importe quelle touche
        ESCAPE, // ! Touche F
        UP,     // ! Touche Z
        LEFT,   // ! Touche Q
        RIGHT,  // ! Touche D
        DOWN    // ! Touche S
    };
    Clavier();
    ~Clavier();
    static TOUCHES touche_appuyee();

private:
    struct termios state;
};

#endif /* CLAVIER_H */