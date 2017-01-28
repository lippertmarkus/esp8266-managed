cmake_minimum_required(VERSION 3.2)
project(esp8266-managed)

include(CMakeListsPrivate.txt)

if(EXISTS "${CMAKE_CURRENT_SOURCE_DIR}/src/config.local.cpp")
    set(PIO_ENV localconfig)
else()
    set(PIO_ENV default)
endif()

add_custom_target(
        PLATFORMIO_BUILD ALL
        COMMAND ${PLATFORMIO_CMD} -f -c clion run -e ${PIO_ENV}
        WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
)

add_custom_target(
        PLATFORMIO_UPLOAD ALL
        COMMAND ${PLATFORMIO_CMD} -f -c clion run -e ${PIO_ENV} --target upload
        WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
)

add_custom_target(
        PLATFORMIO_CLEAN ALL
        COMMAND ${PLATFORMIO_CMD} -f -c clion run -e ${PIO_ENV} --target clean
        WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
)

add_custom_target(
        PLATFORMIO_TEST ALL
        COMMAND ${PLATFORMIO_CMD} -f -c clion test -e ${PIO_ENV}
        WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
)

add_custom_target(
        PLATFORMIO_PROGRAM ALL
        COMMAND ${PLATFORMIO_CMD} -f -c clion run -e ${PIO_ENV} --target program
        WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
)

add_custom_target(
        PLATFORMIO_UPLOADFS ALL
        COMMAND ${PLATFORMIO_CMD} -f -c clion run -e ${PIO_ENV} --target uploadfs
        WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
)

add_custom_target(
        PLATFORMIO_UPDATE_ALL ALL
        COMMAND ${PLATFORMIO_CMD} -f -c clion update
        WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
)

add_custom_target(
        PLATFORMIO_REBUILD_PROJECT_INDEX ALL
        COMMAND ${PLATFORMIO_CMD} -f -c clion init --ide clion
        WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
)

add_executable(${PROJECT_NAME} ${SRC_LIST})