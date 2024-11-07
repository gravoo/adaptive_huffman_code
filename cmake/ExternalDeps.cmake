
# Włącz moduł FetchContent
include(FetchContent)

FetchContent_Declare(
    argh
    GIT_REPOSITORY https://github.com/adishavit/argh.git
    GIT_TAG        431bf323acd3bb805483491ff277dac5d85772ad
)

FetchContent_Declare(
  Catch2
  GIT_REPOSITORY https://github.com/catchorg/Catch2.git
  GIT_TAG        v3.7.1 # or a later release
)
list(APPEND CMAKE_MODULE_PATH ${catch2_SOURCE_DIR}/extras)
FetchContent_MakeAvailable(Catch2)
FetchContent_MakeAvailable(argh)