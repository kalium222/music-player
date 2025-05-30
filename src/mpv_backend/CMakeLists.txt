add_library(mpv_backend
    player.cpp
)

target_include_directories(mpv_backend PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}
)
