

#include <vector>

#include "link/singleton.hpp"
#include "shader.hpp"

namespace link
{
    struct Debug : Singleton<Debug>
    {
        const char* vertex_shader_source =
            "#version 420 core\n"
            "layout(location = 0) in vec3 position;\n"
            "layout(location = 1) in vec3 color;\n"
            "uniform mat4 mvp;\n"
            "out vec3 VS_OUT_color;\n"
            "void main()\n"
            "{\n"
            "    VS_OUT_color = color;\n"
            "    gl_Position = mvp * vec4(position, 1.0f);\n"
            "}\n";

        const char* fragment_shader_source =
            "#version 420 core\n"
            "in vec3 VS_OUT_color;\n"
            "out vec4 FragColor;\n"
            "void main()\n"
            "{\n"
            "    FragColor = vec4(VS_OUT_color, 1.0);\n"
            "}\n";

        void init();
        void draw();
        void line(const glm::vec3& point1, const glm::vec3& point2, const glm::vec3& color);
        void line(const glm::vec3& point1, const glm::vec3& point2, const glm::vec3& color1, const glm::vec3& color2);
        void cube(const glm::vec3& center, const f32 width, const f32 height, const glm::vec3& color);

        static constexpr u32 VERTICES_MAX_COUNT = 1024 * 1024;

        u32                     vertex_count;
        Shader                  shader;
        std::vector<glm::vec3>  debug_vertices;
        std::vector<glm::vec3>  debug_colors;
        u32                     vao;
        u32                     vbo;
        u32                     cbo;
    };
}

#define LINK_DEBUG link::Debug::get()
