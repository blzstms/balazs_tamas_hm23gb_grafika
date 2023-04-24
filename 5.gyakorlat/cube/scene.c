#include "scene.h"


#include <obj/load.h>
#include <obj/draw.h>

#define MOVE_SPEED 0.1f


void init_scene(Scene* scene)
{
    load_model(&(scene->house), "assets/models/house.obj");
    scene->texture_id1 = load_texture("assets/textures/house.png");

    load_model(&(scene->dog), "assets/models/dog.obj");
    scene->texture_id2 = load_texture("assets/textures/dog.jpg");



    scene->material.ambient.red = 1.0;
    scene->material.ambient.green = 1.0;
    scene->material.ambient.blue = 1.0;

    scene->material.diffuse.red = 1.0;
    scene->material.diffuse.green = 1.0;
    scene->material.diffuse.blue = 1.0;

    scene->material.specular.red = 1.0;
    scene->material.specular.green = 1.0;
    scene->material.specular.blue = 1.0;

    scene->material.shininess = 0.0;

    float dog_position_x = 0.0;
    float dog_position_y = 0.0;
    float dog_position_z = 0.0;


}

void set_lighting()
{
    float ambient_light[] = { 10.0f, 10.0f, 10.0f, 10.0f };
    float diffuse_light[] = { 10.0f, 10.0f, 10.0, 10.0f };
    float specular_light[] = { 10.0f, 10.0f, 10.0f, 10.0f };
    float position[] = { 10.0f, 10.0f, 20.0f, 10.0f };

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

void update_scene(Scene* scene)
{

}

void render_scene(const Scene* scene)
{
    set_material(&(scene->material));
    set_lighting();
    draw_origin();
    glScalef(0.6,0.6,0.6);
    draw_model(&(scene->house));
    glBindTexture(GL_TEXTURE_2D, scene->texture_id2);
    draw_model(&(scene->dog));
    glBindTexture(GL_TEXTURE_2D, scene->texture_id1);

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

