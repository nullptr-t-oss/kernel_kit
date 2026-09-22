#!/bin/bash
# Copyright (C) 2023 The Android Open Source Project
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
#       http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.

set -e

[ "$#" -eq 1 ] || (echo "Specify target version as only argument (e.g. 7.0.0-pre.20230926.1)" && exit 1)

UPDATE_DIR=$( cd -- "$( dirname -- "${BASH_SOURCE[0]}" )" &> /dev/null && pwd )
VERSION=$1
VERSION_MAJOR=$(echo "${VERSION}" | cut -d- -f1)

STAGE=$(mktemp -d)
pushd "${STAGE}" > /dev/null

for arch in linux-x86_64; do
  mkdir ${arch}
  pushd ${arch} > /dev/null

  BAZEL_BINARY=bazel-${VERSION}-${arch}

  # Rolling releases come directly from bazel.build. Everything else is hosted
  # on Github
  if [[ $VERSION == *"-pre.2"* ]]; then
    URL=https://releases.bazel.build/${VERSION_MAJOR}/rolling/${VERSION}/${BAZEL_BINARY}
  else
    URL=https://github.com/bazelbuild/bazel/releases/download/${VERSION_MAJOR}/${BAZEL_BINARY}
  fi

  wget -nv "${URL}"
  wget -nv "${URL}.sha256"
  wget -nv "${URL}.sig"

  sha256sum --check "${BAZEL_BINARY}.sha256"

  # the public key is obtained from https://bazel.build/bazel-release.pub.gpg
  gpg --dearmor --output bazel-release.pub.gpg "${UPDATE_DIR}/bazel-release.pub.gpg"
  gpg --trust-model=always --no-default-keyring --keyring="$(pwd)/bazel-release.pub.gpg" --verify "${BAZEL_BINARY}.sig"

  rm ./*.{gpg,sig,sha256}

  ln -s "${BAZEL_BINARY}" bazel
  chmod +x "${BAZEL_BINARY}"
  ./bazel license > LICENSE

  # clean up the generated license file as it contains local paths
  sed 's#.*/embedded_tools/#embedded_tools/#' -i LICENSE

  popd > /dev/null
done

popd > /dev/null

rm -rf "${UPDATE_DIR}/bazel"
mv "${STAGE}" "${UPDATE_DIR}/bazel"

echo '****************************************'
echo "See $(dirname $0)/docs/update-bazel.md for next steps."
echo '****************************************'
