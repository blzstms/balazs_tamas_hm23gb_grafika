#ifndef SCENE_H
#define SCENE_H

#include "camera.h"
#include "texture.h"
#include "dogmove.h"

#include <obj/model.h>



typedef struct Dogmodel
{
    int n_vertices;
    int n_texture_vertices;
    int n_normals;
    int n_triangles;
    Vertex* vertices;
    TextureVertex* texture_vertices;
    Vertex* normals;
    Triangle* triangles;
    vec3 position;
} Dogmodel;


typedef struct Scene
{
    Model wall1;
    Model wall2;
    Model wall3;
    Model wall4;
    Model ceiling;
    Model floor;
    Model window_frame;
    Model window;
    Dogmodel doghouse;
    Dogmodel dog;
    Dogmodel tail;
    Material material;
    GLuint texture_wall;
    GLuint texture_floor;
    GLuint texture_darkwall;
    GLuint texture_window_frame;
    GLuint texture_window;
    GLuint texture_dog;
    GLuint texture_house;
    float ambient_light[4];
    float diffuse_light[4];
    float specular_light[4];
    float position[4];
} Scene;


/**
 * Initialize the scene by loading models.
 */
void init_scene(Scene* scene);

/**
 * Set the lighting of the scene.
 */
void set_lighting(Scene *scene);


/**
 * Set the current material.
 */
void set_material(const Material* material);

/**
 * Update the scene.
 */
 void update_scene(Scene* scene, Dogmove* dogmove);

/**
 * Render the scene objects.
 */
void render_scene(const Scene* scene, Dogmove* dogmove);

/**
* Incrase the light.
*/
void increase_light(Scene* scene);

/**
* Decrase the light.
*/
void decrease_light(Scene* scene);



#endif /* SCENE_H */


