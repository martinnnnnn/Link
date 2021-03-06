#pragma once

#include <string>
#include <memory>
#include <json.hpp>
#include <glm/glm.hpp>

#include "c_material.hpp"
#include "link/types.hpp"
#include "link/editor/editor.hpp"
#include "link/editor/e_string.hpp"
#include "link/editor/e_texture_2D.hpp"

namespace link
{
    struct Shader;
    struct CTransform;
    struct Texture2D;

    struct CMaterial_Phong : public CMaterial
    {
        CMaterial_Phong(SceneObject* owner);

        void draw(u32 lights_count) override;
        void set_shader_consts() override;
        void set_texture(Texture2D* texture) override;

        void to_json(json& j);
        void from_json(const json& j);

        ETexture2D diffuse;
        ETexture2D normal;
        ETexture2D specular;
        ETexture2D ambient;
        ETexture2D shininess;

#ifdef LINK_EDITOR_ENABLED
        bool debug_draw() override;
#else
        inline bool debug_draw() { return false; }
#endif

        LINK_DECLARE_RTTI
    };
}

