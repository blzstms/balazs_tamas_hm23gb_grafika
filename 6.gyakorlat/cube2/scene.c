#include "scene.h"

#include <obj/load.h>
#include <obj/draw.h>



void init_scene(Scene* scene)
{
    load_model(&(scene->cube), "assets/models/cube.obj");
    scene->texture_cube = load_texture("assets/textures/cube.png");

    load_model(&(scene->duck), "assets/models/duck.obj");
    scene->texture_duck = load_texture("assets/textures/duck.jpg");


    scene->duck_speed = 0.0f;
    scene->duck_forward = 0.0f;

    scene->material.ambient.red = 1.0;
    scene->material.ambient.green = 1.0;
    scene->material.ambient.blue = 1.0;

    scene->material.diffuse.red = 1.0;
    scene->material.diffuse.green = 1.0;
    scene->material.diffuse.blue = 1.0;

    scene->material.specular.red = 1.0;
    scene->material.specular.green = 1.0;
    scene->material.specular.blue = 1.0;

    scene->material.shininess = 20.0;

    scene->diffuse_light[0] = 0.5f;
    scene->diffuse_light[1] = 0.5f;
    scene->diffuse_light[2] = 0.5f;
    scene->diffuse_light[3] = 0.5f;

    scene->ambient_light[0] = 0.0f;
    scene->ambient_light[1] = 0.0f;
    scene->ambient_light[2] = 0.0f;
    scene->ambient_light[3] = 1.0f;
}

void set_lighting(Scene *scene)
{
    //float ambient_light[] = { 1.0f, 1.0f, 1.0f, 1.0f };
    //float diffuse_light[] = { 1.0f, 1.0f, 1.0f, 1.0f };
    float specular_light[] = { 1.0f, 1.0f, 1.0f, 1.0f };
    float position[] = { 0.5f, 0.5f, 0.5f, 0.5f };

    glLightfv(GL_LIGHT0, GL_AMBIENT, scene->ambient_light);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, scene->diffuse_light);
    glLightfv(GL_LIGHT0, GL_SPECULAR, specular_light);
    glLightfv(GL_LIGHT0, GL_POSITION, position);
}

void increase_light(Scene *scene)
{
    if (scene->diffuse_light[0] < 1)
    {
        scene->diffuse_light[0] += 0.2f;
    }
    else
    {
        scene->diffuse_light[0] = 0.0f;
    }
    if (scene->diffuse_light[1] < 1)
    {
        scene->diffuse_light[1] += 0.2f;
    }
    else
    {
        scene->diffuse_light[1] = 0.0f;
    }
    if (scene->diffuse_light[2] < 1)
    {
        scene->diffuse_light[2] += 0.2f;
    }
    else
    {
        scene->diffuse_light[2] = 0.0f;
    }
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
     scene->duck_forward += scene->duck_speed / 10;
}

void render_scene(const Scene* scene)
{
    static float rotation = 1;
    set_material(&(scene->material));
    set_lighting(scene);
    draw_origin();
    glBindTexture(GL_TEXTURE_2D, scene->texture_cube);
    glTranslatef(0.0f,0.0f,1.0f);
    draw_model(&(scene->cube));


    glBindTexture(GL_TEXTURE_2D, scene->texture_duck);
    glTranslatef(1.0f,1.0f,-0.5f);
    glScalef(0.2f,0.2f,0.2f);
    glRotatef(rotation,0.0f,0.0f,1.0f);
    glTranslatef(-scene->duck_forward, 0.0, 0.0);
    draw_model(&(scene->duck));
    glTranslatef(+scene->duck_forward, 0.0, 0.0);
    rotation +=1;




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
