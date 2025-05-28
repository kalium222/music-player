#include <iostream>
#include <mpv/client.h>

int main()
{
    mpv_handle *ctx = mpv_create();
    if (!ctx) {
        std::cerr << "Failed to create MPV context" << std::endl;
        return 1;
    }
    return 0;
}
