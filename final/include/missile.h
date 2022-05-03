#ifndef MISSILE_H
#define MISSILE_H

#include "camera.h"
#include "texture.h"

#include <obj/model.h>
typedef struct Missile{

    Model missile;
    GLuint missile_id;

    double speed;

    bool is_moveing;
    bool is_explosion;

}Missile;

void init_missile(Missile *missile);

void update_missile(Missile *missile,double time);

void render_missile(const Missile *missile);

void load_missile_model(Missile *missile);

void load_missile(Missile missile);


#endif