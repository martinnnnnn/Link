#include "e_string.hpp"

#include <fmt/ostream.h>

#ifdef LINK_EDITOR_ENABLED
#include <imgui.h>
#include <imgui_stdlib.h>
#endif LINK_EDITOR_ENABLED

namespace link
{
    EString::EString(const std::string& label, const std::string& v)
        : label(label)
        , value(v)
        , previous(v)
    {
    }

    void EString::set(const std::string& new_value)
    {
        value = new_value;
        previous = new_value;
    }

#ifdef LINK_EDITOR_ENABLED
    bool EString::debug_draw()
    {
        const std::string previous = value;

        ImGui::InputText(label.c_str(), &value);

        if (ImGui::BeginDragDropTarget())
        {
            if (const ImGuiPayload* payload = ImGui::AcceptDragDropPayload(DND::c_str(DND::Target::FilePath)))
            {
                uptr* ptr = (uptr*)(payload->Data);
                FileSystem::Node* fs_node = (FileSystem::Node*)(*ptr);
                value = fs_node->get_absolute();
            }
            else if (const ImGuiPayload* payload = ImGui::AcceptDragDropPayload(DND::c_str(DND::Target::String)))
            {
                value = std::string((char*)payload->Data, payload->DataSize);
            }
            ImGui::EndDragDropTarget();
        }

        return value.compare(previous) != 0;
    }
#endif
}