#pragma once

#define LINK_EDITOR_ENABLED

#include <SDL.h>
#include <functional>
#include <set>
#include <string>
#include <glm/glm.hpp>

#include "link/types.hpp"
#include "link/singleton.hpp"

#include "link/gfx/shader.hpp"

namespace link
{
    class DND
    {
        static constexpr char* Targets_Str[]
        {
            "DND_FILE_PATH",
            "DND_STRING",
        };

    public:
        enum class Target
        {
            FilePath,
            String
        };

        static const char* c_str(const Target target)
        {
            return Targets_Str[(u32)target];
        }
    };

    namespace EUtils
    {
        bool Button(const char* scope, const char* label, const glm::vec3& color = { -1, -1, -1 }, const glm::ivec2& size = { 0, 0 });
        inline bool Button(const char* scope, const char* label, const glm::ivec2& size, const glm::vec3& color = { -1, -1, -1 }) { Button(scope, label, color, size); }
    }

    struct Editor : Singleton<Editor>
    {

        static constexpr char* MAIN_WINDOW = "Main Window";
        static constexpr char* SCENE_CREATION_WINDOW = "Scene Creation";
        static constexpr char* COMPONENT_CREATION_WINDOW = "Component Creation";

#ifdef LINK_EDITOR_ENABLED
        void init();
        void begin_frame();
        void end_frame();
        void shutdown();
        void process_events(SDL_Event* event);
#else
        inline void init() {}
        inline void begin_frame() {}
        inline void end_frame() {}
        inline void shutdown() {}
        inline void process_events(SDL_Event* event) {}
#endif

    private:
        void set_dock();
    };
}

#define LINK_EDITOR link::Editor::get()


