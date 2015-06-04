//
//  VideoManager.h
//  L_Engine
//
//  Created by Imhoisili Otokhagua on 25/03/15.
//  Copyright (c) 2015 TriKomand. All rights reserved.
//

#ifndef __L_Engine__VideoManager__
#define __L_Engine__VideoManager__

#include <stdio.h>
#include <string>
#include <SDL2/SDL.h>

class VideoManager {
    static VideoManager *m_video;
    int m_width;
    int m_height;
    std::string m_title;
    SDL_Window* m_window;
    SDL_GLContext m_glContext;
    bool m_isCloseRequested;
    VideoManager(int width, int height, const std::string& title);
public:
    VideoManager(){}
    ~VideoManager();
    void starUp();
    void shutDown();
    void update();
    void swapBuffers();
    inline bool isCloseRequested() const { return m_isCloseRequested; }
    SDL_Window *getWindow() {return m_window;}
    int getWindowWidth() { return m_width; }
    int getWindowHeight() { return m_height; }
    static VideoManager *get(int width, int height, const std::string& title);
};

#endif /* defined(__L_Engine__VideoManager__) */
