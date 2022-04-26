#ifndef SCENE_H
#define SCENE_H

#include "camera.h"
#include "texture.h"

#include <obj/model.h>

typedef struct Scene
{
    Material material;
    //GROUND
    Model ground; 
    GLuint ground_id;  
    //PLATFORMS
    Model platform;
    GLuint platform_id;
    //CEILING
    Model ceiling;
    GLuint ceiling_id;
    //FRONTWALL
    Model frontwall;
    GLuint frontwall_id;
    //PILLAR
    Model pillar;
    GLuint pillar_id;
    //SIDEWALL
    Model sidewall;
    GLuint sidewall_id;
    //TUNNEL
    Model tunnel;
    GLuint tunnel_id;

    //TRAIN
    Model train;
    GLuint train_id;
    
    //TUNELWALL
    Model tunnelwall;
    GLuint tunnelwall_id;

    //PIGGY
    Model piggy;
    GLuint piggy_id;

    //LADDER
    Model ladder;
    GLuint ladder_id;

    //UFO
    Model ufo;
    GLuint ufo_id;

    //TRAPDOOR
    Model trapdoor;
    GLuint trapdoor_id;

    //HELP
    GLuint help_id;
    bool help_visibility;

    //MAP
    GLuint map_id;
    bool map_visibility;
   
    GLuint sky_id;
    double angle;
} Scene;

/**
 * Initialize the scene by loading models.
 */
void init_scene(Scene* scene);

/**
 * Set the lighting of the scene.
 */
void set_lighting();

/**
 * Set the current material.
 */
void set_material(const Material* material);

/**
 * Update the scene.
 */
void update_scene(Scene* scene,double time);

/**
 * Render the scene objects.
 */
void render_scene(const Scene* scene);

/**
 * Draw the origin of the world coordinate system.
 */
void draw_origin();


//MODELS
void load_ground(Scene scene);
void load_platform(Scene scene);
void load_ceiling(Scene scene);
void load_frontwall(Scene scene);
void load_pillar(Scene scene);
void load_sidewall(Scene scene);
void load_tunnel(Scene scene);
void load_tunnelwall(Scene scene);
void load_train(Scene scene);
void load_piggy(Scene scene);
void load_ladder(Scene scene);
void load_ufo(Scene scene);
void load_trapdoor(Scene scene);
//SKYBOX
void load_skybox(Scene scene);

void help_function(GLuint help_id);
void map_function(GLuint map_id);



#endif /* SCENE_H */
