#!/bin/bash

set -ex

cd /build
cmake -G Ninja -DCMAKE_BUILD_TYPE=Release -B /build /root/project
ninja unit_tests

