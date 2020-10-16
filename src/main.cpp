#include "producer.h"
#include "consumer.h"
using namespace std;
using namespace aca_message_pulsar;

string broker = "pulsar://localhost:6543";
string subscription = "my-sub";
string topic = "my-topic";

int main(){
    Aca_Message_Pulsar_Producer producer(broker,topic);
    Aca_Message_Pulsar_Consumer consumer(broker,subscription);
    producer.publish("my message");
    consumer.consumeDispatched(topic);
    return 0;
}