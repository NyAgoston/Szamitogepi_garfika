#ifndef TRAIN_H
#define TRAIN_H

#include "camera.h"
#include "texture.h"

#include <obj/model.h>
typedef struct Train{

    Model train;
    GLuint train_id;


    double speed;

    bool is_moveing;

}Train;

void init_train(Train *train);

void update_train(Train *train,double time);

void render_train(const Train *train);

void load_train_model(Train *train);

void load_train(Train train);


#endif