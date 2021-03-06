#pragma once

#include <list>
#include <string>
#include <vrpn_Tracker.h>
//#include "vrpn_Tracker_OpenVR.h"
#include <quat.h>

#include "filter.h"

class vrpn_Tracker_Camera :
    public vrpn_Tracker
{
public:
    vrpn_Tracker_Camera(int idx, const std::string& name, vrpn_Connection* connection, const std::string& tracker_serial, q_vec_type arm);
    void mainloop();
    void updateTracking(q_vec_type tracker_pos, q_type tracker_quat, q_vec_type reference_pos, q_type reference_quat, q_vec_type reference_point, struct timeval *tv);
    void getRotation(q_type& quat);
    void getPosition(q_vec_type& vec);
    std::string getName();
    std::string getTrackerSerial();
    void freedAdd(char *host_port);
    void filterAdd(filter_abstract* flt);
protected:
    void freedSend();

private:
    q_vec_type arm;
    std::string name;
    std::string tracker_serial;
    std::list<std::string> freed_targets;
    std::list<struct sockaddr_in> freed_sockaddr;
    int freed_socket;
    int idx;

    filter_abstract* filters_list[16];
    int filters_cnt;
};

