#!/bin/bash -eu

if [ "$#" -ne 3 ]; then
  echo "usage: $0 <target dir> linux_musl.zip linux_musl_sysroots.zip" >&2
  exit 1
fi

TARGET="$1"
LINUX_MUSL="$2"
LINUX_MUSL_SYSROOTS="$3"

function unzip_to() {
    rm -rf "$1"
    if [ -n "$2" ]; then
      mkdir "$1"
      unzip -q -d "$1" "$2"
    fi
}

unzip_to "$TARGET"/linux_musl-x86 "$LINUX_MUSL"
unzip_to "$TARGET"/sysroots/x86_64-unknown-linux-musl "$LINUX_MUSL_SYSROOTS"
