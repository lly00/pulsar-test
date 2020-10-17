#include "producer.h"
#include "consumer.h"
using namespace std;
using namespace aca_message_pulsar;
using namespace test;

string broker = "pulsar://localhost:6543";
string subscription = "my-sub";
string topic = "my-topic";

int main(){
    Test test();
    test.foo();
    Aca_Message_Pulsar_Producer producer(broker,topic);
    Aca_Message_Pulsar_Consumer consumer(broker,subscription);
    producer.publish("my message");
    consumer.consumeDispatched(topic);
    return 0;
}