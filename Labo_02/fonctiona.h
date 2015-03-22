/**
    FonctionA - Full Fonction Declaration File
    FunctionA is derived from Fonction.
    Purpose: Contain the fonction  "sin(x) - x/13"

    @author Equipe 6 (Bitter Lukas, Da Mota Marques Fabio Manuel, Divernois Margaux, Visinand Steve)
*/

#ifndef FONCTIONA_H
#define FONCTIONA_H

#include "fonction.h"
#include "math.h"

class FonctionA : public Fonction
{
    public:
        FonctionA() {}
        virtual ~FonctionA() {}

        double f(double x) { return sin(x)-x/13; }

    protected:
    private:
};

#endif // FONCTIONA_H
