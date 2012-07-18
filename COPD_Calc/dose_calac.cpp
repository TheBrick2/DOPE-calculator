#include <algorithm>
#include <iostream>
#include "dose_calac.h"
#include <QtDebug>


// This object store the info mation and method to caulate the DOSE index score.

DOSE_Calac::DOSE_Calac()
{
    // constuctor
    dyspnoeaScale = 0;
    fev1 = 0;
    smoker = false;
    anualExacerbations = 0;
    doseIndexPoints = 0;
}

int DOSE_Calac::CalcDOSEPoints()
{
    // function for caulating DOSE indexpoints
    int err;

    this->doseIndexPoints = 0;

    if (this->dyspnoeaScale < 0 || this->dyspnoeaScale > 4)
    {
        std::cerr << "Error:Dyspnea scale must be between 0 and 4.";
        err = 1;
        throw err;
        return err;
    }
    else
    {
        this->doseIndexPoints += std::max(0,(int) this->dyspnoeaScale - 1);
    }

    qDebug()<<"P1 " << doseIndexPoints;

    if (this->fev1 <= 0)
    {
        std::cerr << "Error: fev1% must be greater than zero.";
        err = 2;
        return err;
    }
    else if (this->fev1 < 30)
    {
        this->doseIndexPoints += 2;
    }
    else if (this->fev1 >= 30 && this->fev1 < 50)
    {
        this->doseIndexPoints += 1;
    } // otherwise no point.

    qDebug()<<"P2 " << doseIndexPoints;

    if (this->smoker) this->doseIndexPoints += 1;

    qDebug()<<"P3 " << doseIndexPoints;

    // number of exacerbations per year.

    if (this->anualExacerbations > 3)
    {
        this->doseIndexPoints += 2;
    }
    else if (this->anualExacerbations > 2)
    {
        this->doseIndexPoints += 1;
    }

    qDebug()<<"P4 " << doseIndexPoints;

    return 0;

}
