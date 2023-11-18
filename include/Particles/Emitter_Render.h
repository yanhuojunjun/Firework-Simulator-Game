#ifndef EMITTER_RENDER_H
#define EMITTER_RENDER_H

#include "glad.h"
#include "glm.hpp"
#include "gtc/matrix_transform.hpp"
#include "gtc/type_ptr.hpp"
#include "stb_image.h"
#include "Shader.h"
#include "ICamera.h"

#include <vector>

#include "Emitter.h"
#include "Particle_Emitter.h"
class Emitter_Render {
public:
    Emitter_Render(ICamera* cam); //创建shader，连接camera，创建VAO VBO，生成纹理
    void AddEmitter(ParticleEmitter* new_emitter); //增加粒子群
    void Update_and_Collect(uint64_t millisecond_passby); //更新所有粒子的信息，自动删除死亡的粒子群，收集所有粒子的信息
    void Render(); //渲染粒子
    ~Emitter_Render(); //删除shader，vao，vbo
protected:
    std::vector<float> vbo_buffer; // 缓存所有粒子的数据
    unsigned int VAO;
    unsigned int VBO;
    Shader shader;
    ICamera* camera;
    unsigned int texture;
    std::vector < ParticleEmitter* > particle_emitters; // 需要渲染的所有的粒子群
};


#endif