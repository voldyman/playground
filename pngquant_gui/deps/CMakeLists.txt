include(FindPNG)
include_directories(${PNG_INCLUDE_DIRS})

set (CMAKE_C_FLAGS "--std=c99 ${CMAKE_C_FLAGS}")

add_library(libpngquant STATIC
  pngquant/pngquant.c
  pngquant/rwpng.c
  pngquant/lib/blur.c
  pngquant/lib/mediancut.c
  pngquant/lib/mempool.c
  pngquant/lib/nearest.c
  pngquant/lib/pam.c
  pngquant/lib/viter.c
  pngquant/lib/libimagequant.c
)

target_link_libraries(libpngquant ${PNG_LIBRARIES} m)
