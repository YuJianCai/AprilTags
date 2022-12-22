cmake_minimum_required(VERSION 3.6)
project(apriltags VERSION 1.0)

# add all source code
file(GLOB SOURCE_FILES "src/*.cc")
include_directories(AprilTags . /opt/local/include)
add_library(apriltags ${SOURCE_FILES})

# require opencv dependence
find_package(OpenCV 3.0 REQUIRED)
include_directories(${OpenCV_INCLUDE_DIRS})

# require Eigen3
find_package(Eigen3 REQUIRED)
include_directories("/usr/include/eigen3")

# link
target_link_libraries(apriltags ${OpenCV_LIBS})

# installation
install(TARGETS apriltags
        EXPORT apriltagsConfig 
        LIBRARY DESTINATION lib
        ARCHIVE DESTINATION lib
        PUBLIC_HEADER DESTINATION include
        )

install(EXPORT apriltagsConfig
        FILE apriltagsConfig.cmake
	  DESTINATION lib/cmake/apriltags)
