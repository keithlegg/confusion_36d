#ifndef CNC_GLOBALS_H    
#define CNC_GLOBALS_H

//#include <iostream>
//#include <math.h>

#include <vector>

//using std::vector; 


class cncglobals
{

    public: 
        cncglobals(){
        };

        ~cncglobals(){};


        bool GLOBAL_DEBUG           = false;
        bool DEBUG_PARAMS           = false;

        bool ENABLE_LIMIT_SWITCHES  = false;
        bool ENABLE_MOTOR_DRIVE     = false;


        //----------
        //controller hardware config 
        uint parport1_addr = 0;
        uint parport2_addr = 0;

        uint parport2_mode            = 10; // OUT, INOUT
        uint parport2_bytes_per_frame = 4;  //8 bit (byte) * frame  - per data transaction 
        //uint parport2_latency_us      = 10;

        //----------
        //machine travel size in 3D 
        std::string linear_unit = "mm"; //"mm" or "inch" 

        float x_xtntx = 25;
        float y_xtntx = 25;
        float z_xtntx = 25;

        //----------
        //waveform generation parameters
        uint pp1_pulse_dly_us = 200;
        uint pp2_pulse_dly_us = 200;

        //3d pulses per linear unit 
        uint pp1u_x           = 100;
        uint pp1u_y           = 100;
        uint pp1u_z           = 100;

        //----------
        //pin assignments port1
        uint parprt1_dir_x    = 26;
        uint parprt1_step_x   = 26;  
        uint parprt1_dir_y    = 26;
        uint parprt1_step_y   = 26;  
        uint parprt1_dir_z    = 26;
        uint parprt1_step_z   = 26;
        uint parprt1_dir_a    = 26;
        uint parprt1_step_a   = 26;  
        uint parprt1_dir_x_inv   = false;
        uint parprt1_step_x_inv  = false;  
        uint parprt1_dir_y_inv   = false;
        uint parprt1_step_y_inv  = false;  
        uint parprt1_dir_z_inv   = false;
        uint parprt1_step_z_inv  = false;
        uint parprt1_dir_a_inv   = false;
        uint parprt1_step_a_inv  = false;    

        //pin assignments port2
        uint parprt2_dir_x    = 26;
        uint parprt2_step_x   = 26;  
        uint parprt2_dir_y    = 26;
        uint parprt2_step_y   = 26;  
        uint parprt2_dir_z    = 26;
        uint parprt2_step_z   = 26;
        uint parprt2_dir_a    = 26;
        uint parprt2_step_a   = 26;           
        bool parprt2_dir_x_inv    = false;
        bool parprt2_step_x_inv   = false;  
        bool parprt2_dir_y_inv    = false;
        bool parprt2_step_y_inv   = false;  
        bool parprt2_dir_z_inv    = false;
        bool parprt2_step_z_inv   = false;
        bool parprt2_dir_a_inv    = false;
        bool parprt2_step_a_inv   = false;   

        //pin assignments limit switches
        uint x_limitsw_pin  = 26;
        uint y_limitsw_pin  = 26;
        uint z_limitsw_pin  = 26;
        bool x_limitsw_pin_inv = false;
        bool y_limitsw_pin_inv = false;
        bool z_limitsw_pin_inv = false;


        /*******************/
        char* copyString(char[]);

        std::vector<std::string> tokenizer( const std::string&, char);
        int cvt_int( const std::string&);

        void load_cfg_file( char*);
        void show( void );

        //check that all axis are set after running  
        //void verify_axis_set( void );

        //build bitmasks from loded parameters  
        //void verify_axis_set( void );                


};




#endif



