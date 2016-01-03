#include <iostream>
extern "C" {
  #include <pngquant/pngquant.c>
}
int main() {
    pngquant_options opt = {
        .floyd = 1.f,
    };
    opt.liq = liq_attr_create();

    pngquant_file("/home/voldyman/Pictures/profile.png",
                  "/home/voldyman/code/playground/pngquant_t/build/out.png",
                  &opt);
    liq_attr_destroy(opt.liq);
    std::cout << "Test" << std::endl;
    return 0;
}
