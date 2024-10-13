cmake_minimum_required(VERSION 3.14)
SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pthread")

project(md5_sum)
add_compile_options(-std=c++14)
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)

INCLUDE_DIRECTORIES(${CURL_INCLUDE_DIR})
INCLUDE_DIRECTORIES(${OPENSSL_INCLUDE_DIR})
include_directories(include)

file(GLOB_RECURSE srcs "src/*.cpp")
file(GLOB_RECURSE header_file "include/*.h" "include/*.hpp")

add_library(${PROJECT_NAME} SHARED ${srcs})

ament_target_dependencies(${PROJECT_NAME} rclcpp std_msgs)

install(FILES ${header_file} DESTINATION  include/${PROJECT_NAME})

install(
  TARGETS ${PROJECT_NAME}
  EXPORT ${PROJECT_NAME}
  LIBRARY DESTINATION lib
  ARCHIVE DESTINATION lib
  RUNTIME DESTINATION bin
  INCLUDES DESTINATION include
)

# Tell downstream packages where to find our headers
ament_export_include_directories(include)
# Tell downstream packages our libraries to link against
ament_export_libraries(${PROJECT_NAME})
# Help downstream packages to find transitive dependencies
ament_export_dependencies(
  rclcpp
  std_msgs
)
ament_package()
