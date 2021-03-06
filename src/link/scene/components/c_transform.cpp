#include "c_transform.hpp"

#include <glm/gtx/transform.hpp>
#include <imgui.h>

#include "link/gfx/debug.hpp"
#include "link/serialization.hpp"

namespace link
{
    LINK_IMPLEMENT_RTTI(link, CTransform, Component);

    glm::mat4 CTransform::get_matrix()
    {
        glm::mat4 rotation_x = glm::rotate(rotation.x, glm::vec3(1, 0, 0));
        glm::mat4 rotation_y = glm::rotate(rotation.y, glm::vec3(0, 1, 0));
        glm::mat4 rotation_z = glm::rotate(rotation.z, glm::vec3(0, 0, 1));

        return glm::translate(glm::mat4(1.0f), position) * rotation_x * rotation_y * rotation_z * glm::scale(glm::mat4(1), scale);
    }

    glm::vec3 CTransform::forward()
    {
        glm::mat4 mat = get_matrix();

        return glm::vec3(-mat[2][0], -mat[2][1], -mat[2][2]);
    }

    void CTransform::to_json(json& j)
    {
        Component::to_json(j);

        JsonUtils::to_json(j, position, "position");
        JsonUtils::to_json(j, rotation, "rotation");
        JsonUtils::to_json(j, scale, "scale");
    }

    void CTransform::from_json(const json& j)
    {
        Component::from_json(j);

        JsonUtils::from_json(j, position, "position");
        JsonUtils::from_json(j, rotation, "rotation");
        JsonUtils::from_json(j, scale, "scale");
    }

#ifdef LINK_EDITOR_ENABLED
    bool CTransform::debug_draw()
    {
        if (!Component::debug_draw())
            return false;

        ImGui::DragFloat3("Position", (float*)&position, 0.01f, F32_MIN, F32_MAX);
        ImGui::DragFloat3("Rotation", (float*)&rotation, 0.01f, F32_MIN, F32_MAX);
        ImGui::DragFloat3("Scale", (float*)&scale, 0.01f, F32_MIN, F32_MAX);

        LINK_DEBUG->line(position, position + forward(), glm::vec3(0, 1, 1));

        return true;
    }
#endif
}