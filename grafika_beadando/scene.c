#include "scene.h"
#include "app.h"
#include "dogmove.h"

#include <obj/load.h>
#include <obj/draw.h>


void init_scene(Scene* scene)
{
    load_model(&(scene->wall1), "assets/models/wall1.obj");
    load_model(&(scene->wall2), "assets/models/wall2.obj");
    load_model(&(scene->wall3), "assets/models/wall3.obj");
    load_model(&(scene->wall4), "assets/models/wall4.obj");
    load_model(&(scene->ceiling), "assets/models/ceiling.obj");
    load_model(&(scene->floor), "assets/models/floor.obj");
    load_model(&(scene->window_frame), "assets/models/window_frame.obj");
    load_model(&(scene->window), "assets/models/window.obj");
    load_model(&(scene->dog), "assets/models/dog.obj");
    load_model(&(scene->tail), "assets/models/tail.obj");
    load_model(&(scene->doghouse), "assets/models/doghouse.obj");


    scene->texture_wall = load_texture("assets/textures/wall.jpg");
    scene->texture_floor = load_texture("assets/textures/floor.jpg");
    scene->texture_darkwall = load_texture("assets/textures/wall_dark.jpg");
    scene->texture_window_frame = load_texture("assets/textures/window_frame.jpg");
    scene->texture_window = load_texture("assets/textures/window.jpg");
    scene->texture_dog = load_texture("assets/textures/dog.jpg");
    scene->texture_house = load_texture("assets/textures/house.jpg");



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

    scene->diffuse_light[0] = 0.5f;
    scene->diffuse_light[1] = 0.5f;
    scene->diffuse_light[2] = 0.5f;
    scene->diffuse_light[3] = 0.5f;

    scene->ambient_light[0] = 0.5f;
    scene->ambient_light[1] = 0.5f;
    scene->ambient_light[2] = 0.5f;
    scene->ambient_light[3] = 0.0f;

    scene->specular_light[0] = 0.5f;
    scene->specular_light[1] = 0.5f;
    scene->specular_light[2] = 0.5f;
    scene->specular_light[3] = 0.5f;

    scene->position[0] = 1.0f;
    scene->position[1] = 1.0f;
    scene->position[2] = 1.0f;
    scene->position[3] = 1.0f;


}

void set_lighting(Scene* scene)
{

    glLightfv(GL_LIGHT0, GL_AMBIENT, scene->ambient_light);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, scene->diffuse_light);
    glLightfv(GL_LIGHT0, GL_SPECULAR, scene->specular_light);
    glLightfv(GL_LIGHT0, GL_POSITION, scene->position);
}

void increase_light(Scene *scene)
{

    if (scene->ambient_light[0] < 1.0f)
    {
        scene->ambient_light[0] = scene->ambient_light[1] = scene->ambient_light[2] += 0.1f;
    }

}


void decrease_light(Scene *scene)
{

    if (scene->ambient_light[0] > -0.5f)
    {
        scene->ambient_light[0] = scene->ambient_light[1] = scene->ambient_light[2] -= 0.1f;
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

void set_dog_position(Scene* scene, float x,float y)
{
    scene->dog.position.x = x;
    scene->dog.position.y = y;

}




void update_scene(Scene* scene, Dogmove* dogmove)
{

    float rotationAngle = sin(SDL_GetTicks() / 100.0f) * 0.5f;//sebesség és tartomány

    scene->tail.position.z = rotationAngle;

    if (dogmove->isDogInHouse) {
        scene->dog.position.x = scene->doghouse.position.x;
        scene->dog.position.y = scene->doghouse.position.y;
        scene->dog.position.z = scene->doghouse.position.z;

        scene->tail.position.x = scene->doghouse.position.x;
        scene->tail.position.y = scene->doghouse.position.y;
        scene->tail.position.z = scene->doghouse.position.z + rotationAngle;
    }

}

void render_scene(const Scene* scene, Dogmove* dogmove)
{

    set_material(&(scene->material));
    set_lighting(scene);

    glTranslatef(0.0f,0.0f,1.0f);

    glBindTexture(GL_TEXTURE_2D, scene->texture_wall);
    draw_model(&(scene->wall2));
    draw_model(&(scene->wall4));
    draw_model(&(scene->ceiling));

    glBindTexture(GL_TEXTURE_2D, scene->texture_darkwall);
    draw_model(&(scene->wall1));
    draw_model(&(scene->wall3));

    glBindTexture(GL_TEXTURE_2D, scene->texture_floor);
    draw_model(&(scene->floor));

    glBindTexture(GL_TEXTURE_2D, scene->texture_window_frame);
    draw_model(&(scene->window_frame));


    glBindTexture(GL_TEXTURE_2D, scene->texture_window);
    draw_model(&(scene->window));

    glBindTexture(GL_TEXTURE_2D, scene->texture_house);
    draw_model(&(scene->doghouse));

    glBindTexture(GL_TEXTURE_2D, scene->texture_dog);
    draw_model(&(scene->dog));


    glPushMatrix();
    glRotatef(scene->tail.position.x, 0.5f, 0.0f, 0.0f);
    glRotatef(scene->tail.position.y, 0.0f, 0.5f, 0.0f);
    glRotatef(scene->tail.position.z, 0.0f, 0.0f, 0.5f);
    draw_model(&(scene->tail));
    glPopMatrix();




    glPushMatrix();
    glTranslatef(-1.0f,0.0f,0.0f);
    glRotatef(scene->tail.position.x, 0.5f, 0.0f, 0.0f);
    glRotatef(scene->tail.position.y, 0.0f, 0.5f, 0.0f);
    glRotatef(scene->tail.position.z, 0.0f, 0.0f, 0.5f);
    draw_model(&(scene->tail));
    glPopMatrix();

    glTranslatef(-1.0f,0.0f,0.0f);
    draw_model(&(scene->dog));

}

