#include "missile.h"

#include <obj/load.h>
#include <obj/draw.h>
#include <math.h>
#include <time.h>


void init_missile(Missile *missile){
    load_missile_model(missile);
    missile->speed = 0.0;
    missile->is_moveing = false;
    missile->is_explosion = false;
}

void load_missile_model(Missile *missile){
    load_model(&(missile->missile), "assets/models/missile.obj");
    missile->missile_id = load_texture("assets/textures/missile.jpg");
}

void render_missile(const Missile *missile){
    load_missile(*missile);
}

void load_missile(Missile missile){
    glPushMatrix();
    glTranslated(0,0,0);
    glBindTexture(GL_TEXTURE_2D, missile.missile_id); 
    if (missile.is_moveing)
    {
        glTranslated(0,missile.speed * -1,0);
    }
    draw_model(&(missile.missile));
    glPopMatrix();
}

void update_missile(Missile *missile,double elapsed_time){
    missile->speed += 20 * elapsed_time;
}