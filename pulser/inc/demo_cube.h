#ifndef CUBE_DEMO_H    
#define CUBE_DEMO_H



void drawglscene_3d();
void spinningCubeDemo(int *argc, char** argv);

static void ReSizeGLScene(int Width, int Height);
static void keyPressed(unsigned char key, int x, int y);

static void maya_mouse_motion(int x, int y);
static void maya_mouse_button(int button, int state, int x, int y);



#endif