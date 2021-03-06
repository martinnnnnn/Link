#pragma once

#include <glm/glm.hpp>

#include "link/types.hpp"

namespace link
{
    enum class LightSourceType : i32
    {
        NONE = -1,
        Directional = 0,
        Point = 1,
        Spot = 2,
        //PBR_Directional = 3,
        //PBR_Point = 4,
        //PBR_Spot = 5,
    };

    //enum class LightSourceType_PBR : i32
    //{
    //    NONE = -1,
    //    Directional = 0,
    //    Point = 1,
    //    Spot = 2,
    //    PBR_Directional = 3,
    //    PBR_Point = 4,
    //    PBR_Spot = 5,
    //};


    //struct LightSource_Directional
    //{
    //    glm::vec3 direction;
    //    glm::vec3 ambient;
    //    glm::vec3 diffuse;
    //    glm::vec3 specular;
    //};

    //struct LightSource_Point
    //{
    //    glm::vec3 position;
    //    f32 constant;
    //    glm::vec3 ambient;
    //    f32 linear;
    //    glm::vec3 diffuse;
    //    f32 quadratic;
    //    glm::vec3 specular;
    //    bool is_on;
    //};

    //struct LightSource_Spot
    //{
    //    glm::vec3 position;
    //    glm::vec3 direction;
    //    glm::vec3 ambient;
    //    glm::vec3 diffuse;
    //    glm::vec3 specular;
    //    f32 constant;
    //    f32 linear;
    //    f32 quadratic;
    //    f32 cutoff;
    //    f32 outer_cutoff;
    //};

    struct LightSource
    {
        glm::vec3       position;
        LightSourceType type;
        glm::vec3       direction;
        f32             constant;
        glm::vec3       color;
        f32             linear;
        f32             quadratic;
        f32             cutoff;
        f32             outer_cutoff;
    };

    //struct LightSource_PBR
    //{
    //    glm::vec3       position;
    //    LightSourceType type;
    //    glm::vec3       direction;
    //    f32             constant;
    //    glm::vec3       color;
    //    f32             linear;
    //    f32             quadratic;
    //    f32             cutoff;
    //    f32             outer_cutoff;
    //};

    struct LightAttenuation
    {
        f32 range;
        f32 constant;
        f32 linear;
        f32 quadratic;
    };


    constexpr LightAttenuation LightAttenuations[] =
    {
        { 7,	1.0,	0.7,	1.8 },
        { 13, 	1.0, 	0.35, 	0.44},
        { 20, 	1.0, 	0.22, 	0.20},
        { 32, 	1.0, 	0.14, 	0.07},
        { 50, 	1.0, 	0.09, 	0.032},
        { 65, 	1.0, 	0.07, 	0.017},
        { 100, 	1.0, 	0.045, 	0.0075},
        { 160, 	1.0, 	0.027, 	0.0028},
        { 200, 	1.0, 	0.022, 	0.0019},
        { 325, 	1.0, 	0.014, 	0.0007},
        { 600, 	1.0, 	0.007, 	0.0002},
        { 3250, 1.0, 	0.0014, 0.000007}
    };
}