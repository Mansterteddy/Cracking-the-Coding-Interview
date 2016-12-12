#ifndef __AIRPLANES__H__
#define __AIRPLANES__H__

class Jet_Engine {};

class Airplane {};

class Jet_Plane: public Airplane
{
    private:
        int num_engines;
        Jet_Engine jets[4];
};

#endif
