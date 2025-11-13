#ifndef CNC_PLOT_H    
#define CNC_PLOT_H

//#include <iostream>
//#include <math.h>

#include <vector>
using std::vector;  

#include "math_op.h"


class cnc_plot
{
    public:
        cnc_plot(){};
        ~cnc_plot(){};

    void gen_pules(std::vector<int>*, int, int);

    void gen_3d_pules(std::vector<vec3>*, int, int);

    void calc_3d_pulses(std::vector<vec3>*,
                        vec3, 
                        vec3,
                        int);


    //void load_config_file(char*);

};



#endif

