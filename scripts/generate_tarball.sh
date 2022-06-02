#! /bin/bash

NAME=$1
OS=$2
CDT_PREFIX=${PREFIX}/${SUBPREFIX}
mkdir -p ${PREFIX}/bin/
mkdir -p ${PREFIX}/lib/cmake/${PROJECT}
mkdir -p ${CDT_PREFIX}/bin
mkdir -p ${CDT_PREFIX}/include
mkdir -p ${CDT_PREFIX}/lib/cmake/${PROJECT}
mkdir -p ${CDT_PREFIX}/cmake
mkdir -p ${CDT_PREFIX}/scripts
mkdir -p ${CDT_PREFIX}/licenses

#echo "${PREFIX} ** ${SUBPREFIX} ** ${CDT_PREFIX}"

# install binaries
cp -R ${BUILD_DIR}/bin/* ${CDT_PREFIX}/bin || exit 1
cp -R ${BUILD_DIR}/licenses/* ${CDT_PREFIX}/licenses || exit 1

# install cmake modules
sed "s/_PREFIX_/\/${SPREFIX}/g" ${BUILD_DIR}/modules/chainsqlWasmToolchainPackage.cmake &> ${CDT_PREFIX}/lib/cmake/${PROJECT}/chainsqlWasmToolchain.cmake || exit 1
sed "s/_PREFIX_/\/${SPREFIX}\/${SSUBPREFIX}/g" ${BUILD_DIR}/modules/${PROJECT}-config.cmake.package &> ${CDT_PREFIX}/lib/cmake/${PROJECT}/${PROJECT}-config.cmake || exit 1

# install scripts
cp -R ${BUILD_DIR}/scripts/* ${CDT_PREFIX}/scripts  || exit 1

# install misc.
cp ${BUILD_DIR}/chainsql.imports ${CDT_PREFIX} || exit 1

# install wasm includes
cp -R ${BUILD_DIR}/include/* ${CDT_PREFIX}/include || exit 1

# install wasm libs
cp ${BUILD_DIR}/lib/*.a ${CDT_PREFIX}/lib || exit 1

# install libc++.so
if [[ "$OS" == "ubuntu-16.04" ]]; then
    cp /usr/lib/libc++.so.1.0 ${CDT_PREFIX}/lib || exit 1
    cp /usr/lib/libc++abi.so.1.0 ${CDT_PREFIX}/lib || exit 1
    DIR=`pwd`
    cd ${CDT_PREFIX}/lib || exit 1
    ln -sf libc++.so.1.0 libc++.so.1 || exit 1
    ln -sf libc++abi.so.1.0 libc++abi.so.1 || exit 1
    cd ${DIR} || exit 1
fi

# make symlinks
pushd ${PREFIX}/lib/cmake/${PROJECT} &> /dev/null
ln -sf ../../../${SUBPREFIX}/lib/cmake/${PROJECT}/${PROJECT}-config.cmake ${PROJECT}-config.cmake || exit 1
ln -sf ../../../${SUBPREFIX}/lib/cmake/${PROJECT}/chainsqlWasmToolchain.cmake chainsqlWasmToolchain.cmake || exit 1
ln -sf ../../../${SUBPREFIX}/lib/cmake/${PROJECT}/ChainSQLCDTMacros.cmake ChainSQLCDTMacros.cmake || exit 1
popd &> /dev/null

create_symlink() {
   ln -sf ../${SUBPREFIX}/bin/$1 ${PREFIX}/bin/$2 || exit 1
}

create_symlink chainsql-cc chainsql-cc
create_symlink chainsql-cpp chainsql-cpp
create_symlink chainsql-ld chainsql-ld
create_symlink chainsql-pp chainsql-pp
create_symlink chainsql-init chainsql-init
create_symlink chainsql-wasm2wast chainsql-wasm2wast
create_symlink chainsql-wast2wasm chainsql-wast2wasm
create_symlink chainsql-ar chainsql-ar
create_symlink chainsql-abidiff chainsql-abidiff
create_symlink chainsql-nm chainsql-nm
create_symlink chainsql-objcopy chainsql-objcopy
create_symlink chainsql-objdump chainsql-objdump
create_symlink chainsql-ranlib chainsql-ranlib
create_symlink chainsql-readelf chainsql-readelf
create_symlink chainsql-strip chainsql-strip

echo "Generating Tarball $NAME.tar.gz..."
tar -cvzf $NAME.tar.gz ./${PREFIX}/* || exit 1
rm -r ${PREFIX} || exit 1
