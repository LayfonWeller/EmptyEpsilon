#ifndef DEBUG_RENDERER_H
#define DEBUG_RENDERER_H

#include "engine.h"

class DebugRenderer : public Renderable, public InputEventHandler
{
private:
    sf::Clock fps_timer;
    float fps = 0.0;
    int fps_counter = 0;
    
    bool show_fps = false;
    bool show_datarate = false;
    bool show_timing_graph = false;
    
    std::vector<Engine::EngineTiming> timing_graph_points;
public:
    DebugRenderer();

    virtual void render(sf::RenderTarget& window);
    virtual void handleKeyPress(sf::Event::KeyEvent key, int unicode);
};

#endif//DEBUG_RENDERER_H
