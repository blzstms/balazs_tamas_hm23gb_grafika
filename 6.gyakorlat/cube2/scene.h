#ifndef SCENE_H
#define SCENE_H

#include "camera.h"
#include "texture.h"

#include <obj/model.h>

typedef struct Scene
{
    Model cube;
    Model duck;
    Material material;
    GLuint texture_cube;
    GLuint texture_duck;
    float ambient_light[4];
    float diffuse_light[4];
    float duck_speed;
    float duck_forward;
} Scene;

/**
 * Initialize the scene by loading models.
 */
void init_scene(Scene* scene);

/**
 * Set the lighting of the scene.
 */
void set_lighting(Scene *scene);


void change_light_intensity(float delta);

/**
 * Set the current material.
 */
void set_material(const Material* material);

/**
 * Update the scene.
 */
void update_scene(Scene* scene);

/**
 * Render the scene objects.
 */
void render_scene(const Scene* scene);

/**
 * Draw the origin of the world coordinate system.
 */
void draw_origin();

void increase_light(Scene *scene);

#endif /* SCENE_H */


