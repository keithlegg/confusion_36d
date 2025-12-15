

#include "gl_setup.h"



extern GLfloat clr_linez[]   ;
extern GLfloat emis_full[]   ;
extern GLfloat emis_half[]   ;
extern GLfloat emis_text[]   ;
extern GLfloat emis_points[] ;
extern GLfloat emis_off[]    ;
extern GLfloat emis_teal[]   ;
extern GLfloat emis_red[]    ;
extern GLfloat emis_green[]  ;
extern GLfloat emis_blue[]   ;
extern GLfloat emis_lines[]  ;
extern GLfloat clr_yellow[]  ;
extern GLfloat clr_green[]   ;
extern GLfloat clr_blue[]    ;


extern GLuint texture[3];


int line_clr_r; //read from setup.olm 
int line_clr_g; 
int line_clr_b; 
int num_pts_drw;


void render_normals(obj_model* pt_model_buffer)
{

    glColor3f(.5,.5,0);
    for (int p_i=0;p_i<pt_model_buffer->num_quads;p_i++)
    {             
        // fetch the pts for a triangle
        Vector3 p1 = pt_model_buffer->points[pt_model_buffer->quads[p_i][0]-1];
        Vector3 p2 = pt_model_buffer->points[pt_model_buffer->quads[p_i][1]-1];
        Vector3 p3 = pt_model_buffer->points[pt_model_buffer->quads[p_i][2]-1];
        // calculate the centroid 
        Vector3 quad_cntr;
        quad_cntr.x = (p1.x + p2.x + p3.x)/3;
        quad_cntr.y = (p1.y + p2.y + p3.y)/3;
        quad_cntr.z = (p1.z + p2.z + p3.z)/3; 
        
        //display shorter for neatness  
        //Vector3 mv =  add(quad_cntr, div(pt_model_buffer->fnormals[p_i], 20 ));
        Vector3 mv =  quad_cntr.operator+(pt_model_buffer->fnormals[p_i].operator/=(20));

        glBindTexture(GL_TEXTURE_2D, texture[0]);
        glMaterialfv(GL_FRONT, GL_EMISSION, clr_yellow);
        glMaterialfv(GL_FRONT, GL_DIFFUSE, emis_off);
        glBegin(GL_LINES);
            glVertex3f(quad_cntr.x, quad_cntr.y, quad_cntr.z);
            glVertex3f(mv.x, mv.y, mv.z);
        glEnd();
        glMaterialfv(GL_FRONT, GL_EMISSION, emis_off);
        glMaterialfv(GL_FRONT, GL_DIFFUSE, emis_full);  
    }

}




void render_quads(obj_model* pt_model_buffer)
{
        // if (toglr_flatshaded){
        //     glColor3f(1.,1.,1.);
        // }

        glBindTexture(GL_TEXTURE_2D, texture[3]);

        glBegin(GL_QUADS);                      

            for (int q_i=0;q_i<pt_model_buffer->num_quads;q_i++)
            { 

                int qu1 = pt_model_buffer->quads[q_i][0];
                int qu2 = pt_model_buffer->quads[q_i][1];
                int qu3 = pt_model_buffer->quads[q_i][2];
                int qu4 = pt_model_buffer->quads[q_i][3];

                //DEBUG VTX COLORS ARE BROKEN - INDEXING ISSUES 
                Vector3 rgb1 = pt_model_buffer->vtxrgb[qu1-1];
                Vector3 rgb2 = pt_model_buffer->vtxrgb[qu2-1];
                Vector3 rgb3 = pt_model_buffer->vtxrgb[qu3-1];
                Vector3 rgb4 = pt_model_buffer->vtxrgb[qu4-1];

                //DEBUG - not working or tested  
                Vector3 nrm1 = pt_model_buffer->vnormals[qu1-1];
                Vector3 nrm2 = pt_model_buffer->vnormals[qu2-1];
                Vector3 nrm3 = pt_model_buffer->vnormals[qu3-1];
                Vector3 nrm4 = pt_model_buffer->vnormals[qu4-1];
     
                /***********************/
                glColor3f(rgb1.x,rgb1.y,rgb1.z);                 
                glTexCoord2f(0.5, 1.0);                
                glNormal3f( nrm1.x, nrm1.y, nrm1.z);
                Vector3 pt1 = pt_model_buffer->points[qu1-1];
                glVertex3f(pt1.x, pt1.y, pt1.z);

                /***********************/
                glColor3f(rgb2.x,rgb2.y,rgb2.z); 
                glTexCoord2f(0.0, 1.0); 
                glNormal3f( nrm2.x, nrm2.y, nrm2.z);
                Vector3 pt2 = pt_model_buffer->points[qu2-1];
                glVertex3f(pt2.x, pt2.y, pt2.z);

                /***********************/
                glColor3f(rgb3.x,rgb3.y,rgb3.z);                 
                glTexCoord2f(1.0, 0.0);   
                glNormal3f( nrm3.x, nrm3.y, nrm3.z);                             
                Vector3 pt3 = pt_model_buffer->points[qu3-1];
                glVertex3f(pt3.x, pt3.y, pt3.z);

                /***********************/
                glColor3f(rgb4.x,rgb4.y,rgb4.z);                 
                glTexCoord2f(1.0, 0.0);      
                glNormal3f( nrm4.x, nrm4.y, nrm4.z);
                Vector3 pt4 = pt_model_buffer->points[qu4-1];
                glVertex3f(pt4.x, pt4.y, pt4.z);


            }
        glEnd(); 
 
}

/***************************************/

void render_vbo(obj_model* pt_model_buffer)
{
    // persistant point buffer   
    // Not tested well! - I think it needs OpenGL4 amd up

    //http://ogldev.atspace.co.uk/www/tutorial02/tutorial02.html 
    //https://stackoverflow.com/questions/28849321/how-to-draw-polygon-with-3d-points-in-modern-opengl
    
    glMaterialfv(GL_FRONT, GL_EMISSION, emis_points);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, emis_off);

    glPointSize(2);

    //-------------------------
    num_pts_drw = pt_model_buffer->num_pts;

    GLfloat vertices[num_pts_drw*4];
    GLfloat* pt_vert = vertices;
    dump_points_GLfloat( pt_vert, pt_model_buffer, num_pts_drw );
    
    // add in custom points loaded from scene.olm  
    //dump_points_GLfloat( pt_vert, pt_scene_drawpoints, num_drawpoints );



    //-------------------------


    GLuint VBO;

    glGenBuffers(1, &VBO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
    //glEnableVertexAttribArray(0);


    // "Enable a port" to the shader pipeline
    glEnableVertexAttribArray(0);
    
    //DEBUG COMMENTED OUT
    //glBindBuffer(GL_ARRAY_BUFFER, VBO);

    // pass information about how vertex array is composed
    glVertexAttribPointer(0, // same as in glEnableVertexAttribArray(0)
                          4, // # of coordinates that build a vertex
                          GL_FLOAT, // data type
                          GL_FALSE, // normalized?
                          0,        // stride
                          (void*)0);// vbo offset


    glDrawArrays(GL_POINTS, 0, num_pts_drw);
    //glDrawArrays(GL_LINES, 0, num_pts_drw);
    glDisableVertexAttribArray(0);
    
    glMaterialfv(GL_FRONT, GL_EMISSION, emis_off);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, emis_full);
}



/***************************************/



void render_lines(obj_model* pt_model_buffer)
{
    glBindTexture(GL_TEXTURE_2D, texture[0]);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, emis_off);
    
    // glEnable(GL_COLOR_MATERIAL);  
    // glColor3f(.5, 0, .5);
        
    for (int p_i=0;p_i<pt_model_buffer->num_lines;p_i++)
    {   
        glBegin(GL_LINES);
            // fetch the line indices from vertex list 
            int lin1 = pt_model_buffer->lines[p_i][0];
            int lin2 = pt_model_buffer->lines[p_i][1];
            
            Vector3 pt1 = pt_model_buffer->points[lin1-1];
            Vector3 pt2 = pt_model_buffer->points[lin2-1];

            //use the same vertex indices to lookup RGB 
            Vector3 c1 = pt_model_buffer->vtxrgb[lin1-1];
            Vector3 c2 = pt_model_buffer->vtxrgb[lin2-1];

            if(c1.x==0){c1.x=line_clr_r;c2.x=line_clr_r;}
            if(c1.y==0){c1.y=line_clr_g;c2.y=line_clr_g;}
            if(c1.z==0){c1.z=line_clr_b;c2.z=line_clr_b;}

            //std::cout << "line color is set to " << c1.x <<" "<< c1.y<< " " << c1.z << "\n";
            glMaterialfv(GL_FRONT, GL_EMISSION, clr_linez);
            glColor3f(c1.x, c1.y, c1.z);   
            glVertex3f(pt1.x, pt1.y, pt1.z);

            glColor3f(c2.x, c2.y, c2.z);  
            glVertex3f(pt2.x, pt2.y, pt2.z);

        glEnd();
    }

    glMaterialfv(GL_FRONT, GL_EMISSION, emis_off);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, emis_full);  
}




/***************************************/



