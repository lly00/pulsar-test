#ifndef PULSAR_PRODUCER_H
#define PULSAR_PRODUCER_H

#include "pulsar/Client.h"
#include "pulsar/Producer.h"
#include "pulsar/ClientConfiguration.h"
#include "pulsar/ProducerConfiguration.h"
#include "pulsar/Message.h"
#include "pulsar/Result.h"
#include "pulsar/MessageBuilder.h"

using namespace std;
using namespace pulsar;

namespace aca_message_pulsar
{
class ACA_Message_Pulsar_Producer {
  private:
  string brokers_list; //IP addresses of Pulsar brokers, format: pulsar://<pulsar_host_ip>:<port>, example:pulsar://10.213.43.188:9092

  string topic_name; //A string representation of the topic name to be published, example: /hostid/00000000-0000-0000-0000-000000000000/netwconf/

  ClientConfiguration client_config; //Configuration of the pulsar client

  ProducerConfiguration producer_config; //Configuration of the pulsar producer

  Producer *ptr_producer; //A pointer to the pulsar producer

  Client *ptr_client; //A pointer to the pulsar client

  public:
  ACA_Message_Pulsar_Producer(string brokers, string topic);

  ~ACA_Message_Pulsar_Producer();

  string getBrokers() const;

  string getTopicName() const;

  void setTopicName(string topic);

  void publish(string message);

  private:
  void setBrokers(string brokers);
};

} // aca_message_pulsar

#endif