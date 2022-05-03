#ifndef SCENE_H
#define SCENE_H

#include "camera.h"
#include "texture.h"

#include <obj/model.h>

typedef struct Scene
{
    Material material;
    
    Model ufo;
    Model platform;
    Model ladder;
    Model sidewall;
    Model piggy;

    GLuint ufo_id;
    GLuint platform_id;
    GLuint ladder_id;
    GLuint sidewall_id;
    GLuint piggy_id;
    
    GLuint sky_id;

    double angle;
    double pig_speed;

    bool ufo_spin;
    bool pig_spin;

    bool easter_egg_P;
    bool easter_egg_I;
    bool easter_egg_G;
    
    
    //HELP
    GLuint help_id;
    bool help_visibility;
    //MAP
    GLuint map_id;
    bool map_visibility;
    //WELCOME
    GLuint welcome_id;
    bool welcome_visibility;
    //BOOM
    GLuint boom_id;
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

/**
 * Loads the skybox in.
 */
void load_skybox(Scene scene);

/*
 * Loads the models in.
 */
void load_models(Scene *scene);
/**
 * Loads the textures in.
 */
void load_textures(Scene *scene);
/**
 * Fill the space with the models.
 */
void load_space(Scene scene);
/**
 * Loads the map/help/wlcome images in.
 */
void image_function(GLuint image_id);

void update_pig_spin(Scene* scene,double speed,double time);

void set_pig_spawn(Scene scene);

#endif /* SCENE_H */
