#!/usr/bin/env bash

cd build

cmake .. -G"Unix Makefiles"
make MyBot
../halite -d "240 160" "./MyBot" "./MyBot"
