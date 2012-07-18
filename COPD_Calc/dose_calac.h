#ifndef DOSE_CALAC_H
#define DOSE_CALAC_H

class DOSE_Calac
{
public:
// constructor
    DOSE_Calac();
// get functions
    int GetDyspnoeaScale(){return dyspnoeaScale;}
    int GetFev1(){return fev1;}
    bool GetSmoker(){return smoker;}
    int GetAnualExacerbations(){return anualExacerbations;}
    int GetdoseIndexPoints(){return doseIndexPoints;}
// set functions
    void SetDyspnoeaScale(int in_DysponeaScale){dyspnoeaScale = in_DysponeaScale;}
    void SetFev1(int in_Fev1){fev1 = in_Fev1;}
    void SetSmoker(bool in_Smoker){smoker = in_Smoker;}
    void SetAnualExacerbations(int in_AnualExacerbations){anualExacerbations = in_AnualExacerbations;}
// function for caulating DOSE indexpoints
    int CalcDOSEPoints();
private:
    unsigned int dyspnoeaScale;
    unsigned int fev1;
    bool smoker;
    unsigned int anualExacerbations;
    unsigned int doseIndexPoints;

};

#endif // DOSE_CALAC_H
