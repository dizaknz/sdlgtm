FROM alpine:3

RUN apk add \
    cmake \
    pip

RUN pip install conan

RUN conan remote add bincrafters "https://api.bintray.com/conan/bincrafters/public-conan"

RUN mkdir build && \
    cd build && conan install ..
