#include <iostream>
#include <mpv/client.h>

static inline void check_error(int status)
{
    if (status < 0)
    {
        std::cout << "mpv API error: " << mpv_error_string(status) << std::endl;
        exit(1);
    }
}

int main(int argc, char *argv[])
{
    if (argc!=2)
    {
        std::cout << "pass a single media file as argument" << std::endl;
        return 1;
    }

    mpv_handle *ctx = mpv_create();
    if (!ctx)
    {
        std::cerr << "Failed to create MPV context" << std::endl;
        return 1;
    }

    check_error(mpv_set_option_string(ctx, "input-default-bindings", "yes"));
    mpv_set_option_string(ctx, "input-vo-keyboard", "yes");
    int val = 1;
    check_error(mpv_set_option(ctx, "osc", MPV_FORMAT_FLAG, &val));

    // Done setting up options.
    check_error(mpv_initialize(ctx));

    // Play this file.
    const char *cmd[] = {"loadfile", argv[1], NULL};
    check_error(mpv_command(ctx, cmd));

    // Let it play, and wait until the user quits.
    while (1) {
        mpv_event *event = mpv_wait_event(ctx, 10000);
        printf("event: %s\n", mpv_event_name(event->event_id));
        if (event->event_id == MPV_EVENT_END_FILE)
            break;
    }

    mpv_terminate_destroy(ctx);
    return 0;
}
