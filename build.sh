#! /bin/bash
#

#set -e

BIN=$(cd "$(dirname $0)" && pwd)

usage() {
    cat <<EOF
`basename $0` [-c|-h]

Build script

Options:
    -c: clean build
    -h: usage

EOF
}

initRemote() {
    conan remote add bincrafters "https://api.bintray.com/conan/bincrafters/public-conan" &> /dev/null
}

main() {
    clean=0
    while getopts 'ch' c; do
        case $c in
            c) clean=1 ;;
            h) usage && exit 0 ;;
        esac
    done

    [ $clean -eq 1 ] && {
        rm -rf $BIN/build
    }

    [ -d $BIN/build ] || {
        echo "INFO: Clean run"
        mkdir $BIN/build
        initRemote
    }

    pushd $BIN/build
    conan install --build libtiff --build sdl2_image ..
    #gcc -g -o lgtm lgtm.c -L/usr/lib -pthread -lSDL2 -lSDL2_image -I/usr/include/SDL2 -D_REENTRANT
    cmake .. -DCMAKE_BUILD_TYPE=Release
    cmake --build .
}

main "$@"
