#include "train.h"

#include <obj/load.h>
#include <obj/draw.h>
#include <math.h>
#include <time.h>

void init_train(Train *train){
    load_train_model(train);

    train->speed = 0.0;

    train->is_moveing = true;

}

void load_train_model(Train *train){
    load_model(&(train->train), "assets/models/train.obj");
    train->train_id = load_texture("assets/textures/train.jpg");
}

void render_train(const Train *train){
    load_train(*train);
}

void load_train(Train train){
    
    glPushMatrix();
    glTranslated(0,-14,0);
    glBindTexture(GL_TEXTURE_2D, train.train_id);  
    glTranslated(0,fmod(train.speed * 10, 30.0),0);
    draw_model(&(train.train));
    glPopMatrix();
}


void update_train(Train *train,double elapsed_time){
    train->speed += 0.8 * elapsed_time;
    //printf("%lf \n",train->speed);
}