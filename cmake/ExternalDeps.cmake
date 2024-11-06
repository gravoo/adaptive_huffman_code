
# Włącz moduł FetchContent
include(FetchContent)

FetchContent_Declare(
    argh
    GIT_REPOSITORY https://github.com/adishavit/argh.git
    GIT_TAG        431bf323acd3bb805483491ff277dac5d85772ad
)

FetchContent_MakeAvailable(argh)