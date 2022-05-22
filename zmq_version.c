#include <zmq.h>
#include <stdio.h>

void print_zmq_version() {
    int major, minor, patch;
    zmq_version(&major, &minor, &patch);
    printf("Current ZMQ version is %d.%d%d\n", major, minor, patch);
}

