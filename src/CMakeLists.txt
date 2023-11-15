# Compile every *.cc file inside current directory
FILE(GLOB_RECURSE SRC_FILES CONFIGURE_DEPENDS
    ${CMAKE_CURRENT_SOURCE_DIR}/*.cc
)

# Create executable
ADD_EXECUTABLE(biquadris ${SRC_FILES})

# Header file locations
TARGET_INCLUDE_DIRECTORIES(biquadris PUBLIC ${CMAKE_SOURCE_DIR}/include)

# Set compiler flags
TARGET_COMPILE_OPTIONS(biquadris PUBLIC -std=c++14 -Werror=vla -Wall)

# Use X11
FIND_PACKAGE(X11 REQUIRED)
INCLUDE_DIRECTORIES(${X11_INCLUDE_DIR})
TARGET_LINK_LIBRARIES(biquadris ${X11_LIBRARIES})

