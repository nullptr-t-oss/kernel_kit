#!/bin/bash -e

if [ -z $1 ]; then
    echo "usage: $0 <build number>"
    exit 1
fi

readonly BUILD_NUMBER=$1
readonly CI_BRANCH=git_main-kernel-build-tools

cd "$(dirname $0)"

readonly OLD_BUILD_NUMBER=$(cat BUILD_NUMBER)

if ! git diff HEAD --quiet; then
    echo "must be run with a clean prebuilts/kernel-build-tools project"
    exit 1
fi

readonly tmpdir=$(mktemp -d)

function finish {
    if [ ! -z "${tmpdir}" ]; then
        rm -rf "${tmpdir}"
    fi
}
trap finish EXIT

function fetch_artifact() {
    /google/data/ro/projects/android/fetch_artifact --branch ${CI_BRANCH} --bid ${BUILD_NUMBER} --target $1 "$2" "$3"
}

fetch_artifact linux_musl manifest_${BUILD_NUMBER}.xml "${tmpdir}/manifest.xml"
fetch_artifact linux_musl build-prebuilts.zip "${tmpdir}/linux_musl.zip"
fetch_artifact linux_musl musl-sysroot-x86_64-unknown-linux-musl.zip "${tmpdir}/musl-sysroot-x86_64-unknown-linux-musl.zip"

./unpack-prebuilts.sh . "${tmpdir}"/{linux_musl.zip,musl-sysroot-x86_64-unknown-linux-musl.zip}

cp -f "${tmpdir}/manifest.xml" manifest.xml
echo "${BUILD_NUMBER}" > BUILD_NUMBER

git add manifest.xml linux_musl-x86 sysroots/x86_64-unknown-linux-musl BUILD_NUMBER
git commit -m "Update kernel-build-tools to ab/${BUILD_NUMBER}

http://android-build/range_search/cls/from_id/${BUILD_NUMBER}/to_id/${OLD_BUILD_NUMBER}/?selectedFromTarget=linux_musl

Test: treehugger"
