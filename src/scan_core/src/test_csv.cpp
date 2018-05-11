#include "data_rider/csv/Testdata.h"
#include "data_rider/csv/Sbgdata.h"
#include "data_rider/csv/Velodynedata.h"
#include "data_rider/dir_brouser/DirBrouser.h"
#include <iostream>


using namespace drider::csv;
using namespace drider;
using namespace std;


int main(int argc, char *arv[]) 
{
    Velodynedata<VelodyneLine> *tmp = new Velodynedata<VelodyneLine>(); 
    vector<VelodyneLine> list;
    //tmp->Create(DirBrouser::DataDirectory("velodyne_test.csv"));
    VelodyneLine some;
    some.ros_timestamp = "1523545635/628755331";
    some.packet_stamp = "1523545635/578932762";
    some.laser_id = 1;
    some.gps_time_toh = 435611781;
    some.lerp_laser_time = 435611781.071;
    some.x = 1.000;
    some.y = 1.000;
    some.z = 1.000;
    some.distance = 20.9;
    some.intensity = 30;
    tmp->WriteCsvRaw(some);
    some.laser_id = 2;
    tmp->WriteCsvRaw(some);
    some.laser_id = 3;
    tmp->WriteCsvRaw(some);

    tmp->Open(DirBrouser::DataDirectory("velodyne.csv"));
    
    int flag;
    //tmp->Reopen();
    //std::cout << "wtf" << endl;
    flag = tmp->ReadCsvPart(16000000, list);
    int ix = 0;
    for(auto it : list) 
    {
        /*cout << it.ros_timestamp << " " <<
                it.packet_stamp << " " <<
                (int)it.laser_id << " " <<
                it.gps_time_toh << " " <<
                it.lerp_laser_time << " " <<
                it.x << " " <<
                it.y << " " <<
                it.z << " " <<
                it.distance << " " <<
                (int)it.intensity << endl;*/
        ix++; 
    }
    cout << "Считано строчек: " << ix << endl;

}

/*int main(int argc, char *arv[]) 
{
    Sbgdata<SbgLine> *tmp = new Sbgdata<SbgLine>();
    tmp->Open(DirBrouser::DataDirectory("sbg.csv"));
    int flag;
    SbgLine some;
    while((flag = tmp->ReadCsvRaw(some)) == Sbgdata<SbgLine>::Status::OPENED)
    cout << some.ros_timestamp << " " << 
            (int)some.year << " " <<
            (int)some.month << " " <<
            (int)some.day << " " <<
            (int)some.hour << " " <<
            (int)some.minute << " " <<
            (int)some.second << " " <<
            some.utc_nanosecond << " " <<
            some.gps_week << " " <<
            some.clock_stable << " " <<
            some.clock_status << " " <<
            some.clock_utc_sync << " " <<
            some.clock_utc_status << " " <<
            some.roll << " " <<
            some.pitch << " " <<
            some.yaw << " " <<
            some.north << " " <<
            some.east << " " <<
            some.down << " " <<
            some.latitude << " " <<
            some.longitude << " " <<
            some.attitude << " " <<
            some.undulation << " " <<
            (int)some.solution_mode << endl;


}*/

/*int main(int argc, char *argv[])
{
    Testdata<TestDataLine> *tmp = new Testdata<TestDataLine>();
    bool wtf=tmp->Create("/home/zf/scan_viz/src/scan_core/scan_core_files/data/test.csv");
    std::cout<<wtf<<std::endl;
    TestDataLine some;
    some.timestamp = 91191;
    some.flag = 6;
    some.x = 1.00000;
    some.y = 2.00000;
    some.z = 3.00000;

    tmp->WriteCsvRaw(some);
    some.flag = 7;
    tmp->WriteCsvRaw(some);
    some.flag = 8;
    tmp->WriteCsvRaw(some);
    tmp->Close();
    tmp->Open("/home/zf/scan_viz/src/scan_core/scan_core_files/data/test.csv");
    TestDataLine some1;
    for (int i = 0; i < 5; i++) {
        int flag;
        while((flag = tmp->ReadCsvRaw(some1)) == Testdata<TestDataLine>::Status::OPENED)
        cout << some1.timestamp << " " << (int)some1.flag << endl;
        if (flag == Testdata<TestDataLine>::Status::EOFILE) {
            tmp->Reopen();
        }
    }
    
    return 0;
}*/
