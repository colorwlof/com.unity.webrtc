#!/bin/bash

export IDENTITY=~/.ssh/id_rsa_macmini

# render template
envsubst '                                    \
  $SCRIPTING_BACKEND                          \
  $EXTRA_EDITOR_ARG                           \
  $PACKAGE_DIR                                \
  $TEST_RESULT_DIR                            \
  $EDITOR_VERSION'                            \
  < BuildScripts~/template/remote.sh.template \
  > remote.sh
chmod +x ~/remote.sh

# copy package to remote machine
scp -i ${IDENTITY} -r ${PACKAGE_DIR} bokken@${BOKKEN_DEVICE_IP}:${PACKAGE_DIR}

# copy shell script to remote machine
scp -i ${IDENTITY} -r ~/remote.sh bokken@${BOKKEN_DEVICE_IP}:~/remote.sh

ssh -i ${IDENTITY} bokken@${BOKKEN_DEVICE_IP} ~/remote.sh
scp -i ${IDENTITY} -r bokken@${BOKKEN_DEVICE_IP}:${PACKAGE_DIR}/test-results upm-ci~/test-results