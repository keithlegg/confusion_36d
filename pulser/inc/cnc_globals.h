#ifndef CNC_GLOBALS_H    
#define CNC_GLOBALS_H

//#include <iostream>
//#include <math.h>

#include <vector>

//using std::vector; 


/*
// ####################################
// #MACHINE PROPERTIES 
// ####################################

//##INTERFACE 1 (motion)
//# address of the parallel port 

int PARPORT1_ADDR = 0xc010;
int PARPORT2_ADDR = 0xc010;


int PP1_PULSE_DLY_US = 10;
int PP1_STEPS_PER_UNIT_X = 100;
int PP1_STEPS_PER_UNIT_Y = 100;
int PP1_STEPS_PER_UNIT_Z = 100;

// ####################################
// ##INTERFACE 2 (data)
// PP2_LATENCY_US 10
// PP2_BYTES_PER_FRAME 4
// PP2_MODE_INOUT INOUT 

// ####################################
// # OUTPUTS 
// ####################################
// # PIN MAPPING - I.E. wchich pin controls which motor 
// PP1_XDIR  DB25_1 
// PP1_XSTEP DB25_2 
// PP1_YDIR  DB25_3 
// PP1_YSTEP DB25_4 
// PP1_ZDIR  DB25_5 
// PP1_ZSTEP DB25_6 
// #A axis is theta for head!
// PP1_ADIR  DB25_5 
// PP1_ASTEP DB25_6 
// # PP1_INV_XDIR DB25_7 
// # PP1_INV_YDIR DB25_8 
// # PP1_INV ZDIR DB25_9

// ####################################
// # INPUTS 
// ####################################
// X_LIMIT
// Y_LIMIT 
// Z_LIMIT 
*/

class cncglobals
{

    public: 
        cncglobals(){
        };

        ~cncglobals(){};
        //----------

        //DEBUG needs to be 16 bit int 
        //char parport1_addr[10];
        //char parport2_addr[10];
        // char parport3_addr[10];
        // char parport4_addr[10];
        uint parport1_addr = 0;
        uint parport2_addr = 0;

        //machine travel size in 3D 
        uint x_xtntx = 25;
        uint y_xtntx = 25;
        uint z_xtntx = 25;

        //waveform generation parameters
        uint pp1_pulse_x_dly_us = 200;
        uint pp1_pulse_y_dly_us = 200;
        uint pp1_pulse_z_dly_us = 200;

        //3d pulses per linear unit 
        uint pp1lu_x = 100;
        uint pp1lu_y = 100;
        uint pp1lu_z = 100;

        //pin assignments
        uint parprt1_dir_x  = 26;
        uint parprt1_step_x = 26;  
        uint parprt1_dir_y  = 26;
        uint parprt1_step_y = 26;  
        uint parprt1_dir_z  = 26;
        uint parprt1_step_z = 26;
        uint parprt1_dir_a  = 26;
        uint parprt1_step_a = 26;    
        
        uint x_limit_pin    = 26;
        uint y_limit_pin    = 26;
        uint z_limit_pin    = 26;


        /*******************/
        void load_cfg_file( char*);
        void show( void );
        

};




#endif



