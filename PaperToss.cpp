/* Snowman sample 
 * by R. Teather
 * Edited by Noel Brett
 */
/* 
 Borna Kalantar kalantb 001207031
 Rebecca Tran tranr5 001425611
 Neil Robichaud robichne 001425566
 Sean McKay mckaysm 001423885
 */

#ifdef __APPLE__
#  include <OpenGL/gl.h>
#  include <OpenGL/glu.h>
#  include <GLUT/glut.h>
#else
#  include <GL/gl.h>
#  include <GL/glu.h>
#  include <GL/freeglut.h>
#endif
#include <stdio.h>
#include <stdlib.h>
#include <ctime>
#include <cmath>
#include <string>
#include "math3D.h"
#include <string>
#include <sstream>

using namespace std;
int firstwindow;
int secondwindow;

float amb0[4] = {1,1,1,1};
float diff0[4] = {1,1,1,1};
float spec0[4] = {1,1,1,1};

float m_amb[] = {0.33, 0.22, 0.03, 1.0}; 
float m_diff[] = {0.78, 0.57, 0.11, 1.0}; 
float m_spec[] = {0.99, 0.91, 0.81, 1.0}; 
float shiny = 27.8;
float yAngle = 0;
float xAngle = 0;
int intscorecounter = 0;
string stringscorecounter = "";
const char* counterstring;
float boxDepth = 5;
bool selected = false;
bool throwing = false;
bool launched = false;
int startingMousepos[2];
int finalMousepos[2];
float startTime;
float endTime;
float averageXVelocity;
float averageZVelocity;

float windspeed = 0;
float position[] = {0,1,-4};
float startingPos[] = {0,1,-4};
float basketPos[] = {0, 0, 4};
float basketRadius = 1;
float velocity[]  = {0,0,0};
float acceleration[] = {windspeed,-100,0};

//brass
float m_amb1[] = {0.135, 0.2225, 0.1575, 1.0}; //setting the material for the ambient, diffuse and specular values
float m_diff1[] = {0.54, 0.89, 0.63, 1.0}; 
float m_spec1[] = {0.316228, 0.316228, 0.316228, 1.0}; 
float shiny1 = 0.1;

//obsidian 
// float m_amb1[] = {0.05375, 0.05, 0.06625, 1.0}; //setting the material for the ambient, diffuse and specular values
// float m_diff1[] = {0.18275, 0.17, 0.22525, 1.0}; 
// float m_spec1[] = {0.332741, 0.328634, 0.346435, 1.0}; 
// float shiny1 = 0.3; 

float m_amb2[] = {0.0, 0.0, 0.0, 1.0}; //setting the material for the ambient, diffuse and specular values black plastic
float m_diff2[] = {0.01, 0.01, 0.01, 1.0}; 
float m_spec2[] = {0.50, 0.50, 0.50, 1.0}; 
float shiny2 = 0.25; 

float m_amb3[] = {0.0, 0.0, 0.0, 1.0}; //setting the material for the ambient, diffuse and specular values white plastic
float m_diff3[] = {0.55, 0.55, 0.55, 1.0}; 
float m_spec3[] = {0.70, 0.70, 0.70, 1.0}; 
float shiny3 = 0.25; 

float m_amb4[] = {0.25, 0.20725, 0.20725, 1.0}; //setting the material for the ambient, diffuse and specular values pearl for ball
float m_diff4[] = {1.00, 0.829, 0.829, 1.0}; 
float m_spec4[] = {0.296648, 0.296648, 0.296648, 1.0}; 
float shiny4 = 0.088; 

/*** 
 EYE LOCATION
 ***/
float eye[] = {0,1,-7};
float lookat[] = {0,0,0};
float light1_pos[]= {0,4,-4,1}; //last num one is pofloat light
float light2_pos[]= {0,0,0,1}; //last num one is pofloat light


float angle1 = 0.0f;
/* display function - GLUT display callback function
 *      clears the screen, sets the camera position, draws the ground plane and movable box
 */
int mapSize = 300;
float heightMap[1000][1000];
int maxX = mapSize;
int maxZ = mapSize;

//self explanatory various states of the mesh
enum mode{solid, wire, both};
mode currentMode;

enum shading{smooth, flat};
shading currentShading;

bool triangles;
bool lighting;

enum mapType {fault, circles};
mapType currentMap;

bool vertexShading;


float minHeight = 0;
float maxHeight = 0;


// BORNA UPDATE FROM HERE

float eyeradius = 7;
float eyetheta = 4.71;
float eyephi = 1.43;

float lookatradius = 0;
float lookattheta = 0;
float lookatphi = 0;

// x = eyeradius * sin(eyephi) * cos(eyetheta)
// y = eyeradius  * cos(eyephi)
// z = eyeradius * sin(eyetheta) * sin(eyephi)

bool textureToggle = false;
bool textureWall = true;
int text = 2;

GLubyte *img_data1;
GLubyte *img_data2;
GLubyte *img_data3;
// GLubyte *img_data4;
// GLubyte *img_data5;

GLuint textures[3];
int width, height, ppmax;  //width, height, max variables for the file of the texures

GLUquadricObj *sphereOBJ = NULL;

void drawBall(){
    glPushMatrix();
        glTranslatef(position[0],position[1],position[2]);
        //printf("%f",position[1]);
        // glBindTexture(GL_TEXTURE_2D, textures[0]);
        glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT,  m_amb4); //putting material onto the terrain
        glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE,  m_diff4); 
        glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR,  m_spec4); 
        glMaterialf(GL_FRONT_AND_BACK, GL_SHININESS,  shiny4);

        sphereOBJ = gluNewQuadric();
        gluQuadricDrawStyle(sphereOBJ, GLU_FILL);
        gluQuadricTexture(sphereOBJ, GL_TRUE);
        gluQuadricNormals(sphereOBJ, GLU_SMOOTH);
        

        gluSphere(sphereOBJ, 1, 100, 100);
    glPopMatrix();
}

GLubyte* LoadPPM(char* file, int* width, int* height, int* ppmax)
{
    GLubyte* img;
    FILE *fd;
    int n, m;
    int  k, nm;
    char c;
    int i;
    char b[100];
    float s;
    int red, green, blue;
    
    //first open file and check if it's an ASCII PPM (indicated by P3 at the start)
    fd = fopen(file, "r");
    fscanf(fd,"%[^\n] ",b);
    if(b[0]!='P'|| b[1] != '3')
    {
        printf("%s is not a PPM file!\n",file);
        exit(0);
    }
    printf("%s is a PPM file\n", file);
    fscanf(fd, "%c",&c);
    
    //next, skip past the comments - any line starting with #
    while(c == '#')
    {
        fscanf(fd, "%[^\n] ", b);
        printf("%s\n",b);
        fscanf(fd, "%c",&c);
    }
    ungetc(c,fd);
    
    // now get the dimensions and max colour value from the image
    fscanf(fd, "%d %d %d", &n, &m, &k);
    
    printf("%d rows  %d columns  max value= %d\n",n,m,k);
    
    // calculate number of pixels and allocate storage for this
    nm = n*m;
    img = (GLubyte*)malloc(3*sizeof(GLuint)*nm);
    s=255.0/k;
    
    // for every pixel, grab the read green and blue values, storing them in the image data array
    for(i=0;i<nm;i++)
    {
        fscanf(fd,"%d %d %d",&red, &green, &blue );
        img[3*nm-3*i-3]=red*s;
        img[3*nm-3*i-2]=green*s;
        img[3*nm-3*i-1]=blue*s;
    }
    
    // finally, set the "return parameters" (width, height, max) and return the image array
    *width = n;
    *height = m;
    *ppmax = k;
    
    return img;
}

// textures function
void initTexture(void) {
    img_data1 = LoadPPM("hay.ppm", &width, &height, &ppmax);    //loading the texture by using the LoadPPM function, into img_data1
    img_data2 = LoadPPM("tree.ppm", &width, &height, &ppmax);
    img_data3 = LoadPPM("crates.ppm", &width, &height, &ppmax);
    // img_data4 = LoadPPM("city.ppm", &width, &height, &ppmax);
    // img_data5 = LoadPPM("city.ppm", &width, &height, &ppmax);
    
    //enabling textures
    glEnable(GL_TEXTURE_2D);
    
    glGenTextures(3, textures); //using three textures
    glBindTexture(GL_TEXTURE_2D, textures[0]);  //binding the first texture stored in the textures array
    
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, img_data1); //getting the necessary information of the texture
    
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);   //setting parameters
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT );
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    
    glBindTexture(GL_TEXTURE_2D, textures[1]);  //binding the first texture stored in the textures array
    
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, img_data2); //getting the necessary information of the texture
    
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);   //setting parameters
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT );
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    
    glBindTexture(GL_TEXTURE_2D, textures[2]);  //binding the first texture stored in the textures array
    
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, img_data3); //getting the necessary information of the texture
    
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);   //setting parameters
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT );
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);

    // glBindTexture(GL_TEXTURE_2D, textures[3]);  //binding the first texture stored in the textures array
    
    // glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, img_data4); //getting the necessary information of the texture
    
    // glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);   //setting parameters
    // glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT );
    // glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    // glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);

    // glBindTexture(GL_TEXTURE_2D, textures[4]);  //binding the first texture stored in the textures array
    
    // glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, img_data5); //getting the necessary information of the texture
    
    // glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);   //setting parameters
    // glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT );
    // glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    // glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
}

void updateeyeposition(){
    
    eye[0] = eyeradius * sin(eyephi) * cos(eyetheta);
    eye[1] = eyeradius  * cos(eyephi);
    eye[2] = eyeradius * sin(eyetheta) * sin(eyephi);
    
}

void updatelookatposition(){
    
    lookat[0] = lookatradius * sin(lookatphi) * cos(lookattheta);
    lookat[1] = lookatradius  * cos(lookatphi);
    lookat[2] = lookatradius * sin(lookattheta) * sin(lookatphi);
}

// BORNA UPDATE TO HERE
void textprinter(int x, int y, char* text)
{
    glMatrixMode(GL_PROJECTION);
    glPushMatrix();
    glLoadIdentity();
    glOrtho(0, 800, 0, 800, -1, 1);
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glLoadIdentity();
    //glDisable(GL_DEPTH_TEST);
    glRasterPos2i(x,y);

    glColor3f(0,0,1);
    char* c;  //character iterator (ptr)
    for(c = text; *c != '\0'; c++) //stop when we hit null character
    {
        glutBitmapCharacter(GLUT_BITMAP_9_BY_15, *c); //print one char
    }
    glMatrixMode(GL_PROJECTION);
    glPopMatrix();
    glMatrixMode(GL_MODELVIEW);
    glPopMatrix();
//    glEnable(GL_DEPTH_TEST);
    
}
void changetostring(int integer){
    
    stringstream streamint;
    
    streamint << integer;
    
    stringscorecounter = streamint.str();
    
    counterstring = stringscorecounter.c_str();;
    
}
void drawFloor(){
   
    glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT,  m_amb1); //putting material onto the terrain
    glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE,  m_diff1); 
    glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR,  m_spec1); 
    glMaterialf(GL_FRONT_AND_BACK, GL_SHININESS,  shiny1*128);

    //floor
    glPushMatrix();
        glBindTexture(GL_TEXTURE_2D, textures[3]);
        
        glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
        glColor3f(1, 1, 1);
        glBegin(GL_QUADS);
            glTexCoord2f(0, 0);
            glVertex3f(5, 0, 5);

            glTexCoord2f(0, 1);
            glVertex3f(5, 0, -5);

            glTexCoord2f(1, 1);
            glVertex3f(-5, 0, -5);

            glTexCoord2f(1, 0);
            glVertex3f(-5, 0, 5);
        glEnd();
    glPopMatrix();
    
    //ceiling
    glPushMatrix();
        // glBindTexture(GL_TEXTURE_2D, textures[3]);

        glTranslatef(0, 10, 0);
        glBegin(GL_QUADS);
            glTexCoord2f(0, 0);
            glVertex3f(5, 0, 5);

            glTexCoord2f(0, 1);
            glVertex3f(5, 0, -5);

            glTexCoord2f(1, 1);
            glVertex3f(-5, 0, -5);

            glTexCoord2f(1, 0);
            glVertex3f(-5, 0, 5);
        glEnd();
    glPopMatrix();
    
    //right wall
    glPushMatrix();
        // glBindTexture(GL_TEXTURE_2D, textures[3]);

        glTranslatef(-5, 5, 0);
        glRotatef(90, 0, 0, 1);
        glBegin(GL_QUADS);
            glTexCoord2f(0, 0);
            glVertex3f(5, 0, 5);

            glTexCoord2f(0, 1);
            glVertex3f(5, 0, -5);

            glTexCoord2f(1, 1);
            glVertex3f(-5, 0, -5);

            glTexCoord2f(1, 0);
            glVertex3f(-5, 0, 5);
            glEnd();
    glPopMatrix();
    
    //left wall
    glPushMatrix();
        // glBindTexture(GL_TEXTURE_2D, textures[3]);

        glTranslatef(5, 5, 0);
        glRotatef(90, 0, 0, 1);
        glBegin(GL_QUADS);
            glTexCoord2f(0, 0);
            glVertex3f(5, 0, 5);

            glTexCoord2f(0, 1);
            glVertex3f(5, 0, -5);

            glTexCoord2f(1, 1);
            glVertex3f(-5, 0, -5);

            glTexCoord2f(1, 0);
            glVertex3f(-5, 0, 5);
        glEnd();
    glPopMatrix();
    
    //back wall
    // glBindTexture(GL_TEXTURE_2D, textures[3]);
    glPushMatrix();

        glTranslatef(0, 5, 5);
        glRotatef(90, 1, 0, 0);
        glBegin(GL_QUADS);
            glTexCoord2f(0, 0);
            glVertex3f(5, 0, 5);

            glTexCoord2f(0, 1);
            glVertex3f(5, 0, -5);

            glTexCoord2f(1, 1);
            glVertex3f(-5, 0, -5);

            glTexCoord2f(1, 0);
            glVertex3f(-5, 0, 5);
        glEnd();
    glPopMatrix();
}

void resetBall() {
    position[0] = startingPos[0]; position[1] = startingPos[1]; position[2] = startingPos[2];
    velocity[0] = 0.0f; velocity[1] = 0.0f; velocity[2] = 0.0f;
    acceleration[0] = windspeed; acceleration[1] = -100.0f; acceleration[2] = 0.0f;
    launched = false;
}

void drawBasket() {
    glColor3f(1,0,0);
    glPushMatrix();
        glTranslatef(basketPos[0], basketPos[1], basketPos[2]);
        glRotatef(90, 1, 0, 0);
        glutSolidTorus(basketRadius / 2, basketRadius, 100, 100);
    glPopMatrix();
}

float pos[] = {0,1,0};
float rot[] = {0, 0, 0};
float headRot[] = {0, 0, 0};

int counter = 0;
bool movingRight = true;

void DrawSnowman(float* pos, float* rot){
    glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT,  m_amb3); //putting material onto the terrain
    glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE,  m_diff3); 
    glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR,  m_spec3); 
    glMaterialf(GL_FRONT_AND_BACK, GL_SHININESS,  shiny3*128);

    glPushMatrix();
    // printf("%i\n", counter);
        if(movingRight == true){
            if(counter > -50){
                glTranslatef(0.1*counter,0,0);
                counter--;
            } else if (counter == -50){
                glTranslatef(0.1*counter,0,0);
                counter++;
                movingRight = false;
            } 
        }

        if(movingRight == false){
            if(counter < 50){
                glTranslatef(0.1*counter,0,0);
                counter++;
                
            } else if(counter == 50){
                glTranslatef(0.1*counter,0,0);
                counter--;
                movingRight = true;
            } 
        }

        glPushMatrix();

            glTranslatef(pos[0], pos[1], pos[2]);
            // glRotatef(rot[1], 0, 1, 0);
            glRotatef(180,0,1,0);

            //draw body
            glColor3f(1,1,1);
            glutSolidSphere(1, 16, 16);

            glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT,  m_amb2); //putting material onto the terrain
            glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE,  m_diff2); 
            glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR,  m_spec2); 
            glMaterialf(GL_FRONT_AND_BACK, GL_SHININESS,  shiny2*128);

            //draw buttons
            glPushMatrix();
                glTranslatef(0, 0.35, 0.9);
                glColor3f(0, 0, 0);
                glutSolidSphere(0.1, 10, 10);
            glPopMatrix();

            glPushMatrix();
                glTranslatef(0, 0.15, 0.95);
                glColor3f(0, 0, 0);
                glutSolidSphere(0.1, 10, 10);
            glPopMatrix();

            glPushMatrix();
                glTranslatef(0, -0.05, 0.95);
                glColor3f(0, 0, 0);
                glutSolidSphere(0.1, 10, 10);
            glPopMatrix();


            glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT,  m_amb3); //putting material onto the 
            glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE,  m_diff3); 
            glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR,  m_spec3); 
            glMaterialf(GL_FRONT_AND_BACK, GL_SHININESS,  shiny3*128);

            glPushMatrix();
                //translate relative to body, and draw head
                glTranslatef(0, 1.25, 0);
                glRotatef(headRot[1], 0, 1, 0); //turn the head relative to the body
                glColor3f(1,1,1);
                glutSolidSphere(0.5, 16, 16);

                glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT,  m_amb2); //putting material onto the 
                glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE,  m_diff2); 
                glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR,  m_spec2); 
                glMaterialf(GL_FRONT_AND_BACK, GL_SHININESS,  shiny2*128);

                //translate and draw right eye
                glPushMatrix();
                    glTranslatef(0.2, 0.15, 0.45);
                    glColor3f(0,0,0);
                    glutSolidSphere(0.1, 10, 10);
                glPopMatrix();

                //translate and draw left eye
                glPushMatrix();
                    glTranslatef(-0.2, 0.15, 0.45);
                    glColor3f(0,0,0);
                    glutSolidSphere(0.1, 10, 10);
                glPopMatrix();

                //translate and draw nose
                glPushMatrix();
                    glTranslatef(0, 0, 0.5);
                    glColor3f(1,0.4,0);
                    glutSolidSphere(0.1, 10, 10);
                glPopMatrix();

            glPopMatrix();//body
        glPopMatrix();//snowman

    glPopMatrix();
}

bool grounded = true;
bool bounced = false;
void ballMotion(int value){

    if(abs(velocity[1]) < 0.5 && position[1] < 1){
        velocity[0] = 0, velocity[2] = 0, velocity[1] = 0;
        launched = false;
        resetBall();
    }
    if (launched == true){
    velocity[0] += acceleration[0]/60;
    velocity[1] += acceleration[1]/60;
    velocity[2] += acceleration[2]/60;
    position[0] += velocity[0]/60;
    position[1] += velocity[1]/60;
    position[2] += velocity[2]/60;

    
        if (position[2] > 5 ){
            velocity[2] = -1*(velocity[2] - 0.5*velocity[2]);
            position[2] = 5.0 + velocity[2]/60;
            printf("out of z pos wall");
        }
        else if (position[2] < -5 ){
            velocity[2] = -1*(velocity[2] - 0.5*velocity[2]);
            position[2] = -5.0 + velocity[2]/60;
            printf("out of z neg wall");
        }
        if (position[0] < -5){
            velocity[0] = -1*(velocity[0] - 0.5*velocity[0]);
            position[0] = -5.0 + velocity[0]/60;
            printf("out of x neg wall");
        }
        else if (position[0] > 5){
            velocity[0] = -1*(velocity[0] - 0.5*velocity[0]);
            position[0] = 5.0 + velocity[0]/60;
            printf("out of x pos wall");
        }
        if (position[1] < 1){
            //printf("%f",position[1]);
            velocity[1] = -1*(velocity[1] - 0.5*velocity[1]);       //lose half magnitude and reverse direction
            position[1] = 1.0 + velocity[1]/60;
            bounced = true;
        }
        //Intersection with inside of basket (scoring)
        if ((position[0] > (basketPos[0] - basketRadius)) && (position[0] < (basketPos[0] + basketRadius))) {
            if ((position[2] > (basketPos[2] - basketRadius)) && (position[2] < (basketPos[2] + basketRadius))) {
                if (position[1] > 1.0f && position[1] < 2.0f && !bounced) {
                    printf("YOU DID IT\n");
                    resetBall();
                    intscorecounter++;
                }
            }
        }
        //Intersection with outside of basket (rim shot)
         if ((position[0] > (basketPos[0] - basketRadius)) && (position[0] < (basketPos[0] + basketRadius))) {
             if ((position[2] > (basketPos[2] - basketRadius)) && (position[2] < (basketPos[2] + basketRadius))) {
                if (position[1] < 1.05f && bounced) {
                    printf("BOUNCED\n");
                     velocity[0] = -1*(velocity[0] - 0.5*velocity[0]);       //lose half magnitude and reverse direction
                     position[0] = position[0] + velocity[0]/60;

                     velocity[2] = -1*(velocity[2] - 0.5*velocity[2]);       //lose half magnitude and reverse direction
                     position[2] = position[2] + velocity[2]/60;
                }
            }
        }

    
    
    }
    glutTimerFunc(17,ballMotion,0);

}

void ballTexture(){
    switch(text){
        case 2:
            glBindTexture(GL_TEXTURE_2D, textures[0]);
        break;

        case 3:
            glBindTexture(GL_TEXTURE_2D, textures[1]);
        break;

        case 4:
            glBindTexture(GL_TEXTURE_2D, textures[2]);
        break;
    }
}

float input1, input2, input3;

void keyboard(unsigned char key, int x, int y)
{

    /* key presses move the cube, if it isn't at the extents (hard-coded here) */
    switch (key)
    {
        case 'q':
        case 27:
            exit (0);
            break;
            
        case 'u':
        case 'U':
            printf("Type the x,y,z values of your look at \n");
            scanf("%f", &input1);
            scanf("%f", &input2);
            scanf("%f", &input3);
            lookat[0] = input1;
            lookat[1] = input2;
            lookat[2] = input2;
            break;
            
        case 'v':
        case 'V':
            printf("Type the x,y,z values of your camera \n");
            scanf("%f", &input1);
            scanf("%f", &input2);
            scanf("%f", &input3);
            eye[0] = input1;
            eye[1] = input2;
            eye[2] = input2;
            break;
        case 'a':
            lookatradius += 0.1;
            break;
            
        case 'A':
            lookatradius -= 0.1;
            break;
            
            
        case 's':
            lookattheta += 0.05;
            break;
            
            
        case 'S':
            lookattheta -= 0.05;
            break;
            
        case 'd':
            lookatphi += 0.05;
            break;
            
        case 'D':
            lookatphi -= 0.05;
            break;
            
        case 'z':
            eyeradius += 0.1;
            break;
            
        case 'Z':
            eyeradius -= 0.1;
            break;
            
            
        case 'x':
            eyetheta += 0.05;
            break;
            
            
        case 'X':
            eyetheta -= 0.05;
            break;
            
        case 'c':
            if(eyephi < 1.5){
                eyephi += 0.05;
            }
            break;
            
        case 'C':
            if(eyephi > -1.5){
                eyephi -= 0.05;
            }           
            break;
        case '1':
            if (textureToggle == true){
                glEnable(GL_TEXTURE_2D);
                // glBindTexture(GL_TEXTURE_2D, textures[0]);

                textureToggle = false;
            } else {
                glDisable(GL_TEXTURE_2D);
                textureToggle = true;
            }
            break;
            
        case '2':
            text = 2;
            // glBindTexture(GL_TEXTURE_2D, textures[0]);
            break;
            
        case '3':
            text = 3;
            // glBindTexture(GL_TEXTURE_2D, textures[1]);

            break;
            
        case '4':
            text = 4;
            // glBindTexture(GL_TEXTURE_2D, textures[2]);

            break;
            
        case 'r':
            case 'R':
            resetBall();
            break;
    

    }
    glutPostRedisplay();
}


void special(int key, int x, int y)
{

    switch(key)
    { case GLUT_KEY_UP:
            eye[1] += 1;
            lookat[1] += 1;
        break;
        case GLUT_KEY_DOWN:
            eye[1] -= 1;
            lookat[1] -= 1;
        break;
        case GLUT_KEY_LEFT:
            eye[0] -= 1;
            lookat[0] -= 1;
        break;
        case GLUT_KEY_RIGHT:
            eye[0] += 1;
            lookat[0] += 1;
        break;
        
    }
    glutPostRedisplay();
}

void init(void)
{   glClearColor(0, 0, 0, 0);
    glColor3f(1,0,0);
    
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glEnable(GL_LIGHT1);
    glLightfv(GL_LIGHT0, GL_AMBIENT, amb0);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, diff0);
    glLightfv(GL_LIGHT0, GL_SPECULAR, spec0);

    glLightfv(GL_LIGHT1, GL_AMBIENT, amb0);
    glLightfv(GL_LIGHT1, GL_DIFFUSE, diff0);
    glLightfv(GL_LIGHT1, GL_SPECULAR, spec0);

    // glColorMaterial(GL_FRONT, GL_AMBIENT);  //changing ambient colour of material -- necessary for wireframe
    // glEnable(GL_COLOR_MATERIAL);

    
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glFrustum(-10,10,-10,10,0,1000);
    gluPerspective(90, 1, 1, 1000);

}




void display(void)
{
    float origin[3] = {0,0,0};
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    updateeyeposition();
    updatelookatposition();
    glLoadIdentity();
    changetostring(intscorecounter);
    glDisable(GL_LIGHTING);
    textprinter(750,780, (char*)counterstring);
    glEnable(GL_LIGHTING);
    gluLookAt(eye[0],eye[1],eye[2], lookat[0],lookat[1],lookat[2], 0, 1, 0);
    glLightfv(GL_LIGHT0, GL_POSITION, light1_pos);
    glLightfv(GL_LIGHT1, GL_POSITION, light2_pos);
    
    // if(textureWall == true){
    //     glEnable(GL_TEXTURE_2D);
    // }
    drawFloor();
    glDisable(GL_TEXTURE_2D);
    drawBasket();
    DrawSnowman(pos, rot);
    if(textureToggle == true){
        glEnable(GL_TEXTURE_2D);
    }
    ballTexture();
    drawBall();
    glutSwapBuffers();
    glutPostRedisplay();
    
}



bool calcIntersection(vec3D r0, vec3D rd) {
    //Max and min of bounding box for ball
    vec3D min, max;
    min.x = position[0] - 0.5f; min.y = position[1] - 0.5f; min.z = position[2] - 0.5f;
    max.x = min.x + 1.0f; max.y = min.y + 1.0f; max.z = min.z + 1.0f;
    
    //Calculate points on the front face of the ball
    point3D p0, p1, p2, p3;
    p0.x = min.x; p0.y = min.y; p0.z = max.z;
    p1.x = max.x; p1.y = min.y; p1.z = max.z;
    p2.x = max.x; p2.y = max.y; p2.z = max.z;
    p3.x = min.x; p3.y = max.y; p3.z = max.z;
    
    //Calculate the equation of the plane intersecting with the face
    float a, b, c, d;
    vec3D t1, t2, norm;
    
    t1 = t1.createVector(p1, p0);
    t2 = t2.createVector(p2, p0);
    
    norm = t1.crossProduct(t2);
    
    norm = norm.normalize();
    
    d = -((norm.x * p0.x) + (norm.y * p0.y) + (norm.z * p0.z));
    a = norm.x; b = norm.y; c = norm.z;
    
    //Test for intersection of the ray and the plane
    float t, dot0, dotD;
    vec3D is;
    
    dot0 = (a * r0.x) + (b * r0.y) + (c * r0.z);
    dotD = (a * rd.x) + (b * rd.y) + (c * r0.z);
    
    if (dot0 == 0) return false;
    
    t = -((dot0 + d) / dotD);
    
    is = r0 + rd.vectorMultiply(t);
    
    if ((is.x > p0.x) && (is.x < p1.x) && (is.y > p0.y) && (is.y < p2.y)) {
        return true;
    } else {
        return false;
    }
    
    
    
}

bool rayCast(float x, float y) {
    GLint viewport[4];          //declaring arrays and variables
    GLdouble modelview[16];
    GLdouble projection[16];
    float winX;
    float winY;
    GLdouble pos1X, pos1Y, pos1Z;
    GLdouble pos2X, pos2Y, pos2Z;
    GLdouble dirX, dirY, dirZ;
    vec3D r0, rd;
    
    glGetIntegerv(GL_VIEWPORT, viewport);
    glGetDoublev(GL_MODELVIEW_MATRIX, modelview);
    
    glGetDoublev(GL_PROJECTION_MATRIX, projection);
    
    //Flip the y coordinate to have the proper opengl screen coords
    winX = x;
    winY = (float)viewport[3] - y;
    
    //Unproject the coordinates from screen to world coordinates on the near clipping plane
    gluUnProject(winX, winY, 0.0, modelview, projection, viewport, &pos1X, &pos1Y, &pos1Z);
    
    //Unproject the coordinates from screen to world coordinates on the far clipping plane
    gluUnProject(winX, winY, 1.0, modelview, projection, viewport, &pos2X, &pos2Y, &pos2Z);
    
    //Calculate a normalized ray between the far and near clipping planes
    dirX = pos2X - pos1X;
    dirY = pos2Y - pos1Y;
    dirZ = pos2Z - pos1Z;
    
    r0.x = pos1X; r0.y = pos1Y; r0.z = pos1Z;
    rd.x = dirX; rd.y = dirY; rd.z = dirZ;
    
    rd = rd.normalize();
    
    if (calcIntersection(r0, rd)) {
        return true;
    } else {
        return false;
    }
}


void mouse(int btn, int state, int x, int y){
    
    if (btn == GLUT_LEFT_BUTTON && launched == false){
        if (state == GLUT_DOWN){
            startingMousepos[0] = x, startingMousepos[1] = y;       //store the starting mouse position
            startTime=(GLfloat)glutGet(GLUT_ELAPSED_TIME);          //store the time when the user first clicks down
        }
        else if(state == GLUT_UP){
            
            finalMousepos[0] = x;
            finalMousepos[1] = y;
            endTime=(GLfloat)glutGet(GLUT_ELAPSED_TIME);          //store the time when the user first clicks down
            
            float timeElapsed = endTime - startTime;
            float dy = -(finalMousepos[1] - startingMousepos[1]);
            float dx = -(finalMousepos[0] - startingMousepos[0]);
            
            averageXVelocity = dx/timeElapsed;
            averageZVelocity = dy/timeElapsed;
            velocity[0] += averageXVelocity*5;
            velocity[1] = 20;
            velocity[2] += averageZVelocity*5;
            
            printf("%f,%f\n", averageXVelocity,averageZVelocity);
            launched = true;
            bounced = false;
        }
    }
    
}
void callbackinit(){
    glutTimerFunc(0, ballMotion, 0);
}
/* main function - program entry point */
int main(int argc, char** argv)
{
    srand(time(NULL));
    
    glutInit(&argc, argv);      //starts up GLUT
    
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    
    
    glutInitWindowSize(800, 800);
    glutInitWindowPosition(100, 100);

    firstwindow = glutCreateWindow("Terrain");  //creates the window
    
    
    glutDisplayFunc(display);   //registers "display" as the display callback function
    glutKeyboardFunc(keyboard);
    glutMouseFunc(mouse);
    glutSpecialFunc(special);
    
    glEnable(GL_DEPTH_TEST);
    //glFrontFace((GL_CCW));
    //glCullFace(GL_FRONT);
    //glEnable(GL_CULL_FACE);
    init();
    initTexture();
    callbackinit();

    glutMainLoop();             //starts the event loop

    return(0);                  //return may not be necessary on all compilers
}