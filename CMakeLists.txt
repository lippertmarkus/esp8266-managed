cmake_minimum_required(VERSION 3.2)
project(esp8266-managed)

include(CMakeListsPrivate.txt)

if(EXISTS "${CMAKE_CURRENT_SOURCE_DIR}/src/config.local.cpp")
    set(PIO_ENV esp12e-localconfig)
else()
    set(PIO_ENV esp12e)
endif()

add_custom_target(
    PLATFORMIO_BUILD ALL
    COMMAND ${PLATFORMIO_CMD} -f -c clion run -e ${PIO_ENV}
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
)

add_custom_target(
    PLATFORMIO_UPLOAD ALL
    COMMAND ${PLATFORMIO_CMD} -f -c clion -e ${PIO_ENV} run --target upload
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
)

add_custom_target(
    PLATFORMIO_CLEAN ALL
    COMMAND ${PLATFORMIO_CMD} -f -c clion -e ${PIO_ENV} run --target clean
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
)

add_custom_target(
    PLATFORMIO_TEST ALL
    COMMAND ${PLATFORMIO_CMD} -f -c clion -e ${PIO_ENV} test
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
)

add_custom_target(
    PLATFORMIO_PROGRAM ALL
    COMMAND ${PLATFORMIO_CMD} -f -c clion -e ${PIO_ENV} run --target program
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
)

add_custom_target(
    PLATFORMIO_UPLOADFS ALL
    COMMAND ${PLATFORMIO_CMD} -f -c clion -e ${PIO_ENV} run --target uploadfs
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
)

add_custom_target(
    PLATFORMIO_UPDATE_ALL ALL
    COMMAND ${PLATFORMIO_CMD} -f -c clion -e ${PIO_ENV} update
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
)

add_custom_target(
    PLATFORMIO_REBUILD_PROJECT_INDEX ALL
    COMMAND ${PLATFORMIO_CMD} -f -c clion -e ${PIO_ENV} init --ide clion
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
)


add_executable(${PROJECT_NAME} ${SRC_LIST})


