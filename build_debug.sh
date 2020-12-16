meson setup build -Dflavors=drm-gl,drm-glesv2,wayland-gl,wayland-glesv2,x11-gl,x11-glesv2
meson build
meson configure build -D c_args=-g
meson configure build -D cpp_args=-g
meson configure build -D buildtype=debug
ninja -C build