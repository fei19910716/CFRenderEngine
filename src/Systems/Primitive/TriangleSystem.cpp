#include "TriangleSystem.h"

#include <QDebug>
#include <QTime>

#include "stb_image_write.h"
#include "Render/Base/ShaderProgram.h"
#include "Render/Base/VertexBuffer.h"
#include "Render/Base/IndexBuffer.h"
#include "Render/Base/VertexArray.h"
#include "Render/Base/Texture.h"
#include "Render/Base/RenderBuffer.h"

#include "Render/Renderer/SimpleRenderer.h"
#include "Utils/RenderUtils.h"
#include "Core/glm.h"

std::shared_ptr<CFEngineRender::Renderer> CFEngineRender::TriangleSystem::update(entt::registry &registry, float dt){

    auto view = registry.view<CFEngineRender::Triangle>();
    for(auto entity: view) {
        auto &triangle = view.get<CFEngineRender::Triangle>(entity);

        if(!triangle.enable()) continue;

        auto renderer_  = std::make_shared<CFEngineRender::SimpleRenderer>();
        auto vert = Utils::readShaderSource(vertexShader_);
        auto frag = Utils::readShaderSource(fragmentShader_);
        auto shaderProgram = std::make_shared<CFEngineRender::ShaderProgram>(vert,frag,false);
        shaderProgram->clearColor();
        shaderProgram->id_ = "primitive";
        //renderer_->setShaderProgram(shaderProgram);

        auto vao = std::make_shared<CFEngineRender::VertexArray>();
        auto vboLayout = std::make_shared<VertexLayout>();
        vboLayout->begin().add(Attribute::Enum::Position,3,AttribType::Enum::Float)
                          .add(Attribute::Enum::Color,3,AttribType::Enum::Float)
                          .end();

        auto vertexBuffer = std::make_shared<CFEngineRender::VertexBuffer>(triangle.vertices,vboLayout);
        auto indexBuffer = std::make_shared<CFEngineRender::IndexBuffer>(triangle.indices);

        vao->bindVertexBuffer(vertexBuffer);
        vao->bindIndexBuffer(indexBuffer);

        vao->id_ = "primitive";
//! 线框模式
//         glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);


        shaderProgram->use();
        vao->use();

        glm::mat4 trans;
        //trans = glm::rotate(trans, (float)QTime::currentTime().second(), glm::vec3(0.0f, 0.0f, 1.0f));

        shaderProgram->setVec4("u_color",1.0,1.0,0.0,1.0);

        //renderer_->setVertexArray(vao);
        return renderer_;
        // glDrawArrays(GL_TRIANGLES, 0, 3);
        //glDrawElements(GL_TRIANGLES, 3, GL_UNSIGNED_INT, 0);


//        vao->release();
//        vertexBuffer->release();
//        indexBuffer->release();
//        shaderProgram->release();
    }
    return nullptr;
}

CFEngineRender::TriangleSystem::TriangleSystem():System() {

}
