#!/bin/bash
set -e

BIN=$(cd "$(dirname $0)" && pwd)

usage() {
    cat <<EOF
`basename $0` [-h] -a <Android SDK> -n <Android NDK> -p <package name> -s <SDL project>

Generate Android project

Options:
    -h Usage
    -a Android SDK directory
    -n Android NDK directory
    -p Output package name
    -s SDL2 source code directory

EOF
}

info() {
    echo -e "\e[1m[$(date --rfc-3339=ns)]  INFO:\e[0m $@"
}

error() {
    echo -e "\e[31m[$(date --rfc-3339=ns)] ERROR:\e[0m $@"
}

main() {
    while getopts 'ha:n:p:s:' c; do
        case $c in
            h) usage && exit 0 ;;
            a) sdk=$OPTARG ;;
            n) ndk=$OPTARG ;;
            p) package=$OPTARG ;;
            s) sdl=$OPTARG ;;
        esac
    done
    [ -z "$sdk" -o -z "$ndk" -o -z "$package" -o -z "$sdl" ] && {
        error "Require mandatory options"
        usage
        exit 1
    }

    [ -d $BIN/Android ] || mkdir -p $BIN/Android
    info "Generating Android project"
    (
        cd $sdl/build-scripts
        ANDROID_HOME=$sdk ANDROID_NDK_HOME=$ndk ./androidbuild.sh $package $BIN/lgtm.c || {
            error "Failed to generate Android project"
            exit 1
        }
        mv $sdl/build/$package $BIN/Android/lgtm
    )
}

main "$@"
