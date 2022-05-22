#include <zmq.h>
#include <string.h>
#include <stdio.h>
#include <unistd.h>

static char * s_recv(void *socket) {
    char buffer[256];
    int size = zmq_recv(socket, buffer, 255, 0);
    if (size == -1)
        return NULL;
    if (size > 255)
        size = 255;
    buffer[size] = 0;
    return strdup(buffer);
}

void print_zmq_version() {
    int major, minor, patch;
    zmq_version(&major, &minor, &patch);
    printf("Current ZMQ version is %d.%d%d\n", major, minor, patch);
}

int main(void) {
    print_zmq_version();
    return 0;
}
