cmake_minimum_required(VERSION 3.8)

set(CMAKE_OSX_DEPLOYMENT_TARGET 10.12 CACHE STRING "Minimum macOS version targeted by RDMnet on macOS")
project(RDMnet VERSION 0.3.0)

# Sometimes the seems to be some weirdness with drive letter capitalization on Windows, so do a
# case-insensitive comparision
if(${CMAKE_HOST_SYSTEM_NAME} STREQUAL Windows)
  string(TOLOWER ${PROJECT_SOURCE_DIR} PROJECT_SOURCE_DIR_LC)
  string(TOLOWER ${CMAKE_SOURCE_DIR} CMAKE_SOURCE_DIR_LC)
else()
  set(PROJECT_SOURCE_DIR_LC ${PROJECT_SOURCE_DIR})
  set(CMAKE_SOURCE_DIR_LC ${CMAKE_SOURCE_DIR})
endif()

if(PROJECT_SOURCE_DIR_LC STREQUAL CMAKE_SOURCE_DIR_LC)
  if (MSVC)
    add_compile_options(/W4 /permissive-)
  elseif("${CMAKE_CXX_COMPILER_ID}" MATCHES "Clang" OR "${CMAKE_CXX_COMPILER_ID}" STREQUAL "GNU")
    add_compile_options(-Wall)
    if("${CMAKE_CXX_COMPILER_ID}" MATCHES "Clang")
      add_compile_options(-Wno-sign-conversion)
    else()
      add_compile_options(-Wno-sign-compare)
    endif()
  endif()

  # Allow folder grouping in generated IDE projects
  set_property(GLOBAL PROPERTY USE_FOLDERS ON)

  set(OPTION_DEFAULTS ON)
else()
  set(OPTION_DEFAULTS OFF)
endif()

set(RDMNET_ROOT ${CMAKE_CURRENT_LIST_DIR})
set(RDMNET_INCLUDE ${CMAKE_CURRENT_LIST_DIR}/include)
set(RDMNET_SRC ${CMAKE_CURRENT_LIST_DIR}/src)

list(APPEND CMAKE_MODULE_PATH ${CMAKE_CURRENT_LIST_DIR}/cmake)

option(RDMNET_BUILD_TESTS "Build the RDMnet unit tests" ${OPTION_DEFAULTS})
option(RDMNET_BUILD_GUI_EXAMPLES "Build the RDMnet GUI example applications" OFF)
option(RDMNET_BUILD_CONSOLE_EXAMPLES "Build the RDMnet console example applications" ${OPTION_DEFAULTS})
option(RDMNET_BUILD_TEST_TOOLS "Build the RDMnet test tools (typically used in development only)" OFF)

if(RDMNET_BUILD_TESTS)
  add_subdirectory(external/fff)
endif()

################################ Main libraries ###############################

add_subdirectory(src)

#################################### Tests ####################################

if(RDMNET_BUILD_TESTS)
  enable_testing()
  include(AddGoogleTest)
  add_subdirectory(tests)
endif()

################################### Examples ################################## 

if(RDMNET_BUILD_GUI_EXAMPLES OR RDMNET_BUILD_CONSOLE_EXAMPLES)
  add_subdirectory(examples)
endif()

##################################### Misc ####################################

if(RDMNET_BUILD_TEST_TOOLS)
  add_subdirectory(tools/test)
endif()

# On Windows, we put the DLL in the install directory to later be packaged with
# the installer.
if(DEFINED DNS_SD_DLL)
  install(FILES ${DNS_SD_DLL} DESTINATION bin)
  install(FILES ${DNS_SD_DLL} DESTINATION controller)
endif()
