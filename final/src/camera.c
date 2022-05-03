#include "camera.h"

#include <GL/gl.h>

#include <math.h>

#define CAMERA_SPEED 5.0

int sprint = 2;

void init_camera(Camera* camera)
{
    camera->position.x = 2.0;
    camera->position.y = 2.0;
    camera->position.z = 1.0;
    camera->rotation.x = 0.0;
    camera->rotation.y = 0.0;
    camera->rotation.z = 0.0;
    camera->speed.x = 0.0;
    camera->speed.y = 0.0;
    camera->speed.z = 0.0;

    camera->is_preview_visible = false;
}

int Collided(float x, float y,float z)
{
    //külső falak
    if(z == 1.0){
        if(x>3.90 || y>5.90 || x<-3.90 || y<-5.90 ){
            return 1;
        }else if(x<1.0 && x > -1.0){
            return 1;
        }   
    }else if(z == 3.4){
        if(x>3.90 || y>11.0 || x<-3.90 || y<-11.0 ){
            return 1;
        }
    }else{
        if(x>4.0 || y>5.0 || x<-4.0 || y<-5.0){
            return 1;
        }  
    }   
    
    return 0;
}

void update_camera(Camera* camera, double time)
{
    double angle;
    double side_angle;
    double distance;
    distance = time * CAMERA_SPEED*sprint;

    angle = degree_to_radian(camera->rotation.z);
    side_angle = degree_to_radian(camera->rotation.z + 90.0);
    if(camera->position.x += cos(angle) * camera->speed.y * time){
        angle = degree_to_radian(camera->rotation.z);
    if(!Collided(camera->position.x,camera->position.y + sin(angle)*distance ,camera->position.z)){
    camera->position.y += sin(angle) * distance;
}
    if(!Collided(camera->position.x + cos(angle) * distance ,camera->position.y,camera->position.z)){
    camera->position.x += cos(angle) * distance;
    }
    }
    if(camera->position.y += sin(angle) * camera->speed.y * time){
        angle = degree_to_radian(camera->rotation.z);
    if(!Collided(camera->position.x,camera->position.y - sin(angle)*distance ,camera->position.z)){
    camera->position.y -= sin(angle) * distance;
}
    if(!Collided(camera->position.x - cos(angle) * distance ,camera->position.y,camera->position.z)){
    camera->position.x -= cos(angle) * distance;
    }
    }
    if(camera->position.x += cos(side_angle) * camera->speed.x * time){
        angle = degree_to_radian(camera->rotation.z + 90.0);
    if(!Collided(camera->position.x,camera->position.y + sin(angle)*distance ,camera->position.z)){
        camera->position.y += sin(angle) * distance;
}
    if(!Collided(camera->position.x + cos(angle) * distance ,camera->position.y,camera->position.z)){
    camera->position.x += cos(angle) * distance;
    }
    }
    if(camera->position.y += sin(side_angle) * camera->speed.x * time){
        angle = degree_to_radian(camera->rotation.z - 90.0);
    if(!Collided(camera->position.x,camera->position.y + sin(angle)*distance ,camera->position.z)){
    camera->position.y += sin(angle) * distance;
}
    if(!Collided(camera->position.x + cos(angle) * distance ,camera->position.y,camera->position.z)){
    camera->position.x += cos(angle) * distance;
    }
    }
    if(camera->position.z == 1){
        if(camera->position.x < 2.6 && camera->position.x > 1.8 && camera->position.y < -5.5 && camera->position.y > -5.8){
            camera->position.x = 0;
            camera->position.y = 0;
            camera->position.z = 4.6;
        }
        if(camera->position.x > -2.6 && camera->position.x < -1.8 && camera->position.y > 5.5 && camera->position.y < 5.8){
            camera->position.x = 0;
            camera->position.y = 0;
            camera->position.z = 4.6;
        }
    }else
    {
        if(camera->position.x > 2.1 && camera->position.x < 3.6 && camera->position.y > 0.2 && camera->position.y < 2){
            camera->position.x = 2.5;
            camera->position.y = 5.6;
            camera->position.z = 1;
        }
        if(camera->position.x < -2.1 && camera->position.x > -3.6 && camera->position.y > 0.2 && camera->position.y < 2){
            camera->position.x = -2.5;
            camera->position.y = -5.6;
            camera->position.z = 1;
        }
        
    }
    
    

}


void set_view(const Camera* camera)
{
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    glRotatef(-(camera->rotation.x + 90), 1.0, 0, 0);
    glRotatef(-(camera->rotation.z - 90), 0, 0, 1.0);
    glTranslatef(-camera->position.x, -camera->position.y, -camera->position.z);
}

void rotate_camera(Camera* camera, double horizontal, double vertical)
{
    camera->rotation.z += horizontal;
    camera->rotation.x += vertical;

    if (camera->rotation.z < 0) {
        camera->rotation.z += 360.0;
    }

    if (camera->rotation.z > 360.0) {
        camera->rotation.z -= 360.0;
    }

    if (camera->rotation.x < 0) {
        camera->rotation.x += 360.0;
    }

    if (camera->rotation.x > 360.0) {
        camera->rotation.x -= 360.0;
    }
}

void set_camera_speed(Camera* camera, double speed)
{
    camera->speed.y = speed;
}

void set_camera_side_speed(Camera* camera, double speed)
{
    camera->speed.x = speed;
}
//FLY
void set_camera_vertical_speed(Camera* camera, double speed){
    camera->position.z += speed;
}

//SPAWN
void set_spawn_point(Camera* camera){
    camera->position.x = 2;
    camera->position.y = 2;
    camera->position.z = 1;
}
//SPACEWALK
void space_walk(Camera* camera){    
    camera->position.x = 0;
    camera->position.y = -10;
    camera->position.z = 4.6; 
    
}
//TELPORTBACK
void teleport_back(Camera* camera){
    camera->position.x = 0;
    camera->position.y = 0;
    camera->position.z = 4.6; 
}

void show_texture_preview()
{
    glDisable(GL_LIGHTING);
    glDisable(GL_DEPTH_TEST);
    glEnable(GL_COLOR_MATERIAL);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    glColor3f(1, 1, 1);

    glBegin(GL_QUADS);
    glTexCoord2f(0, 0);
    glVertex3f(-1, 1, -3);
    glTexCoord2f(1, 0);
    glVertex3f(1, 1, -3);
    glTexCoord2f(1, 1);
    glVertex3f(1, -1, -3);
    glTexCoord2f(0, 1);
    glVertex3f(-1, -1, -3);
    glEnd();

    glDisable(GL_COLOR_MATERIAL);
    glEnable(GL_LIGHTING);
    glEnable(GL_DEPTH_TEST);
}
