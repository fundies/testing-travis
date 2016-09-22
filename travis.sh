#!/bin/bash +x

./emake --compiler ${COMPILER} --mode ${MODE} --platform ${PLATFORM} --graphics ${GRAPHICS} --audio ${AUDIO} --collision ${COLLISION} --network ${NETWORK} --widgets ${WIDGETS} -o /tmp/test
