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

# boost 
find_package(Boost REQUIRED)
find_package(Boost COMPONENTS filesystem thread REQUIRED)
include_directories(${Boost_INCLUDE_DIRS})

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

add_executable(demo example/demo.cpp)
target_link_libraries(demo 
        apriltags
        glog
        ${Boost_LIBRARIES})

# set include
set(APRILTAGS_HEADER_FILES
  AprilTags/Edge.h
  AprilTags/Gridder.h
  AprilTags/Tag16h5.h
  AprilTags/Tag36h9.h
  AprilTags/FloatImage.h
  AprilTags/Homography33.h
  AprilTags/Tag16h5_other.h
  AprilTags/TagDetection.h
  AprilTags/Gaussian.h
  AprilTags/MathUtil.h
  AprilTags/Tag25h7.h
  AprilTags/TagDetector.h
  AprilTags/GLine2D.h
  AprilTags/pch.h
  AprilTags/Tag25h9.h
  AprilTags/TagFamily.h
  AprilTags/GLineSegment2D.h
  AprilTags/Quad.h
  AprilTags/Tag36h11.h
  AprilTags/UnionFindSimple.h
  AprilTags/GrayModel.h
  AprilTags/Segment.h
  AprilTags/Tag36h11_other.h
  AprilTags/XYWeight.h
)

install(
  FILES ${APRILTAGS_HEADER_FILES}
  DESTINATION include/AprilTags
)