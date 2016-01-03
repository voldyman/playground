#include <thread> // for sleep
#include <chrono> // for sleep time

#include <pulse/simple.h>

int main() {
    pa_simple *s;
    pa_sample_spec ss;
    ss.format = PA_SAMPLE_S16NE;
    ss.channels = 2;
    ss.rate = 44100;
    s = pa_simple_new(NULL,               // Use the default server.
                      "Fooapp",           // Our application's name.
                      PA_STREAM_RECORD,
                      NULL,               // Use the default device.
                      "Music",            // Description of our stream.
                      &ss,                // Our sample format.
                      NULL,               // Use default channel map
                      NULL,               // Use default buffering attributes.
                      NULL               // Ignore error code.
        );


    std::this_thread::sleep_for(std::chrono::seconds(10));

    pa_simple_free(s);
    return 0;
}
