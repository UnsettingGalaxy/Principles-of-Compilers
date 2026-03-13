#!/usr/bin/env bash
docker run --rm -it \
  -v "$(pwd)":/usr/src/compiler \
  compiler-env
