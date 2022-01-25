#include <ctime>
#include <chrono>
#include <sys/time.h>

using std::chrono::duration_cast;
using std::chrono::milliseconds;
using std::chrono::seconds;
using std::chrono::system_clock;

auto getCurrentTime()
{
    return duration_cast<milliseconds>(system_clock::now().time_since_epoch()).count();
}