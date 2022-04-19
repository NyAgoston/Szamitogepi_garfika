#include "scene.h"

#include <obj/load.h>
#include <obj/draw.h>
#include <math.h>
#include <time.h>

void init_scene(Scene* scene)
{
    load_model(&(scene->cube), "assets/models/cube.obj");
    scene->texture_id = load_texture("assets/textures/cube.png");
    glBindTexture(GL_TEXTURE_2D, scene->texture_id);

    //GROUND
    load_model(&(scene->ground), "assets/models/ground.obj");
    scene->ground_id = load_texture("assets/textures/rails.jpg");
    glBindTexture(GL_TEXTURE_2D, scene->ground_id);

    //PLATFORM
    load_model(&(scene->platform), "assets/models/platform.obj");
    scene->platform_id = load_texture("assets/textures/platform.png");
    glBindTexture(GL_TEXTURE_2D, scene->platform_id);

    //TRAIN
    load_model(&(scene->train), "assets/models/train.obj");
    scene->train_id = load_texture("assets/textures/train.jpg");
    glBindTexture(GL_TEXTURE_2D, scene->train_id);

    //CEILING
    load_model(&(scene->ceiling), "assets/models/ceiling.obj");
    scene->ceiling_id = load_texture("assets/textures/ceiling.png");
    glBindTexture(GL_TEXTURE_2D, scene->ceiling_id);

    //FRONTWALL
    load_model(&(scene->frontwall), "assets/models/frontwall.obj");
    scene->frontwall_id = load_texture("assets/textures/frontwall.png");
    glBindTexture(GL_TEXTURE_2D, scene->frontwall_id);

    //PILLAR
    load_model(&(scene->pillar), "assets/models/pillar.obj");
    scene->pillar_id = load_texture("assets/textures/platform.png");
    glBindTexture(GL_TEXTURE_2D, scene->pillar_id);

    //SIDEWALL
    load_model(&(scene->sidewall), "assets/models/sidewall.obj");
    scene->sidewall_id = load_texture("assets/textures/sidewall.png");
    glBindTexture(GL_TEXTURE_2D, scene->sidewall_id);

    //TUNNEL
    load_model(&(scene->tunnel), "assets/models/tunnel.obj");
    scene->tunnel_id = load_texture("assets/textures/tunnel.png");
    glBindTexture(GL_TEXTURE_2D, scene->tunnel_id);
    

    //TUNNELWALL
    load_model(&(scene->tunnelwall_id), "assets/models/tunnelwall.obj");
    scene->tunnelwall_id = load_texture("assets/textures/tunnelwall.png");
    glBindTexture(GL_TEXTURE_2D, scene->tunnelwall_id);

    

    //SKYBOX
    scene->sky_id = load_texture("assets/textures/egbolt.jpg");
    glBindTexture(GL_TEXTURE_2D, scene->sky_id);

    scene->material.ambient.red = 1.0;
    scene->material.ambient.green = 1.0;
    scene->material.ambient.blue = 1.0;

    scene->material.diffuse.red = 1.0;
    scene->material.diffuse.green = 1.0;
    scene->material.diffuse.blue = 1.0;

    scene->material.specular.red = 1.0;
    scene->material.specular.green = 1.0;
    scene->material.specular.blue = 1.0;

    scene->material.shininess = 1.0;
    scene->angle = 0;
}

void set_lighting()
{
    float ambient_light[] = { 0.0f, 0.0f, 0.0f, 1.0f };
    float diffuse_light[] = { 1.0f, 1.0f, 1.0, 1.0f };
    float specular_light[] = { 0.0f, 0.0f, 0.0f, 1.0f };
    float position[] = { 0.0f, 0.0f, 10.0f, 1.0f };

    glLightfv(GL_LIGHT0, GL_AMBIENT, ambient_light);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, diffuse_light);
    glLightfv(GL_LIGHT0, GL_SPECULAR, specular_light);
    glLightfv(GL_LIGHT0, GL_POSITION, position);
}

void set_material(const Material* material)
{
    float ambient_material_color[] = {
        material->ambient.red,
        material->ambient.green,
        material->ambient.blue
    };

    float diffuse_material_color[] = {
        material->diffuse.red,
        material->diffuse.green,
        material->diffuse.blue
    };

    float specular_material_color[] = {
        material->specular.red,
        material->specular.green,
        material->specular.blue
    };

    glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, ambient_material_color);
    glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, diffuse_material_color);
    glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, specular_material_color);

    glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS, &(material->shininess));
}


void render_scene(const Scene* scene)
{
    set_material(&(scene->material));
    set_lighting();
    draw_origin();
    draw_model(&(scene->cube));
    //TRAIN
    glBindTexture(GL_TEXTURE_2D, scene->train_id);
    load_train(*scene);
    //GROUND
    glBindTexture(GL_TEXTURE_2D, scene->ground_id);
    load_ground(*scene);
    //PLATFORM
    glBindTexture(GL_TEXTURE_2D, scene->platform_id);
    load_platform(*scene);
    //CEILING
    glBindTexture(GL_TEXTURE_2D, scene->ceiling_id);
    load_ceiling(*scene);
    //FRONTWALL
    glBindTexture(GL_TEXTURE_2D, scene->frontwall_id);
    load_frontwall(*scene);
    //PILLAR
    glBindTexture(GL_TEXTURE_2D, scene->pillar_id);
    load_pillar(*scene);
    //SIDEWALL
    glBindTexture(GL_TEXTURE_2D, scene->sidewall_id);
    load_sidewall(*scene);
    //TUNNEL
    glBindTexture(GL_TEXTURE_2D, scene->tunnel_id);
    load_tunnel(*scene);
    //TUNNELWALL
    /*glBindTexture(GL_TEXTURE_2D, scene->tunnelwall_id);
    load_tunnelwall(*scene);*/

    

    //SKYBOX
    glBindTexture(GL_TEXTURE_2D, scene->sky_id);
    load_skybox(*scene);

}

void draw_origin()
{
    glBegin(GL_LINES);

    glColor3f(1, 0, 0);
    glVertex3f(0, 0, 0);
    glVertex3f(1, 0, 0);

    glColor3f(0, 1, 0);
    glVertex3f(0, 0, 0);
    glVertex3f(0, 1, 0);

    glColor3f(0, 0, 1);
    glVertex3f(0, 0, 0);
    glVertex3f(0, 0, 1);

    glEnd();
}

void load_skybox(Scene scene) {

    glBindTexture(GL_TEXTURE_2D, scene.sky_id);

    double theta, phi1, phi2;
    double x1, y1, z1;
    double x2, y2, z2;
    double u, v1, v2;
    int n_slices, n_stacks;
    double radius;
    int i, k;
    n_slices = 15;
    n_stacks = 15;
    radius = 70;

    glPushMatrix();

    glScaled(radius, radius, radius);

    glColor3f(1, 1, 1);

    glBegin(GL_TRIANGLE_STRIP);

    for (i = 0; i < n_stacks; ++i) {
        v1 = (double) i / n_stacks;
        v2 = (double) (i + 1) / n_stacks;
        phi1 = v1 * M_PI / 2.0;
        phi2 = v2 * M_PI / 2.0;
        for (k = 0; k <= n_slices; ++k) {
            u = (double) k / n_slices;
            theta = u * 2.0 * M_PI;
            x1 = cos(theta) * cos(phi1);
            y1 = sin(theta) * cos(phi1);
            z1 = sin(phi1) - 0.25;
            x2 = cos(theta) * cos(phi2);
            y2 = sin(theta) * cos(phi2);
            z2 = sin(phi2) - 0.25;
            glTexCoord2d(u, 1.0 - v1);
            glVertex3d(x1, y1, z1);
            glTexCoord2d(u, 1.0 - v2);
            glVertex3d(x2, y2, z2);
        }
    }

    glEnd();

    glPopMatrix();

}

//GROUND
void load_ground(Scene scene) {

    glPushMatrix();
    //glTranslated(0, 0, 0.0);
    glBindTexture(GL_TEXTURE_2D, scene.ground_id);
    glTranslated(0, 0, 0.0);
    draw_model(&(scene.ground));
    glPopMatrix();
}
//TRAIN
void load_train(Scene scene) {

    glPushMatrix();
    glTranslated(0, -8, 0.0);
    glBindTexture(GL_TEXTURE_2D, scene.train_id);
    glTranslated(0, -8, 0.0);
    double time_taken;
    clock_t start;
    start = clock();
    time_taken = ((double) (start)) / CLOCKS_PER_SEC;
    //printf("time_taken %lf \n",time_taken);
    //printf("sceneangle %lf\n",scene.angle);
    //printf("speed: %lf",scene.angle - (time_taken - 2)
   
    glTranslated(0,fmod(time_taken * 20, 30.0),0);      
    
    
    draw_model(&(scene.train));
    glPopMatrix();
}
//PLATFORM
void load_platform(Scene scene) {

    glPushMatrix();
    glTranslated(0, 0, 0.0);
    glBindTexture(GL_TEXTURE_2D, scene.platform_id);
    glTranslated(0, 0, 0.0);
    draw_model(&(scene.platform));
    glPopMatrix();
}
//CEILING
void load_ceiling(Scene scene) {

    glPushMatrix();
    glTranslated(0, 0, 0.0);
    glBindTexture(GL_TEXTURE_2D, scene.ceiling_id);
    glTranslated(0, 0, 0.0);
    draw_model(&(scene.ceiling));
    glPopMatrix();
}
//FRONTWALL
void load_frontwall(Scene scene) {

    glPushMatrix();
    glTranslated(0, 0, 0.0);
    glBindTexture(GL_TEXTURE_2D, scene.frontwall_id);
    glTranslated(0, 0, 0.0);
    draw_model(&(scene.frontwall));
    glPopMatrix();
}
//PILLAR
void load_pillar(Scene scene) {

    glPushMatrix();
    glTranslated(0, 0, 0.0);
    glBindTexture(GL_TEXTURE_2D, scene.pillar_id);
    glTranslated(0, 0, 0.0);
    draw_model(&(scene.pillar));
    glPopMatrix();
}
//SIDEWALL
void load_sidewall(Scene scene) {

    glPushMatrix();
    glTranslated(0, 0, 0.0);
    glBindTexture(GL_TEXTURE_2D, scene.sidewall_id);
    glTranslated(0, 0, 0.0);
    draw_model(&(scene.sidewall));
    glPopMatrix();
}
//TUNNEL
void load_tunnel(Scene scene) {

    glPushMatrix();
    glTranslated(0, 0, 0.0);
    glBindTexture(GL_TEXTURE_2D, scene.tunnel_id);
    glTranslated(0, 0, 0.0);
    draw_model(&(scene.tunnel));
    glPopMatrix();
}
//TUNNELWALL
void load_tunnelwall(Scene scene) {

    glPushMatrix();
    glTranslated(0, 0, 0.0);
    glBindTexture(GL_TEXTURE_2D, scene.tunnelwall_id);
    glTranslated(0, 0, 0.0);
    draw_model(&(scene.tunnelwall));
    glPopMatrix();
}



void update_scene(Scene* scene, double time)
{
    scene->angle += 50 * time;
}

