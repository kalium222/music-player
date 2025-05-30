#pragma once

#include <mpv/client.h>
#include <string>

class Player
{
public:
    Player();
    ~Player();

    void play(std::string url);
    void pause();
    void stop();
    // TODO:
    void get_playback_pos();
    void set_vol();

private:
    mpv_handle *mpv;
};
