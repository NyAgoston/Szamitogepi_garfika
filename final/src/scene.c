#include "scene.h"

#include <obj/load.h>
#include <obj/draw.h>
#include <math.h>
#include <time.h>

void init_scene(Scene* scene)
{

    load_models(scene);
    load_textures(scene);
    
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
    
    scene->help_visibility = false;
    scene->map_visibility = false;
    scene->welcome_visibility = true;
}

void load_models(Scene *scene){
    load_model(&(scene->ground), "assets/models/ground.obj");
    load_model(&(scene->platform), "assets/models/platform.obj");
    //load_model(&(scene->train), "assets/models/train.obj");
    load_model(&(scene->ceiling), "assets/models/ceiling.obj");
    load_model(&(scene->frontwall), "assets/models/frontwall.obj");
    load_model(&(scene->pillar), "assets/models/pillar.obj");
    load_model(&(scene->sidewall), "assets/models/sidewall.obj");
    load_model(&(scene->tunnel), "assets/models/tunnel.obj");
    load_model(&(scene->tunnelwall), "assets/models/tunnelwall.obj");
    load_model(&(scene->piggy), "assets/models/piggy.obj");
    load_model(&(scene->ladder), "assets/models/ladder.obj");
    load_model(&(scene->ufo), "assets/models/ufo.obj");
    load_model(&(scene->trapdoor), "assets/models/trapdoor.obj");

}
void load_textures(Scene *scene){
    scene->ground_id = load_texture("assets/textures/ground.jpg");
    scene->platform_id = load_texture("assets/textures/platform.jpg");
    //scene->train_id = load_texture("assets/textures/train.jpg");
    scene->ceiling_id = load_texture("assets/textures/ceiling.jpg");
    scene->frontwall_id = load_texture("assets/textures/frontwall.jpg");
    scene->pillar_id = load_texture("assets/textures/pillar.jpg");
    scene->sidewall_id = load_texture("assets/textures/sidewall.jpg");
    scene->tunnel_id = load_texture("assets/textures/tunnel.jpg");
    scene->tunnelwall_id = load_texture("assets/textures/tunnelwall.jpg");
    scene->piggy_id = load_texture("assets/textures/piggy.jpg");
    scene->ladder_id = load_texture("assets/textures/ladder.jpg");
    scene->ufo_id = load_texture("assets/textures/ufo.jpg");
    scene->trapdoor_id = load_texture("assets/textures/trapdoor.jpg");
    scene->sky_id = load_texture("assets/textures/space.jpg");

    scene->help_id = load_texture("assets/textures/help.jpg");
    scene->map_id = load_texture("assets/textures/map.jpg");
    scene->welcome_id = load_texture("assets/textures/welcome.jpg");


}
void load_space(Scene scene){
    //GROUND
    glPushMatrix();
    glTranslated(0, 0, 0.0);
    glBindTexture(GL_TEXTURE_2D, scene.ground_id);
    glTranslated(0, 0, 0.0);
    draw_model(&(scene.ground));
    glPopMatrix();

    //CEILING
    glPushMatrix();
    glTranslated(0, 0, 0.0);
    glBindTexture(GL_TEXTURE_2D, scene.ceiling_id);
    glTranslated(0, 0, 0.0);
    draw_model(&(scene.ceiling));
    glPopMatrix();

    /*TRAIN
    glPushMatrix();
    glTranslated(0, -8, 0.0);
    glBindTexture(GL_TEXTURE_2D, scene.train_id);
    glTranslated(0, -8, 0.0);
    double time_taken;
    clock_t start;
    start = clock();
    time_taken = ((double) (start)) / CLOCKS_PER_SEC;
    glTranslated(0,fmod(time_taken * 20, 30.0),0);      
    draw_model(&(scene.train));
    glPopMatrix();*/

    //PLATFORM
    glPushMatrix();
    glTranslated(0, 0, 0.0);
    glBindTexture(GL_TEXTURE_2D, scene.platform_id);
    glTranslated(0, 0, 0.0);
    draw_model(&(scene.platform));
    glPopMatrix();

    //FRONTWALL
    glPushMatrix();
    glTranslated(0, 0, 0.0);
    glBindTexture(GL_TEXTURE_2D, scene.frontwall_id);
    glTranslated(0, 0, 0.0);
    draw_model(&(scene.frontwall));
    glPopMatrix();

    //PILLAR
    glPushMatrix();
    glTranslated(0, 0, 0.0);
    glBindTexture(GL_TEXTURE_2D, scene.pillar_id);
    glTranslated(0, 0, 0.0);
    draw_model(&(scene.pillar));
    glPopMatrix();

    //SIDEWALL
    glPushMatrix();
    glTranslated(0, 0, 0.0);
    glBindTexture(GL_TEXTURE_2D, scene.sidewall_id);
    glTranslated(0, 0, 0.0);
    draw_model(&(scene.sidewall));
    glPopMatrix();

    //TUNNEL
    glPushMatrix();
    glTranslated(0, 0, 0.0);
    glBindTexture(GL_TEXTURE_2D, scene.tunnel_id);
    glTranslated(0, 0, 0.0);
    draw_model(&(scene.tunnel));
    glPopMatrix();

    //TUNNELWALL
    glPushMatrix();
    glTranslated(0, 0, 0.0);
    glBindTexture(GL_TEXTURE_2D, scene.tunnelwall_id);
    glTranslated(0, 0, 0.0);
    draw_model(&(scene.tunnelwall));
    glPopMatrix();

    //PIGGY
    glPushMatrix();
    glTranslated(0, 0, 0.0);
    glBindTexture(GL_TEXTURE_2D, scene.piggy_id);
    glTranslated(0, -30, 3.0);
    glScaled(1,1,1);
    draw_model(&(scene.piggy));
    glPopMatrix();

    //LADDER
    glPushMatrix();
    glTranslated(0, 0, 0.0);
    glBindTexture(GL_TEXTURE_2D, scene.ladder_id);
    glTranslated(0, 0, 0.0);
    draw_model(&(scene.ladder));
    glPopMatrix();

    //UFO
    glPushMatrix();
    glTranslated(0, 0, 0.0);
    glBindTexture(GL_TEXTURE_2D, scene.ufo_id);
    glTranslated(0, 0, 0.0);
    draw_model(&(scene.ufo));
    glPopMatrix();

    //TRAPDOOR
    glPushMatrix();
    glTranslated(0, 0, 0.0);
    glBindTexture(GL_TEXTURE_2D, scene.trapdoor_id);
    glTranslated(0, 0, 0.0);
    draw_model(&(scene.trapdoor));
    glPopMatrix();

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
    
    //SKYBOX
    glBindTexture(GL_TEXTURE_2D, scene->sky_id);
    load_skybox(*scene);
    load_space(*scene);

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

void update_scene(Scene* scene, double time)
{
    scene->angle += 50 * time;
    //printf("%lf \n",scene->angle);
    
}
//HELP
void image_function(GLuint image_id) {

    glDisable(GL_LIGHTING);
    glDisable(GL_DEPTH_TEST);
    glEnable(GL_COLOR_MATERIAL);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    glColor3f(1, 1, 1);
    glBindTexture(GL_TEXTURE_2D, image_id);

    glBegin(GL_QUADS);
    glTexCoord2f(0, 0);
    glVertex3d(-2, 1.5, -3);
    glTexCoord2f(1, 0);
    glVertex3d(2, 1.5, -3);
    glTexCoord2f(1, 1);
    glVertex3d(2, -1.5, -3);
    glTexCoord2f(0, 1);
    glVertex3d(-2, -1.5, -3);
    glEnd();


    glDisable(GL_COLOR_MATERIAL);
    glEnable(GL_LIGHTING);
    glEnable(GL_DEPTH_TEST);

}

