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

            // else {
            //     glTranslatef(1,0,0);
            //     counter++;
            // }

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
            // else {
            //     glTranslatef(-1,0,0);
            //     counter++;
        // }

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

//keyboard function
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

//display function
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

