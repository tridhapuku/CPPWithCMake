cmake_minimum_required(VERSION 3.0.0)
project(WithCMake2 VERSION 0.1.0)
# set (CMAKE_CXX_STANDARD 17)
#============START - CMAKE TUTORIAL===================
# https://medium.com/@onur.dundar1/cmake-tutorial-585dd180109b
# Just adding some testing
message("Hello World from CMakeLists")
set(files a.txt b.txt c.txt d.txt e.txt)

foreach(file ${files})
    message("FIlename: ${file}")
endforeach()

message("CMAKE_CXX_STANDARD = ${CMAKE_CXX_STANDARD}")
set(CMAKE_CXX_STANDARD 20)
message("CMAKE_CXX_STANDARD = ${CMAKE_CXX_STANDARD}")
message("CMAKE_SYSTEM_PROCESSOR = ${CMAKE_SYSTEM_PROCESSOR}")
message("CMAKE_HOST_SYSTEM_NAME = ${CMAKE_HOST_SYSTEM_NAME}")
message("CMAKE_SYSTEM = ${CMAKE_SYSTEM}")
message("CMAKE_RUNTIME_OUTPUT_DIRECTORY = ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}")
message("CMAKE_BINARY_DIR = ${CMAKE_BINARY_DIR}")

if(UNIX)
    message("This is a ${CMAKE_SYSTEM_NAME} system")
elseif(WIN32)
    message("This is a Windows System -- WIN32")
endif()
# or use MATCHES to see if actual system name 
# Darwin is Apple's system name
if(${CMAKE_SYSTEM_NAME} MATCHES Darwin)
    message("This is a ${CMAKE_SYSTEM_NAME} system")
elseif(${CMAKE_SYSTEM_NAME} MATCHES Windows)
    add_definitions(-DCMAKEMACROSAMPLE="Windows PC")
    message("This is a Windows System")
endif()

# set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR}/bin)

# For Lib =================
# set(LIBRARY_OUTPUT_PATH ${CMAKE_BINARY_DIR}/lib)

# add_library(math SHARED lib/math/operations.cpp)
# add_library(math STATIC lib/math/operations.cpp)
add_subdirectory(lib/math)
set(SOURCES main.cpp 
     
     #Problem
     TryAlgorithm/SimpleProblems/TryRandomQues.cpp
     TryAlgorithm/SimpleProblems/TryRandomQues.hpp
     TryAlgorithm/SimpleProblems/TrySignalProcessing.hpp
     TryAlgorithm/SimpleProblems/TrySignalProcessing.cpp
     TryAlgorithm/SimpleProblems/TryString.hpp
     TryAlgorithm/SimpleProblems/TryString.cpp

     #CPPLangg Folder
     TryAlgorithm/TryCPPLangg/TrySTL.cpp
     TryAlgorithm/TryCPPLangg/TrySTL.hpp
     TryAlgorithm/TryCPPLangg/TryOOP.cpp
     TryAlgorithm/TryCPPLangg/TryOOP.hpp
     TryAlgorithm/TryCPPLangg/TryConcurrency.cpp
     TryAlgorithm/TryCPPLangg/TryConcurrency.cpp
     TryAlgorithm/TryCPPLangg/TryTemplate.cpp
     TryAlgorithm/TryCPPLangg/TryTemplate.hpp
     TryAlgorithm/TryCPPLangg/TryCPPConcepts.hpp
     TryAlgorithm/TryCPPLangg/TryCPPConcepts.cpp
     TryAlgorithm/TryCPPLangg/TryMemoryManagement.hpp
     TryAlgorithm/TryCPPLangg/TryMemoryManagement.cpp
    
     #Datastructure folder
     TryAlgorithm/TryDataStructure/TryTrees.hpp
     TryAlgorithm/TryDataStructure/TryTrees.cpp
     TryAlgorithm/TryDataStructure/TryLL.hpp
     TryAlgorithm/TryDataStructure/TryLL.cpp
     TryAlgorithm/TryDataStructure/TrySTLProblems/TryStackProb.hpp
     TryAlgorithm/TryDataStructure/TrySTLProblems/TryStackProb.cpp
     )
# add_executable(WithCMake2 main.cpp)
add_executable(WithCMake2 ${SOURCES})

#Add subdirectory
# add_subdirectory(TrySeparateFolder)
# target_link_libraries(WithCMake2 TrySeparateFolder)

find_package(Boost 1.82)

#check for libaray
if(Boost_FOUND)
    message("Boost Found")
    include_directories(${Boost_INCLUDE_DIRS})
    target_link_libraries(WithCMake2 ${Boost_LIBRARIES})
elseif(NOT Boost_FOUND)
    message("Boost Not Found")
    message("Boost_INCLUDE_DIRS : ${Boost_INCLUDE_DIRS}")
    # set(BOOST_INCLUDEDIR ${"C:\\Program Files\\Boost\\boost_1_82_0"})
    # set(BOOST_INCLUDEDIR "C:\\Program Files\\Boost\\boost_1_82_0")
    # set(BOOST_LIBRARYDIR "C:\\Program Files\\Boost\\boost_1_82_0\\libs")
    # set(BOOST_ROOT "C:\\Program Files\\Boost\\boost_1_82_0\\boost")
    # include_directories(${BOOST_INCLUDEDIR})
    # LINK_DIRECTORIES(${BOOST_LIBRARYDIR})
    message("Boost_INCLUDE_DIRS : ${Boost_INCLUDE_DIRS}")
    # add_executable(WithCMake2 main.cpp)
    # target_link_libraries(WithCMake2 ${BOOST_LIBRARYDIR})
    message("Boost_LIBRARIES : ${Boost_LIBRARIES}")
    # target_link_libraries(WithCMake2 ${Boost_LIBRARIES})
endif()

# set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS True)
target_link_libraries(WithCMake2 math)
if(${CMAKE_BUILD_TYPE} MATCHES Debug)
    message("Debug Build")
elseif(${CMAKE_BUILD_TYPE} MATCHES Release)
    message("Release Build")
endif()
#******End For Lib =================
# set(SOURCES main.cpp
#             lib/math/operations.cpp
#             lib/math/operations.hpp)
# add_executable(WithCMake2 ${SOURCES})

#=============END - CMAKE TUTORIAL==================


include(CTest)
enable_testing()

# add_executable(WithCMake2 main.cpp)
# add_executable(WithCMake2 main.cpp lib/math/operations.cpp 
#                 lib/math/operations.hpp)


# =================================
# ==============================

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)

