#include "examplePort.cpp"
#include "exampleTomom.cpp"

int main () {
    send_command("123", callback_result);
    start_measure(callback_result);
    return 0;
}
