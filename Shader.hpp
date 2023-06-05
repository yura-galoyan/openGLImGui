#include <string_view>

#ifndef SHADER_HPP
#define SHADER_HPP


class Shader
{
private:
    class VertexCode;
    class FragmentCode;

public:
    Shader(const std::string_view vertexPath,const std::string_view fragmentPath );
    void use();
    void setBool(const std::string &name, bool value) const;
    void setInt(const std::string &name, int value) const;
    void setFloat(const std::string &name, float value) const;
    inline const unsigned int get_id()const{
        return id;
    };

private:
    std::string getFileContents(const std::string_view path) const;
    unsigned int compileShader(const std::string& code, std::string_view name = "unname debuging") const;
    void compileShaderProgram(unsigned int vertexId,unsigned int fragmentId);

private:
    unsigned int id;

};

#endif//SHADER_HPP