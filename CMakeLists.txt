cmake_minimum_required(VERSION 3.15)
project(stag)

find_package(OpenCV REQUIRED)

include_directories(
  include
  ${OpenCV_INCLUDE_DIRS}
)

add_executable(stag
  ${PROJECT_SOURCE_DIR}/src/stag/Decoder.cpp
  ${PROJECT_SOURCE_DIR}/src/stag/Drawer.cpp
  ${PROJECT_SOURCE_DIR}/src/stag/EDInterface.cpp
  ${PROJECT_SOURCE_DIR}/src/stag/Ellipse.cpp
  ${PROJECT_SOURCE_DIR}/src/stag/Marker.cpp
  ${PROJECT_SOURCE_DIR}/src/stag/PoseRefiner.cpp
  ${PROJECT_SOURCE_DIR}/src/stag/Quad.cpp
  ${PROJECT_SOURCE_DIR}/src/stag/QuadDetector.cpp
  ${PROJECT_SOURCE_DIR}/src/stag/Stag.cpp
  ${PROJECT_SOURCE_DIR}/src/stag/utility.cpp
  ${PROJECT_SOURCE_DIR}/src/stag/ED/ED.cpp
  ${PROJECT_SOURCE_DIR}/src/stag/ED/EDInternals.cpp
  ${PROJECT_SOURCE_DIR}/src/stag/ED/EDLines.cpp
  ${PROJECT_SOURCE_DIR}/src/stag/ED/GradientOperators.cpp
  ${PROJECT_SOURCE_DIR}/src/stag/ED/ImageSmooth.cpp
  ${PROJECT_SOURCE_DIR}/src/stag/ED/LineSegment.cpp
  ${PROJECT_SOURCE_DIR}/src/stag/ED/MyMath.cpp
  ${PROJECT_SOURCE_DIR}/src/stag/ED/NFA.cpp
  ${PROJECT_SOURCE_DIR}/src/stag/ED/ValidateEdgeSegments.cpp
  ${PROJECT_SOURCE_DIR}/src/main.cpp
)


target_link_libraries(stag
  ${OpenCV_LIBS}
  ${CPP_REQUIRED_LIBRARIES}
)
