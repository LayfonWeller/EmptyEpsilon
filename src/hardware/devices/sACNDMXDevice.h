#ifndef S_ACN_DMX_DEVICE_H
#define S_ACN_DMX_DEVICE_H

#include <SFML/System.hpp>
#include <SFML/Network.hpp>
#include <stdint.h>
#include "hardware/hardwareOutputDevice.h"

//The AcnDMXDevice talks the ACN E1.31 protocol. Which is an UDP protocol for sending DMX messages trough IP networks.
class StreamingAcnDMXDevice : public HardwareOutputDevice
{
private:
    static constexpr int acn_port = 5568;

    sf::Thread update_thread;
    sf::UdpSocket socket;
    
    bool run_thread = false;
    int channel_count = 512;
    uint8_t channel_data[512] = {0};
    
    int resend_delay = 50;
    bool multicast = false;
    
    int universe = 1;
    uint8_t uuid[16];
    uint8_t source_name[64] = "EmptyEpsilon";
public:
    StreamingAcnDMXDevice();
    virtual ~StreamingAcnDMXDevice();
    
    //Configure the device.
    // Parameter: "channels" amount of output channels used (default: 512)
    // Parameter: "universe" which sACN universe to broadcast in. Default "1"
    // Parameter: "resend_delay" Time between broadcast packets, in ms. Default "50"
    // Parameter: "multicast" Per default, sACN should be using multicast. But this implementation can also use broadcast. Default is to use broadcast. Set to 1 for multicast.
    virtual bool configure(std::unordered_map<string, string> settings) override;

    //Set a hardware channel output. Value is 0.0 to 1.0 for no to max output.
    virtual void setChannelData(int channel, float value) override;
    
    //Return the number of output channels supported by this device.
    virtual int getChannelCount() override;

private:
    void updateLoop();
};

#endif//S_ACN_DMX_DEVICE_H
