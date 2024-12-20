#ifndef FIREWORK_VIEWER_H
#define FIREWORK_VIEWER_H

#include "ICamera.h"
#include "SDL.h"

#include <iostream>

class Firework_Viewer :public ICamera
{
protected:
    // 控制移动距离
    Uint64 Last_Frame_time;
    Uint64 Time_Pass_By;
    // 走路浏览模式 否则飞行模式
    bool is_view_mode;
    // 连续移动 前后左右上下
    glm::vec3 direct[6];
    // 跳跃
    bool jumping;
public:
    /*
        摄像机位置 世界上坐标 偏航角 俯仰角(不能超过90度)
        默认初始: 摄像机朝向(0, 0, -1)点,
    */
    Firework_Viewer(glm::vec3 position = glm::vec3(0.0f, 0.0f, 0.5f), glm::vec3 up = glm::vec3(0.0f, 1.0f, 0.0f), float yaw = YAW, float pitch = PITCH);
    /*
        摄像机位置值 世界上坐标值 偏航角 俯仰角(不能超过90度)
    */
    Firework_Viewer(float posX, float posY, float posZ, float upX, float upY, float upZ, float yaw, float pitch);

    void FlushFrameTime();

    void ProcessKeyboardDown(SDL_Event& event);

    void ProcessKeyboardUp(SDL_Event& event);

    void ProcessMouseMovement(SDL_Event& event);

    void ProcessMouseScroll(SDL_Event& event);

    void ProcessEvent(SDL_Event& event);

    ~Firework_Viewer();
protected:
    void ProcessCommand(SDL_Event& event);
};


#endif