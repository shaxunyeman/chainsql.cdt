#!/bin/bash
set -e

DIR=$(cd $(dirname ${BASH_SOURCE[0]}) && pwd)

cd ${DIR}/../..
${DIR}/jsoncons_tests
