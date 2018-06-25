# Libraries:

link_libraries (gcc)

set (hwlib ${build_environment}/libraries/hwlib)
include_directories (${hwlib}/library)

set (catch ${build_environment}/libraries/Catch2)
include_directories (${catch}/single_include)

# Source Files:

set (sources
    src/pi_cam.cpp
    src/vector_2d.cpp
    src/base64_encoder.cpp	
    src/main.cpp
)
